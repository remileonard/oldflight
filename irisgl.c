#include "irisgl.h"

void polf2s(int nbvert, GLshort vertex[][2]) {
	int i;
	glBegin(GL_POLYGON);
	for (i = 0; i < nbvert; i++)
		glVertex2sv(vertex[i]);
	glEnd();
}
void circfs(float p1, float p2, double p3) {
	GLUquadricObj *qobj = gluNewQuadric();
	glPushMatrix();
	glTranslatef(p1, p2, 0.);
	gluDisk(qobj, 0., p3, 32, 1);
	glPopMatrix();
	gluDeleteQuadric(qobj);
}

void polf(int nbvert, GLfloat poly[][3]) {
	draw_poly(poly, nbvert, 0);
}
void closeobj() {
	glEndList();
}
void pnt(float x, float y, float z) {
	glBegin(GL_POINTS);
	glVertex3f(x, y, z);
	glEnd();
}
void pnts(short x, short y, short z) {
	glBegin(GL_POINTS);
	glVertex3s(x, y, z);
	glEnd();
}
void makeobj(int obj) {
	if (glIsList(obj)) {
		glDeleteLists(obj, 1);
	}
	glNewList(obj, GL_COMPILE);
}

void polfs(int nbvert, GLshort poly[][3]) {
	int i;
	GLfloat normal[3] = { 0.0f, 0.0f, 0.0f };
	GLfloat center[3] = { 0.0f, 0.0f, 0.0f };
	GLshort* vc;
	GLshort* vn;
	glBegin(GL_TRIANGLE_FAN);
	for (i = 0; i < nbvert; i++) {
		vc = poly[i];
		vn = poly[i + 1 % nbvert];
		glVertex3sv(poly[i]);
		normal[0] += (vc[1] - vn[1]) * (vc[2] + vn[2]);
		normal[1] += (vc[2] - vn[2]) * (vc[0] + vn[0]);
		normal[2] += (vc[0] - vn[0]) * (vc[1] + vn[1]);
	}
	glNormal3fv(normal);
	glEnd();
}

void color(int colr) {
	setColor(colr);
}
void setpattern(int pat) {
	if (pat) {
		glCallList(pat);
		glEnable(GL_POLYGON_STIPPLE);
	}
	else {
		glDisable(GL_POLYGON_STIPPLE);
	}
}
void defpattern(int pattern, GLubyte *mask) {
	glNewList(pattern, GL_COMPILE);
	glPolygonStipple(mask);
	glEndList();
}
void maketag(int tag) {
	// do nothing for now
}

void rotate(int angle, char axe) {
	glRotatef(.1f * (float) angle, (float) (axe == 'x' || axe == 'X'), (float) (axe == 'y' || axe == 'Y'), (float) (axe == 'z' || axe == 'Z'));
}
void callobj(int obj) {
	glCallList(obj);
}
void translate(float x, float y, float z) {
	glTranslatef(x, y, z);
}
void pushmatrix() {
	glPushMatrix();
}
void popmatrix() {
	glPopMatrix();
}
