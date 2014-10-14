/*
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
 */

/*
 * Taylor Simons + Joseph DeVictoria
 * ECEN 425 Lab 3 aliens source.
 */

#include <stdio.h>
#include "bitmap.h"
#include "stdlib.h"
#include "platform.h"
#include "xparameters.h"
#include "xaxivdma.h"
#include "xgpio.h"
#include "xio.h"
#include "time.h"
#include "unistd.h"
#include "mb_interface.h"   // provides the microblaze interrupt enables, etc.
#include "xintc_l.h"        // Provides handy macros for the interrupt controller.

#define DEBUG void print(char *str);
#define WRD_WIDTH 32
#define FRAME_BUFFER_0_ADDR 0xC1000000  // Starting location in DDR where we will store the images that we display.
#define NUM_OF_PIXELS 307200
//#define MAX_SILLY_TIMER 10000000;

#define SIDE_MARGINE 56
#define TOP_MARGINE 44
#define X_BOUND_RIGHT SIDE_MARGINE
#define X_BOUND_LEFT 640 - SIDE_MARGINE


#define GREEN_LINE_ROW 480 - TOP_MARGINE - 16
#define TANK_ROW GREEN_LINE_ROW - 32
#define TOP_BULLET_END TOP_MARGINE + 28
#define A_BLOCK_WIDTH 11*32
#define TANK_WIDTH  32
#define BUNKER_ROW GREEN_LINE_ROW - 90
#define BUNK_SHIFT X_BOUND_RIGHT + 74
#define BLOCK_SHIFT 4
#define INV_VERT 28
#define A_B_MOVE 14
#define A_B_Y_INIT TOP_MARGINE + 64
#define A_B_X_OFF 9
#define BUNK_SPACE 108


// Declare Variables for game objects.
// TA's NOTE: We are declaring these variables globally
// to use in both our render and displaying [render()].
int tankX, tankY;
int tBulletX, tBulletY;
int aBlockX, aBlockY;
_Bool aBlockT, aBlockD;
int aBullet0X, aBullet0Y;
int aBullet1X, aBullet1Y;
int aBullet2X, aBullet2Y;
int aBullet3X, aBullet3Y;
int bNum = 0;
_Bool bDone;
_Bool bs[4] = {1,1,1,1};
_Bool ts;
_Bool aBullet0T, aBullet1T, aBullet2T, aBullet3T;
_Bool abs0, abs1, abs2, abs3;
int bErosion[4][10];
_Bool alien_life[55];
int fit_counter, runtime;

int random;
int randomT;

unsigned int * framePointer = (unsigned int *) FRAME_BUFFER_0_ADDR;

void render(int caller){
	int row, col,invader;
	int bunkerNum;
	int block;
	int bar;
	int bsc;
	// Choose what to update depending on calling function.
	switch (caller){
	case 0:
		break;
	case 2:
		//Draw Invader
		for(invader = 0; invader < 55; invader++){
			for (row = 0; row < 16; row ++){
				for (col = 0; col < 32; col ++){
					if(invader < 11){
						if(aBlockT){
							if ((topInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
						else{
							if ((topOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
					}
					else if(invader < 33){
						if(aBlockT){
							if ((midInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
						else{
							if ((midOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
					}
					else{
						if(aBlockT){
							if ((bottomInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
						else{
							if ((bottomOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
					}
				}
			}
		}
		break;
	case 3:
		// Spawn aliens bullets.
		for(bsc = 0; bsc < 4; bsc++){
			for (row = 0; row < 14; row ++){
				for (col = 0; col < 8; col ++){
					switch (bsc){
					case 0:
						if (bs[bsc] == 0){
							if (aBullet0T == 0){
								if (abs0){
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet0Y-A_B_MOVE+row)*640+aBullet0X+col] = 0x00000000;
									}
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet0Y+row)*640+aBullet0X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet0Y-A_B_MOVE+row)*640+aBullet0X+col] = 0x00000000;
									}
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet0Y+row)*640+aBullet0X+col] = 0x00FFFFFF;
									}
								}
							}else{
								if (abs0){
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet0Y-A_B_MOVE+row)*640+aBullet0X+col] = 0x00000000;
									}
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet0Y+row)*640+aBullet0X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet0Y-A_B_MOVE+row)*640+aBullet0X+col] = 0x00000000;
									}
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet0Y+row)*640+aBullet0X+col] = 0x00FFFFFF;
									}
								}
							}
						}
						break;
					case 1:
						if (bs[bsc] == 0){
							if (aBullet1T == 0){
								if (abs1){
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet1Y-A_B_MOVE+row)*640+aBullet1X+col] = 0x00000000;
									}
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet1Y+row)*640+aBullet1X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet1Y-A_B_MOVE+row)*640+aBullet1X+col] = 0x00000000;
									}
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet1Y+row)*640+aBullet1X+col] = 0x00FFFFFF;
									}
								}
							}else{
								if (abs1){
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet1Y-A_B_MOVE+row)*640+aBullet1X+col] = 0x00000000;
									}
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet1Y+row)*640+aBullet1X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet1Y-A_B_MOVE+row)*640+aBullet1X+col] = 0x00000000;
									}
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet1Y+row)*640+aBullet1X+col] = 0x00FFFFFF;
									}
								}
							}
						}
						break;
					case 2:
						if (bs[bsc] == 0){
							if (aBullet2T == 0){
								if (abs2){
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet2Y-A_B_MOVE+row)*640+aBullet2X+col] = 0x00000000;
									}
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet2Y+row)*640+aBullet2X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet2Y-A_B_MOVE+row)*640+aBullet2X+col] = 0x00000000;
									}
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet2Y+row)*640+aBullet2X+col] = 0x00FFFFFF;
									}
								}
							}else{
								if (abs2){
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet2Y-A_B_MOVE+row)*640+aBullet2X+col] = 0x00000000;
									}
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet2Y+row)*640+aBullet2X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet2Y-A_B_MOVE+row)*640+aBullet2X+col] = 0x00000000;
									}
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet2Y+row)*640+aBullet2X+col] = 0x00FFFFFF;
									}
								}
							}
						}

						break;
					case 3:
						if (bs[bsc] == 0){
							if (aBullet3T == 0){
								if (abs3){
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet3Y-A_B_MOVE+row)*640+aBullet3X+col] = 0x00000000;
									}
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet3Y+row)*640+aBullet3X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet3Y-A_B_MOVE+row)*640+aBullet3X+col] = 0x00000000;
									}
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet3Y+row)*640+aBullet3X+col] = 0x00FFFFFF;
									}
								}
							}else{
								if (abs3){
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet3Y-A_B_MOVE+row)*640+aBullet3X+col] = 0x00000000;
									}
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet3Y+row)*640+aBullet3X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet3Y-A_B_MOVE+row)*640+aBullet3X+col] = 0x00000000;
									}
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet3Y+row)*640+aBullet3X+col] = 0x00FFFFFF;
									}
								}
							}
						}
						break;
					default:
						break;
					}
				}
			}
		}
		break;
	case 4:
		// Move tank left.
		// Cleanup
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				if (tankSymbol[row] & (1 << (31-col))){
					framePointer[(tankY+row)*640+tankX+4+col] = 0x00000000;
				}
			}
		}
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				if (tankSymbol[row] & (1 << (31-col))){
					framePointer[(tankY+row)*640+tankX+col] = 0x0000FF00;
				}
			}
		}

		break;
	case 5:
		for (row = 0; row < 14; row ++){
			for (col = 0; col < 2; col ++){
				framePointer[(tBulletY+row)*640+tBulletX+col] = 0x00FFFFFF;
			}
		}
		break;
	case 6:
		// Move tank right.
		// Cleanup
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				if (tankSymbol[row] & (1 << (31-col))){
					framePointer[(tankY+row)*640+tankX-4+col] = 0x00000000;
				}
			}
		}
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				if (tankSymbol[row] & (1 << (31-col))){
					framePointer[(tankY+row)*640+tankX+col] = 0x0000FF00;
				}
			}
		}
		break;
	case 7:
		for(bunkerNum = 0; bunkerNum < 4; bunkerNum++){
			for(block = 0; block < 10; block ++){
				switch(block){
				case 0:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker0[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD10[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD20[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD30[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 1:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 2:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 3:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD13[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD23[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD33[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 4:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(32*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 5:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker5[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD15[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD25[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD35[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 6:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker6[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD16[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD26[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD36[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 7:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 8:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 9:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				default:
					break;
				}
			}
		}
		break;
	case 8:
		//Draw Invader
		if ((aBlockD == 0) && (aBlockX >= X_BOUND_LEFT - A_BLOCK_WIDTH - BLOCK_SHIFT)){
			for(bar = 0; bar < 5; bar++){
				for (row = 0; row < 16; row ++){
					for (col = 0; col < 32*11; col ++){
						framePointer[(aBlockY+((bar)*INV_VERT)-16+row)*640+aBlockX+col] = 0x00000000;
					}
				}
			}
		}else if ((aBlockD == 1) && (aBlockX <= X_BOUND_RIGHT + BLOCK_SHIFT)){
			for(bar = 0; bar < 5; bar++){
				for (row = 0; row < 16; row ++){
					for (col = 0; col < 32*11; col ++){
						framePointer[(aBlockY+((bar)*INV_VERT)-16+row)*640+aBlockX+col] = 0x00000000;
					}
				}
			}
		}else if (aBlockD == 1){
			for (row = 0; row < INV_VERT * 5; row ++){
				for (col = 0; col < 32; col ++){
					framePointer[(aBlockY+row)*640+aBlockX-32+col] = 0x00000000;
				}
			}
		}else if (aBlockD == 0){
			for (row = 0; row < INV_VERT * 5; row ++){
				for (col = 0; col < 32; col ++){
					framePointer[(aBlockY+row)*640+aBlockX+32+col+(32*10)] = 0x00000000;
				}
			}
		}
		for(invader = 0; invader < 55; invader++){
			for (row = 0; row < 16; row ++){
				for (col = 0; col < 32; col ++){
					if(invader < 11){
						if(aBlockT){
							if ((topInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
						else{
							if ((topOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
					}
					else if(invader < 33){
						if(aBlockT){
							if ((midInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
						else{
							if ((midOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
					}
					else{
						if(aBlockT){
							if ((bottomInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
						else{
							if ((bottomOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
					}
				}
			}
		}
		break;
	case 9:
		// Move bullets
		// Cleanup tank bullet.
		if(!ts){
			for (row = 0; row < 14; row ++){
				for (col = 0; col < 2; col ++){
					framePointer[(tBulletY+row+14)*640+tBulletX+col] = 0x00000000;
				}
			}
			// Move tank bullet.
			for (row = 0; row < 14; row ++){
				for (col = 0; col < 2; col ++){
					framePointer[(tBulletY+row)*640+tBulletX+col] = 0x00FFFFFF;
				}
			}
		}
		// Cleanup Alien Bullets
		for(bsc = 0; bsc < 4; bsc++){
			for (row = 0; row < 14; row ++){
				for (col = 0; col < 8; col ++){
					switch (bsc){
					case 0:
						if (bs[bsc] == 0){
							if (aBullet0T == 0){
								if (abs0){
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet0Y-A_B_MOVE+row)*640+aBullet0X+col] = 0x00000000;
									}
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet0Y+row)*640+aBullet0X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet0Y-A_B_MOVE+row)*640+aBullet0X+col] = 0x00000000;
									}
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet0Y+row)*640+aBullet0X+col] = 0x00FFFFFF;
									}
								}
							}else{
								if (abs0){
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet0Y-A_B_MOVE+row)*640+aBullet0X+col] = 0x00000000;
									}
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet0Y+row)*640+aBullet0X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet0Y-A_B_MOVE+row)*640+aBullet0X+col] = 0x00000000;
									}
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet0Y+row)*640+aBullet0X+col] = 0x00FFFFFF;
									}
								}
							}
						}
						break;
					case 1:
						if (bs[bsc] == 0){
							if (aBullet1T == 0){
								if (abs1){
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet1Y-A_B_MOVE+row)*640+aBullet1X+col] = 0x00000000;
									}
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet1Y+row)*640+aBullet1X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet1Y-A_B_MOVE+row)*640+aBullet1X+col] = 0x00000000;
									}
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet1Y+row)*640+aBullet1X+col] = 0x00FFFFFF;
									}
								}
							}else{
								if (abs1){
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet1Y-A_B_MOVE+row)*640+aBullet1X+col] = 0x00000000;
									}
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet1Y+row)*640+aBullet1X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet1Y-A_B_MOVE+row)*640+aBullet1X+col] = 0x00000000;
									}
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet1Y+row)*640+aBullet1X+col] = 0x00FFFFFF;
									}
								}
							}
						}
						break;
					case 2:
						if (bs[bsc] == 0){
							if (aBullet2T == 0){
								if (abs2){
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet2Y-A_B_MOVE+row)*640+aBullet2X+col] = 0x00000000;
									}
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet2Y+row)*640+aBullet2X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet2Y-A_B_MOVE+row)*640+aBullet2X+col] = 0x00000000;
									}
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet2Y+row)*640+aBullet2X+col] = 0x00FFFFFF;
									}
								}
							}else{
								if (abs2){
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet2Y-A_B_MOVE+row)*640+aBullet2X+col] = 0x00000000;
									}
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet2Y+row)*640+aBullet2X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet2Y-A_B_MOVE+row)*640+aBullet2X+col] = 0x00000000;
									}
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet2Y+row)*640+aBullet2X+col] = 0x00FFFFFF;
									}
								}
							}
						}

						break;
					case 3:
						if (bs[bsc] == 0){
							if (aBullet3T == 0){
								if (abs3){
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet3Y-A_B_MOVE+row)*640+aBullet3X+col] = 0x00000000;
									}
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet3Y+row)*640+aBullet3X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet3Y-A_B_MOVE+row)*640+aBullet3X+col] = 0x00000000;
									}
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet3Y+row)*640+aBullet3X+col] = 0x00FFFFFF;
									}
								}
							}else{
								if (abs3){
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet3Y-A_B_MOVE+row)*640+aBullet3X+col] = 0x00000000;
									}
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet3Y+row)*640+aBullet3X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet3Y-A_B_MOVE+row)*640+aBullet3X+col] = 0x00000000;
									}
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet3Y+row)*640+aBullet3X+col] = 0x00FFFFFF;
									}
								}
							}
						}
						break;
					default:
						break;
					}
				}
			}
		}
		break;
	default:
		break;
		}
	return;
}

void clearBullet(int sel){
	int tempY = 0;
	int tempX = 0;
	switch(sel){
	case 0:
		tempY = aBullet0Y;
		tempX = aBullet0X;
		break;
	case 1:
		tempY = aBullet1Y;
		tempX = aBullet1X;
		break;
	case 2:
		tempY = aBullet2Y;
		tempX = aBullet2X;
		break;
	case 3:
		tempY = aBullet3Y;
		tempX = aBullet3X;
		break;
	case 4:
		tempY = tBulletY + 14;
		tempX = tBulletX;
		break;
	}
	int row,col;
	for (row = 0; row < 14; row ++){
		for (col = 0; col < 8; col ++){
			framePointer[(tempY+row)*640+tempX+col] = 0x00000000;
		}
	}

}

void control(){
	// Get command from user.
	char cmd = getc(stdin);
	if (cmd == '4'){
		xil_printf("%c\r\n", cmd);
		if (tankX > X_BOUND_RIGHT)
			tankX -= 4;
		render(4);
		xil_printf("%d\r\n", tankX);
	}
	if (cmd == '6'){
		xil_printf("%c\r\n", cmd);
		if (tankX < X_BOUND_LEFT - TANK_WIDTH)
			tankX += 4;
		render(6);
		xil_printf("%d\r\n", tankX);
	}
	if (cmd == '8'){
		xil_printf("%c\r\n", cmd);
		aBlockT = !aBlockT;
		if ((aBlockD == 1) && (aBlockX >= X_BOUND_LEFT - A_BLOCK_WIDTH - BLOCK_SHIFT)){
			aBlockD = 0;
			aBlockY += BLOCK_SHIFT;
		}else if ((aBlockD == 0) && (aBlockX <= X_BOUND_RIGHT + BLOCK_SHIFT)){
			aBlockD = 1;
			aBlockY += BLOCK_SHIFT;
		}else if (aBlockD == 1){
			aBlockX += BLOCK_SHIFT;
		}else if (aBlockD == 0){
			aBlockX -= BLOCK_SHIFT;
		}
		render(8);
	}
	if (cmd == '2'){
		xil_printf("%c\r\n", cmd);
		xil_printf("Please provide the number of the alien you want to kill\n\r");
		int toKill;
		scanf("%d", &toKill);
		xil_printf("%d\r\n", toKill);
		if ((toKill >= 0) & (toKill < 55)){
			alien_life[toKill] = 0;
			if (alien_life[toKill] == 0){
				xil_printf("Killed alien #%d\n\r", toKill);
			}else{
				xil_printf("Error\n\r");
			}
		}
		render(2);
	}
	if (cmd == '5'){
		xil_printf("%c\r\n", cmd);
		if(ts){
			ts = 0;
			tBulletX = tankX+16;
			tBulletY = tankY-12;
			render(5);
		}
	}
	if (cmd == '3'){
		xil_printf("%c\r\n", cmd);
		random = rand()%11;
		randomT = rand()%2;
		while (alien_life[random+44] != 1){
			random = rand()%11;
		}
		int i;
		if(bNum < 4){
			bDone = 0;
			for(i=0; i<4; i++){
				if(!bDone){
					if (bs[i] == 1){
						bDone = 1;
						bNum++;
						bs[i] = 0;
						switch(i){
						case 0:
							aBullet0X = aBlockX + (random*32) + A_B_X_OFF;
							aBullet0Y = aBlockY + INV_VERT*5;
							aBullet0T = randomT;
							break;
						case 1:
							aBullet1X = aBlockX + (random*32) + A_B_X_OFF;
							aBullet1Y = aBlockY + INV_VERT*5;
							aBullet1T = randomT;
							break;
						case 2:
							aBullet2X = aBlockX + (random*32) + A_B_X_OFF;
							aBullet2Y = aBlockY + INV_VERT*5;
							aBullet2T = randomT;
							break;
						case 3:
							aBullet3X = aBlockX + (random*32) + A_B_X_OFF;
							aBullet3Y = aBlockY + INV_VERT*5;
							aBullet3T = randomT;
							break;
						default:
							break;
						}
					}
				}
			}
		}
		render(3);
	}
	if (cmd == '9'){
		xil_printf("%c\r\n", cmd);
		int i;
		if(bNum > 0){
			for(i=0; i<4; i++){
				if (bs[i] == 0){
					switch(i){
					case 0:
						if (aBullet0Y >= GREEN_LINE_ROW - (A_B_MOVE * 2)){
							bs[i] = 1;
							bNum--;
							clearBullet(0);
						}
						aBullet0Y += A_B_MOVE;
						abs0 = !abs0;
						break;
					case 1:
						if (aBullet1Y >= GREEN_LINE_ROW - (A_B_MOVE * 2)){
							bs[i] = 1;
							bNum--;
							clearBullet(1);
						}
						aBullet1Y += A_B_MOVE;
						abs1 = !abs1;
						break;
					case 2:
						if (aBullet2Y >= GREEN_LINE_ROW - (A_B_MOVE * 2)){
							bs[i] = 1;
							bNum--;
							clearBullet(2);
						}
						aBullet2Y += A_B_MOVE;
						abs2 = !abs2;
						break;
					case 3:
						if (aBullet3Y >= GREEN_LINE_ROW - (A_B_MOVE * 2)){
							bs[i] = 1;
							bNum--;
							clearBullet(3);
						}
						aBullet3Y += A_B_MOVE;
						abs3 = !abs3;
						break;
					default:
						break;
					}
				}
			}
		}
		if (!ts){
			tBulletY -= 14;
			if (tBulletY <= TOP_BULLET_END){
				clearBullet(4);
				ts = 1;
			}
		}
		render(9);
	}
	if (cmd == '7'){
		xil_printf("%c\r\n", cmd);
		xil_printf("%c\r\n", cmd);
		xil_printf("Please provide the number of the bunker you want to erode\n\r");
		int toErode;
		scanf("%d", &toErode);
		xil_printf("%d\r\n", toErode);
		toErode = 3 - toErode;
		if ((toErode >= 0) & (toErode < 4)){
			int random = rand()%10;
			while (bErosion[toErode][random] > 3){
				random = rand()%10;
			}
			bErosion[toErode][random]++;
		}
		render(7);
	}
	return;
}

void drawGreenLine(){

	int row,col;
	for(row = 0; row < 2; row ++){
		for (col = 0; col < X_BOUND_LEFT - X_BOUND_RIGHT; col ++){
			framePointer[(GREEN_LINE_ROW+row)*640+X_BOUND_RIGHT+col] = 0x0000FF00;
		}
	}
}

// This is invoked in response to a timer interrupt.
void timer_interrupt_handler() {
	fit_counter++;
	if (fit_counter == 100){				//Update the timer by one second every second
		runtime++;							//Increment the timer
		fit_counter = 0;					//reset the fit count
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
	// Check the push buttons.
	//if (intc_status & XPAR_PUSH_BUTTONS_5BITS_IP2INTC_IRPT_MASK){
	//	XIntc_AckIntr(XPAR_INTC_0_BASEADDR, XPAR_PUSH_BUTTONS_5BITS_IP2INTC_IRPT_MASK);
	//	pb_interrupt_handler();
	//}
}

int main(){
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

/*
     // Initialize the GPIO peripherals.
     int success;
     // print("hello world\n\r");
     success = XGpio_Initialize(&gpPB, XPAR_PUSH_BUTTONS_5BITS_DEVICE_ID);
     // success = XGpio_Initialize(&gpPB, XPAR_PUSH_BUTTONS_5BITS_DEVICE_ID);

     // Set the push button peripheral to be inputs.
     XGpio_SetDataDirection(&gpPB, 1, 0x0000001F);
     // Enable the global GPIO interrupt for push buttons.
     XGpio_InterruptGlobalEnable(&gpPB);
     // Enable all interrupts in the push button peripheral.
     XGpio_InterruptEnable(&gpPB, 0xFFFFFFFF);
*/

/*     microblaze_register_handler(interrupt_handler_dispatcher, NULL);
     XIntc_EnableIntr(XPAR_INTC_0_BASEADDR, XPAR_FIT_TIMER_0_INTERRUPT_MASK);
     XIntc_MasterEnable(XPAR_INTC_0_BASEADDR);
     microblaze_enable_interrupts();
*/
     //initilize bunker status
     int bunk;
     int blk;
     for(bunk = 0; bunk < 4; bunk++){
    	 for(blk = 0; blk < 10; blk ++){
    		 bErosion[bunk][blk] = 0;
    	 }
     }

     // Write black to all pixels in frame buffer.
     // This is sort of a default
     int row, col;
     for(row=0; row <480; row++){
     	 for(col=0; col<640; col++){
     		 framePointer[row*640+col] = 0x00000000;
       	 }
     }
     srand(time(0));
     // Initialize positions
     tankX = 304;					// Tank Initial Position.
     tankY = TANK_ROW;
     aBlockX = 144;					// Alien Block Initial Position.
     aBlockY = A_B_Y_INIT;
     aBlockT = 0;
     aBlockD = 1;
     ts = 1;

     // Initialize alien array.
     int a;
     for (a=0; a<55; a++){
    	 alien_life[a] = 1;
     }

     render(8);
     render(4);
     render(7);

     drawGreenLine();

     while(1){
    	 control();
     }

     cleanup_platform();

    return 0;
}
