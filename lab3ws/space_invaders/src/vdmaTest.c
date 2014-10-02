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
#include "platform.h"
#include "xparameters.h"
#include "xaxivdma.h"
#include "xio.h"
#include "time.h"
#include "unistd.h"
//#include "mb_interface.h"   // provides the microblaze interrupt enables, etc.
//#include "xintc_l.h"        // Provides handy macros for the interrupt controller.
#define DEBUG void print(char *str);
#define ALIEN_HEIGHT 16
#define WORD_WIDTH 32
#define FRAME_BUFFER_0_ADDR 0xC1000000  // Starting location in DDR where we will store the images that we display.
#define NUM_OF_PIXELS 307200
//#define MAX_SILLY_TIMER 10000000;

// Packs each horizontal line of the figures into a single 32 bit word.
#define packWord32(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) \
((b31 << 31) | (b30 << 30) | (b29 << 29) | (b28 << 28) | (b27 << 27) | (b26 << 26) | (b25 << 25) | (b24 << 24) |						  \
 (b23 << 23) | (b22 << 22) | (b21 << 21) | (b20 << 20) | (b19 << 19) | (b18 << 18) | (b17 << 17) | (b16 << 16) |						  \
 (b15 << 15) | (b14 << 14) | (b13 << 13) | (b12 << 12) | (b11 << 11) | (b10 << 10) | (b9  << 9 ) | (b8  << 8 ) |						  \
 (b7  << 7 ) | (b6  << 6 ) | (b5  << 5 ) | (b4  << 4 ) | (b3  << 3 ) | (b2  << 2 ) | (b1  << 1 ) | (b0  << 0 ) )
#define packWord12(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20) \
((b31 << 31) | (b30 << 30) | (b29 << 29) | (b28 << 28) | (b27 << 27) | (b26 << 26) | (b25 << 25) | (b24 << 24) | 					  \
 (b23 << 23) | (b22 << 22) | (b21 << 21) | (b20 << 20) )


int bunker[12] =
{
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	
};
 
int bunkerD1[12] =
{
	packWord12(1,1,0,0,0,0,1,1,1,1,1,1),
	packWord12(1,1,0,0,0,0,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,0,0),
	packWord12(1,1,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,0,0,1,1,1,1),
	packWord12(0,0,0,0,1,1,0,0,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,0,0,0,0,1,1,1,1),
	packWord12(1,1,1,1,0,0,0,0,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,0,0,1,1),
	packWord12(1,1,1,1,1,1,1,1,0,0,1,1),
	
};

int bunkerD2[12] =
{
	packWord12(0,0,0,0,0,0,1,1,0,0,1,1),
	packWord12(0,0,0,0,0,0,1,1,0,0,1,1),
	packWord12(0,0,1,1,0,0,1,1,1,1,0,0),
	packWord12(0,0,1,1,0,0,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,0,0,0,0,0,0,1,1,0,0),
	packWord12(1,1,0,0,0,0,0,0,1,1,0,0),
	packWord12(1,1,0,0,0,0,1,1,0,0,1,1),
	packWord12(1,1,0,0,0,0,1,1,0,0,1,1),
	
};
int bunkerD3[12] =
{
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,1,1,0,0),
	packWord12(0,0,1,1,0,0,0,0,1,1,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,1,1),
	packWord12(0,0,0,0,1,1,0,0,0,0,1,1),
	packWord12(1,1,0,0,0,0,0,0,1,1,0,0),
	packWord12(1,1,0,0,0,0,0,0,1,1,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
};


int capitalS[10] =
{
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
};

int capitalC[10] =
{
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
};

int capitalO[10] =
{
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
};

int capitalR[10] =
{
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
};

int capitalE[10] =
{
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
};

int capitalL[10] =
{
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
};

int capitalI[10] =
{
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
};

int capitalV[10] =
{
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,1,1,0,0,1,1,0,0),
	packWord12(0,0,0,0,1,1,0,0,1,1,0,0),
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
};

 
int box1[ALIEN_HEIGHT] =
{
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),
};
int box2[ALIEN_HEIGHT] =
{
	packWord32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
};
int topOutAlienSymbol[ALIEN_HEIGHT] =
{
	packWord32(0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
};

int topInAlienSymbol[ALIEN_HEIGHT] =
{
	packWord32(0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
};

int midOutAlienSymbol[ALIEN_HEIGHT] =
{
	packWord32(0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0),
};

int midInAlienSymbol[ALIEN_HEIGHT] =
{
	packWord32(0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
};

int bottomOutAlienSymbol[ALIEN_HEIGHT] =
{
	packWord32(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0),
};

int bottomInAlienSymbol[ALIEN_HEIGHT] =
{
	packWord32(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0),
};

int tankSymbol[ALIEN_HEIGHT] =
{
	packWord32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0),
	packWord32(0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0),
	packWord32(0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0),
	packWord32(0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0),
	packWord32(0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0),
	packWord32(0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0),
	packWord32(0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0),
	packWord32(0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0),
	packWord32(0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0),
	packWord32(0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0),
	packWord32(0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0),
};

// Declare Variables for game objects.
// TA's NOTE: We are declaring these variables globally
// to use in both our render and displaying [render()].
int tankX, tankY;
int tBulletX, tBulletY;
int aBlockX, aBlockY;
_Bool aBlockT;
int aBullet0X, aBullet0Y;
int aBullet1X, aBullet1Y;
int aBullet2X, aBullet2Y;
int aBullet3X, aBullet3Y;
_Bool aBullet0T, aBullet1T, aBullet2T, aBullet3T;
int b0Erosion, b1Erosion;
int b2Erosion, b3Erosion;
_Bool alien_life[55];
int fit_counter, runtime;

_Bool whiteFrame1[NUM_OF_PIXELS];
_Bool whiteFrame2[NUM_OF_PIXELS];
_Bool greenFrame1[NUM_OF_PIXELS];
_Bool greenFrame2[NUM_OF_PIXELS];
unsigned int * framePointer = (unsigned int *) FRAME_BUFFER_0_ADDR;



void render(){
	// Get command from user.
	char cmd = getc(stdin);
	if (cmd == '4'){
		xil_printf("%c\r\n", cmd);
		if (tankX > 3)
			tankX -= 4;
		xil_printf("%d\r\n", tankX);
	}
	if (cmd == '6'){
		xil_printf("%c\r\n", cmd);
		if (tankX < 604)
			tankX += 4;
		xil_printf("%d\r\n", tankX);
	}
	if (cmd == '8'){
		xil_printf("%c\r\n", cmd);
	}
	if (cmd == '2'){
		xil_printf("%c\r\n", cmd);
		xil_printf("Please provide the number of the alien you want to kill\n\r");
		int toKill;
		scanf("%d", &toKill);
		if ((toKill >= 0) & (toKill < 55)){
			alien_life[toKill] = 0;
			if (alien_life[toKill] == 0){
				xil_printf("Killed alien #%d\n\r", toKill);
			}else{
				xil_printf("Error\n\r");
			}
		}
	}
	if (cmd == '5'){
		xil_printf("%c\r\n", cmd);
	}
	if (cmd == '3'){
		xil_printf("%c\r\n", cmd);
	}
	if (cmd == '9'){
		xil_printf("%c\r\n", cmd);
	}
	if (cmd == '7'){
		xil_printf("%c\r\n", cmd);
	}
}

void display(){
	//Clear frames
	int row;
	int col;
    for(row=0; row <480; row++){
    	 for(col=0; col<640; col++){
    		greenFrame2[row*640+col] = 0;
		}
	}

	for(row=0; row <480; row++){
    	 for(col=0; col<640; col++){
    		whiteFrame2[row*640+col] = 0;
		}
	}

	//Draw Tank

	tankY = 200;
	tankX = 200;
	for (row = 0; row < 16; row ++){
		for (col = 0; col < 32; col ++){
			if (tankSymbol[row*32+col]){
				greenFrame2[(tankY+row)*640+tankX+col] = 1;
			}
			else{
				greenFrame2[(tankY+row)*640+tankX+col] = 0;
			}
		}
	}
	
	//Draw Invader
	int invader;
	for(invader = 0; invader < 55; invader++){
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				if(invader < 11){
					if(aBlockT){
						if (topInAlienSymbol[row*32+col] && alien_life[invader]){
							whiteFrame2[(aBlockY+(invader*16)+row)*640+aBlockY+(invader*32)+col] = 1;
						}
					}
					else{
						if (topOutAlienSymbol[row*32+col] && alien_life[invader]){
							whiteFrame2[(aBlockY+(invader*16)+row)*640+aBlockY+(invader*32)+col] = 1;
						}						
					}
				}
				else if(invader < 33){
					if(aBlockT){
						if (midInAlienSymbol[row*32+col] && alien_life[invader]){
							whiteFrame2[(aBlockY+(invader*16)+row)*640+aBlockY+(invader*32)+col] = 1;
						}
					}
					else{
						if (midOutAlienSymbol[row*32+col] && alien_life[invader]){
							whiteFrame2[(aBlockY+(invader*16)+row)*640+aBlockY+(invader*32)+col] = 1;
						}						
					}
				}
				else{
					if(aBlockT){
						if (bottomInAlienSymbol[row*32+col] && alien_life[invader]){
							whiteFrame2[(aBlockY+(invader*16)+row)*640+aBlockY+(invader*32)+col] = 1;
						}
					}
					else{
						if (bottomOutAlienSymbol[row*32+col] && alien_life[invader]){
							whiteFrame2[(aBlockY+(invader*16)+row)*640+aBlockY+(invader*32)+col] = 1;
						}						
					}
				}
			}
		}	
	}

	//Draw Letters
	
/*     for(row=0; row <480; row++){
    	 for(col=0; col<640; col++){
    		 if(greenFrame2[row*640+col]){
    			 framePointer[row*640+col] = 0x0000FF00;
    		 }
      	 }
    } */


	return;
}

/*// This is invoked in response to a timer interrupt.
void timer_interrupt_handler() {
	fit_counter++;
	if (fit_counter == 100){				//Update the timer by one second every second
		runtime++;								//Increment the timer
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
}*/

int main()
{
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

     // Write black to all pixels in frame buffer.
     // This is sort of a default
     int row, col;
     for(row=0; row <480; row++){
     	 for(col=0; col<640; col++){
     		 framePointer[row*640+col] = 0x00000000;
       	 }
     }

     // Initialize positions
     tankX = 304;					// Tank Initial Position.
     tankY = 400;
     aBlockX = 0;					// Alien Block Initial Position.
     aBlockY = 75;

     // Initialize alien array.
     int a;
     for (a=0; a<55; a++){
    	 alien_life[a] = 1;
     }

     xil_printf("did I get here?\n\r");
     while(1){
    	 //render();
    	 display();
     }

     cleanup_platform();

    return 0;
}
