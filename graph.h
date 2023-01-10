#pragma once
// Header File For Windows
#ifdef W32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include "colors.h"
#include "maths.h"

static GLuint texID[3];

void draw_mouse_cursor(int w, int h, int x, int y);
void draw_filled_circle(GLfloat x, GLfloat y, GLfloat radius);
void draw_rect(int x, int y, int w, int h);
void draw_polyi(GLuint poly[][3], int nbvert);
void draw_poly(GLfloat poly[][3], int nbvert, int drawNormal);
void gl_print(char* str, float x, float y);
void gl_print_matrix(float m[4][4], float ystart);
void set_view_screen(double real_fov, int w, int h, int top);
