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

#include "meters.h"
#include <stdio.h>

#pragma warning(disable : 4996)
 /*
  *  because flight was originally written for a screen with resolution
  *  of 1024 in X and 768 in Y we must use an adjust ment factor
  */

extern short wm_allplanes;


/* make objects for drawing meters	*/
void make_meters()
{
	int i;

	static GLuint crash_pattern[16] = {
	0x0007,0x000e,0x001c,0x0038,
	0x0070,0x00e0,0x01c0,0x0380,
	0x0700,0x0e00,0x1c00,0x3800,
	0x7000,0xe000,0xc001,0x8003,
	};

	//PATTERN_16
	//glNewList(1, GL_COMPILE);
	//glPolygonStipple(crash_pattern);
	//glEndList();


	glNewList(METER_OVERLAY, GL_COMPILE);
	setColor(orange);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRecti(0, 0, 50, 200);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	for (i = 20; i < 200; i += 20) {
		glBegin(GL_LINE_STRIP);
		glVertex2s(0, i);
		glVertex2s(15, i);
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2s(35, i);
		glVertex2s(50, i);
		glEnd();
	}
	glEndList();

	create_g_metter();
	create_heading();
}

#define OLD_XMIDDLE 512

void genbar(int x, int y)
{
	glBegin(GL_LINE_STRIP);
	glVertex2s(-x, -y);
	glVertex2s(x, -y);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2s(-x, y);
	glVertex2s(x, y);
	glEnd();
}

void text_meter() {
	setColor(orange);
	gl_print("2", 20, 34);
	gl_print("4", 20, 74);
	gl_print("6", 20, 114);
	gl_print("8", 20, 154);
}

void bar_meter(float x, float y, int val) {
	glTranslatef(x, y, 0.0);
	setColor(brown);
	glRects(0, 0, 50, 200);
	draw_meter(0, val);
	text_meter();
	glCallList(METER_OVERLAY);
}

void display_meters(plane *pp) {
#define OLD_XMIDDLE 512
	static GLshort gy_triangle[][2] = {
		{0,200},
		{8,208},
		{8,192},
	};
	static GLshort triangle[3][2] = {
		{OLD_XMIDDLE + 1,302},
		{OLD_XMIDDLE + 9,310},
		{OLD_XMIDDLE - 7,310}
	};
	static GLshort triangle1[3][2] = {
		{HEADING_CX + 1,302},
		{HEADING_CX + 9,310},
		{HEADING_CX - 7,310}
	};
	char charbuff[255];

	glPushMatrix();
	glLoadIdentity();


	bar_meter((float)THRUST_LLX, (float)METER_LLY, pp->thrust);
	bar_meter((float)(SPEED_LLX - THRUST_LLX), 0.0f, pp->airspeed / 10);
	bar_meter((float)(CLIMB_LLX - SPEED_LLX), 0.0f, (pp->climbspeed >> 1) + (pp->climbspeed >> 3));
	bar_meter((float)(FUEL_LLX - CLIMB_LLX), 0.0f, pp->fuel >> 7);

	glPopMatrix();
	gl_print("Thrust", THRUST_LLX, METER_LLY - 20);
	gl_print("Speed", SPEED_LLX, METER_LLY - 20);
	gl_print("knots", SPEED_LLX, METER_LLY - 36);
	gl_print("Climb", CLIMB_LLX, METER_LLY - 20);
	gl_print(" fpm", CLIMB_LLX, METER_LLY - 36);
	gl_print("G-force", CLIMB_LLX + 70, METER_LLY - 20);
	gl_print("Horizon", 512 - 30, METER_LLY - 20);
	gl_print("Heading", HEADING_CX - 30, METER_LLY - 20);
	gl_print("Fuel", FUEL_LLX + 8, METER_LLY - 20);

	/* meter center marks	*/
	polf2s(3, triangle);
	polf2s(3, triangle1);

	sprintf(charbuff, "Flaps: %2d degrees", pp->flaps);
	gl_print(charbuff, 100, 310);

	sprintf(charbuff, "Spoilers: %d degrees", pp->spoilers);
	gl_print(charbuff, 280, 310);

	sprintf(charbuff, "Altitude: %d", (int)pp->y);
	gl_print(charbuff, 612, 330);

	gl_print(pp->plane_type, 612, 310);

	if (pp->wheels) {
		gl_print("LANDING GEAR DOWN", 100, 330);
	}



	// G-METER
	glCallList(OBJ_G_METER);

	glPushMatrix();
	glLoadIdentity();
	glTranslatef(366.0, -100.0 / 8.0 / pp->gravity * pp->lift, 0.0);
	polf2s(3, gy_triangle);
	glPopMatrix();
}
void display_heading(plane *pp, float X_ADJUST, float Y_ADJUST) {
	/* set up heading meter	*/
	glEnable(GL_SCISSOR_TEST);
	glTranslatef((float)HEADING_CX, 200.0, 0.0);

	glScissor((int)((HEADING_CX - 102) * X_ADJUST + 0.1), (int)(90.0f * Y_ADJUST + 0.1), 208.0f*X_ADJUST, 220.0f*Y_ADJUST);

	setColor(black);
	circfs(0.0f, 0.0f, 102.0);


	/* draw plane		*/
	setColor(orange);

	glBegin(GL_LINE_STRIP);
	glVertex2s(0, 0);
	glVertex2s(2, -10);
	glVertex2s(12, -18);
	glVertex2s(12, -20);
	glVertex2s(2, -14);
	glVertex2s(2, -20);
	glVertex2s(5, -23);
	glVertex2s(-5, -23);
	glVertex2s(-2, -20);
	glVertex2s(-2, -14);
	glVertex2s(-12, -20);
	glVertex2s(-12, -18);
	glVertex2s(-2, -10);
	glVertex2s(0, 0);
	glEnd();


	glRotatef(-pp->azimuthf * 0.1, 0, 0, 1);
	glCallList(OBJ_HEADING_METER);


	//glCallList(RADAR);
	/* scale down (y=-z)	*/
	glScalef(.004, -.004, .004);
	setColor(purple0);
	glTranslatef(-pp->x, -pp->z, 0.0);
	/* the runway	*/
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -8500.0);
	glEnd();
	glLineWidth(1);
	glDisable(GL_SCISSOR_TEST);
}

void display_artificial_horizon(plane *pp, float X_ADJUST, float Y_ADJUST) {
	char charbuff[255];
	// Artifitial Horizon

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport((int)(412 * X_ADJUST + 0.1), (int)(METER_VLLY * Y_ADJUST + 0.1), ((int)(612 * X_ADJUST + 0.1)) - ((int)(412 * X_ADJUST + 0.1)) + 1, ((int)(METER_VURY * Y_ADJUST + 0.1)) - ((int)(METER_VLLY * Y_ADJUST + 0.1)) + 1);
	glScissor((int)(412 * X_ADJUST + 0.1), (int)(METER_VLLY * Y_ADJUST + 0.1), ((int)(612 * X_ADJUST + 0.1)) - ((int)(412 * X_ADJUST + 0.1)) + 1, ((int)(METER_VURY * Y_ADJUST + 0.1)) - ((int)(METER_VLLY * Y_ADJUST + 0.1)) + 1);
	gluOrtho2D(-90.0, 90.0, -90.0, 90.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	setColor(brown);
	glRects(-90, -90, 90, 90);
	setColor(blue);
	glPushMatrix();
	glRotatef(-pp->twist * 0.1, 0, 0, 1);
	glTranslatef(0.0f, -.1 * pp->elevationf, 0.0f);
	glRects(-150, 0, 150, 500);
	setColor(white);
	glBegin(GL_LINE_STRIP);
	glVertex2s(-30, 0);
	glVertex2s(30, 0);
	glEnd();
	genbar(30, 80);
	genbar(10, 60);
	genbar(15, 40);
	genbar(10, 20);
	glPopMatrix();


	setColor(orange);
	glRects(-66, -2, -30, 0);		/* W	*/
	glRects(66, -2, 30, 0);
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
	glVertex2s(33, -6);
	glVertex2s(20, -20);
	glVertex2s(0, 0);
	glVertex2s(-20, -20);
	glVertex2s(-33, -6);
	glLineWidth(1);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2s(-60, -90);
	glVertex2s(-60, -83);	/* yaw lines	*/
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2s(-30, -90);
	glVertex2s(-30, -86);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2s(0, -90);
	glVertex2s(0, -83);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2s(30, -90);
	glVertex2s(30, -86);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2s(60, -90);
	glVertex2s(60, -83);
	glEnd();

	setColor(orange);
	sprintf(charbuff, "%d", pp->airspeed);
	gl_print(charbuff, -80, -55);

	sprintf(charbuff, "%.2f", pp->mach);
	gl_print(charbuff, -80, -70);


	sprintf(charbuff, "g %.2f", pp->lift / pp->gravity);
	gl_print(charbuff, -80, 55);

	sprintf(charbuff, "%.0f", pp->azimuthf * .1);
	gl_print(charbuff, 65, 55);

	sprintf(charbuff, "%.0f", pp->y);
	gl_print(charbuff, 45, -70);

	if (pp->g_limit) {
		setColor(white);
		gl_print("G-LIMIT", -24, 4);
	}

	if (pp->wing_stall) {
		setColor(white);
		gl_print("WING-STALL", -32, 4);
	}
	change_rudder(pp->rudder);
	glLoadIdentity();
	draw_blanking();
	setColor(orange);
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
	glVertex2s(-90, -90);
	glVertex2s(90, -90);
	glVertex2s(90, 90);
	glVertex2s(-90, 90);
	glVertex2s(-90, -90);

	glEnd();
}
/************************************************************
/*	Trash procedures
/************************************************************/
void draw_blanking()
{
	static GLshort blanking1[][2] = { {90,90}, {70,90}, {90,70} };
	static GLshort blanking2[][2] = { {-90,90}, {-90,70}, {-70,90} };
	static GLshort blanking3[][2] = { {-90,-90}, {-70,-90}, {-90,-70} };
	static GLshort blanking4[][2] = { {90,-90}, {90,-70}, {70,-90} };

	setColor(black);				/* remove borders	*/

	polf2s(3, blanking4);
	polf2s(3, blanking3);
	polf2s(3, blanking2);
	polf2s(3, blanking1);
	/*
	setColor(tan0);
	polf2s(3, blanking2);
	setColor(blue);
	polf2s(3, blanking3);
	setColor(tan0);
	polf2s(3, blanking4);
	*/
}

void draw_meter(int llx, int val) {
	if (val >= 0) {
		setColor(blue);
		if (val > 100) {
			val = 100;
		}
		glRects(llx, METER_LLY-100, llx + 50, METER_LLY-100 + (val << 1));
	}
	else {
		setColor(red);
		if (val < -100) {
			val = -100;
		}
		glRects(llx, METER_LLY - 100, llx + 50, METER_LLY - 100 - (val << 1));
	}
}

void change_rudder(float rudder) {
	static GLshort yaw_indicator[][2] = { {0,-85},{-4,-81},{4,-81} };
	/* map .8 => 60	*/
	glTranslatef(rudder * 75.0f, 0.0f, 0.0f); 
	polf2s(3, yaw_indicator);
}


void create_g_metter() {
	glNewList(OBJ_G_METER, GL_COMPILE);

	setColor(orange);
	/* Y	*/
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRects(350, 97, 364, 103);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	setColor(orange);
	glBegin(GL_LINE_STRIP);
	glVertex2s(350, 125);
	glVertex2s(356, 125);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRects(350, 147, 356, 153);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glBegin(GL_LINE_STRIP);
	glVertex2s(350, 175);
	glVertex2s(356, 175);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRects(350, 197, 364, 203);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glBegin(GL_LINE_STRIP);
	glVertex2s(350, 225);
	glVertex2s(356, 225);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRects(350, 247, 356, 253);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_LINE_STRIP);
	glVertex2s(350, 275);
	glVertex2s(356, 275);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRects(350, 297, 364, 303);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	gl_print("8", 330, 96);
	gl_print("6", 330, 121);
	gl_print("4", 330, 146);
	gl_print("2", 330, 171);
	gl_print("0", 330, 196);
	gl_print("2", 330, 221);
	gl_print("4", 330, 246);
	gl_print("6", 330, 271);
	gl_print("8", 330, 296);

	glEndList();
}

void create_heading() {
	glNewList(OBJ_HEADING_METER,GL_COMPILE);
	setColor(white);
	float sin, cos, r;
	for (int i = 0; i < 3600; i += 100) {
		gl_sincos((float) i, &sin, &cos);
		glBegin(GL_LINE_STRIP);
		glVertex2f(100.0f * sin, 100.0f * cos);
		if (i == 300 || i == 600 || i == 1200 || i == 1500 ||
			i == 2100 || i == 2400 || i == 3000 || i == 3300) {
			r = 75.0;	/* long line	*/
		}
		else {
			r = 90.0;	/* short line	*/
		}
		glVertex2f(r * sin, r * cos);
		glEnd();
	}
	glBegin(GL_LINE_STRIP);
	glVertex2s(-7, 60);		/* N	*/
	glVertex2s(-7, 80);
	glVertex2s(7, 60);
	glVertex2s(7, 80);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2s(60, -7);		/* E	*/
	glVertex2s(60, 7);
	glVertex2s(80, 7);
	glVertex2s(80, -7);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2s(70, 7);
	glVertex2s(70, -3);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2s(-80, -9);	/* W	*/
	glVertex2s(-60, -4);
	glVertex2s(-70, 0);
	glVertex2s(-60, 4);
	glVertex2s(-80, 9);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2s(-7, -78);	/* S	*/
	glVertex2s(-5, -80);
	glVertex2s(7, -80);
	glVertex2s(7, -70);
	glVertex2s(-7, -70);
	glVertex2s(-7, -60);
	glVertex2s(5, -60);
	glVertex2s(7, -62);
	glEnd();
	glEndList();
}

void draw_cockpit(plane *pp, GLubyte *halftone, int sc_width, int sc_height, float X_ADJUST, float Y_ADJUST) {

	if (glIsList(COCKPIT)) {
		glDeleteLists(COCKPIT, 1);
	}
	float YMIDDLE = sc_height / 2;
	float XMIDDLE = sc_width / 2;
	glNewList(COCKPIT, GL_COMPILE);

	glPushMatrix();
	glLoadIdentity();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, (sc_width)-(0) + 1, (sc_height)-(0) + 1);
	gluOrtho2D(-0.5, 1023 + .5, -0.5, 767 + .5);

	glMatrixMode(GL_MODELVIEW);

	/**/
	setColor(grey10);
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(halftone);
	glRects(0, 0, 1023, 767 / 2);
	glDisable(GL_POLYGON_STIPPLE);
	/**/
	display_meters(pp);

	display_heading(pp, X_ADJUST, Y_ADJUST);

	display_artificial_horizon(pp, X_ADJUST, Y_ADJUST);
	glPopMatrix();
	glPopMatrix();
	glLineWidth(1);



	glLineWidth(2);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, (sc_width)-(0) + 1, (sc_height)-(0) + 1);
	glScissor(0, 0, (sc_width)-(0) + 1, (sc_height)-(0) + 1);
	gluOrtho2D(-0.5, sc_width + 0.5, -0.5, sc_height + 0.5);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	setColor(orange);
	glBegin(GL_LINE_STRIP);
	glVertex2s(XMIDDLE, YMIDDLE);
	glVertex2s(XMIDDLE, YMIDDLE - 16);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRects(0, YMIDDLE - 1, sc_width, sc_height);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glLineWidth(1);
	glCallList(REPORT_CARD);
	glPopMatrix();
	glEndList();
}

void draw_hud(gameState *gs, plane *pp, int sc_width, int sc_height, float X_ADJUST, float Y_ADJUST) {
	int i;
	int x;
	int y;
	int a;
	float r;
	float sin;
	float cos;
	char charbuff[255];
	float vv = pp->climbspeed;
	float rhaws[][2] = {	/* 20 point unit circle	*/
		0.0f,1.0f,
		0.309017f,0.951057f,
		0.587785f,0.809017f,
		0.809017f,0.587785f,
		0.951057f,0.309017f,
		1.0f,0.0f,
		0.951057f,-0.309017f,
		0.809017f,-0.587785f,
		0.587785f,-0.809017f,
		0.309017f,-0.951057f,
		0.0f,-1.0f,
		-0.309017f,-0.951057f,
		-0.587785f,-0.809017f,
		-0.809017f,-0.587785f,
		-0.951057f,-0.309017f,
		-1.0f,0.0f,
		-0.951057f,0.309017f,
		-0.809017f,0.587785f,
		-0.587785f,0.809017f,
		-0.309017f,0.951057f,
	};
	char* numbers[] = {
		"0","1","2","3","4","5","6","7","8","9",
		"10","11","12","13","14","15","16","17","18","19",
		"20","21","22","23","24","25","26","27","28","29",
		"30","31","32","33","34","35","36","37","38","39",
		"40","41","42","43","44","45","46","47","48","49",
		"50","51","52","53","54","55","56","57","58","59",
		"60","61","62","63","64","65","66","67","68","69",
		"70","71","72","73","74","75","76","77","78","79",
		"80","81","82","83","84","85","86","87","88","89",
		"90","91","92","93","94","95","96","97","98","99","100"
	};
	float YMIDDLE = sc_height / 2;
	float XMIDDLE = sc_width / 2;

	if (glIsList(HUD)) {
		glDeleteLists(HUD, 1);
	}

	glNewList(HUD, GL_COMPILE);
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-0.5, sc_width + 0.5, -0.5, sc_height + .5);
	glMatrixMode(GL_MODELVIEW);
	setColor(orange);
	glLineWidth(2);
	glPushMatrix();
	glLoadIdentity();
	x = XMIDDLE;
	y = 75;					/* marker for heading	*/
	glBegin(GL_LINE_STRIP);
	glVertex2s(x, y);
	glVertex2s(x, y + 15);
	glEnd();

	y = (sc_height + 1) / 2;
	glBegin(GL_LINE_STRIP);
	glVertex2s(x + 4, y);
	glVertex2s(x + 16, y);		/* nose cross hairs	*/
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2s(x - 4, y);
	glVertex2s(x - 16, y);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2s(x, y + 4);
	glVertex2s(x, y + 16);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2s(x, y - 4);
	glVertex2s(x, y - 16);
	glEnd();

	x = HUD_MARGIN;				/* mach and g text	*/

	sprintf(charbuff, "G %.2f", pp->lift / pp->gravity);
	gl_print(charbuff, x, 290);


	sprintf(charbuff, "M %.2f", pp->mach);
	gl_print(charbuff, x, 75);

	y = (sc_height + 1) / 4;
	x = HUD_MARGIN;				/* marker for airspeed	*/
	glBegin(GL_LINE_STRIP);
	glVertex2s(x, y);
	glVertex2s(x + 16, y);
	gl_print("C", x + 4, y + 4);
	glEnd();
	x = sc_width - HUD_MARGIN;		/* marker for altitude	*/

	glBegin(GL_LINE_STRIP);
	glVertex2s(x, y);
	glVertex2s(x - 16, y);		/* and vv (climbspeed)	*/
	glEnd();
	x -= 32;
	y += 30 * 3;
	for (i = 0; i < 6; i++) {
		glBegin(GL_LINE_STRIP);
		glVertex2s(x, y);
		glVertex2s(x + 8, y);		/* long tick	*/
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2s(x, y - 15);
		glVertex2s(x + 4, y - 15);	/* short tick	*/
		glEnd();
		y -= 30;
	}
	y -= 24;
	gl_print("R", x - 14, y + 4);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRects(x, y - 2, x + 60, y + 14);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	int planey = pp->y;
	if (planey >= 1000) {
		sprintf(charbuff, "%2d,%03d", planey / 1000, planey % 1000);
	}
	else {
		sprintf(charbuff, "   %3d", planey);
	}
	if (vv < 0) {
		vv = -vv;
	}
	if (vv > 300) {
		charbuff[3] = '0';
	}
	if (vv > 30) {
		charbuff[4] = '0';
	}
	charbuff[5] = '0';


	gl_print(charbuff, x + 2, y);


	glPushMatrix();
	glTranslatef(0.0, vv * (60.0f * 30.0f / 1000.0f), 0.0);

	y = (sc_height + 1) / 4;
	glBegin(GL_LINE_STRIP);
	glVertex2s(x, y);
	glVertex2s(x - 14, y + 6);		/* draw triangle	*/
	glVertex2s(x - 14, y - 6);
	glVertex2s(x, y);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	float k;
	k = -57.3 * (sc_height + 1) / 36.0;	/* screen is 36 degrees */
	glTranslatef(k * pp->vx / pp->vz, k * pp->vy / pp->vz, 0.0);

	x = XMIDDLE;
	y = (sc_height + 1) / 2;

	glBegin(GL_LINE_STRIP);
	glVertex2s(x + 16, y);
	glVertex2s(x + 6, y);		/* draw FPM		*/
	glVertex2s(x + 4, y + 4);
	glVertex2s(x, y + 6);
	glVertex2s(x, y + 16);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2s(x - 16, y);
	glVertex2s(x - 6, y);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2s(x, y + 6);
	glVertex2s(x - 4, y + 4);
	glVertex2s(x - 6, y);
	glVertex2s(x - 4, y - 4);
	glVertex2s(x, y - 6);
	glVertex2s(x + 4, y - 4);
	glVertex2s(x + 6, y);
	glEnd();
	glPopMatrix();


	a = -gs->tps * 3600.0 / 6082.0 * pp->vz;	/* airspeed meter	*/
	y = (sc_height + 1) / 4 - (a % 10) - 70;
	x = HUD_MARGIN - 8;			/* right edge		*/
	a = a / 10 - 7;			/* starting number	*/
	for (i = 0; i < 16; i++) {
		if (a >= 0) {
			if (a % 5) {
				glBegin(GL_LINE_STRIP);
				glVertex2s(x, y);
				glVertex2s(x - 4, y);
				glEnd();
			}
			else {
				glBegin(GL_LINE_STRIP);
				glVertex2s(x, y);
				glVertex2s(x - 8, y);
				glEnd();

				if (a < 10) {
					gl_print("  ", x - 8 - 30, y - 4);
					gl_print(numbers[a], x - 30, y - 4);
				}
				else if (a < 100) {
					gl_print(" ", x - 8 - 30, y - 4);
					gl_print(numbers[a], x - 30, y - 4);
				}
				else {
					sprintf(charbuff, "%3d", a);
					gl_print(charbuff, x - 30, y - 4);
				}
			}
		}
		a++;
		y += 10;
	}

	a = 0.1 * pp->y;			/* altitude in 10's	*/
	x = sc_width - HUD_MARGIN + 4;
	y = (sc_height + 1) / 4 - (a % 10) - 70;
	a = a / 10 - 7;			/* starting number	*/
	for (i = 0; i < 16; i++) {
		if (a >= 0) {
			if (a % 5) {
				glBegin(GL_LINE_STRIP);
				glVertex2s(x, y);
				glVertex2s(x + 4, y);
				glEnd();
			}
			else {
				glBegin(GL_LINE_STRIP);
				glVertex2s(x, y);
				glVertex2s(x + 8, y);
				glEnd();
				glRasterPos2s(x + 10, y - 4);
				if (a < 10) {
					gl_print("   ", x + 10, y - 4);
					gl_print(numbers[a], x + 18, y - 4);
				}
				else {
					int j = a / 10;

					if (j < 10) {
						gl_print(" ", x + 10, y - 4);
					}
					sprintf(charbuff, "%d,%s", j, numbers[a % 10]);
					gl_print(charbuff, x + 18, y - 4);
				}
			}
		}
		a++;
		y += 10;
	}


	a = 3600 - (int)pp->azimuthf;		/* heading in tenth's	*/
	x = XMIDDLE - (a % 50) - 100;
	y = 75 - 4;
	a = a / 50 - 2;			/* heading in 5's	*/
	for (i = 0; i < 6; i++) {
		if (a < 0) {
			a += 360 / 5;	/* wrap around		*/
		}
		if (a >= 360 / 5) {
			a -= 360 / 5;
		}
		if (a & 1) {
			glBegin(GL_LINE_STRIP);
			glVertex2s(x, y);
			glVertex2s(x, y - 4);
			glEnd();
		}
		else {
			glBegin(GL_LINE_STRIP);
			glVertex2s(x, y);
			glVertex2s(x, y - 8);
			glEnd();

			if (a < 20) {
				gl_print("0", x - 8, y - 9 - 12);
				gl_print(numbers[a >> 1], x, y - 9 - 12);
			}
			else {
				gl_print(numbers[a >> 1], x - 8, y - 9 - 12);
			}

		}
		a++;
		x += 50;
	}

	x = sc_width - HUD_MARGIN - 32 - 14;
	if (pp->wheels) {
		gl_print("L", x, 50);
	}
	if (pp->flaps) {
		sprintf(charbuff, "Flap: %d", pp->flaps);
		gl_print(charbuff, x, 30);
	}
	if (pp->spoilers) {
		sprintf(charbuff, "Spoilr: %d", pp->spoilers);
		gl_print(charbuff, x + 80, 30);
	}

	/*if (pp->autop) {
		glRasterPos2s(x - 60, 10);
		//glCallLists(strlen("Auto"), GL_UNSIGNED_BYTE, "Auto");
	}*/
	if ((pp->fuel == 0) || (pp->fuel > 10)) {
		sprintf(charbuff, "Fuel: %d", pp->fuel >> 7);
		gl_print(charbuff, x, 10);
	}
	else if (pp->fuel < 0) {
		gl_print("Fuel: E", x, 10);
	}
	/* make fuel flash in the 1-10 % range */
	else if (gs->ticks & 2) {
		sprintf(charbuff, "Fuel: %d", pp->fuel >> 7);
		gl_print(charbuff, x, 10);
	}
	else {
		gl_print("    ", x, 10);
	}

	glRasterPos2s(x + 80, 10);
	sprintf(charbuff, "Thrust: %d", pp->thrust);
	gl_print(charbuff, x + 80, 10);


	gl_print(pp->plane_type, HUD_MARGIN - 30, 30);
	/* max G force		*/
	sprintf(charbuff, "%.1f", pp->Lmax);
	gl_print(charbuff, HUD_MARGIN - 30, 50);


	glPushMatrix();
	glPushAttrib(GL_VIEWPORT_BIT);
	glViewport(XMIDDLE - 200, 75, (XMIDDLE + 200) - (XMIDDLE - 200) + 1, ((sc_height + 1) * 3 / 4) - (75) + 1);
	glScissor(XMIDDLE - 200, 75, (XMIDDLE + 200) - (XMIDDLE - 200) + 1, ((sc_height + 1) * 3 / 4) - (75) + 1);
	{
		GLint mm;
		glGetIntegerv(GL_MATRIX_MODE, &mm);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-200.5, 200.5, 74.5 - (sc_height + 1) / 2, (sc_height + 1) / 4 + .5);
		glMatrixMode(mm);
	};
	/* rotate about nose marker	*/
	glRotatef(.1 * -pp->twist, 0.0f, 0.0f, 1.0f);
	/* elevation in tenths		*/
	a = pp->elevationf;
	i = a % 50;
	y = i * -(sc_height + 1) / 36 / 10 - 1 * (sc_height + 1) * 5 / 36;
	/* starting number	*/
	a = (a - i) / 10 - 1 * 5;

	for (i = 0; i < 4; i++) {
		if (a >= -90 && a <= 90) {
			if (a > 0) {
				glBegin(GL_LINE_STRIP);
				glVertex2s(25, y);
				glVertex2s(75, y);
				glVertex2s(75, y - 12);
				glEnd();
				gl_print(numbers[a], 77, y - 12);
				glBegin(GL_LINE_STRIP);
				glVertex2s(-25, y);
				glVertex2s(-75, y);
				glVertex2s(-75, y - 12);
				glEnd();
				gl_print(numbers[a], -77 - 20, y - 12);
			}
			else if (a < 0) {

				glCallList(1);
				glEnable(GL_LINE_STIPPLE);

				glBegin(GL_LINE_STRIP);
				glVertex2s(25, y);
				glVertex2s(75, y);
				glVertex2s(75, y + 12);
				glEnd();
				gl_print(numbers[-a], 77, y);
				glBegin(GL_LINE_STRIP);
				glVertex2s(-25, y);
				glVertex2s(-75, y);
				glVertex2s(-75, y + 12);
				glEnd();
				gl_print(numbers[-a], -77 - 20, y);
				glDisable(GL_LINE_STIPPLE);
			}
			else {			/* 0 marker	*/
				glBegin(GL_LINE_STRIP);
				glVertex2s(25, y);
				glVertex2s(75, y);
				glEnd();
				glBegin(GL_LINE_STRIP);
				glVertex2s(-25, y);
				glVertex2s(-75, y);
				glEnd();
			}
		}
		a += 5;
		y += 5 * (sc_height + 1) / 36;
	}



	glPopMatrix();
	glPopAttrib();



	glPushAttrib(GL_VIEWPORT_BIT);
	glPushMatrix();
	glViewport(8, 8, (HUD_MARGIN - 50) - (8) + 1, (HUD_MARGIN - 50) - (8) + 1);
	glScissor(8, 8, (HUD_MARGIN - 50) - (8) + 1, (HUD_MARGIN - 50) - (8) + 1); /* RHAWS scope	*/



	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(-100.5, 100.5, -100.0, 100.5);
	glMatrixMode(GL_MODELVIEW);

	setColor(green0);
	glBegin(GL_POINTS); glVertex2s(0, 0); glEnd();
	for (i = 0; i < 3600; i += 150) {	/* static ticks	*/
		gl_sincos(i, &sin, &cos);
		glBegin(GL_LINE_STRIP);
		glVertex2f(100.0f * sin, 100.0f * cos);
		if (i % 900 == 0) {
			r = 20.0;
		}
		else if (i % 450 == 0) {
			r = 75.0;
		}
		else {
			r = 88.0;
		}
		glVertex2f(r * sin, r * cos);
		glEnd();
	}
	glBegin(GL_LINE_STRIP);
	glVertex2s(20, 0);
	glVertex2s(20, 0);
	glEnd();
	glPushMatrix();
	glScalef(25.0, 25.0, 1.0);
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 20; i++) glVertex2fv(rhaws[i]); glEnd(); };
	glScalef(2.0, 2.0, 1.0);
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 20; i++) glVertex2fv(rhaws[i]); glEnd(); };
	glScalef(2.0, 2.0, 1.0);
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 20; i++) glVertex2fv(rhaws[i]); glEnd(); };
	glPopMatrix();




	//glCallList(RADAR);
	glPushMatrix();
	glLoadIdentity();
	glScalef(.004f, -.004f, .004f);	/* scale down (y=-z)	*/
	glRotatef(.1 * pp->azimuthf, 0, 0, 1);
	glTranslatef(-pp->x, -pp->z, 0.0);
	setColor(purple0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(0.0, 0.0);		/* the runway	*/
	glVertex2f(0.0, -8500.0);
	glEnd();
	setColor(white);		/* NOTE: threat patches are in land2.c */
	gl_print("4", 6000, 14000);
	gl_print("8", -20000, 15000);
	gl_print("A", 3000, 34000);
	glLineWidth(1);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopAttrib();
	glEndList();
}

void draw_hud_sc(gameState* gs, plane* pp, int sc_width, int sc_height, float X_ADJUST, float Y_ADJUST) {
	int i;
	int x;
	int y;
	int a;
	float r;
	float sin;
	float cos;
	int x_margin = HUD_MARGIN +200;
	char charbuff[255];
	float vv = pp->climbspeed;
	float rhaws[][2] = {	/* 20 point unit circle	*/
		0.0f,1.0f,
		0.309017f,0.951057f,
		0.587785f,0.809017f,
		0.809017f,0.587785f,
		0.951057f,0.309017f,
		1.0f,0.0f,
		0.951057f,-0.309017f,
		0.809017f,-0.587785f,
		0.587785f,-0.809017f,
		0.309017f,-0.951057f,
		0.0f,-1.0f,
		-0.309017f,-0.951057f,
		-0.587785f,-0.809017f,
		-0.809017f,-0.587785f,
		-0.951057f,-0.309017f,
		-1.0f,0.0f,
		-0.951057f,0.309017f,
		-0.809017f,0.587785f,
		-0.587785f,0.809017f,
		-0.309017f,0.951057f,
	};
	char* numbers[] = {
		"0","1","2","3","4","5","6","7","8","9",
		"10","11","12","13","14","15","16","17","18","19",
		"20","21","22","23","24","25","26","27","28","29",
		"30","31","32","33","34","35","36","37","38","39",
		"40","41","42","43","44","45","46","47","48","49",
		"50","51","52","53","54","55","56","57","58","59",
		"60","61","62","63","64","65","66","67","68","69",
		"70","71","72","73","74","75","76","77","78","79",
		"80","81","82","83","84","85","86","87","88","89",
		"90","91","92","93","94","95","96","97","98","99","100"
	};
	float YMIDDLE = sc_height / 2;
	float XMIDDLE = sc_width / 2;

	if (glIsList(HUD)) {
		glDeleteLists(HUD, 1);
	}

	glNewList(HUD, GL_COMPILE);
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-0.5, sc_width + 0.5, -0.5, sc_height + .5);
	glMatrixMode(GL_MODELVIEW);
	setColor(orange);
	glLineWidth(2);
	glPushMatrix();
	glLoadIdentity();
	x = XMIDDLE;
	y = 75;					/* marker for heading	*/
	glBegin(GL_LINE_STRIP);
	glVertex2s(x, y);
	glVertex2s(x, y + 15);
	glEnd();

	y = (sc_height + 1) / 2;
	glBegin(GL_LINE_STRIP);
	glVertex2s(x + 4, y);
	glVertex2s(x + 16, y);		/* nose cross hairs	*/
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2s(x - 4, y);
	glVertex2s(x - 16, y);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2s(x, y + 4);
	glVertex2s(x, y + 16);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2s(x, y - 4);
	glVertex2s(x, y - 16);
	glEnd();

	x = x_margin;				/* mach and g text	*/

	sprintf(charbuff, "G %.2f", pp->lift / pp->gravity);
	gl_print(charbuff, x, 450);


	sprintf(charbuff, "M %.2f", pp->mach);
	gl_print(charbuff, x, 175);

	y = ((sc_height + 1) / 4)+110;
	x = x_margin;			/* marker for airspeed	*/
	glBegin(GL_LINE_STRIP);
	glVertex2s(x, y);
	glVertex2s(x + 16, y);
	gl_print("C", x + 4, y + 4);
	glEnd();
	x = sc_width - x_margin;		/* marker for altitude	*/

	glBegin(GL_LINE_STRIP);
	glVertex2s(x, y);
	glVertex2s(x - 16, y);		/* and vv (climbspeed)	*/
	glEnd();
	x -= 32;
	y += 30 * 3;
	for (i = 0; i < 6; i++) {
		glBegin(GL_LINE_STRIP);
		glVertex2s(x, y);
		glVertex2s(x + 8, y);		/* long tick	*/
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2s(x, y - 15);
		glVertex2s(x + 4, y - 15);	/* short tick	*/
		glEnd();
		y -= 30;
	}
	y -= 24;
	gl_print("R", x - 14, y + 4);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRects(x, y - 2, x + 60, y + 14);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	int planey = pp->y-gs->groundlevel;
	if (planey >= 1000) {
		sprintf(charbuff, "%2d,%03d", planey / 1000, planey % 1000);
	}
	else {
		sprintf(charbuff, "   %3d", planey);
	}
	if (vv < 0) {
		vv = -vv;
	}
	if (vv > 300) {
		charbuff[3] = '0';
	}
	if (vv > 30) {
		charbuff[4] = '0';
	}
	charbuff[5] = '0';


	gl_print(charbuff, x + 2, y);


	glPushMatrix();
	glTranslatef(0.0, vv * (60.0f * 30.0f / 1000.0f), 0.0);

	y = (sc_height + 1) / 4;
	glBegin(GL_LINE_STRIP);
	glVertex2s(x, y);
	glVertex2s(x - 14, y + 6);		/* draw triangle	*/
	glVertex2s(x - 14, y - 6);
	glVertex2s(x, y);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	float k;
	k = -57.3 * (sc_height + 1) / 36.0;	/* screen is 36 degrees */
	glTranslatef(k * pp->vx / pp->vz, k * pp->vy / pp->vz, 0.0);

	x = XMIDDLE;
	y = (sc_height + 1) / 2;
	
	glBegin(GL_LINE_STRIP);
	glVertex2s(x + 16, y);
	glVertex2s(x + 6, y);		/* draw FPM		*/
	glVertex2s(x + 4, y + 4);
	glVertex2s(x, y + 6);
	glVertex2s(x, y + 16);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2s(x - 16, y);
	glVertex2s(x - 6, y);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2s(x, y + 6);
	glVertex2s(x - 4, y + 4);
	glVertex2s(x - 6, y);
	glVertex2s(x - 4, y - 4);
	glVertex2s(x, y - 6);
	glVertex2s(x + 4, y - 4);
	glVertex2s(x + 6, y);
	glEnd();
	glPopMatrix();
	

	a = -gs->tps * 3600.0 / 6082.0 * pp->vz;	/* airspeed meter	*/
	y = (sc_height + 1) / 4 - (a % 10) + 40;
	x = x_margin - 8;			/* right edge		*/
	a = a / 10 - 7;			/* starting number	*/
	for (i = 0; i < 16; i++) {
		if (a >= 0) {
			if (a % 5) {
				glBegin(GL_LINE_STRIP);
				glVertex2s(x, y);
				glVertex2s(x - 4, y);
				glEnd();
			}
			else {
				glBegin(GL_LINE_STRIP);
				glVertex2s(x, y);
				glVertex2s(x - 8, y);
				glEnd();

				if (a < 10) {
					gl_print("  ", x - 8 - 30, y - 4);
					gl_print(numbers[a], x - 30, y - 4);
				}
				else if (a < 100) {
					gl_print(" ", x - 8 - 30, y - 4);
					gl_print(numbers[a], x - 30, y - 4);
				}
				else {
					sprintf(charbuff, "%3d", a);
					gl_print(charbuff, x - 30, y - 4);
				}
			}
		}
		a++;
		y += 10;
	}

	a = 0.1 * pp->y;			/* altitude in 10's	*/
	x = sc_width - x_margin + 4;
	y = (sc_height + 1) / 4 - (a % 10) + 40;
	a = a / 10 - 7;			/* starting number	*/
	for (i = 0; i < 16; i++) {
		if (a >= 0) {
			if (a % 5) {
				glBegin(GL_LINE_STRIP);
				glVertex2s(x, y);
				glVertex2s(x + 4, y);
				glEnd();
			}
			else {
				glBegin(GL_LINE_STRIP);
				glVertex2s(x, y);
				glVertex2s(x + 8, y);
				glEnd();
				glRasterPos2s(x + 10, y - 4);
				if (a < 10) {
					gl_print("   ", x + 10, y - 4);
					gl_print(numbers[a], x + 18, y - 4);
				}
				else {
					int j = a / 10;

					if (j < 10) {
						gl_print(" ", x + 10, y - 4);
					}
					sprintf(charbuff, "%d,%s", j, numbers[a % 10]);
					gl_print(charbuff, x + 18, y - 4);
				}
			}
		}
		a++;
		y += 10;
	}


	a = 3600 - (int)pp->azimuthf;		/* heading in tenth's	*/
	x = XMIDDLE - (a % 50) - 100;
	y = 75 - 4;
	a = a / 50 - 2;			/* heading in 5's	*/
	for (i = 0; i < 6; i++) {
		if (a < 0) {
			a += 360 / 5;	/* wrap around		*/
		}
		if (a >= 360 / 5) {
			a -= 360 / 5;
		}
		if (a & 1) {
			glBegin(GL_LINE_STRIP);
			glVertex2s(x, y);
			glVertex2s(x, y - 4);
			glEnd();
		}
		else {
			glBegin(GL_LINE_STRIP);
			glVertex2s(x, y);
			glVertex2s(x, y - 8);
			glEnd();

			if (a < 20) {
				gl_print("0", x - 8, y - 9 - 12);
				gl_print(numbers[a >> 1], x, y - 9 - 12);
			}
			else {
				gl_print(numbers[a >> 1], x - 8, y - 9 - 12);
			}

		}
		a++;
		x += 50;
	}

	x = sc_width - x_margin - 32 - 14;
	if (pp->wheels) {
		gl_print("L", x, 50);
	}
	if (pp->flaps) {
		sprintf(charbuff, "Flap: %d", pp->flaps);
		gl_print(charbuff, x, 30);
	}
	if (pp->spoilers) {
		sprintf(charbuff, "Spoilr: %d", pp->spoilers);
		gl_print(charbuff, x + 80, 30);
	}

	/*if (pp->autop) {
		glRasterPos2s(x - 60, 10);
		//glCallLists(strlen("Auto"), GL_UNSIGNED_BYTE, "Auto");
	}*/
	if ((pp->fuel == 0) || (pp->fuel > 10)) {
		sprintf(charbuff, "Fuel: %d", pp->fuel >> 7);
		gl_print(charbuff, x, 10);
	}
	else if (pp->fuel < 0) {
		gl_print("Fuel: E", x, 10);
	}
	/* make fuel flash in the 1-10 % range */
	else if (gs->ticks & 2) {
		sprintf(charbuff, "Fuel: %d", pp->fuel >> 7);
		gl_print(charbuff, x, 10);
	}
	else {
		gl_print("    ", x, 10);
	}

	glRasterPos2s(x + 80, 10);
	sprintf(charbuff, "Thrust: %d", pp->thrust);
	gl_print(charbuff, x + 80, 10);


	gl_print(pp->plane_type, x_margin - 30, 30);
	/* max G force		*/
	sprintf(charbuff, "%.1f", pp->Lmax);
	gl_print(charbuff, x_margin - 30, 50);


	glPushMatrix();
	glPushAttrib(GL_VIEWPORT_BIT);
	glViewport(XMIDDLE - 200, 75, (XMIDDLE + 200) - (XMIDDLE - 200) + 1, ((sc_height + 1) * 3 / 4) - (75) + 1);
	glScissor(XMIDDLE - 200, 75, (XMIDDLE + 200) - (XMIDDLE - 200) + 1, ((sc_height + 1) * 3 / 4) - (75) + 1);
	{
		GLint mm;
		glGetIntegerv(GL_MATRIX_MODE, &mm);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-200.5, 200.5, 74.5 - (sc_height + 1) / 2, (sc_height + 1) / 4 + .5);
		glMatrixMode(mm);
	};
	/* rotate about nose marker	*/
	glRotatef(.1 * -pp->twist, 0.0f, 0.0f, 1.0f);
	/* elevation in tenths		*/
	a = pp->elevationf;
	i = a % 50;
	y = i * -(sc_height + 1) / 36 / 10 - 1 * (sc_height + 1) * 5 / 36;
	/* starting number	*/
	a = (a - i) / 10 - 1 * 5;

	for (i = 0; i < 4; i++) {
		if (a >= -90 && a <= 90) {
			if (a > 0) {
				glBegin(GL_LINE_STRIP);
				glVertex2s(25, y);
				glVertex2s(75, y);
				glVertex2s(75, y - 12);
				glEnd();
				gl_print(numbers[a], 77, y - 12);
				glBegin(GL_LINE_STRIP);
				glVertex2s(-25, y);
				glVertex2s(-75, y);
				glVertex2s(-75, y - 12);
				glEnd();
				gl_print(numbers[a], -77 - 20, y - 12);
			}
			else if (a < 0) {

				glCallList(1);
				glEnable(GL_LINE_STIPPLE);

				glBegin(GL_LINE_STRIP);
				glVertex2s(25, y);
				glVertex2s(75, y);
				glVertex2s(75, y + 12);
				glEnd();
				gl_print(numbers[-a], 77, y);
				glBegin(GL_LINE_STRIP);
				glVertex2s(-25, y);
				glVertex2s(-75, y);
				glVertex2s(-75, y + 12);
				glEnd();
				gl_print(numbers[-a], -77 - 20, y);
				glDisable(GL_LINE_STIPPLE);
			}
			else {			/* 0 marker	*/
				glBegin(GL_LINE_STRIP);
				glVertex2s(25, y);
				glVertex2s(75, y);
				glEnd();
				glBegin(GL_LINE_STRIP);
				glVertex2s(-25, y);
				glVertex2s(-75, y);
				glEnd();
			}
		}
		a += 5;
		y += 5 * (sc_height + 1) / 36;
	}



	glPopMatrix();
	glPopAttrib();



	glPushAttrib(GL_VIEWPORT_BIT);
	glPushMatrix();
	glViewport(8, 8, (HUD_MARGIN - 50) - (8) + 1, (HUD_MARGIN - 50) - (8) + 1);
	glScissor(8, 8, (HUD_MARGIN - 50) - (8) + 1, (HUD_MARGIN - 50) - (8) + 1); /* RHAWS scope	*/



	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(-100.5, 100.5, -100.0, 100.5);
	glMatrixMode(GL_MODELVIEW);

	setColor(green0);
	glBegin(GL_POINTS); glVertex2s(0, 0); glEnd();
	for (i = 0; i < 3600; i += 150) {	/* static ticks	*/
		gl_sincos(i, &sin, &cos);
		glBegin(GL_LINE_STRIP);
		glVertex2f(100.0f * sin, 100.0f * cos);
		if (i % 900 == 0) {
			r = 20.0;
		}
		else if (i % 450 == 0) {
			r = 75.0;
		}
		else {
			r = 88.0;
		}
		glVertex2f(r * sin, r * cos);
		glEnd();
	}
	glBegin(GL_LINE_STRIP);
	glVertex2s(20, 0);
	glVertex2s(20, 0);
	glEnd();
	glPushMatrix();
	glScalef(25.0, 25.0, 1.0);
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 20; i++) glVertex2fv(rhaws[i]); glEnd(); };
	glScalef(2.0, 2.0, 1.0);
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 20; i++) glVertex2fv(rhaws[i]); glEnd(); };
	glScalef(2.0, 2.0, 1.0);
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 20; i++) glVertex2fv(rhaws[i]); glEnd(); };
	glPopMatrix();




	
	glPushMatrix();
	glLoadIdentity();
	glScalef(.002f, -.002f, .002f);	
	glRotatef(.1 * pp->azimuthf, 0, 0, 1);
	glTranslatef(-pp->x, -pp->z, 0.0);
	
	setColor(white);		
	for (int i = 0; i < gs->nbspt; i++) {
		gl_print(gs->rspt[i].name, gs->rspt[i].x, gs->rspt[i].y);
	}

	glLineWidth(1);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopAttrib();
	glEndList();
}