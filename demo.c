#include "demo.h"
#include "graph.h"
#include "flight.h"

#ifdef OLDCODE

void make_horizon_meter()
{
	static GLshort yaw_indicator[][2] = { {0,-85},{-4,-81},{4,-81} };

	glNewList(HORIZON_METER, GL_COMPILE);

	/*
	 *  set up horizon meter
	 */
#ifdef NTSC
	glViewport(260, METER_VLLY, (380) - (260) + 1, (METER_VURY)-(METER_VLLY)+1);
	glScissor(260, METER_VLLY, (380) - (260) + 1, (METER_VURY)-(METER_VLLY)+1);
#else
	 /*viewport (412,612,METER_VLLY,METER_VURY);XXX*/
	glViewport((int)(412 * X_ADJUST + 0.1), (int)(METER_VLLY * Y_ADJUST + 0.1), ((int)(612 * X_ADJUST + 0.1)) - ((int)(412 * X_ADJUST + 0.1)) + 1, ((int)(METER_VURY * Y_ADJUST + 0.1)) - ((int)(METER_VLLY * Y_ADJUST + 0.1)) + 1);
	glScissor((int)(412 * X_ADJUST + 0.1), (int)(METER_VLLY * Y_ADJUST + 0.1), ((int)(612 * X_ADJUST + 0.1)) - ((int)(412 * X_ADJUST + 0.1)) + 1, ((int)(METER_VURY * Y_ADJUST + 0.1)) - ((int)(METER_VLLY * Y_ADJUST + 0.1)) + 1);
#endif

	{
		GLint mm;
		glGetIntegerv(GL_MATRIX_MODE, &mm);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-90.0, 90.0, -90.0, 90.0);
		glMatrixMode(mm);
	};
	glPushMatrix();
	setColor(blue);
	glNewList(HORIZON_EDIT, GL_COMPILE);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, 0.0f, 0.0f);
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

	glPopMatrix();				/* return to ortho	*/
	draw_blanking();
	setColor(red);
	glPushMatrix();			/* save matrix for wing_stall	*/
	glEndList();
	glNewList(YAW_EDIT, GL_COMPILE);
	glTranslatef(0.0, 0.0, 0.0);
	polf2s(3, yaw_indicator);
	//writemask (wm_allplanes);
	glPopMatrix();
	glEndList();

	glNewList(WING_STALL, GL_COMPILE);
	//writemask (white);
	setColor(white);
	glRasterPos2s(-32, 4);
	//glCallLists(strlen("WING-STALL"), GL_UNSIGNED_BYTE, "WING-STALL");
	//writemask (wm_allplanes);
	glEndList();

	glNewList(G_LIMIT, GL_COMPILE);
	//writemask (white);
	setColor(white);
	glRasterPos2s(-24, 4);
	//glCallLists(strlen("G-LIMIT"), GL_UNSIGNED_BYTE, "G-LIMIT");
	//writemask (wm_allplanes);
	glEndList();

	glNewList(AUTO_PILOT, GL_COMPILE);
	//writemask (white);
	setColor(white);
	glRasterPos2s(-40, 20);
	//glCallLists(strlen("AUTO-PILOT"), GL_UNSIGNED_BYTE, "AUTO-PILOT");
	//writemask (wm_allplanes);
	glEndList();


	glEndList();

	glNewList(CRASH_METERS, GL_COMPILE);
	/*viewport (METER_VLLX,METER_VURX,METER_VLLY,METER_VURY);XXX*/
	glViewport((int)(METER_VLLX * X_ADJUST + 0.1), (int)(METER_VLLY * Y_ADJUST + 0.1), ((int)(METER_VURX * X_ADJUST + 0.1)) - ((int)(METER_VLLX * X_ADJUST + 0.1)) + 1, ((int)(METER_VURY * Y_ADJUST + 0.1)) - ((int)(METER_VLLY * Y_ADJUST + 0.1)) + 1);
	glScissor((int)(METER_VLLX * X_ADJUST + 0.1), (int)(METER_VLLY * Y_ADJUST + 0.1), ((int)(METER_VURX * X_ADJUST + 0.1)) - ((int)(METER_VLLX * X_ADJUST + 0.1)) + 1, ((int)(METER_VURY * Y_ADJUST + 0.1)) - ((int)(METER_VLLY * Y_ADJUST + 0.1)) + 1);
	//writemask (white);
	setColor(white);
	glCallList(1);
	glEnable(GL_POLYGON_STIPPLE);
	//glClear(GL_COLOR_BUFFER_BIT);
	glDisable(GL_POLYGON_STIPPLE);
	//writemask (wm_allplanes);
	glEndList();
}

void make_slow_meters()
{
	int i;
	float r, sin, cos;

	static GLshort gy_triangle[][2] = {
	{0,200},
	{8,208},
	{8,192},
	};

	glNewList(SLOW_METERS, GL_COMPILE);
	setColor(white);
	glNewList(TEXT_EDIT, GL_COMPILE);
	glRasterPos2s(0, 0);
	//glCallLists(strlen(""), GL_UNSIGNED_BYTE, "");
	glRasterPos2s(0, 0);
	//glCallLists(strlen(""), GL_UNSIGNED_BYTE, "");
	glEndList();
#ifndef NOGMETER
	glPushMatrix();

	glNewList(GY_EDIT, GL_COMPILE);
	glTranslatef(0.0, 0.0, 0.0);
	polf2s(3, gy_triangle);
	glEndList();
	glPopMatrix();
#endif

	/* HEADING meter	*/
	glTranslatef((float)HEADING_CX, 200.0, 0.0);
	glNewList(HEADING_ROTATE_EDIT, GL_COMPILE);
	glRotatef(0.0, 0, 0, 1);
	setColor(white);
	for (i = 0; i < 3600; i += 100) {
		gl_sincos((float)i, &sin, &cos);
		glBegin(GL_LINE_STRIP);
		glVertex2f(100.0f * sin, 100.0f * cos);
		if (i == 300 || i == 600 || i == 1200 || i == 1500 ||
			i == 2100 || i == 2400 || i == 3000 || i == 3300) {
			r = 75.0f;	/* long line	*/
		}
		else {
			r = 90.0f;	/* short line	*/
		}
		glVertex2f(r * sin, r * cos);
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
	glScalef(.004f, -.004f, .004f);	/* scale down (y=-z)	*/
	glCallList(RADAR);
	setColor(blue);
	glBegin(GL_LINE_STRIP);
	glVertex2f(0.0f, 0.0f);		/* the runway	*/
	glVertex2f(0.0f, -8500.0f);
	glEnd();
	glEndList();
}
void make_clear_meters()
{
	glNewList(CLEAR_TEXT_DISPLAY, GL_COMPILE);
#ifdef NTSC
	glViewport(79, 196, (560) - (79) + 1, (217) - (196) + 1);
	glScissor(79, 196, (560) - (79) + 1, (217) - (196) + 1);
#else
	/*viewport (99,900,310,345);*/
	glViewport((int)(99 * X_ADJUST + 0.1), (int)(310 * Y_ADJUST + 0.1), ((int)(900 * X_ADJUST + 0.1)) - ((int)(99 * X_ADJUST + 0.1)) + 1, ((int)(345 * Y_ADJUST + 0.1)) - ((int)(310 * Y_ADJUST + 0.1)) + 1);
	glScissor((int)(99 * X_ADJUST + 0.1), (int)(310 * Y_ADJUST + 0.1), ((int)(900 * X_ADJUST + 0.1)) - ((int)(99 * X_ADJUST + 0.1)) + 1, ((int)(345 * Y_ADJUST + 0.1)) - ((int)(310 * Y_ADJUST + 0.1)) + 1);
#endif
	{
		GLint mm;
		glGetIntegerv(GL_MATRIX_MODE, &mm);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(99.0, 900.0, 300.0, 345.0);
		glMatrixMode(mm);
	};
	setColor(black);
	//glClear(GL_COLOR_BUFFER_BIT);
	setColor(white);
	glEndList();

	glNewList(CLEAR_METERS, GL_COMPILE);	/* clear ALL the meters	*/
	 /*viewport (METER_VLLX,FUEL_VLLX,METER_VLLY,METER_VURY);XXX*/
	glViewport((int)(METER_VLLX * X_ADJUST + 0.1), (int)(METER_VLLY * Y_ADJUST + 0.1), ((int)(FUEL_VLLX * X_ADJUST + 0.1)) - ((int)(METER_VLLX * X_ADJUST + 0.1)) + 1, ((int)(METER_VURY * Y_ADJUST + 0.1)) - ((int)(METER_VLLY * Y_ADJUST + 0.1)) + 1);
	glScissor((int)(METER_VLLX * X_ADJUST + 0.1), (int)(METER_VLLY * Y_ADJUST + 0.1), ((int)(FUEL_VLLX * X_ADJUST + 0.1)) - ((int)(METER_VLLX * X_ADJUST + 0.1)) + 1, ((int)(METER_VURY * Y_ADJUST + 0.1)) - ((int)(METER_VLLY * Y_ADJUST + 0.1)) + 1);
	{
		GLint mm;
		glGetIntegerv(GL_MATRIX_MODE, &mm);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(50 - 0.5, FUEL_LLX + 0.5, 100 - 0.5, 300 + 0.5);
		glMatrixMode(mm);
	};
	//writemask (wm_allplanes-3);
	setColor(black);
	//glClear(GL_COLOR_BUFFER_BIT);
	glEndList();

	glNewList(CLEAR_FUEL_METER, GL_COMPILE);
	/*viewport (FUEL_VLLX,METER_VURX,METER_VLLY,METER_VURY);*/
	glViewport((int)(FUEL_VLLX * X_ADJUST + 0.1), (int)(METER_VLLY * Y_ADJUST + 0.1), ((int)(METER_VURX * X_ADJUST + 0.1)) - ((int)(FUEL_VLLX * X_ADJUST + 0.1)) + 1, ((int)(METER_VURY * Y_ADJUST + 0.1)) - ((int)(METER_VLLY * Y_ADJUST + 0.1)) + 1);
	glScissor((int)(FUEL_VLLX * X_ADJUST + 0.1), (int)(METER_VLLY * Y_ADJUST + 0.1), ((int)(METER_VURX * X_ADJUST + 0.1)) - ((int)(FUEL_VLLX * X_ADJUST + 0.1)) + 1, ((int)(METER_VURY * Y_ADJUST + 0.1)) - ((int)(METER_VLLY * Y_ADJUST + 0.1)) + 1);
	{
		GLint mm;
		glGetIntegerv(GL_MATRIX_MODE, &mm);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(FUEL_LLX - 0.5, FUEL_LLX + 50.5, 100 - 0.5, 300 + 0.5);
		glMatrixMode(mm);
	};
	setColor(black);
	//glClear(GL_COLOR_BUFFER_BIT);
	glEndList();

	glNewList(CLEAR_REPORT_CARD, GL_COMPILE);
	glViewport(0, 0, (XMAXSCREEN)-(0) + 1, (METER_VLLY - 40) - (0) + 1);
	glScissor(0, 0, (XMAXSCREEN)-(0) + 1, (METER_VLLY - 40) - (0) + 1);
	{
		GLint mm;
		glGetIntegerv(GL_MATRIX_MODE, &mm);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-0.5, 1023 + .5, -0.5, METER_LLY - 39.5);
		glMatrixMode(mm);
	};
	setColor(black);
	//glClear(GL_COLOR_BUFFER_BIT);
	glEndList();
}


makebox{
	if (glIsList(b->ury_obj)) {
		glDeleteLists(b->ury_obj, 1);
	}
	glNewList(b->ury_obj, GL_COMPILE);
	p = &mat[0][0];
	/* top face	*/
	setColor(col + 1);
	*p++ = llx;	*p++ = ury;	*p++ = llz;
	*p++ = urx;	*p++ = ury;	*p++ = llz;
	*p++ = urx;	*p++ = ury;	*p++ = urz;
	*p++ = llx;	*p++ = ury;	*p++ = urz;
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3iv(mat[i]); glEnd(); }



	for (i = llz; i <= urz; i += dz) {	/* front and back	*/
		if (i == llz) {
			setColor(col + 3);
		}
		else {
			setColor(col + 2);
		}
		p = &mat[0][0];
		*p++ = llx;	*p++ = lly;	*p++ = i;
		*p++ = urx;	*p++ = lly;	*p++ = i;
		*p++ = urx;	*p++ = ury;	*p++ = i;
		*p++ = llx;	*p++ = ury;	*p++ = i;
		{int er; glBegin(GL_POLYGON); for (er = 0; er < 4; er++) glVertex3iv(mat[er]); glEnd(); }
		facet(4, mat, col);
	}

	/* left and right	*/
	for (i = llx; i <= urx; i += dx) {
		if (i == llx) {
			setColor(col + 1);
		}
		else {
			setColor(col + 4);
		}
		p = &mat[0][0];
		*p++ = i;	*p++ = lly;	*p++ = llz;
		*p++ = i;	*p++ = ury;	*p++ = llz;
		*p++ = i;	*p++ = ury;	*p++ = urz;
		*p++ = i;	*p++ = lly;	*p++ = urz;
		{int er; glBegin(GL_POLYGON); for (er = 0; er < 4; er++) glVertex3iv(mat[er]); glEnd(); }
		facet(4, mat, col);
	}
	glEndList();
}

void simulation(struct gameState* gs, struct plane* pp, int msx, int msy, int XMIDDLE, int YMIDDLE, int XMAXSCREEN, int YMAXSCREEN) {
	int itemp;
	float temp;
	float elevtemp = 0.0f;

	gs->tick_counter++;
	if (pp->status > MEXPLODE) {
		/* tenths of degrees per tick	*/
		pp->rollers = (pp->ROLLF * ((msx - XMIDDLE + 8) >> 4));
		itemp = (int)ceilf(pp->rollers * pp->vz - pp->roll_speed);	/* delta	*/
		if (itemp != 0) {
			if (itemp >= DELAY || itemp <= -DELAY) {
				itemp /= DELAY;
			}
			else {
				itemp = itemp > 0 ? 1 : -1;
			}
		}
		if (pp->wing_stall > 0) {
			itemp >>= pp->wing_stall;
			itemp += mrandom(pp->wing_stall << 3);
		}
		pp->roll_speed += itemp;
		pp->elevator = -1.0f * (pp->ELEVF * ((msy - YMIDDLE + 8) >> 4));
		itemp = (int)ceilf(pp->elevator * pp->vz + pp->vy - pp->elevation_speed);
		elevtemp = pp->elevator * pp->vz + pp->vy - pp->elevation_speedf;
		if (itemp != 0) {
			if (itemp >= DELAY || itemp <= -DELAY) {
				itemp /= DELAY;
			}
			else {
				itemp = itemp > 0 ? 1 : -1;
			}
		}
		if (pp->wing_stall > 0) {
			itemp >>= pp->wing_stall;
			elevtemp = elevtemp / powf(2, pp->wing_stall);
			itemp += mrandom(pp->wing_stall * 2);
			elevtemp += mrandom(pp->wing_stall * 2);
		}
		pp->elevation_speed += itemp;
		pp->elevation_speedf += elevtemp;
		float aztemp;
		temp = pp->rudder * pp->vz - 2.0f * pp->vx;
		if (pp->on_ground) {
			itemp = 16 * (int)temp;
			if (itemp < -MAX_TURNRATE || itemp > MAX_TURNRATE) {
				/* clip turn rate	*/
				if (itemp < 0) {
					itemp = -MAX_TURNRATE;
				}
				else {
					itemp = MAX_TURNRATE;
				}
				/* decrease with velocity */
				if (fabs(pp->vz) > 10.0f / gs->tps) {
					/* skid effect */
					temp = 0.4f * gs->tps * (pp->rudder * pp->vz - .75f);
					if (temp < -MAX_TURNRATE || temp > MAX_TURNRATE) {
						temp = (float)itemp;
					}
					itemp -= (int)ceilf(temp);
				}
			}
			temp = (float)itemp;
		}
		else {
			itemp = (int)ceilf(temp);	/* itemp is desired azimuth speed	*/
		}

		aztemp = temp;
		itemp -= (int)pp->azimuth_speedf;	/* itemp is now desired-actual		*/
		aztemp -= pp->azimuth_speedf;
		if (itemp != 0) {
			if (itemp >= DELAY || itemp <= -DELAY) {
				itemp /= DELAY;
			}
			else {
				itemp = itemp > 0 ? 1 : -1;
			}
		}

		pp->azimuth_speed += itemp;
		pp->azimuth_speedf += itemp;
		if (pp->on_ground) {
			/* dont allow negative pitch unless positive elevation	*/
			if (pp->elevation_speedf < 0) {
				if (pp->elevationf <= 0) {
					pp->elevation_speedf = 0;
				}
			}
			else {		/* mimic gravitational torque	*/
				itemp = -((int)pp->vz * gs->tps + pp->MIN_LIFT_SPEED) >> 2;
				elevtemp = -(pp->vz * gs->tps + pp->MIN_LIFT_SPEED) / 4.0f;
				if (itemp < 0 && pp->elevation <= 0) {
					itemp = 0;
				}
				if (elevtemp < 0 && pp->elevationf <= 0) {
					elevtemp = 0.0f;
				}
				if (pp->elevation_speed > itemp) {
					pp->elevation_speed = itemp;
				}
				if (pp->elevation_speedf > elevtemp) {
					pp->elevation_speedf = elevtemp;
				}
				if (gs->tps == 20 && -(int)(pp->fps_knots * pp->vz) > 173) {
					int breakpoint = 1;
				}
				if (gs->tps == 60 && -(int)(pp->fps_knots * pp->vz) > 173) {
					int breakpoint = 1;
				}
			}
			pp->roll_speed = 0;
		}

		/****************************************************************
		/*	concat incremental rotations and get new angles back
		/****************************************************************/
#define LOCAL_MATRIX 1
#ifdef OLDCODE
		popmatrix();			// pop back to identity		7
		pushmatrix();			// push it		
		//if ((tick_counter&1) == 0) {	// every once in a while
		if (TRUE) {
			translate(pp->x, pp->y, pp->z);// rebuild old ptw		
			rotate(pp->azimuth, 'y');	// to keep it normalized	
			rotate(pp->elevation, 'x');
			rotate(pp->twist, 'z');
		}
		else loadmatrix(pp->ptw);		// otherwise reload old one	
		translate(pp->vx, pp->vy, pp->vz);		// build up new one		
		if (pp->azimuth_speed) rotate(pp->azimuth_speed, 'y');
		if (pp->elevation_speed) rotate(pp->elevation_speed, 'x');
		if (pp->roll_speed) rotate(pp->roll_speed, 'z');
		getmatrix(pp->ptw);		// fetch new one		
#endif
#ifdef GLMATRIX
		glPushMatrix();
		//glMatrixMode(GL_MODELVIEW);*/

		glLoadIdentity();
		glTranslatef(pp->x, pp->y, pp->z);
		glRotatef(pp->azimuthf / 10.0f, 0, 1, 0);
		glRotatef(pp->elevationf / 10.0f, 1, 0, 0);
		glRotatef(pp->twist / 10.0f, 0, 0, 1);
		glTranslatef(pp->vx, pp->vy, pp->vz);
		if (pp->azimuth_speedf) {
			glRotatef(pp->azimuth_speedf / 10.0f, 0, 1, 0);
		}
		if (pp->elevation_speedf) {
			glRotatef(pp->elevation_speedf / 10.0f, 1, 0, 0);
		}
		if (pp->roll_speed) {
			glRotatef(pp->roll_speed / 10.0f, 0, 0, 1);
		}

		getGlMatrix(pp->ptw);
		glPopMatrix();
		pp->my_ptw = pp->ptw;
#endif
#ifdef LOCAL_MATRIX
		if (FALSE) {
			setIdentity(pp->ptw);
			translateM(pp->ptw, pp->x, pp->y, pp->z);// rebuild old ptw		
			rotateM(pp->ptw, pp->azimuthf * .1f, 0, 1, 0);	// to keep it normalized	
			rotateM(pp->ptw, pp->elevationf * .1f, 1, 0, 0);
			rotateM(pp->ptw, pp->twist * .1f, 0, 0, 1);
		}
		translateM(pp->ptw, pp->vx, pp->vy, pp->vz);
		if (pp->azimuth_speedf) rotateM(pp->ptw, pp->azimuth_speedf * .1f, 0, 1, 0);
		if (pp->elevation_speedf) rotateM(pp->ptw, pp->elevation_speedf * .1f, 1, 0, 0);
		if (pp->roll_speed) rotateM(pp->ptw, pp->roll_speed * .1f, 0, 0, 1);
		pp->my_ptw = pp->ptw;
#endif

		/* analyze new ptw	*/
		temp = 0.0f;
		pp->elevation = -xasin(pp->ptw[2][1]);
		pp->elevationf = -xasin_new(pp->ptw[2][1], pp);
		float ascos = 0.0f;

		gl_sincos(pp->elevation, &ascos, &temp);
		if (pp->azimuthf > 850 && pp->azimuthf < 900) {
			int breakpoint = 1;
		}
		if (temp != 0.0) {
			pp->azimuthf = xasin_new(pp->ptw[2][0] / temp, pp);
			if (pp->ptw[2][2] < 0.0) {
				/* if heading into z	*/
				pp->azimuthf = 1800 - pp->azimuthf;	/* then adjust		*/
			}
			if (pp->azimuthf < 0) {
				pp->azimuthf += 3600;
			}

			pp->twist = xasin(pp->ptw[0][1] / temp);
			if (pp->ptw[1][1] < 0.0) {
				/* if upside down	*/
				pp->twist = 1800 - pp->twist;
			}
			if (pp->twist < 0) {
				pp->twist += 3600;
			}
		}
		pp->last_px = pp->x;			/* save last position	*/
		pp->last_py = pp->y;
		pp->last_pz = pp->z;
		pp->x = pp->ptw[3][0];
		pp->y = pp->ptw[3][1];
		pp->z = pp->ptw[3][2];
		pp->climbspeed = gs->tps * (int)(pp->y - pp->last_py);


		/****************************************************************
		/*	perform incremental rotations on velocities
		/****************************************************************/
#ifdef OLDCODE
		popmatrix();				// pop and push I	
		pushmatrix();
		if (pp->roll_speed) rotate(-pp->roll_speed, 'z');
		if (pp->elevation_speed) rotate(-pp->elevation_speed, 'x');
		if (pp->azimuth_speed) rotate(-pp->azimuth_speed, 'y');
		translate(pp->vx, pp->vy, pp->vz);
		getmatrix(pp->incremental);	// to get new rotated velocities
		pp->vx = pp->incremental[3][0];
		pp->vy = pp->incremental[3][1];
		pp->vz = pp->incremental[3][2];
#endif
#ifdef GLMATRIX
		glPushMatrix();
		glLoadIdentity();
		if (pp->roll_speed) glRotatef(-pp->roll_speed / 10.0, 0, 0, 1);
		if (pp->elevation_speedf) glRotatef(-pp->elevation_speedf / 10.0, 1, 0, 0);
		if (pp->azimuth_speedf) glRotatef(-pp->azimuth_speedf / 10.0, 0, 1, 0);
		glTranslatef(pp->vx, pp->vy, pp->vz);
		getGlMatrix(pp->incremental);
		glPopMatrix();

		pp->vx = pp->incremental[3][0];
		pp->vy = pp->incremental[3][1];
		pp->vz = pp->incremental[3][2];
#endif
#ifdef LOCAL_MATRIX
		setIdentity(pp->incremental);
		pp->my_ptw = pp->ptw;
		if (pp->roll_speed) rotateM(pp->incremental, -pp->roll_speed * .1f, 0, 0, 1);
		if (pp->elevation_speedf) rotateM(pp->incremental, -pp->elevation_speedf * .1f, 1, 0, 0);
		if (pp->azimuth_speedf) rotateM(pp->incremental, -pp->azimuth_speedf * .1f, 0, 1, 0);
		translateM(pp->incremental, pp->vx, pp->vy, pp->vz);


		pp->vx = pp->incremental[3][0];
		pp->vy = pp->incremental[3][1];
		pp->vz = pp->incremental[3][2];

#endif
		/****************************************************************
		/*	check altitude for too high, and landing/takeoff
		/****************************************************************/
		if (pp->y > 50000.0) pp->thrust = 0;	/* flame out		*/
		else if (pp->y > 4.0) {		/* not on ground	*/
			if (pp->on_ground) {			/* if was on ground	*/
				clear_report_card();		/* clear report card	*/
				pp->Cdp /= 3.0;			/* decrease drag	*/
				pp->min_throttle = 0;		/* no reverse engines	*/
			}
			pp->on_ground = FALSE;
		}
		else if (pp->y < .5) {		/* check for on the ground */
			if (IN_BOX(pp, -800.0, 100.0, -9500.0, 1000.0) ||
				IN_BOX(pp, 100.0, 1300.0, -2500.0, -1500.0) ||
				IN_BOX(pp, -2300.0, -800.0, -4900.0, -2000.0))
				if (!pp->on_ground) {			/* and not on ground before */
					int rating;

					pp->Cdp *= 3.0;			/* increase drag	*/
					pp->min_throttle = -pp->max_throttle;	/* allow reverse engines*/
					rating = report_card(-pp->climbspeed, pp->twist,
						(int)(pp->vx * gs->tps), (int)(-pp->vz * pp->fps_knots),
						pp->wheels, pp);
					if (rating == -1) {		/* oops - you crashed	*/
						pp->status = MEXPLODE;	/* set to exploding	*/
						pp->lost++;		/* increment count	*/
					}
					else {
						pp->fuel += rating << 7;
						if (pp->fuel > (100 << 7))  pp->fuel = 100 << 7;
						pp->max_throttle = 100;
					}
					rebuild_status();
				}
				else;
			else {
				make_crash("You crashed into the swamps");
				//broadcast("crashed into the swamps");
			}
			pp->ptw[3][1] = pp->y = 0.0;
			pp->on_ground = TRUE;
			if (pp->status > MEXPLODE) {
				if (pp->elevationf < 0) pp->elevationf = 0;/* kill negative elevation */
				if (pp->twist != 0) pp->twist = 0;	/* kill any twist	*/
			}
		}
	}	/* end not crashing	*/



	/****************************************************************
	/*	compute new velocities, accelerations
	/****************************************************************/
	//callobj(CLEAR_METERS);		/* sets up viewport, ortho, wm	*/


	if (pp->fuel <= 0) {		/* out of gas	*/
		pp->thrust = 0;
		pp->max_throttle = 0;
		pp->min_throttle = 0;
	}

	if (pp->status > MEXPLODE) {
		if (pp->y > pp->gefy) {
			// ground effect factor
			pp->kl = 1.0f;
		}
		else {
			pp->kl = (pp->y / pp->b);
			if (pp->kl > .225f) {
				pp->kl = .484f * pp->kl + .661f;
			}
			else {
				pp->kl = 2.533f * pp->kl + .20f;
			}
		}

		/* compute new accelerations, lift: only if vz is negative	*/
		pp->val = (pp->vz >= 0.0);
		if (!pp->val) {
			pp->ae = pp->vy / pp->vz + pp->tilt_factor;
			pp->Cl = pp->uCl = pp->ae / (.17f + pp->kl * pp->ipi_AR);
			if (pp->Cl > pp->max_cl) {		/* check for positive stall	*/
				pp->Cl = 3.0f * pp->max_cl - 2.0f * pp->Cl;
				pp->wing_stall = 1;
				if (pp->wing_stall > 0) {
					printf("stalled %f %f %f\n", pp->Cl, pp->max_cl, pp->min_cl);
				}
				if (pp->Cl < 0.0f) {
					pp->wing_stall += 1 - (int)(pp->Cl / pp->max_cl);
					pp->Cl = 0.0f;
				}
				if (pp->uCl > 5.0f) {
					pp->uCl = 5.0f;
				}

			}
			else if (pp->Cl < pp->min_cl) {	/* check for negative stall	*/
				pp->Cl = 3.0f * pp->min_cl - 2.0f * pp->Cl;
				pp->wing_stall = 1;
				if (pp->Cl > 0.0f) {
					pp->wing_stall += 1 - (int)(pp->Cl / pp->min_cl);
					pp->Cl = 0.0f;
				}
				if (pp->uCl < -5.0f) {
					pp->uCl = -5.0f;
				}
			}
			else {
				pp->wing_stall = FALSE;
			}

		}
		else {
			pp->Cl = pp->uCl = 0.0f;
			pp->wing_stall = pp->on_ground ? 0 : (int)pp->vz;
			pp->ae = 0.0f;
		}
		if (pp->wing_stall > 64) {
			pp->wing_stall = 64;
		}
		if ((gs->tick_counter & 1) == 0) {	/* only do on even ticks	*/
			/* compute speed of sound	*/
			if (pp->y <= 36000.0f) {
				pp->sos = -1116.0f / gs->tps + (1116.0f - 968.0f) / gs->tps / 36000.0f * pp->y;
			}
			else {
				pp->sos = -968.0f / gs->tps;
			}
			itemp = ((int)pp->y) >> 10;
			if (itemp > 74) {
				itemp = 74;
			}
			pp->ro2 = .5f * ro[itemp];
			if (pp->Cl < .2) {
				pp->mcc = .7166666f + .1666667f * pp->Cl;
			}
			else {
				pp->mcc = .7833333f - .1666667f * pp->Cl;
			}
			pp->mach = pp->vz / pp->sos;		/* and current mach number	*/
			pp->mratio = pp->mach / pp->mcc;
			if (pp->mratio < 1.034f) {
				pp->Cdc = 0.0f;
			}
			else {
				pp->Cdc = .082f * pp->mratio - 0.084788f;
				if (pp->Cdc > .03f) pp->Cdc = .03f;
			}
			if (pp->spoilers > 0.0f) {
				pp->Cdc += pp->Spdf;
			}
		}

		pp->qs = pp->ro2 * pp->vz * pp->s;		/* assume V approx = vz	*/

		pp->lift = pp->Cl * pp->qs;
		pp->g_limit = FALSE;
		if (pp->spoilers > 0) {
			pp->lift *= pp->Splf;
		}
	relift:
		pp->ay = pp->vz * pp->lift;
		pp->az = -pp->vy * pp->lift;
		pp->lift = pp->ay * pp->inverse_mass;	/* save for wing loading meter	*/
		if (pp->lift > pp->Lmax) {
			pp->lift = .99f * pp->Lmax / pp->inverse_mass / pp->vz;
			pp->g_limit = TRUE;
			goto relift;
		}
		else if (pp->lift < pp->Lmin) {
			pp->lift = .99f * pp->Lmin / pp->inverse_mass / pp->vz;
			pp->g_limit = TRUE;
			goto relift;
		}

		/* engine thrust		*/
		pp->az = pp->az - (.01f / gs->tps / gs->tps * pp->thrust * pp->Mthrust);

		/* drag - needs to be broken into y/z components		*/
		pp->Cd = pp->Cdp + pp->kl * pp->uCl * pp->uCl * pp->ie_pi_AR + pp->Cdc;
		pp->zdrag = pp->Cd * pp->qs;
		pp->ydrag = pp->vy * pp->zdrag;
		pp->zdrag = pp->vz * pp->zdrag;
		if (pp->val) {			/* if vz is positive	*/
			pp->ay -= pp->ydrag;
			pp->az -= pp->zdrag;
		}
		else {
			pp->ay += pp->ydrag;
			pp->az += pp->zdrag;
		}

		/* now convert forces to accelerations (A=F/M)	*/
		pp->ax = 0.0f;
		pp->ay *= pp->inverse_mass;
		pp->az *= pp->inverse_mass;

		/* add in gravity which is an acceleration	*/
		/**/
		pp->ax -= pp->ptw[0][1] * pp->gravity;
		pp->ay -= pp->ptw[1][1] * pp->gravity;
		pp->az -= pp->ptw[2][1] * pp->gravity;
		/**/
		pp->vx += pp->ax;
		pp->vz += pp->az;
		if (pp->on_ground && pp->status > MEXPLODE) {
			temp = 0.0f;
			float mcos;
			pp->vx = 0.0;
			gl_sincos(pp->elevation, &temp, &mcos);
			temp = pp->vz * temp / mcos;
			if (pp->vy + pp->ay < temp) {
				pp->ay = temp - pp->vy;
			}
		}
		pp->vy += pp->ay;

		pp->airspeed = -(int)(pp->fps_knots * pp->vz);
		pp->climbspeed = gs->tps * (int)(pp->y - pp->last_py);


		if (pp->thrust > 0) {
			itemp = pp->thrust;
		}
		else {
			itemp = -pp->thrust;
		}
		if (gs->ticks % 100 == 1) {
			pp->fuel_rate = fuel_consump(pp->Mthrust, pp->W);
			pp->fuel -= (int)(itemp * pp->fuel_rate);
			pp->inverse_mass = G_ACC / (pp->W + pp->fuel / 12800.0f * pp->fuel_weight);
		}
	}
}



void drawWorld(void) {
	fps++;

	glClearColor(0.2f, 0.2f, 0.8f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glCallList(WORLD_OBJECT);

	glCallList(RUNWAY_STRIPES);
	glCallList(LIGHTS);

	glPopMatrix();

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	draw_buildings(0, 0, 0, 0, 0, lgs);
	draw_shadow(lpp, 1);
	// draw plane

	glDisable(GL_DEPTH_TEST);
	setColor(black);
	if (lgs->debug == TRUE) {
		drawText();
	}
	ftime(&start);
	if (end.time != 0 && end.millitm != 0) {
		diff =
			(int)(1000.0 * (start.time - end.time) + (start.millitm - end.millitm));
		if (diff != 0) {
			tickperseconds = (fps - oldfps) * 1000 / diff;
		}
	}
	end.time = start.time;
	end.millitm = start.millitm;

	oldfps = fps;
	switch (lgs->view_switch) {
	case 1:
		glLoadIdentity();
		glTranslatef(0, -lpp->pilot_y, lpp->pilot_z);
		glRotatef(-(lpp->twist / 10.0), 0.0, 0.0, 1.0);
		glRotatef(-(lpp->elevationf / 10.0), 1.0, 0.0, 0.0);
		glRotatef(-(lpp->azimuthf / 10.0), 0.0, 1.0, 0.0);
		glTranslatef(-lpp->x, -lpp->y, -lpp->z);
		break;
	case 2:

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);

		glTranslatef(lpp->x, lpp->y, lpp->z);
		glRotatef(lpp->azimuthf / 10.0, 0, 1, 0);
		glRotatef(lpp->elevationf / 10.0, 1, 0, 0);
		glRotatef(lpp->twist / 10.0, 0, 0, 1);
		glCallList(lpp->obj);
		glutWireOctahedron();
		glDisable(GL_DEPTH_TEST);

		glLoadIdentity();
		planeCamera();
		gluLookAt(eyes.x, eyes.y + 100, eyes.z + 500, eyes.x, eyes.y, eyes.z, 0, 1, 0);
		glPopMatrix();
		break;
	case 3:
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);

		glTranslatef(lpp->x, lpp->y, lpp->z);
		glRotatef((lpp->azimuthf / 10.0), 0.0, 1.0, 0.0);
		glRotatef((lpp->elevationf / 10.0), 1.0, 0.0, 0.0);
		glRotatef((lpp->twist / 10.0), 0.0, 0.0, 1.0);
		glCallList(lpp->obj);
		glutWireOctahedron();
		glDisable(GL_DEPTH_TEST);
		glLoadIdentity();
		freeCamera();
		gluLookAt(TOWER_EX, TOWER_EY, TOWER_EZ, lpp->x, lpp->y, lpp->z, 0, 1, 0);
		glPopMatrix();
		break;
	}
	float c[16];
	glGetFloatv(GL_CURRENT_RASTER_POSITION_VALID, c);

	glFlush();
	glutSwapBuffers();
}
void drawWaterMark(void) {
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glOrtho(0, XMAXSCREEN, 0, YMAXSCREEN, -1000.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_LIGHTING);
	glLoadIdentity();
	glTranslatef(XMAXSCREEN - 470, 110, 0.0f);

	glRotatef((lpp->azimuth / 10.0), 0.0, 1.0, 0.0);
	glRotatef((lpp->elevation / 10.0), 1.0, 0.0, 0.0);
	glRotatef((lpp->twist / 10.0), 0.0, 0.0, 1.0);

	glScalef(5.5f, 5.5f, 5.5f);
	draw_logo();
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glColor4f(1.0, 1.0, 1.0, 0.5f);
	glLoadIdentity();
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glRasterPos2i(XMAXSCREEN - 400, 64);
	float c[4];
	glGetFloatv(GL_CURRENT_RASTER_POSITION_VALID, c);
	// 354x92px
	glBitmap(354, 92, 0, 0, 0.0, 0, sgi);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}
void drawWorldAndSimul(void) {
	float pambient[] = { 0.1, 0.1, 0.1, 1.0 };
	float pdiffuse[] = { 0.5, 1.0, 1.0, 1.0 };
	float pposition[] = { -1.0, 1.0, 2.0 };

	fps++;

	glClearColor(0.2f, 0.2f, 0.8f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_DEPTH_TEST);

	glCallList(WORLD_OBJECT);
	glCallList(RUNWAY_STRIPES);
	glCallList(LIGHTS);

	glPopMatrix();

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	draw_buildings(0, 0, 0, 0, 0, lgs);
	draw_shadow(lpp, 1);
	glDisable(GL_DEPTH_TEST);

	ftime(&start);
	if (end.time != 0 && end.millitm != 0) {
		diff = (int)(1000.0 * (start.time - end.time) + (start.millitm - end.millitm));
		if (diff != 0) {
			tickperseconds = (fps - oldfps) * 1000 / diff;
		}
	}
	end.time = start.time;
	end.millitm = start.millitm;

	oldfps = fps;

	switch (view) {
	case 1:
		glLoadIdentity();

		glTranslatef(0, -lpp->pilot_y, lpp->pilot_z);
		glRotatef(-(lpp->twist / 10.0), 0.0, 0.0, 1.0);
		glRotatef(-(lpp->elevationf / 10.0), 1.0, 0.0, 0.0);
		glRotatef(-(lpp->azimuthf / 10.0), 0.0, 1.0, 0.0);
		glTranslatef(-lpp->x, -lpp->y, -lpp->z);

		break;
	case 2:

		glEnable(GL_DEPTH_TEST);
		//glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);
		glDepthFunc(GL_LESS);
		glTranslatef(lpp->x, lpp->y, lpp->z);
		glRotatef(lpp->azimuthf / 10.0, 0, 1, 0);
		glRotatef(lpp->elevationf / 10.0, 1, 0, 0);
		glRotatef(lpp->twist / 10.0, 0, 0, 1);
		glCallList(lpp->obj);
		glutWireOctahedron();
		glDisable(GL_DEPTH_TEST);
		//glDisable(GL_LIGHTING);
		glDisable(GL_COLOR_MATERIAL);
		glLoadIdentity();


		glTranslatef(0, -20.0f, -100.0f);
		glRotatef(-(lpp->twist / 10.0), 0.0, 0.0, 1.0);
		glRotatef(-(lpp->elevationf / 10.0), 1.0, 0.0, 0.0);
		glRotatef(-(lpp->azimuthf / 10.0), 0.0, 1.0, 0.0);
		glTranslatef(-lpp->x, -lpp->y, -lpp->z);

		glPopMatrix();
		break;
	case 3:



		glEnable(GL_DEPTH_TEST);
		//glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);

		glTranslatef(lpp->x, lpp->y, lpp->z);
		glRotatef((lpp->azimuthf / 10.0), 0.0, 1.0, 0.0);
		glRotatef((lpp->elevationf / 10.0), 1.0, 0.0, 0.0);
		glRotatef((lpp->twist / 10.0), 0.0, 0.0, 1.0);
		glCallList(lpp->obj);
		glutWireOctahedron();
		glDisable(GL_DEPTH_TEST);
		//glDisable(GL_LIGHTING);
		glDisable(GL_COLOR_MATERIAL);

		glLoadIdentity();

		gluLookAt(TOWER_EX, TOWER_EY, TOWER_EZ, lpp->x, lpp->y, lpp->z, 0, 1, 0);
		glPopMatrix();
		break;
	case 4:
		freeCamera();
		glEnable(GL_DEPTH_TEST);
		//glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);

		glTranslatef(lpp->x, lpp->y, lpp->z);
		glRotatef((lpp->azimuthf / 10.0), 0.0, 1.0, 0.0);
		glRotatef((lpp->elevationf / 10.0), 1.0, 0.0, 0.0);
		glRotatef((lpp->twist / 10.0), 0.0, 0.0, 1.0);
		glCallList(lpp->obj);
		glutWireOctahedron();
		glDisable(GL_DEPTH_TEST);
		//glDisable(GL_LIGHTING);
		glDisable(GL_COLOR_MATERIAL);
		drawPlaneSpeedVector();
		glLoadIdentity();

		gluLookAt(lpp->x + eyes.x, lpp->y + eyes.y, lpp->z + eyes.z, lpp->x, lpp->y, lpp->z, 0, 1, 0);
		glPopMatrix();
		break;
	}
	if (lgs->sts == DEMONSTRATION) {
		drawWaterMark();
	}
	else {
		setColor(white);
		if (lgs->debug == TRUE) {
			drawText();
		}
		else {
			drawRealHud();
		}
	}
	glFlush();
	glutSwapBuffers();
}
void drawSimpleWorld(void) {
	glClearColor(0.2f, 0.2f, 0.8f, 1.0f);
	// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	float model[4][4];
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	getGlMatrix(model);

	int mnt_dist = 500000;
	int mod = 0;
	glGetIntegerv(GL_MATRIX_MODE, &mod);
	if (mod != GL_MODELVIEW) {
		int breakpoint = 0;
	}

	setColor(green);
	glBegin(GL_POLYGON);
	glVertex3i(mnt_dist, 0, mnt_dist);
	glVertex3i(mnt_dist, 0, -mnt_dist);
	glVertex3i(-mnt_dist, 0, -mnt_dist);
	glVertex3i(-mnt_dist, 0, mnt_dist);
	glEnd();

	setColor(brown);

	for (int x = -mnt_dist; x <= mnt_dist; x += 10000) {
		glBegin(GL_LINE_STRIP);
		glVertex3i(x, 0, -mnt_dist);
		glVertex3i(x, 0, mnt_dist);
		glEnd();
	}
	for (int x = -mnt_dist; x <= mnt_dist; x += 10000) {
		glBegin(GL_LINE_STRIP);
		glVertex3i(-mnt_dist, 0, x);
		glVertex3i(mnt_dist, 0, x);
		glEnd();
	}

	setColor(grey0);

	glPushMatrix();
	glTranslatef(100, 0, -500.0);
	glutSolidCube(50);
	glPopMatrix();

	setColor(orange);
	float ystart = 0.0f;

	switch (view) {
	case 1:
		glLoadIdentity();
		glTranslatef(0, -lpp->pilot_y, lpp->pilot_z);
		glRotatef(-(lpp->twist / 10.0), 0.0, 0.0, 1.0);
		glRotatef(-(lpp->elevationf / 10.0), 1.0, 0.0, 0.0);
		glRotatef(-(lpp->azimuth / 10.0), 0.0, 1.0, 0.0);
		glTranslatef(-lpp->x, -lpp->y, -lpp->z);
		break;
	case 2:

		glPushMatrix();
		glTranslatef(lpp->x, lpp->y, lpp->z);
		glRotatef(lpp->azimuth / 10.0, 0, 1, 0);
		glRotatef(lpp->elevationf / 10.0, 1, 0, 0);
		glRotatef(lpp->twist / 10.0, 0, 0, 1);
		glutWireCube(50);
		glPopMatrix();

		glLoadIdentity();
		planeCamera();
		gluLookAt(eyes.x, eyes.y + 100, eyes.z + 500, eyes.x, eyes.y, eyes.z, 0, 1, 0);

		break;
	case 3:

		glPushMatrix();
		glTranslatef(lpp->x, lpp->y, lpp->z);
		glRotatef((lpp->azimuth / 10.0), 0.0, 1.0, 0.0);
		glRotatef((lpp->elevation / 10.0), 1.0, 0.0, 0.0);
		glRotatef((lpp->twist / 10.0), 0.0, 0.0, 1.0);
		glutWireCube(50);
		glPopMatrix();

		glLoadIdentity();
		freeCamera();
		gluLookAt(TOWER_EX, TOWER_EY, TOWER_EZ, lpp->x, lpp->y, lpp->z, 0, 1, 0);

		break;
	}
	// glPopMatrix();
	glGetIntegerv(GL_MATRIX_MODE, &mod);
	if (mod != GL_MODELVIEW) {
		int breakpoint = 0;
	}

	gl_print_matrix(model, ystart);
	glPushMatrix();
	glFlush();
	glutSwapBuffers();
}

void tick_count(int va) {
	lgs->tick_counter++;
	glutTimerFunc(1000 / lgs->tps, tick_count, 0);
}
void tick_per_seconds(int va) {
	tickperseconds = lgs->tick_counter - oldtick;
	// lgs->tps = tickperseconds;
	oldtick = lgs->tick_counter;
	int current_tps;
	float veldiff;
	current_tps = tickperseconds;

	lpp->gravity = G_ACC / (current_tps * 1.0) / (current_tps * 1.0);
	if (lpp->gravity == 0) {
		int breakpoint = 1;
	}
	lpp->inverse_mass = G_ACC / (lpp->W + lpp->fuel / 12800.0 * lpp->fuel_weight);
	lpp->fps_knots = current_tps * (3600.0 / 6082.0);

	if (current_tps == lgs->tps) {
		lgs->vx_add = lgs->vy_add = lgs->vz_add = 0.0;
		glutTimerFunc(1000, tick_per_seconds, 0);
		return;
	}
	else if (current_tps > lgs->tps) {
		veldiff = current_tps / (float)(lgs->tps + 1);
		// int_tps++;
	}
	else /* (current_tps < int_tps) */
	{
		veldiff = lgs->tps / (float)(lgs->tps - 1);
		// int_tps--;
	}

	lgs->vx_add = ((lpp->vx * veldiff) - lpp->vx) / lgs->tps;
	lgs->vy_add = ((lpp->vy * veldiff) - lpp->vy) / lgs->tps;
	lgs->vz_add = ((lpp->vz * veldiff) - lpp->vz) / lgs->tps;

	lgs->tps = current_tps;
	glutTimerFunc(1000, tick_per_seconds, 0);
}
void planeCamera() {
	eyes.x = lpp->x;
	eyes.y = lpp->y + 50.0f;
	eyes.z = lpp->z;
}
void drawHud() {
	unsigned char string[255];
	int w;
	w = glutBitmapLength(GLUT_BITMAP_8_BY_13, string);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glOrtho(0, XMAXSCREEN, 0, YMAXSCREEN, -1000.0, 1000.0);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	float ystart = 0.95f;
	int airspeed = -(int)(lpp->fps_knots * lpp->vz);
	sprintf(string, "FLYING : %s", lpp->plane_type);
	gl_print(string, -1.0, ystart -= .05);
	sprintf(string, "flaps : %d; throttle: %d, spoilers: %d", lpp->flaps, lpp->thrust, lpp->spoilers);
	gl_print(string, -1.0, ystart -= .05);
	sprintf(string, "gear : %d", lpp->wheels);
	gl_print(string, -1.0, ystart -= .05);

	sprintf(string, "speed %d", airspeed);
	gl_print(string, -1.0, ystart -= .05);

	int alt = lpp->y;
	if (alt >= 1000) {
		sprintf(string, "altitude %2d - %03d", alt / 1000, alt % 1000);
	}
	else {
		sprintf(string, "altitude %3d", alt);
	}
	gl_print(string, -1.0, ystart -= .05);

	int a;
	/* heading in tenth's	*/
	a = 3600 - lpp->azimuth;
	// a = a / 50 - 2;			/* heading in 5's	*/

	sprintf(string, "heading %d", a / 10);
	gl_print(string, -1.0, ystart -= .05);

	glBegin(GL_LINE_STRIP); // We want to draw a quad, i.e. shape with four sides
	glColor3f(1, 1, 0);     // Set the colour to red
	glVertex2f(0.025, 0.025); // Draw the four corners of the rectangle
	glVertex2f(0.025, -0.025);
	glVertex2f(-0.025, -0.025);
	glVertex2f(-0.025, 0.025);
	glVertex2f(0.025, 0.025);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.25, -0.25, 0.0f); // Translate rectangle to its assigned x and y position
// Put other transformations here
	glBegin(GL_LINE_STRIP); // We want to draw a quad, i.e. shape with four sides
	glColor3f(1, 1, 0);     // Set the colour to red
	glVertex2f(0, 0);       // Draw the four corners of the rectangle
	glVertex2f(0, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, 0);
	glVertex2f(0, 0);
	glEnd();

	/*glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glRasterPos2i(0, 0);
	glBitmap(10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
	glBitmap(10, 12, 0.0, 0.0, 11.0, 0.0, bcursor);
	glBitmap(10, 12, 0.0, 0.0, 11.0, 0.0, rasters);*/
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(0, 0, 0.0f);
	draw_logo();
	glPopMatrix();
	glCallList(CROSS_HAIRS);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix(); // revert back to the matrix I had before.
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}
#endif