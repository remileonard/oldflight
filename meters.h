#pragma once
#include "graph.h"
#include "colors.h"
#include "flight.h"



#define OBJ_G_METER			8584
#define OBJ_HEADING_METER	8585

void create_g_metter();
void create_heading();
void text_meter();
void bar_meter(float x, float y, int val);
void make_meters();
void genbar(int x, int y);
void draw_blanking();
void draw_meter(int llx, int val);
void change_rudder(float rudder);
void display_heading(plane *lpp, float X_ADJUST, float Y_ADJUST);
void display_artificial_horizon(plane *lpp, float X_ADJUST, float Y_ADJUST);
void display_meters(plane *lpp);
void draw_cockpit(plane *pp, GLubyte *halftone, int w, int h, float X_ADJUST, float Y_ADJUST);
void draw_hud(gameState *gs, plane *pp, int w, int h, float X_ADJUST, float Y_ADJUST);