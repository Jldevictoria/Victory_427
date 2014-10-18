/*
 * space_invaders_main.c
 *
 * Copyright (c) 2009 Xilinx, Inc.  All rights reserved.
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Taylor Simons + Joseph DeVictoria
 * ECEN 425 Lab 3 aliens source.
 */

// Includes
#include <stdio.h>
#include "bitmap.h"
#include "letters.h"
#include "platform.h"
#include "xparameters.h"
#include "xaxivdma.h"
#include "xgpio.h"
#include "xio.h"
#include "time.h"
#include "unistd.h"
#include "mb_interface.h"
#include "xintc_l.h"
#include "globals.h"

unsigned int * framePointer = (unsigned int *) FRAME_BUFFER_0_ADDR;

XGpio gpPB;   // This is a handle for the push-button GPIO block.

void pollButtons(){
	if((fit_counter % TANK_SPEED) == 0){
		currentButtonState = XGpio_DiscreteRead(&gpPB, 1);  // Get the current state of the buttons.
		char left = currentButtonState&(0x8);
		char mid = currentButtonState&(0x1);
		char right = currentButtonState&(0x2);
		char up = currentButtonState&(0x10);
		char down = currentButtonState&(0x4);
		if((gameStatus == STOPPED)&& down){
			if(tankBulletSpeed > 1){
				tankBulletSpeed--;
			}
		}
		if(((gameStatus == RUNNING)&& down)&& mothershipSpawned == 0){
			mothershipD = rand()%2;
			mothershipSpawned = 1;
			if (mothershipD == 1){
				mothershipX = 1;
			}else{
				mothershipX = 639;
			}
		}

		if((up && (playerLives <= 0)) || (up && (gameStatus != STOPPED)) || (up && (reachedBottom == 1))){
			initilizeGame();
		}
		if(gameStatus == STOPPED && (left || right || mid) && (0 < playerLives) && (reachedBottom != 1)){
			gameStatus = RUNNING;
			srand(fit_counter);
		}
		//xil_printf("poll the buttons! %d \n\r", currentButtonState);
		if (gameStatus != STOPPED){
			if (left && (right == 0)){
				control(4);
			}
			if (right){
				control(6);
			}
			if (mid && (tankState == TANK_ALIVE)){
				control(5);
			}
		}
	}
}

void drawGreenLine(){
	int row,col;
	for(row = 0; row < 2; row ++){
		for (col = 0; col < X_BOUND_RIGHT - X_BOUND_LEFT; col ++){
			framePointer[(GREEN_LINE_ROW+row)*640+X_BOUND_LEFT+col] = 0x0000FF00;
		}
	}
}

// This is invoked in response to a timer interrupt.
void timer_interrupt_handler() {
	//runTimeO = fit_counter;
	if(fit_counter++ == FIT_COUNT_MAX){
		xil_printf("fit maxed out \n\r");
		fit_counter = 0;
	}
	pollButtons();

	if(gameStatus != STOPPED){
		updateBullets();
		cleanDebris();
		if(tankState == TANK_ALIVE){
			updateAliens();
			spawnBullets();
			spawnMothership();
			updateMothership();
			clearMotherScoreTimer();
			runTimeN = fit_counter;
			//deltaRunTime = runTimeN - runTimeO;
			//xil_printf("Instructions for one game loop: %d\n\r", deltaRunTime);
		}
		if(tankState != TANK_ALIVE){
			tankFlicker();
		}
		if (gameStatus == GAME_OVER){
			if (finalFlicker == 0){
				gameStatus = STOPPED;
				clearAliens();
				clearMothership();
				printLetters("GAME OVER",WHITE,GAME_OVER_X_POS,GAME_OVER_Y_POS);
			}
			if (reachedBottom == 1){
				gameStatus = STOPPED;
				clearAliens();
				clearAllBunkers();
				clearMothership();
				printLetters("GAME OVER",WHITE,GAME_OVER_X_POS,GAME_OVER_Y_POS);
			}
		}
	}
}

// Main interrupt handler, queries the interrupt controller to see what peripheral
// fired the interrupt and then dispatches the corresponding interrupt handler.
// This routine acks the interrupt at the controller level but the peripheral
// interrupt must be ack'd by the dispatched interrupt handler.
void interrupt_handler_dispatcher(void* ptr) {
	int intc_status = XIntc_GetIntrStatus(XPAR_INTC_0_BASEADDR);
	// Check the FIT interrupt first.
	if (intc_status & XPAR_FIT_TIMER_0_INTERRUPT_MASK){
		XIntc_AckIntr(XPAR_INTC_0_BASEADDR, XPAR_FIT_TIMER_0_INTERRUPT_MASK);
		timer_interrupt_handler();
	}
}

void clearConsole(){
	int i;
	for(i = 0; i < 30; i++){
		xil_printf("\n\r");
	}
}

void initilizeGame(){
	int i;
	level = 0;
	gameStatus = STOPPED;
	for(i = 0; i < 4; i++){
		bs[i] = 1;
	}
	for(i = 0; i < 11; i++){
		bottomAlien[i] = 4;
	}
	bNum = 0;
	alienMarchSpeed = 65;
	playerScore = 0;

    int bunk;
    int blk;
    for(bunk = 0; bunk < 4; bunk++){
    	for(blk = 0; blk < 10; blk ++){
    		bErosion[bunk][blk] = 0;
    	}
    }

	lastDebrisRow = 0;
	lastDebrisCol = 0;
    aBlockRightBlank = 0;
    aBlockLeftBlank = 0;

    tankBulletSpeed = 2;

    int bullStat;
    for(bullStat = 0; bullStat < 4; bullStat++){
    	aBulletX[bullStat] = 0;
    	aBulletY[bullStat] = 0;
    	abs_[bullStat] = 0;
    }

    // Write black to all pixels in frame buffer.
    // This is sort of a default
    int row, col;
    for(row=0; row <480; row++){
    	 for(col=0; col<640; col++){
    		 framePointer[row*640+col] = BLACK;
      	 }
    }
    srand(fit_counter);
    // Initialize positions
    tankX = TANK_X_INIT;					// Tank Initial Position.
    tankY = TANK_ROW;
    aBlockX = 144;					// Alien Block Initial Position.
    aBlockY = A_B_Y_INIT;
    aBlockT = 0;
    aBlockD = 1;
    ts = 1;
    reachedBottom = 0;

    // Initialize fit counter
    fit_counter = 0;

    // Initialize player
    playerLives = 3;
    tankDestroyedFlicker = 8;
    tankState = TANK_ALIVE;
    finalFlicker = 1;

    // Initialize alien array.
    int a;
    for (a=0; a<55; a++){
    	alien_life[a] = 1;
    }
    mothershipSpawned = 0;
    mothershipX = 0;
    mothershipY = MOTHERSHIP_Y_POS;

    render(8);
    render(4);
    render(7);
    printLetters("SCORE",WHITE,SCORE_TEXT_X_POS,TOP_MARGINE);
    printLetters("LIVES",WHITE,LIVES_X_POS,TOP_MARGINE);
    scoreToString();
    printLetters("0",GREEN,(SCORE_X_POS),TOP_MARGINE);
    drawLives();
    drawGreenLine();
}

int main(){
	gameStatus = STOPPED;
	init_platform();                   // Necessary for all programs.
	int Status;                        // Keep track of success/failure of system function calls.
	XAxiVdma videoDMAController;
	// There are 3 steps to initializing the vdma driver and IP.
	// Step 1: lookup the memory structure that is used to access the vdma driver.
    XAxiVdma_Config * VideoDMAConfig = XAxiVdma_LookupConfig(XPAR_AXI_VDMA_0_DEVICE_ID);
    // Step 2: Initialize the memory structure and the hardware.
    if(XST_FAILURE == XAxiVdma_CfgInitialize(&videoDMAController, VideoDMAConfig,	XPAR_AXI_VDMA_0_BASEADDR)) {
    	xil_printf("VideoDMA Did not initialize.\r\n");
    }
    // Step 3: (optional) set the frame store number.
    if(XST_FAILURE ==  XAxiVdma_SetFrmStore(&videoDMAController, 2, XAXIVDMA_READ)) {
    	xil_printf("Set Frame Store Failed.");
    }
    // Initialization is complete at this point.

    // Setup the frame counter. We want two read frames. We don't need any write frames but the
    // function generates an error if you set the write frame count to 0. We set it to 2
    // but ignore it because we don't need a write channel at all.
    XAxiVdma_FrameCounter myFrameConfig;
    myFrameConfig.ReadFrameCount = 2;
    myFrameConfig.ReadDelayTimerCount = 10;
    myFrameConfig.WriteFrameCount =2;
    myFrameConfig.WriteDelayTimerCount = 10;
    Status = XAxiVdma_SetFrameCounter(&videoDMAController, &myFrameConfig);
    if (Status != XST_SUCCESS) {
	   xil_printf("Set frame counter failed %d\r\n", Status);
	   if(Status == XST_VDMA_MISMATCH_ERROR)
		   xil_printf("DMA Mismatch Error\r\n");
    }
    // Now we tell the driver about the geometry of our frame buffer and a few other things.
    // Our image is 480 x 640.
    XAxiVdma_DmaSetup myFrameBuffer;
    myFrameBuffer.VertSizeInput = 480;    // 480 vertical pixels.
    myFrameBuffer.HoriSizeInput = 640*4;  // 640 horizontal (32-bit pixels).
    myFrameBuffer.Stride = 640*4;         // Dont' worry about the rest of the values.
    myFrameBuffer.FrameDelay = 0;
    myFrameBuffer.EnableCircularBuf=1;
    myFrameBuffer.EnableSync = 0;
    myFrameBuffer.PointNum = 0;
    myFrameBuffer.EnableFrameCounter = 0;
    myFrameBuffer.FixedFrameStoreAddr = 0;
    if(XST_FAILURE == XAxiVdma_DmaConfig(&videoDMAController, XAXIVDMA_READ, &myFrameBuffer)) {
    	xil_printf("DMA Config Failed\r\n");
     }
    // We need to give the frame buffer pointers to the memory that it will use. This memory
    // is where you will write your video data. The vdma IP/driver then streams it to the HDMI
    // IP.
     myFrameBuffer.FrameStoreStartAddr[0] = FRAME_BUFFER_0_ADDR;
     myFrameBuffer.FrameStoreStartAddr[1] = FRAME_BUFFER_0_ADDR + 4*640*480;

     if(XST_FAILURE == XAxiVdma_DmaSetBufferAddr(&videoDMAController, XAXIVDMA_READ,
    		               myFrameBuffer.FrameStoreStartAddr)) {
    	 xil_printf("DMA Set Address Failed Failed\r\n");
     }
     // Print a sanity message if you get this far.
     //xil_printf("Woohoo! I made it through initialization.\n\r");
     // Now, let's get ready to start displaying some stuff on the screen.
     // The variables framePointer and framePointer1 are just pointers to the base address
     // of frame 0 and frame 1.

     //unsigned int * framePointer1 = ((unsigned int *) FRAME_BUFFER_0_ADDR) + 640*480;
     // Just paint some large red, green, blue, and white squares in different
     // positions of the image for each frame in the buffer (framePointer0 and framePointer1).
     //    			 framePointer[row*640 + col] = 0x0000FF00;  // frame 1 is green here.

     // This tells the HDMI controller the resolution of your display (there must be a better way to do this).
     XIo_Out32(XPAR_AXI_HDMI_0_BASEADDR, 640*480);

     // Start the DMA for the read channel only.
     if(XST_FAILURE == XAxiVdma_DmaStart(&videoDMAController, XAXIVDMA_READ)){
    	 xil_printf("DMA START FAILED\r\n");
     }
     int frameIndex = 0;
     // We have two frames, let's park on frame 0. Use frameIndex to index them.
     // Note that you have to start the DMA process before parking on a frame.
     if (XST_FAILURE == XAxiVdma_StartParking(&videoDMAController, frameIndex,  XAXIVDMA_READ)) {
    	 xil_printf("vdma parking failed\n\r");
     }

     // Initialize the GPIO peripherals.
     int success;
     // print("hello world\n\r");
     success = XGpio_Initialize(&gpPB, XPAR_PUSH_BUTTONS_5BITS_DEVICE_ID);
     // success = XGpio_Initialize(&gpPB, XPAR_PUSH_BUTTONS_5BITS_DEVICE_ID);

     // Set the push button peripheral to be inputs.
     XGpio_SetDataDirection(&gpPB, 1, 0x0000001F);
     // Enable the global GPIO interrupt for push buttons.
     //XGpio_InterruptGlobalEnable(&gpPB);
     // Enable all interrupts in the push button peripheral.
     //XGpio_InterruptEnable(&gpPB, 0xFFFFFFFF);


     microblaze_register_handler(interrupt_handler_dispatcher, NULL);
     XIntc_EnableIntr(XPAR_INTC_0_BASEADDR, XPAR_FIT_TIMER_0_INTERRUPT_MASK);
     XIntc_MasterEnable(XPAR_INTC_0_BASEADDR);
     microblaze_enable_interrupts();

     clearConsole();

     initilizeGame();

     while(1){
//    	 idleTime++;
//    	 if (idleTime >= 1000000){
//    		 runTimeO = runTimeN;
//    		 runTimeN = fit_counter;
//    		 deltaRunTime = runTimeN - runTimeO;
//    		 xil_printf("Active instructions to idle instructions ratio: %d / 1\n\r", (deltaRunTime-1));
//    		 idleTime = 0;
//    	 }
     }
     xil_printf("We do not what to be here\n\r");
     cleanup_platform();

    return 0;
}
