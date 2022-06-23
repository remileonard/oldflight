#include "flight.h"
#include <string.h>
#include <stdio.h>
#include <math.h>

#pragma warning(disable : 4996)

void rebuild_status() {

}
void handle_key(char k, gameState *gs, plane *pp) {
	switch (k) {
	case '&':
		gs->debug = !gs->debug;
		break;
	case 'q':
		pp->thrust -= 5;
		if (pp->thrust < pp->min_throttle) {
			pp->thrust = pp->min_throttle;
		}
		break;
	case 's':
		pp->thrust += 5;
		if (pp->thrust > pp->max_throttle) {
			pp->thrust = pp->max_throttle;
		}
		break;
	case 'H':
		gs->hud = !gs->hud;
		break;
	case 'w':
	case 'x':
		/**/
		// ZOOM in/out
		if (gs->view_switch == TOWER) {
			if (k == 'x') {
				if (gs->tower_fov > 2.0f) {
					gs->tower_fov -= 0.5f;
				}
			}
			else if (gs->tower_fov < 45.0f) {
				gs->tower_fov += 0.5f;
			}
			glMatrixMode(GL_PROJECTION);
			// Reset first
			glLoadIdentity();
			gs->real_fov = gs->tower_fov;
			// Set perspective
			gluPerspective(gs->real_fov, (double)XMAXSCREEN / (double)YMAXSCREEN, 1.0, 1.0e9);
			// Set viewport
			glViewport(0, 0, XMAXSCREEN, YMAXSCREEN);
			glMatrixMode(GL_MODELVIEW);
		}
		/**/
		break;
	case 'D':
		gs->tviewpoint = (gs->tviewpoint + 1) % 5;
		switch (gs->tviewpoint) {
		case 0:
			gs->tx = TOWER_EX;
			gs->ty = TOWER_EY;
			gs->tz = TOWER_EZ;
			break;
		case 1:
			gs->tx = -12000;
			gs->ty = TOWER_EY;
			gs->tz = -48000;
			break;
		case 2:
			gs->tx = -200000;
			gs->ty = TOWER_EY;
			gs->tz = 48000;
			break;
		case 3:
			gs->tx = 52000;
			gs->ty = TOWER_EY;
			gs->tz = -168000;
			break;
		case 4:
			gs->tx = 120000;
			gs->ty = TOWER_EY;
			gs->tz = 68000;
			break;
		}
		break;
	case 'd':
		if (gs->view_switch == PILOTE) {
			gs->view_switch = TOWER;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity(); // Reset first
			gs->real_fov = gs->tower_fov;
			gluPerspective(gs->real_fov, (double)XMAXSCREEN / (double)YMAXSCREEN, 1.0, 1.0e9); // Set perspective
			glViewport(0, 0, XMAXSCREEN, YMAXSCREEN); // Set viewport
			glMatrixMode(GL_MODELVIEW);
		}
		else {
			gs->view_switch = PILOTE;
			gs->real_fov = 45.0f;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity(); // Reset first
			gluPerspective(gs->real_fov, (double)XMAXSCREEN / (double)YMAXSCREEN, 1.0, 1.0e9); // Set perspective
			glViewport(0, 0, XMAXSCREEN, YMAXSCREEN); // Set viewport
			glMatrixMode(GL_MODELVIEW);
		}
		break;
	case 'X':
		// free camera
		gs->view_switch = FREE;
		gs->real_fov = 45.0f;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity(); // Reset first
		gluPerspective(gs->real_fov, (double)XMAXSCREEN / (double)YMAXSCREEN, 1.0, 1.0e9); // Set perspective
		glViewport(0, 0, XMAXSCREEN, YMAXSCREEN); // Set viewport
		glMatrixMode(GL_MODELVIEW);
		break;
	case 'W':
		// wingman view
		gs->view_switch = WINGMAN;
		gs->real_fov = 45.0f;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity(); // Reset first
		gluPerspective(gs->real_fov, (double)XMAXSCREEN / (double)YMAXSCREEN, 1.0, 1.0e9); // Set perspective
		glViewport(0, 0, XMAXSCREEN, YMAXSCREEN); // Set viewport
		glMatrixMode(GL_MODELVIEW);
		break;
	case 'v':
		/*
		auto pilot

		autopilot = !autopilot;
		if (autopilot) {
				target_speed = airspeed;
				target_climb = climbspeed;
				target_twist = twist;
		}
		*/
		break;
	case 'f':
	case 'F':
		if (k == 'f') {
			if (pp->flaps < pp->Fmax) {
				pp->flaps += 10;
			}
		}
		else if (pp->flaps > 0) {
			pp->flaps -= 10;
		}
		pp->max_cl = 1.5 + pp->flaps / 62.5;
		pp->min_cl = pp->flaps / 62.5 - 1.5;
		pp->tilt_factor = .005 * pp->flaps + .017;
		break;
	case 'c':
	case 'C':
		if (k == 'c') {
			if (pp->spoilers < pp->Smax) {
				pp->spoilers += 20;
			}
		}
		else if (pp->spoilers > 0) {
			pp->spoilers -= 20;
		}
		pp->Spdf = .0025 * pp->spoilers; /* adjust drag and lift	*/
		pp->Splf = 1.0 - .005 * pp->spoilers;
		break;
	case 'l':
		if (pp->landing_gear_stuck != pp->wheels) {
			if (pp->wheels) /* bring wheels up	*/
			{
				if (pp->type == F16W) {
					pp->wheels_retracting = 1;
				}
				else if (pp->type == P38W) {
					pp->type = P38;
					pp->wheels = 0;
				}
				pp->wheels = FALSE;
				pp->Cdp /= 2.0;

				if (pp->on_ground && pp->status > MEXPLODE) {

					make_crash("You retracted the landing gear while on the ground", pp);
					//broadcast("retracted my landing gear while on the ground");

				}
			}
			else { /* put wheels down	*/
				pp->wheels = TRUE;
				if (pp->type == F16) {
					pp->type = F16W;
					pp->wheels_retracting = -1;
					pp->wheels = 10;
				}
				else if (pp->type == P38) {
					pp->type = P38W;
					pp->wheels = 10;
				}
				pp->Cdp *= 2.0;
			}
		}
		break;
	case 't':
		/*
		target plane
		// if I'm alive and no weapon already fired
		if (pp->status > MEXPLODE && !pp->mstatus) {
				if (ptemp = find_closest_plane(pp)) {
						// lock on the plane for 1 second
						missile_target = PLANE_ID(ptemp);
						tick_counter = 2;
				}
		}
		*/
		break;
	case 'a':
	case 'z':
	case 'e':
		/*
		fire weapon
		// if I'm alive and no weapon already fired
		if (pp->status > MEXPLODE && !pp->mstatus)
				if (!pp->on_ground) {
						if (val == 'w' && sidewinders > 0) {
								sidewinders--;
								pp->mtype = TYPE_SIDEWINDER;
								pp->mstatus = MSTART;
								if (missile_target == NULL_PLANE_ID) {
										if (ptemp = find_closest_plane(pp))
												then missile_target =
		PLANE_ID(ptemp);
								}
						}
						else if (val == 'q' && rockets > 0) {
								rockets--;
								pp->mtype = TYPE_ROCKET;
								pp->mstatus = MSTART;
								missile_target = NULL_PLANE_ID;
						}
						temp = fabs(vy) + fabs(vz);
						if (val == 'e') {
								pp->mtype = TYPE_CANNON;
								pp->mstatus = MFINISH + int_tps;
								temp = -2000.0 / TPS - temp;
								missile_target = NULL_PLANE_ID;
						}
						else temp = -500.0 / TPS - temp;

						missile_vx = ptw[2][0] * temp;
						missile_vy = ptw[2][1] * temp;
						missile_vz = ptw[2][2] * temp;
						pp->mx = pp->x + missile_vx;
						pp->my = pp->y + missile_vy;
						pp->mz = pp->z + missile_vz;
						pp->mkill = NULL_PLANE_ID;
						tick_counter = 2;
						rebuild_status();
				}
		*/
		break;
	case 'n':
		map_daynight(gs->daytime = !gs->daytime);
		make_world(gs);
		reset_building(gs);
		make_buildings(TOWER_EX, TOWER_EY, TOWER_EZ, gs);
		break;
	case 'h':
		/*
		display help, pause the simulation
		display_help();
		wait_for_input();
		*/
		break;
	
	case 'T':
		gs->threat_mode = !gs->threat_mode;
		break;
	case '~':
		/*
		unknown for now
		test_mode = !test_mode;
		fuel_rate = fuel_consump(Mthrust, W);
		sidewinders = rockets = 0;
		rebuild_status();*/
		break;
	case ':':
		gs->polymod = GL_FILL;

		break;
	case '!':
		gs->polymod = GL_LINE;

		break;
	case ';':
		gs->polymod = GL_POINT;
		break;
	case '?':

		/*
		unknown for now
		timeit = !timeit;
		if (timeit) {
		time_start = times (&tms_start_buf);
		tick_counter = TPS;
		}
		*/
		break;
	}
}
int report_card(int descent, int roll, int vx, int vz, int wheels, struct plane* p) {
	short on_runway;
	int rating;
	float azimuth;
	float xdist, zdist;
	char charbuf[80];
	int DY = 15;
	float y;

	clear_report_card();
	glNewList(REPORT_CARD, GL_COMPILE);
	
	azimuth = p->azimuthf;
	on_runway = IN_BOX(p, -100.0, 100.0, -8500.0, 0.0) || isOnRunWay(p);

	roll /= 10;
	if (roll > 180) roll -= 360;
	rating = 1;

	color(white);
	y = 50.0f;
	
	gl_print("Landing Report Card:", 50, y);
	sprintf(charbuf, "Rate of descent: %d fpm", descent * 60);
	gl_print(charbuf, 50, y - DY);

	sprintf(charbuf, "Roll angle: %d", roll);
	gl_print(charbuf,50, y - 2 * DY);
	sprintf(charbuf, "Air speed: %d knots", vz);
	gl_print(charbuf, 50, y - 3 * DY);

	if (!wheels) {
		gl_print("*** Landed with the landing gear up!", 500, y);
		rating = 0;
	}
	if (descent > 100) {
		gl_print("*** Descending too fast!", 350, y - DY);
		rating = 0;
	}
	if (roll < 0) roll = -roll;
	if (roll > 10) {
		gl_print("*** Too much roll!",350, y - 2 * DY);
		rating = 0;
	}
	if (!on_runway) {
		sprintf(charbuf, "*** Landed off the runway!");
		gl_print(charbuf,350, y - 3 * DY);
		rating = 0;
	}
	else if (vx > 10 || vx < -10) {
		sprintf(charbuf, "*** Too much drifting: %d fps", vx);
		gl_print(charbuf, 350, y - 3 * DY);
		rating = 0;
	}
	if (roll > 20 || descent > 20 || vx > 20 || vx < -20) rating = -1;

	if (rating == 1) {		// good landing => rate it
		sprintf(charbuf, "Sideways speed: %d fps", vx);
		gl_print(charbuf, 650, y);

		if (azimuth < 900 || azimuth > 2700) {
			zdist = -1075.0f - p->z;
		}
		else {
			zdist = -7425.0f - p->z;
		}
		xdist = fabsf(p->x);

		sprintf(charbuf, "Distance from centerline: %d", (int)xdist);
		gl_print(charbuf, 650, y - DY);

		zdist = fabsf(zdist);
		sprintf(charbuf, "Distance from touchdown: %d", (int)zdist);
		gl_print(charbuf, 650, y - 2.0f * DY);

		if (azimuth > 2700.0f) {
			azimuth = 3600.0f - azimuth;
		}
		else if (azimuth > 900.0f) {
			azimuth = 1800.0f - azimuth;
		}
		if (azimuth < 0.0f) {
			azimuth = -azimuth;
		}
		azimuth /= 10.0f;
		sprintf(charbuf, "Heading error: %f degrees", azimuth);
		gl_print(charbuf, 650, y - 3.0f * DY);

		if (vx < 0) {
			vx = -vx;
		}
		rating = 100 - descent - roll - (int) azimuth - (vx >> 1) - (int)(.01 * zdist) - (int)(.1 * xdist);
		if (rating < 0) {
			rating = 0;
		}
		sprintf(charbuf, "Nice landing! (%d/100)", rating);
		gl_print(charbuf, 250, y);
	}
	else if (rating == 0) {
		gl_print("CRASH LANDING! (0/100)", 250, y);
	}
	else {
		gl_print("EXPLODED ON IMPACT!",250, y);
		//broadcast("exploded on impact");
	}
	glEndList();
	return (rating);
}
void clear_report_card() {
	if (glIsList(REPORT_CARD)) {
		glDeleteLists(REPORT_CARD, 1);
	}
	/*if (hud) {
		if (isobj(CLEAR_TEXT_DISPLAY))
			delobj(CLEAR_TEXT_DISPLAY);		// delete all text messages
	}
	else {
		cursoff();
		frontbuffer(TRUE);	// clear report card from both buffers
		callobj(CLEAR_REPORT_CARD);
		frontbuffer(FALSE);
		curson();
	}*/
}
void make_crash(char* msg, struct plane* pp)
{
	
	int DY = 15;
	int y = METER_LLY - 40 - DY;

	clear_report_card();
	if (pp->status <= MEXPLODE)  return;
	pp->status = MEXPLODE;

	glNewList(REPORT_CARD, GL_COMPILE);
	color(white);
	gl_print(msg, 50, y);
	glEndList();
	/*
	int y;
	Plane p;

	p = planes[0];		// a bold assumption
	if (p->status <= MEXPLODE)  return;
	p->lost++;		// increment my lost count
	p->status = MEXPLODE;

	y = METER_LLY - 40 - DY;
	if (hud) {
		makeobj(CLEAR_TEXT_DISPLAY);
		color(white);
		cmov2s(50, y);
		charstr(msg);	// crash message
		closeobj();
	}
	else {
		cursoff();
		frontbuffer(TRUE);
		pushmatrix();
		pushviewport();
		callobj(CLEAR_REPORT_CARD);	// just in case, also set up
		color(white);
		cmov2s(50, y);
		charstr(msg);
		popmatrix();
		popviewport();
		frontbuffer(FALSE);
		curson();
	}
	*/
}
struct plane* init_plane() {
	struct plane* pp;
	pp = (Plane)malloc(sizeof(struct plane));
	if (pp != NULL) {
		pp->alive = -1;
		pp->won = 0;
		pp->lost = 0;
		PLANE_ID(pp) = 23;
		pp->myname[0] = '\0';
		pp->landing_gear_stuck = -1;		/* can toggle landing gear	*/
		pp->autopilot = pp->wheels = pp->wing_stall = FALSE;
		pp->thrust = 0;
		pp->airspeed = pp->last_airspeed = pp->climbspeed = pp->last_climbspeed = 0;
		pp->on_ground = pp->y <= 4.0f;

		pp->max_throttle = 100;
		pp->min_throttle = pp->on_ground ? -pp->max_throttle : 0;
		pp->ax = 0.0f;
		pp->ay = 0.0f;
		pp->az = 0.0f;

		pp->vx = 0.0f;
		pp->vy = 0.0f;
		pp->vz = 0.0f;

		pp->lift = 0.0f;
		pp->mach = 0.0f;
		pp->last_zdrag = 0.0f;

		pp->Splf = 1.0f;
		pp->Spdf = 0;
		pp->max_cl = 1.5f;
		pp->min_cl = -1.5f;
	}
	return pp;
}
struct gameState* init_game_state() {
	struct gameState* gs;
	gs = malloc(sizeof(struct gameState));
	if (gs != NULL) {
		reset_gs(gs);
 	}
	return (gs);
}
void reset_gs(struct gameState *gs) {
	gs->nbspt = 0;
	gs->groundlevel = .5;
	gs->nocrash = 0;
	gs->tx = TOWER_EX;
	gs->ty = TOWER_EY;
	gs->tz = TOWER_EZ;
	gs->real_fov = 45.0f;
	gs->textures = 0;
	gs->light = 0;
	gs->fog = 0;
	gs->sts = PRESENTATION;
	gs->tps = TPS;
	gs->tick_counter = 0;
	gs->timer = 0;
	gs->number_planes = 1;
	gs->test_mode = FALSE;
	gs->debug = FALSE;
	gs->threat_mode = FALSE;
	gs->timeit = FALSE;
	gs->eye_x = -1950.0f;
	gs->eye_y = 400.0f;
	gs->eye_z = -3150.0f;
	gs->view_switch = PILOTE;
	gs->view_angle_vertical = 0;
	gs->view_angle = 0;
	gs->tower_fov = 45.0f;
	gs->polymod = GL_FILL;
	gs->ticks = 0;

	gs->eyes.x = 100.0f;
	gs->eyes.y = 50.0f;
	gs->eyes.z = 100.0f;
	gs->cyaw = 0.0f;
	gs->croll = 0.0f;
	gs->cpitch = 0.0f;
	gs->objz = -200.0f;
	gs->daytime = 1;
}
void common_plane_init(struct gameState* gs, struct plane* pp) {
	setIdentity(pp->ptw);
	setIdentity(pp->incremental);
	pp->gravity = G_ACC / gs->tps / gs->tps;
	pp->fps_knots = gs->tps * (3600.0f / 6082.0f);
	pp->x = START_X;
	pp->y = START_Y;
	pp->z = START_Z;
	pp->mstatus = 0;
	pp->twist = 0;
	pp->azimuthf = START_AZIMUTH;
	pp->status = 580000;
	pp->alive = gs->tps << 2;
	pp->flaps = 0;
	pp->spoilers = 0;
	pp->rollers = 0;
	pp->rudder = 0;
	pp->elevator = 0;

	pp->ELEVF = pp->ELEVF_CSTE * 10.0f / (20.0f * 400.0f);			/* elevator rate in degrees/sec	*/
	pp->ROLLF = pp->ROLLFF_CSTE  * 10.0f / (30.0f * 400.0f);			/* roll rate (both at 300 mph)	*/

	pp->zdrag = 0.0f;
	pp->ydrag = 0.0f;
	pp->Cdp = .015f;				/* coefficient of parasitic drag*/
	pp->ipi_AR = 1.0f / (M_PI * pp->b * pp->b / pp->s);	/* 1.0 / pi * wing Aspect Ratio	*/
	pp->ie_pi_AR = pp->ipi_AR / pp->ie_pi_AR;		/* 1.0 / pi * AR * efficiency	*/
	pp->Lmax = pp->LmaxDEF * pp->gravity;
	pp->Lmin = pp->LminDEF * pp->gravity;
	pp->wheels = 1;
	pp->Cdp *= 2.0;
	pp->sidewinders = pp->MAX_SW;
	pp->rockets = pp->MAX_RK;
	pp->fuel = 100 << 7;
	pp->gefy = .7f * pp->b;
	pp->thrust = 0;
	pp->tilt_factor = 0.17f;
	pp->roll_speed = 0;
	pp->azimuth_speedf = 0.0f;
	pp->elevation_speedf = 0.0f;
	pp->elevationf = 0.0f;
	pp->inverse_mass = G_ACC / (pp->W + pp->fuel / 12800.0f * pp->fuel_weight);
}
void set_c150(struct gameState* gs, struct plane* pp) {
	
	pp->type = C150;
	
	pp->LmaxDEF = 5.0f;				/* maximum lift before wing breaks */
	pp->LminDEF = -3.0f;			/* minimum lift before wing breaks */
	pp->Fmax = 20.0f;				/* maximum flap deflection	*/
	pp->Smax = 0.0f;				/* maximum spoiler deflection	*/
	pp->ELEVF_CSTE = 75.0f;
	pp->ROLLFF_CSTE = 130.0f;

	pp->obj = C150;
	pp->plane_type = C150_NAME;
	pp->s = 157.0f;				/* wing area in sq. feet	*/
	pp->W = 1000.0f;			/* weight of plane in lbs.	*/
	pp->fuel_weight = 400.0f;
	pp->Mthrust = 300.0f;			/* maximum thrust		*/
	pp->b = 28.0f;				/* wing span in feet		*/
	pp->ie_pi_AR = .80f;			/* efficiency factor		*/
	pp->MAX_RK = 0;
	pp->MAX_SW = 0;
	pp->MIN_LIFT_SPEED = 70;

	pp->pilot_y = 8.0f;
	pp->pilot_z = 18.0f;

	common_plane_init(gs, pp);
	gs->pp = pp;
}
void set_f15(struct gameState* gs, struct plane* pp) {
	
	pp->type = F15;
	pp->LmaxDEF = 8.0f;				/* maximum lift before wing breaks */
	pp->LminDEF = -5.0f;			/* minimum lift before wing breaks */
	pp->Fmax = 30.0f;				/* maximum flap deflection	*/
	pp->Smax = 60.0f;				/* maximum spoiler deflection	*/
	pp->ELEVF_CSTE = 32.0f;
	pp->ROLLFF_CSTE = 140.0f;

	pp->obj = F15;
	pp->plane_type = F15_NAME;
	
	pp->s = 608.0f;				/* wing area in sq. feet	*/
	pp->W = 28000.0f;			/* weight of plane in lbs.	*/
	pp->fuel_weight = 14000.0f;
	pp->Mthrust = 46000.0f;			/* maximum thrust		*/
	pp->b = 43.0f;				/* wing span in feet		*/
	pp->ie_pi_AR = .87f;			/* efficiency factor		*/
	pp->MAX_RK = 0;
	pp->MAX_SW = 0;
	pp->MIN_LIFT_SPEED = 100;

	pp->pilot_y = 10.0f;
	pp->pilot_z = 25.0f;

	common_plane_init(gs, pp);

	gs->pp = pp;
}
void set_b747(struct gameState* gs, struct plane* pp) {
	pp->type = B747;
	pp->LmaxDEF = 4.0f;				/* maximum lift before wing breaks */
	pp->LminDEF = -2.0f;			/* minimum lift before wing breaks */
	pp->Fmax = 50.0f;				/* maximum flap deflection	*/
	pp->Smax = 80.0f;				/* maximum spoiler deflection	*/
	pp->ELEVF_CSTE = 25.0f;
	pp->ROLLFF_CSTE = 50.0f;
	pp->obj = B747;
	pp->plane_type = B747_NAME;
	pp->s = 5500.0f;				/* wing area in sq. feet	*/
	pp->W = 500000.0f;			/* weight of plane in lbs.	*/
	pp->fuel_weight = 100000.0f;
	pp->Mthrust = 200000.0f;			/* maximum thrust		*/
	pp->b = 220.0f;				/* wing span in feet		*/
	pp->ie_pi_AR = .83f;			/* efficiency factor		*/
	pp->MAX_RK = 0;
	pp->MAX_SW = 0;
	pp->MIN_LIFT_SPEED = 200;
	
	pp->pilot_y = 30.0f;
	pp->pilot_z = -92.0f;
	
	common_plane_init(gs, pp);
	gs->pp = pp;
}
void set_f18(struct gameState* gs, struct plane* pp) {
	pp->type = F18;
	pp->LmaxDEF = 9.0f;				/* maximum lift before wing breaks */
	pp->LminDEF = -6.0f;			/* minimum lift before wing breaks */
	pp->Fmax = 50.0f;				/* maximum flap deflection	*/
	pp->Smax = 60.0f;				/* maximum spoiler deflection	*/
	pp->ELEVF_CSTE = 30.0f;
	pp->ROLLFF_CSTE = 100.0f;
	pp->obj = F18;
	pp->plane_type = F18_NAME;
	pp->s = 510.0f;				/* wing area in sq. feet	*/
	pp->W = 24000.0f;			/* weight of plane in lbs.	*/
	pp->fuel_weight = 12000.0f;
	pp->Mthrust = 32000.0f;			/* maximum thrust		*/
	pp->b = 38.0f;				/* wing span in feet		*/
	pp->ie_pi_AR = .90f;			/* efficiency factor		*/
	pp->MAX_RK = 0;
	pp->MAX_SW = 0;
	pp->MIN_LIFT_SPEED = 200;
	
	pp->pilot_y = 10.0f;
	pp->pilot_z = 22.0f;

	common_plane_init(gs, pp);
	gs->pp = pp;
}
void set_f16(struct gameState* gs, struct plane* pp) {
	pp->type = F16;
	pp->LmaxDEF = 10.0f;				/* maximum lift before wing breaks */
	pp->LminDEF = -7.0f;			/* minimum lift before wing breaks */
	pp->Fmax = 40.0f;				/* maximum flap deflection	*/
	pp->Smax = 40.0f;				/* maximum spoiler deflection	*/
	pp->ELEVF_CSTE = 30.0f;
	pp->ROLLFF_CSTE = 100.0f;
	pp->obj = F16;
	pp->plane_type = F16_NAME;
	pp->s = 390.0f;				/* wing area in sq. feet	*/
	pp->W = 18000.0;			/* weight of plane in lbs.	*/
	pp->fuel_weight = 8000.0f;
	pp->Mthrust = 23000.0;			/* maximum thrust		*/
	pp->b = 32.0f;				/* wing span in feet		*/
	pp->ie_pi_AR = .93f;			/* efficiency factor		*/
	pp->MAX_RK = 2;
	pp->MAX_SW = 2;
	pp->MIN_LIFT_SPEED = 120;

	pp->pilot_y = 9.0f;
	pp->pilot_z = 18.0f;
	common_plane_init(gs, pp);
	gs->pp = pp;
}
void set_p38(struct gameState* gs, struct plane* pp) {
	pp->type = P38;
	pp->LmaxDEF = 6.0f;				/* maximum lift before wing breaks */
	pp->LminDEF = -3.5f;			/* minimum lift before wing breaks */
	pp->Fmax = 50.0f;				/* maximum flap deflection	*/
	pp->Smax = 60.0f;				/* maximum spoiler deflection	*/
	pp->ELEVF_CSTE = 30.0f;
	pp->ROLLFF_CSTE = 100.0f;
	pp->obj = P38;
	pp->plane_type = P38_NAME;
	pp->s = 327.5f;				/* wing area in sq. feet	*/
	pp->W = 13500.0;			/* weight of plane in lbs.	*/
	pp->fuel_weight = 1600.0f;
	pp->Mthrust = 4000.0f;			/* maximum thrust		*/
	pp->b = 52.0f;				/* wing span in feet		*/
	pp->ie_pi_AR = .90f;			/* efficiency factor		*/
	pp->MAX_RK = 2;
	pp->MAX_SW = 0;
	pp->MIN_LIFT_SPEED = 75;

	pp->pilot_y = 10.0f;
	pp->pilot_z = 22.0f;
	common_plane_init(gs, pp);
	gs->pp = pp;
}
float fuel_consump(float f, float b) {
	return  0.3f * f / b;
}
void simulation(struct gameState* gs, struct plane* pp, int msx, int msy, int XMIDDLE, int YMIDDLE, int XMAXSCREEN, int YMAXSCREEN) {
	int itemp;
	float temp;
	float elevtemp = 0.0f; 

	gs->tick_counter++;
	if (pp->status > MEXPLODE) {
		/* tenths of degrees per tick	*/
		pp->rollers = (pp->ROLLF * ((msx - XMIDDLE + 8) >> 4) );
		itemp = (int) (pp->rollers * pp->vz - pp->roll_speed);	/* delta	*/
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
		pp->elevator = -1.0f*(pp->ELEVF * ((msy - YMIDDLE + 8) >> 4));
		itemp = (int)(pp->elevator * pp->vz + pp->vy - pp->elevation_speedf);
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
			itemp += mrandom(pp->wing_stall *2);
			elevtemp += mrandom(pp->wing_stall * 2);
		}
		pp->elevation_speedf += itemp;
		float aztemp;
		temp = pp->rudder * pp->vz - (2.0f*gs->tps/20.0f) * pp->vx;
		if (pp->on_ground) {
			itemp = (int)(16.0f * temp);
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
						temp = (float) itemp;
					}
					itemp -= (int)temp;
				}
			}
			temp = (float)itemp;
		} else {
			itemp = (int)temp;	/* itemp is desired azimuth speed	*/
		}
		
		aztemp = temp;
		/* itemp is now desired-actual		*/
		itemp -= (int) pp->azimuth_speedf;	
		aztemp -= pp->azimuth_speedf;
		if (itemp != 0) {
			if (itemp >= DELAY || itemp <= -DELAY) {
				itemp /= DELAY;
			}
			else {
				itemp = itemp > 0 ? 1 : -1;
			}
		}
		pp->azimuth_speedf += itemp;
		if (pp->on_ground) {
			/* dont allow negative pitch unless positive elevation	*/
			if (pp->elevation_speedf < 0) {
				if (pp->elevationf <= 0) {
					pp->elevation_speedf = 0;
				}
			}
			else {		
				/* mimic gravitational torque	*/
				elevtemp = -(pp->vz * gs->tps + pp->MIN_LIFT_SPEED) / 4.0f;
				if (elevtemp < 0 && pp->elevationf <= 0) {
					elevtemp = 0.0f;
				}
				if (pp->elevation_speedf > elevtemp) {
					pp->elevation_speedf = elevtemp;
				}
			}
			pp->roll_speed = 0;
		}

		/****************************************************************
		/*	concat incremental rotations and get new angles back
		/****************************************************************/
		if (gs->tick_counter%100 == 1) {
			// rebuild old ptw	
			// to keep it normalized
			setIdentity(pp->ptw);
			translateM(pp->ptw, pp->x, pp->y, pp->z);	
			rotateM(pp->ptw, pp->azimuthf, 0, 1, 0);
			rotateM(pp->ptw, pp->elevationf, 1, 0, 0);
			rotateM(pp->ptw, pp->twist, 0, 0, 1);
		}
		translateM(pp->ptw, pp->vx, pp->vy, pp->vz);
		if (round(pp->azimuth_speedf) != 0) rotateM(pp->ptw, round(pp->azimuth_speedf), 0, 1, 0);
		if (round(pp->elevation_speedf) != 0) rotateM(pp->ptw, round(pp->elevation_speedf), 1, 0, 0);
		if (round(pp->roll_speed) != 0) rotateM(pp->ptw, round(pp->roll_speed), 0, 0, 1);


		/* analyze new ptw	*/
		temp = 0.0f;
		pp->elevationf = -asinf(pp->ptw[2][1]) / M_PI *1800.0f;
		
		float ascos = 0.0f;

		temp = cosf(pp->elevationf / 1800.0f * M_PI);
		
		if (temp != 0.0) {
			
			float sincosas = pp->ptw[2][0] / temp;

			if (sincosas > 1) {
				sincosas = 1.0f;
			}
			else if (sincosas < -1) {
				sincosas = -1;
			}
			pp->azimuthf = asinf(sincosas) / M_PI * 1800.0f;
			if (pp->ptw[2][2] < 0.0) {
				/* if heading into z	*/
				
				pp->azimuthf = 1800 - pp->azimuthf;	
			}	
			if (pp->azimuthf < 0) {
				/* then adjust		*/
				pp->azimuthf += 3600;
			}

			pp->twist = asinf(pp->ptw[0][1] / temp) / M_PI * 1800.0f;
 			if (pp->ptw[1][1] < 0.0) {
				/* if upside down	*/
				pp->twist = 1800 - pp->twist;
			}
			if (pp->twist < 0) {
				pp->twist += 3600;
			}
		}
		/* save last position	*/
		pp->last_px = pp->x;			
		pp->last_py = pp->y;
		pp->last_pz = pp->z;
		pp->x = pp->ptw[3][0];
		pp->y = pp->ptw[3][1];
		pp->z = pp->ptw[3][2];
		
		//printf("az [%f] el [%f]  tw [%d] x [%f]  y [%f]  z [%f] \n", pp->azimuthf, pp->elevationf, pp->twist, pp->x, pp->y, pp->z);

		/****************************************************************
		/*	perform incremental rotations on velocities
		/****************************************************************/

		setIdentity(pp->incremental);
		if (pp->roll_speed) rotateM(pp->incremental, -pp->roll_speed, 0, 0, 1);
		if (pp->elevation_speedf) rotateM(pp->incremental, -pp->elevation_speedf, 1, 0, 0);
		if (pp->azimuth_speedf) rotateM(pp->incremental, -pp->azimuth_speedf, 0, 1, 0);
		translateM(pp->incremental, pp->vx, pp->vy, pp->vz);


		pp->vx = pp->incremental[3][0];
		pp->vy = pp->incremental[3][1];
		pp->vz = pp->incremental[3][2];

		/****************************************************************/
		/*	check altitude for too high, and landing/takeoff            */
		/****************************************************************/
		/* flame out		*/
		if (pp->y > 50000.0) pp->thrust = 0;	
		else if (pp->y > gs->groundlevel + 4.0) {
			/* not on ground	*/
			
			if (pp->on_ground) {
				/* if was on ground	*/
				/* clear report card	*/
				clear_report_card();	
				/* decrease drag	*/
				pp->Cdp /= 3.0;	
				/* no reverse engines	*/
				pp->min_throttle = 0;		
			}
			pp->on_ground = FALSE;
		}
		else if (pp->y < gs->groundlevel) {
			/* check for on the ground */
			if (gs->nocrash == 0) {
				if (IN_BOX(pp, -800.0, 100.0, -9500.0, 1000.0) ||
					IN_BOX(pp, 100.0, 1300.0, -2500.0, -1500.0) ||
					IN_BOX(pp, -2300.0, -800.0, -4900.0, -2000.0) ||
					isOnRunWay(pp))
					/* and not on ground before */
					if (!pp->on_ground) {
						int rating;
						/* increase drag	*/
						pp->Cdp *= 3.0;
						/* allow reverse engines*/
						pp->min_throttle = -pp->max_throttle;
						rating = report_card(-pp->climbspeed, pp->twist, (int)(pp->vx * gs->tps), (int)(-pp->vz * pp->fps_knots), pp->wheels, pp);
						/* oops - you crashed	*/
						if (rating == -1) {
							/* set to exploding	*/
							pp->status = MEXPLODE;
							/* increment count	*/
							pp->lost++;
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
					make_crash("You crashed into the swamps", pp);
					//broadcast("crashed into the swamps");
				}
			}
			pp->ptw[3][1] = pp->y = gs->groundlevel;
			pp->on_ground = TRUE;
			if (pp->status > MEXPLODE) {
				/* kill negative elevation */
				if (pp->elevationf < 0) {
					pp->elevationf = 0;
				}
				/* kill any twist	*/
				if (pp->twist != 0) {
					pp->twist = 0;
				}
			}
		}
	}	/* end not crashing	*/



	/****************************************************************
	/*	compute new velocities, accelerations
	/****************************************************************/
	
	/* out of gas	*/
	if (pp->fuel <= 0) {		
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
			if (pp->kl > .225f ) {
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
			/* check for positive stall	*/
			if (pp->Cl > pp->max_cl) {		
				pp->Cl = 3.0f * pp->max_cl - 2.0f * pp->Cl;
				pp->wing_stall = 1;
				if (pp->Cl < 0.0f) {
					pp->wing_stall += 1 - (int)(pp->Cl / pp->max_cl);
					pp->Cl = 0.0f;
				}
				if (pp->uCl > 5.0f) {
					pp->uCl = 5.0f;
				}
				
			}
			else if (pp->Cl < pp->min_cl) {	
				/* check for negative stall	*/
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
		if ((gs->tick_counter & 1) == 0) {	
			/* only do on even ticks	*/
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
			else if (itemp < 0) {
				itemp = 0;
			}
			pp->ro2 = .5f * ro[itemp];
			if (pp->Cl < .2) {
				pp->mcc = .7166666f + .1666667f * pp->Cl;
			}
			else {
				pp->mcc = .7833333f - .1666667f * pp->Cl;
			}
			/* and current mach number	*/
			pp->mach = pp->vz / pp->sos;		
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

		/* assume V approx = vz	*/
		pp->qs = pp->ro2 * pp->vz * pp->s;		

		pp->lift = pp->Cl * pp->qs;
		pp->g_limit = FALSE;
		if (pp->spoilers > 0) {
			pp->lift *= pp->Splf;
		}
	relift:
		pp->ay = pp->vz * pp->lift;
		pp->az = -pp->vy * pp->lift;
		/* save for wing loading meter	*/
		pp->lift = pp->ay * pp->inverse_mass;	
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
		/* if vz is positive	*/
		if (pp->val) {			
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
			gl_sincos(pp->elevationf, &temp, &mcos);
			temp = pp->vz * temp / mcos;
			if (pp->vy + pp->ay < temp) {
				pp->ay = temp - pp->vy;
			}
		}
		pp->vy += pp->ay;

		pp->airspeed = -(int)(pp->fps_knots * pp->vz);
		pp->climbspeed = gs->tps * (pp->y - pp->last_py);


		pp->vx += gs->vx_add;
		pp->vy += gs->vy_add;
		pp->vz += gs->vz_add;
		if (pp->thrust > 0) {
			itemp = pp->thrust;
		}
		else {
			itemp = -pp->thrust;
		}
		if (gs->tick_counter%(100*TPS) == 1) {
			pp->fuel_rate = fuel_consump(pp->Mthrust, pp->W);
			pp->fuel -= (int)(itemp * pp->fuel_rate);
			pp->inverse_mass = G_ACC / (pp->W + pp->fuel / 12800.0f * pp->fuel_weight);
		}
	}
}
void draw_game_sc(gameState * gs, plane *pp) {
	if (gs->light) {

		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_LIGHTING);
	}
	glPolygonMode(GL_FRONT_AND_BACK, gs->polymod);
	glCallList(SC_WORLD - 1);
	glCallList(SC_WORLD);

	switch (gs->view_switch) {
	case PILOTE:
		glLoadIdentity();
		glCallList(CROSS_HAIRS);
		glPopMatrix();
		glRotatef(-gs->view_angle, 0, 1, 0);
		glTranslatef(0, -pp->pilot_y, pp->pilot_z);
		glRotatef(-(pp->twist / 10.0), 0.0, 0.0, 1.0);
		glRotatef(-(pp->elevationf / 10.0), 1.0, 0.0, 0.0);
		glRotatef(-(pp->azimuthf / 10.0), 0.0, 1.0, 0.0);
		glTranslatef(-pp->x, -pp->y, -pp->z);

		break;
	case WINGMAN:

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glTranslatef(pp->x, pp->y, pp->z);
		glRotatef(pp->azimuthf / 10.0, 0, 1, 0);
		glRotatef(pp->elevationf / 10.0, 1, 0, 0);
		glRotatef(pp->twist / 10.0, 0, 0, 1);
		glCallList(pp->obj);
		glDisable(GL_DEPTH_TEST);
		glLoadIdentity();


		glTranslatef(0, -20.0f, -100.0f);
		glRotatef(-(pp->twist / 10.0), 0.0, 0.0, 1.0);
		glRotatef(-(pp->elevationf / 10.0), 1.0, 0.0, 0.0);
		glRotatef(-(pp->azimuthf / 10.0), 0.0, 1.0, 0.0);
		glTranslatef(-pp->x, -pp->y, -pp->z);

		glPopMatrix();
		break;
	case TOWER:



		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glTranslatef(pp->x, pp->y, pp->z);
		glRotatef((pp->azimuthf / 10.0), 0.0, 1.0, 0.0);
		glRotatef((pp->elevationf / 10.0), 1.0, 0.0, 0.0);
		glRotatef((pp->twist / 10.0), 0.0, 0.0, 1.0);
		glCallList(pp->obj);
		glDisable(GL_DEPTH_TEST);

		glLoadIdentity();

		gluLookAt(gs->tx, gs->ty, gs->tz, pp->x, pp->y, pp->z, 0, 1, 0);
		glPopMatrix();
		break;
	case FREE:
		free_camera(gs);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glTranslatef(pp->x, pp->y, pp->z);
		glRotatef((pp->azimuthf / 10.0), 0.0, 1.0, 0.0);
		glRotatef((pp->elevationf / 10.0), 1.0, 0.0, 0.0);
		glRotatef((pp->twist / 10.0), 0.0, 0.0, 1.0);
		glCallList(pp->obj);
		draw_plane_speed_vector(gs, pp);
		glDisable(GL_DEPTH_TEST);



		glLoadIdentity();

		gluLookAt(pp->x + gs->eyes.x, pp->y + gs->eyes.y, pp->z + gs->eyes.z, pp->x, pp->y, pp->z, 0, 1, 0);
		glPopMatrix();
		break;
	}
	if (gs->light) {

		glDisable(GL_COLOR_MATERIAL);
		glDisable(GL_LIGHTING);
	}
}
void draw_game(gameState * gs, plane *pp) {


	

	glPolygonMode(GL_FRONT_AND_BACK, gs->polymod);

	glDisable(GL_DEPTH_TEST);
	if (gs->light) {
		init_light(10000.0f);
		glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	}
	glCallList(WORLD_OBJECT);
	glCallList(RUNWAY_STRIPES);
	glCallList(LIGHTS);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glPushMatrix();
	glTranslatef(-10000, 1000, -1000);
	glCallList(TEXTCUBE);
	glPopMatrix();
	draw_buildings(0, 0, 0, 0, 0, gs);
	glPushMatrix();
	glTranslatef(120000, 0, 100000);
	glScalef(300, 100, 220);
	if (gs->textures) {
		glEnable(GL_TEXTURE_2D);
	}
	glCallList(MYMOUNTAIN);
	if (gs->textures) {
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(120000, 0, 140000);
	glRotatef(180, 0, 1, 0);
	glScalef(300, 100, 220);
	if (gs->textures) {
		glEnable(GL_TEXTURE_2D);
	}
	glCallList(MYMOUNTAIN);
	if (gs->textures) {
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();
	if (gs->light) {
		glDisable(GL_LIGHTING);
	}
	draw_shadow(pp, 1);
	if (gs->light) {
		glEnable(GL_LIGHTING);
	}
	draw_vasi(pp);

	switch (gs->view_switch) {
	case PILOTE:
		glLoadIdentity();
		glCallList(CROSS_HAIRS);
		glPopMatrix();
		glRotatef(-gs->view_angle, 0, 1, 0);
		glTranslatef(0, -pp->pilot_y, pp->pilot_z);
		glRotatef(-(pp->twist / 10.0), 0.0, 0.0, 1.0);
		glRotatef(-(pp->elevationf / 10.0), 1.0, 0.0, 0.0);
		glRotatef(-(pp->azimuthf / 10.0), 0.0, 1.0, 0.0);
		glTranslatef(-pp->x, -pp->y, -pp->z);

		break;
	case WINGMAN:

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glTranslatef(pp->x, pp->y, pp->z);
		glRotatef(pp->azimuthf / 10.0, 0, 1, 0);
		glRotatef(pp->elevationf / 10.0, 1, 0, 0);
		glRotatef(pp->twist / 10.0, 0, 0, 1);
		glCallList(pp->obj);
		glDisable(GL_DEPTH_TEST);
		glLoadIdentity();


		glTranslatef(0, -20.0f, -100.0f);
		glRotatef(-(pp->twist / 10.0), 0.0, 0.0, 1.0);
		glRotatef(-(pp->elevationf / 10.0), 1.0, 0.0, 0.0);
		glRotatef(-(pp->azimuthf / 10.0), 0.0, 1.0, 0.0);
		glTranslatef(-pp->x, -pp->y, -pp->z);

		glPopMatrix();
		break;
	case TOWER:



		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glTranslatef(pp->x, pp->y, pp->z);
		glRotatef((pp->azimuthf / 10.0), 0.0, 1.0, 0.0);
		glRotatef((pp->elevationf / 10.0), 1.0, 0.0, 0.0);
		glRotatef((pp->twist / 10.0), 0.0, 0.0, 1.0);
		glCallList(pp->obj);
		glDisable(GL_DEPTH_TEST);

		glLoadIdentity();

		gluLookAt(gs->tx, gs->ty, gs->tz, pp->x, pp->y, pp->z, 0, 1, 0);
		glPopMatrix();
		break;
	case FREE:
		free_camera(gs);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glTranslatef(pp->x, pp->y, pp->z);
		glRotatef((pp->azimuthf / 10.0), 0.0, 1.0, 0.0);
		glRotatef((pp->elevationf / 10.0), 1.0, 0.0, 0.0);
		glRotatef((pp->twist / 10.0), 0.0, 0.0, 1.0);
		glCallList(pp->obj);
		draw_plane_speed_vector(gs, pp);
		glDisable(GL_DEPTH_TEST);



		glLoadIdentity();

		gluLookAt(pp->x + gs->eyes.x, pp->y + gs->eyes.y, pp->z + gs->eyes.z, pp->x, pp->y, pp->z, 0, 1, 0);
		glPopMatrix();
		break;
	}
	if (gs->light) {
		
		glDisable(GL_COLOR_MATERIAL);
		glDisable(GL_LIGHTING);
	}
}

void draw_plane_speed_vector(gameState *gs, plane *pp) {
	if (gs->debug) {
		setColor(red);
		glBegin(GL_LINE_STRIP);
		glVertex3f(0, 0, 0);
		glVertex3f(0, pp->ay * 1000, 0);
		glEnd();
		glBegin(GL_LINE_STRIP);
		setColor(cyan);
		glVertex3f(0, 0, 0);
		glVertex3f(pp->ax * 1000, 0, 0);
		glEnd();
		glBegin(GL_LINE_STRIP);
		setColor(purple0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, pp->az * 10000);
		glEnd();
		glBegin(GL_LINE_STRIP);
		setColor(orange);
		glVertex3f(0, 0, 0);
		glVertex3f(pp->ax * 1000, pp->ay * 1000, pp->az * 1000);
		glEnd();
	}
}

void draw_debug_text(gameState *gs, plane *pp, int msx, int msy) {
	unsigned char string[255];
	float temp;
	if (glIsList(DEBUG_TEXT)) {
		glDeleteLists(DEBUG_TEXT, 1);
	}

	glNewList(DEBUG_TEXT, GL_COMPILE);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();   // save
	glLoadIdentity(); // and clear
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	float ystart = 0.95f;
	int airspeed = -(int)(pp->fps_knots * pp->vz);
	setColor(white);
	sprintf(string, "tick: %d, FPS: %f TPS: %d DELAY: %d ELEVF:%f", gs->ticks, gs->fps, gs->tps, DELAY, pp->ELEVF);
	gl_print(string, -1.0, ystart -= .05);

	sprintf(string, "mx : %d; my: %d", msx, msy);
	gl_print(string, -1.0, ystart -= .05);

	sprintf(string, "flight [roller:%f, elevator:%f, rudder:%f] [%f %f]", pp->rollers, pp->elevator, pp->rudder, pp->ROLLF, pp->ELEVF);
	gl_print(string, -1.0, ystart -= .05);
	temp = pp->inverse_mass * gs->tps * gs->tps;

	sprintf(string, "Position (xyz): %12.2f%12.2f%12.2f    %s", pp->x, pp->y, pp->z, pp->on_ground ? "*** ON THE GROUND" : "");
	gl_print(string, -1.0, ystart -= .05);

	sprintf(string, "Elevation, azimuth, roll: %f %f %6d", pp->elevationf, pp->azimuthf, pp->twist);
	gl_print(string, -1.0, ystart -= .05);

	sprintf(string, "Elev, azim, roll speeds: %f %f %6d", pp->elevation_speedf, pp->azimuth_speedf, pp->roll_speed);
	gl_print(string, -1.0, ystart -= .05);

	sprintf(string, "Rotated velocities per tick: %9.2f%9.2f%9.2f", pp->incremental[3][0] * gs->tps, pp->incremental[3][1] * gs->tps, pp->incremental[3][2] * gs->tps);
	sprintf(string, "Speed-of-sound:%8.1f  Mach:%5.2f  Mcc:%5.2f  Mach/Mcc:%5.2f", -pp->sos * gs->tps, pp->mach, pp->mcc, pp->mratio);
	gl_print(string, -1.0, ystart -= .05);

	sprintf(string, "Cd:%8.4f=%7.4f +%7.4f +%7.4f  (p+i+c)", pp->Cd, pp->Cdp, pp->kl * pp->uCl * pp->uCl * pp->ie_pi_AR, pp->Cdc);
	gl_print(string, -1.0, ystart -= .05);

	sprintf(string, "Cl:%5.2f  kl:%5.2f  ro2:%7.4f  qs:%6.2f", pp->Cl, pp->kl, pp->ro2, pp->qs);
	gl_print(string, -1.0, ystart -= .05);

	sprintf(string, "Thrust:   %21.2f | %21.2f", -.01 / gs->tps / gs->tps * pp->thrust * pp->Mthrust, .01 * pp->thrust * pp->Mthrust * pp->inverse_mass * gs->tps *gs->tps);
	gl_print(string, -1.0, ystart -= .05);

	if (pp->spoilers > 0) {
		pp->qs *= pp->Splf;
	}
	sprintf(string, "Lift:     %14.2f%7.2f        angle:%6.2f", pp->vz * pp->Cl * pp->qs * temp, -pp->vy * pp->Cl * pp->qs * temp, 57.3 * (pp->ae - pp->tilt_factor));
	gl_print(string, -1.0, ystart -= .05);

	sprintf(string, "Drag:     %14.2f%7.2f", pp->ydrag * temp, pp->zdrag * temp);
	gl_print(string, -1.0, ystart -= .05);

	sprintf(string, "Gravity:  %7.2f%7.2f%7.2f", pp->ptw[0][1] * -G_ACC, pp->ptw[1][1] * -G_ACC, pp->ptw[2][1] * -G_ACC);
	sprintf(string, "-------------------------------   Mass: %g", G_ACC / pp->inverse_mass);
	gl_print(string, -1.0, ystart -= .05);

	sprintf(string, "Totals:   %7.2f%7.2f%7.2f", pp->ax * gs->tps * gs->tps, pp->ay * gs->tps * gs->tps, pp->az * gs->tps * gs->tps);
	gl_print(string, -1.0, ystart -= .05);

	sprintf(string, "New velocities per tick: %9.2f%9.2f%9.2f", pp->vx, pp->vy, pp->vz);
	gl_print(string, -1.0, ystart -= .05);

	sprintf(string, "Wing_stall = %d", pp->wing_stall);
	gl_print(string, -1.0, ystart -= .05);

	sprintf(string, "airspeed = %d, climbespeed = %d", airspeed, pp->climbspeed);
	gl_print(string, -1.0, ystart -= .05);

	sprintf(string, "gravity = %f, ay = %f", pp->gravity, pp->ay);
	gl_print(string, -1.0, ystart -= .05);

	sprintf(string, "%s", "ptw");
	gl_print(string, -1.0, ystart -= .05);
	for (int o = 0; o < 4; o++) {
		sprintf(string, "PTW[%d]=[%f,%f,%f,%f]", o, pp->ptw[o][0], pp->ptw[o][1], pp->ptw[o][2], pp->ptw[o][3]);
		gl_print(string, -1.0, ystart -= .05);
	}

	sprintf(string, "%s", "incremental");
	gl_print(string, -1.0, ystart -= .05);
	for (int o = 0; o < 4; o++) {
		sprintf(string, "INC[%d]=[%f,%f,%f,%f]", o, pp->incremental[o][0], pp->incremental[o][1], pp->incremental[o][2], pp->incremental[o][3]);
		gl_print(string, -1.0, ystart -= .05);
	}
	sprintf(string, "drag param : cdp=%f kl=%f ucl=%f ie_pi_ar=%f cdc=%f", pp->Cdp, pp->kl, pp->uCl, pp->ie_pi_AR, pp->Cdc);
	gl_print(string, -1.0, ystart -= .05);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEndList();
}