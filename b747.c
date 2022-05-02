/**************************************************************************
 *									  *
 *  Copyright (C)  1988 Silicon Graphics, Inc.	  *
 *									  *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *									  *
 **************************************************************************/

 /* contains plane definitions	*/
#include "planes.h"



/************************************************************
	B747 plane definitions  Don Hill 10-10-84
/************************************************************/
static GLshort Ehanger[][3] = {
	{  0,  0,   0},
	{  0,  0,  17},
	{  0, -4,   5},
	{  0, -4, -10},
};
static GLshort EL1[][3] = {
	{ -3, -3, -12},
	{ -3, -9, -12},
	{ -3, -9,  -4},
	{ -3, -3,  -4},
};
static GLshort EL2[][3] = {
	{ -2, -4,  -4},
	{ -2, -8,  -4},
	{ -2, -8,   4},
	{ -2, -4,   4},
};
static GLshort EL3[][3] = {
	{ -1, -5,   4},
	{  0, -6,  10},
	{ -1, -7,   4},
};
static GLshort ER1[][3] = {
	{  3, -3, -12},
	{  3, -9, -12},
	{  3, -9,  -4},
	{  3, -3,  -4},
};
static GLshort ER2[][3] = {
	{  2, -4,  -4},
	{  2, -8,  -4},
	{  2, -8,   4},
	{  2, -4,   4},
};
static GLshort ER3[][3] = {
	{  1, -5,   4},
	{  0, -6,  10},
	{  1, -7,   4},
};
static GLshort EFRONT[][3] = {
	{ -3, -3, -11},
	{ -3, -9, -11},
	{  3, -9, -11},
	{  3, -3, -11},
};
static GLshort EFIRE[][3] = {
	{ -2, -4, 3},
	{ -2, -8, 3},
	{  2, -8, 3},
	{  2, -4, 3},
};
static GLshort ET1[][3] = {
	{ -3, -3, -12},
	{  3, -3, -12},
	{  3, -3,  -4},
	{ -3, -3,  -4},
};
static GLshort EB1[][3] = {
	{ -3, -9, -12},
	{  3, -9, -12},
	{  3, -9,  -4},
	{ -3, -9,  -4},
};
static GLshort ET2[][3] = {
	{ -2, -4,  -4},
	{  2, -4,  -4},
	{  2, -4,   4},
	{ -2, -4,   4},
};
static GLshort EB2[][3] = {
	{ -2, -8,  -4},
	{  2, -8,  -4},
	{  2, -8,   4},
	{ -2, -8,   4},
};
static GLshort ET3[][3] = {
	{  1, -5,   4},
	{  0, -6,  10},
	{ -1, -5,   4},
};
static GLshort EB3[][3] = {
	{  1, -7,   4},
	{  0, -6,  10},
	{ -1, -7,   4},
};
static GLshort B1[][3] = {
	{  0, 20, -100},
	{ -4, 16,  -98},
	{  4, 16,  -98},
};
static GLshort B2[][3] = {
	{  4, 16, -98},
	{ -4, 16, -98},
	{-10, 10, -84},
	{ 10, 10, -84},
};
static GLshort B3[][3] = {
	{ 10, 10, -84},
	{-10, 10, -84},
	{-10, 10,  66},
	{ 10, 10,  66},
};
static GLshort B4[][3] = {
	{ 10, 10,  66},
	{-10, 10,  66},
	{-10, 17,  99},
	{  0, 24, 132},
	{ 10, 17,  99},
};
static GLshort L1[][3] = {
	{  0, 20,-100},
	{ -4, 24, -98},
	{ -4, 16, -98},
};
static GLshort L2[][3] = {
	{ -4, 16, -98},
	{ -4, 24, -98},
	{-10, 30, -84},
	{-10, 10, -84},
};
static GLshort L3[][3] = {
	{-10, 10, -84},
	{-10, 30, -84},
	{-10, 30,  99},
	{-10, 17,  99},
	{-10, 10,  66},
};
static GLshort L4[][3] = {
	{-10, 17,  99},
	{-10, 30,  99},
	{  0, 30, 132},
	{  0, 24, 132},
};
static GLshort R1[][3] = {
	{  0, 20,-100},
	{  4, 24, -98},
	{  4, 16, -98},
};
static GLshort R2[][3] = {
	{  4, 16, -98},
	{  4, 24, -98},
	{ 10, 30, -84},
	{ 10, 10, -84},
};
static GLshort R3[][3] = {
	{ 10, 10, -84},
	{ 10, 30, -84},
	{ 10, 30,  99},
	{ 10, 17,  99},
	{ 10, 10,  66},
};
static GLshort R4[][3] = {
	{ 10, 17,  99},
	{ 10, 30,  99},
	{  0, 30, 132},
	{  0, 24, 132},
};
static GLshort T0[][3] = {	/* used for shadow	*/
	{  0, 30,-100},
	{  4, 30, -98},
	{ 10, 30, -84},
	{ 10, 30,  99},
	{  0, 30, 132},
	{-10, 30,  99},
	{-10, 30, -84},
	{ -4, 30, -98},
};
static GLshort T1[][3] = {
	{  0, 20,-100},
	{ -4, 24, -98},
	{  4, 24, -98},
};
static GLshort T2[][3] = {
	{  4, 24, -98},
	{ -4, 24, -98},
	{ -2, 30, -90},
	{  2, 30, -90},
};
static GLshort T3[][3] = {
	{  4, 24, -98},
	{  2, 30, -90},
	{  8, 30, -84},
	{ 10, 30, -84},
};
static GLshort T4[][3] = {
	{ -4, 24, -98},
	{ -2, 30, -90},
	{ -8, 30, -84},
	{-10, 30, -84},
};
static GLshort T5[][3] = {
	{ 10, 30, -84},
	{  8, 30, -84},
	{  6, 32, -84},
	{  6, 34, -84},
};
static GLshort T6[][3] = {
	{-10, 30, -84},
	{ -8, 30, -84},
	{ -6, 32, -84},
	{ -6, 34, -84},
};
static GLshort T7[][3] = {
	{ -2, 30, -90},
	{  2, 30, -90},
	{  2, 32, -88},
	{ -2, 32, -88},
};
static GLshort T8[][3] = {
	{  2, 30, -90},
	{  2, 32, -88},
	{  6, 32, -84},
	{  8, 30, -84},
};
static GLshort T9[][3] = {
	{ -2, 30, -90},
	{ -2, 32, -88},
	{ -6, 32, -84},
	{ -8, 30, -84},
};
static GLshort T10[][3] = {
	{  2, 32, -88},
	{  6, 34, -84},
	{ -6, 34, -84},
	{ -2, 32, -88},
};
static GLshort T13[][3] = {
	{  6, 34, -84},
	{  6, 34, -68},
	{ -6, 34, -68},
	{ -6, 34, -84},
};
static GLshort T14[][3] = {
	{  6, 34, -84},
	{ 10, 30, -84},
	{ 10, 30, -52},
	{  6, 34, -68},
};
static GLshort T15[][3] = {
	{ -6, 34, -84},
	{-10, 30, -84},
	{-10, 30, -52},
	{ -6, 34, -68},
};
static GLshort T16[][3] = {
	{  6, 34, -68},
	{ 10, 30, -52},
	{-10, 30, -52},
	{ -6, 34, -68},
};
static GLshort T17[][3] = {
	{ 10, 30, -52},
	{ 10, 30,  99},
	{  0, 30, 132},
	{-10, 30,  99},
	{-10, 30, -52},
};
static GLshort rudder[][3] = {
	{  0, 30, 126},
	{  0, 64, 140},
	{  0, 64, 128},
	{  0, 30,  92},
};
static GLshort fakeside[][3] = {
	{  0, 30, 132},
	{  0, 16, 132},
	{  0, 16,-100},
	{  0, 30,-100},
};
static GLshort rightelevator1[][3] = {
	{  0, 26, 126},
	{ 49, 30, 140},
	{ 49, 30, 130},
	{ 10, 26,  99},
};
static GLshort rightelevator2[][3] = {
	{ 10, 26,  89},
	{ 10, 26,  99},
	{ 49, 30, 130},
	{ 49, 30, 126},
};
static GLshort leftelevator1[][3] = {
	{ -0, 26, 126},
	{-49, 30, 140},
	{-49, 30, 130},
	{-10, 26,  99},
};
static GLshort leftelevator2[][3] = {
	{-10, 26,  89},
	{-10, 26,  99},
	{-49, 30, 130},
	{-49, 30, 126},
};
static GLshort rightwing1[][3] = {
	{ 10, 16, -55 + 20},
	{ 10, 16, -15 + 20},
	{ 98, 24,  31 + 20},
	{ 98, 24,  13 + 20},
};
static GLfloat rightwing2[][3] = {
	{ 10, 16, -15 + 20},
	{ 10, 16,  -7 + 20},
	{ 38, 18.5555f, -3 + 20},
};
static GLshort leftwing1[][3] = {
	{-10, 16, -55 + 20},
	{-10, 16, -15 + 20},
	{-98, 24,  31 + 20},
	{-98, 24,  13 + 20},
};
static GLfloat leftwing2[][3] = {
	{-10, 16, -15 + 20},
	{-10, 16,  -7 + 20},
	{-38, 18.5555f, -3 + 20},
};
static GLshort fakewing[][3] = {
	{ 98, 24,  31 + 20},
	{ -98, 24,  31 + 20},
	{ 0,  16, -55 + 20}
};

#define C_TOPNOSE silver4
#define C_LEFTNOSE silver6
#define C_TOPBUBBLE silver1
#define C_FRONTBUBBLE silver3
#define C_TOPBACK silver2
#define C_RIGHTRUDDER silver3
#define C_LEFTRUDDER silver4
#define C_UNDERWING silver8
#define C_UNDERBODY silver9


void make_b747(GLuint obj) {
	GLuint eng_alf, eng_arf;

	eng_alf = 2000;
	eng_arf = 2001;

	glNewList(eng_alf, GL_COMPILE);
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(EB3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EB2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EB1[i]); glEnd(); };
	setColor(C_LEFTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(ER3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ER2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ER1[i]); glEnd(); };
	setColor(red);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EFIRE[i]); glEnd(); };
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EFRONT[i]); glEnd(); };
	setColor(C_LEFTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(EL3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EL2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EL1[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(ET3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ET2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ET1[i]); glEnd(); };
	setColor(C_LEFTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(Ehanger[i]); glEnd(); };
	glEndList();

	glNewList(eng_arf, GL_COMPILE);
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(EB3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EB2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EB1[i]); glEnd(); };
	setColor(C_LEFTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(EL3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EL2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EL1[i]); glEnd(); };
	setColor(red);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EFIRE[i]); glEnd(); };
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EFRONT[i]); glEnd(); };
	setColor(C_LEFTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(ER3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ER2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ER1[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(ET3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ET2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ET1[i]); glEnd(); };
	setColor(C_LEFTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(Ehanger[i]); glEnd(); };
	glEndList();



	glNewList(obj, GL_COMPILE);
	glEnable(GL_NORMALIZE);
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rudder[i]); glEnd(); };
	setColor(white);
	glBegin(GL_POINTS); glVertex3s(0, 64, 140); glEnd();
	setColor(C_UNDERWING);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightwing1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(rightwing2[i]); glEnd(); };
	glBegin(GL_LINE_STRIP); glVertex3s(98, 24, 31);
	glVertex3s(98, 24, 40);
	glEnd();
	setColor(green0);
	glBegin(GL_POINTS); glVertex3s(98, 24, 31); glEnd();

	setColor(C_TOPBACK);	/*	top back to front from left 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(T17[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T14[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T16[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T13[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T15[i]); glEnd(); };
	setColor(C_TOPBUBBLE);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T8[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T7[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T9[i]); glEnd(); };
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T8[i]); glEnd(); };
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T7[i]); glEnd(); };
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T9[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T10[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T5[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T3[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T2[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T4[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T6[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(T1[i]); glEnd(); };

	setColor(C_RIGHTRUDDER);	/*	right side back to front 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R4[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(R3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(R1[i]); glEnd(); };

	setColor(C_RIGHTRUDDER);	/*	left side back to front 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L4[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(L3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(L1[i]); glEnd(); };

	setColor(C_UNDERBODY);	/*	bottom back to front	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(B4[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(B3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(B2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(B1[i]); glEnd(); };

	setColor(C_UNDERWING);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftwing1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(leftwing2[i]); glEnd(); };
	glBegin(GL_LINE_STRIP); 
	glVertex3s(-98, 24, 31);
	glVertex3s(-98, 24, 40);
	glEnd();
	setColor(red);
	glBegin(GL_POINTS); 
	glVertex3s(-98, 24, 31); 
	glEnd();


	glPushMatrix();
	glTranslatef(68.0f, 21.27f, -9.0f + 20);
	glCallList(eng_alf);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(40.0f, 18.73f, -21.0f + 20);
	glCallList(eng_alf);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-40.0f, 18.73f, -21.0f + 20);
	glCallList(eng_alf);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-68.0f, 21.27f, -9.0f + 20);
	glCallList(eng_alf);
	glPopMatrix();
	glDisable(GL_NORMALIZE);
	glEndList();



	glNewList(obj+9, GL_COMPILE);		/* shadow	*/
	setColor(black);
	if (3) { glCallList(3); glEnable(GL_POLYGON_STIPPLE); }
	else glDisable(GL_POLYGON_STIPPLE);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rudder[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightwing1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(rightwing2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftwing1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(leftwing2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L4[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(L3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(L1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R4[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(R3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(R1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 8; i++) glVertex3sv(T0[i]); glEnd(); };
	if (0) { glCallList(0); glEnable(GL_POLYGON_STIPPLE); }
	else glDisable(GL_POLYGON_STIPPLE);
	glEndList();

	glNewList(obj + 100, GL_COMPILE);		/* shadow far away	*/
	setColor(black);
	if (3) { glCallList(3); glEnable(GL_POLYGON_STIPPLE); }
	else glDisable(GL_POLYGON_STIPPLE);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(fakewing[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rudder[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(fakeside[i]); glEnd(); };
	if (0) { glCallList(0); glEnable(GL_POLYGON_STIPPLE); }
	else glDisable(GL_POLYGON_STIPPLE);
	glEndList();

}

void make_b747_old(GLuint obj)
{
	GLuint eng_alf, eng_arf, eng_blf, eng_brf;
	GLuint eng_alb, eng_arb, eng_blb, eng_brb;

	eng_alf = 2000;
	eng_arf = 2001;
	eng_blf = 2002;
	eng_brf = 2003;
	eng_alb = 2004;
	eng_arb = 2005;
	eng_blb = 2006;
	eng_brb = 2007;

	glNewList(eng_alf, GL_COMPILE);
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(EB3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EB2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EB1[i]); glEnd(); };
	setColor(C_LEFTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(ER3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ER2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ER1[i]); glEnd(); };
	setColor(red);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EFIRE[i]); glEnd(); };
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EFRONT[i]); glEnd(); };
	setColor(C_LEFTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(EL3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EL2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EL1[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(ET3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ET2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ET1[i]); glEnd(); };
	setColor(C_LEFTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(Ehanger[i]); glEnd(); };
	glEndList();

	glNewList(eng_arf, GL_COMPILE);
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(EB3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EB2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EB1[i]); glEnd(); };
	setColor(C_LEFTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(EL3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EL2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EL1[i]); glEnd(); };
	setColor(red);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EFIRE[i]); glEnd(); };
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EFRONT[i]); glEnd(); };
	setColor(C_LEFTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(ER3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ER2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ER1[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(ET3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ET2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ET1[i]); glEnd(); };
	setColor(C_LEFTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(Ehanger[i]); glEnd(); };
	glEndList();

	glNewList(eng_blf, GL_COMPILE);
	setColor(C_LEFTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(Ehanger[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ET1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ET2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(ET3[i]); glEnd(); };
	setColor(C_LEFTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ER1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ER2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(ER3[i]); glEnd(); };
	setColor(red);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EFIRE[i]); glEnd(); };
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EFRONT[i]); glEnd(); };
	setColor(C_LEFTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EL1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EL2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(EL3[i]); glEnd(); };
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EB1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EB2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(EB3[i]); glEnd(); };
	glEndList();

	glNewList(eng_brf, GL_COMPILE);
	setColor(C_LEFTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(Ehanger[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ET1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ET2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(ET3[i]); glEnd(); };
	setColor(C_LEFTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EL1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EL2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(EL3[i]); glEnd(); };
	setColor(red);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EFIRE[i]); glEnd(); };
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EFRONT[i]); glEnd(); };
	setColor(C_LEFTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ER1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(ER2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(ER3[i]); glEnd(); };
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EB1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(EB2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(EB3[i]); glEnd(); };
	glEndList();

	glNewList(obj++, GL_COMPILE);	/* below, left, front	*/
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rudder[i]); glEnd(); };
	setColor(white);
	glBegin(GL_POINTS); glVertex3s(0, 64, 140); glEnd();
	setColor(C_UNDERWING);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightwing1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(rightwing2[i]); glEnd(); };
	glBegin(GL_LINE_STRIP); glVertex3s(98, 24, 31);
	glVertex3s(98, 24, 40);
	glEnd();
	setColor(green0);
	glBegin(GL_POINTS); glVertex3s(98, 24, 31); glEnd();

	setColor(C_TOPBACK);	/*	top back to front from left 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(T17[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T14[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T16[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T13[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T15[i]); glEnd(); };
	setColor(C_TOPBUBBLE);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T8[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T7[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T9[i]); glEnd(); };
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T8[i]); glEnd(); };
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T7[i]); glEnd(); };
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T9[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T10[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T5[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T3[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T2[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T4[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T6[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(T1[i]); glEnd(); };

	setColor(C_RIGHTRUDDER);	/*	right side back to front 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R4[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(R3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(R1[i]); glEnd(); };

	setColor(C_RIGHTRUDDER);	/*	left side back to front 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L4[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(L3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(L1[i]); glEnd(); };

	setColor(C_UNDERBODY);	/*	bottom back to front	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(B4[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(B3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(B2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(B1[i]); glEnd(); };

	setColor(C_UNDERWING);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftwing1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(leftwing2[i]); glEnd(); };
	glBegin(GL_LINE_STRIP); glVertex3s(-98, 24, 31);
	glVertex3s(-98, 24, 40);
	glEnd();
	setColor(red);
	glBegin(GL_POINTS); glVertex3s(-98, 24, 31); glEnd();
	glEndList();

	glNewList(obj++, GL_COMPILE);	/* below ,right, front */
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rudder[i]); glEnd(); };
	setColor(white);
	glBegin(GL_POINTS); glVertex3s(0, 64, 140); glEnd();
	setColor(C_UNDERWING);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftwing1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(leftwing2[i]); glEnd(); };
	glBegin(GL_LINE_STRIP); glVertex3s(-98, 24, 31);
	glVertex3s(-98, 24, 40);
	glEnd();
	setColor(red);
	glBegin(GL_POINTS); glVertex3s(-98, 24, 31); glEnd();

	setColor(C_TOPBACK);	/*	top back to front 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(T17[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T15[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T16[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T13[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T14[i]); glEnd(); };
	setColor(C_TOPBUBBLE);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T9[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T7[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T8[i]); glEnd(); };
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T9[i]); glEnd(); };
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T7[i]); glEnd(); };
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T8[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T10[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T6[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T4[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T2[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T3[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T5[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(T1[i]); glEnd(); };

	setColor(C_RIGHTRUDDER);	/*	left side back to front 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L4[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(L3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(L1[i]); glEnd(); };

	setColor(C_RIGHTRUDDER);	/*	right side back to front 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R4[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(R3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(R1[i]); glEnd(); };

	setColor(C_UNDERBODY);	/*	bottom back to front	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(B4[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(B3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(B2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(B1[i]); glEnd(); };

	setColor(C_UNDERWING);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightwing1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(rightwing2[i]); glEnd(); };
	glBegin(GL_LINE_STRIP); 
	glVertex3s(98, 24, 31);
	glVertex3s(98, 24, 40);
	glEnd();
	setColor(green0);
	glBegin(GL_POINTS); 
	glVertex3s(98, 24, 31); 
	glEnd();
	glEndList();

	glNewList(obj++, GL_COMPILE);	/* above, left, front	*/
	setColor(C_UNDERBODY);	/*	bottom back to front	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(B2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(B1[i]); glEnd(); };

	glPushMatrix();
	glTranslatef(68.0f, 21.27f, -9.0f + 20);
	glCallList(eng_alf);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(40.0f, 18.73f, -21.0f + 20);
	glCallList(eng_alf);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-40.0f, 18.73f, -21.0f + 20);
	glCallList(eng_alf);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-68.0f, 21.27f, -9.0f + 20);
	glCallList(eng_alf);
	glPopMatrix();

	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator1[i]); glEnd(); };
	setColor(silver1);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator2[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightwing1[i]); glEnd(); };
	setColor(silver1);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(rightwing2[i]); glEnd(); };
	glBegin(GL_LINE_STRIP); glVertex3s(98, 24, 31);
	glVertex3s(98, 24, 40);
	setColor(green0);
	glBegin(GL_POINTS); glVertex3s(98, 24, 31); glEnd();

	setColor(C_RIGHTRUDDER);	/*	right side back to front 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(R1[i]); glEnd(); };

	setColor(C_RIGHTRUDDER);	/*	left side back to front 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L4[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(L3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(L1[i]); glEnd(); };

	setColor(C_TOPBACK);	/*	top back to front from left 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(T17[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T14[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T16[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T13[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T15[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T5[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T3[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T2[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T4[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T6[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(T1[i]); glEnd(); };
	setColor(C_TOPBUBBLE);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T8[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T7[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T9[i]); glEnd(); };
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T8[i]); glEnd(); };
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T7[i]); glEnd(); };
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T9[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T10[i]); glEnd(); };

	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rudder[i]); glEnd(); };
	setColor(white);
	glBegin(GL_POINTS); glVertex3s(0, 64, 140); glEnd();
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator1[i]); glEnd(); };
	setColor(silver1);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator2[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftwing1[i]); glEnd(); };
	setColor(silver1);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(leftwing2[i]); glEnd(); };
	glBegin(GL_LINE_STRIP); glVertex3s(-98, 24, 31);
	glVertex3s(-98, 24, 40);
	setColor(red);
	glBegin(GL_POINTS); glVertex3s(-98, 24, 31); glEnd();
	glEndList();

	glNewList(obj++, GL_COMPILE);	/* above, right, front		*/
	setColor(C_UNDERBODY);	/*	bottom back to front	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(B2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(B1[i]); glEnd(); };

	glPushMatrix();
	glTranslatef(68.0f, 21.27f, -9.0f + 20);
	glCallList(eng_arf);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(40.0f, 18.73f, -21.0f + 20);
	glCallList(eng_arf);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-40.0f, 18.73f, -21.0f + 20);
	glCallList(eng_arf);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-68.0f, 21.27f, -9.0f + 20);
	glCallList(eng_arf);
	glPopMatrix();

	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator1[i]); glEnd(); };
	setColor(silver1);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator2[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftwing1[i]); glEnd(); };
	setColor(silver1);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(leftwing2[i]); glEnd(); };
	glBegin(GL_LINE_STRIP); glVertex3s(-98, 24, 31);
	glVertex3s(-98, 24, 40);
	setColor(red);
	glBegin(GL_POINTS); glVertex3s(-98, 24, 31); glEnd();

	setColor(C_RIGHTRUDDER);	/*	left side back to front 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(L1[i]); glEnd(); };

	setColor(C_RIGHTRUDDER);	/*	right side back to front 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R4[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(R3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(R1[i]); glEnd(); };

	setColor(C_TOPBACK);	/*	top back to front 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(T17[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T15[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T16[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T13[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T14[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T6[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T4[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T2[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T3[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T5[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(T1[i]); glEnd(); };

	setColor(C_TOPBUBBLE);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T9[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T7[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T8[i]); glEnd(); };
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T9[i]); glEnd(); };
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T7[i]); glEnd(); };
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T8[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T10[i]); glEnd(); };

	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator1[i]); glEnd(); };
	setColor(silver1);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator2[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightwing1[i]); glEnd(); };
	setColor(silver1);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(rightwing2[i]); glEnd(); };
	glBegin(GL_LINE_STRIP); glVertex3s(98, 24, 31);
	glVertex3s(98, 24, 40);
	setColor(green0);
	glBegin(GL_POINTS); glVertex3s(98, 24, 31); glEnd();
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rudder[i]); glEnd(); };
	setColor(white);
	glBegin(GL_POINTS); glVertex3s(0, 64, 140); glEnd();
	glEndList();

	glNewList(obj++, GL_COMPILE);	/* below, left, behind		*/

	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rudder[i]); glEnd(); };
	setColor(white);
	glBegin(GL_POINTS); glVertex3s(0, 64, 140); glEnd();
	setColor(C_UNDERWING);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightwing1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(rightwing2[i]); glEnd(); };
	glBegin(GL_LINE_STRIP); glVertex3s(98, 24, 31);
	glVertex3s(98, 24, 40);
	setColor(green0);
	glBegin(GL_POINTS); glVertex3s(98, 24, 31); glEnd();

	setColor(silver0);	/* top front to back */
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(T1[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T2[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T3[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T5[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T6[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T4[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T10[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T13[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T14[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T15[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T16[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(T17[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);	/*	rightside front to back 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(R1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(R3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R4[i]); glEnd(); };

	setColor(C_UNDERBODY);	/*	bottom front to back	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(B1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(B2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(B3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(B4[i]); glEnd(); };

	setColor(C_RIGHTRUDDER);	/*	left side front to back  	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(L1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(L3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L4[i]); glEnd(); };

	setColor(C_UNDERWING);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftwing1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(leftwing2[i]); glEnd(); };
	glBegin(GL_LINE_STRIP); glVertex3s(-98, 24, 31);
	glVertex3s(-98, 24, 40);
	glBegin(GL_LINE_STRIP); glVertex3s(-98, 24, 31);
	glVertex3s(-98, 24, 40);
	setColor(red);
	glBegin(GL_POINTS); glVertex3s(-98, 24, 31); glEnd();
	glEndList();

	glNewList(obj++, GL_COMPILE);	/* below, right, behind		*/
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rudder[i]); glEnd(); };
	setColor(white);
	glBegin(GL_POINTS); glVertex3s(0, 64, 140); glEnd();
	setColor(C_UNDERWING);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftwing1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(leftwing2[i]); glEnd(); };
	glBegin(GL_LINE_STRIP); glVertex3s(-98, 24, 31);
	glVertex3s(-98, 24, 40);
	setColor(red);
	glBegin(GL_POINTS); glVertex3s(-98, 24, 31); glEnd();

	setColor(silver0);	/* top front to back */
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(T1[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T2[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T3[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T5[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T6[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T4[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T10[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T13[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T14[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T15[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T16[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(T17[i]); glEnd(); };

	setColor(C_RIGHTRUDDER);	/*	left side front to back 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(L1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(L3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L4[i]); glEnd(); };

	setColor(C_RIGHTRUDDER);	/*	right side front to back 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(R1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(R3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R4[i]); glEnd(); };

	setColor(C_UNDERBODY);	/*	bottom front to back	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(B1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(B2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(B3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(B4[i]); glEnd(); };

	setColor(C_UNDERWING);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightwing1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(rightwing2[i]); glEnd(); };
	glBegin(GL_LINE_STRIP); glVertex3s(98, 24, 31);
	glVertex3s(98, 24, 40);
	setColor(green0);
	glBegin(GL_POINTS); glVertex3s(98, 24, 31); glEnd();
	glEndList();

	glNewList(obj++, GL_COMPILE);	/* above, left, behind		*/
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator1[i]); glEnd(); };
	setColor(silver1);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator2[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightwing1[i]); glEnd(); };
	setColor(silver1);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(rightwing2[i]); glEnd(); };
	glBegin(GL_LINE_STRIP); glVertex3s(98, 24, 31);
	glVertex3s(98, 24, 40);
	setColor(green0);
	glBegin(GL_POINTS); glVertex3s(98, 24, 31); glEnd();

	setColor(C_UNDERBODY);	/*	bottom front to back	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(B4[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);	/*	right side front to back 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R4[i]); glEnd(); };

	setColor(C_RIGHTRUDDER);	/*	left side front to back  	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(L1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(L3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L4[i]); glEnd(); };
	setColor(C_TOPBUBBLE);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T8[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T7[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T9[i]); glEnd(); };
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T8[i]); glEnd(); };
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T7[i]); glEnd(); };
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T9[i]); glEnd(); };

	setColor(silver0);	/* top front to back */
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(T1[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T2[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T3[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T5[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T6[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T4[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T10[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T14[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T15[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T16[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(T17[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T13[i]); glEnd(); };

	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rudder[i]); glEnd(); };
	setColor(white);
	glBegin(GL_POINTS); glVertex3s(0, 64, 140); glEnd();
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator1[i]); glEnd(); };
	setColor(silver1);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator2[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftwing1[i]); glEnd(); };
	setColor(silver1);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(leftwing2[i]); glEnd(); };
	glBegin(GL_LINE_STRIP); glVertex3s(-98, 24, 31);
	glVertex3s(-98, 24, 40);
	setColor(red);
	glBegin(GL_POINTS); glVertex3s(-98, 24, 31); glEnd();
	glEndList();

	glNewList(obj++, GL_COMPILE);	/* above, right, behind		*/
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator1[i]); glEnd(); };
	setColor(silver1);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator2[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftwing1[i]); glEnd(); };
	setColor(silver1);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(leftwing2[i]); glEnd(); };
	glBegin(GL_LINE_STRIP); glVertex3s(-98, 24, 31);
	glVertex3s(-98, 24, 40);
	setColor(red);
	glBegin(GL_POINTS); glVertex3s(-98, 24, 31); glEnd();


	setColor(C_UNDERBODY);	/*	bottom front to back	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(B4[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);	/*	left side front to back 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L4[i]); glEnd(); };

	setColor(C_RIGHTRUDDER);	/*	right side front to back 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(R1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(R3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R4[i]); glEnd(); };

	setColor(C_TOPBUBBLE);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T9[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T7[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T8[i]); glEnd(); };
	setColor(C_UNDERBODY);
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T9[i]); glEnd(); };
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T7[i]); glEnd(); };
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 4; i++) glVertex3sv(T8[i]); glEnd(); };

	setColor(silver0);	/*  top front to back 	*/
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(T1[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T2[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T3[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T5[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T6[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T4[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T10[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T14[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T15[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T16[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(T17[i]); glEnd(); };
	setColor(C_TOPBACK);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(T13[i]); glEnd(); };

	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator1[i]); glEnd(); };
	setColor(silver1);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator2[i]); glEnd(); };
	setColor(silver0);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightwing1[i]); glEnd(); };
	setColor(silver1);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(rightwing2[i]); glEnd(); };
	glBegin(GL_LINE_STRIP); glVertex3s(98, 24, 31);
	glVertex3s(98, 24, 40);
	setColor(green0);
	glBegin(GL_POINTS); glVertex3s(98, 24, 31); glEnd();
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rudder[i]); glEnd(); };
	setColor(white);
	glBegin(GL_POINTS); glVertex3s(0, 64, 140); glEnd();

	glEndList();

	glNewList(obj++, GL_COMPILE);		/* real far away	*/
	setColor(silver1);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(fakewing[i]); glEnd(); };
	setColor(C_RIGHTRUDDER);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rudder[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(fakeside[i]); glEnd(); };
	setColor(red);
	glBegin(GL_POINTS); glVertex3s(-98, 24, 31); glEnd();
	setColor(white);
	glBegin(GL_POINTS); glVertex3s(0, 64, 140); glEnd();
	setColor(green0);
	glBegin(GL_POINTS); glVertex3s(98, 24, 31); glEnd();
	glEndList();

	glNewList(obj++, GL_COMPILE);		/* shadow	*/
	setColor(black);
	if (3) { glCallList(3); glEnable(GL_POLYGON_STIPPLE); }
	else glDisable(GL_POLYGON_STIPPLE);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rudder[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightelevator2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rightwing1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(rightwing2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftelevator2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(leftwing1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3fv(leftwing2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L4[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(L3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(L2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(L1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R4[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 5; i++) glVertex3sv(R3[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(R2[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(R1[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 8; i++) glVertex3sv(T0[i]); glEnd(); };
	if (0) { glCallList(0); glEnable(GL_POLYGON_STIPPLE); }
	else glDisable(GL_POLYGON_STIPPLE);
	glEndList();

	glNewList(obj + 100, GL_COMPILE);		/* shadow far away	*/
	setColor(black);
	if (3) { glCallList(3); glEnable(GL_POLYGON_STIPPLE); }
	else glDisable(GL_POLYGON_STIPPLE);
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(fakewing[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3sv(rudder[i]); glEnd(); };
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 3; i++) glVertex3sv(fakeside[i]); glEnd(); };
	if (0) { glCallList(0); glEnable(GL_POLYGON_STIPPLE); }
	else glDisable(GL_POLYGON_STIPPLE);
	glEndList();
}
