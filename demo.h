#pragma once
#include "flight.h"
typedef struct demoinput {
	int msx;
	int msy;
	int throttle;
	int flaps;
	int spoilers;
	int gears;
	int framecounter;
	enum GAMEVIEW cameraview;
	float cameraZoom;
	int gotoNext;
} demoinput;

#define maxdemo 10
 static demoinput demo[maxdemo] = {
	{0,0,0,0,0,1,10,TOWER,5.0f,0},
	{0,0,0,30,0,1,20,TOWER,5.0f,0},
	{600,350+100,100,30,0,1,500,TOWER,5.0f,0},
	{600,350,100,0,0,0,600,TOWER,5.0f,0},
	{750,400,100,0,0,0,800,TOWER,5.0f,0},
	{600,450,100,0,0,0,1800,WINGMAN,1.0f,0},
	{400,400,100,0,0,0,2000,FREE,45.0f,0},
	{600,400,100,0,0,0,2220,FREE,45.0f,0},
	{750,500,100,0,0,0,2560,FREE,45.0f,0},
	{600,400,100,0,0,0,3000,FREE,45.0f,2},
};

 static int demoCounter;