#pragma once
#define M_PI 3.14159265358979323846f
#include <math.h>
#include <string.h>
#ifndef NULL
#define NULL 0
#endif

/*

Some docs on matrix

X rotation matrix
1,0,0,0
0,cos,sin,0
0,-sin,cos,0
0,0,0,1

Y rotaton matrix
cos,0,-sin,0
0,1,0,0
sin,0,cos,0
0,0,0,1

Z rotation matrix
cos,sin,0,0
-sin,cos,0,0
0,0,1,0
0,0,0,1

Translation matrix
1,0,0,0
0,1,0,0
0,0,1,0
dx,dy,dz,1

Scaling matrix
sx,0,0,0
0,sy,0,0
0,0,sz,0
0,0,0,1

Identity matrix
1,0,0,0
0,1,0,0
0,0,1,0
0,0,0,1

*/

/*
		camera move straf
		// camera cross (0, 1, 0)
		// normalize
		// add value * factor
*/
typedef struct Vector {
	float x;
	float y;
	float z;
} Vector;
typedef float matrix4x4f[16];

void gl_sincos(float a, float* b, float* c);
void rotateM(float m[][4], float angle, float x, float y, float z);
void rotateNM(float m[][4], float angle, float x, float y, float z);
void translateM(float m[][4], float x, float y, float z);
void translateNM(float m[][4], float x, float y, float z);
void addMatrix(float a[][4], float b[][4]);
void mulMatrix(float a[][4], float b[][4]);
void mulnoMatrix(float a[][4], float b[][4]);
void setIdentity(float m[][4]);
void normalizeVector(Vector *v);
void rotateVector(Vector *v, float yaw, float pitch);
void crossVector(Vector *a, Vector *b);
int mrandom(int maxr);

static matrix4x4f identity_4x4f = {
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1,
};
void matrix4x4f_copy(matrix4x4f s, matrix4x4f d);
void matrix4x4f_translate(float x, float y, float z, float matrix[16]);
void matrix4x4f_scale(float x, float y, float z, float matrix[16]);
void matrix4x4f_rotate(float a, float x, float y, float z, float matrix[16]);
void matrix4x4f_mult_matrix4x4f(const matrix4x4f m1, const matrix4x4f m2, matrix4x4f r);