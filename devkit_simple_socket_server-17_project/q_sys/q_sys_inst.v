	q_sys u0 (
		.altpll_shift_c0_clk                         (<connected-to-altpll_shift_c0_clk>),                         //                     altpll_shift_c0.clk
		.altpll_shift_locked_conduit_export          (<connected-to-altpll_shift_locked_conduit_export>),          //         altpll_shift_locked_conduit.export
		.clock_bridge_0_in_clk_clk                   (<connected-to-clock_bridge_0_in_clk_clk>),                   //               clock_bridge_0_in_clk.clk
		.enet_pll_c0_clk                             (<connected-to-enet_pll_c0_clk>),                             //                         enet_pll_c0.clk
		.enet_pll_c1_clk                             (<connected-to-enet_pll_c1_clk>),                             //                         enet_pll_c1.clk
		.enet_pll_c2_clk                             (<connected-to-enet_pll_c2_clk>),                             //                         enet_pll_c2.clk
		.enet_pll_c3_clk                             (<connected-to-enet_pll_c3_clk>),                             //                         enet_pll_c3.clk
		.enet_pll_c4_clk                             (<connected-to-enet_pll_c4_clk>),                             //                         enet_pll_c4.clk
		.enet_pll_locked_conduit_export              (<connected-to-enet_pll_locked_conduit_export>),              //             enet_pll_locked_conduit.export
		.eth_tse_mac_mdio_connection_mdc             (<connected-to-eth_tse_mac_mdio_connection_mdc>),             //         eth_tse_mac_mdio_connection.mdc
		.eth_tse_mac_mdio_connection_mdio_in         (<connected-to-eth_tse_mac_mdio_connection_mdio_in>),         //                                    .mdio_in
		.eth_tse_mac_mdio_connection_mdio_out        (<connected-to-eth_tse_mac_mdio_connection_mdio_out>),        //                                    .mdio_out
		.eth_tse_mac_mdio_connection_mdio_oen        (<connected-to-eth_tse_mac_mdio_connection_mdio_oen>),        //                                    .mdio_oen
		.eth_tse_mac_rgmii_connection_rgmii_in       (<connected-to-eth_tse_mac_rgmii_connection_rgmii_in>),       //        eth_tse_mac_rgmii_connection.rgmii_in
		.eth_tse_mac_rgmii_connection_rgmii_out      (<connected-to-eth_tse_mac_rgmii_connection_rgmii_out>),      //                                    .rgmii_out
		.eth_tse_mac_rgmii_connection_rx_control     (<connected-to-eth_tse_mac_rgmii_connection_rx_control>),     //                                    .rx_control
		.eth_tse_mac_rgmii_connection_tx_control     (<connected-to-eth_tse_mac_rgmii_connection_tx_control>),     //                                    .tx_control
		.eth_tse_mac_status_connection_set_10        (<connected-to-eth_tse_mac_status_connection_set_10>),        //       eth_tse_mac_status_connection.set_10
		.eth_tse_mac_status_connection_set_1000      (<connected-to-eth_tse_mac_status_connection_set_1000>),      //                                    .set_1000
		.eth_tse_mac_status_connection_eth_mode      (<connected-to-eth_tse_mac_status_connection_eth_mode>),      //                                    .eth_mode
		.eth_tse_mac_status_connection_ena_10        (<connected-to-eth_tse_mac_status_connection_ena_10>),        //                                    .ena_10
		.eth_tse_pcs_mac_rx_clock_connection_clk     (<connected-to-eth_tse_pcs_mac_rx_clock_connection_clk>),     // eth_tse_pcs_mac_rx_clock_connection.clk
		.eth_tse_pcs_mac_tx_clock_connection_clk     (<connected-to-eth_tse_pcs_mac_tx_clock_connection_clk>),     // eth_tse_pcs_mac_tx_clock_connection.clk
		.ext_flash_flash_dataout_conduit_dataout     (<connected-to-ext_flash_flash_dataout_conduit_dataout>),     //             ext_flash_flash_dataout.conduit_dataout
		.ext_flash_flash_dclk_out_conduit_dclk_out   (<connected-to-ext_flash_flash_dclk_out_conduit_dclk_out>),   //            ext_flash_flash_dclk_out.conduit_dclk_out
		.ext_flash_flash_ncs_conduit_ncs             (<connected-to-ext_flash_flash_ncs_conduit_ncs>),             //                 ext_flash_flash_ncs.conduit_ncs
		.i2c_ckm_c0_i2c_serial_sda_in                (<connected-to-i2c_ckm_c0_i2c_serial_sda_in>),                //               i2c_ckm_c0_i2c_serial.sda_in
		.i2c_ckm_c0_i2c_serial_scl_in                (<connected-to-i2c_ckm_c0_i2c_serial_scl_in>),                //                                    .scl_in
		.i2c_ckm_c0_i2c_serial_sda_oe                (<connected-to-i2c_ckm_c0_i2c_serial_sda_oe>),                //                                    .sda_oe
		.i2c_ckm_c0_i2c_serial_scl_oe                (<connected-to-i2c_ckm_c0_i2c_serial_scl_oe>),                //                                    .scl_oe
		.i2c_ckm_id_i2c_serial_sda_in                (<connected-to-i2c_ckm_id_i2c_serial_sda_in>),                //               i2c_ckm_id_i2c_serial.sda_in
		.i2c_ckm_id_i2c_serial_scl_in                (<connected-to-i2c_ckm_id_i2c_serial_scl_in>),                //                                    .scl_in
		.i2c_ckm_id_i2c_serial_sda_oe                (<connected-to-i2c_ckm_id_i2c_serial_sda_oe>),                //                                    .sda_oe
		.i2c_ckm_id_i2c_serial_scl_oe                (<connected-to-i2c_ckm_id_i2c_serial_scl_oe>),                //                                    .scl_oe
		.i2c_rxm_ctrl_i2c_serial_sda_in              (<connected-to-i2c_rxm_ctrl_i2c_serial_sda_in>),              //             i2c_rxm_ctrl_i2c_serial.sda_in
		.i2c_rxm_ctrl_i2c_serial_scl_in              (<connected-to-i2c_rxm_ctrl_i2c_serial_scl_in>),              //                                    .scl_in
		.i2c_rxm_ctrl_i2c_serial_sda_oe              (<connected-to-i2c_rxm_ctrl_i2c_serial_sda_oe>),              //                                    .sda_oe
		.i2c_rxm_ctrl_i2c_serial_scl_oe              (<connected-to-i2c_rxm_ctrl_i2c_serial_scl_oe>),              //                                    .scl_oe
		.i2c_rxm_id_i2c_serial_sda_in                (<connected-to-i2c_rxm_id_i2c_serial_sda_in>),                //               i2c_rxm_id_i2c_serial.sda_in
		.i2c_rxm_id_i2c_serial_scl_in                (<connected-to-i2c_rxm_id_i2c_serial_scl_in>),                //                                    .scl_in
		.i2c_rxm_id_i2c_serial_sda_oe                (<connected-to-i2c_rxm_id_i2c_serial_sda_oe>),                //                                    .sda_oe
		.i2c_rxm_id_i2c_serial_scl_oe                (<connected-to-i2c_rxm_id_i2c_serial_scl_oe>),                //                                    .scl_oe
		.led_pio_external_connection_export          (<connected-to-led_pio_external_connection_export>),          //         led_pio_external_connection.export
		.mem_if_ddr3_emif_0_status_local_init_done   (<connected-to-mem_if_ddr3_emif_0_status_local_init_done>),   //           mem_if_ddr3_emif_0_status.local_init_done
		.mem_if_ddr3_emif_0_status_local_cal_success (<connected-to-mem_if_ddr3_emif_0_status_local_cal_success>), //                                    .local_cal_success
		.mem_if_ddr3_emif_0_status_local_cal_fail    (<connected-to-mem_if_ddr3_emif_0_status_local_cal_fail>),    //                                    .local_cal_fail
		.mem_resetn_in_reset_reset_n                 (<connected-to-mem_resetn_in_reset_reset_n>),                 //                 mem_resetn_in_reset.reset_n
		.memory_mem_a                                (<connected-to-memory_mem_a>),                                //                              memory.mem_a
		.memory_mem_ba                               (<connected-to-memory_mem_ba>),                               //                                    .mem_ba
		.memory_mem_ck                               (<connected-to-memory_mem_ck>),                               //                                    .mem_ck
		.memory_mem_ck_n                             (<connected-to-memory_mem_ck_n>),                             //                                    .mem_ck_n
		.memory_mem_cke                              (<connected-to-memory_mem_cke>),                              //                                    .mem_cke
		.memory_mem_cs_n                             (<connected-to-memory_mem_cs_n>),                             //                                    .mem_cs_n
		.memory_mem_dm                               (<connected-to-memory_mem_dm>),                               //                                    .mem_dm
		.memory_mem_ras_n                            (<connected-to-memory_mem_ras_n>),                            //                                    .mem_ras_n
		.memory_mem_cas_n                            (<connected-to-memory_mem_cas_n>),                            //                                    .mem_cas_n
		.memory_mem_we_n                             (<connected-to-memory_mem_we_n>),                             //                                    .mem_we_n
		.memory_mem_reset_n                          (<connected-to-memory_mem_reset_n>),                          //                                    .mem_reset_n
		.memory_mem_dq                               (<connected-to-memory_mem_dq>),                               //                                    .mem_dq
		.memory_mem_dqs                              (<connected-to-memory_mem_dqs>),                              //                                    .mem_dqs
		.memory_mem_dqs_n                            (<connected-to-memory_mem_dqs_n>),                            //                                    .mem_dqs_n
		.memory_mem_odt                              (<connected-to-memory_mem_odt>),                              //                                    .mem_odt
		.reset_reset_n                               (<connected-to-reset_reset_n>),                               //                               reset.reset_n
		.spi_rxm_external_MISO                       (<connected-to-spi_rxm_external_MISO>),                       //                    spi_rxm_external.MISO
		.spi_rxm_external_MOSI                       (<connected-to-spi_rxm_external_MOSI>),                       //                                    .MOSI
		.spi_rxm_external_SCLK                       (<connected-to-spi_rxm_external_SCLK>),                       //                                    .SCLK
		.spi_rxm_external_SS_n                       (<connected-to-spi_rxm_external_SS_n>),                       //                                    .SS_n
		.sys_clk_clk                                 (<connected-to-sys_clk_clk>)                                  //                             sys_clk.clk
	);

