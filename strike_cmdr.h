#pragma once
typedef struct plane;

void init_SC();
float getY(float x, float z);
void setStartPosition(plane* pp);
void setTowerView(gameState* gs);
void getRadarSpot(gameState* gs);
int isOnRunWay(plane* pp);