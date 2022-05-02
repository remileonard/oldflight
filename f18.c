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
/*	F-18 plane definition
/************************************************************/
static GLfloat fakewing[][3] = {
	{0, 0, -38},
	{20, 0, 12},
	{-20, 0, 12},
};
static GLfloat fakestab[][3] = { 
	{0, 0, 0}, 
	{0, 10, 12}, 
	{0, 0, 12},
};
static GLfloat rightfire[][3] = {
	{1.6f, .75f, 16.0f},
	{2.4f, .75f, 16.0f},
	{3.0f, 1.5f, 16.0f},
	{2.4f, 2.25f, 16.0f},
	{1.6f, 2.25f, 16.0f},
	{1.0f, 1.5f, 16.0f},
};
static GLfloat leftfire[][3] = {
	{-1.0f, 1.5f, 16.0f},
	{-1.6f, 2.25f, 16.0f},
	{-2.4f, 2.25f, 16.0f},
	{-3.0f, 1.5f, 16.0f},
	{-2.4f, .75f, 16.0f},
	{-1.6f, .75f, 16.0f},
};

static GLfloat rightwing[][3] = {
	{4, 3, 5},
	{20, 3, 4},
	{20, 3, -1},
	{4, 3, -8},
};
static GLfloat leftwing[][3] = {
	{-4, 3, -8},
	{-20, 3, -1},
	{-20, 3, 4},
	{-4, 3, 5},
};

static GLfloat brightwing[][3] = {
	{4, 3, -8},
	{20, 3, -1},
	{20, 3, 4},
	{4, 3, 5},
};
static GLfloat bleftwing[][3] = {
	{-4, 3, 5},
	{-20, 3, 4},
	{-20, 3, -1},
	{-4, 3, -8},
};

static GLfloat brightchine[][3] = {
	{1.5, 3, -22},
	{4, 3, -11},
	{4, 3, -8},
	{1.5, 3, -8},
};
static GLfloat bleftchine[][3] = {
	{-1.5, 3, -8},
	{-4, 3, -8},
	{-4, 3, -11},
	{-1.5, 3, -22},
};

static GLfloat rightchine[][3] = {
	{1.5, 3, -8},
	{4, 3, -8},
	{4, 3, -11},
	{1.5, 3, -22},
};
static GLfloat leftchine[][3] = {
	{-1.5, 3, -22},
	{-4, 3, -11},
	{-4, 3, -8},
	{-1.5, 3, -8},
};

static GLfloat rightrudder[][3] = {
	{3, 3, 11},
	{6, 10, 12},
	{6, 10, 8},
	{3, 3, 2},
};
static GLfloat leftrudder[][3] = {
	{-3, 3, 11},
	{-6, 10, 12},
	{-6, 10, 8},
	{-3, 3, 2},
};

static GLfloat brightrudder[][3] = {
	{3, 3, 2},
	{6, 10, 8},
	{6, 10, 12},
	{3, 3, 11},
};
static GLfloat bleftrudder[][3] = {
	{-3, 3, 2},
	{-6, 10, 8},
	{-6, 10, 12},
	{-3, 3, 11},
};


static GLfloat rightelevator[][3] = {
	{4, 2, 15}, 
	{10, 2, 18}, 
	{11, 2, 17}, 
	{11, 2, 15}, 
	{4, 2, 8},
};
static GLfloat leftelevator[][3] = {
	{-4, 2, 8}, 
	{-11, 2, 15}, 
	{-11, 2, 17}, 
	{-10, 2, 18}, 
	{-4, 2, 15},
};

static GLfloat brightelevator[][3] = {
	{4, 2, 8},
	{11, 2, 15},
	{11, 2, 17},
	{10, 2, 18},
	{4, 2, 15},
};
static GLfloat bleftelevator[][3] = {
	{-4, 2, 15},
	{-10, 2, 18},
	{-11, 2, 17},
	{-11, 2, 15},
	{-4, 2, 8},
};

static GLfloat topback[][3] = {
	{4, 3, -8},
	{-4, 3, -8},
	{-4, 3, 16},
	{4, 3, 16},
};
static GLfloat rightback[][3] = {
	{4, 3, -8},
	{4, 3, 16},
	{4, 0, 16},
	{4, 0, -8},
};
static GLfloat leftback[][3] = {
	{-4, 0, -8},
	{-4, 0, 16},
	{-4, 3, 16},
	{-4, 3, -8},
};
static GLfloat bottomback[][3] = {
	{-4, 0, -8},
	{4, 0, -8},
	{4, 0, 16},
	{-4, 0, 16},
};
static GLfloat backback[][3] = {
	{-4, 0, 16},
	{4, 0, 16},
	{4, 3, 16},
	{-4, 3, 16},
};
static GLfloat frontback[][3] = {
	{-4, 3, -8},
	{4, 3, -8},
	{4, 0, -8},
	{-4, 0, -8},
};

static GLfloat bottomfront[][3] = {
	{1.5, 0, -32},
	{1.5, 0, -8},
	{-1.5, 0, -8},
	{-1.5, 0, -32},
};
static GLfloat rightfront[][3] = {
	{1.5f, 2.2f, -32}, 
	{1.5f, 5, -14}, 
	{1.5f, 4.7272f, -8},
	{1.5f, 0, -8},    
	{1.5f, 0, -32},
};
static GLfloat leftfront[][3] = {
	{-1.5f, 0, -32}, 
	{-1.5f, 0, -8},    
	{-1.5f, 4.7272f, -8},
	{-1.5f, 5, -14}, 
	{-1.5f, 2.2f, -32},
};
static GLfloat rightnose[][3] = {
	{1.5f, 2.2f, -32},
	{1.5f, 0, -32},
	{0, .6f, -38},
};
static GLfloat leftnose[][3] = {
	{-1.5f, 2.2f, -32},
	{0, .6f, -38},
	{-1.5f, 0, -32},

};
static GLfloat topnose[][3] = {
	{1.5f, 2.2f, -32},
	{0, .6f, -38},
	{-1.5f, 2.2f, -32},

};
static GLfloat botnose[][3] = {
	{0, .6f, -38},
	{1.5f, 0, -32},
	{-1.5f, 0, -32},
};
static GLfloat frontbubble[][3] = {
	{-1.5f, 2.2f, -32},
	{-1.5f, 5, -14},
	{1.5f, 5, -14},
	{1.5f, 2.2f, -32},
};
static GLfloat topbubble[][3] = {
	{-1.5f, 5, -14},
	{-1.5f, 4.7272f, -8},
	{0, 3, 8},
	{1.5f, 4.7272f, -8},
	{1.5f, 5, -14},
};
static GLfloat rightbubble[][3] = {
	{1.5f, 4.7272f, -8},
	{0, 3, 8},
	{1.5f, 3, -8},
};
static GLfloat leftbubble[][3] = {
	{-1.5f, 3, -8},
	{0, 3, 8},
	{-1.5f, 4.7272f, -8},
};
static GLfloat pit1[][3] = {
	{0, 3.14f, -26},
	{0, 6, -21},
	{1.5, 4, -21},

};
static GLfloat pit2[][3] = {
	{0, 3.14f, -26},
	{-1.5f, 4, -21},
	{0, 6, -21},
};
static GLfloat pit3[][3] = {
	{0, 5, -14},
	{1.5f, 4, -21},
	{0, 6, -21},
};
static GLfloat pit4[][3] = {
	{0, 6, -21},
	{-1.5f, 4, -21},
	{0, 5, -14},
};

#define C_TOPNOSE silver4
#define C_LEFTNOSE silver6
#define C_TOPBUBBLE silver1
#define C_FRONTBUBBLE silver3
#define C_TOPBACK silver2
#define C_RIGHTRUDDER silver3
#define C_LEFTRUDDER silver4
#define C_PIT1 silver6
#define C_PIT2 silver7
#define C_PIT3 silver8
#define C_PIT4 silver9
#define C_UNDERWING silver8
#define C_UNDERBODY silver9

void make_f18(GLuint obj) {

	float mat_logo_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
	float mat_logo_diffuse[] = { 0.5f, 0.4f, 0.7f, 1.0f };
	float mat_logo_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float mat_logo_shininess[] = { 30.0 };

	glNewList(obj, GL_COMPILE);
	glEnable(GL_NORMALIZE);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	setColor(silver5);
	setColor(C_TOPBACK);
	draw_poly(rightwing, 4, 0);
	draw_poly(leftwing, 4, 0);
	setColor(C_UNDERWING);
	draw_poly(brightwing, 4, 0);
	draw_poly(bleftwing, 4, 0);
	setColor(C_TOPBACK);
	draw_poly(rightelevator, 5, 0);
	draw_poly(leftelevator, 5, 0);
	setColor(C_UNDERWING);
	draw_poly(brightelevator, 5, 0);
	draw_poly(bleftelevator, 5, 0);

	setColor(C_RIGHTRUDDER);
	draw_poly(rightrudder, 4, 0);
	draw_poly(brightrudder, 4, 0);

	setColor(C_LEFTRUDDER);
	draw_poly(leftrudder, 4, 0);
	draw_poly(bleftrudder, 4, 0);

	setColor(C_TOPBACK);
	draw_poly(rightchine, 4, 0);
	draw_poly(leftchine, 4, 0);

	setColor(C_UNDERWING);
	draw_poly(brightchine, 4, 0);
	draw_poly(bleftchine, 4, 0);

	setColor(C_LEFTNOSE);
	draw_poly(rightfront, 5, 0);
	draw_poly(leftfront, 5, 0);
	setColor(C_UNDERBODY);
	draw_poly(bottomfront, 4, 0);

	setColor(C_FRONTBUBBLE);
	draw_poly(frontbubble, 4, 0);
	setColor(C_TOPBUBBLE);
	draw_poly(topbubble, 5, 0);
	setColor(C_LEFTNOSE);
	draw_poly(rightbubble, 3, 0);
	draw_poly(leftbubble, 3, 0);

	setColor(C_UNDERBODY);
	draw_poly(rightback, 4, 0);
	draw_poly(leftback, 4, 0);
	setColor(C_TOPBACK);
	draw_poly(topback, 4, 0);
	setColor(brown);
	draw_poly(frontback, 4, 0);
	setColor(C_UNDERBODY);
	draw_poly(bottomback, 4, 0);
	setColor(brown);
	draw_poly(backback, 4, 0);

	setColor(C_LEFTNOSE);
	draw_poly(rightnose, 3, 0);
	draw_poly(leftnose, 3, 0);
	setColor(C_TOPNOSE);
	draw_poly(topnose, 3, 0);
	setColor(C_UNDERBODY);
	draw_poly(botnose, 3, 0);

	setColor(C_PIT3);
	draw_poly(pit3, 3, 0);
	setColor(C_PIT4);
	draw_poly(pit4, 3, 0);
	setColor(C_PIT1);
	draw_poly(pit1, 3, 0);
	setColor(C_PIT2);
	draw_poly(pit2, 3, 0);

	setColor(orange);
	draw_poly(leftfire, 6, 0);
	draw_poly(rightfire, 6, 0);

	setColor(red);
	glBegin(GL_POINTS);
	glVertex3s(5, 8, 12);
	glEnd();

	setColor(white);
	glBegin(GL_POINTS);
	glVertex3s(-5, 8, 12);
	glEnd();

	setColor(green0);
	glBegin(GL_POINTS);
	glVertex3s(19, 3, -1);
	glEnd();

	setColor(red);
	glBegin(GL_POINTS);
	glVertex3s(-19, 3, -1);
	glEnd();

	setColor(C_UNDERBODY);
	glBegin(GL_LINE_STRIP);
	glVertex3s(-20, 3, 4);
	glVertex3s(-20, 3, -5);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3s(20, 3, 4);
	glVertex3s(20, 3, -5);
	glEnd();

	glDisable(GL_CULL_FACE);
	glDisable(GL_NORMALIZE);
	glEndList();

	/* shadow	*/
	glNewList(obj+9, GL_COMPILE); 
	setColor(black);
	setpattern(3);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftwing[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightwing[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(rightelevator[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(leftelevator[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightrudder[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftrudder[i]);
		glEnd();
	};

	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightback[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftback[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(topback[i]);
		glEnd();
	};

	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(rightfront[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(leftfront[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(frontbubble[i]);
		glEnd();
	};

	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(rightnose[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(leftnose[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(topnose[i]);
		glEnd();
	};
	setpattern(0);
	glEndList();

	/* shadow far away	*/
	glNewList(obj + 100, GL_COMPILE);
	setColor(black);
	setpattern(3);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(fakewing[i]);
		glEnd();
	};
	setpattern(0);
	glEndList();
}
void make_f18_old(GLuint obj) {
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glNewList(obj++, GL_COMPILE); /* below, left, front	*/
	setColor(C_RIGHTRUDDER);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightrudder[i]);
		glEnd();
	};
	setColor(red);
	glBegin(GL_POINTS);
	glVertex3s(5, 8, 12);
	glEnd();
	setColor(silver6);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(leftbubble[i]);
		glEnd();
	};
	setColor(C_LEFTRUDDER);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftrudder[i]);
		glEnd();
	};
	setColor(white);
	glBegin(GL_POINTS);
	glVertex3s(-5, 8, 12);
	glEnd();

	setColor(C_UNDERWING);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(rightelevator[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightwing[i]);
		glEnd();
	};
	glBegin(GL_LINE);
	glVertex3s(20, 3, 4);
	glVertex3s(20, 3, -5);
	glEnd();
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftwing[i]);
		glEnd();
	};
	glBegin(GL_LINE);
	glVertex3s(-20, 3, 4);
	glVertex3s(-20, 3, -5);
	glEnd();
	setColor(green0);
	glBegin(GL_POINTS);
	glVertex3s(19, 3, -1);
	glEnd();
	setColor(red);
	glBegin(GL_POINTS);
	glVertex3s(-19, 3, -1);
	glEnd();
	setColor(brown);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(frontback[i]);
		glEnd();
	};
	setColor(C_LEFTNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(rightnose[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftback[i]);
		glEnd();
	};
	setColor(C_UNDERWING);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(leftelevator[i]);
		glEnd();
	};

	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightchine[i]);
		glEnd();
	};
	setColor(C_FRONTBUBBLE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(frontbubble[i]);
		glEnd();
	};
	setColor(C_PIT4);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit4[i]);
		glEnd();
	};
	setColor(C_PIT1);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit1[i]);
		glEnd();
	};
	setColor(C_PIT2);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit2[i]);
		glEnd();
	};
	setColor(silver5);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(leftfront[i]);
		glEnd();
	};
	setColor(C_UNDERWING);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftchine[i]);
		glEnd();
	};

	setColor(C_TOPNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(topnose[i]);
		glEnd();
	};
	setColor(C_LEFTNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(leftnose[i]);
		glEnd();
	};

	setColor(C_UNDERBODY);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(bottomback[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(bottomfront[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(botnose[i]);
		glEnd();
	};
	// glEndList();

	// glNewList(obj++, GL_COMPILE);	/* below, right, front	*/
	setColor(C_LEFTRUDDER);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftrudder[i]);
		glEnd();
	};
	setColor(white);
	glBegin(GL_POINTS);
	glVertex3s(-5, 8, 12);
	glEnd();
	setColor(silver6);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(rightbubble[i]);
		glEnd();
	};
	setColor(C_RIGHTRUDDER);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightrudder[i]);
		glEnd();
	};
	setColor(red);
	glBegin(GL_POINTS);
	glVertex3s(5, 8, 12);
	glEnd();

	setColor(C_UNDERWING);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(leftelevator[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftwing[i]);
		glEnd();
	};
	glBegin(GL_LINE);
	glVertex3s(-20, 3, 4);
	glVertex3s(-20, 3, -5);
	glEnd();
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightwing[i]);
		glEnd();
	};
	glBegin(GL_LINE);
	glVertex3s(20, 3, 4);
	glVertex3s(20, 3, -5);
	glEnd();
	setColor(red);
	glBegin(GL_POINTS);
	glVertex3s(-19, 3, -1);
	glEnd();
	setColor(green0);
	glBegin(GL_POINTS);
	glVertex3s(19, 3, -1);
	glEnd();
	setColor(brown);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(frontback[i]);
		glEnd();
	};
	setColor(C_LEFTNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(leftnose[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightback[i]);
		glEnd();
	};
	setColor(C_UNDERWING);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(rightelevator[i]);
		glEnd();
	};

	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftchine[i]);
		glEnd();
	};
	setColor(C_FRONTBUBBLE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(frontbubble[i]);
		glEnd();
	};
	setColor(C_PIT3);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit3[i]);
		glEnd();
	};
	setColor(C_PIT2);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit2[i]);
		glEnd();
	};
	setColor(C_PIT1);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit1[i]);
		glEnd();
	};
	setColor(silver5);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(rightfront[i]);
		glEnd();
	};
	setColor(C_UNDERWING);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightchine[i]);
		glEnd();
	};

	setColor(C_TOPNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(topnose[i]);
		glEnd();
	};
	setColor(C_LEFTNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(rightnose[i]);
		glEnd();
	};

	setColor(C_UNDERBODY);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(bottomback[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(bottomfront[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(botnose[i]);
		glEnd();
	};
	// glEndList();

	// glNewList(obj++, GL_COMPILE);	/* above, left, front	*/
	setColor(silver0);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(rightelevator[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightwing[i]);
		glEnd();
	};
	glBegin(GL_LINE);
	glVertex3s(20, 3, 4);
	glVertex3s(20, 3, -5);
	glEnd();
	setColor(green0);
	glBegin(GL_POINTS);
	glVertex3s(19, 3, -1);
	glEnd();
	setColor(brown);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(frontback[i]);
		glEnd();
	};
	setColor(C_LEFTNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftback[i]);
		glEnd();
	};
	setColor(silver0);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(leftelevator[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftwing[i]);
		glEnd();
	};
	glBegin(GL_LINE);
	glVertex3s(-20, 3, 4);
	glVertex3s(-20, 3, -5);
	glEnd();
	setColor(red);
	glBegin(GL_POINTS);
	glVertex3s(-19, 3, -1);
	glEnd();
	setColor(C_TOPBACK);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(topback[i]);
		glEnd();
	};

	setColor(C_RIGHTRUDDER);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightrudder[i]);
		glEnd();
	};
	setColor(red);
	glBegin(GL_POINTS);
	glVertex3s(5, 8, 12);
	glEnd();
	setColor(silver2);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightchine[i]);
		glEnd();
	};
	setColor(C_TOPBUBBLE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(topbubble[i]);
		glEnd();
	};
	setColor(silver6);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(leftbubble[i]);
		glEnd();
	};

	setColor(C_LEFTRUDDER);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftrudder[i]);
		glEnd();
	};
	setColor(white);
	glBegin(GL_POINTS);
	glVertex3s(-5, 8, 12);
	glEnd();
	setColor(silver5);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(leftfront[i]);
		glEnd();
	};
	setColor(silver2);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftchine[i]);
		glEnd();
	};

	setColor(C_FRONTBUBBLE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(frontbubble[i]);
		glEnd();
	};
	setColor(C_PIT3);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit3[i]);
		glEnd();
	};
	setColor(C_PIT4);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit4[i]);
		glEnd();
	};
	setColor(C_PIT1);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit1[i]);
		glEnd();
	};
	setColor(C_PIT2);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit2[i]);
		glEnd();
	};

	setColor(C_UNDERBODY);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(botnose[i]);
		glEnd();
	};
	setColor(C_LEFTNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(rightnose[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(leftnose[i]);
		glEnd();
	};
	setColor(C_TOPNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(topnose[i]);
		glEnd();
	};
	// glEndList();

	// glNewList(obj++, GL_COMPILE);	/* above, right, front	*/
	setColor(silver0);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(leftelevator[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftwing[i]);
		glEnd();
	};
	glBegin(GL_LINE);
	glVertex3s(-20, 3, 4);
	glVertex3s(-20, 3, -5);
	glEnd();
	setColor(red);
	glBegin(GL_POINTS);
	glVertex3s(-19, 3, -1);
	glEnd();
	setColor(brown);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(frontback[i]);
		glEnd();
	};
	setColor(C_LEFTNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightback[i]);
		glEnd();
	};
	setColor(silver0);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(rightelevator[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightwing[i]);
		glEnd();
	};
	glBegin(GL_LINE);
	glVertex3s(20, 3, 4);
	glVertex3s(20, 3, -5);
	glEnd();
	setColor(green0);
	glBegin(GL_POINTS);
	glVertex3s(19, 3, -1);
	glEnd();

	setColor(C_TOPBACK);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(topback[i]);
		glEnd();
	};
	setColor(C_LEFTRUDDER);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftrudder[i]);
		glEnd();
	};
	setColor(white);
	glBegin(GL_POINTS);
	glVertex3s(-5, 8, 12);
	glEnd();
	setColor(silver2);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftchine[i]);
		glEnd();
	};
	setColor(C_TOPBUBBLE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(topbubble[i]);
		glEnd();
	};
	setColor(silver6);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(rightbubble[i]);
		glEnd();
	};

	setColor(C_RIGHTRUDDER);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightrudder[i]);
		glEnd();
	};
	setColor(red);
	glBegin(GL_POINTS);
	glVertex3s(5, 8, 12);
	glEnd();
	setColor(silver5);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(rightfront[i]);
		glEnd();
	};
	setColor(silver2);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightchine[i]);
		glEnd();
	};

	setColor(C_FRONTBUBBLE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(frontbubble[i]);
		glEnd();
	};
	setColor(C_PIT4);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit4[i]);
		glEnd();
	};
	setColor(C_PIT3);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit3[i]);
		glEnd();
	};
	setColor(C_PIT2);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit2[i]);
		glEnd();
	};
	setColor(C_PIT1);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit1[i]);
		glEnd();
	};

	setColor(C_UNDERBODY);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(botnose[i]);
		glEnd();
	};
	setColor(C_LEFTNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(leftnose[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(rightnose[i]);
		glEnd();
	};
	setColor(C_TOPNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(topnose[i]);
		glEnd();
	};
	// glEndList();

	// glNewList(obj++, GL_COMPILE);	/* below, left, behind	*/
	setColor(C_LEFTNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(leftnose[i]);
		glEnd();
	};
	setColor(C_PIT2);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit2[i]);
		glEnd();
	};
	setColor(C_PIT3);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit3[i]);
		glEnd();
	};
	setColor(C_PIT4);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit4[i]);
		glEnd();
	};

	setColor(C_UNDERWING);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightchine[i]);
		glEnd();
	};
	setColor(C_RIGHTRUDDER);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightrudder[i]);
		glEnd();
	};
	setColor(red);
	glBegin(GL_POINTS);
	glVertex3s(5, 8, 12);
	glEnd();
	setColor(C_TOPBUBBLE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(topbubble[i]);
		glEnd();
	};
	setColor(silver6);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(rightbubble[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(leftbubble[i]);
		glEnd();
	};

	setColor(silver5);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(leftfront[i]);
		glEnd();
	};
	setColor(C_UNDERWING);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftchine[i]);
		glEnd();
	};
	setColor(C_LEFTRUDDER);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftrudder[i]);
		glEnd();
	};
	setColor(white);
	glBegin(GL_POINTS);
	glVertex3s(-5, 8, 12);
	glEnd();

	setColor(C_UNDERWING);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(rightelevator[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightwing[i]);
		glEnd();
	};
	glBegin(GL_LINE);
	glVertex3s(20, 3, 4);
	glVertex3s(20, 3, -5);
	glEnd();
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftwing[i]);
		glEnd();
	};
	glBegin(GL_LINE);
	glVertex3s(-20, 3, 4);
	glVertex3s(-20, 3, -5);
	glEnd();
	setColor(green0);
	glBegin(GL_POINTS);
	glVertex3s(19, 3, -1);
	glEnd();
	setColor(red);
	glBegin(GL_POINTS);
	glVertex3s(-19, 3, -1);
	glEnd();

	setColor(C_LEFTNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftback[i]);
		glEnd();
	};
	setColor(C_UNDERWING);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(leftelevator[i]);
		glEnd();
	};

	setColor(C_UNDERBODY);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(botnose[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(bottomfront[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(bottomback[i]);
		glEnd();
	};
	setColor(brown);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(backback[i]);
		glEnd();
	};
	setColor(orange);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 6; i++)
			glVertex3fv(leftfire[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 6; i++)
			glVertex3fv(rightfire[i]);
		glEnd();
	};
	// glEndList();

	// glNewList(obj++, GL_COMPILE);	/* below, right, behind	*/
	setColor(C_LEFTNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(rightnose[i]);
		glEnd();
	};
	setColor(C_PIT1);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit1[i]);
		glEnd();
	};
	setColor(C_PIT4);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit4[i]);
		glEnd();
	};
	setColor(C_PIT3);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit3[i]);
		glEnd();
	};

	setColor(C_UNDERWING);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftchine[i]);
		glEnd();
	};
	setColor(C_LEFTRUDDER);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftrudder[i]);
		glEnd();
	};
	setColor(white);
	glBegin(GL_POINTS);
	glVertex3s(-5, 8, 12);
	glEnd();
	setColor(C_TOPBUBBLE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(topbubble[i]);
		glEnd();
	};
	setColor(silver6);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(leftbubble[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(rightbubble[i]);
		glEnd();
	};

	setColor(silver5);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(rightfront[i]);
		glEnd();
	};
	setColor(C_UNDERWING);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightchine[i]);
		glEnd();
	};
	setColor(C_RIGHTRUDDER);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightrudder[i]);
		glEnd();
	};
	setColor(red);
	glBegin(GL_POINTS);
	glVertex3s(5, 8, 12);
	glEnd();

	setColor(C_UNDERWING);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(leftelevator[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftwing[i]);
		glEnd();
	};
	glBegin(GL_LINE);
	glVertex3s(-20, 3, 4);
	glVertex3s(-20, 3, -5);
	glEnd();
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightwing[i]);
		glEnd();
	};
	glBegin(GL_LINE);
	glVertex3s(20, 3, 4);
	glVertex3s(20, 3, -5);
	glEnd();
	setColor(red);
	glBegin(GL_POINTS);
	glVertex3s(-19, 3, -1);
	glEnd();
	setColor(green0);
	glBegin(GL_POINTS);
	glVertex3s(19, 3, -1);
	glEnd();

	setColor(C_LEFTNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightback[i]);
		glEnd();
	};
	setColor(C_UNDERWING);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(rightelevator[i]);
		glEnd();
	};

	setColor(C_UNDERBODY);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(botnose[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(bottomfront[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(bottomback[i]);
		glEnd();
	};
	setColor(brown);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(backback[i]);
		glEnd();
	};
	setColor(orange);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 6; i++)
			glVertex3fv(leftfire[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 6; i++)
			glVertex3fv(rightfire[i]);
		glEnd();
	};
	// glEndList();

	// glNewList(obj++, GL_COMPILE);	/* above, left, behind	*/
	setColor(silver2);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightchine[i]);
		glEnd();
	};
	setColor(C_LEFTNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(leftnose[i]);
		glEnd();
	};
	setColor(C_TOPNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(topnose[i]);
		glEnd();
	};

	setColor(C_FRONTBUBBLE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(frontbubble[i]);
		glEnd();
	};
	setColor(C_PIT1);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit1[i]);
		glEnd();
	};
	setColor(C_PIT2);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit2[i]);
		glEnd();
	};
	setColor(C_PIT3);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit3[i]);
		glEnd();
	};
	setColor(C_PIT4);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit4[i]);
		glEnd();
	};

	setColor(silver5);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(leftfront[i]);
		glEnd();
	};
	setColor(silver2);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftchine[i]);
		glEnd();
	};

	setColor(silver0);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightwing[i]);
		glEnd();
	};
	glBegin(GL_LINE);
	glVertex3s(20, 3, 4);
	glEnd();
	glVertex3s(20, 3, -5);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(rightelevator[i]);
		glEnd();
	};
	setColor(green0);
	glBegin(GL_POINTS);
	glVertex3s(19, 3, -1);
	glEnd();

	setColor(C_LEFTNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftback[i]);
		glEnd();
	};
	setColor(silver0);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftwing[i]);
		glEnd();
	};
	glBegin(GL_LINE);
	glVertex3s(-20, 3, 4);
	glVertex3s(-20, 3, -5);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(leftelevator[i]);
		glEnd();
	};
	setColor(red);
	glBegin(GL_POINTS);
	glVertex3s(-19, 3, -1);
	glEnd();

	setColor(C_TOPBACK);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(topback[i]);
		glEnd();
	};
	setColor(C_RIGHTRUDDER);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightrudder[i]);
		glEnd();
	};
	setColor(red);
	glBegin(GL_POINTS);
	glVertex3s(5, 8, 12);
	glEnd();
	setColor(silver6);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(rightbubble[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(leftbubble[i]);
		glEnd();
	};
	setColor(C_TOPBUBBLE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(topbubble[i]);
		glEnd();
	};
	setColor(C_LEFTRUDDER);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftrudder[i]);
		glEnd();
	};
	setColor(white);
	glBegin(GL_POINTS);
	glVertex3s(-5, 8, 12);
	glEnd();

	setColor(brown);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(backback[i]);
		glEnd();
	};
	setColor(orange);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 6; i++)
			glVertex3fv(leftfire[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 6; i++)
			glVertex3fv(rightfire[i]);
		glEnd();
	};
	// glEndList();

	// glNewList(obj++, GL_COMPILE);	/* above, right, behind	*/
	setColor(silver2);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftchine[i]);
		glEnd();
	};
	setColor(C_LEFTNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(rightnose[i]);
		glEnd();
	};
	setColor(C_TOPNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(topnose[i]);
		glEnd();
	};

	setColor(C_FRONTBUBBLE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(frontbubble[i]);
		glEnd();
	};
	setColor(C_PIT2);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit2[i]);
		glEnd();
	};
	setColor(C_PIT1);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit1[i]);
		glEnd();
	};
	setColor(C_PIT4);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit4[i]);
		glEnd();
	};
	setColor(C_PIT3);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(pit3[i]);
		glEnd();
	};

	setColor(silver5);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(rightfront[i]);
		glEnd();
	};
	setColor(silver2);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightchine[i]);
		glEnd();
	};

	setColor(silver0);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftwing[i]);
		glEnd();
	};
	glBegin(GL_LINE);
	glVertex3s(-20, 3, 4);
	glVertex3s(-20, 3, -5);
	glEnd();
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(leftelevator[i]);
		glEnd();
	};
	setColor(red);
	glBegin(GL_POINTS);
	glVertex3s(-19, 3, -1);
	glEnd();

	setColor(C_LEFTNOSE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightback[i]);
		glEnd();
	};
	setColor(silver0);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightwing[i]);
		glEnd();
	};
	glBegin(GL_LINE);
	glVertex3s(20, 3, 4);
	glVertex3s(20, 3, -5);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(rightelevator[i]);
		glEnd();
	};
	setColor(green0);
	glBegin(GL_POINTS);
	glVertex3s(19, 3, -1);
	glEnd();

	setColor(C_TOPBACK);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(topback[i]);
		glEnd();
	};
	setColor(C_LEFTRUDDER);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(leftrudder[i]);
		glEnd();
	};
	setColor(white);
	glBegin(GL_POINTS);
	glVertex3s(-5, 8, 12);
	glEnd();
	setColor(silver6);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(rightbubble[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(leftbubble[i]);
		glEnd();
	};
	setColor(C_TOPBUBBLE);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 5; i++)
			glVertex3fv(topbubble[i]);
		glEnd();
	};
	setColor(C_RIGHTRUDDER);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(rightrudder[i]);
		glEnd();
	};
	setColor(red);
	glBegin(GL_POINTS);
	glVertex3s(5, 8, 12);
	glEnd();

	setColor(brown);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 4; i++)
			glVertex3fv(backback[i]);
		glEnd();
	};
	setColor(orange);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 6; i++)
			glVertex3fv(leftfire[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 6; i++)
			glVertex3fv(rightfire[i]);
		glEnd();
	};
	glEndList();

	glNewList(obj++, GL_COMPILE); /* real far away	*/
	setColor(silver4);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(fakewing[i]);
		glEnd();
	};
	setColor(silver7);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 3; i++)
			glVertex3fv(fakestab[i]);
		glEnd();
	};
	setColor(orange);
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 6; i++)
			glVertex3fv(leftfire[i]);
		glEnd();
	};
	{
		int i;
		glBegin(GL_POLYGON);
		for (i = 0; i < 6; i++)
			glVertex3fv(rightfire[i]);
		glEnd();
	};
	setColor(white);
	glBegin(GL_POINTS);
	glVertex3f(-5, 8, 12);
	glEnd();
	setColor(green0);
	glBegin(GL_POINTS);
	glVertex3s(19, 3, -1);
	glEnd();
	glEndList();




	
}
