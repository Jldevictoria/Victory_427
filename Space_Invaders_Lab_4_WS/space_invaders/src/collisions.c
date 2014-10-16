#include "globals.h"
#include <stdio.h>

void tankCollision(int pixelHit){
	playerLives--;
	tankState = TANK_DEAD_ONE;
	if(playerLives == 0){
		gameStatus = GAME_OVER;
	}
}

void bunkerCollision(int pixelHit){

	//find which bunker was hit
	int whichBunker = 0;
	int whichBlock = 0;
	int bunkGridX = 0;
	int bunkGridY = 0;
	if((pixelHit % 640) > (BUNK_SPACE*1+ BUNK_SHIFT)){
		whichBunker = 1;
	}
	if((pixelHit % 640) > (BUNK_SPACE*2+ BUNK_SHIFT)){
		whichBunker = 2;
	}
	if((pixelHit % 640) > (BUNK_SPACE*3+ BUNK_SHIFT)){
		whichBunker = 3;
	}

	//Find which block
	bunkGridX = ((pixelHit%640)-((BUNK_SPACE*whichBunker)+BUNK_SHIFT))/12;
	bunkGridY = ((pixelHit/640)-BUNKER_ROW)/12;

	whichBlock = bunkGridX+(bunkGridY*4);
	if(whichBlock == 11){
		whichBlock = 9;
	}
	bErosion[whichBunker][whichBlock]++;
	drawBunkerBlock(whichBlock, whichBunker);
}

void alienCollision(int pixelHit){
	int whichAlien;
	int alienGridX = 0;
	int alienGridY = 0;
	alienGridX = ((pixelHit%640)- aBlockX)/32;
	alienGridY = ((pixelHit/640)- aBlockY)/INV_VERT;
	whichAlien = alienGridX + (alienGridY*11);
	alien_life[whichAlien] = 0;

	// Decrement bottomAlien for corresponding column.
	if ((whichAlien/11) == bottomAlien[(whichAlien%11)]){
		bottomAlien[(whichAlien%11)] = (bottomAlien[(whichAlien%11)] - 1);
		updateBlockBlank();
		if (11 < whichAlien){
			if (alien_life[whichAlien-11] != 1){
				bottomAlien[(whichAlien%11)] = (bottomAlien[(whichAlien%11)] - 1);
				updateBlockBlank();
				if (22 < whichAlien){
					if (alien_life[whichAlien-22] != 1){
						bottomAlien[(whichAlien%11)] = (bottomAlien[(whichAlien%11)] - 1);
						updateBlockBlank();
						if (33 < whichAlien){
							if (alien_life[whichAlien-33] != 1){
								bottomAlien[(whichAlien%11)] = (bottomAlien[(whichAlien%11)] - 1);
								updateBlockBlank();
								if (44 < whichAlien){
									if (alien_life[whichAlien-44] != 1){
										bottomAlien[(whichAlien%11)] = (bottomAlien[(whichAlien%11)] - 1);
										updateBlockBlank();
									}
								}
							}
						}
					}
				}
			}
		}
	}
	alienMarchSpeed--;
	clearAlien(whichAlien);
	debrisTimer = alienMarchSpeed;
	int i,allDead;
	allDead = 1;
	for(i = 0; i < 55; i++){
		if(alien_life[i] == 1){
			allDead = 0;
		}
	}
	if(allDead){
		nextLevel();
	}
}
