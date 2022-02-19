#pragma once
//map size
const int height = 20;
const int  width  = 20;
//position
int cordX, cordY, appleX, appleY;
bool gameOn;
//movement
const int STOP = 0;
const int UP  = 1;
const int LEFT = 2;
const int DOWN = 3;
const int RIGHT = 4;

int direction = STOP;
