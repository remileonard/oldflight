#include "graph.h"
#include "bitmap.h"

#pragma warning(disable : 4996)
void display_error() {
	int error = glGetError();
	switch (error)
	{
	case GL_INVALID_ENUM:
		printf("invalid enum\n");
		break;
	case GL_INVALID_VALUE:
		printf("invalid value\n");
		break;
	case GL_INVALID_OPERATION:
		printf("invalid operation\n");
		break;
	case GL_NO_ERROR:
		printf("no error\n");
		break;
	default:
		printf("euuuhh\n");
		break;
	}
}
void draw_mouse_cursor(int w, int h, int x, int y) {
	
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glViewport(0, 0, w, h);
	glOrtho(0.0f, w, h, 0.0f, -1.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	setColor(red);
	glRasterPos2i(x-8, y+4);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBitmap(16, 18, 0.0, 0.0, 16, 16, bcursor);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}
void draw_filled_circle(GLfloat x, GLfloat y, GLfloat radius) {
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle
	int flow = 0;

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * M_PI;
	GLfloat rradius= radius;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		flow = mrandom(10);
		if (flow < 0) {
			rradius -= radius * 0.2f;
		}
		else if (flow > 0) {
			rradius += radius * 0.2f;
		}
		if (rradius == 0) {
			rradius += radius * 0.2f;
		}
		glVertex2f(
			x + (rradius * cosf(i *  twicePi / triangleAmount)),
			y + (rradius * sinf(i * twicePi / triangleAmount))
		);
	}
	glEnd();
}
void draw_rect(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
		glVertex2i(x, y);
		glVertex2i(x + w, y);
		glVertex2i(x + w, y + h);
		glVertex2i(x, y + h);
	glEnd();
}

void set_view_screen(double real_fov, int w, int h , int top) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(real_fov, (double)w / (double)h, 1.0, 1.0e9);
	glViewport(0, top, w, h);
	glMatrixMode(GL_MODELVIEW);
}
void gl_print_matrix(float m[4][4], float ystart) {
	unsigned char string[255];
	glPushMatrix();
	glLoadIdentity();
	for (int o = 0; o < 4; o++) {
		sprintf(string, "MAT[%d]=[%f,%f,%f,%f]", o, m[o][0], m[o][1], m[o][2],
			m[o][3]);
		gl_print(string, -1.0f, ystart -= .05f);
	}
	glPopMatrix();
}
void gl_print(char* str, float x, float y) {
	int w;
	w = glutBitmapLength(GLUT_BITMAP_8_BY_13, str);
	glRasterPos2f(x, y);
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str[i]);
	}
}
void draw_polyi(GLuint poly[][3], int nbvert) {
	int i; 
	glBegin(GL_POLYGON); 
	for (i = 0; i < nbvert; i++) {
		glVertex3iv(poly[i]);
	}
	glEnd();
}
void draw_poly(GLfloat poly[][3], int nbvert, int drawNormal) {
	int i;
	GLfloat normal[3] = { 0.0f, 0.0f, 0.0f };
	GLfloat center[3] = { 0.0f, 0.0f, 0.0f };
	GLfloat* vc;
	GLfloat* vn;
	glBegin(GL_TRIANGLE_FAN);
	for (i = 0; i < nbvert; i++) {
		vc = poly[i];
		vn = poly[i + 1 % nbvert];
		glVertex3fv(poly[i]);
		normal[0] += (vc[1] - vn[1]) * (vc[2] + vn[2]);
		normal[1] += (vc[2] - vn[2]) * (vc[0] + vn[0]);
		normal[2] += (vc[0] - vn[0]) * (vc[1] + vn[1]);
		center[0] += poly[i][0];
		center[1] += poly[i][1];
		center[2] += poly[i][2];
	}
	center[0] /= nbvert;
	center[1] /= nbvert;
	center[2] /= nbvert;
	
	/*
	float length = sqrt((normal[0] * normal[0]) + (normal[1] * normal[1]) + (normal[2] * normal[2]));
	normal[0] /= length;
	normal[1] /= length;
	normal[2] /= length;
	*/
	glNormal3fv(normal);
	glEnd();
	if (drawNormal) {
		glBegin(GL_LINE_STRIP);
		glVertex3fv(center);
		glVertex3fv(normal);
		glEnd();
	}
}

#ifdef W32
GLvoid BuildFont(GLuint *base)								// Build Our Bitmap Font
{
	HFONT	font;										// Windows Font ID
	HDC hDC;
	int toto = 0;
	HWND windowHandle = FindWindow(NULL, "Flight");
	HDC deviceContext = GetDC(windowHandle);
	HGLRC renderingContext = wglGetCurrentContext();
	hDC = wglGetCurrentDC();
	if (hDC != NULL) {
		if (*base == 0) {
			*base = glGenLists(96);								// Storage For 96 Characters
		}
		font = CreateFont(-24,							// Height Of Font
			0,								// Width Of Font
			0,								// Angle Of Escapement
			0,								// Orientation Angle
			FW_BOLD,						// Font Weight
			FALSE,							// Italic
			FALSE,							// Underline
			FALSE,							// Strikeout
			ANSI_CHARSET,					// Character Set Identifier
			OUT_TT_PRECIS,					// Output Precision
			CLIP_DEFAULT_PRECIS,			// Clipping Precision
			ANTIALIASED_QUALITY,			// Output Quality
			FF_DONTCARE | DEFAULT_PITCH,		// Family And Pitch
			"Courier New");					// Font Name
		if (font != NULL && *base != 0) {
			SelectObject(hDC, font);							// Selects The Font We Want

			toto = wglUseFontBitmaps(hDC, 32, 96, *base);
			if (toto == 0) {
				DWORD err = GetLastError();
				if (err != 0) {
					printf("error %ld\n", err);
				}
				else {
					toto = 1;
				}
			}
		}
	}
}
#endif
GLvoid glPrint(char* text, int base)								// Custom GL "Print" Routine
{
	if (text == NULL)									// If There's No Text
		return;											// Do Nothing

	glPushAttrib(GL_LIST_BIT);							// Pushes The Display List Bits
	glListBase(base - 32);								// Sets The Base Character to 32
	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);	// Draws The Display List Text
	printf("%s\n",text);
	glPopAttrib();										// Pops The Display List Bits
}