// q_sys_eth_tse.v

// This file was auto-generated from altera_eth_tse_hw.tcl.  If you edit it your changes
// will probably be lost.
// 
// Generated using ACDS version 16.0 211

`timescale 1 ps / 1 ps
module q_sys_eth_tse (
		input  wire        clk,           // control_port_clock_connection.clk
		input  wire        reset,         //              reset_connection.reset
		input  wire [7:0]  reg_addr,      //                  control_port.address
		output wire [31:0] reg_data_out,  //                              .readdata
		input  wire        reg_rd,        //                              .read
		input  wire [31:0] reg_data_in,   //                              .writedata
		input  wire        reg_wr,        //                              .write
		output wire        reg_busy,      //                              .waitrequest
		input  wire        tx_clk,        //   pcs_mac_tx_clock_connection.clk
		input  wire        rx_clk,        //   pcs_mac_rx_clock_connection.clk
		input  wire        set_10,        //         mac_status_connection.set_10
		input  wire        set_1000,      //                              .set_1000
		output wire        eth_mode,      //                              .eth_mode
		output wire        ena_10,        //                              .ena_10
		input  wire [3:0]  rgmii_in,      //          mac_rgmii_connection.rgmii_in
		output wire [3:0]  rgmii_out,     //                              .rgmii_out
		input  wire        rx_control,    //                              .rx_control
		output wire        tx_control,    //                              .tx_control
		input  wire        ff_rx_clk,     //      receive_clock_connection.clk
		input  wire        ff_tx_clk,     //     transmit_clock_connection.clk
		output wire [31:0] ff_rx_data,    //                       receive.data
		output wire        ff_rx_eop,     //                              .endofpacket
		output wire [5:0]  rx_err,        //                              .error
		output wire [1:0]  ff_rx_mod,     //                              .empty
		input  wire        ff_rx_rdy,     //                              .ready
		output wire        ff_rx_sop,     //                              .startofpacket
		output wire        ff_rx_dval,    //                              .valid
		input  wire [31:0] ff_tx_data,    //                      transmit.data
		input  wire        ff_tx_eop,     //                              .endofpacket
		input  wire        ff_tx_err,     //                              .error
		input  wire [1:0]  ff_tx_mod,     //                              .empty
		output wire        ff_tx_rdy,     //                              .ready
		input  wire        ff_tx_sop,     //                              .startofpacket
		input  wire        ff_tx_wren,    //                              .valid
		output wire        mdc,           //           mac_mdio_connection.mdc
		input  wire        mdio_in,       //                              .mdio_in
		output wire        mdio_out,      //                              .mdio_out
		output wire        mdio_oen,      //                              .mdio_oen
		output wire        magic_wakeup,  //           mac_misc_connection.magic_wakeup
		input  wire        magic_sleep_n, //                              .magic_sleep_n
		input  wire        ff_tx_crc_fwd, //                              .ff_tx_crc_fwd
		output wire        ff_tx_septy,   //                              .ff_tx_septy
		output wire        tx_ff_uflow,   //                              .tx_ff_uflow
		output wire        ff_tx_a_full,  //                              .ff_tx_a_full
		output wire        ff_tx_a_empty, //                              .ff_tx_a_empty
		output wire [17:0] rx_err_stat,   //                              .rx_err_stat
		output wire [3:0]  rx_frm_type,   //                              .rx_frm_type
		output wire        ff_rx_dsav,    //                              .ff_rx_dsav
		output wire        ff_rx_a_full,  //                              .ff_rx_a_full
		output wire        ff_rx_a_empty  //                              .ff_rx_a_empty
	);

	wire  [3:0] i_tse_mac_rgmii_in4_pad_export;   // i_tse_mac:rgmii_in4_pad -> rgmii_in4_0:pad_in
	wire  [7:0] rgmii_in4_0_dout_export;          // rgmii_in4_0:dout -> i_tse_mac:rgmii_in4_dout
	wire        i_tse_mac_rgmii_in4_ck_export;    // i_tse_mac:rgmii_in4_ck -> rgmii_in4_0:inclock
	wire        i_tse_mac_rgmii_in1_pad_export;   // i_tse_mac:rgmii_in1_pad -> rgmii_in1_0:pad_in
	wire  [1:0] rgmii_in1_0_dout_export;          // rgmii_in1_0:dout -> i_tse_mac:rgmii_in1_dout
	wire        i_tse_mac_rgmii_in1_ck_export;    // i_tse_mac:rgmii_in1_ck -> rgmii_in1_0:inclock
	wire  [3:0] rgmii_out4_0_pad_out_export;      // rgmii_out4_0:pad_out -> i_tse_mac:rgmii_out4_pad
	wire  [7:0] i_tse_mac_rgmii_out4_din_export;  // i_tse_mac:rgmii_out4_din -> rgmii_out4_0:din
	wire        i_tse_mac_rgmii_out4_ck_export;   // i_tse_mac:rgmii_out4_ck -> rgmii_out4_0:outclock
	wire        i_tse_mac_rgmii_out4_aclr_export; // i_tse_mac:rgmii_out4_aclr -> rgmii_out4_0:aclr
	wire  [0:0] rgmii_out1_0_pad_out_export;      // rgmii_out1_0:pad_out -> i_tse_mac:rgmii_out1_pad
	wire  [1:0] i_tse_mac_rgmii_out1_din_export;  // i_tse_mac:rgmii_out1_din -> rgmii_out1_0:din
	wire        i_tse_mac_rgmii_out1_ck_export;   // i_tse_mac:rgmii_out1_ck -> rgmii_out1_0:outclock
	wire        i_tse_mac_rgmii_out1_aclr_export; // i_tse_mac:rgmii_out1_aclr -> rgmii_out1_0:aclr

	altera_eth_tse_mac #(
		.ING_ADDR                 (11),
		.ENABLE_MAC_RX_VLAN       (0),
		.ENABLE_SUP_ADDR          (0),
		.DEVICE_FAMILY            ("MAX10"),
		.INSERT_TA                (0),
		.ING_FIFO                 (2048),
		.ENABLE_ECC               (0),
		.CRC32DWIDTH              (8),
		.ENABLE_ENA               (32),
		.SYNCHRONIZER_DEPTH       (3),
		.ENABLE_MAC_TX_VLAN       (0),
		.RESET_LEVEL              (1),
		.STAT_CNT_ENA             (1),
		.CUST_VERSION             (0),
		.CRC32S1L2_EXTERN         (0),
		.MBIT_ONLY                (1),
		.EG_ADDR                  (11),
		.CORE_VERSION             (4096),
		.CRC32GENDELAY            (6),
		.EG_FIFO                  (2048),
		.REDUCED_INTERFACE_ENA    (1),
		.ENABLE_MAGIC_DETECT      (1),
		.ENABLE_MDIO              (1),
		.ENABLE_MAC_TXADDR_SET    (1),
		.RAM_TYPE                 ("AUTO"),
		.CRC32CHECK16BIT          (0),
		.ENABLE_LGTH_CHECK        (1),
		.ENABLE_MAC_FLOW_CTRL     (0),
		.ENABLE_SHIFT16           (1),
		.USE_SYNC_RESET           (1),
		.REDUCED_CONTROL          (0),
		.MDIO_CLK_DIV             (40),
		.ENABLE_PADDING           (1),
		.ENABLE_GMII_LOOPBACK     (0),
		.GBIT_ONLY                (1),
		.ENA_HASH                 (0),
		.ENABLE_EXTENDED_STAT_REG (0),
		.ENABLE_HD_LOGIC          (0)
	) i_tse_mac (
		.clk             (clk),                              // control_port_clock_connection.clk
		.reset           (reset),                            //              reset_connection.reset
		.reg_addr        (reg_addr),                         //                  control_port.address
		.reg_data_out    (reg_data_out),                     //                              .readdata
		.reg_rd          (reg_rd),                           //                              .read
		.reg_data_in     (reg_data_in),                      //                              .writedata
		.reg_wr          (reg_wr),                           //                              .write
		.reg_busy        (reg_busy),                         //                              .waitrequest
		.ff_tx_clk       (ff_tx_clk),                        //     transmit_clock_connection.clk
		.ff_rx_clk       (ff_rx_clk),                        //      receive_clock_connection.clk
		.ff_rx_data      (ff_rx_data),                       //                       receive.data
		.ff_rx_eop       (ff_rx_eop),                        //                              .endofpacket
		.rx_err          (rx_err),                           //                              .error
		.ff_rx_mod       (ff_rx_mod),                        //                              .empty
		.ff_rx_rdy       (ff_rx_rdy),                        //                              .ready
		.ff_rx_sop       (ff_rx_sop),                        //                              .startofpacket
		.ff_rx_dval      (ff_rx_dval),                       //                              .valid
		.ff_tx_data      (ff_tx_data),                       //                      transmit.data
		.ff_tx_eop       (ff_tx_eop),                        //                              .endofpacket
		.ff_tx_err       (ff_tx_err),                        //                              .error
		.ff_tx_mod       (ff_tx_mod),                        //                              .empty
		.ff_tx_rdy       (ff_tx_rdy),                        //                              .ready
		.ff_tx_sop       (ff_tx_sop),                        //                              .startofpacket
		.ff_tx_wren      (ff_tx_wren),                       //                              .valid
		.magic_wakeup    (magic_wakeup),                     //           mac_misc_connection.export
		.magic_sleep_n   (magic_sleep_n),                    //                              .export
		.ff_tx_crc_fwd   (ff_tx_crc_fwd),                    //                              .export
		.ff_tx_septy     (ff_tx_septy),                      //                              .export
		.tx_ff_uflow     (tx_ff_uflow),                      //                              .export
		.ff_tx_a_full    (ff_tx_a_full),                     //                              .export
		.ff_tx_a_empty   (ff_tx_a_empty),                    //                              .export
		.rx_err_stat     (rx_err_stat),                      //                              .export
		.rx_frm_type     (rx_frm_type),                      //                              .export
		.ff_rx_dsav      (ff_rx_dsav),                       //                              .export
		.ff_rx_a_full    (ff_rx_a_full),                     //                              .export
		.ff_rx_a_empty   (ff_rx_a_empty),                    //                              .export
		.mdc             (mdc),                              //           mac_mdio_connection.mdc
		.mdio_in         (mdio_in),                          //                              .mdio_in
		.mdio_out        (mdio_out),                         //                              .mdio_out
		.mdio_oen        (mdio_oen),                         //                              .mdio_oen
		.rgmii_out1_aclr (i_tse_mac_rgmii_out1_aclr_export), //               rgmii_out1_aclr.export
		.rgmii_out1_din  (i_tse_mac_rgmii_out1_din_export),  //                rgmii_out1_din.export
		.rgmii_in1_dout  (rgmii_in1_0_dout_export),          //                rgmii_in1_dout.export
		.rgmii_in1_ck    (i_tse_mac_rgmii_in1_ck_export),    //                  rgmii_in1_ck.export
		.rgmii_out4_din  (i_tse_mac_rgmii_out4_din_export),  //                rgmii_out4_din.export
		.rgmii_out4_ck   (i_tse_mac_rgmii_out4_ck_export),   //                 rgmii_out4_ck.export
		.rgmii_in1_pad   (i_tse_mac_rgmii_in1_pad_export),   //                 rgmii_in1_pad.export
		.rgmii_out4_aclr (i_tse_mac_rgmii_out4_aclr_export), //               rgmii_out4_aclr.export
		.rgmii_out1_pad  (rgmii_out1_0_pad_out_export),      //                rgmii_out1_pad.export
		.rgmii_out1_ck   (i_tse_mac_rgmii_out1_ck_export),   //                 rgmii_out1_ck.export
		.rgmii_in4_dout  (rgmii_in4_0_dout_export),          //                rgmii_in4_dout.export
		.rgmii_in4_pad   (i_tse_mac_rgmii_in4_pad_export),   //                 rgmii_in4_pad.export
		.rgmii_out4_pad  (rgmii_out4_0_pad_out_export),      //                rgmii_out4_pad.export
		.rgmii_in4_ck    (i_tse_mac_rgmii_in4_ck_export),    //                  rgmii_in4_ck.export
		.rgmii_in        (rgmii_in),                         //          mac_rgmii_connection.rgmii_in
		.rgmii_out       (rgmii_out),                        //                              .rgmii_out
		.rx_control      (rx_control),                       //                              .rx_control
		.tx_control      (tx_control),                       //                              .tx_control
		.set_10          (set_10),                           //         mac_status_connection.set_10
		.set_1000        (set_1000),                         //                              .set_1000
		.eth_mode        (eth_mode),                         //                              .eth_mode
		.ena_10          (ena_10),                           //                              .ena_10
		.tx_clk          (tx_clk),                           //   pcs_mac_tx_clock_connection.clk
		.rx_clk          (rx_clk),                           //   pcs_mac_rx_clock_connection.clk
		.rx_clkena       (1'b1),                             //                   (terminated)
		.tx_clkena       (1'b1),                             //                   (terminated)
		.xon_gen         (1'b0),                             //                   (terminated)
		.xoff_gen        (1'b0),                             //                   (terminated)
		.mac_eccstatus   (),                                 //                   (terminated)
		.gm_rx_d         (8'b00000000),                      //                   (terminated)
		.gm_rx_dv        (1'b0),                             //                   (terminated)
		.gm_rx_err       (1'b0),                             //                   (terminated)
		.gm_tx_d         (),                                 //                   (terminated)
		.gm_tx_en        (),                                 //                   (terminated)
		.gm_tx_err       (),                                 //                   (terminated)
		.m_rx_d          (4'b0000),                          //                   (terminated)
		.m_rx_en         (1'b0),                             //                   (terminated)
		.m_rx_err        (1'b0),                             //                   (terminated)
		.m_tx_d          (),                                 //                   (terminated)
		.m_tx_en         (),                                 //                   (terminated)
		.m_tx_err        (),                                 //                   (terminated)
		.m_rx_crs        (1'b0),                             //                   (terminated)
		.m_rx_col        (1'b0)                              //                   (terminated)
	);

	altera_gpio_lite #(
		.PIN_TYPE                                 ("input"),
		.SIZE                                     (4),
		.REGISTER_MODE                            ("ddr"),
		.BUFFER_TYPE                              ("single-ended"),
		.ASYNC_MODE                               ("none"),
		.SYNC_MODE                                ("none"),
		.BUS_HOLD                                 ("false"),
		.OPEN_DRAIN_OUTPUT                        ("false"),
		.ENABLE_OE_PORT                           ("false"),
		.ENABLE_NSLEEP_PORT                       ("false"),
		.ENABLE_CLOCK_ENA_PORT                    ("false"),
		.SET_REGISTER_OUTPUTS_HIGH                ("false"),
		.INVERT_OUTPUT                            ("false"),
		.INVERT_INPUT_CLOCK                       ("false"),
		.USE_ONE_REG_TO_DRIVE_OE                  ("false"),
		.USE_DDIO_REG_TO_DRIVE_OE                 ("false"),
		.USE_ADVANCED_DDR_FEATURES                ("false"),
		.USE_ADVANCED_DDR_FEATURES_FOR_INPUT_ONLY ("false"),
		.ENABLE_OE_HALF_CYCLE_DELAY               ("true"),
		.INVERT_CLKDIV_INPUT_CLOCK                ("false"),
		.ENABLE_PHASE_INVERT_CTRL_PORT            ("false"),
		.ENABLE_HR_CLOCK                          ("false"),
		.INVERT_OUTPUT_CLOCK                      ("false"),
		.INVERT_OE_INCLOCK                        ("false"),
		.ENABLE_PHASE_DETECTOR_FOR_CK             ("false")
	) rgmii_in4_0 (
		.inclock         (i_tse_mac_rgmii_in4_ck_export),  // inclock.export
		.dout            (rgmii_in4_0_dout_export),        //    dout.export
		.pad_in          (i_tse_mac_rgmii_in4_pad_export), //  pad_in.export
		.inclocken       (1'b1),                           // (terminated)
		.fr_clock        (),                               // (terminated)
		.hr_clock        (),                               // (terminated)
		.invert_hr_clock (1'b0),                           // (terminated)
		.outclock        (1'b0),                           // (terminated)
		.outclocken      (1'b0),                           // (terminated)
		.phy_mem_clock   (1'b0),                           // (terminated)
		.mimic_clock     (),                               // (terminated)
		.din             (8'b00000000),                    // (terminated)
		.pad_io          (),                               // (terminated)
		.pad_io_b        (),                               // (terminated)
		.pad_in_b        (4'b0000),                        // (terminated)
		.pad_out         (),                               // (terminated)
		.pad_out_b       (),                               // (terminated)
		.aset            (1'b0),                           // (terminated)
		.aclr            (1'b0),                           // (terminated)
		.sclr            (1'b0),                           // (terminated)
		.nsleep          (4'b0000),                        // (terminated)
		.oe              (4'b0000)                         // (terminated)
	);

	altera_gpio_lite #(
		.PIN_TYPE                                 ("input"),
		.SIZE                                     (1),
		.REGISTER_MODE                            ("ddr"),
		.BUFFER_TYPE                              ("single-ended"),
		.ASYNC_MODE                               ("none"),
		.SYNC_MODE                                ("none"),
		.BUS_HOLD                                 ("false"),
		.OPEN_DRAIN_OUTPUT                        ("false"),
		.ENABLE_OE_PORT                           ("false"),
		.ENABLE_NSLEEP_PORT                       ("false"),
		.ENABLE_CLOCK_ENA_PORT                    ("false"),
		.SET_REGISTER_OUTPUTS_HIGH                ("false"),
		.INVERT_OUTPUT                            ("false"),
		.INVERT_INPUT_CLOCK                       ("false"),
		.USE_ONE_REG_TO_DRIVE_OE                  ("false"),
		.USE_DDIO_REG_TO_DRIVE_OE                 ("false"),
		.USE_ADVANCED_DDR_FEATURES                ("false"),
		.USE_ADVANCED_DDR_FEATURES_FOR_INPUT_ONLY ("false"),
		.ENABLE_OE_HALF_CYCLE_DELAY               ("true"),
		.INVERT_CLKDIV_INPUT_CLOCK                ("false"),
		.ENABLE_PHASE_INVERT_CTRL_PORT            ("false"),
		.ENABLE_HR_CLOCK                          ("false"),
		.INVERT_OUTPUT_CLOCK                      ("false"),
		.INVERT_OE_INCLOCK                        ("false"),
		.ENABLE_PHASE_DETECTOR_FOR_CK             ("false")
	) rgmii_in1_0 (
		.inclock         (i_tse_mac_rgmii_in1_ck_export),  // inclock.export
		.dout            (rgmii_in1_0_dout_export),        //    dout.export
		.pad_in          (i_tse_mac_rgmii_in1_pad_export), //  pad_in.export
		.inclocken       (1'b1),                           // (terminated)
		.fr_clock        (),                               // (terminated)
		.hr_clock        (),                               // (terminated)
		.invert_hr_clock (1'b0),                           // (terminated)
		.outclock        (1'b0),                           // (terminated)
		.outclocken      (1'b0),                           // (terminated)
		.phy_mem_clock   (1'b0),                           // (terminated)
		.mimic_clock     (),                               // (terminated)
		.din             (2'b00),                          // (terminated)
		.pad_io          (),                               // (terminated)
		.pad_io_b        (),                               // (terminated)
		.pad_in_b        (1'b0),                           // (terminated)
		.pad_out         (),                               // (terminated)
		.pad_out_b       (),                               // (terminated)
		.aset            (1'b0),                           // (terminated)
		.aclr            (1'b0),                           // (terminated)
		.sclr            (1'b0),                           // (terminated)
		.nsleep          (1'b0),                           // (terminated)
		.oe              (1'b0)                            // (terminated)
	);

	altera_gpio_lite #(
		.PIN_TYPE                                 ("output"),
		.SIZE                                     (4),
		.REGISTER_MODE                            ("ddr"),
		.BUFFER_TYPE                              ("single-ended"),
		.ASYNC_MODE                               ("clear"),
		.SYNC_MODE                                ("none"),
		.BUS_HOLD                                 ("false"),
		.OPEN_DRAIN_OUTPUT                        ("false"),
		.ENABLE_OE_PORT                           ("false"),
		.ENABLE_NSLEEP_PORT                       ("false"),
		.ENABLE_CLOCK_ENA_PORT                    ("false"),
		.SET_REGISTER_OUTPUTS_HIGH                ("false"),
		.INVERT_OUTPUT                            ("false"),
		.INVERT_INPUT_CLOCK                       ("false"),
		.USE_ONE_REG_TO_DRIVE_OE                  ("false"),
		.USE_DDIO_REG_TO_DRIVE_OE                 ("false"),
		.USE_ADVANCED_DDR_FEATURES                ("false"),
		.USE_ADVANCED_DDR_FEATURES_FOR_INPUT_ONLY ("false"),
		.ENABLE_OE_HALF_CYCLE_DELAY               ("true"),
		.INVERT_CLKDIV_INPUT_CLOCK                ("false"),
		.ENABLE_PHASE_INVERT_CTRL_PORT            ("false"),
		.ENABLE_HR_CLOCK                          ("false"),
		.INVERT_OUTPUT_CLOCK                      ("false"),
		.INVERT_OE_INCLOCK                        ("false"),
		.ENABLE_PHASE_DETECTOR_FOR_CK             ("false")
	) rgmii_out4_0 (
		.outclock        (i_tse_mac_rgmii_out4_ck_export),   // outclock.export
		.din             (i_tse_mac_rgmii_out4_din_export),  //      din.export
		.pad_out         (rgmii_out4_0_pad_out_export),      //  pad_out.export
		.aclr            (i_tse_mac_rgmii_out4_aclr_export), //     aclr.export
		.outclocken      (1'b1),                             // (terminated)
		.inclock         (1'b0),                             // (terminated)
		.inclocken       (1'b0),                             // (terminated)
		.fr_clock        (),                                 // (terminated)
		.hr_clock        (),                                 // (terminated)
		.invert_hr_clock (1'b0),                             // (terminated)
		.phy_mem_clock   (1'b0),                             // (terminated)
		.mimic_clock     (),                                 // (terminated)
		.dout            (),                                 // (terminated)
		.pad_io          (),                                 // (terminated)
		.pad_io_b        (),                                 // (terminated)
		.pad_in          (4'b0000),                          // (terminated)
		.pad_in_b        (4'b0000),                          // (terminated)
		.pad_out_b       (),                                 // (terminated)
		.aset            (1'b0),                             // (terminated)
		.sclr            (1'b0),                             // (terminated)
		.nsleep          (4'b0000),                          // (terminated)
		.oe              (4'b0000)                           // (terminated)
	);

	altera_gpio_lite #(
		.PIN_TYPE                                 ("output"),
		.SIZE                                     (1),
		.REGISTER_MODE                            ("ddr"),
		.BUFFER_TYPE                              ("single-ended"),
		.ASYNC_MODE                               ("clear"),
		.SYNC_MODE                                ("none"),
		.BUS_HOLD                                 ("false"),
		.OPEN_DRAIN_OUTPUT                        ("false"),
		.ENABLE_OE_PORT                           ("false"),
		.ENABLE_NSLEEP_PORT                       ("false"),
		.ENABLE_CLOCK_ENA_PORT                    ("false"),
		.SET_REGISTER_OUTPUTS_HIGH                ("false"),
		.INVERT_OUTPUT                            ("false"),
		.INVERT_INPUT_CLOCK                       ("false"),
		.USE_ONE_REG_TO_DRIVE_OE                  ("false"),
		.USE_DDIO_REG_TO_DRIVE_OE                 ("false"),
		.USE_ADVANCED_DDR_FEATURES                ("false"),
		.USE_ADVANCED_DDR_FEATURES_FOR_INPUT_ONLY ("false"),
		.ENABLE_OE_HALF_CYCLE_DELAY               ("true"),
		.INVERT_CLKDIV_INPUT_CLOCK                ("false"),
		.ENABLE_PHASE_INVERT_CTRL_PORT            ("false"),
		.ENABLE_HR_CLOCK                          ("false"),
		.INVERT_OUTPUT_CLOCK                      ("false"),
		.INVERT_OE_INCLOCK                        ("false"),
		.ENABLE_PHASE_DETECTOR_FOR_CK             ("false")
	) rgmii_out1_0 (
		.outclock        (i_tse_mac_rgmii_out1_ck_export),   // outclock.export
		.din             (i_tse_mac_rgmii_out1_din_export),  //      din.export
		.pad_out         (rgmii_out1_0_pad_out_export),      //  pad_out.export
		.aclr            (i_tse_mac_rgmii_out1_aclr_export), //     aclr.export
		.outclocken      (1'b1),                             // (terminated)
		.inclock         (1'b0),                             // (terminated)
		.inclocken       (1'b0),                             // (terminated)
		.fr_clock        (),                                 // (terminated)
		.hr_clock        (),                                 // (terminated)
		.invert_hr_clock (1'b0),                             // (terminated)
		.phy_mem_clock   (1'b0),                             // (terminated)
		.mimic_clock     (),                                 // (terminated)
		.dout            (),                                 // (terminated)
		.pad_io          (),                                 // (terminated)
		.pad_io_b        (),                                 // (terminated)
		.pad_in          (1'b0),                             // (terminated)
		.pad_in_b        (1'b0),                             // (terminated)
		.pad_out_b       (),                                 // (terminated)
		.aset            (1'b0),                             // (terminated)
		.sclr            (1'b0),                             // (terminated)
		.nsleep          (1'b0),                             // (terminated)
		.oe              (1'b0)                              // (terminated)
	);

endmodule
