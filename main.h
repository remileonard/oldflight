#pragma once
#include "graph.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>


#include "bitmap.h"
#include "colors.h"
#include "demo.h"
#include "flight.h"
#include "maths.h"
#include "planes.h"
#include "sgilogo.h"
#include "uflight.h"
#include "meters.h"

#pragma warning(disable : 4996)
#pragma warning(disable : 4244)
void free_memory();
void mouse_mouve(int x, int y);
void mouse_click(int button, int state, int x, int y);
void draw_presentation(void);
void reshape(int width, int height);
void reshape_2d(int width, int height);
void special_key(int k, int x, int y);
void simul_key(unsigned char k, int x, int y);
void object_viewer_key(unsigned char k, int x, int y);
void object_special_viewerKey(int k, int x, int y);
void presentation_key(unsigned char k, int x, int y);
void getTime();
void idle(void);
void visible(int vis);
void flight_simulation();
void flight_demo_simulation(int va);
void init_game(unsigned char k);
void init_demo(int va);
void init_presentation(int va);
void draw_3D_viewer(void);
void init_3D_viewer(int va);
int main_start(int argc, char *argv[]);



static GLfloat logorotate = 45.0f;
static GLuint object3Dview = F15;

static int msx, msdx;
static int msy, msdy;


static int cz = 0;
static float frames;

static plane* lpp = NULL;
static gameState* lgs = NULL;



static int message = 1;
static int windows = 0;
static int fullscreen = 0;
static int moveok = 0;
static int zoomok = 0;