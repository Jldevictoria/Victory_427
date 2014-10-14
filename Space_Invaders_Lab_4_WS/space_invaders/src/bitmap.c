/*
 * bitmap.c
 *
 *  Created on: Oct 13, 2014
 *      Author: Taylor Simons + Joseph DeVictoria
 */

#include "bitmap.h"

int bunkerBlank[12] =
{
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),

};

int bulletType10[14] =
{
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(1,1,0,0,0,0,0,0,0,0,0,0),
	packWord12(1,1,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
};

int bulletType00[14] =
{
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(1,1,0,0,0,0,0,0,0,0,0,0),
	packWord12(1,1,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
};

int bulletType01[14] =
{
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(1,1,1,1,1,1,0,0,0,0,0,0),
	packWord12(1,1,1,1,1,1,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
};

int bulletType11[14] =
{
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(1,1,1,1,1,1,0,0,0,0,0,0),
	packWord12(1,1,1,1,1,1,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
};

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


int bunker0[12] =
{
	packWord12(0,0,0,0,0,0,1,1,1,1,1,1),
	packWord12(0,0,0,0,0,0,1,1,1,1,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),

};

int bunkerD10[12] =
{
	packWord12(0,0,0,0,0,0,1,1,1,1,1,1),
	packWord12(0,0,0,0,0,0,1,1,1,1,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,0,0,1,1,1,1),
	packWord12(0,0,0,0,1,1,0,0,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,0,0,0,0,1,1,1,1),
	packWord12(1,1,1,1,0,0,0,0,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,0,0,1,1),
	packWord12(1,1,1,1,1,1,1,1,0,0,1,1),

};

int bunkerD20[12] =
{
	packWord12(0,0,0,0,0,0,1,1,0,0,1,1),
	packWord12(0,0,0,0,0,0,1,1,0,0,1,1),
	packWord12(0,0,0,0,0,0,1,1,1,1,0,0),
	packWord12(0,0,0,0,0,0,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,0,0,0,0,0,0,1,1,0,0),
	packWord12(1,1,0,0,0,0,0,0,1,1,0,0),
	packWord12(1,1,0,0,0,0,1,1,0,0,1,1),
	packWord12(1,1,0,0,0,0,1,1,0,0,1,1),

};
int bunkerD30[12] =
{
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,1,1,0,0),
	packWord12(0,0,0,0,0,0,0,0,1,1,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,1,1),
	packWord12(0,0,0,0,1,1,0,0,0,0,1,1),
	packWord12(1,1,0,0,0,0,0,0,1,1,0,0),
	packWord12(1,1,0,0,0,0,0,0,1,1,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
};

int bunker3[12] =
{
	packWord12(1,1,1,1,1,1,0,0,0,0,0,0),
	packWord12(1,1,1,1,1,1,0,0,0,0,0,0),
	packWord12(1,1,1,1,1,1,1,1,0,0,0,0),
	packWord12(1,1,1,1,1,1,1,1,0,0,0,0),
	packWord12(1,1,1,1,1,1,1,1,1,1,0,0),
	packWord12(1,1,1,1,1,1,1,1,1,1,0,0),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),

};

int bunkerD13[12] =
{
	packWord12(1,1,0,0,0,0,0,0,0,0,0,0),
	packWord12(1,1,0,0,0,0,0,0,0,0,0,0),
	packWord12(1,1,1,1,1,1,1,1,0,0,0,0),
	packWord12(1,1,1,1,1,1,1,1,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,1,1,0,0),
	packWord12(0,0,0,0,1,1,0,0,1,1,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,0,0,0,0,1,1,1,1),
	packWord12(1,1,1,1,0,0,0,0,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,0,0,1,1),
	packWord12(1,1,1,1,1,1,1,1,0,0,1,1),

};

int bunkerD23[12] =
{
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,1,1,0,0,0,0),
	packWord12(0,0,1,1,0,0,1,1,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,0,0,0,0,0,0,1,1,0,0),
	packWord12(1,1,0,0,0,0,0,0,1,1,0,0),
	packWord12(1,1,0,0,0,0,1,1,0,0,1,1),
	packWord12(1,1,0,0,0,0,1,1,0,0,1,1),

};
int bunkerD33[12] =
{
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,1,1),
	packWord12(0,0,0,0,1,1,0,0,0,0,1,1),
	packWord12(1,1,0,0,0,0,0,0,1,1,0,0),
	packWord12(1,1,0,0,0,0,0,0,1,1,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
};

int bunker5[12] =
{
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,0,0,0,0),
	packWord12(1,1,1,1,1,1,1,1,0,0,0,0),
	packWord12(1,1,1,1,1,1,0,0,0,0,0,0),
	packWord12(1,1,1,1,1,1,0,0,0,0,0,0),
	packWord12(1,1,1,1,0,0,0,0,0,0,0,0),
	packWord12(1,1,1,1,0,0,0,0,0,0,0,0),
	packWord12(1,1,0,0,0,0,0,0,0,0,0,0),
	packWord12(1,1,0,0,0,0,0,0,0,0,0,0),

};

int bunkerD15[12] =
{
	packWord12(1,1,0,0,0,0,1,1,1,1,1,1),
	packWord12(1,1,0,0,0,0,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,0,0),
	packWord12(1,1,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,1,1,1,1,0,0,0,0,0,0),
	packWord12(0,0,1,1,1,1,0,0,0,0,0,0),
	packWord12(1,1,1,1,0,0,0,0,0,0,0,0),
	packWord12(1,1,1,1,0,0,0,0,0,0,0,0),
	packWord12(1,1,0,0,0,0,0,0,0,0,0,0),
	packWord12(1,1,0,0,0,0,0,0,0,0,0,0),

};

int bunkerD25[12] =
{
	packWord12(0,0,0,0,0,0,1,1,0,0,1,1),
	packWord12(0,0,0,0,0,0,1,1,0,0,1,1),
	packWord12(0,0,1,1,0,0,1,1,1,1,0,0),
	packWord12(0,0,1,1,0,0,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,1,1,1,1,0,0,0,0,0,0),
	packWord12(0,0,1,1,1,1,0,0,0,0,0,0),
	packWord12(1,1,0,0,0,0,0,0,0,0,0,0),
	packWord12(1,1,0,0,0,0,0,0,0,0,0,0),
	packWord12(1,1,0,0,0,0,0,0,0,0,0,0),
	packWord12(1,1,0,0,0,0,0,0,0,0,0,0),

};
int bunkerD35[12] =
{
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,1,1,0,0),
	packWord12(0,0,1,1,0,0,0,0,1,1,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(1,1,0,0,0,0,0,0,0,0,0,0),
	packWord12(1,1,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
};

int bunker6[12] =
{
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,0,0,1,1,1,1,1,1),
	packWord12(0,0,0,0,0,0,1,1,1,1,1,1),
	packWord12(0,0,0,0,0,0,0,0,1,1,1,1),
	packWord12(0,0,0,0,0,0,0,0,1,1,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),

};

int bunkerD16[12] =
{
	packWord12(1,1,0,0,0,0,1,1,1,1,1,1),
	packWord12(1,1,0,0,0,0,1,1,1,1,1,1),
	packWord12(1,1,1,1,1,1,1,1,1,1,0,0),
	packWord12(1,1,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,0,0,1,1,1,1),
	packWord12(0,0,0,0,1,1,0,0,1,1,1,1),
	packWord12(0,0,0,0,0,0,1,1,1,1,1,1),
	packWord12(0,0,0,0,0,0,1,1,1,1,1,1),
	packWord12(0,0,0,0,0,0,0,0,1,1,1,1),
	packWord12(0,0,0,0,0,0,0,0,1,1,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),

};

int bunkerD26[12] =
{
	packWord12(0,0,0,0,0,0,1,1,0,0,1,1),
	packWord12(0,0,0,0,0,0,1,1,0,0,1,1),
	packWord12(0,0,1,1,0,0,1,1,1,1,0,0),
	packWord12(0,0,1,1,0,0,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,1,1,1,1,1,1),
	packWord12(0,0,0,0,0,0,1,1,1,1,1,1),
	packWord12(0,0,0,0,0,0,0,0,1,1,0,0),
	packWord12(0,0,0,0,0,0,0,0,1,1,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),

};
int bunkerD36[12] =
{
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,1,1,0,0),
	packWord12(0,0,1,1,0,0,0,0,1,1,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,1,1,0,0),
	packWord12(0,0,0,0,0,0,0,0,1,1,0,0),
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
