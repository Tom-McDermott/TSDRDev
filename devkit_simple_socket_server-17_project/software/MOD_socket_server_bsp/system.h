/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'cpu' in SOPC Builder design 'q_sys'
 * SOPC Builder design path: ../../q_sys.sopcinfo
 *
 * Generated: Tue Oct 25 11:50:19 PDT 2022
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x18003020
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1d
#define ALT_CPU_DCACHE_BYPASS_MASK 0x80000000
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 32768
#define ALT_CPU_EXCEPTION_ADDR 0x08000120
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_EXTRA_EXCEPTION_INFO
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 32768
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x1d
#define ALT_CPU_NAME "cpu"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x14430000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x18003020
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1d
#define NIOS2_DCACHE_BYPASS_MASK 0x80000000
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 32768
#define NIOS2_EXCEPTION_ADDR 0x08000120
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_EXTRA_EXCEPTION_INFO
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 32768
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x1d
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x14430000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_I2C
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SPI
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_DUAL_BOOT
#define __ALTERA_ETH_TSE
#define __ALTERA_GENERIC_QUAD_SPI_CONTROLLER
#define __ALTERA_MEM_IF_DDR3_EMIF
#define __ALTERA_MSGDMA
#define __ALTERA_NIOS2_GEN2


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "MAX 10"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_BASE 0x18003ff8
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_BASE 0x18003ff8
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_BASE 0x18003ff8
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "q_sys"


/*
 * altera_iniche configuration
 *
 */

#define DHCP_CLIENT
#define INCLUDE_TCP
#define INICHE_DEFAULT_IF "NOT_USED"
#define IP_FRAGMENTS


/*
 * descriptor_memory configuration
 *
 */

#define ALT_MODULE_CLASS_descriptor_memory altera_avalon_onchip_memory2
#define DESCRIPTOR_MEMORY_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define DESCRIPTOR_MEMORY_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define DESCRIPTOR_MEMORY_BASE 0x18000000
#define DESCRIPTOR_MEMORY_CONTENTS_INFO ""
#define DESCRIPTOR_MEMORY_DUAL_PORT 0
#define DESCRIPTOR_MEMORY_GUI_RAM_BLOCK_TYPE "AUTO"
#define DESCRIPTOR_MEMORY_INIT_CONTENTS_FILE "q_sys_descriptor_memory"
#define DESCRIPTOR_MEMORY_INIT_MEM_CONTENT 1
#define DESCRIPTOR_MEMORY_INSTANCE_ID "NONE"
#define DESCRIPTOR_MEMORY_IRQ -1
#define DESCRIPTOR_MEMORY_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DESCRIPTOR_MEMORY_NAME "/dev/descriptor_memory"
#define DESCRIPTOR_MEMORY_NON_DEFAULT_INIT_FILE_ENABLED 0
#define DESCRIPTOR_MEMORY_RAM_BLOCK_TYPE "AUTO"
#define DESCRIPTOR_MEMORY_READ_DURING_WRITE_MODE "DONT_CARE"
#define DESCRIPTOR_MEMORY_SINGLE_CLOCK_OP 0
#define DESCRIPTOR_MEMORY_SIZE_MULTIPLE 1
#define DESCRIPTOR_MEMORY_SIZE_VALUE 8192
#define DESCRIPTOR_MEMORY_SPAN 8192
#define DESCRIPTOR_MEMORY_TYPE "altera_avalon_onchip_memory2"
#define DESCRIPTOR_MEMORY_WRITABLE 1


/*
 * dual_boot_0 configuration
 *
 */

#define ALT_MODULE_CLASS_dual_boot_0 altera_dual_boot
#define DUAL_BOOT_0_BASE 0x18003fc0
#define DUAL_BOOT_0_IRQ -1
#define DUAL_BOOT_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DUAL_BOOT_0_NAME "/dev/dual_boot_0"
#define DUAL_BOOT_0_SPAN 32
#define DUAL_BOOT_0_TYPE "altera_dual_boot"


/*
 * eth_tse configuration
 *
 */

#define ALT_MODULE_CLASS_eth_tse altera_eth_tse
#define ETH_TSE_BASE 0x18003800
#define ETH_TSE_ENABLE_MACLITE 0
#define ETH_TSE_FIFO_WIDTH 32
#define ETH_TSE_IRQ -1
#define ETH_TSE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ETH_TSE_IS_MULTICHANNEL_MAC 0
#define ETH_TSE_MACLITE_GIGE 0
#define ETH_TSE_MDIO_SHARED 0
#define ETH_TSE_NAME "/dev/eth_tse"
#define ETH_TSE_NUMBER_OF_CHANNEL 1
#define ETH_TSE_NUMBER_OF_MAC_MDIO_SHARED 1
#define ETH_TSE_PCS 0
#define ETH_TSE_PCS_ID 0
#define ETH_TSE_PCS_SGMII 1
#define ETH_TSE_RECEIVE_FIFO_DEPTH 2048
#define ETH_TSE_REGISTER_SHARED 0
#define ETH_TSE_RGMII 1
#define ETH_TSE_SPAN 1024
#define ETH_TSE_TRANSMIT_FIFO_DEPTH 2048
#define ETH_TSE_TYPE "altera_eth_tse"
#define ETH_TSE_USE_MDIO 1


/*
 * ext_flash_avl_csr configuration
 *
 */

#define ALT_MODULE_CLASS_ext_flash_avl_csr altera_generic_quad_spi_controller
#define EXT_FLASH_AVL_CSR_BASE 0x18003fa0
#define EXT_FLASH_AVL_CSR_FLASH_TYPE "Micron512"
#define EXT_FLASH_AVL_CSR_IRQ 2
#define EXT_FLASH_AVL_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define EXT_FLASH_AVL_CSR_IS_EPCS 0
#define EXT_FLASH_AVL_CSR_NAME "/dev/ext_flash_avl_csr"
#define EXT_FLASH_AVL_CSR_NUMBER_OF_SECTORS 1024
#define EXT_FLASH_AVL_CSR_PAGE_SIZE 256
#define EXT_FLASH_AVL_CSR_SECTOR_SIZE 65536
#define EXT_FLASH_AVL_CSR_SPAN 32
#define EXT_FLASH_AVL_CSR_SUBSECTOR_SIZE 4096
#define EXT_FLASH_AVL_CSR_TYPE "altera_generic_quad_spi_controller"


/*
 * ext_flash_avl_mem configuration
 *
 */

#define ALT_MODULE_CLASS_ext_flash_avl_mem altera_generic_quad_spi_controller
#define EXT_FLASH_AVL_MEM_BASE 0x14000000
#define EXT_FLASH_AVL_MEM_FLASH_TYPE "Micron512"
#define EXT_FLASH_AVL_MEM_IRQ -1
#define EXT_FLASH_AVL_MEM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define EXT_FLASH_AVL_MEM_IS_EPCS 0
#define EXT_FLASH_AVL_MEM_NAME "/dev/ext_flash_avl_mem"
#define EXT_FLASH_AVL_MEM_NUMBER_OF_SECTORS 1024
#define EXT_FLASH_AVL_MEM_PAGE_SIZE 256
#define EXT_FLASH_AVL_MEM_SECTOR_SIZE 65536
#define EXT_FLASH_AVL_MEM_SPAN 67108864
#define EXT_FLASH_AVL_MEM_SUBSECTOR_SIZE 4096
#define EXT_FLASH_AVL_MEM_TYPE "altera_generic_quad_spi_controller"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK SYS_CLK_TIMER
#define ALT_TIMESTAMP_CLK none


/*
 * i2c_ckm_c0 configuration
 *
 */

#define ALT_MODULE_CLASS_i2c_ckm_c0 altera_avalon_i2c
#define I2C_CKM_C0_BASE 0x18003d80
#define I2C_CKM_C0_FIFO_DEPTH 4
#define I2C_CKM_C0_FREQ 50000000
#define I2C_CKM_C0_IRQ -1
#define I2C_CKM_C0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define I2C_CKM_C0_NAME "/dev/i2c_ckm_c0"
#define I2C_CKM_C0_SPAN 64
#define I2C_CKM_C0_TYPE "altera_avalon_i2c"
#define I2C_CKM_C0_USE_AV_ST 0


/*
 * i2c_ckm_c1 configuration
 *
 */

#define ALT_MODULE_CLASS_i2c_ckm_c1 altera_avalon_i2c
#define I2C_CKM_C1_BASE 0x18003d40
#define I2C_CKM_C1_FIFO_DEPTH 4
#define I2C_CKM_C1_FREQ 50000000
#define I2C_CKM_C1_IRQ -1
#define I2C_CKM_C1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define I2C_CKM_C1_NAME "/dev/i2c_ckm_c1"
#define I2C_CKM_C1_SPAN 64
#define I2C_CKM_C1_TYPE "altera_avalon_i2c"
#define I2C_CKM_C1_USE_AV_ST 0


/*
 * i2c_ckm_id configuration
 *
 */

#define ALT_MODULE_CLASS_i2c_ckm_id altera_avalon_i2c
#define I2C_CKM_ID_BASE 0x18003dc0
#define I2C_CKM_ID_FIFO_DEPTH 4
#define I2C_CKM_ID_FREQ 50000000
#define I2C_CKM_ID_IRQ -1
#define I2C_CKM_ID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define I2C_CKM_ID_NAME "/dev/i2c_ckm_id"
#define I2C_CKM_ID_SPAN 64
#define I2C_CKM_ID_TYPE "altera_avalon_i2c"
#define I2C_CKM_ID_USE_AV_ST 0


/*
 * i2c_rxm_ctrl configuration
 *
 */

#define ALT_MODULE_CLASS_i2c_rxm_ctrl altera_avalon_i2c
#define I2C_RXM_CTRL_BASE 0x18003e00
#define I2C_RXM_CTRL_FIFO_DEPTH 4
#define I2C_RXM_CTRL_FREQ 50000000
#define I2C_RXM_CTRL_IRQ -1
#define I2C_RXM_CTRL_IRQ_INTERRUPT_CONTROLLER_ID -1
#define I2C_RXM_CTRL_NAME "/dev/i2c_rxm_ctrl"
#define I2C_RXM_CTRL_SPAN 64
#define I2C_RXM_CTRL_TYPE "altera_avalon_i2c"
#define I2C_RXM_CTRL_USE_AV_ST 0


/*
 * i2c_rxm_id configuration
 *
 */

#define ALT_MODULE_CLASS_i2c_rxm_id altera_avalon_i2c
#define I2C_RXM_ID_BASE 0x18003e40
#define I2C_RXM_ID_FIFO_DEPTH 4
#define I2C_RXM_ID_FREQ 50000000
#define I2C_RXM_ID_IRQ -1
#define I2C_RXM_ID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define I2C_RXM_ID_NAME "/dev/i2c_rxm_id"
#define I2C_RXM_ID_SPAN 64
#define I2C_RXM_ID_TYPE "altera_avalon_i2c"
#define I2C_RXM_ID_USE_AV_ST 0


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x18003ff8
#define JTAG_UART_IRQ 3
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * led_pio configuration
 *
 */

#define ALT_MODULE_CLASS_led_pio altera_avalon_pio
#define LED_PIO_BASE 0x18003fe0
#define LED_PIO_BIT_CLEARING_EDGE_REGISTER 0
#define LED_PIO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LED_PIO_CAPTURE 0
#define LED_PIO_DATA_WIDTH 4
#define LED_PIO_DO_TEST_BENCH_WIRING 0
#define LED_PIO_DRIVEN_SIM_VALUE 0
#define LED_PIO_EDGE_TYPE "NONE"
#define LED_PIO_FREQ 50000000
#define LED_PIO_HAS_IN 0
#define LED_PIO_HAS_OUT 1
#define LED_PIO_HAS_TRI 0
#define LED_PIO_IRQ -1
#define LED_PIO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED_PIO_IRQ_TYPE "NONE"
#define LED_PIO_NAME "/dev/led_pio"
#define LED_PIO_RESET_VALUE 15
#define LED_PIO_SPAN 16
#define LED_PIO_TYPE "altera_avalon_pio"


/*
 * mem_if_ddr3_emif_0 configuration
 *
 */

#define ALT_MODULE_CLASS_mem_if_ddr3_emif_0 altera_mem_if_ddr3_emif
#define MEM_IF_DDR3_EMIF_0_BASE 0x8000000
#define MEM_IF_DDR3_EMIF_0_IRQ -1
#define MEM_IF_DDR3_EMIF_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MEM_IF_DDR3_EMIF_0_NAME "/dev/mem_if_ddr3_emif_0"
#define MEM_IF_DDR3_EMIF_0_SPAN 134217728
#define MEM_IF_DDR3_EMIF_0_TYPE "altera_mem_if_ddr3_emif"


/*
 * msgdma_rx_csr configuration
 *
 */

#define ALT_MODULE_CLASS_msgdma_rx_csr altera_msgdma
#define MSGDMA_RX_CSR_BASE 0x18003f60
#define MSGDMA_RX_CSR_BURST_ENABLE 0
#define MSGDMA_RX_CSR_BURST_WRAPPING_SUPPORT 0
#define MSGDMA_RX_CSR_CHANNEL_ENABLE 0
#define MSGDMA_RX_CSR_CHANNEL_ENABLE_DERIVED 0
#define MSGDMA_RX_CSR_CHANNEL_WIDTH 8
#define MSGDMA_RX_CSR_DATA_FIFO_DEPTH 32
#define MSGDMA_RX_CSR_DATA_WIDTH 32
#define MSGDMA_RX_CSR_DESCRIPTOR_FIFO_DEPTH 128
#define MSGDMA_RX_CSR_DMA_MODE 2
#define MSGDMA_RX_CSR_ENHANCED_FEATURES 0
#define MSGDMA_RX_CSR_ERROR_ENABLE 1
#define MSGDMA_RX_CSR_ERROR_ENABLE_DERIVED 1
#define MSGDMA_RX_CSR_ERROR_WIDTH 8
#define MSGDMA_RX_CSR_IRQ -1
#define MSGDMA_RX_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MSGDMA_RX_CSR_MAX_BURST_COUNT 2
#define MSGDMA_RX_CSR_MAX_BYTE 2048
#define MSGDMA_RX_CSR_MAX_STRIDE 1
#define MSGDMA_RX_CSR_NAME "/dev/msgdma_rx_csr"
#define MSGDMA_RX_CSR_PACKET_ENABLE 1
#define MSGDMA_RX_CSR_PACKET_ENABLE_DERIVED 1
#define MSGDMA_RX_CSR_PREFETCHER_ENABLE 1
#define MSGDMA_RX_CSR_PROGRAMMABLE_BURST_ENABLE 0
#define MSGDMA_RX_CSR_RESPONSE_PORT 2
#define MSGDMA_RX_CSR_SPAN 32
#define MSGDMA_RX_CSR_STRIDE_ENABLE 0
#define MSGDMA_RX_CSR_STRIDE_ENABLE_DERIVED 0
#define MSGDMA_RX_CSR_TRANSFER_TYPE "Aligned Accesses"
#define MSGDMA_RX_CSR_TYPE "altera_msgdma"


/*
 * msgdma_rx_prefetcher_csr configuration
 *
 */

#define ALT_MODULE_CLASS_msgdma_rx_prefetcher_csr altera_msgdma
#define MSGDMA_RX_PREFETCHER_CSR_BASE 0x18003f20
#define MSGDMA_RX_PREFETCHER_CSR_BURST_ENABLE 0
#define MSGDMA_RX_PREFETCHER_CSR_BURST_WRAPPING_SUPPORT 0
#define MSGDMA_RX_PREFETCHER_CSR_CHANNEL_ENABLE 0
#define MSGDMA_RX_PREFETCHER_CSR_CHANNEL_ENABLE_DERIVED 0
#define MSGDMA_RX_PREFETCHER_CSR_CHANNEL_WIDTH 8
#define MSGDMA_RX_PREFETCHER_CSR_DATA_FIFO_DEPTH 32
#define MSGDMA_RX_PREFETCHER_CSR_DATA_WIDTH 32
#define MSGDMA_RX_PREFETCHER_CSR_DESCRIPTOR_FIFO_DEPTH 128
#define MSGDMA_RX_PREFETCHER_CSR_DMA_MODE 2
#define MSGDMA_RX_PREFETCHER_CSR_ENHANCED_FEATURES 0
#define MSGDMA_RX_PREFETCHER_CSR_ERROR_ENABLE 1
#define MSGDMA_RX_PREFETCHER_CSR_ERROR_ENABLE_DERIVED 1
#define MSGDMA_RX_PREFETCHER_CSR_ERROR_WIDTH 8
#define MSGDMA_RX_PREFETCHER_CSR_IRQ 1
#define MSGDMA_RX_PREFETCHER_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define MSGDMA_RX_PREFETCHER_CSR_MAX_BURST_COUNT 2
#define MSGDMA_RX_PREFETCHER_CSR_MAX_BYTE 2048
#define MSGDMA_RX_PREFETCHER_CSR_MAX_STRIDE 1
#define MSGDMA_RX_PREFETCHER_CSR_NAME "/dev/msgdma_rx_prefetcher_csr"
#define MSGDMA_RX_PREFETCHER_CSR_PACKET_ENABLE 1
#define MSGDMA_RX_PREFETCHER_CSR_PACKET_ENABLE_DERIVED 1
#define MSGDMA_RX_PREFETCHER_CSR_PREFETCHER_ENABLE 1
#define MSGDMA_RX_PREFETCHER_CSR_PROGRAMMABLE_BURST_ENABLE 0
#define MSGDMA_RX_PREFETCHER_CSR_RESPONSE_PORT 2
#define MSGDMA_RX_PREFETCHER_CSR_SPAN 32
#define MSGDMA_RX_PREFETCHER_CSR_STRIDE_ENABLE 0
#define MSGDMA_RX_PREFETCHER_CSR_STRIDE_ENABLE_DERIVED 0
#define MSGDMA_RX_PREFETCHER_CSR_TRANSFER_TYPE "Aligned Accesses"
#define MSGDMA_RX_PREFETCHER_CSR_TYPE "altera_msgdma"


/*
 * msgdma_tx_csr configuration
 *
 */

#define ALT_MODULE_CLASS_msgdma_tx_csr altera_msgdma
#define MSGDMA_TX_CSR_BASE 0x18003f80
#define MSGDMA_TX_CSR_BURST_ENABLE 0
#define MSGDMA_TX_CSR_BURST_WRAPPING_SUPPORT 0
#define MSGDMA_TX_CSR_CHANNEL_ENABLE 0
#define MSGDMA_TX_CSR_CHANNEL_ENABLE_DERIVED 0
#define MSGDMA_TX_CSR_CHANNEL_WIDTH 8
#define MSGDMA_TX_CSR_DATA_FIFO_DEPTH 32
#define MSGDMA_TX_CSR_DATA_WIDTH 32
#define MSGDMA_TX_CSR_DESCRIPTOR_FIFO_DEPTH 128
#define MSGDMA_TX_CSR_DMA_MODE 1
#define MSGDMA_TX_CSR_ENHANCED_FEATURES 0
#define MSGDMA_TX_CSR_ERROR_ENABLE 1
#define MSGDMA_TX_CSR_ERROR_ENABLE_DERIVED 1
#define MSGDMA_TX_CSR_ERROR_WIDTH 8
#define MSGDMA_TX_CSR_IRQ -1
#define MSGDMA_TX_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MSGDMA_TX_CSR_MAX_BURST_COUNT 2
#define MSGDMA_TX_CSR_MAX_BYTE 2048
#define MSGDMA_TX_CSR_MAX_STRIDE 1
#define MSGDMA_TX_CSR_NAME "/dev/msgdma_tx_csr"
#define MSGDMA_TX_CSR_PACKET_ENABLE 1
#define MSGDMA_TX_CSR_PACKET_ENABLE_DERIVED 1
#define MSGDMA_TX_CSR_PREFETCHER_ENABLE 1
#define MSGDMA_TX_CSR_PROGRAMMABLE_BURST_ENABLE 0
#define MSGDMA_TX_CSR_RESPONSE_PORT 2
#define MSGDMA_TX_CSR_SPAN 32
#define MSGDMA_TX_CSR_STRIDE_ENABLE 0
#define MSGDMA_TX_CSR_STRIDE_ENABLE_DERIVED 0
#define MSGDMA_TX_CSR_TRANSFER_TYPE "Aligned Accesses"
#define MSGDMA_TX_CSR_TYPE "altera_msgdma"


/*
 * msgdma_tx_prefetcher_csr configuration
 *
 */

#define ALT_MODULE_CLASS_msgdma_tx_prefetcher_csr altera_msgdma
#define MSGDMA_TX_PREFETCHER_CSR_BASE 0x18003f40
#define MSGDMA_TX_PREFETCHER_CSR_BURST_ENABLE 0
#define MSGDMA_TX_PREFETCHER_CSR_BURST_WRAPPING_SUPPORT 0
#define MSGDMA_TX_PREFETCHER_CSR_CHANNEL_ENABLE 0
#define MSGDMA_TX_PREFETCHER_CSR_CHANNEL_ENABLE_DERIVED 0
#define MSGDMA_TX_PREFETCHER_CSR_CHANNEL_WIDTH 8
#define MSGDMA_TX_PREFETCHER_CSR_DATA_FIFO_DEPTH 32
#define MSGDMA_TX_PREFETCHER_CSR_DATA_WIDTH 32
#define MSGDMA_TX_PREFETCHER_CSR_DESCRIPTOR_FIFO_DEPTH 128
#define MSGDMA_TX_PREFETCHER_CSR_DMA_MODE 1
#define MSGDMA_TX_PREFETCHER_CSR_ENHANCED_FEATURES 0
#define MSGDMA_TX_PREFETCHER_CSR_ERROR_ENABLE 1
#define MSGDMA_TX_PREFETCHER_CSR_ERROR_ENABLE_DERIVED 1
#define MSGDMA_TX_PREFETCHER_CSR_ERROR_WIDTH 8
#define MSGDMA_TX_PREFETCHER_CSR_IRQ 0
#define MSGDMA_TX_PREFETCHER_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define MSGDMA_TX_PREFETCHER_CSR_MAX_BURST_COUNT 2
#define MSGDMA_TX_PREFETCHER_CSR_MAX_BYTE 2048
#define MSGDMA_TX_PREFETCHER_CSR_MAX_STRIDE 1
#define MSGDMA_TX_PREFETCHER_CSR_NAME "/dev/msgdma_tx_prefetcher_csr"
#define MSGDMA_TX_PREFETCHER_CSR_PACKET_ENABLE 1
#define MSGDMA_TX_PREFETCHER_CSR_PACKET_ENABLE_DERIVED 1
#define MSGDMA_TX_PREFETCHER_CSR_PREFETCHER_ENABLE 1
#define MSGDMA_TX_PREFETCHER_CSR_PROGRAMMABLE_BURST_ENABLE 0
#define MSGDMA_TX_PREFETCHER_CSR_RESPONSE_PORT 2
#define MSGDMA_TX_PREFETCHER_CSR_SPAN 32
#define MSGDMA_TX_PREFETCHER_CSR_STRIDE_ENABLE 0
#define MSGDMA_TX_PREFETCHER_CSR_STRIDE_ENABLE_DERIVED 0
#define MSGDMA_TX_PREFETCHER_CSR_TRANSFER_TYPE "Aligned Accesses"
#define MSGDMA_TX_PREFETCHER_CSR_TYPE "altera_msgdma"


/*
 * onchip_ram configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_ram altera_avalon_onchip_memory2
#define ONCHIP_RAM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_RAM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_RAM_BASE 0x18002800
#define ONCHIP_RAM_CONTENTS_INFO ""
#define ONCHIP_RAM_DUAL_PORT 0
#define ONCHIP_RAM_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_RAM_INIT_CONTENTS_FILE "q_sys_onchip_ram"
#define ONCHIP_RAM_INIT_MEM_CONTENT 1
#define ONCHIP_RAM_INSTANCE_ID "NONE"
#define ONCHIP_RAM_IRQ -1
#define ONCHIP_RAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_RAM_NAME "/dev/onchip_ram"
#define ONCHIP_RAM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_RAM_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_RAM_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_RAM_SINGLE_CLOCK_OP 0
#define ONCHIP_RAM_SIZE_MULTIPLE 1
#define ONCHIP_RAM_SIZE_VALUE 2048
#define ONCHIP_RAM_SPAN 2048
#define ONCHIP_RAM_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_RAM_WRITABLE 1


/*
 * spi_rxm configuration
 *
 */

#define ALT_MODULE_CLASS_spi_rxm altera_avalon_spi
#define SPI_RXM_BASE 0x18003ee0
#define SPI_RXM_CLOCKMULT 1
#define SPI_RXM_CLOCKPHASE 0
#define SPI_RXM_CLOCKPOLARITY 0
#define SPI_RXM_CLOCKUNITS "Hz"
#define SPI_RXM_DATABITS 8
#define SPI_RXM_DATAWIDTH 16
#define SPI_RXM_DELAYMULT "1.0E-9"
#define SPI_RXM_DELAYUNITS "ns"
#define SPI_RXM_EXTRADELAY 0
#define SPI_RXM_INSERT_SYNC 0
#define SPI_RXM_IRQ -1
#define SPI_RXM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SPI_RXM_ISMASTER 1
#define SPI_RXM_LSBFIRST 0
#define SPI_RXM_NAME "/dev/spi_rxm"
#define SPI_RXM_NUMSLAVES 1
#define SPI_RXM_PREFIX "spi_"
#define SPI_RXM_SPAN 32
#define SPI_RXM_SYNC_REG_DEPTH 2
#define SPI_RXM_TARGETCLOCK 6250000u
#define SPI_RXM_TARGETSSDELAY "0.0"
#define SPI_RXM_TYPE "altera_avalon_spi"


/*
 * sys_clk_timer configuration
 *
 */

#define ALT_MODULE_CLASS_sys_clk_timer altera_avalon_timer
#define SYS_CLK_TIMER_ALWAYS_RUN 0
#define SYS_CLK_TIMER_BASE 0x18003f00
#define SYS_CLK_TIMER_COUNTER_SIZE 32
#define SYS_CLK_TIMER_FIXED_PERIOD 0
#define SYS_CLK_TIMER_FREQ 50000000
#define SYS_CLK_TIMER_IRQ 4
#define SYS_CLK_TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SYS_CLK_TIMER_LOAD_VALUE 499999
#define SYS_CLK_TIMER_MULT 0.001
#define SYS_CLK_TIMER_NAME "/dev/sys_clk_timer"
#define SYS_CLK_TIMER_PERIOD 10
#define SYS_CLK_TIMER_PERIOD_UNITS "ms"
#define SYS_CLK_TIMER_RESET_OUTPUT 0
#define SYS_CLK_TIMER_SNAPSHOT 1
#define SYS_CLK_TIMER_SPAN 32
#define SYS_CLK_TIMER_TICKS_PER_SEC 100
#define SYS_CLK_TIMER_TIMEOUT_PULSE_OUTPUT 0
#define SYS_CLK_TIMER_TYPE "altera_avalon_timer"


/*
 * sysid configuration
 *
 */

#define ALT_MODULE_CLASS_sysid altera_avalon_sysid_qsys
#define SYSID_BASE 0x18003ff0
#define SYSID_ID -87110914
#define SYSID_IRQ -1
#define SYSID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_NAME "/dev/sysid"
#define SYSID_SPAN 8
#define SYSID_TIMESTAMP 1666722890
#define SYSID_TYPE "altera_avalon_sysid_qsys"


/*
 * ucosii configuration
 *
 */

#define OS_ARG_CHK_EN 1
#define OS_CPU_HOOKS_EN 1
#define OS_DEBUG_EN 1
#define OS_EVENT_NAME_SIZE 32
#define OS_FLAGS_NBITS 16
#define OS_FLAG_ACCEPT_EN 1
#define OS_FLAG_DEL_EN 1
#define OS_FLAG_EN 1
#define OS_FLAG_NAME_SIZE 32
#define OS_FLAG_QUERY_EN 1
#define OS_FLAG_WAIT_CLR_EN 1
#define OS_LOWEST_PRIO 20
#define OS_MAX_EVENTS 60
#define OS_MAX_FLAGS 20
#define OS_MAX_MEM_PART 60
#define OS_MAX_QS 20
#define OS_MAX_TASKS 10
#define OS_MBOX_ACCEPT_EN 1
#define OS_MBOX_DEL_EN 1
#define OS_MBOX_EN 1
#define OS_MBOX_POST_EN 1
#define OS_MBOX_POST_OPT_EN 1
#define OS_MBOX_QUERY_EN 1
#define OS_MEM_EN 1
#define OS_MEM_NAME_SIZE 32
#define OS_MEM_QUERY_EN 1
#define OS_MUTEX_ACCEPT_EN 1
#define OS_MUTEX_DEL_EN 1
#define OS_MUTEX_EN 1
#define OS_MUTEX_QUERY_EN 1
#define OS_Q_ACCEPT_EN 1
#define OS_Q_DEL_EN 1
#define OS_Q_EN 1
#define OS_Q_FLUSH_EN 1
#define OS_Q_POST_EN 1
#define OS_Q_POST_FRONT_EN 1
#define OS_Q_POST_OPT_EN 1
#define OS_Q_QUERY_EN 1
#define OS_SCHED_LOCK_EN 1
#define OS_SEM_ACCEPT_EN 1
#define OS_SEM_DEL_EN 1
#define OS_SEM_EN 1
#define OS_SEM_QUERY_EN 1
#define OS_SEM_SET_EN 1
#define OS_TASK_CHANGE_PRIO_EN 1
#define OS_TASK_CREATE_EN 1
#define OS_TASK_CREATE_EXT_EN 1
#define OS_TASK_DEL_EN 1
#define OS_TASK_IDLE_STK_SIZE 512
#define OS_TASK_NAME_SIZE 32
#define OS_TASK_PROFILE_EN 1
#define OS_TASK_QUERY_EN 1
#define OS_TASK_STAT_EN 1
#define OS_TASK_STAT_STK_CHK_EN 1
#define OS_TASK_STAT_STK_SIZE 512
#define OS_TASK_SUSPEND_EN 1
#define OS_TASK_SW_HOOK_EN 1
#define OS_TASK_TMR_PRIO 0
#define OS_TASK_TMR_STK_SIZE 512
#define OS_THREAD_SAFE_NEWLIB 1
#define OS_TICKS_PER_SEC SYS_CLK_TIMER_TICKS_PER_SEC
#define OS_TICK_STEP_EN 1
#define OS_TIME_DLY_HMSM_EN 1
#define OS_TIME_DLY_RESUME_EN 1
#define OS_TIME_GET_SET_EN 1
#define OS_TIME_TICK_HOOK_EN 1
#define OS_TMR_CFG_MAX 16
#define OS_TMR_CFG_NAME_SIZE 16
#define OS_TMR_CFG_TICKS_PER_SEC 10
#define OS_TMR_CFG_WHEEL_SIZE 2
#define OS_TMR_EN 0

#endif /* __SYSTEM_H_ */
