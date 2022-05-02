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
/*	F-15 plane definition
/************************************************************/
static float fakewing[][3] = {
    {0,0,-41},
    {21,0,16},
    {-21,0,16},
};
static float fakestab[][3] = {
    {0,0,0},
    {0,14,16},
    {0,0,16}
};
static float rightfire[][3] = {
	{2		,1.5	,16.0},
	{3		,1.5	,16.0},
	{4.0	,2.5	,16.0},
	{3		,4		,16.0},
	{2		,4		,16.0},
    {1.0	,2.5	,16.0},
};
static float leftfire[][3] = {
    {-1.0	,2.5	,16.0},
    {-2		,4		,16.0},
    {-3		,4		,16.0},
    {-4.0	,2.5	,16.0},
    {-3		,1.5	,16.0},
    {-2		,1.5	,16.0},
};

static float rightwing[][3] = {
	{19,5,8},
	{21,5,2},
	{5,5,-11},
	{5,5,7},
};
static float leftwing[][3] = {
    {-5,5,7},
    {-5,5,-11},
    {-21,5,2},
    {-19,5,8},
};

static float brightwing[][3] = {
	{5,5,7},
	{5,5,-11},
	{21,5,2},
	{19,5,8},
};
static float bleftwing[][3] = {
	{-19,5,8},
	{-21,5,2},
	{-5,5,-11},
	{-5,5,7},
};

static float rightchine[][3] = {
	{7,5,-9},
	{7,5,-12},
	{5,5,-17},
	{5,5,-9},
};
static float leftchine[][3] = {
    {-5,5,-9},
    {-5,5,-17},
    {-7,5,-12},
    {-7,5,-9},
};
static float brightchine[][3] = {
	{5,5,-9},
	{5,5,-17},
	{7,5,-12},
	{7,5,-9},
};
static float bleftchine[][3] = {
	{-7,5,-9},
	{-7,5,-12},
	{-5,5,-17},
	{-5,5,-9},
};
static float rightinlet[][3] = {
	{2,5,-23},
	{2,5,-17},
	{5,5,-17},
	{5,5,-23},
};
static float brightinlet[][3] = {
	{5,5,-23},
	{5,5,-17},
	{2,5,-17},
	{2,5,-23},
};
static float leftinlet[][3] = {
	{-5,5,-23},
	{-5,5,-17},
	{-2,5,-17},
    {-2,5,-23},
};
static float bleftinlet[][3] = {
	{-2,5,-23},
	{-2,5,-17},
	{-5,5,-17},
	{-5,5,-23},
};

static float rightrudder[][3] = {
	{4.5,5,7},
	{4.5,14,14},
	{4.5,14,17},
	{4.5,5,16},
};
static float leftrudder[][3] = {
	{-4.5,5,16},
	{-4.5,14,17},
	{-4.5,14,14},
	{-4.5,5,7},
};

static float brightrudder[][3] = {
	{4.5,5,16},
	{4.5,14,17},
	{4.5,14,14},
    {4.5,5,7},
};
static float bleftrudder[][3] = {
    {-4.5,5,7},
    {-4.5,14,14},
    {-4.5,14,17},
    {-4.5,5,16},
};

static float rightelevator[][3] = {
	{5,2,20},
	{12,2,22},
	{13,2,18},
    {5,2,10},
};
static float brightelevator[][3] = {
	{5,2,10},
	{13,2,18},
	{12,2,22},
	{5,2,20},
};
static float leftelevator[][3] = {
    {-5,2,10},
    {-13,2,18},
    {-12,2,22},
    {-5,2,20},
};
static float bleftelevator[][3] = {
	{-5,2,20},
	{-12,2,22},
	{-13,2,18},
	{-5,2,10},
};

static float topback[][3] = {
	{-5,5,16},
	{5,5,16},
	{5,5,-17},
	{-5,5,-17},
};
static float rightback[][3] = {
    {5,5,-23},
    {5,5,16},
    {5,1,16},
    {5,1,-17},
};
static float leftback[][3] = {
	{-5,1,-17},
	{-5,1,16},
	{-5,5,16},
    {-5,5,-23},
};

static float brightback[][3] = {
	{5,1,-17},
	{5,1,16},
	{5,5,16},
	{5,5,-23},
};
static float bleftback[][3] = {
	{-5,5,-23},
	{-5,5,16},
	{-5,1,16},
	{-5,1,-17},
	
	
	
};

static float bottomback[][3] = {
    {-5,1,-17},
    {5,1,-17},
    {5,1,16},
    {-5,1,16},
};
static float backback[][3] = {
	{-5,1,16},
	{5,1,16},
	{5,5,16},
    {-5,5,16},
};
static float frontback[][3] = {
    {-5,5,-17},
    {5,5,-17},
    {5,1,-17},
    {-5,1,-17},
};

static float bottomfront[][3] = {
    {2,1,-34},
    {2,1,-17},
    {-2,1,-17},
    {-2,1,-34},
};
static float rightfront[][3] = {
	{2,4,-34},
	 {2,7,-17},
	 {2,1,-17},
    {2,1,-34},
};
static float leftfront[][3] = {
    {-2,1,-34},
    {-2,1,-17},
    {-2,7,-17},
    {-2,4,-34},
};
static float rightnose[][3] = {
	 {2,4,-34},
	  {2,1,-34},
    {0,2,-41},
};
static float leftnose[][3] = {
    {0,2,-41},
    {-2,1,-34},
    {-2,4,-34},
};
static float topnose[][3] = {
	{-2,4,-34},
	{2,4,-34},
    {0,2,-41},
};
static float botnose[][3] = {
    {0,2,-41},
    {2,1,-34},
    {-2,1,-34},
};
static float frontbubble[][3] = {
    {-2,4,-34},
    {-2,7,-17},
    {2,7,-17},
    {2,4,-34},
};
static float topbubble[][3] = {
    {-2,7,-17},
    {0,5,0},
    {2,7,-17},
};
static float rightbubble[][3] = {
    {2,7,-17},
    {0,5,0},
    {2,5,-17},
};
static float leftbubble[][3] = {
	 {-2,5,-17},
	 {0,5,0},
    {-2,7,-17},
};
static float pit1[][3] = {
	{0,8,-24},
	{1.8f,5.7648f,-24},
    {0,4.8825f,-29},
};
static float pit2[][3] = {
    {0,4.8825f,-29},
    {-1.8f,5.7648f,-24},
    {0,8,-24},
};
static float pit3[][3] = {
    {0,7,-17},
    {1.8f,5.7648f,-24},
    {0,8,-24},
};
static float pit4[][3] = {
	{0,8,-24},
	{-1.8f,5.7648f,-24},
    {0,7,-17},
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


void make_f15(GLuint obj) {

	glNewList(obj, GL_COMPILE);
	glEnable(GL_NORMALIZE);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	setColor(C_LEFTRUDDER);
	polf(4, rightrudder);
	setColor(C_RIGHTRUDDER);
	polf(4, brightrudder);
	glBegin(GL_LINE_STRIP);
	glVertex3f(4.5, 14.0, 12.5);
	glVertex3f(4.5, 14.0, 17.5);
	glEnd();

	setColor(red);
	pnt(4.5, 12.0, 17.0);

	setColor(C_LEFTRUDDER);
	polf(4, leftrudder);
	setColor(C_RIGHTRUDDER);
	polf(4, bleftrudder);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-4.5, 14.0, 12.5);
	glVertex3f(-4.5, 14.0, 17.5);
	glEnd();

	setColor(white);
	pnt(-4.5, 12.0, 17.0);


	setColor(silver4);
	polf(4, topback);

	setColor(C_LEFTNOSE);
	polf(4, leftback);
	setColor(C_UNDERWING);
	polf(4, bleftback);
	setColor(C_LEFTNOSE);
	polf(4, rightback);
	setColor(C_UNDERWING);
	polf(4, brightback);

	setColor(brown);
	polf(4, frontback);

	setColor(C_FRONTBUBBLE);
	polf(4, frontbubble);
	setColor(C_TOPBUBBLE);
	polf(3, topbubble);
	setColor(silver6);
	polf(3, leftbubble);
	setColor(silver6);
	polf(3, rightbubble);


	setColor(C_PIT1);
	polf(3, pit1);
	setColor(C_PIT2);
	polf(3, pit2);
	setColor(C_PIT3);
	polf(3, pit3);
	setColor(C_PIT4);
	polf(3, pit4);

	setColor(C_LEFTNOSE);
	polf(4, leftfront);
	setColor(C_LEFTNOSE);
	polf(4, rightfront);

	setColor(silver4);
	polf(4, leftwing);
	polf(4, leftchine);
	polf(4, leftinlet);
	setColor(silver5);
	polf(4, leftelevator);
	setColor(C_UNDERWING);
	polf(4, bleftwing);
	polf(4, bleftchine);
	polf(4, bleftinlet);
	polf(4, bleftelevator);
	setColor(red);
	pnts(-20, 5, 1);


	setColor(silver4);
	polf(4, rightwing);
	polf(4, rightchine);
	polf(4, rightinlet);
	setColor(silver5);
	polf(4, rightelevator);
	setColor(C_UNDERWING);
	polf(4, brightelevator);
	polf(4, brightwing);
	polf(4, brightchine);
	polf(4, brightinlet);
	setColor(green0);
	pnts(20, 5, 1);

	
	
	setColor(C_TOPNOSE);
	polf(3, topnose);
	setColor(C_LEFTNOSE);
	polf(3, leftnose);
	polf(3, rightnose);


	setColor(C_UNDERWING);
	polf(4, bottomback);
	polf(4, bottomfront);
	polf(3, botnose);




	setColor(brown);
	polf(4, backback);
	setColor(orange);
	polf(6, leftfire);
	polf(6, rightfire);

	glDisable(GL_CULL_FACE);
	glDisable(GL_NORMALIZE);
	glEndList();

	/* shadow	*/
	makeobj(obj+9);		
	setColor(black);
	setpattern(3);
	polf(4, rightwing);
	polf(4, leftwing);
	polf(4, rightelevator);
	polf(4, leftelevator);
	polf(4, rightrudder);
	polf(4, leftrudder);

	polf(4, rightback);
	polf(4, leftback);
	polf(4, topback);

	polf(4, rightfront);
	polf(4, leftfront);
	polf(4, frontbubble);

	polf(3, rightnose);
	polf(3, leftnose);
	polf(3, topnose);
	setpattern(0);
	closeobj();


	/* shadow far away	*/
	makeobj(obj + 100);		
	setColor(black);
	setpattern(3);
	polf(3, fakestab);
	polf(3, fakewing);
	setpattern(0);
	closeobj();
}
void make_f15_old (GLuint obj) {
    makeobj (obj++);	/* below, left, front	*/
	setColor(C_LEFTNOSE);
	polf (4,rightback);
	setColor(C_RIGHTRUDDER);
	polf (4,rightrudder);
	glBegin(GL_LINE_STRIP);
	glVertex3f (4.5,14.0,12.5);
	glVertex3f (4.5,14.0,17.5);
	glEnd();
	setColor(red);
	pnt (4.5,12.0,17.0);
	setColor(silver6);
	polf (3,leftbubble);
	setColor(C_LEFTRUDDER);
	polf (4,leftrudder);
	glBegin(GL_LINE_STRIP);
	glVertex3f (-4.5,14.0,12.5);
	glVertex3f (-4.5,14.0,17.5);
	glEnd();
	setColor(white);
	pnt (-4.5,12.0,17.0);

	setColor(C_UNDERWING);
	polf (4,rightelevator);
	polf (4,rightwing);
 	polf (4,rightchine);
 	polf (4,rightinlet);
	setColor(green0);
	pnts (20,5,1);
	setColor(brown);
	polf (4,frontback);
    
	setColor(C_FRONTBUBBLE);
	polf (4,frontbubble);
	setColor(C_PIT4);
	polf (3,pit4);
	setColor(C_PIT1);
	polf (3,pit1);
	setColor(C_PIT2);
	polf (3,pit2);
	setColor(silver5);
	polf (4,leftfront);

	setColor(C_UNDERWING);
	polf (4,leftwing);
 	polf (4,leftchine);
 	polf (4,leftinlet);
	setColor(red);
	pnts (-20,5,1);

	setColor(C_LEFTNOSE);
	polf (4,leftback);
	polf (3,rightnose);
	setColor(C_TOPNOSE);
	polf (3,topnose);
	setColor(C_LEFTNOSE);
	polf (3,leftnose);

	setColor(C_UNDERWING);
	polf (4,leftelevator);
	setColor(C_UNDERBODY);
	polf (4,bottomback);
	polf (4,bottomfront);
	polf (3,botnose);
    closeobj ();

    makeobj (obj++);	/* below, right, front	*/
	setColor(C_LEFTNOSE);
	polf (4,leftback);
	setColor(C_LEFTRUDDER);
	polf (4,leftrudder);
	glBegin(GL_LINE);
	glVertex3f(-4.5,14.0,12.5);
	glVertex3f(-4.5,14.0,17.5);
	glEnd();
	setColor(white);
	pnt (-4.5,12.0,17.0);
	setColor(silver6);
	polf (3,rightbubble);
	setColor(C_RIGHTRUDDER);
	polf (4,rightrudder);
	glBegin(GL_LINE);
	glVertex3f(4.5,14.0,12.5);
	glVertex3f(4.5,14.0,17.5);
	glEnd();
	setColor(red);
	pnt (4.5,12.0,17.0);

	setColor(C_UNDERWING);
	polf (4,leftelevator);
	polf (4,leftwing);
 	polf (4,leftchine);
 	polf (4,leftinlet);
	setColor(red);
	pnts (-20,5,1);
	setColor(brown);
	polf (4,frontback);

	setColor(C_FRONTBUBBLE);
	polf (4,frontbubble);
	setColor(C_PIT3);
	polf (3,pit3);
	setColor(C_PIT2);
	polf (3,pit2);
	setColor(C_PIT1);
	polf (3,pit1);
	setColor(silver5);
	polf (4,rightfront);

	setColor(C_UNDERWING);
	polf (4,rightwing);
 	polf (4,rightchine);
 	polf (4,rightinlet);
	setColor(green0);
	pnts (20,5,1);

	setColor(C_LEFTNOSE);
	polf (4,rightback);
	polf (3,leftnose);
	setColor(C_TOPNOSE);
	polf (3,topnose);
	setColor(C_LEFTNOSE);
	polf (3,rightnose);

	setColor(C_UNDERWING);
	polf (4,rightelevator);
	setColor(C_UNDERBODY);
	polf (4,bottomback);
	polf (4,bottomfront);
	polf (3,botnose);
    closeobj ();

    makeobj (obj++);	/* above, left, front	*/
	setColor(C_LEFTNOSE);
	polf (4,rightback);
	setColor(silver0);
	polf (4,rightelevator);
	polf (4,rightwing);
 	polf (4,rightchine);
	setColor(green0);
	pnts (20,5,1);
	setColor(brown);
	polf (4,frontback);
	setColor(C_TOPBACK);
 	polf (4,rightinlet);
	polf (4,topback);
	setColor(C_RIGHTRUDDER);
	polf (4,rightrudder);
	glBegin(GL_LINE);
	    glVertex3f (4.5,14.0,12.5);
	    glVertex3f (4.5,14.0,17.5);
		glEnd();
	    setColor(red);
	    pnt (4.5,12.0,17.0);
	setColor(C_TOPBUBBLE);
	polf (3,topbubble);
	setColor(silver6);
	polf (3,leftbubble);

	setColor(silver5);
	polf (4,leftfront);
	setColor(C_LEFTNOSE);
	polf (4,leftback);
	setColor(C_TOPBACK);
 	polf (4,leftinlet);
	setColor(silver0);
	polf (4,leftelevator);
	polf (4,leftwing);
 	polf (4,leftchine);
	setColor(red);
	pnts (-20,5,1);

	setColor(C_LEFTRUDDER);
	polf (4,leftrudder);
	glBegin(GL_LINE);
	    glVertex3f (-4.5,14.0,12.5);
	    glVertex3f (-4.5,14.0,17.5);
		glEnd();
	    setColor(white);
	    pnt (-4.5,12.0,17.0);

	setColor(C_FRONTBUBBLE);
	polf (4,frontbubble);
	setColor(C_PIT3);
	polf (3,pit3);
	setColor(C_PIT4);
	polf (3,pit4);
	setColor(C_PIT1);
	polf (3,pit1);
	setColor(C_PIT2);
	polf (3,pit2);

	setColor(C_UNDERBODY);
	polf (3,botnose);
	setColor(C_LEFTNOSE);
	polf (3,rightnose);
	polf (3,leftnose);
	setColor(C_TOPNOSE);
	polf (3,topnose);
    closeobj ();

    makeobj (obj++);	/* above, right, front	*/
	setColor(C_LEFTNOSE);
	polf (4,leftback);
	setColor(silver0);
	polf (4,leftelevator);
	polf (4,leftwing);
 	polf (4,leftchine);
	setColor(red);
	pnts (-20,5,1);
	setColor(brown);
	polf (4,frontback);
	setColor(C_TOPBACK);
	polf (4,topback);
 	polf (4,leftinlet);
	setColor(C_LEFTRUDDER);
	polf (4,leftrudder);
	glBegin(GL_LINE);
	    glVertex3f (-4.5,14.0,12.5);
	    glVertex3f (-4.5,14.0,17.5);
		glEnd();
	    setColor(white);
	    pnt (-4.5,12.0,17.0);
	setColor(C_TOPBUBBLE);
	polf (3,topbubble);
	setColor(silver6);
	polf (3,rightbubble);

	setColor(silver5);
	polf (4,rightfront);
	setColor(C_LEFTNOSE);
	polf (4,rightback);
	setColor(C_TOPBACK);
 	polf (4,rightinlet);
	setColor(silver0);
	polf (4,rightelevator);
	polf (4,rightwing);
 	polf (4,rightchine);
	setColor(green0);
	pnts (20,5,1);

	setColor(C_RIGHTRUDDER);
	polf (4,rightrudder);
	glBegin(GL_LINE);
	    glVertex3f (4.5,14.0,12.5);
	    glVertex3f (4.5,14.0,17.5);
		glEnd();
	    setColor(red);
	    pnt (4.5,12.0,17.0);

	setColor(C_FRONTBUBBLE);
	polf (4,frontbubble);
	setColor(C_PIT4);
	polf (3,pit4);
	setColor(C_PIT3);
	polf (3,pit3);
	setColor(C_PIT2);
	polf (3,pit2);
	setColor(C_PIT1);
	polf (3,pit1);

	setColor(C_UNDERBODY);
	polf (3,botnose);
	setColor(C_LEFTNOSE);
	polf (3,leftnose);
	polf (3,rightnose);
	setColor(C_TOPNOSE);
	polf (3,topnose);
    closeobj ();

    makeobj (obj++);	/* below, left, behind	*/
	setColor(C_UNDERWING);
 	polf (4,rightinlet);
	setColor(C_LEFTNOSE);
 	polf (4,rightback);
	polf (3,leftnose);
	setColor(C_PIT2);
	polf (3,pit2);
	setColor(C_PIT3);
	polf (3,pit3);
	setColor(C_PIT4);
	polf (3,pit4);

	setColor(C_RIGHTRUDDER);
	polf (4,rightrudder);
	glBegin(GL_LINE);
	    glVertex3f (4.5,14.0,12.5);
	    glVertex3f (4.5,14.0,17.5);
		glEnd();
	    setColor(red);
	    pnt (4.5,12.0,17.0);
	setColor(C_TOPBUBBLE);
	polf (3,topbubble);
	setColor(silver6);
	polf (3,rightbubble);
	polf (3,leftbubble);

	setColor(silver5);
	polf (4,leftfront);
	setColor(C_LEFTRUDDER);
	polf (4,leftrudder);
	glBegin(GL_LINE);
	    glVertex3f (-4.5,14.0,12.5);
	    glVertex3f (-4.5,14.0,17.5);
		glEnd();
	    setColor(white);
	    pnt (-4.5,12.0,17.0);

	setColor(C_UNDERWING);
	polf (4,rightelevator);
	polf (4,rightwing);
 	polf (4,rightchine);
 	polf (4,leftinlet);
	polf (4,leftwing);
 	polf (4,leftchine);
	setColor(green0);
	pnts (20,5,1);
	setColor(red);
	pnts (-20,5,1);

	setColor(C_LEFTNOSE);
	polf (4,leftback);

	setColor(C_UNDERBODY);
	polf (3,botnose);
	polf (4,bottomfront);
	polf (4,bottomback);
	setColor(brown);
	polf (4,backback);
	setColor(orange);
	polf (6,leftfire);
	polf (6,rightfire);

	setColor(C_UNDERWING);
	polf (4,leftelevator);
    closeobj ();

    makeobj (obj++);	/* below, right, behind	*/
	setColor(C_UNDERWING);
 	polf (4,leftinlet);
	setColor(C_LEFTNOSE);
	polf (4,leftback);
	polf (3,rightnose);
	setColor(C_PIT1);
	polf (3,pit1);
	setColor(C_PIT4);
	polf (3,pit4);
	setColor(C_PIT3);
	polf (3,pit3);

	setColor(C_LEFTRUDDER);
	polf (4,leftrudder);
	glBegin(GL_LINE);
	    glVertex3f (-4.5,14.0,12.5);
	    glVertex3f (-4.5,14.0,17.5);
		glEnd();
	    setColor(white);
	    pnt (-4.5,12.0,17.0);
	setColor(C_TOPBUBBLE);
	polf (3,topbubble);
	setColor(silver6);
	polf (3,leftbubble);
	polf (3,rightbubble);

	setColor(silver5);
	polf (4,rightfront);
	setColor(C_RIGHTRUDDER);
	polf (4,rightrudder);
	glBegin(GL_LINE);
	    glVertex3f (4.5,14.0,12.5);
	    glVertex3f (4.5,14.0,17.5);
		glEnd();
	    setColor(red);
	    pnt (4.5,12.0,17.0);

	setColor(C_UNDERWING);
 	polf (4,leftchine);
	polf (4,leftelevator);
	polf (4,leftwing);
 	polf (4,rightinlet);
	polf (4,rightwing);
 	polf (4,rightchine);
	setColor(red);
	pnts (-20,5,1);
	setColor(green0);
	pnts (20,5,1);

	setColor(C_LEFTNOSE);
	polf (4,rightback);

	setColor(C_UNDERBODY);
	polf (3,botnose);
	polf (4,bottomfront);
	polf (4,bottomback);
	setColor(brown);
	polf (4,backback);
	setColor(orange);
	polf (6,leftfire);
	polf (6,rightfire);

	setColor(C_UNDERWING);
	polf (4,rightelevator);
    closeobj ();

    makeobj (obj++);	/* above, left, behind	*/
	setColor(C_LEFTNOSE);
	polf (3,leftnose);
	setColor(C_TOPNOSE);
	polf (3,topnose);
	setColor(C_TOPBACK);
 	polf (4,rightinlet);

	setColor(C_FRONTBUBBLE);
	polf (4,frontbubble);
	setColor(C_PIT1);
	polf (3,pit1);
	setColor(C_PIT2);
	polf (3,pit2);
	setColor(C_PIT3);
	polf (3,pit3);
	setColor(C_PIT4);
	polf (3,pit4);

	setColor(silver5);
	polf (4,leftfront);

	setColor(silver0);
 	polf (4,rightchine);
	polf (4,rightwing);
	polf (4,rightelevator);
	setColor(green0);
	pnts (20,5,1);

	setColor(brown);
	polf (4,backback);
	setColor(orange);
	polf (6,leftfire);
	polf (6,rightfire);
    
	setColor(C_LEFTNOSE);
	polf (4,leftback);
	setColor(silver0);
 	polf (4,leftchine);
	polf (4,leftwing);
	polf (4,leftelevator);
	setColor(red);
	pnts (-20,5,1);

	setColor(C_TOPBACK);
 	polf (4,leftinlet);
	polf (4,topback);
	setColor(C_RIGHTRUDDER);
	polf (4,rightrudder);
	glBegin(GL_LINE);
	    glVertex3f (4.5,14.0,12.5);
	    glVertex3f (4.5,14.0,17.5);
		glEnd();
	    setColor(red);
	    pnt (4.5,12.0,17.0);
	setColor(silver6);
	polf (3,rightbubble);
	polf (3,leftbubble);
	setColor(C_TOPBUBBLE);
	polf (3,topbubble);
	setColor(C_LEFTRUDDER);
	polf (4,leftrudder);
	glBegin(GL_LINE);
	    glVertex3f (-4.5,14.0,12.5);
	    glVertex3f (-4.5,14.0,17.5);
		glEnd();
	    setColor(white);
	    pnt (-4.5,12.0,17.0);
    closeobj ();

    makeobj (obj++);	/* above, right, behind	*/
	setColor(C_LEFTNOSE);
	polf (3,rightnose);
	setColor(C_TOPNOSE);
	polf (3,topnose);
	setColor(C_TOPBACK);
 	polf (4,leftinlet);

	setColor(C_FRONTBUBBLE);
	polf (4,frontbubble);
	setColor(C_PIT2);
	polf (3,pit2);
	setColor(C_PIT1);
	polf (3,pit1);
	setColor(C_PIT4);
	polf (3,pit4);
	setColor(C_PIT3);
	polf (3,pit3);

	setColor(silver5);
	polf (4,rightfront);

	setColor(silver0);
 	polf (4,leftchine);
	polf (4,leftwing);
	polf (4,leftelevator);
	setColor(red);
	pnts (-20,5,1);

	setColor(brown);
	polf (4,backback);
	setColor(orange);
	polf (6,leftfire);
	polf (6,rightfire);

	setColor(C_LEFTNOSE);
	polf (4,rightback);
	setColor(silver0);
 	polf (4,rightchine);
	polf (4,rightwing);
	polf (4,rightelevator);
	setColor(green0);
	pnts (20,5,1);

	setColor(C_TOPBACK);
 	polf (4,rightinlet);
	polf (4,topback);
	setColor(C_LEFTRUDDER);
	polf (4,leftrudder);
	glBegin(GL_LINE);
	    glVertex3f (-4.5,14.0,12.5);
	    glVertex3f (-4.5,14.0,17.5);
		glEnd();
	    setColor(white);
	    pnt (-4.5,12.0,17.0);
	setColor(silver6);
	polf (3,rightbubble);
	polf (3,leftbubble);
	setColor(C_TOPBUBBLE);
	polf (3,topbubble);
	setColor(C_RIGHTRUDDER);
	polf (4,rightrudder);
	glBegin(GL_LINE);
	    glVertex3f (4.5,14.0,12.5);
	    glVertex3f (4.5,14.0,17.5);
		glEnd();
	    setColor(red);
	    pnt (4.5,12.0,17.0);
    closeobj ();

    makeobj (obj++);		/* real far away	*/
	setColor(silver4);
	polf (3,fakewing);
	setColor(silver7);
	polf (3,fakestab);
	setColor(orange);
	polf (6,leftfire);
	polf (6,rightfire);

	setColor(green0);
	pnts (20,5,1);
	setColor(white);
	pnt (-4.5,12.0,17.0);
    closeobj ();

    makeobj (obj++);		/* shadow	*/
	setColor(black);
	//setpattern(3);
	polf (4,rightwing);
	polf (4,leftwing);
	polf (4,rightelevator);
	polf (4,leftelevator);
	polf (4,rightrudder);
	polf (4,leftrudder);

	polf (4,rightback);
	polf (4,leftback);
	polf (4,topback);

	polf (4,rightfront);
	polf (4,leftfront);
	polf (4,frontbubble);

	polf (3,rightnose);
	polf (3,leftnose);
	polf (3,topnose);
	//setpattern(0);
    closeobj ();

    makeobj (obj+100);		/* shadow far away	*/
	setColor(black);
	//setpattern(3);
	polf (3,fakestab);
	polf (3,fakewing);
	//setpattern(0);
    closeobj ();
}
