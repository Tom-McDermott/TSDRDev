/*
 * 10-18-2021	Tom McDermott, N5EG
 *
 * Copyright 2021, Thomas C. McDermott.
 * Licensed under GNU Public License, version 2 or later.
 *
 * Implementation of the Data Engine (host) side of
 * the LH_DE protocol for TangerineSDR.
 *
 * This dynamically creates connections as described by
 * the protocol. Future feature: clear connections when
 * they are inactive for a long time.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "system.h"

#include "alt_error_handler.h"
#include "DELHProtocol.h"

#include "simple_socket_server.h"	// LED Queue

#include "altera_avalon_i2c.h"		// I2C interface
#include "altera_avalon_spi.h"		// SPI interface


/* Allocate the channel table in global memory so
 * the timer task can manipulate the timers in it.
 * The LED command also needs to be in global memory
 * for the same reason.
 */
static struct UDPCHAN Connections[MAXUDPCHAN];
struct ITFCMAP ItfcTable[MAXITFC];
static INT32U LEDCommand;



/* Initialize the connection table,
 * Add a connection to the table,
 * Delete a connection from the table.
 * Find a connection in the table.
 * Build a UDPCONN struct from pieces and add.
 * Return array of all active fd's in the table.
 * fd == -1 implies an empty connection slot.
 *
 * NOTE: fd = 0 could be stdin or stdout ?
 */

void initChan()
{
	for (int i=0; i < MAXUDPCHAN; i++)
	{
		Connections[i].fd = -1;
		Connections[i].chantype = 'I';	// Inactive
	}
};

int addChan(struct UDPCHAN * Conn)
{
	if (Conn->fd < 0)
		return(-2);	// bad fd value to add.

	for (int i=0; i < MAXUDPCHAN; i++)
	{
		if (Connections[i].fd == -1)
		{
			memcpy(&Connections[i], Conn, sizeof(struct UDPCHAN));
			return(i);
		}
	}

	return(-1);  // out of space in the table
};

int delChan(struct UDPCHAN * Conn)
{
	if (Conn->fd < 0)
		return(-2);	// bad fd value to delete.

	for (int i=0; i < MAXUDPCHAN; i++)
	{
		if (Connections[i].fd == Conn->fd)
		{
			Connections[i].fd = -1;
			Connections[i].chantype = 'I';
			return(i);
		}
	}

	return(-1);  // didn't find in the table
};

int findfdChan(int fd)
{
	if (fd < 0)
		return(-2);	// bad fd value to search for.

	for (int i=0; i < MAXUDPCHAN; i++)
	{

		if (Connections[i].fd == fd)
			return(i);  // index of the matching connection
	}

	return(-1);  // didn't find in the table
};

int findExistingChan(char chantype, struct sockaddr_in * client)
{
	// See if we already have a channel to the client IP

	for (int i=0; i < MAXUDPCHAN; i++)
	{
		if ((Connections[i].chantype == chantype)      &&
		   (memcmp(&(Connections[i].client_ip.sin_addr), &(client->sin_addr), sizeof(struct in_addr) ) == 0))
		{
			return(i);	// have existing channel
		}
	}

	return(-1);		// didn't find in the table

}

int buildaddChan(int fd, char type, struct sockaddr_in * host, struct sockaddr_in * client)
{
	struct UDPCHAN conn;

	if (fd < 0)
		return(-2);	// bad fd value

	conn.fd = fd;
	conn.chantype = type;
	memcpy(&conn.host_ip, host, sizeof(struct sockaddr_in));
	memcpy(&conn.client_ip, client, sizeof(struct sockaddr_in));

	return addChan(&conn);
};

int allListeners(int * theList)			// return array of active channels to listen for
{
	int count = 0;

	//memset(theList, -1, MAXUDPCHAN);	// clear the returned list

	for(int i=0; i<MAXUDPCHAN; i++)
		if (Connections[i].fd > 0)		// valid fd
			theList[count++] = Connections[i].fd;

	return count;
};


/*************************************************************************************************
 * Handle received packets according to the type of channel they are received on.
 * Also transmit packets in response as necessary.
 * ***********************************************************************************************/

#define MAXLINE 1500
unsigned char buffer[MAXLINE+1];  // room to hold string terminating \0


int ProcessRxPacket(int index)
{

    int                 len, bufflen;
    struct sockaddr_in  client_addr;

	// Discovery channel has to process the receive buffer itself

	if (Connections[index].chantype == 'D')  // Discovery
		return DiscChanMessage(index);

	// Get the received buffer
    memset(&client_addr, 0, sizeof(struct sockaddr_in));

    len = sizeof(struct sockaddr_in);
	bufflen = recvfrom(Connections[index].fd, (char *)buffer, MAXLINE,
			/*MSG_WAITALL*/ 0, (struct sockaddr *) &client_addr, &len);
	buffer[bufflen] = '\0';

	if (Connections[index].chantype == 'P')  // Provisioning
		return ProvChanMessage(index, bufflen);

	if (Connections[index].chantype == 'C')  // Configuration
		return ConfigChanMessage(index, bufflen);

	if (Connections[index].chantype == 'T')  // Traffic (Data rx'd from Ethernet to be RF transmitted)
		return TrafficChanMessage(index, bufflen);

	return -1;		// unknown or Idle chantype
};


int DiscChanMessage(int index)
{
    /* Received HPSDR discovery request.
     * If it's a new one, create a provisioning channel and reply
     * using it.  Else reply using existing provisioning channel.
     * If it's not a request message, we don't know what to do with it.
     */

    int                 len, n, fd_prov_tx;
    struct sockaddr_in  client_addr, host_addr;

    memset(&client_addr, 0, sizeof(struct sockaddr_in));
    memset(&host_addr, 0, sizeof(struct sockaddr_in));

    /* Discovery reply format:
     * 0xEF 0xFE 0x02 (not sending data yet) 6-byte ourMACaddress code_ver
     * board_id (0x07 from TSDR)
     */
    uint8_t disc_resp[64] = { 0xfe, 0xef, 0x02, 0x00, 0x07, 0xed, 0x2a, 0x22, 0x16, 0x07 };
    memset(&disc_resp[10], 0, 54);  // discovery reply is padded with zeros

    len = sizeof(struct sockaddr_in);
	n = recvfrom(Connections[index].fd, (char *)buffer, MAXLINE,
			/*MSG_WAITALL*/ 0, (struct sockaddr *) &client_addr, &len);
	buffer[n] = '\0';

    /* check for 0xef 0xfe 0x02 signifying discovery request */
	if ((buffer[0] == 0xef) && (buffer[1] == 0xfe) && (buffer[2] == 0x02))
	  printf("Valid OpenHPSDR Discovery request received\n");
	else
		return -1;	// unknown discovery message - throw away

	printf("From: %s   Port: %u\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
	printf("Received buffer : 0x%2x 0x%2x 0x%2x 0x%2x\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    // See if we already have a Provisioning Channel open from this client

    int existingIndex = findExistingChan('P', &client_addr);
    if (existingIndex >= 0)		// Have an existing provisioning channel - send a duplicate reply
    {
    	int result = sendto(Connections[existingIndex].fd, (void *)disc_resp, sizeof(disc_resp),
				/*MSG_CONFIRM*/ 0, (struct sockaddr *) &client_addr, sizeof(struct sockaddr_in));
    	return result;
    }

    // Don't have an existing channel. Create a new Provisioning channel to send the discovery reply

    if ((fd_prov_tx = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
      alt_NetworkErrorHandler(EXPANDED_DIAGNOSIS_CODE,"[TSDR_task] Provisioning Socket creation failed");
    }

    // Use a new sending socket. sendto implicitly binds a new (random) receive port number

    sendto(fd_prov_tx, (void *)disc_resp, sizeof(disc_resp),
    		/*MSG_CONFIRM*/ 0, (struct sockaddr *) &client_addr, sizeof(struct sockaddr_in));

    len = sizeof(struct sockaddr_in);
    if (getsockname(fd_prov_tx, (struct sockaddr *)&host_addr, &len) == -1)
    {
    	perror("getsockname() error\n");
    	return -1;	// Error
    }
    else
    {
    	printf("Provisioning port number: %d\n", ntohs(host_addr.sin_port));
    	int addresult = buildaddChan(fd_prov_tx, 'P', &host_addr, &client_addr);
    	printf("Result of adding new provisioning channel to table: %u\n", addresult);
    	return addresult;   // return the result of adding the channel to the table
    }
};

int ProvChanMessage(int index, int bufflen)
{

    /* Received a Provisioning Channel message command:
	 * MR - Module Read
	 * MW - Module Write
	 * CC - Create a Config Chan
	 * UC - Uncreate (Delete) a Config chan
	 * XR - Reboot DE
	 * S? - status request
	 * Yn - Turn on LED n.  The DEVKIT has 4 LEDs
	 * Xn - Turn off LED n
	 */

	int result;

	printf("Received Provisioning Channel Message: %s\n", buffer);

	if (buffer[0] == 'Y' || buffer[0] == 'X')
		result = ProvisioningLEDCommand(index, bufflen);

	if (buffer[0] == 'M')
		result = ProvisioningModuleRegisterCommand(index, bufflen);

	if (result >= 0)
	    sendto(Connections[index].fd, (void *)"AK\n", 4, 0, (struct sockaddr *) &Connections[index].client_ip, sizeof(struct sockaddr_in));
	else
        sendto(Connections[index].fd, (void *)"NAK\n", 4, 0, (struct sockaddr *) &Connections[index].client_ip, sizeof(struct sockaddr_in));

	return result;
};

int ConfigChanMessage(int index, int bufflen)
{
    // Received Configuration Channel message

	printf("Received Configuration Channel Message: %s\n", buffer);
	return -2;	// not yet implemented
};

int TrafficChanMessage(int index, int bufflen)
{
    // Received Traffic (Data) Channel message

	printf("Received Traffic Channel Message: %s\n",buffer);
	return -2;	// not yet implemented
};


int ProvisioningLEDCommand(int index, int bufflen)
{
	if (buffer[0] == 'Y')	// Turn on LED0 - 3
	{
		if (buffer[1] == '0')
		{
			LEDCommand = 0x01;
			OSQPost(SSSLEDCommandQ, (void *) LEDCommand);
			return 0;
		}
		if (buffer[1] == '1')
		{
			LEDCommand = 0x02;
			OSQPost(SSSLEDCommandQ, (void *) LEDCommand);
			return 0;
		}
		if (buffer[1] == '2')
		{
			LEDCommand = 0x04;
			OSQPost(SSSLEDCommandQ, (void *) LEDCommand);
			return 0;
		}
		if (buffer[1] == '3')
		{
			LEDCommand = 0x08;
			OSQPost(SSSLEDCommandQ, (void *) LEDCommand);
			return 0;
		}
		return -1;	// unknown LED number
	}

	if (buffer[0] == 'X')	// Turn off LED0 - 3
	{
		if (buffer[1] == '0')
		{
			LEDCommand = 0x10;
			OSQPost(SSSLEDCommandQ, (void *) LEDCommand);
			return 0;
		}
		if (buffer[1] == '1')
		{
			LEDCommand = 0x20;
			OSQPost(SSSLEDCommandQ, (void *) LEDCommand);
			return 0;
		}
		if (buffer[1] == '2')
		{
			LEDCommand = 0x40;
			OSQPost(SSSLEDCommandQ, (void *) LEDCommand);
			return 0;
		}
		if (buffer[1] == '3')
		{
			LEDCommand = 0x80;
			OSQPost(SSSLEDCommandQ, (void *) LEDCommand);
			return 0;
		}
		return -1;	// unknown LED number
	}
	return -2;		// How did we get here?

};

int ProvisioningModuleRegisterCommand(int index, int bufflen)
{

	/* Define a table mapping the slot# and interface# to a specific
	 * I2C or SPI interface for the test system based on the DEV_KIT.
	 * For a real system this table needs to be constructed based on
	 * how the DE is actually equipped with modules which probably
	 * needs to be determined at run time.
	 *
	 * The I2C and SPI driver calls may be different.  The name of the
	 * interfaces for the I2C and SPI are manually encoded here based
	 * on direct knowledge of the SOPCINFO file and Quartus Qsys planner.
	 */

	// struct REGMAP { };    // definition should be in the .h file

	// Note: buffer gets modified by strtok(), so don't further reuse it.
	//              Cmd  Slot# Intfc#  Addr   Data
	// Module Read:  MR 0xssss 0xiiii 0xaaaa
	// Module Write: MW 0xssss 0xiiii 0xaaaa 0xZZZZ

	char * cmd = strtok((char *)buffer, " ");
	char * module = strtok(NULL, " ");
	char * slot = strtok(NULL, " ");
	char * regaddr = strtok(NULL, " ");
	char * regdata = strtok(NULL, " ");

	int moduleint, slotint, regaddrint, regdataint;

	char * ptr;		// dummy used to make strtoul work

	moduleint = strtoul(module, &ptr, 0);
	slotint = strtoul(slot, &ptr, 0);
	regaddrint = strtoul(regaddr, &ptr, 0);
	if (regdata != NULL)
		regdataint = strtoul(regdata, &ptr, 0);
	else
		regdataint = 0;



	int itfcindex = FindItfcIndex(moduleint, slotint);	// Find index of requested interface

	if (itfcindex == -1)	// Not found
		return -1;		// Unknown Module / Slot combination


	// Module Read command
	// Reply with either NAK or AK and RR 0xssss 0xiiii 0xaaaa 0xZZ   (ZZ = data read)
	if (cmd[1] == 'R')
	{

		// ***********************************************************************************
		// QUESTION: how many bytes of address to write to the device before reading back?
		// Is this different for various I2C device types?
		// ***********************************************************************************
		//
		// The IDENT_PROM has a default address of 0x60. Is this the slave address ???
		// The unique serial number is in the configuration zone.
		// It requires a special wake-up sequence from power-down.
		// It needs a 100 Khz speed to wake up.
		//


		if (ItfcTable[itfcindex].IFtype == 'I')	// I2C
		{
			ALT_AVALON_I2C_DEV_t *i2c_dev; 		//pointer to instance structure
			ALT_AVALON_I2C_STATUS_CODE status;

			i2c_dev = alt_avalon_i2c_open(ItfcTable[itfcindex].name);

			if (NULL==i2c_dev)
			{
				printf("Device Error: Cannot find: %s\n", ItfcTable[itfcindex].name);
				return -1;
			}

			if (ItfcTable[itfcindex].devtype == 1)		// ID_EPROM
			{


				//set the slave address of the ID_EPROM device
				unsigned long slave_addr = 0x51;
				alt_avalon_i2c_master_target_set(i2c_dev, slave_addr);

				// write 0x00 to wake up the device
				// need address of 0x60 to read the serial number
				// the 72-bit unique ID is at addr perhaps 0x60, 0x61, 0x62
				// via 32-bit reads ???

				// Can we send back a string or just a sequence of bytes?


				return 0;		// OK

			};

			if (ItfcTable[itfcindex].devtype == 2)		// 2 -> TI PCF8574 I/O latch
			{
				// null since we don't read this register on the receiver
				return 0;		// OK
			};

/*
			//alt_u8 txbuffer[0x2];
			alt_u8 rxbuffer[0x2];
			//int i;
			//get a pointer to the avalon i2c instance


			//write data to an eeprom at address 0x0200
			//txbuffer[0]=2; txbuffer[1]=0;
			//The eeprom address which will be sent as first two bytes of data
			//for (i=0;i<0x10;i++) txbuffer[i+2]=i;
			//some data to write

			//status=alt_avalon_i2c_master_tx(i2c_dev, txbuffer, 0x10+2, ALT_AVALON_I2C_NO_INTERRUPTS);

			//if (status != ALT_AVALON_I2C_SUCCESS)
			//	return -1; //FAIL

			//read back the data into rxbuffer
			//This command sends the 2 byte eeprom data address required by the eeprom
			//Then does a restart and receives the data.
			//status = alt_avalon_i2c_master_tx_rx(i2c_dev, txbuffer, 2, rxbuffer, 0x10, ALT_AVALON_I2C_NO_INTERRUPTS);

			status = alt_avalon_i2c_master_rx(i2c_dev, rxbuffer, 0x1, ALT_AVALON_I2C_NO_INTERRUPTS);

			if (status!=ALT_AVALON_I2C_SUCCESS)
				return -1; //FAIL
*/
			return -1;  // Got some unknown device type to read

		}
		if (ItfcTable[itfcindex].IFtype == 'S')	// SPI
		{

		}
	}

	// Module Write command
	// Reply with either NAK or AK
	if (cmd[1] == 'W')
	{
		ALT_AVALON_I2C_DEV_t *i2c_dev; 		//pointer to instance structure
		ALT_AVALON_I2C_STATUS_CODE status;

		i2c_dev = alt_avalon_i2c_open(ItfcTable[itfcindex].name);

		if (NULL==i2c_dev)
		{
			printf("Device Error: Cannot find: %s\n", ItfcTable[itfcindex].name);
			return -1;
		}


		if (ItfcTable[itfcindex].IFtype == 'I')	// I2C
		{

			if (ItfcTable[itfcindex].devtype == 1)		// ID_EPROM
			{
				// right now null since we don't write this device on receiver or clock
				return 0;		// OK

			};


			if (ItfcTable[itfcindex].devtype == 2)		// 2 -> TI PCF8574 I/O latch write
			{
				// regdataint is an integer of the data to write

				alt_u8 txdata = (alt_u8)regdataint;
				alt_u32 count = 0x01;				// num bytes to send

				//
				// Receive Module. All data are ACTIVE LOW.
				// Bit7 = Red LED   		Bit6 = Green LED  		Bit5 = Ch2 20dB Atten  	Bit4 = Ch2 10 dB Atten
				// Bit3 = Ch2 Noise Enable 	Bit2 = Ch1 20 dB Atten  Bit1 = Ch1 10 dB Atten  Bit0 = Ch1 Noise Enable

				//set the slave address
//				alt_u32 slave_addr_write = 0x70;  // PCF8574 Write address (0x71 is the corresponding read addr)
				alt_u32 slave_addr = 0x38;  	  // PCF8574 address - the i2c driver left shifts then appends 0 for
												  // write or 1 for read translating this to 0x70 for write, 0x71 for read

				alt_avalon_i2c_master_target_set(i2c_dev, slave_addr);

				status = alt_avalon_i2c_master_tx(i2c_dev, &txdata, count, ALT_AVALON_I2C_NO_INTERRUPTS);

				if (status == ALT_AVALON_I2C_NACK_ERR)		// retry the write
				{
					printf("Received NACK error from I2C device. Retry once\n");
					status = alt_avalon_i2c_master_tx(i2c_dev, &txdata, count, ALT_AVALON_I2C_NO_INTERRUPTS);
				}


				if (status != ALT_AVALON_I2C_SUCCESS)
				{
					printf("i2c_master_tx: error = %ld\n", status);
					return -1; //FAIL
				}

				return 0;		// OK

			};

		}
		if (ItfcTable[itfcindex].IFtype == 'S')	// SPI
		{
			return -1;	// CHANGE THIS once SPI is implemented
		}
	}

	// Unknown module register sub-command
//	sendto(Connections[index].fd, (void *)"NAK\n", 4, 0, (struct sockaddr *) &Connections[index].client_ip, sizeof(struct sockaddr_in));
	return -2;
};

/* Routines to initialize the Interface Map table and to find the index
 * of the entry that matches the module # / slot #
 *
 * base address copied from the BSP system.h file.
 * name copied from the BSP generated system.h file.
 * If the Qsys blocks have their names changed, then these must change.
 * Often need to rebuild the Project Indexes when BSP --> system.h is regenerated.
 *
 * I2C Device Types:
 * 1 = Microchip ATECC608A Ident PROM
 * 2 = TI PCF8574 Latch
 * 3 =
 * 4 =
 */

// Initialize the Interface Map Table.
void initItfcMap()
{
	ItfcTable[0].module = 0;	// CKM_C0
	ItfcTable[0].slot = 0;
	ItfcTable[0].base = I2C_CKM_C0_BASE;
	strcpy(&ItfcTable[0].name[0], I2C_CKM_C0_NAME);
	ItfcTable[0].IFtype = 'I';
	ItfcTable[0].devtype = 2;

	ItfcTable[1].module = 0;	// CKM_C1
	ItfcTable[1].slot = 1;
	ItfcTable[1].base = I2C_CKM_C1_BASE;
	strcpy(&ItfcTable[1].name[0], I2C_CKM_C1_NAME);
	ItfcTable[1].IFtype = 'I';
	ItfcTable[1].devtype = 2;

	ItfcTable[2].module = 0;	// CKM_ID
	ItfcTable[2].slot = 2;
	ItfcTable[2].base = I2C_CKM_ID_BASE;
	strcpy(&ItfcTable[2].name[0], I2C_CKM_ID_NAME);
	ItfcTable[2].IFtype = 'I';
	ItfcTable[2].devtype = 1;

	ItfcTable[3].module = 1;	// RXM_CTRL
	ItfcTable[3].slot = 0;
	ItfcTable[3].base = I2C_RXM_CTRL_BASE;
	strcpy(&ItfcTable[3].name[0], I2C_RXM_CTRL_NAME);
	ItfcTable[3].IFtype = 'I';
	ItfcTable[3].devtype = 2;

	ItfcTable[4].module = 1;	// RXM_ID
	ItfcTable[4].slot = 1;
	ItfcTable[4].base = I2C_RXM_ID_BASE;
	strcpy(&ItfcTable[4].name[0], I2C_RXM_ID_NAME);
	ItfcTable[4].IFtype = 'I';
	ItfcTable[4].devtype = 1;

	ItfcTable[5].module = 1;	// RXM_SPI_ADC
	ItfcTable[5].slot = 2;
	ItfcTable[5].base = SPI_RXM_BASE;
	strcpy(&ItfcTable[5].name[0], SPI_RXM_NAME);
	ItfcTable[5].IFtype = 'S';
	ItfcTable[5].devtype = 3;
};

// Find the index of the Module / Slot in the Interface Map table
int FindItfcIndex(int module, int slot)
{
	for (int i=0; i< MAXITFC; i++)		if ((module == ItfcTable[i].module) && (slot == ItfcTable[i].slot))
			return i;

	return -1;	// Didn't find it in the table
};
