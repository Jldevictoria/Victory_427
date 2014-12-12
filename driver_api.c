
//      SPACE INVADERS DMA DRIVER API.
// Joseph DeVictoria & Taylor Simons - 2014

//  perform_dma_copy() is a utility function that is meant to allow the user to perform 
//  a dma file copy of any given size from one address to another.
//  This function takes in a void pointer to the start address of the code that is meant to be
//  copied (source), a second void pointer to the start address of the location where the code is meant
//  to be placed (destination), and an integer value containing the number of bytes to be transferred (size).

void perform_dma_copy(void * source_address, void * destination_address, int transfer_size){
	// Convert transfer_size from bytes to number of transfers needed, per our hdl hardware.
	int transfer_count = transfer_size/4;
	// Set custom internal registers used to determine source, destination and number of tranfers.
	DMA_SCREENCAP_mWriteReg(XPAR_DMA_SCREENCAP_0_BASEADDR, DMA_SCREENCAP_SLV_REG1_OFFSET, start_address);
    DMA_SCREENCAP_mWriteReg(XPAR_DMA_SCREENCAP_0_BASEADDR, DMA_SCREENCAP_SLV_REG2_OFFSET, destination_address);
    DMA_SCREENCAP_mWriteReg(XPAR_DMA_SCREENCAP_0_BASEADDR, DMA_SCREENCAP_SLV_REG3_OFFSET, transfer_count);
	// Assert the mst_go signal responsible for initiating the hardware state machine that performs the copy.
	Xil_Out8(XPAR_DMA_SCREENCAP_0_BASEADDR+DMA_SCREENCAP_MST_GO_PORT_OFFSET, MST_START);
}

