#include "graph.h"
#include "objects.h"
#include "bitmap.h"

#include "flight.h"

void make_house() {
	float murnort[][3] = {
		4,0,4,
		4,4,4,
		-4,4,4,
		-4,0,4,
		4,0,4,
	};
	float mursud[][3] = {
		4,0,-4,
		4,4,-4,
		-4,4,-4,
		-4,0,-4,
		4,0,-4,
	};
	float murest[][3] = {
		4,0,-4,
		4,4,-4,
		4,4,4,
		4,0,4,
		4,0,-4,
	};
	float murouest[][3] = {
		-4,0,-4,
		-4,4,-4,
		-4,4,4,
		-4,0,4,
		-4,0,-4,
	};
	float toit2[][3] = {
		4.4,4,4.4,
		0,6,4.4,
		0,6,-4.4,
		4.4,4,-4.4
	};
	float toit3[][3] = {
		0,6,4.4,
		-4.4,4,4.4,
		-4.4,4,-4.4,
		0,6,-4.4
	};
	float toit4[][3] = {
		4.4,4,4.4,
		0,6,4.4,
		-4.4,4,4.4
	};
	float toit5[][3] = {
		4.4,4,-4.4,
		0,6,-4.4,
		-4.4,4,-4.4
	};

	if (glIsList(HOUSE)) {
		glDeleteLists(HOUSE, 1);
	}

	glNewList(HOUSE, GL_COMPILE);
	glEnable(GL_NORMALIZE);
	setColor(tan0);	
	draw_poly(murest, 4, 0);
	setColor(tan0+1);
	draw_poly(mursud, 4, 0);
	setColor(tan0+2);
	draw_poly(murnort, 4, 0);
	setColor(tan0 + 3);
	draw_poly(murouest, 4, 0);
	

	setColor(orange0 +1);
	draw_poly(toit3, 4, 0); 
	setColor(orange0 + 2);
	draw_poly(toit4, 3, 0);
	setColor(orange0 + 3);
	draw_poly(toit2, 4, 0);
	setColor(orange0 + 4);
	draw_poly(toit5, 3, 0);
	glDisable(GL_NORMALIZE);
	glEndList();
}
void make_my_building(int obj, int col, int llx, int lly, int llz, int dx, int dy, int dz, float segments) {
	
	
	

	float segh = dy / segments;
	float windowsHigh = segh/ segments;
	
	float by = 0.0f;
	float wy = segh - windowsHigh;
	if (segments == 1) {
		wy = segh;
	}

	if (glIsList(obj)) {
		glDeleteLists(obj, 1);
	}


	glNewList(obj, GL_COMPILE);
	glEnable(GL_NORMALIZE);
	for (int j = 0; j < segments; j++) {

		float north[][3] = {
			llx,		lly+by,					llz,
			llx,		lly+wy,					llz,
			llx+dx,		lly+wy,					llz,
			llx+dx,		lly+by,					llz
		};
		float south[][3] = {
			llx+dx,		lly + by,				llz + dz,
			llx+dx,		lly + wy,				llz + dz,
			llx,		lly + wy,				llz + dz,
			llx,		lly + by,				llz + dz
		};
		float east[][3] = {
			llx + dx,	lly + by,				llz + 0,
			llx + dx,	lly + by,				llz + dz,
			llx + dx,	lly + wy,				llz + dz,
			llx + dx,	lly + wy,				llz + 0,
		};
		float west[][3] = {
			llx + 0,	lly + by,				llz + dz,
			llx + 0,	lly + wy,				llz + dz,
			llx + 0,	lly + wy,				llz + 0,
			llx + 0,	lly + by,				llz + 0,
		};

		float bnorth[][3] = {
			llx + 0,	lly + wy,				llz + 0,
			llx + 0,	lly + wy+windowsHigh,	llz + 0,
			llx + dx,	lly + wy+windowsHigh,	llz + 0,
			llx + dx,	lly + wy,				llz + 0
		};
		float bsouth[][3] = {
			llx + dx,	lly + wy,				llz + dz,
			llx + dx,	lly + wy+windowsHigh,	llz + dz,
			llx + 0,	lly + wy+windowsHigh,	llz + dz,
			llx + 0,	lly + wy,				llz + dz
		};
		float beast[][3] = {
			llx + dx,	lly + wy,				llz + 0,
			llx + dx,	lly + wy,				llz + dz,
			llx + dx,	lly + wy+windowsHigh,	llz + dz,
			llx + dx,	lly + wy+windowsHigh,	llz + 0,
		};
		float bwest[][3] = {
			llx + 0,	lly + wy,				llz + dz,
			llx + 0,	lly + wy+windowsHigh,	llz + dz,
			llx + 0,	lly + wy+windowsHigh,	llz + 0,
			llx + 0,	lly + wy,				llz + 0,
		};

		setColor(col+1);
		draw_poly(north, 4, 0);

		setColor(col + 2);
		draw_poly(east, 4, 0);
		setColor(col+3);
		draw_poly(south, 4, 0);
		setColor(col + 4);
		draw_poly(west, 4, 0);
		if (segments != 1) {
			by = wy;
		}
		
		if (segments > 1 && j< segments-1) {
			dimColor(col + 1);
			draw_poly(bnorth, 4, 0);
			dimColor(col + 2);
			draw_poly(beast, 4, 0);
			dimColor(col + 3);
			draw_poly(bsouth, 4, 0);
			dimColor(col + 4);
			draw_poly(bwest, 4, 0);
			by = wy + windowsHigh;
		}
		wy = by + segh;
	}
	if (segments == 1) {
		by += wy;
	}
	float top[][3] = {
		llx + 0,	lly + by,	llz + 0,
		llx + 0,	lly + by,	llz + dz,
		llx + dx,	lly + by,	llz + dz,
		llx + dx,	lly + by,	llz + 0
	};
	setColor(col);
	draw_poly(top, 4, 0);
	glDisable(GL_NORMALIZE);
	glEndList();

}
void make_tree() {
	float i;
	float triangleAmount = 5.0f; //# of triangles used to draw circle
	int flow = 0;
	float x, y, z;
	x = 0;
	y = 10+25;
	z = 0;

	GLfloat twicePi = 2.0f * M_PI;
	GLfloat rradius = 10.0f;
	float inc = 2.0f*M_PI / triangleAmount;
	glNewList(TREE,GL_COMPILE);
	glEnable(GL_NORMALIZE);
	setColor(lime0);
	int pass = 0;
	for (i = 0; i <= 2.0f*M_PI; i+=inc) {
		switch (pass % 3) {
		case 0:
			setColor(lime0+2);
			break;
		case 1:
			setColor(lime0+3);
			break;
		case 2:
			setColor(lime0+4);
			break;
		}
		glBegin(GL_TRIANGLES);
		glVertex3f(x, y, z);
		glVertex3f(
			x + (rradius * cos(i)),
			10,
			z + (rradius * sin(i))
		);
		glVertex3f(
			x + (rradius * cos(i+inc)),
			10,
			z + (rradius * sin(i+inc))
		);
		glEnd();
		pass++;
	}
	rradius /= 10;
	for (i = 0; i <= 2.0f*M_PI; i += inc) {
		switch (pass % 3) {
		case 0:
			setColor(tan0 + 2);
			break;
		case 1:
			setColor(tan0 + 3);
			break;
		case 2:
			setColor(tan0 + 4);
			break;
		}
		glBegin(GL_QUADS);
		glVertex3f(
			x + (rradius * cos(i)),
			0,
			z + (rradius * sin(i))
		);
		glVertex3f(
			x + (rradius * cos(i)),
			10+20,
			z + (rradius * sin(i))
		);
		glVertex3f(
			x + (rradius * cos(i+inc)),
			10+20,
			z + (rradius * sin(i+inc))
		);
		glVertex3f(
			x + (rradius * cos(i + inc)),
			0,
			z + (rradius * sin(i + inc))
		);
		glEnd();
		pass++;
	}
	glDisable(GL_NORMALIZE);
	glEndList();
}
void init_textures() {
	GLuint boundTexture = 0;
	glEnable(GL_TEXTURE_2D);
	glGenTextures(2, texID);

	glBindTexture(GL_TEXTURE_2D, texID[0]);
	glGetIntegerv(GL_TEXTURE_BINDING_2D, (GLint*)&boundTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 32, 32, 0, GL_RGBA, GL_UNSIGNED_BYTE, &terain);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, texID[1]);
	glGetIntegerv(GL_TEXTURE_BINDING_2D, (GLint*)&boundTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 32, 32, 0, GL_RGBA, GL_UNSIGNED_BYTE, &herbes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glDisable(GL_TEXTURE_2D);
}

void make_textures_cube() {
	glNewList(TEXTCUBE, GL_COMPILE);
	glColor4f(1.0f,1.0f, 1.0f,1.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texID[0]);
	glBegin(GL_QUADS);
	// Front Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, -10.0f, 10.0f);  // Bottom Left Of The Texture and Quad
		glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0f, -10.0f, 10.0f);  // Bottom Right Of The Texture and Quad
		glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0f, 10.0f, 10.0f);  // Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f, 10.0f, 10.0f);  // Top Left Of The Texture and Quad
		// Back Face
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, -10.0f, -10.0f);  // Bottom Right Of The Texture and Quad
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f, 10.0f, -10.0f);  // Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, 1.0f); glVertex3f(10.0f, 10.0f, -10.0f);  // Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f(10.0f, -10.0f, -10.0f);  // Bottom Left Of The Texture and Quad
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f, 10.0f, -10.0f);  // Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, 10.0f, 10.0f);  // Bottom Left Of The Texture and Quad
		glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0f, 10.0f, 10.0f);  // Bottom Right Of The Texture and Quad
		glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0f, 10.0f, -10.0f);  // Top Right Of The Texture and Quad
		// Bottom Face
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texID[1]);
	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f, -10.0f, -10.0f);  // Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, 1.0f); glVertex3f(10.0f, -10.0f, -10.0f);  // Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f(10.0f, -10.0f, 10.0f);  // Bottom Left Of The Texture and Quad
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, -10.0f, 10.0f);  // Bottom Right Of The Texture and Quad
		// Right face
		glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0f, -10.0f, -10.0f);  // Bottom Right Of The Texture and Quad
		glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0f, 10.0f, -10.0f);  // Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, 1.0f); glVertex3f(10.0f, 10.0f, 10.0f);  // Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f(10.0f, -10.0f, 10.0f);  // Bottom Left Of The Texture and Quad
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, -10.0f, -10.0f);  // Bottom Left Of The Texture and Quad
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, -10.0f, 10.0f);  // Bottom Right Of The Texture and Quad
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f, 10.0f, 10.0f);  // Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f, 10.0f, -10.0f);  // Top Left Of The Texture and Quad
	glEnd();
	
	glDisable(GL_TEXTURE_2D);
	glEndList();
}
void init_light(float sunpos) {

	// i would like the light to originate from an upper corner
	// directed to the opposing lower corner (across the room basically)

	//GLfloat lightPosition[] = { 0, 100000, sunpos, 1 };
	GLfloat lightPosition[] = { -1.0f, -5.0f, 10.0f, 0.0f };
	GLfloat lightDirection[] = { 0, -1, -1, 1 };
	GLfloat ambientLight[] = { 0.5f, 0.5f, 0.5f, 0.5f };
	GLfloat diffuseLight[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightDirection);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	//glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.8f);
	//sunpos += 1000;
}
void free_camera(gameState *gs) {
	rotateVector(&gs->camera, gs->cyaw, gs->cpitch);
	normalizeVector(&gs->camera);
}

void create_pattern() {

	GLubyte shadow_pattern[] = {
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55
	};

	GLubyte crash_pattern[32] = {
		0x00,0x07,0x00,0x00e,0x00,0x1c,0x00,0x38,
		0x00,0x70,0x00,0xe0,0x01,0xc0,0x03,0x80,
		0x07,0x00,0x0e,0x00,0x1c,0x00,0x38,0x00,
		0x70,0x00,0xe0,0x00,0xc0,0x01,0x80,0x03,
	};
	defpattern(3, shadow_pattern);
	defpattern(1, crash_pattern);
}
void make_mountain_zone(int x, int y, int size, struct gameState *gs) {


	int increment = size / 4;
	float mountain[10000][3];
	
	int cpt = 0;
	int squares = 0;
	float height = 0;
	float prevhght = 0;
	float dy = 0;
	for (int i = -size ; i <= size; i += increment) {
		for (int j = -size; j <= size; j += increment) {
			dy = mrandom(3);
			if (dy > 0) {
				height += increment;
			}
			else if (!((dy > -2) && (dy < 2))) {
				height -= increment;
			}
			if (height < 0) {
				height = 0;
			}
			if ((i == -size) || (j == -size)) {
				height = 0;
			}
			if ((i > size-increment) || (j >size- increment)) {
				height = 0;
			}
			mountain[cpt][0] = i;
			mountain[cpt][1] = height;
			mountain[cpt][2] = j;
			cpt++;
		}
		squares++;
		height = 0;
	}
	for (int i = 1; i < squares - 2; i++) {
		for (int j = 1; j < squares - 2; j++) {
			if ((mountain[(i*squares + j)][1] == 0) && ((mountain[(i - 1) * squares + j][1] > 0) || (mountain[(i + 1) * squares + j][1] > 0))) {
				mountain[(i*squares + j)][1] = (mountain[(i - 1) * squares + j][1] + mountain[(i + 1) * squares + j][1]) / 2.0f;
			}
			
		}
	}
	glNewList(MYMOUNTAIN, GL_COMPILE);
	glScalef(1.5, 1.0, 1.0);
	int c = 0;
	glBindTexture(GL_TEXTURE_2D, texID[1]);
	glEnable(GL_NORMALIZE);
	for (int i =0; i< squares-1; i++) {
		for (int j = 0; j < squares-1; j++) {
			glBegin(GL_POLYGON);
			c = mountain[(i*squares + j + 1)][1]/3.0;
			setColor(grey1 + (c % 4));
				glTexCoord2f(0.0f, 0.0f);
				glVertex3fv(mountain[(i*squares+j)]);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3fv(mountain[(i*squares + j+1)]);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3fv(mountain[(i+1)*squares + j]);
			glEnd();
			c = mountain[(i + 1)*squares + j + 1][1]/3.0;
			glBegin(GL_POLYGON);
			setColor(grey1 + (c % 4));
				glTexCoord2f(1.0f, 0.0f);
				glVertex3fv(mountain[(i*squares + j + 1)]);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3fv(mountain[(i + 1)*squares + j+1]);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3fv(mountain[(i + 1)*squares + j]);
			glEnd();
			c++;
		}
	}
	glDisable(GL_NORMALIZE);
	glEndList();
}