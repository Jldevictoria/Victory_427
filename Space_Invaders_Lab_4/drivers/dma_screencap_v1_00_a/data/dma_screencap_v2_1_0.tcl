##############################################################################
## Filename:          C:\Victory_427\Space_Invaders_Lab_4/drivers/dma_screencap_v1_00_a/data/dma_screencap_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Thu Dec 04 17:44:41 2014 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "dma_screencap" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
