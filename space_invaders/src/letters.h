/*
 * letters.h
 *
 * Taylor Simons + Joseph DeVictoria
 * ECEN 425 Lab 3 aliens source.
 */

#ifndef LETTERS_H_
#define LETTERS_H_

int number0[12];
int number1[12];
int number2[12];
int number3[12];
int number4[12];
int number5[12];
int number6[12];
int number7[12];
int number8[12];
int number9[12];
int capitalS[10];
int capitalC[10];
int capitalO[10];
int capitalR[10];
int capitalE[10];
int capitalL[10];
int capitalI[10];
int capitalV[10];
int capitalG[10];
int capitalA[10];
int capitalM[10];
int space[10];

#define packWord12(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20) \
((b31 << 31) | (b30 << 30) | (b29 << 29) | (b28 << 28) | (b27 << 27) | (b26 << 26) | (b25 << 25) | (b24 << 24) | 					  	  \
 (b23 << 23) | (b22 << 22) | (b21 << 21) | (b20 << 20) )

#endif /* LETTERS_H_ */
