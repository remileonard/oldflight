#pragma once
#include "graph.h"
#include "colors.h"
#include "maths.h"
#include "objects.h"
#include "flight_remake.h"


#pragma warning(disable : 4244)


void set_tree(int cx, int cy, int cz, struct gameState *gs);
void make_forest(int x, int y, int size, struct gameState *gs);
void makehouse(int cx, int cy, int cz, struct gameState *gs);
void makebox(int col, int llx, int lly, int llz, int dx, int dy, int dz, int nbstripe, struct gameState *gs);
void set_sun(float x, float y, float z);
void draw_buildings(float rx, float ry, float rz, int start_plane, int num_planes, struct gameState *gs);
void makethreat(int cx, int cz, int col, float radius, struct gameState* gs);
void makemtn(int cx, register int cy, int cz, int n, int savearray[], struct gameState* gs);
void facet(int n, int p[4][3], int col);
void sink_sort(register int n, int *array, int *array_tag);
void make_buildings(int eye_x, int eye_y, int eye_z, struct gameState* gs);
void draw_shadow(struct plane *pp, int nnear);
void genstripe(GLint x1, GLint y1, GLint x2, GLint y2);
void map_daynight(int daytime);
void init_shade(int i, int shade);
void make_explosion();
void make_world(struct gameState *gs);
void make_lights();
void make_vasi_lights();
void reset_building(struct gameState* gs);