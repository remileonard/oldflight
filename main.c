#include "main.h"

void free_memory() {
	if (lpp != NULL) {
		free(lpp);
		lpp = NULL;
	}
}
void mouse_mouve(int x, int y) {
	
	if (lgs != NULL) {
		switch (lgs->sts) {
		case PRESENTATION:
			break;
		case OBJECTVIEWER:
			if (moveok) {
				msdx = x - msx;
				msdy = y - msy;
				lgs->cyaw += msdx * 0.5;
				lgs->cpitch -= msdy * 0.5;
			}
			if (zoomok) {
				msdy = y - msy;
				lgs->objz -= msdy * 0.5;
			}
			//glutPostRedisplay();
			break;
		case SIMULATION:
			break;
		}
	}
	msx = x;
	msy = y;
}
void mouse_click(int button, int state, int x, int y) {
	switch(lgs->sts) {
	case OBJECTVIEWER:
		switch (button) {
		case GLUT_RIGHT_BUTTON:
			zoomok = (state == GLUT_DOWN);
			break;
		case GLUT_LEFT_BUTTON:
			moveok = (state == GLUT_DOWN);
			break;
		}
		break;
	case SIMULATION:
		switch (button) {
		case GLUT_RIGHT_BUTTON:
			lpp->rudder += .1f;
			break;
		case GLUT_MIDDLE_BUTTON:
			lpp->rudder = 0.0f;
			break;
		case GLUT_LEFT_BUTTON:
			lpp->rudder -= .1f;
			break;
		}
		break;
	}
}

void draw_presentation(void) {
	float ystart = YMAXSCREEN - 10.0f;
	unsigned char string[255];

	glClearColor(0.2f, 0.2f, 0.8f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	/**/
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glLoadIdentity();
	glTranslatef(XMAXSCREEN / 2.0f, YMAXSCREEN / 2.0f - 200, 0.0f);
	glRotatef(90, 1, 1, 1);
	glEnable(GL_LIGHTING);
	glRotatef(-30, 0, 0, 1);
	glRotatef(logorotate += 0.1f, 1, 0, 0);
	glScalef(10.0f, 10.0f, 10.0f);
	draw_logo();
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	int w;
	w = glutBitmapLength(GLUT_BITMAP_8_BY_13, string);
	if (message == 1) {
		for (int u = 0; u < 24; u++) {
			sprintf(string, "%s", helpmsg[u]);
			gl_print(string, XMAXSCREEN / 2 - 350, ystart -= 13.0);
		}
	}
	else {
		for (int u = 0; u < 24; u++) {
			sprintf(string, "%s", plane_menu[u]);
			gl_print(string, XMAXSCREEN / 2 - 350, ystart -= 13.0);
		}
	}

	 glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	 glRasterPos2i(XMAXSCREEN - 400, 64);
	 //glGetFloatv(GL_CURRENT_RASTER_POSITION_VALID, c);
	// 354x92px
	 glBitmap(354, 92, 0, 0, 0.0, 0, sgi);

	glFlush();

	glutSwapBuffers();
}
void reshape_3d(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // Reset first
	gluPerspective(lgs->real_fov, (double)width / (double)height, 1.0f, 1.0e9);           // Set perspective
	glViewport(0, 0, width, height); // Set viewport
	glMatrixMode(GL_MODELVIEW);
	XMAXSCREEN = width;
	YMAXSCREEN = height;
	XMIDDLE = XMAXSCREEN / 2;
	YMIDDLE = YMAXSCREEN / 2;
	X_ADJUST = XMAXSCREEN / 1024.0;
	Y_ADJUST = YMAXSCREEN / 768.0;
}
void reshape_2d(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height); // Set viewport
	glOrtho(0, width, 0, height, -1000.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	XMAXSCREEN = width;
	YMAXSCREEN = height;
	XMIDDLE = XMAXSCREEN / 2;
	YMIDDLE = YMAXSCREEN / 2;
	X_ADJUST = XMAXSCREEN / 1024.0;
	Y_ADJUST = YMAXSCREEN / 768.0;
}
void special_key(int k, int x, int y) {
	switch (k) {
	case GLUT_KEY_LEFT:
		if (lgs->view_switch == PILOTE) {
			lgs->view_angle = 90.0f;
		}
		else {
			lgs->eyes.x -= 10.0f;
		}
		
		break;
	case GLUT_KEY_RIGHT:
		if (lgs->view_switch == PILOTE) {
			lgs->view_angle = 270.0f;
		}
		else {
			lgs->eyes.x += 10.0f;
		}
		break;
	case GLUT_KEY_UP:
		if (lgs->view_switch == PILOTE) {
			lgs->view_angle = 0.0f;
		}
		else {
			lgs->eyes.z -= 10.0f;
		}
		break;
	case GLUT_KEY_DOWN:
		if (lgs->view_switch == PILOTE) {
			lgs->view_angle = 180.0f;
		}
		else {
			lgs->eyes.z += 10.0f;
		}
		break;
	case GLUT_KEY_F1:
		lgs->fog = !lgs->fog;
		if (lgs->fog) {
			glEnable(GL_FOG);
			GLfloat fogcolor[4] = { 0.5, 0.5, 0.5, 1 };
			GLint fogmode = GL_EXP;
			glFogi(GL_FOG_MODE, fogmode);
			glFogfv(GL_FOG_COLOR, fogcolor);
			glFogf(GL_FOG_DENSITY, 0.000007);
			glFogf(GL_FOG_START, 10.0);
			glFogf(GL_FOG_END, 5.0);
		}
		else {
			glDisable(GL_FOG);
		}
		break;
	case GLUT_KEY_F2:
		lgs->light = !lgs->light;
		break;
	case GLUT_KEY_F3:
		lgs->textures = !lgs->textures;
		break;
	case GLUT_KEY_F11:
		if (!fullscreen) {
			glutFullScreen();
		}
		else {
			glutPositionWindow(100, 50);
			glutReshapeWindow(XWIDTH, YHEIGHT);
		}
		fullscreen = !fullscreen;
	}
}
void simul_key(unsigned char k, int x, int y) {
	switch (k) {
	case 27:
		init_presentation(1);
		break;
	case 'r':
	case 'R':
	case 'u':
	case 'U':
		init_presentation(0);
		break;
	default:
		handle_key(k, lgs, lpp);
		break;
	}
}
void object_viewer_key(unsigned char k, int x, int y) {
	switch (k) {
	case 27:
		/* Escape */
		init_presentation(0);
		break;
	case 32:

		break;
	case '+':
		cz += 5;
		break;
	case '-':
		cz -= 5;
		break;
	case '1':
		object3Dview = C150;
		break;
	case '2':
		object3Dview = B747;
		break;
	case '3':
		object3Dview = F15;
		break;
	case '4':
		object3Dview = F16;
		break;
	case '5':
		object3Dview = F18;
		break;
	case '6':
		object3Dview = P38;
		break;
	case '7':
		object3Dview = HOUSE;
		break;
	case '8':
		object3Dview = 8000;
		break;
	case '9':
		object3Dview = TREE;
		break;
	case 'a':
		object3Dview = TEXTCUBE;
		break;
	case 'z':
		object3Dview = MYMOUNTAIN;
		break;
	case 'e':
		object3Dview = SC_WORLD;
		break;
	case 'r':
		object3Dview++;
		printf("%d, SC[%d]\n", object3Dview, object3Dview-SC_WORLD-1);
		break;
	case 't':
		object3Dview--;
		printf("%d, SC[%d]\n", object3Dview, object3Dview - SC_WORLD-1);
		break;
	case ':':
		lgs->polymod = GL_FILL;

		break;
	case '!':
		lgs->polymod = GL_LINE;

		break;
	case ';':
		lgs->polymod = GL_POINT;
		break;
	}
	//glutPostRedisplay();
}
void object_special_viewerKey(int k, int x, int y) {
	switch (k) {
	case GLUT_KEY_LEFT:
		lgs->cyaw += 5;
		break;
	case GLUT_KEY_RIGHT:
		lgs->cyaw -= 5;
		break;
	case GLUT_KEY_UP:
		lgs->cpitch += 5;
		break;
	case GLUT_KEY_DOWN:
		lgs->cpitch -= 5;
		break;
	case GLUT_KEY_F11:
		glutFullScreen();
		break;
	}
}
void presentation_key(unsigned char k, int x, int y) {
	switch (k) {
	case 27:
		/* Escape */
		exit(0);
		break;
	case 32:
		message = !message;
		break;
	case '0':
		init_3D_viewer(0);
		break;
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
		init_game(k);
		break;
	case 's':
		init_strike_commander(k);
		break;
	}
}
void get_time() {
	
	int zetimer = glutGet(GLUT_ELAPSED_TIME);
	int timeelapsed = zetimer - lgs->timer +1;
	if (lgs->ticks == 20) {
		float realtps = lgs->ticks / (timeelapsed/1000.0f);
		frames = realtps / 20;
		lgs->fps = realtps;
		lgs->ticks = 0;
		lgs->timer = zetimer;
	}
}
void idle(void) {
	
}
void idleViewer(void) {
	glutPostRedisplay();
}
void visible(int vis) {
	if (vis == GLUT_VISIBLE)
		glutIdleFunc(NULL);
	else
		glutIdleFunc(NULL);
}


void strike_commander(int va) {
	int zetimer1, zetimer2;
	if (lgs->sts == SIMULATION) {
		lgs->ticks++;
		zetimer1 = glutGet(GLUT_ELAPSED_TIME);
		simulation(lgs, lpp, msx, msy, XMIDDLE, YMIDDLE, XMAXSCREEN, YMAXSCREEN);
		lgs->groundlevel =  getY(lpp->x, lpp->z);
		setClearColor(grey12);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		lgs->vx_add = lgs->vy_add = lgs->vz_add = 0.0;
		if (!lgs->hud) {
			draw_cockpit(lpp, halftone, XMAXSCREEN, YMAXSCREEN, X_ADJUST, Y_ADJUST);
			glCallList(COCKPIT);

			int w = XMAXSCREEN - 1;
			int h = YMAXSCREEN / 2 - 1;
			set_view_screen(lgs->real_fov, w, h, h);
			draw_game_sc(lgs, lpp);
		}
		else {
			set_view_screen(lgs->real_fov, XMAXSCREEN, YMAXSCREEN, 0);

			draw_game_sc(lgs, lpp);

			if (lgs->debug) {
				draw_debug_text(lgs, lpp, msx, msy);
				glCallList(DEBUG_TEXT);
			}
			else {
				draw_hud(lgs, lpp, XMAXSCREEN, YMAXSCREEN, X_ADJUST, Y_ADJUST);
				glCallList(HUD);
			}



			glCallList(REPORT_CARD);


		}
		draw_mouse_cursor(XMAXSCREEN, YMAXSCREEN, msx, msy);
		glFlush();
		glutSwapBuffers();
		zetimer2 = glutGet(GLUT_ELAPSED_TIME);
		//printf("time simul and render %d %d \n", zetimer2 - zetimer1, (1000 / lgs->tps) - (zetimer2 - zetimer1));
		get_time();
		glutTimerFunc(fabs((1000 / lgs->tps) - (zetimer2 - zetimer1)), strike_commander, va);
	}
}

void flight_simulation(int va) {
	int zetimer1, zetimer2;
	if (lgs->sts == SIMULATION) {
		lgs->ticks++;
		zetimer1 = glutGet(GLUT_ELAPSED_TIME);
		simulation(lgs, lpp, msx, msy, XMIDDLE, YMIDDLE, XMAXSCREEN, YMAXSCREEN);
		setClearColor(grey12);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		lgs->vx_add = lgs->vy_add = lgs->vz_add = 0.0;
		if (!lgs->hud) {
			draw_cockpit(lpp, halftone, XMAXSCREEN, YMAXSCREEN, X_ADJUST, Y_ADJUST);
			glCallList(COCKPIT);
			
			int w = XMAXSCREEN - 1;
			int h = YMAXSCREEN / 2 - 1;
			set_view_screen(lgs->real_fov, w, h, h);
			draw_game(lgs,lpp);
		}
		else {
			set_view_screen(lgs->real_fov, XMAXSCREEN, YMAXSCREEN, 0);
			
			draw_game(lgs, lpp);

			if (lgs->debug) {
				draw_debug_text(lgs,lpp, msx,msy);
				glCallList(DEBUG_TEXT);
			}
			else {
				draw_hud(lgs,lpp, XMAXSCREEN, YMAXSCREEN, X_ADJUST, Y_ADJUST);
				glCallList(HUD);
			}
			
			

			glCallList(REPORT_CARD);
			
			
		}
		draw_mouse_cursor(XMAXSCREEN, YMAXSCREEN, msx, msy);
		glFlush();
		glutSwapBuffers();
		zetimer2 = glutGet(GLUT_ELAPSED_TIME);
		//printf("time simul and render %d %d \n", zetimer2 - zetimer1, (1000 / lgs->tps) - (zetimer2 - zetimer1));
		get_time();
		glutTimerFunc(fabs((1000 / lgs->tps) - (zetimer2 - zetimer1)) , flight_simulation, va);
	}
}
void flight_demo_simulation(int va) {
	if (lgs->sts == DEMONSTRATION) {
		lgs->ticks++;
		lpp->thrust = demo[demoCounter].throttle;
		msx = demo[demoCounter].msx * ((float)XMAXSCREEN / (XWIDTH * 1.0f));
		msy = demo[demoCounter].msy * ((float)YMAXSCREEN / (YHEIGHT * 1.0f));
		/* adjust drag and lift	*/
		lpp->spoilers = demo[demoCounter].spoilers;
		lpp->Spdf = .0025 * lpp->spoilers;
		lpp->Splf = 1.0 - .005 * lpp->spoilers;

		lpp->flaps = demo[demoCounter].flaps;
		lpp->max_cl = 1.5 + lpp->flaps / 62.5;
		lpp->min_cl = lpp->flaps / 62.5 - 1.5;
		lpp->tilt_factor = .005 * lpp->flaps + .017;

		if ((lgs->tick_counter/ 30)* lgs->tps > demo[demoCounter].framecounter) {
			if (demoCounter < maxdemo - 1) {
				demoCounter++;
			}
			else {
				if (demo[demoCounter].gotoNext != 0) {
					demoCounter = demo[demoCounter].gotoNext;
					lgs->tick_counter = 0;
				}
			}
			lgs->tower_fov = demo[demoCounter].cameraZoom;
			lgs->view_switch = demo[demoCounter].cameraview;
			lgs->real_fov = 45.0f;
			if (lgs->view_switch == TOWER) {
				lgs->real_fov = lgs->tower_fov;
			}
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity(); // Reset first
			gluPerspective(lgs->real_fov, (double)XMAXSCREEN / (double)YMAXSCREEN, 1.0, 1.0e9);                    // Set perspective
			glViewport(0, 0, XMAXSCREEN, YMAXSCREEN); // Set viewport
			glMatrixMode(GL_MODELVIEW);
		}


		simulation(lgs, lpp, msx, msy, XMIDDLE, YMIDDLE, XMAXSCREEN, YMAXSCREEN);
		lgs->vx_add = lgs->vy_add = lgs->vz_add = 0.0;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity(); // Reset first
		gluPerspective(lgs->real_fov, (double)XMAXSCREEN / (double)YMAXSCREEN, 1.0, 1.0e9);           // Set perspective
		glViewport(0, 0, XMAXSCREEN, YMAXSCREEN); // Set viewport
		glMatrixMode(GL_MODELVIEW);
		setClearColor(grey12);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		draw_game(lgs,lpp);
		glFlush();
		glutSwapBuffers();
		glutTimerFunc(1000 / lgs->tps, flight_demo_simulation, va);
	}
}
void init_strike_commander(unsigned char k) {
	free_memory();
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT3);

	glEnable(GL_LIGHT0);
	float lmodel_LVW[] = { 0.5 };
	float lmodel_ambient[] = { 0.02, 0.02, 0.02, 1.0 };
	float lmodel_TWO[] = { GL_TRUE };

	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, lmodel_LVW);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);


	GLuint fogMode[] = { GL_EXP, GL_EXP2, GL_LINEAR };   // Storage For Three Types Of Fog
	GLuint fogfilter = 0;                    // Which Fog To Use
	GLfloat fogColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glFogi(GL_FOG_MODE, fogMode[fogfilter]);        // Fog Mode
	glFogfv(GL_FOG_COLOR, fogColor);            // Set Fog Color
	glFogf(GL_FOG_DENSITY, 0.000002f);              // How Dense Will The Fog Be
	glHint(GL_FOG_HINT, GL_DONT_CARE);          // Fog Hint Value
	glFogf(GL_FOG_START, max_int*2-6000.0f);             // Fog Start Depth
	glFogf(GL_FOG_END, max_int*2);               // Fog End Depth
	glEnable(GL_FOG);


	glutSetCursor(GLUT_CURSOR_NONE);
	reset_gs(lgs);
	make_sc_world();
	lgs->nocrash = 1;
	lpp = init_plane();
	lgs->sts = SIMULATION;
	lgs->hud = 0;
	
	set_f16(lgs, lpp);
	setStartPosition(lpp);


	//lpp->x = -196038.890625;
	//lpp->z = -368130.562500;
	printf("STARTING FROM {%f,%f}\n", lpp->x, lpp->z);
	lpp->azimuthf = 1800.0f;
	lgs->vx_add = lgs->vy_add = lgs->vz_add = 0.0;
	glutReshapeFunc(reshape_3d);
	glutDisplayFunc(idle);
	glutIdleFunc(NULL);

	glutMotionFunc(mouse_mouve);
	glutMouseFunc(mouse_click);
	glutPassiveMotionFunc(mouse_mouve);
	glutKeyboardFunc(simul_key);
	glutSpecialFunc(special_key);
	reshape_3d(XMAXSCREEN, YMAXSCREEN);
	glutTimerFunc(1000 / lgs->tps, strike_commander, 0);
}
void init_game(unsigned char k) {
	free_memory();
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT3);

	glEnable(GL_LIGHT0);
	float lmodel_LVW[] = { 0.5 };
	float lmodel_ambient[] = { 0.02, 0.02, 0.02, 1.0 };
	float lmodel_TWO[] = { GL_TRUE };

	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, lmodel_LVW);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	glutSetCursor(GLUT_CURSOR_NONE);
	reset_gs(lgs);
	lpp = init_plane();
	lgs->sts = SIMULATION;
	lgs->hud = 0;
	if (k == '2') {
		set_b747(lgs, lpp);
	}
	else if (k == '5') {
		set_f18(lgs, lpp);
	}
	else if (k == '3') {
		set_f15(lgs, lpp);
	}
	else if (k == '4') {
		set_f16(lgs, lpp);
	}
	else if (k == '1') {
		set_c150(lgs, lpp);
	}
	else if (k == '6') {
		set_p38(lgs, lpp);
	}
	lgs->vx_add = lgs->vy_add = lgs->vz_add = 0.0;
	glutReshapeFunc(reshape_3d);
	glutDisplayFunc(idle);
	glutIdleFunc(NULL);

	glutMotionFunc(mouse_mouve);
	glutMouseFunc(mouse_click);
	glutPassiveMotionFunc(mouse_mouve);
	glutKeyboardFunc(simul_key);
	glutSpecialFunc(special_key);
	reshape_3d(XMAXSCREEN, YMAXSCREEN);
	glutTimerFunc(1000 / lgs->tps, flight_simulation, 0);
}
void init_demo(int va) {
    if (lgs->sts == PRESENTATION) {
		free_memory();
		reset_gs(lgs);
		lpp = init_plane();
		set_f18(lgs, lpp);
		lgs->vx_add = lgs->vy_add = lgs->vz_add = 0.0;
		lgs->sts = DEMONSTRATION;
		reshape_3d(XMAXSCREEN, YMAXSCREEN);
		glutReshapeFunc(reshape_3d);
		glutDisplayFunc(idle);
		glutIdleFunc(idle);
		glutTimerFunc(1000 / lgs->tps, flight_demo_simulation, 0);
		glutTimerFunc(200 * 1000, init_presentation, 0);
	}
}
void init_presentation(int va) {
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);

	glutSetCursor(GLUT_CURSOR_CROSSHAIR);
	reset_gs(lgs);
	lgs->sts = PRESENTATION;
	reshape_2d(XMAXSCREEN, YMAXSCREEN);
	glutDisplayFunc(draw_presentation);
	glutIdleFunc(draw_presentation);
	glutReshapeFunc(reshape_2d);
	glutSetKeyRepeat(GLUT_KEY_REPEAT_ON);
	glutKeyboardFunc(presentation_key);
	glutTimerFunc(50 * 1000, init_demo, 0);
}


void draw_3D_viewer(void) {
	glClearColor(0.2f, 0.2f, 0.8f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, lgs->polymod);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(0, 0, lgs->objz);
	glRotatef(lgs->cyaw, 0, 1, 0);
	glRotatef(lgs->cpitch, 1, 0, 0);
	glRotatef(lgs->croll, 0, 0, 1);
	glCallList(object3Dview);
	gluLookAt(0, 0, cz, 0, 0, 100, 0, 1, 0);
	glPopMatrix();
	glFlush();
	
	glutSwapBuffers();
	if (!moveok && !zoomok) {
		//lgs->cyaw += msdx * 0.5 *0.1;
		//lgs->cpitch -= msdy * 0.5*0.1;
	}
}
void init_3D_viewer(int va) {
	free_memory();
	reset_gs(lgs);
	lgs->sts = OBJECTVIEWER;
	reshape_3d(XMAXSCREEN, YMAXSCREEN);
	glutMotionFunc(mouse_mouve);
	glutMouseFunc(mouse_click);
	glutReshapeFunc(reshape_3d);
	glutSetKeyRepeat(GLUT_KEY_REPEAT_ON);
	glutKeyboardFunc(object_viewer_key);
	glutSpecialFunc(object_special_viewerKey);
	glutIdleFunc(idleViewer);
	glutDisplayFunc(draw_3D_viewer);
}
#ifdef W32
#ifdef DEBUG
int main() {
	return WinMain(GetModuleHandle(NULL), NULL, GetCommandLineA(), SW_SHOWNORMAL);
}
#endif
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	return main_start(__argc, __argv);
}
#else
int main(int argc, char *argv[]) {
	main_start(argc, argv);
}
#endif

int main_start(int argc, char *argv[]) {
	glutInit(&argc, argv);
	windows = glutCreateWindow("Flight");
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);

	init_palette();
	
	frames = 0;
	
	
	lgs = init_game_state();
	init_lights();
	set_sun(-1.0, 1.0, 2.0);
	init_logo();
	create_pattern();
	init_textures();
	make_meters();
	make_c150(C150);
	make_b747(B747);
	make_f18(F18);
	make_f15(F15);
	make_f16(F16);
	make_f16w(F16W);
	make_p38w(P38W);
	make_p38(P38);
	make_world(lgs);
	make_house();
	make_tree();
	make_my_building(8000, orange0, -50,-75,-50, 100, 150, 100,1);
	make_buildings(TOWER_EX, TOWER_EY, TOWER_EZ, lgs);
	make_lights();
	make_mountain_zone(0, 0, 100, lgs);
	make_textures_cube();
	init_SC();
	//test_SC();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);

	init_presentation(0);
	
	
	glutReshapeWindow(XMAXSCREEN, YMAXSCREEN);

	glutMainLoop();
	return 0;
}
