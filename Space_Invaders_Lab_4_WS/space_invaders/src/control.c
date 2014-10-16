#include "globals.h"
#include <stdio.h>
#include "stdlib.h"


void tankFlicker(){
	if ((tankState == TANK_DEAD_ONE) || (tankState == TANK_DEAD_TWO)){
		if ((fit_counter % FLICKER_SPEED) == 0){
			if (0 < tankDestroyedFlicker){
				renderTankFlicker();
				if (tankState == TANK_DEAD_ONE){
					tankState = TANK_DEAD_TWO;
				}else{
					tankState = TANK_DEAD_ONE;
				}
				tankDestroyedFlicker--;
			}else if (gameStatus == RUNNING){
				renderTankBlank();
				tankState = TANK_ALIVE;
			    tankX = TANK_X_INIT;					// Tank Initial Position.
			    tankY = TANK_ROW;
				render(4);
				tankDestroyedFlicker = NUM_OF_T_FLICKERS;
			}
		}
	}
}

void updateBlockBlank(){
	int i,done;
	done = 0;
	for (i = 0; i < 11; i++){
		if((bottomAlien[i] == -1) && !done){
			aBlockLeftBlank = i+1;
		}else{
			done = 1;
		}
	}
	done = 0;
	for (i = 0; i < 11; i++){
		if((bottomAlien[10 - i] == -1) && !done){
			aBlockRightBlank = i+1;
		}else{
			done = 1;
		}
	}
}


void nextLevel(){
    int i;
    clearDebris();
	aBlockX = 144;					// Alien Block Initial Position.
    aBlockY = A_B_Y_INIT;
    aBlockT = 0;
    aBlockD = 1;
    alienMarchSpeed = 65;
    aBlockLeftBlank = 0;
    aBlockRightBlank = 0;

    debrisTimer =  alienMarchSpeed;
    for(i = 0;i < 55; i++){
    	alien_life[i]=1;
    }

    for (i = 0; i < 11; i++){
    	bottomAlien[i]=4;
    }

    for(i = 0; i < 4; i++){
    	if (bs[i] == 0){
    		bs[i] = 1;
    		bNum--;
    		clearBullet(i);
    		aBulletY[i] += A_B_MOVE;
    	}
    }
    int bullStat;
    for(bullStat = 0; bullStat < 4; bullStat++){
   	 aBulletX[bullStat] = 0;
   	 aBulletY[bullStat] = 0;
   	 abs_[bullStat] = 0;
    }

}

void cleanDebris(){
	if(debrisTimer > 0){
		if((debrisTimer--) == 1){
			clearDebris();
			debrisTimer = 0;
		}
	}
}





void updateBullets(){
	if ((fit_counter % tankBulletSpeed) == 0){
		control(9);
	}
	if ((fit_counter % ALIEN_BULLET_SPEED) == 0){
		control(10);
	}
}
void updateAliens(){
	if ((fit_counter % alienMarchSpeed) == 0){
		control(8);
	}
}

void spawnBullets(){
	rando = rand()%ALIEN_FIRE_RATE;
	if ((fit_counter % rando) == 0){
		control(3);
	}
}

void control(int input){
	// Get command from user.
	char cmd = input;
	if (cmd == 4){
		if (tankState == TANK_ALIVE){
			if (tankX > X_BOUND_LEFT)
				tankX -= 4;
			render(4);
		}
	}
	if (cmd == 6){
		if (tankState == TANK_ALIVE){
			if (tankX < X_BOUND_RIGHT - TANK_WIDTH)
				tankX += 4;
			render(6);
		}
	}
	if (cmd == 8){
		aBlockT = !aBlockT;
		if ((aBlockD == 1) && (aBlockX >= X_BOUND_RIGHT - (A_BLOCK_WIDTH-aBlockRightBlank*32) - BLOCK_SHIFT)){
			aBlockD = 0;
			aBlockY += BLOCK_SHIFT;
		}else if ((aBlockD == 0) && (aBlockX <= X_BOUND_LEFT-aBlockLeftBlank*32 + BLOCK_SHIFT)){
			aBlockD = 1;
			aBlockY += BLOCK_SHIFT;
		}else if (aBlockD == 1){
			aBlockX += BLOCK_SHIFT;
		}else if (aBlockD == 0){
			aBlockX -= BLOCK_SHIFT;
		}
		//drawInvaderBlock();
		render(8);
	}
	if (cmd == 2){
		int toKill = 0;
		if ((toKill >= 0) & (toKill < 55)){
			alien_life[toKill] = 0;
			if (alien_life[toKill] == 0){
			}else{
			}
		}
		render(2);
	}
	if (cmd == 5){
		if(ts){
			ts = 0;
			tBulletX = tankX+15;
			tBulletY = tankY-T_BULLET_HEIGHT;
			render(5);
		}
	}
	if (cmd == 3){
		int noAliens,i;
		noAliens = 1;
		for(i = 0; i < 55; i++){
			if(alien_life[i] == 1){
				noAliens = 0;
			}
		}
		randomRow = rand()%11;
		randomT = rand()%2;
		if(!noAliens){
			while (bottomAlien[randomRow] < 0){
				randomRow = rand()%11;
			}
			if(bNum < 4){
				bDone = 0;
				for(i=0; i<4; i++){
					if(!bDone){
						if (bs[i] == 1){
							bDone = 1;
							bNum++;
							bs[i] = 0;
							aBulletX[i] = aBlockX + ((randomRow)*32) + A_B_X_OFF;
							aBulletY[i] = aBlockY + (INV_VERT*(bottomAlien[randomRow]+1)-10);
							aBulletT[i] = randomT;
						}
					}
				}
			}
			render(3);
		}
	}
	if (cmd == 9){
		int tempPixel;
		if (!ts){
			// Check for collision with bunker
			int k,l;
			char done = 0;
			for(k = 0; k < 2;k++){
				for(l = 0; l < 7; l++){
					tempPixel = framePointer[(tBulletY-l)*640+tBulletX+k];
					if ((tempPixel == GREEN) && !done){
						done = 1;
						clearBullet(4);
						ts = 1;
						bunkerCollision((tBulletY-l)*640+tBulletX+k);
					}
					else if((tempPixel == ALIEN_COLOR) && !done){
						done = 1;
						clearBullet(4);
						ts = 1;
						alienCollision((tBulletY-l)*640+tBulletX+k);
					}
				}
			}
			// Check for collision with alien
			tBulletY -= 7;
			if (tBulletY <= TOP_BULLET_END){
				clearBullet(4);
				ts = 1;
			}
		}
		render(9);
	}
	if (cmd == 7){
		int toErode = 0;
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
	if (cmd == 10){
		int tempPixel;
		int k,l;
		int i;
		char done = 0;
		if(bNum > 0){
			for(i=0; i<4; i++){
				if (bs[i] == 0){
					if (aBulletY[i] >= GREEN_LINE_ROW - (ALIEN_BULLET_HIGHT+2)){
						bs[i] = 1;
						bNum--;
						clearBullet(i);
					}
					for(k = 0; k < 8;k++){
						for(l = 0; l < (ALIEN_BULLET_HIGHT); l++){
							tempPixel = framePointer[(aBulletY[i]+l)*640+aBulletX[i]+k];
							if ((tempPixel == GREEN) && !done){
								done = 1;
								clearBullet(i);
								bNum--;
								bs[i] = 1;
								if((aBulletY[i]+ALIEN_BULLET_HIGHT) < TANK_ROW-8){
									bunkerCollision((aBulletY[i]+l)*640+aBulletX[i]+k);
								}else if ((aBulletY[i]+ALIEN_BULLET_HIGHT) <= GREEN_LINE_ROW){
									tankCollision((aBulletY[i]+l)*640+aBulletX[i]+k);
								}
							}
						}
					}
					aBulletY[i] += A_B_MOVE;
					abs_[i] = !abs_[i];

				}
			}
		}
	}
	return;
}

