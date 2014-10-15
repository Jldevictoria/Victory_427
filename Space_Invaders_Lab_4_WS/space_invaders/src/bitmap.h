/*
 * bitmap.h
 *
 *  Created on: Oct 13, 2014
 *      Author: superman
 */

#ifndef BITMAP_H_
#define BITMAP_H_

#define ALIEN_HEIGHT 16

// Packs each horizontal line of the figures into a single 32 bit word.
#define packWord32(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) \
((b31 << 31) | (b30 << 30) | (b29 << 29) | (b28 << 28) | (b27 << 27) | (b26 << 26) | (b25 << 25) | (b24 << 24) |						  \
 (b23 << 23) | (b22 << 22) | (b21 << 21) | (b20 << 20) | (b19 << 19) | (b18 << 18) | (b17 << 17) | (b16 << 16) |						  \
 (b15 << 15) | (b14 << 14) | (b13 << 13) | (b12 << 12) | (b11 << 11) | (b10 << 10) | (b9  << 9 ) | (b8  << 8 ) |						  \
 (b7  << 7 ) | (b6  << 6 ) | (b5  << 5 ) | (b4  << 4 ) | (b3  << 3 ) | (b2  << 2 ) | (b1  << 1 ) | (b0  << 0 ) )
#define packWord12(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20) \
((b31 << 31) | (b30 << 30) | (b29 << 29) | (b28 << 28) | (b27 << 27) | (b26 << 26) | (b25 << 25) | (b24 << 24) | 					  	  \
 (b23 << 23) | (b22 << 22) | (b21 << 21) | (b20 << 20) )

int bunkerBlank[12];
int bulletType10[14];
int bulletType00[14];
int bulletType01[14];
int bulletType11[14];
int bunker[12];
int bunkerD1[12];
int bunkerD2[12];
int bunkerD3[12];
int bunker0[12];
int bunkerD10[12];
int bunkerD20[12];
int bunkerD30[12];
int bunker3[12];
int bunkerD13[12];
int bunkerD23[12];
int bunkerD33[12];
int bunker5[12];
int bunkerD15[12];
int bunkerD25[12];
int bunkerD35[12];
int bunker6[12];
int bunkerD16[12];
int bunkerD26[12];
int bunkerD36[12];
int capitalS[10];
int capitalC[10];
int capitalO[10];
int capitalR[10];
int capitalE[10];
int capitalL[10];
int capitalI[10];
int capitalV[10];
int box1[ALIEN_HEIGHT];
int box2[ALIEN_HEIGHT];
int topOutAlienSymbol[ALIEN_HEIGHT];
int topInAlienSymbol[ALIEN_HEIGHT];
int midOutAlienSymbol[ALIEN_HEIGHT];
int midInAlienSymbol[ALIEN_HEIGHT];
int bottomOutAlienSymbol[ALIEN_HEIGHT];
int bottomInAlienSymbol[ALIEN_HEIGHT];
int tankSymbol[ALIEN_HEIGHT];
int mothershipSymbol[ALIEN_HEIGHT];
int alienExplosionSymbol[20];
int tankDestoyedInSymbol[18];
int tankDestoyedOutSymbol[ALIEN_HEIGHT];



#endif /* BITMAP_H_ */
