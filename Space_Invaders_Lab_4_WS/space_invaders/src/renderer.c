/*
 * renderer.c
 *
 *  Created on: Oct 13, 2014
 *      Author: superman
 */

#include <stdio.h>
#include "globals.h"
#include "bitmap.h"

void clearAlien(int alienNum){
	int aRow,aCol,row,col,tempPix;
	int alienGridX = alienNum%11;
	int alienGridY = alienNum/11;

	aRow = (aBlockY+(alienGridY*INV_VERT));
	aCol = (aBlockX+(alienGridX*32));

	for(row = 0; row < 16; row++){
		for(col = 0; col < 32; col++){
			tempPix = (aRow+row)*640+aCol+col;
			if(framePointer[tempPix] == ALIEN_COLOR){
				framePointer[tempPix] = BLACK;
			}
		}
	}
}

void drawAlienBullets(){
	int bsc,row,col,pixTemp;
	//Clear alien bullet
	for(bsc = 0; bsc < 4; bsc++){
		for (row = 0; row < 14; row ++){
			for (col = 0; col < 8; col ++){
				pixTemp = (aBulletY[bsc]-A_B_MOVE+row)*640+aBulletX[bsc]+col;
				if(framePointer[pixTemp] == BULLET_COLOR){
					framePointer[pixTemp] = BLACK;
				}
/*
				if (bs[bsc] == 0){
					if (aBulletT[bsc]){
						if (((aBulletY[bsc]-A_B_MOVE)/(BUL_TOGGLE_SIZE))%2){
							if (bulletType10[row] & (1 << (31-col))){
								framePointer[(aBulletY[bsc]-A_B_MOVE+row)*640+aBulletX[bsc]+col] = BLACK;
							}

						}else{
							if (bulletType00[row] & (1 << (31-col))){
								framePointer[(aBulletY[bsc]-A_B_MOVE+row)*640+aBulletX[bsc]+col] = BLACK;
							}
						}
					}else{
						if (abs_[bsc]){
							if (bulletType11[row] & (1 << (31-col))){
								framePointer[(aBulletY[bsc]-A_B_MOVE+row)*640+aBulletX[bsc]+col] = BLACK;
							}
						}else{
							if (bulletType01[row] & (1 << (31-col))){
								framePointer[(aBulletY[bsc]-A_B_MOVE+row)*640+aBulletX[bsc]+col] = BLACK;
							}
						}
					}
				}
*/
			}
		}
	}


	//Draw alien bullets
	for(bsc = 0; bsc < 4; bsc++){
		for (row = 0; row < 14; row ++){
			for (col = 0; col < 8; col ++){
				if (bs[bsc] == 0){
					if (aBulletT[bsc]){
						if ((aBulletY[bsc]/BUL_TOGGLE_SIZE)%2){
							if (bulletType10[row] & (1 << (31-col))){
								framePointer[(aBulletY[bsc]+row)*640+aBulletX[bsc]+col] = BULLET_COLOR;
							}

						}else{
							if (bulletType00[row] & (1 << (31-col))){
								framePointer[(aBulletY[bsc]+row)*640+aBulletX[bsc]+col] = BULLET_COLOR;
							}
						}
					}else{
						if ((aBulletY[bsc]/BUL_TOGGLE_SIZE)%2){
							if (bulletType11[row] & (1 << (31-col))){
								framePointer[(aBulletY[bsc]+row)*640+aBulletX[bsc]+col] = BULLET_COLOR;
							}
						}else{
							if (bulletType01[row] & (1 << (31-col))){
								framePointer[(aBulletY[bsc]+row)*640+aBulletX[bsc]+col] = BULLET_COLOR;
							}
						}
					}
				}
			}
		}
	}
/*
	for(bsc = 0; bsc < 4; bsc++){
		for (row = 0; row < 14; row ++){
			for (col = 0; col < 8; col ++){
				if (bs[bsc] == 0){
					if (aBulletT[bsc]){
						if (abs_[bsc]){
							if (bulletType00[row] & (1 << (31-col))){
								framePointer[(aBulletY[bsc]-A_B_MOVE+row)*640+aBulletX[bsc]+col] = BLACK;
							}
							if (bulletType10[row] & (1 << (31-col))){
								framePointer[(aBulletY[bsc]+row)*640+aBulletX[bsc]+col] = BULLET_COLOR;
							}

						}else{
							if (bulletType10[row] & (1 << (31-col))){
								framePointer[(aBulletY[bsc]-A_B_MOVE+row)*640+aBulletX[bsc]+col] = BLACK;
							}
							if (bulletType00[row] & (1 << (31-col))){
								framePointer[(aBulletY[bsc]+row)*640+aBulletX[bsc]+col] = BULLET_COLOR;
							}
						}
					}else{
						if (abs_[bsc]){
							if (bulletType01[row] & (1 << (31-col))){
								framePointer[(aBulletY[bsc]-A_B_MOVE+row)*640+aBulletX[bsc]+col] = BLACK;
							}
							if (bulletType11[row] & (1 << (31-col))){
								framePointer[(aBulletY[bsc]+row)*640+aBulletX[bsc]+col] = BULLET_COLOR;
							}

						}else{
							if (bulletType11[row] & (1 << (31-col))){
								framePointer[(aBulletY[bsc]-A_B_MOVE+row)*640+aBulletX[bsc]+col] = BLACK;
							}
							if (bulletType01[row] & (1 << (31-col))){
								framePointer[(aBulletY[bsc]+row)*640+aBulletX[bsc]+col] = BULLET_COLOR;
							}
						}
					}
				}

			}
		}
	}
*/
}

void drawBunkerBlock(int block, int bunkerNum){
	int col,row;
	switch(block){
		case 0:
			for(row = 0; row < 12; row++){
				for(col = 0; col < 12; col++){
					switch(bErosion[bunkerNum][block]){
					case 0:
						if (bunker0[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
						}
						break;
					case 1:
						if (bunkerD10[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
						}
						break;
					case 2:
						if (bunkerD20[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
						}
						break;
					case 3:
						if (bunkerD30[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
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
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
						}
						break;
					case 1:
						if (bunkerD1[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
						}
						break;
					case 2:
						if (bunkerD2[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
						}
						break;
					case 3:
						if (bunkerD3[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
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
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
						}
						break;
					case 1:
						if (bunkerD1[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
						}
						break;
					case 2:
						if (bunkerD2[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
						}
						break;
					case 3:
						if (bunkerD3[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
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
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
						}
						break;
					case 1:
						if (bunkerD13[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
						}
						break;
					case 2:
						if (bunkerD23[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
						}
						break;
					case 3:
						if (bunkerD33[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
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
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
						}
						break;
					case 1:
						if (bunkerD1[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
						}
						break;
					case 2:
						if (bunkerD2[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
						}
						break;
					case 3:
						if (bunkerD3[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
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
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
						}
						break;
					case 1:
						if (bunkerD15[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
						}
						break;
					case 2:
						if (bunkerD25[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
						}
						break;
					case 3:
						if (bunkerD35[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
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
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
						}
						break;
					case 1:
						if (bunkerD16[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
						}
						break;
					case 2:
						if (bunkerD26[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
						}
						break;
					case 3:
						if (bunkerD36[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
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
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
						}
						break;
					case 1:
						if (bunkerD1[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
						}
						break;
					case 2:
						if (bunkerD2[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
						}
						break;
					case 3:
						if (bunkerD3[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
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
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
						}
						break;
					case 1:
						if (bunkerD1[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
						}
						break;
					case 2:
						if (bunkerD2[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
						}
						break;
					case 3:
						if (bunkerD3[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
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
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
						}
						break;
					case 1:
						if (bunkerD1[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
						}
						break;
					case 2:
						if (bunkerD2[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
						}
						break;
					case 3:
						if (bunkerD3[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
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



void drawScore(){

}

void render(int caller){
	int row, col,invader;
	int bunkerNum;
	int block;
	int bar;
	int curPix;
	// Choose what to update depending on calling function.
	switch (caller){
	case 0:
		break;
	case 2:
		//Draw Invader
		for(invader = 0; invader < 55; invader++){
			for (row = 0; row < 16; row ++){
				for (col = 0; col < 32; col ++){
					curPix = (aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col;
					if(invader < 11){
						if(aBlockT){
							if ((topInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[curPix] = ALIEN_COLOR;
							}else{
								framePointer[curPix] = BLACK;
							}
						}
						else{
							if ((topOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[curPix] = ALIEN_COLOR;
							}else{
								framePointer[curPix] = BLACK;
							}
						}
					}
					else if(invader < 33){
						if(aBlockT){
							if ((midInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[curPix] = ALIEN_COLOR;
							}else{
								framePointer[curPix] = BLACK;
							}
						}
						else{
							if ((midOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[curPix] = ALIEN_COLOR;
							}else{
								framePointer[curPix] = BLACK;
							}
						}
					}
					else{
						if(aBlockT){
							if ((bottomInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[curPix] = ALIEN_COLOR;
							}else{
								framePointer[curPix] = BLACK;
							}
						}
						else{
							if ((bottomOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[curPix] = ALIEN_COLOR;
							}else{
								framePointer[curPix] = BLACK;
							}
						}
					}
				}
			}
		}
		break;
	case 3:
		// Spawn aliens bullets.
		drawAlienBullets();
		break;
	case 4:
		// Move tank left.
		// Cleanup
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				if (tankSymbol[row] & (1 << (31-col))){
					framePointer[(tankY+row)*640+tankX+4+col] = BLACK;
				}
			}
		}
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				if (tankSymbol[row] & (1 << (31-col))){
					framePointer[(tankY+row)*640+tankX+col] = GREEN;
				}
			}
		}

		break;
	case 5:
		for (row = 0; row < 14; row ++){
			for (col = 0; col < 2; col ++){
				framePointer[(tBulletY+row)*640+tBulletX+col] = BULLET_COLOR;
			}
		}
		break;
	case 6:
		// Move tank right.
		// Cleanup
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				if (tankSymbol[row] & (1 << (31-col))){
					framePointer[(tankY+row)*640+tankX-4+col] = BLACK;
				}
			}
		}
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				if (tankSymbol[row] & (1 << (31-col))){
					framePointer[(tankY+row)*640+tankX+col] = GREEN;
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
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
								}
								break;
							case 1:
								if (bunkerD10[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
								}
								break;
							case 2:
								if (bunkerD20[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
								}
								break;
							case 3:
								if (bunkerD30[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
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
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
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
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
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
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
								}
								break;
							case 1:
								if (bunkerD13[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
								}
								break;
							case 2:
								if (bunkerD23[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
								}
								break;
							case 3:
								if (bunkerD33[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
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
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(32*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
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
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
								}
								break;
							case 1:
								if (bunkerD15[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
								}
								break;
							case 2:
								if (bunkerD25[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
								}
								break;
							case 3:
								if (bunkerD35[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = BLACK;
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
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
								}
								break;
							case 1:
								if (bunkerD16[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
								}
								break;
							case 2:
								if (bunkerD26[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
								}
								break;
							case 3:
								if (bunkerD36[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = BLACK;
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
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
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
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = BLACK;
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
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
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
						framePointer[(aBlockY+((bar)*INV_VERT)-16+row)*640+aBlockX+col] = BLACK;
					}
				}
			}
		}else if ((aBlockD == 1) && (aBlockX <= X_BOUND_RIGHT + BLOCK_SHIFT)){
			for(bar = 0; bar < 5; bar++){
				for (row = 0; row < 16; row ++){
					for (col = 0; col < 32*11; col ++){
						framePointer[(aBlockY+((bar)*INV_VERT)-16+row)*640+aBlockX+col] = BLACK;
					}
				}
			}
		}else if (aBlockD == 1){
			for (row = 0; row < ((INV_VERT * 5)-12); row ++){
				for (col = 0; col < 32; col ++){
					framePointer[(aBlockY+row)*640+aBlockX-32+col] = BLACK;
				}
			}
		}else if (aBlockD == 0){
			for (row = 0; row < ((INV_VERT * 5)-12); row ++){
				for (col = 0; col < 32; col ++){
					framePointer[(aBlockY+row)*640+aBlockX+32+col+(32*10)] = BLACK;
				}
			}
		}
		for(invader = 0; invader < 55; invader++){
			for (row = 0; row < 16; row ++){
				for (col = 0; col < 32; col ++){
					curPix = (aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col;
					if(invader < 11){
						if(aBlockT){
							if ((topInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[curPix] = ALIEN_COLOR;
							}else if (framePointer[curPix] ==  ALIEN_COLOR){
								framePointer[curPix] = BLACK;
							}
						}
						else{
							if ((topOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[curPix] = ALIEN_COLOR;
							}else if (framePointer[curPix] ==  ALIEN_COLOR){
								framePointer[curPix] = BLACK;
							}
						}
					}
					else if(invader < 33){
						if(aBlockT){
							if ((midInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[curPix] = ALIEN_COLOR;
							}else if (framePointer[curPix] ==  ALIEN_COLOR){
								framePointer[curPix] = BLACK;
							}
						}
						else{
							if ((midOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[curPix] = ALIEN_COLOR;
							}else if (framePointer[curPix] ==  ALIEN_COLOR){
								framePointer[curPix] = BLACK;
							}
						}
					}
					else{
						if(aBlockT){
							if ((bottomInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[curPix] = ALIEN_COLOR;
							}else if (framePointer[curPix] ==  ALIEN_COLOR){
								framePointer[curPix] = BLACK;
							}
						}
						else{
							if ((bottomOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[curPix] = ALIEN_COLOR;
							}else if (framePointer[curPix ] ==  ALIEN_COLOR){
								framePointer[curPix] = BLACK;
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
					framePointer[(tBulletY+row+7)*640+tBulletX+col] = BLACK;
				}
			}
			// Move tank bullet.
			for (row = 0; row < 14; row ++){
				for (col = 0; col < 2; col ++){
					framePointer[(tBulletY+row)*640+tBulletX+col] = BULLET_COLOR;
				}
			}
		}
		// Cleanup Alien Bullets
		drawAlienBullets();
		break;
	default:
		break;
		}
	return;
}
