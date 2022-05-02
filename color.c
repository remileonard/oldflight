#include "colors.h"

void init_shade(int i, int shade)
{
	building_shade[i][0] = shade++;
	building_shade[i][1] = shade++;
	building_shade[i][2] = shade++;
	building_shade[i][3] = shade++;
	building_shade[i][4] = shade++;
}
void init_palette() {

	int i;
	int r, g, b;
	mapcolor(black, 0, 0, 0);		/* 0	*/
	mapcolor(brown, 96, 80, 64);		/* 1	*/
	mapcolor(orange, 255, 192, 0);	/* 2	*/
	mapcolor(blue, 80, 160, 240);		/* 4	*/
	mapcolor(blue + orange, 255, 192, 0);
	mapcolor(blue + brown, 0, 0, 255);
	mapcolor(cyan, 0, 0, 255);
	mapcolor(red, 255, 0, 0);		/* 8	*/
	mapcolor(red + brown, 255, 0, 0);
	mapcolor(red + orange, 255, 192, 0);
	mapcolor(white, 220, 220, 220);
	mapcolor(white + brown, 220, 220, 220);
	mapcolor(white + orange, 220, 220, 220);
	mapcolor(green0, 0, 255, 0);
	mapcolor(grey2, 192, 192, 192);
	mapcolor(grey5, 140, 140, 140);
	mapcolor(grey8, 96, 96, 96);
	mapcolor(green, 80, 144, 80);
	mapcolor(skyblue, 80, 160, 240);
	mapcolor(dirt, 0x70, 0x60, 0x30);
	mapcolor(grey0, 224, 224, 224);
	mapcolor(grey1, 208, 208, 208);
	mapcolor(grey3, 176, 176, 176);
	mapcolor(grey4, 160, 160, 160);
	mapcolor(grey6, 128, 128, 128);
	mapcolor(grey7, 112, 112, 112);
	mapcolor(grey9, 80, 80, 80);
	mapcolor(grey10, 64, 64, 64);
	mapcolor(grey11, 48, 48, 48);
	mapcolor(grey12, 32, 32, 32);
	mapcolor(green1, 69, 140, 60);
	for (i = purple0, r = 208, g = 0, b = 208; i < purple0 + 5; i++, r -= 32, b -= 32)
		mapcolor(i, r, g, b);
	for (i = lime0, r = 176, g = 208, b = 160; i < lime0 + 5; i++, r -= 32, g -= 32, b -= 32)
		mapcolor(i, r, g, b);
	for (i = orange0, r = 200, g = 70, b = 0; i < orange0 + 5; i++, r -= 32, g -= 13)
		mapcolor(i, r, g, b);
	for (i = tan0, r = 176, g = 144, b = 112; i < tan0 + 5; i++, r -= 20, g -= 20, b -= 20)
		mapcolor(i, r, g, b);
	for (i = silver0, r = 160, g = 176, b = 188; i <= silver9; i++, r -= 10, g -= 10, b -= 10)
		mapcolor(i, r, g, b);

	init_shade(blime, lime0);
	init_shade(borange, orange0);
	init_shade(btan, tan0);

	building_shade[bgrey][0] = grey0;
	building_shade[bgrey][1] = grey3;
	building_shade[bgrey][2] = grey4;
	building_shade[bgrey][3] = grey7;
	building_shade[bgrey][4] = grey8;

}

void map_daynight(int daytime)
{
	GLshort i;
	GLuint r, g, b;
	init_palette();
	if (daytime) {
		for (i = purple0, r = 208, g = 0, b = 208; i < purple0 + 5; i++, r -= 32, b -= 32) {
			mapcolor(i, r, g, b);
		}
		for (i = lime0, r = 176, g = 208, b = 160; i < lime0 + 5; i++, r -= 32, g -= 32, b -= 32) {
			mapcolor(i, r, g, b);
		}	
		for (i = orange0, r = 200, g = 70, b = 0; i < orange0 + 5; i++, r -= 32, g -= 13) {
			mapcolor(i, r, g, b);
		}	
		for (i = tan0, r = 176, g = 144, b = 112; i < tan0 + 5; i++, r -= 20, g -= 20, b -= 20) {
			mapcolor(i, r, g, b);
		}
		for (i = silver0, r = 160, g = 176, b = 188; i <= silver9; i++, r -= 10, g -= 10, b -= 10) {
			mapcolor(i, r, g, b);
		}
	}
	else {
		mapcolor(green, 80 >> 2, 144 >> 2, 80 >> 2);
		mapcolor(skyblue, 80 >> 2, 160 >> 2, 240 >> 2);
		mapcolor(dirt, 0x70 >> 2, 0x60 >> 2, 0x30 >> 2);
		mapcolor(grey0, 224 >> 2, 224 >> 2, 224 >> 2);
		mapcolor(grey1, 208 >> 2, 208 >> 2, 208 >> 2);
		mapcolor(grey2, 192 >> 2, 192 >> 2, 192 >> 2);
		mapcolor(grey3, 176 >> 2, 176 >> 2, 176 >> 2);
		mapcolor(grey4, 160 >> 2, 160 >> 2, 160 >> 2);
		mapcolor(grey5, 140 >> 2, 140 >> 2, 140 >> 2);
		mapcolor(grey6, 128 >> 2, 128 >> 2, 128 >> 2);
		mapcolor(grey7, 112 >> 2, 112 >> 2, 112 >> 2);
		mapcolor(grey8, 96 >> 2, 96 >> 2, 96 >> 2);
		mapcolor(grey9, 80 >> 2, 80 >> 2, 80 >> 2);
		mapcolor(grey10, 64 >> 2, 64 >> 2, 64 >> 2);
		mapcolor(grey11, 48 >> 2, 48 >> 2, 48 >> 2);
		mapcolor(grey12, 32 >> 2, 32 >> 2, 32 >> 2);
		mapcolor(green1, 69 >> 2, 140 >> 2, 60>>2);
		for (i = purple0, r = 208 >> 2, g = 0, b = 208 >> 2; i < purple0 + 5; i++, r -= 8, b -= 8) {
			mapcolor(i, r, g, b);
		}
		for (i = lime0, r = 176 >> 2, g = 208 >> 2, b = 160 >> 2; i < lime0 + 5; i++, r -= 8, g -= 8, b -= 8) {
			mapcolor(i, r, g, b);
		}	
		for (i = orange0, r = 200 >> 2, g = 70 >> 2, b = 0; i < orange0 + 5; i++, r -= 8, g -= 3) {
			mapcolor(i, r, g, b);
		}	
		for (i = tan0, r = 176 >> 2, g = 144 >> 2, b = 112 >> 2; i < tan0 + 5; i++, r -= 5, g -= 5, b -= 5) {
			mapcolor(i, r, g, b);
		}
		for (i = silver0, r = 160 >> 2, g = 176 >> 2, b = 188 >> 2; i <= silver9; i++, r -= 2, g -= 2, b -= 2) {
			mapcolor(i, r, g, b);
		}
	}
}
void setColor(int c) {
	if (c > 300) {
		c = 299;
	}
	if (c < 300) {
		glColor3fv(floatingColor[c]);
	}
}
void dimColor(int c) {
	if (c > 300) {
		c = 299;
	}
	if (c < 300) {
		glColor3f(floatingColor[c][0] / 2.0f, floatingColor[c][1] / 2.0f, floatingColor[c][2] / 2.0f);
	}
}
void setClearColor(int c) {
	if (c > 299) {
		c = 299;
	}
	if (c < 300) {
		glClearColor(
			floatingColor[c][0],
			floatingColor[c][1],
			floatingColor[c][2],
			floatingColor[c][3]
		);
	}
}
void mapcolor(int c, int r, int v, int b) {
	floatingColor[c][0] = r / 255.0f;
	floatingColor[c][1] = v / 255.0f;
	floatingColor[c][2] = b / 255.0f;
	floatingColor[c][3] = 1.0f;
}