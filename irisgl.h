#pragma once
#include "graph.h"


void makeobj(int obj);
void closeobj();
void pnt(float x, float y, float z);
void pnts(short x, short y, short z);
void color(int colr);
void setpattern(int pat);
void maketag(int tag);
void rotate(int angle, char axe);
void callobj(int obj);
void translate(float x, float y, float z);
void pushmatrix();
void popmatrix();
void polf2s(int nbvert, GLshort vertex[][2]);
void circfs(float p1, float p2, double p3);
void defpattern(int pattern, GLubyte *mask);
void polfs(int nbvert, GLshort poly[][3]);
void polf(int nbvert, GLfloat poly[][3]);
