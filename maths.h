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
inline void matrix4x4f_copy(matrix4x4f s, matrix4x4f d)
{
	memcpy(d, s, sizeof(matrix4x4f));
}
inline void matrix4x4f_translate(float x, float y, float z, float matrix[16])
{
	matrix4x4f_copy(identity_4x4f,matrix);
	matrix[12] = x;
	matrix[13] = y;
	matrix[14] = z;
}

inline void matrix4x4f_scale(float x, float y, float z, float matrix[16])
{
	matrix4x4f_copy(identity_4x4f,matrix);
	matrix[0] = x;
	matrix[5] = y;
	matrix[10] = z;
}

inline void matrix4x4f_rotate(float a, float x, float y, float z, float matrix[16])
{
	float c, s, t;
	float rangle = a / 1800.0f *M_PI;
	c = (float)cos(rangle);
	s = (float)sin(rangle);
	t = 1.0f - c;

	matrix[0] = t * x * x + c;
	matrix[1] = t * x * y + s * z;
	matrix[2] = t * x * z - s * y;
	matrix[3] = 0;

	matrix[4] = t * x * y - s * z;
	matrix[5] = t * y * y + c;
	matrix[6] = t * y * z + s * x;
	matrix[7] = 0;

	matrix[8] = t * x * z + s * y;
	matrix[9] = t * y * z - s * x;
	matrix[10] = t * z * z + c;
	matrix[11] = 0;

	matrix[12] = 0;
	matrix[13] = 0;
	matrix[14] = 0;
	matrix[15] = 1;
}

inline void matrix4x4f_mult_matrix4x4f(const matrix4x4f m1, const matrix4x4f m2, matrix4x4f r)
{
	matrix4x4f t;
	int i, j;

	for (j = 0; j < 4; j++)
		for (i = 0; i < 4; i++)
			t[i * 4 + j] = m1[i * 4 + 0] * m2[0 * 4 + j] +
			m1[i * 4 + 1] * m2[1 * 4 + j] +
			m1[i * 4 + 2] * m2[2 * 4 + j] +
			m1[i * 4 + 3] * m2[3 * 4 + j];

	matrix4x4f_copy(t, r);
}