#include "main.h"

#ifndef __COLOR_LIST_
#define __COLOR_LIST_

enum {
	black,
	blue,
	green, 
	cyan, 
	red, 
	purple, 
	brown, 
	lightgray, 
	darkgray, 
	lightblue, 
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

#endif

void init(); 
void gotoxy(int, int);
void setColor(int, int);

 



