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

 /*	UFLIGHT.C	*/



#include "uflight.h"
#include "objects.h"

static GLfloat shadow_matrix[4][4];

/************************************************************
/*	Object definitions
/************************************************************/

#define RADIUS 300
void make_explosion()
{
	GLuint i;
	int n, temp;
	int x, y, z, radius;

	glNewList(EXPLOSION, GL_COMPILE);
	glEndList();

	for (i = 1; i < MEXPLODE; i++) {
		if (i <= 10 * TPS / 8) n = i * 8; else n = 90;
		radius = (MEXPLODE + 1 - i) * RADIUS / TPS / 2;

		glNewList(i + EXPLOSION, GL_COMPILE);
		setColor(red);
		for (; n > 0; n--) {
			temp = mrandom(3);
			if (temp > 2) setColor(orange);
		r1:
			x = mrandom(radius);
			y = mrandom(radius);
			z = mrandom(radius);
			if (x * x + y * y + z * z > RADIUS * RADIUS) goto r1;
			glBegin(GL_LINE_STRIP);
			glVertex3s(x, y, z);
			x = radius >> 3;
			if (n & 7) {
				glVertex3s(mrandom(x), mrandom(x), mrandom(x));
				glEnd();
			}
		r2:
			x = mrandom(radius);
			y = mrandom(radius);
			z = mrandom(radius);
			if (x * x + y * y + z * z > RADIUS * RADIUS) goto r2;
			glVertex3s(x, y, z);
			glEnd();
			if (temp > 2) setColor(red);
		}
		glEndList();
	}
}

void make_city_buildings(int x, int y, int size, gameState *gs) {
	int bheight;
	int segments;
	for (int t = 0; t < 100; t++) {
		int lx = mrandom(size / 2)+(x + size / 2);
		int ly = 0;
		int lz = mrandom(size/2) - (y+size/2);
		
		switch (t % 5) {
		case 0:
			bheight = fabs(mrandom(200)) + 350;
			segments = bheight / 100;
			makebox(orange0, lx, ly, lz, fabs(mrandom(200)) + 100, bheight, fabs(mrandom(200)) + 300, segments, gs);
			break;
		case 1:
			bheight = fabs(mrandom(200)) + 250;
			segments = bheight / 100;
			makebox(tan0, lx, ly, lz, fabs(mrandom(200)) + 250, bheight, fabs(mrandom(200)) + 400, segments, gs);
			break;
		case 2:
			bheight = fabs(mrandom(200)) + 150;
			segments = bheight / 100;
			makebox(bgrey+5, lx, ly, lz, fabs(mrandom(200)) + 350, bheight, fabs(mrandom(400)) + 250, segments, gs);
			break;
		case 3:
			set_tree(lx, ly, lz, gs);
			break;
		case 4:
			makehouse(lx, ly, lz, gs);
			break;
		}
	}
}

/* make all the buildings (and mountains) including data structures etc. */
void make_buildings(int eye_x,int eye_y,int eye_z, gameState* gs)
{
	int ex, ey, ez;
	/* color delta x, delta z	*/
	/* lime	*/
	static GLint mtn1[] = {
	36, -15000,8000,	
	37, 1000,10000,
	39, 15000,6000,
	38, 1000,-8000,
	35, -15000,-8000,
	};
	/* color delta x, delta z	*/
	/* tan	*/
	static GLint mtn2[] = {	
	46, -10000,8000,	
	47, -2000,6000,
	49, 5000,3000,
	48, 4000,-9000,
	45, -12000,-7000,
	};
	/* color delta x, delta z	*/
	/* orange	*/
	static GLint mtn3[] = {	
	41, -2000,5000,		
	42, 1200,1500,
	43, 1000,-5000,
	40, -3000,-7000,
	};
	/* color delta x, delta z	*/
	/* tan	*/
	static GLint mtn4[] = {	
	45, -6000,6000,		
	47, 8000,10000,
	48, 18000,-15000,
	46, -5000,-8000,
	};
	/* color delta x, delta z	*/
	/* orange	*/
	static GLint mtn5[] = {	
	40, -17000,10000,	
	42, 8000,20000,
	43, 11000,-12000,
	41, -7000,-15000,
	};
	/* color delta x, delta z	*/
	/* lime	*/
	static GLint  mtn6[] = {	
	35, -8000,1000,		
	37, -500,4000,
	38, 2000,0,
	36, 0,-2000,
	};
	/* color delta x, delta z	*/
	/* tan	*/
	static GLint  mtn7[] = {	
	45, -2000,5000,		
	47, 1500,0,
	46, 0,-1500,
	};
	/* color delta x, delta z	*/
	/* tan	*/
	static GLint  mtn8[] = {	
	46, -2500,8000,		
	47, 8000,5000,
	48, 10000,-6000,
	45, -18000,-5000,
	};
	/* color delta x, delta z	*/
	/* orange	*/
	static GLint  mtn9[] = {	
	40, -26000,12000,	
	42, 10000,10000,
	43, 30000,0,
	44, 15000,-18000,
	41, -18000,-10000,
	};
	/* color delta x, delta z	*/
	/* grey	*/
	static GLint  mtn10[] = {	
	19, -5000,18000,	
	21, 10000,6000,
	20, 8000,-10000,
	18, -15000,-2000,
	};

	ex = eye_x;
	ey = eye_y;
	ez = eye_z;		
	/* note buildings are sorted from tower view	*/
	//makebox(borange, -0, 0, 0, 100, 150, 100);
	makebox(orange0, -2000, 0, -3200, 100, 150, 100, 5, gs);
	makebox(tan0, -2000, 0, -2400, 200, 60, 300, 2, gs);
	makebox(tan0, -1900, 0, -4000, 250, 50, 400, 2, gs);
	makebox(orange0, -1800, 0, -4900, 400, 45, 200,2,  gs);
	makebox(bgrey, 1000, 0, -1900, 200, 40, 350, 2,  gs);

	

	makemtn(-40000, 2900, 45000, 5, mtn1, gs);
	makemtn(-2000, 2200, 45000, 5, mtn2, gs);
	makemtn(5000, 2000, 43000, 4, mtn3, gs);
	makemtn(16000, 2400, 44000, 4, mtn4, gs);
	makemtn(41000, 3600, 44000, 4, mtn5, gs);
	makemtn(15000, 400, 0, 4, mtn6, gs);
	makemtn(-12000, 500, -8000, 3, mtn7, gs);
	makemtn(-28000, 2300, -46000, 4, mtn8, gs);
	makemtn(33000, 2700, -37000, 5, mtn9, gs);
	makemtn(-55000, 2500, 15000, 4, mtn10, gs);

	for (int j = 0; j < 100; j++) {
		int x = mrandom(max_int);
		int y = mrandom(3000)+3400;
		int z = mrandom(max_int);
		while ((z < 12000) && (z > -12000)) {
			z = mrandom(max_int);
		}
		while ((x < 12000) && (x > -12000)) {
			x = mrandom(max_int);
		}
		switch (j % 11) {
		case 0:
			makemtn(x, y, z, 5, mtn1, gs);
			break;
		case 1:
			makemtn(x, y, z, 5, mtn2, gs);
			break;
		case 2:
			makemtn(x, y, z, 4, mtn3, gs);
			break;
		case 3:
			makemtn(x, y, z, 4, mtn4, gs);
			break;
		case 5:
			makemtn(x, y, z, 4, mtn5, gs);
			break;
		case 6:
			makemtn(x, y, z, 4, mtn6, gs);
			break;
		case 7:
			makemtn(x, y, z, 3, mtn7, gs);
			break;
		case 8:
			makemtn(x, y, z, 4, mtn8, gs);
			break;
		case 9:
			makemtn(x, y, z, 5, mtn9, gs);
			break;
		case 10:
			makemtn(x, y, z, 4, mtn10, gs);
			break;
		}
	}

	make_city_buildings(-12000, 48000, 24000, gs);
	make_city_buildings(12000, 48000, 24000, gs);
	make_city_buildings(-12000, 72000, 24000, gs);
	make_city_buildings(-36000, 48000, 24000, gs);
	make_city_buildings(-12000, 36000, 24000, gs);
	make_city_buildings(12000, 72000, 60000, gs);

	make_city_buildings(-152000, -168000, 80000, gs);

	/* threat patches are in land2.c	*/
	makethreat(6000, 14000, red, 17000.0, gs);
	makethreat(-20000, 15000, red, 10700.0, gs);
	makethreat(3000, 34000, red, 2700.0, gs);

	for (int j = 0; j < 10; j++) {
		int x = mrandom(max_int);
		int y = mrandom(max_int);
		int w = fabs(mrandom(160000));
		make_forest(x, y, w, gs);
	}
}

void draw_missiles(gameState* gs)
{
	plane *p, *pp;

	glLineWidth(2);
	for (pp = gs->planes, p = pp++; p->alive > 0; p = pp++) {
		if (p->mstatus) {		/* if launched		*/
			if (p->mstatus <= MEXPLODE) {	/* if exploding	*/
				glPushMatrix();
				/* replace with balls of fire	*/
				glTranslatef(p->mx, p->my, p->mz);
				glCallList(EXPLOSION + p->mstatus);
				glPopMatrix();
			}
			else {
				setColor(red);
				glBegin(GL_LINE_STRIP); 
				glVertex3f(p->last_mx,  p->last_my,  p->last_mz);
				glVertex3f(p->mx,  p->my,  p->mz);
				glEnd();
			}
		}
	}
	glLineWidth(1.0);
}

void set_sun(float x, float y, float z)
{
	// @TODO find replacement glIdentifyMatrix(shadow_matrix);
	shadow_matrix[0][0] = 1;
	shadow_matrix[0][1] = 0;
	shadow_matrix[0][2] = 0;
	shadow_matrix[0][3] = 0;

	shadow_matrix[1][0] = 0;
	shadow_matrix[1][1] = 1;
	shadow_matrix[1][2] = 0;
	shadow_matrix[1][3] = 0;

	shadow_matrix[2][0] = 0;
	shadow_matrix[2][1] = 0;
	shadow_matrix[2][2] = 1;
	shadow_matrix[2][3] = 0;

	shadow_matrix[3][0] = 0;
	shadow_matrix[3][1] = 0;
	shadow_matrix[3][2] = 0;
	shadow_matrix[3][3] = 1;


	shadow_matrix[1][0] = -x / y;
	shadow_matrix[1][1] = 0.0;
	shadow_matrix[1][2] = -z / y;
}

void draw_shadow(struct plane* pp, int nnear)
{
	if (pp) {
		glPushMatrix();
		glMultMatrixf((GLfloat*)shadow_matrix);
		if (pp->ptw)
			// pre-cat ptw
			glMultMatrixf((GLfloat*)pp->ptw);
		else {
			glTranslatef(pp->x, pp->y, pp->z);
			glRotatef(.1f * (pp->azimuthf), 0, 1, 0);
			glRotatef(.1f * (pp->elevationf), 1, 0, 0);
			glRotatef(.1f * (pp->twist), 0, 0, 1);
		}
		/* shadow object	*/
		glCallList(pp->type + (nnear ? 9 : 110));
		glPopMatrix();
	}
}
void draw_buildings(float rx, float ry, float rz, int start_plane, int num_planes, gameState* gs) {
	Building b;
	//glNewList(BUILDINGS, GL_COMPILE);
	for (int i = 0; i < current_building; i++) {
		b = gs->buildings[i]; 
		switch (b->type) {
		case TYPE_THREAT:
			if (gs->threat_mode) {
				glCallList(b->ury_obj);
			}
			break;
		case TYPE_MOUNTAIN:
			if (gs->textures) {
				glEnable(GL_TEXTURE_2D);
				//glBindTexture(GL_TEXTURE_2D, texID);
				glCallList(b->ury_obj);
				glDisable(GL_TEXTURE_2D);
			}
			else {
				glCallList(b->ury_obj);
			}
			break;
		default:
			glCallList(b->ury_obj);
			break;
		}
	}
	//glEndList();
}
/* draw the buildings from viewpoint (rx,ry,rz)	*/
void draw_buildings_old(float rx, float ry, float rz, int start_plane, int num_planes, gameState* gs)
{
	register int i, n, x, z;
	int ex, ey, ez;
	register int *parray;
	register Building b, *parray_tag;
	register Plane pp;
	GLfloat mat[4][4];
	static int static_array[MAX_BUILDINGS + MAX_PLANES];
	static Building static_array_tag[MAX_BUILDINGS + MAX_PLANES];

	ex = (int) rx;	
	ey = (int) ry;
	ez = (int) rz;
	/* copy data into sort arrays	*/
	parray = static_array;		
	parray_tag = static_array_tag;
	/* count number of items	*/
	n = 0;				
	for (i = 0; i < current_building; i++) {
		b = gs->buildings[i];
		z = ez - b->cz;
		if (z < 0) z = -z;
		x = ex - b->cx;
		if (x < 0) x = -x;
		if (x < 1024000 && z < 1024000) {
			x >>= 5;
			z >>= 5;
			n++;
			*parray++ = x * x + z * z;
			*parray_tag++ = b;
		}
	}
	for (i = start_plane; i < num_planes; i++) {
		pp = &gs->planes[i];
		z = ez - (int)pp->z;
		if (z < 0) z = -z;
		x = ex - (int)pp->x;
		if (x < 0) x = -x;
		if (x < 1024000 && z < 1024000) {
			x >>= 5;
			z >>= 5;
			n++;
			/* flag plane with high bit	*/
			*parray++ = x * x + z * z;	
			*parray_tag++ = (Building)((int)pp | PLANE_BIT);
		}
	}
	sink_sort(n, (int *)static_array, (int *)static_array_tag);

#ifdef QSDEBUG
	if (gs->debug) {
		printf("start_plane: %d, num_planes: %d,   dist_for_lines: %d\n", start_plane, num_planes, gs->dist_for_lines);
		printf("--------------AFTER SORT-------------------\n");
		for (i = 0; i < n; i++) {
			x = (int)static_array_tag[i];
			printf("%s ", x >= 0 ? "building" : "plane   ");
			/* turn off high bit	*/
			x &= 0x7fffffff;			
			printf("%3d %12d\n", x, static_array[i]);
		}
	}
#endif
	x = ex;	z = ez;
	/* plot the data from back to front	*/
	for (parray_tag = &static_array_tag[n - 1], parray = &static_array[n - 1];
		parray_tag >= static_array_tag; parray_tag--, parray--)
	{
		b = *parray_tag;
		if (b->type  & PLANE_BIT) {
			/* its a plane - compute above/below	*/
			/* turn off high bit	*/
			pp = (Plane)(b->type & ~PLANE_BIT);
			/* if close enough	*/
			if (*parray < (gs->dist_for_lines << 1)) {	
				n = TRUE;
				glPushMatrix();
				/* build WTP	*/
				glLoadIdentity();
				/* twist	*/
				glRotatef(-0.1f*pp->twist, 0, 0, 1);	
				/* elevation	*/
				glRotatef(-0.1f*pp->elevationf, 1, 0, 0);
				/* azimuth	*/
				glRotatef(-0.1f*pp->azimuthf, 0, 1, 0);	
				glTranslatef(rx - pp->x, ry - pp->y, rz - pp->z);
				glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *)mat);
				/* pop back to wte	*/
				glPopMatrix();			
			}
			else n = FALSE;

			if (pp->y < 5000.0) {
				/* show my shadow	*/
				draw_shadow(pp, n);		
			}
			glPushMatrix();
			/*if (pp == planes[0] && my_ptw != NULL)*/
			if (FALSE) {
				/* pre-cat ptw		*/
				glMultMatrixf((GLfloat*)pp->ptw);
			}
			else {
				glTranslatef(pp->x, pp->y, pp->z);
				glRotatef(.1f*pp->azimuthf,0, 1, 0);
				glRotatef(.1f*pp->elevationf,1, 0, 0);
				glRotatef(.1f*pp->twist, 0, 0, 1);
			}
			if (n) {
				n = 0;
				/* test right/left, above/below, front/behind of plane	*/
				if (mat[3][0] >= 0.0) n += 1;
				if (mat[3][1] >= 0.0) n += 2;
				if (mat[3][2] >= 0.0) n += 4;
				if (pp->type == F16W) {
					/*
					 * migth need more work because of editobj and objreplace not existing in opengl
					*/
					glCallList(RWHEEL_ANGLE);
					//objreplace(0);
					if (pp->wheels < 5)
						glRotatef(.1f*(pp->wheels * 100), 0, 1, 0);
					else glRotatef(.1f*(500), 0, 1, 0);
					glEndList();

					glCallList(LWHEEL_ANGLE);
					//objreplace(0);
					if (pp->wheels < 5)
						glRotatef(.1f*(-pp->wheels * 100), 0, 1, 0);
					else glRotatef(.1f*(-500), 0, 1, 0);
					glEndList();

					glCallList(WHEEL_ANGLE);
					//objreplace(1);
					glRotatef(.1f*(pp->wheels * 100), ( 'x')=='x'||( 'x')=='X', ( 'x')=='y'||( 'x')=='Y', ( 'x')=='z'||( 'x')=='Z');
					glEndList();
				}
				/* call appropriate plane*/
				glCallList(pp->type);	
			}
			else glCallList(pp->type + 8);
			/* explosion if needed	*/
			if (pp->status < MEXPLODE)	
				glCallList(EXPLOSION + pp->status);

			glPopMatrix();
		}
		else if (b->type == TYPE_BUILDING) {	
			/* its a building	*/
			glCallList(b->ury_obj);
		}
		else if (b->type == TYPE_MOUNTAIN) {
			/* its a mountain	*/
			glCallList(b->ury_obj);
		}
		else if (b->type == TYPE_HOUSE) {
			/* its a house	*/
			glCallList(b->ury_obj);
		}
		else if (gs->threat_mode) {
			/* its a threat		*/
			glCallList(b->ury_obj);
		}
		
	}	/* end of each object	*/
	/* always draw my shadow	*/
	if (start_plane > 0) draw_shadow(&gs->planes[0], TRUE);
}

Building new_building(int type, gameState* gs)
{
	Building b;

	if (current_building == MAX_BUILDINGS) {
		exit(1);
	}
	int id = current_building++;
	
	b = (Building)malloc(sizeof(struct building));
	if (b) {
		gs->buildings[id] = b;
		b->type = type;
	}
	return b;
}

void makethreat(int cx, int cz, int col, float radius, gameState *gs)
{
	int i;
	int j;
	float *f;
	Building b;
	/* 20 point unit circle	*/
	GLfloat thcircle[20][3] = {	
	   0.951057f,	0,-0.309017f,
	   0.809017f,	0,-0.587785f,
	   0.587785f,	0,-0.809017f,
	   0.309017f,	0,-0.951057f,
	   0,0,-1,
	   -0.309017f,0,-0.951057f,
	   -0.587785f,0,-0.809017f,
	   -0.809017f,0,-0.587785f,
	   -0.951057f,0,-0.309017f,
	   -1,0,0,
	   -0.951057f,0,0.309017f,
	   -0.809017f,0,0.587785f,
	   -0.587785f,0,0.809017f,
	   -0.309017f,0,0.951057f,
	   0,0,1,
	   0.309017f,0,0.951057f,
	   0.587785f,0,0.809017f,
	   0.809017f,0,0.587785f,
	   0.951057f,0,0.309017f,
	   1,0,0,
	};

	b = new_building(TYPE_THREAT, gs);
	b->cx = cx;
	b->cy = 0;
	b->cz = cz;
	glNewList(b->ury_obj = (current_building_object++)+BUILDINGS_OFFSET, GL_COMPILE);
	setColor(col);
	glPushMatrix();
	glTranslatef((float)cx, 0.0, (float)cz);
	glScalef(radius, radius, radius);
	glBegin(GL_LINE_STRIP); glVertex2s(-1, 0);
	for (i = 0, f = (float *) thcircle + 30; i < 10; i++, f += 3)
		glVertex2f(f[0], f[2]);
	glEnd();
	for (j = 0; j < 5; j++) {
		glRotatef(.1f*(300), 0, 1, 0);
		glBegin(GL_LINE_STRIP); glVertex2s(-1, 0);
		for (i = 0, f = (float*) thcircle + 30; i < 10; i++, f += 3)
			glVertex2f(f[0], f[2]);
		glEnd();
	}
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 20; i++) glVertex3fv(thcircle[i]); glEnd(); }
	/*
	glTranslatef (0.0,0.5,0.0);
	scale (.866,.866,.866);
	*/
	glTranslatef(0.0, 0.33, 0.0);
	glScalef(.94, .94, .94);
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 20; i++) glVertex3fv(thcircle[i]); glEnd(); }
	glTranslatef(0.0, 0.33 / .94, 0.0);
	glScalef(.794, .794, .794);
	{int i; glBegin(GL_LINE_LOOP); for (i = 0; i < 20; i++) glVertex3fv(thcircle[i]); glEnd(); }
	glPopMatrix();
	glEndList();
}

void makehouse(int cx, int cy, int cz, gameState *gs) {
	Building b;
	b = new_building(TYPE_HOUSE, gs);

	b->urx = cx;
	b->urz = cz;
	b->ury = cy;

	b->cx = cx;
	b->cy = cy;
	b->cz = cz;
	b->ury_obj = (current_building_object++) + BUILDINGS_OFFSET;
	if (glIsList(b->ury_obj)) {
		glDeleteLists(b->ury_obj, 1);
	}
	glNewList(b->ury_obj, GL_COMPILE);
	glPushMatrix();
	glTranslatef(cx, cy, cz);
	glScalef(12.0f, 12.0f, 22.0f);
	glCallList(HOUSE);
	glPopMatrix();
	glEndList();

}
/* make a mountain given center [x,y,z], number of faces, and data array */
void makemtn(int cx, int cy, int cz, int n, int savearray[], gameState *gs)
{
	int *array = savearray;
	
	Building b;
	

	b = new_building(TYPE_MOUNTAIN, gs);
	b->cx = cx;
	b->cy = cy;
	b->cz = cz;
	b->ury_obj = (current_building_object++)+ BUILDINGS_OFFSET;
	if (glIsList(b->ury_obj)) {
		glDeleteLists(b->ury_obj, 1);
	}
	glNewList(b->ury_obj, GL_COMPILE);
	glBindTexture(GL_TEXTURE_2D, texID[0]);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_NORMALIZE);
	while (n-- > 0) {
		setColor(array[0]);
		glBegin(GL_POLYGON); 
		glTexCoord2d(0, 0);
		glVertex3i(cx, cy, cz);
		glTexCoord2d(1, 0);
		glVertex3i(cx + array[1], 0, cz + array[2]);
		array += 3;		/* advance to next point	*/
		if (n == 0) array = savearray;
		glTexCoord2d(0, 1);
		glVertex3i(cx + array[1], 0, cz + array[2]);
		glEnd();
	}
	
	glCullFace(GL_FRONT);
	glDisable(GL_CULL_FACE);
	glDisable(GL_NORMALIZE);
	glEndList();
}

void makebox(int col, int llx, int lly, int llz, int dx, int dy, int dz, int nbstripe, gameState *gs) {
	Building b;
	b = new_building(TYPE_BUILDING, gs);
	b->ury_obj = (current_building_object++) + BUILDINGS_OFFSET;
	
	b->urx = llx + dx;
	b->urz = llz+dz;
	b->ury = lly+dy;

	b->cx = (llx + b->urx) >> 1;
	b->cy = (lly + b->ury) >> 1;
	b->cz = (llz + b->urz) >> 1;
	
	make_my_building(b->ury_obj, col, llx, lly, llz, dx, dy, dz, nbstripe);
}
/* create the data structure for a box shaped building	*/
void oldmakebox(int col, int llx, int lly, int llz, int dx, int dy, int dz, int nbstripe, gameState *gs)
{
	short *shade;
	int i;
	int *p;
	int urx, ury, urz;
	int mat[4][3];
	Building b;
	

	urx = llx + dx;
	ury = lly + dy;
	urz = llz + dz;

	b = new_building(TYPE_BUILDING, gs);
	b->llx = llx;
	b->urx = urx;
	b->llz = llz;
	b->urz = urz;
	b->ury = ury;

	b->cx = (llx + urx) >> 1;
	b->cy = (lly + ury) >> 1;
	b->cz = (llz + urz) >> 1;

	shade = &building_shade[col][0];
	b->ury_obj = (current_building_object++)+ BUILDINGS_OFFSET;

	if (glIsList(b->ury_obj)) {
		glDeleteLists(b->ury_obj, 1);
	}
	glNewList(b->ury_obj, GL_COMPILE);
	p = &mat[0][0];
	setColor(col+1);		/* top face	*/
	*p++ = llx;	*p++ = ury;	*p++ = llz;
	*p++ = urx;	*p++ = ury;	*p++ = llz;
	*p++ = urx;	*p++ = ury;	*p++ = urz;
	*p++ = llx;	*p++ = ury;	*p++ = urz;
	{int i; glBegin(GL_POLYGON); for (i = 0; i < 4; i++) glVertex3iv(mat[i]); glEnd(); }
	
	

	for (i = llz; i <= urz; i += dz) {	/* front and back	*/
		if (i == llz) {
			setColor(col+3);
		}
		else {
			setColor(col+2);
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
			setColor(col+1);
		}
		else {
			setColor(col+4);
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
void reset_building(gameState *gs) {
	for (int i = 0; i < current_building; i++) {
		if (gs->buildings[i] != NULL) {
			free(gs->buildings[i]);
		}
	}
	current_building = 0;
	current_building_object = BUILDING_OBJECTS;
}
/* draw the face of the building and then lines	*/
void facet(int n, int p[4][3], int col)
{
	float a1, b1, c1, a2, b2, c2, x1, y1, z1, x2, y2, z2;
	float dx, dy, dz, da, db, dc;

	x1 = p[0][0];	
	y1 = p[0][1];	
	z1 = p[0][2];

	if (p[1][1] == p[0][1]) {
		a1 = p[1][0];	b1 = p[1][1];	c1 = p[1][2];
		a2 = p[2][0];	b2 = p[2][1];	c2 = p[2][2];
		if (n == 3) {
			x2 = a2; y2 = b2; z2 = c2;
		}
		else {
			x2 = p[3][0]; y2 = p[3][1];	z2 = p[3][2];
		}
	}
	else {
		x2 = p[1][0];	y2 = p[1][1];	z2 = p[1][2];
		if (n == 3) {
			a1 = p[2][0];	b1 = p[2][1];	c1 = p[2][2];
			a2 = x2; b2 = y2; c2 = z2;
		}
		else {
			a2 = p[2][0];	b2 = p[2][1];	c2 = p[2][2];
			a1 = p[3][0];   b1 = p[3][1];	c1 = p[3][2];
		}
	}
	dy = y2 - y1;
	if (dy > 50.0) db = 25.0;
	else db = 0.8*dy;

	dx = (x2 - x1) * db / dy;
	dz = (z2 - z1) * db / dy;
	da = (a2 - a1) * db / dy;
	dc = (c2 - c1) * db / dy;

	dimColor(col);
	y2 -= 2.0;
	if (y1 < 2.0) {		/* if on ground, skip first line	*/
		y1 += db;
		x1 += dx;	a1 += da;
		z1 += dz;	c1 += dc;
	}
	else {
		glBegin(GL_POLYGON);
		glVertex3f(x1,  y1,  z1);
		glVertex3f(a1,  y1,  c1);
		glVertex3f(a1,  y1 + 10, c1);
		glVertex3f(x1,  y1 + 10, z1);
		glVertex3f(x1,  y1, z1);
		glEnd();
	}

	if (dy > 26.0) {
		while (y1 < y2) {
			glBegin(GL_POLYGON);
			glVertex3f(x1,  y1,  z1);
			glVertex3f(a1,  y1,  c1);
			glVertex3f(a1, y1 + 10, c1);
			glVertex3f(x1, y1 + 10, z1);
			glVertex3f(x1, y1, z1);
			glEnd();
			y1 += db;
			x1 += dx;	a1 += da;
			z1 += dz;	c1 += dc;
		}
	}
}

/* sort an array (and an associated tag array) in increasing order	*/
void sink_sort(int n, int *array, int *array_tag)
{
	register int tag, *end;
	register int *top, *top_tag, *bot, *bot_tag;

	end = &array[n];

	for (bot = array + 1, bot_tag = array_tag + 1; bot < end; bot++, bot_tag++) {
		top = bot - 1;		    top_tag = bot_tag - 1;
		n = *bot;
		if (*top > n) {
			tag = *bot_tag;
		sinktest:
			top[1] = *top;	top_tag[1] = *top_tag;
			top--;		top_tag--;
			if (top >= array) {
				if (*top > n) goto sinktest;
			}

			top[1] = n;	top_tag[1] = tag;
		}
	}
}
void makeCity(int x, int y, int size, gameState* gs) {
	setColor(dirt);
	draw_rect(x, y, size, size);

	for (int j = 0; j < 50; j++) {
		int lx = mrandom(size / 2) + (x + size / 2);
		int ly = mrandom(size / 2) + (y + size /2);
		int w = mrandom(2000) + 2800;
		int h = mrandom(2000) + 2800;
		switch (j % 2) {
		case 0:
			setColor(lime0 + 3);
			break;
		case 1:
			setColor(brown);
			break;
		}
		draw_rect(lx, ly, w, h);
	}
	setColor(grey8);
	for (int r = y; r <= y+size; r += 4000) {
		draw_rect(x, r, size, 300);
	}
	for (int r = x; r <= x+size; r += 4000) {
		draw_rect(r, y, 300, size);
	}
}
void set_tree(int cx,int cy,int cz, gameState *gs) {
	Building b;
	b = new_building(TYPE_HOUSE, gs);

	b->urx = cx;
	b->urz = cz;
	b->ury = cy;

	b->cx = cx;
	b->cy = cy;
	b->cz = cz;
	b->ury_obj = (current_building_object++) + BUILDINGS_OFFSET;
	if (glIsList(b->ury_obj)) {
		glDeleteLists(b->ury_obj, 1);
	}
	glNewList(b->ury_obj, GL_COMPILE);
	glPushMatrix();
	glTranslatef(cx, cy, cz);
	glScalef(8.0f, 8.0f, 8.0f);
	glCallList(TREE);
	glPopMatrix();
	glEndList();
}
void make_forest(int x, int y, int size, gameState *gs) {
	make_tree();
	for (int t = 0; t < 5; t++) {
		int lx = mrandom(size / 2) + (x + size / 2);
		int ly = 0;
		int lz = mrandom(size / 2) - (y + size / 2);
		set_tree(lx, ly, lz, gs);
	}
}
void make_sc_world() {
	static GLuint sky1[][4] = {
	{-max_int,0,-max_int,skyblue},
	{-max_int,0,max_int,skyblue},
	{0,max_int,0,nightblue},
	};
	static GLuint sky2[][4] = {
		{max_int,0,-max_int,skyblue},
		{max_int,0,max_int,skyblue},
		{0,max_int,0,nightblue},
	};
	static GLuint sky3[][4] = {
		{-max_int,0,-max_int,skyblue},
		{max_int,0,-max_int,skyblue},
		{0,max_int,0,nightblue},
	};
	static GLuint sky4[][4] = {
		{-max_int,0,max_int,skyblue},
		{max_int,0,max_int,skyblue},
		{0,max_int,0,nightblue},
	};
	
	glNewList(SC_WORLD - 1, GL_COMPILE);
	draw_polyiColor(sky1, 3);
	draw_polyiColor(sky2, 3);
	draw_polyiColor(sky3, 3);
	draw_polyiColor(sky4, 3);
	glEndList();
}
void make_world(gameState* gs) {
	register int x, y;
	static GLuint world[][3] = {
		{max_int,0,max_int},
		{-max_int,0,max_int},
		{-max_int,0,-max_int},
		{max_int,0,-max_int},
	};
	static GLuint sky1[][3] = {
		{-max_int,0,-max_int},
		{-max_int,0,max_int},
		{0,max_int,0},
	};
	static GLuint sky2[][3] = {
		{max_int,0,-max_int},
		{max_int,0,max_int},
		{0,max_int,0},
	};
	static GLuint sky3[][3] = {
		{-max_int,0,-max_int},
		{max_int,0,-max_int},
		{0,max_int,0},
	};
	static GLuint sky4[][3] = {
		{-max_int,0,max_int},
		{max_int,0,max_int},
		{0,max_int,0},
	};


	static GLuint north_mtn_dark0[][3] = {
		{-mtn_left - 20000,0,-mtn_dist},
		{-mtn_left,5000,-mtn_dist},
		{mtn_left,5000,-mtn_dist},
		{mtn_left + 20000,0,-mtn_dist},
	};

	static GLuint north_mtn_lite1[][3] = {
		{-mtn_left - 15000,0,-mtn_dist - 5000},
		{-100000,8500,-mtn_dist - 5000},
		{-80000,0,-mtn_dist - 5000},
	};

	static GLuint north_mtn_lite2[][3] = {
		{-90000,0,-mtn_dist - 5000},
		{-70000,12000,-mtn_dist - 5000},
		{-50000,5000,-mtn_dist - 5000},
	};

	static GLuint north_mtn_lite3[][3] = {
		{-70000,5000,-mtn_dist - 5000},
		{-40000,21000,-mtn_dist - 5000},
		{-20000,5000,-mtn_dist - 5000},
	};

	static GLuint north_mtn_lite4[][3] = {
		{-30000,5000,-mtn_dist - 5000},
		{0,22500,-mtn_dist - 5000},
		{50000,5000,-mtn_dist - 5000},
	};

	static GLuint north_mtn_lite5[][3] = {
		{12000,10000,-mtn_dist - 5000},
		{28000,19000,-mtn_dist - 5000},
		{37300,17500,-mtn_dist - 5000},
	};

	static GLuint north_mtn_lite6[][3] = {
		{12000,10000,-mtn_dist - 5000},
		{50000,22000,-mtn_dist - 5000},
		{80000,5000,-mtn_dist - 5000},
	};

	static GLuint snow_cap2[][3] = {
		{43700,20000,-mtn_dist - 5000},
		{50000,22000,-mtn_dist - 5000},
		{53500,20000,-mtn_dist - 5000},
	};

	static GLuint north_mtn_dark1[][3] = {
		{-100000,5000,-mtn_dist},
		{-85000,10000,-mtn_dist},
		{-70000,5000,-mtn_dist},
	};

	static GLuint north_mtn_dark2[][3] = {
		{-60000,5000,-mtn_dist},
		{-25000,20000,-mtn_dist},
		{0,5000,-mtn_dist},
	};

	static GLuint north_mtn_dark3[][3] = {
		{-10000,5000,-mtn_dist},
		{5000,17500,-mtn_dist},
		{30000,5000,-mtn_dist},
	};

	static GLuint north_mtn_dark4[][3] = {
		{15000,5000,-mtn_dist},
		{30000,15000,-mtn_dist},
		{50000,10000,-mtn_dist},
	};

	static GLuint north_mtn_dark5[][3] = {
		{15000,5000,-mtn_dist},
		{62000,20000,-mtn_dist},
		{100000,5000,-mtn_dist},
	};

	static GLuint snow_cap1[][3] = {
		{-34333,16000,-mtn_dist},
		{-25000,20000,-mtn_dist},
		{-18444,16000,-mtn_dist},
	};
	if (glIsList(MTN_RANGE)) {
		glDeleteLists(MTN_RANGE, 1);
	}

	glNewList(MTN_RANGE, GL_COMPILE);
	setColor(purple1);
	draw_polyi(north_mtn_lite1, 3);
	draw_polyi(north_mtn_lite2, 3);
	draw_polyi(north_mtn_lite3, 3);
	draw_polyi(north_mtn_lite4, 3);
	draw_polyi(north_mtn_lite5, 3);
	draw_polyi(north_mtn_lite6, 3);
	setColor(grey0);
	draw_polyi(snow_cap2, 3);
	setColor(purple3);
	draw_polyi(north_mtn_dark0, 4);
	draw_polyi(north_mtn_dark1, 3);
	draw_polyi(north_mtn_dark2, 3);
	draw_polyi(north_mtn_dark3, 3);
	draw_polyi(north_mtn_dark4, 3);
	draw_polyi(north_mtn_dark5, 3);
	setColor(grey0);
	draw_polyi(snow_cap1, 3);
	glEndList();

	make_lights();

	if (glIsList(WORLD_OBJECT)) {
		glDeleteLists(WORLD_OBJECT, 1);
	}
	glNewList(WORLD_OBJECT, GL_COMPILE);
	setColor(green);
	glEnable(GL_NORMALIZE);
	draw_polyi(world, 4);

	setColor(skyblue);
	draw_polyi(sky1, 3);
	draw_polyi(sky2, 3);
	draw_polyi(sky3, 3);
	draw_polyi(sky4, 3);

	glPushMatrix();
	glTranslatef(0, 0, -max_int);
	glScalef(5.0f, 2.0f, 1.0f);
	glCallList(MTN_RANGE);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, max_int);
	glScalef(5.0f, 2.0f, 1.0f);
	glCallList(MTN_RANGE);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(max_int, 0, 0);
	glRotatef(90, 0, 1, 0);
	glScalef(5.0f, 2.0f, 1.0f);
	glCallList(MTN_RANGE);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-max_int, 0, 0);
	glRotatef(270, 0, 1, 0);
	glScalef(5.0f, 2.0f, 1.0f);
	glCallList(MTN_RANGE);
	glPopMatrix();


	glPushMatrix();
	/* z = -y */
	glRotatef(.1 * (-900), 1, 0, 0);
	setColor(brown);
	glRects(-300, -300, 300, 300);

	

	

	for (int j = 0; j < 500; j++) {
		int x = mrandom(max_int);
		int y = mrandom(max_int);
		int w = mrandom(24000) + 28000;
		int h = mrandom(24000) + 28000;
		switch (j % 3) {
		case 0:
			setColor(grey7);
			break;
		case 1:
			setColor(lime0+3);
			break;
		case 2:
			setColor(brown);
			break;
		}
		draw_rect(x, y, w, h);
	}

	setColor(skyblue);
	for (int j = 0; j < 100; j++) {
		int x = mrandom(max_int);
		int y = mrandom(max_int);
		int z = mrandom(10000) + 13000;
		draw_filled_circle(x, y, z);
	}

	// city
	/**/
	makeCity(-12000, 48000, 24000, gs);
	makeCity(12000, 48000, 24000, gs);
	makeCity(-12000, 72000, 24000, gs);
	makeCity(-36000, 48000, 24000, gs);
	makeCity(-12000, 36000, 24000, gs);
	makeCity(12000, 72000, 60000, gs);
	makeCity(-152000, -168000, 80000, gs);
	/**/


	

	


	setColor(lime0+3);
	draw_rect(-12000, -12000, 24000, 24000);

	/* grid lines */
	setColor(dirt);
	for (x = -max_int; x <= max_int; x += 10000) {
		glBegin(GL_LINE_STRIP);
		glVertex2i(x, -max_int);
		glVertex2i(x, max_int);
		glEnd();
	}
	for (x = -max_int; x <= max_int; x += 10000) {
		glBegin(GL_LINE_STRIP);
		glVertex2i(-max_int, x);
		glVertex2i(max_int, x);
		glEnd();
	}

	
	setColor(dirt);
	/* VASI patches	*/
	genstripe(150, 0, 210, 1000);
	/* dirt		*/
	glRects(-20, -3100, 20, -1000);
	/* over runs	*/
	glRects(-100, -1000, 100, 0);		
	glRects(-100, 8500, 100, 9500);

	setColor(red);
	/* threats	*/
	glRects(6000, -14000, 6020, -14030);	
	glRecti(-20000, -15000, -20040, -15020);
	glRecti(3000, -34000, 3010, -34030);

	setColor(grey9);
	{
		static GLshort p23[][2] = {
			-2300,2500,
			-2250,2500,
			-650,-3300,
			-700,-3300,
		};
		static GLshort p24[][2] = {
			-700,-3250,
			600,-3350,
			600,-3400,
			-700,-3300,
		};
		static GLshort p25[][2] = {
			600,-3400,
			550,-3400,
			1050,1600,
			1100,1600,
		};
		polf2s(4, p23);
		polf2s(4, p24);
		polf2s(4, p25);

		glRects(-2300, 2500, -2000, 4200);
		glRects(1000, 1500, 1300, 2100);
	}
	/* taxi ways		*/
	setColor(grey7);
	glRects(-700, 0, -100, 100);
	glRects(-1200, 2000, 700, 2100);

	{
		static GLshort parray[][2] = {
			-700,3100,
			-700,3300,
			-100,4000,
			-100,3800,
		};
		polf2s(4, parray);
	}
	{
		static GLshort parray[][2] = {
			-700,4700,
			-700,4900,
			-100,4200,
			-100,4000,
		};
		polf2s(4, parray);
	}
	/* roads	*/
	glRects(-700, 5900, -100, 6000);
	glRects(-700, 8400, -100, 8500);
	glRects(-1200, 3100, -800, 3300);
	glRects(-1200, 4700, -800, 4900);

	setColor(grey6);
	glRects(-800, 0, -700, 8500);
	glRects(-2000, 2000, -1200, 4900);
	glRects(700, 1600, 1000, 2500);

	/* asphalt		*/
	setColor(grey3);
	/* main runway		*/
	glRects(-100, 0, 100, 8500);
	glPopMatrix();
	glDisable(GL_NORMALIZE);
	glEndList();

	if (glIsList(FAKE_STRIPES)) {
		glDeleteLists(FAKE_STRIPES, 1);
	}
	glNewList(FAKE_STRIPES, GL_COMPILE);
	glPushMatrix();
	/* z = -y */
	glRotatef(.1 * (-900), 1, 0, 0);
	setColor(grey1);
	genstripe(8, 10, 63, 150);
	glRecti(-1, 450, 2, 8000);
	glPopMatrix();
	glEndList();

	if (glIsList(RUNWAY_STRIPES)) {
		glDeleteLists(RUNWAY_STRIPES, 1);
	}

	glNewList(RUNWAY_STRIPES, GL_COMPILE);
	glPushMatrix();
	/* z = -y */
	glRotatef(.1 * (-900), 1, 0, 0);
	{
		/* tire marks		*/
		static GLshort parray[][2] = {
			 5,		400,
			-7,		410,
			-35,	800,
			-30,	1200,
			-4,		2300,
			 1,		2350,
			 30,	1270,
			 36,	720,
		};
		setColor(grey7);
		polf2s(8, parray);
	}

	setColor(grey1);
	for (y = 450; y < 8000; y += 350) {
		/* center stripes	*/
		glRects(-1, y, 2, y + 150);
	}
	/* long side stripes	*/
	glRects(72, 0, 75, 8500);
	glRects(-72, 0, -75, 8500);
	/* 4 big ones		*/
	for (x = 8; x <= 53; x += 15) {
		genstripe(x, 10, x + 10, 150);
	}
	for (x = 38; x <= 58; x += 10) {
		/* 3 small ones		*/
		genstripe(x, 500, x + 5, 575);
	}
	/* 1 big fat one	*/
	genstripe(38, 1000, 63, 1150);
	genstripe(38, 1500, 43, 1575);
	/* 2	*/
	genstripe(38, 1500, 43, 1575);
	genstripe(48, 1500, 53, 1575);
	/* 2	*/
	genstripe(38, 2000, 43, 2075);
	genstripe(48, 2000, 53, 2075);
	/* 1	*/
	genstripe(38, 2500, 43, 2575);
	/* 1	*/
	genstripe(38, 3000, 43, 3075);
	{
		/* runway numbers "10	*/
		static GLshort parray[][2] = {
			-20,	250,
			-15,	260,
			-15,	250,
		};
		/* "1"	*/
		polf2s(3, parray);
	}
	glRects(-20, 200, -5, 210);
	glRects(-15, 210, -10, 260);
	{
		/* "0"	*/
		static GLshort parray[][2] = {
			5,	255,
			10,	260,
			25,	260,
			30,	255,
			30,	205,
			25,	200,
			10,	200,
			5,	205,
		};
		polf2s(8, parray);
	}
	setColor(grey3);
	/* inside of "0"	*/
	glRects(10, 210, 25, 250);
	glPopMatrix();


	glEndList();

	

}

void genstripe(GLint x1, GLint y1, GLint x2, GLint y2)
{
	glRects(x1, y1, x2, y2);
	glRects(-x1, y1, -x2, y2);
	glRects(x1, 8500 - y1, x2, 8500 - y2);
	glRects(-x1, 8500 - y1, -x2, 8500 - y2);
}
void make_lights()
{
	register int x, y;

	glNewList(LIGHTS, GL_COMPILE);
	glPushMatrix();
	glRotatef(.1 * (-900), 1, 0, 0);
	/* mrandom LIGHTS	*/
	setColor(white);
	for (x = 0; x < 40; x++) {
		glBegin(GL_POINTS);
		glVertex2s(mrandom(2000), mrandom(2000) - 6000);
		glEnd();
	}
	/* city lights */
	for (x = 0; x < 30; x++) {
		glBegin(GL_POINTS);
		glVertex2i(mrandom(3000), mrandom(3000) + 60000);
		glEnd();
	}

	/* RIGHT SIDE WHITE LIGHTS ON RUNWAY EDGE */
	for (y = 200; y <= 6400; y += 200) {
		glBegin(GL_POINTS);
		glVertex2s(0, y);
		glEnd();
	}

	/* LEFT SIDE WHITE LIGHTS - NEAR END */
	for (y = -200; y <= 3600; y += 200) {
		glBegin(GL_POINTS);
		glVertex2s(0, y);
		glEnd();
	}

	/* LEFT SIDE WHITE LIGHTS - FAR END */
	for (y = 4400; y <= 6400; y += 200) {
		glBegin(GL_POINTS);
		glVertex2s(0, y);
		glEnd();
	}
	/* APPROACH LIGHTS TO RUNWAY */
	for (y = -3000; y <= -100; y += 200) {
		for (x = -8; x <= 8; x += 4) {
			glBegin(GL_POINTS);
			glVertex2s(x, y);
			glEnd();
		}
	}

	/* RUNWAY CENTERLINE LIGHTS */
	for (y = 0; y <= 8500; y += 100) {
		glBegin(GL_POINTS);
		glVertex2s(2, y);
		glEnd();
	}

	/* RIGHT AND LEFT SIDE ORANGE LIGHTS */
	setColor(orange);
	for (y = 6600; y <= 8500; y += 200) {
		glBegin(GL_POINTS);
		glVertex2s(0, y);
		glEnd();
		glBegin(GL_POINTS);
		glVertex2s(0, y);
		glEnd();
	}
	/* city street lights */
	setColor(orange);

	for (x = -30000; x < 0; x += 1500) {
		glBegin(GL_POINTS);
		glVertex2i(x, 60000 + x);
		glEnd();
		glBegin(GL_POINTS);
		glVertex2i(x, 60000 - x);
		glEnd();
	}


	/* NEAR END GREEN LIGHTS */
	setColor(green0);
	for (x = -90; x <= -50; x += 10) {
		glBegin(GL_POINTS);
		glVertex2s(x, 0);
		glEnd();
	}
	for (x = 50; x <= 90; x += 10) {
		glBegin(GL_POINTS);
		glVertex2s(x, 0);
		glEnd();
	}
	/* FAR END RED LIGHTS */
	setColor(red);
	for (x = -90; x <= -50; x += 10) {
		glBegin(GL_POINTS);
		glVertex2s(x, 8500);
		glEnd();
	}
	for (x = 50; x <= 90; x += 10) {
		glBegin(GL_POINTS);
		glVertex2s(x, 8500);
		glEnd();
	}

	/* city lights */
	for (x = 0; x < 10; x++) {
		glBegin(GL_POINTS);
		glVertex2i(mrandom(1500), mrandom(1500) + 60000);
		glEnd();
	}

	glPopMatrix();
	glEndList();
}
void make_vasi_lights()
{
	register int x;

	for (x = 160; x <= 200; x += 20) {
		glRects(x, 0, x + 3, 3);
		glRects(-x, 0, -x - 3, 3);
	}
}

/* draw VASI lights , plane is at pz	*/
void draw_vasi(Plane pp)
{
	register GLuint obj;
	register float temp1, temp2;

	temp1 = temp2 = 0.0;
	if (pp->z > -4000.0) {
		obj = VASI1;
		if (pp->z != -1150.0f) temp1 = pp->y / (pp->z + 1150.0f);
		if (pp->z != -500.0f) temp2 = pp->y / (pp->z + 500.0f);
		glPushMatrix();

		setColor(temp1 < 12.0 / 200.0 ? red : white);
		glTranslatef(0.0, 0.0, -800.0);
		make_vasi_lights();

		setColor(temp2 < 12.0 / 200.0 ? red : white);
		glTranslatef(0.0, 0.0, 700.0);
		make_vasi_lights();
		glPopMatrix();

	}
	else {
		obj = VASI2;
		if (pp->z != -6850.0f) temp1 = pp->y / (-6850.0f - pp->z);
		if (pp->z != -7500.0f) temp2 = pp->y / (-7500.0f - pp->z);


		glPushMatrix();
		setColor(temp1 < 10.0 / 200.0 ? red : white);
		setColor(white);
		glTranslatef(0.0, 0.0, -7700.0);
		make_vasi_lights();
		setColor(temp2 < 10.0 / 200.0 ? red : white);
		glTranslatef(0.0, 0.0, -700.0);
		make_vasi_lights();
		glPopMatrix();
	}

}

