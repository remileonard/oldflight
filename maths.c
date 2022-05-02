#include "maths.h"
#include <math.h>

void gl_sincos(float a, float* b, float* c) {
	if (b != NULL) {
		*b = sinf((a) / 1800.0f * M_PI);
	}
	if (c != NULL) {
		*c = cosf((a) / 1800.0f * M_PI);
	}
}

void setIdentity(float m[][4]) {
	float identity[4][4] = {
		{1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1}
	};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m[i][j] = identity[i][j];
		}
	}
}
// mul a by b store result in a
void mulMatrix(float a[][4], float b[][4]) {
	float result[4][4] = {
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};

	/*
	*	matrix 4x4
		c00 = a00xb00+a01xb10+a02xb20+a03xb30
		c01 = a00xb10+a01xb11+a02xb12+a03xb13
		c02 = a00xb20+a01xb21+a02xb22+a03xb23
		c03 = a00xb30+a01xb31+a02xb32+a03xb33
	*/

	for (int i = 0; i < 4; i++) {
		result[i][0] = b[i][0] * a[0][0] + b[i][1] * a[1][0] + b[i][2] * a[2][0] + b[i][3] * a[3][0];
		result[i][1] = b[i][0] * a[0][1] + b[i][1] * a[1][1] + b[i][2] * a[2][1] + b[i][3] * a[3][1];
		result[i][2] = b[i][0] * a[0][2] + b[i][1] * a[1][2] + b[i][2] * a[2][2] + b[i][3] * a[3][2];
		result[i][3] = b[i][0] * a[0][3] + b[i][1] * a[1][3] + b[i][2] * a[2][3] + b[i][3] * a[3][3];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = result[i][j];
		}
	}

}

void addMatrix(float a[][4], float b[][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] += b[i][j];
		}
	}
}

void mulnoMatrix(float a[][4], float b[][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = a[i][j] * b[i][j];
		}
	}

}
void translateM(float m[][4], float x, float y, float z) {
	float vector[3] = { x,y,z };
	float transMatrix[4][4] = {
		{1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{x,y,z,1}
	};
	mulMatrix(m, transMatrix);
}
void translateNM(float m[][4], float x, float y, float z) {
	float transMatrix[4][4] = {
		{1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{x,y,z,1}
	};
	matrix4x4f_mult_matrix4x4f((float *)transMatrix, (float *)m, (float *)m);
}
void rotateM(float m[][4], float angle, float x, float y, float z) {
	float radangle = angle / 1800.0f * M_PI;
	float xrot[4][4] = {
		{1					,0				,0					,0},
		{0					,cosf(radangle)	,sinf(radangle)		,0},
		{0					,-sinf(radangle),cosf(radangle)		,0},
		{0					,0				,0					,1}
	};

	float yrot[4][4] = {
		{cosf(radangle)		,0				,-sinf(radangle)	,0}, /* [0][0] [0][1] [0][2] */
		{0					,1				,0					,0}, /* [1][0] [1][1] [1][2] */
		{sinf(radangle)		,0				,cosf(radangle)		,0}, /* [2][0] [2][1] [2][2] */
		{0					,0				,0					,1}  /* [3][0] [3][1] [3][2] */
	};
	float zrot[4][4] = {
		{cosf(radangle)		,sinf(radangle)	,0					,0},
		{-sinf(radangle)	,cosf(radangle)	,0					,0},
		{0					,0				,1					,0},
		{0					,0				,0					,1},
	};
	if (x != 0) {
		mulMatrix(m, xrot);
	}
	if (y != 0) {
		mulMatrix(m, yrot);
	}
	if (z != 0) {
		mulMatrix(m, zrot);
	}
}
void rotateNM(float m[][4], float angle, float x, float y, float z) {
	float c, s, t;
	float rot[4][4];

	float rangle = angle / 1800.0f *M_PI;
	c = (float)cos(rangle);
	s = (float)sin(rangle);
	t = 1.0f - c;

	rot[0][0] = t * x * x + c;
	rot[0][1] = t * x * y + s * z;
	rot[0][2] = t * x * z - s * y;
	rot[0][3] = 0;

	rot[1][0] = t * x * y - s * z;
	rot[1][1] = t * y * y + c;
	rot[1][2] = t * y * z + s * x;
	rot[1][3] = 0;

	rot[2][0] = t * x * z + s * y;
	rot[2][1] = t * y * z - s * x;
	rot[2][2] = t * z * z + c;
	rot[2][3] = 0;

	rot[3][0] = 0;
	rot[3][1] = 0;
	rot[3][2] = 0;
	rot[3][3] = 1;

	matrix4x4f_mult_matrix4x4f((float *)rot, (float *)m , (float *)m);
}

void normalizeVector(Vector *v) {
	float length = sqrtf((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	v->x /= length;
	v->y /= length;
	v->z /= length;
}
void rotateVector(Vector *v, float yaw, float pitch) {
	v->x = cosf(yaw * M_PI/ 180.0f) * cosf(pitch * M_PI / 180.0f);
	v->y = sinf(pitch * M_PI / 180.0f);
	v->z = sinf(yaw * M_PI / 180.0f) * cosf(pitch * M_PI / 180.0f);
}
void crossVector(Vector *a, Vector *b) {
	Vector c = { 0.0f,0.0f,0.0f };

	c.x = b->y*a->z - b->z*a->y;
	c.y = b->z*a->x - b->x*a->z;
	c.z = b->x*a->y - b->y * a->x;

	a->x = c.x;
	a->y = c.y;
	a->z = c.z;
}

/* generate a mrandom number x, where -maxr <= x <= maxr	*/
int mrandom(int maxr)
{
	static unsigned long randx = 1;
	register int n, retval;

	/*for (n = 1; n < 32; n++)
		if ((1 << n) > maxr) break;*/

	for (n = 1; n < 32 && (1 << n) < maxr; n++);

	retval = maxr << 1;
	while (retval > maxr) {
		randx = randx * 1103515245 + 12345;
		retval = (randx & 0x7fffffff) >> (31 - n);
	}
	randx = randx * 1103515245 + 12345;
	if (randx & 0x40000000)
		return (retval);
	else return (-retval);
}