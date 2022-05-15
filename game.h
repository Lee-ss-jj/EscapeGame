#include "main.h"

#ifndef KEY_CODE
#define KEY_CODE

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

#endif

void gLoop(int);
void move(int*, int*, int, int, int*, int*); // x, y, _x, _y, key, playing
int keyControl();
void titleDraw();
int menuDraw(); 
int maplistDraw();
void infoDraw();
void drawMap(int*, int*);
void drawUI(int*, int*, int*);







