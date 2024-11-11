#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include "termparams.h"

#ifndef UPDATE
#define UPDATE

//const float UPDATE_TIME = 1.0f/30.0f;
#define UPDATE_TIME 1.0f/30.0f

#endif

float convert(int ij, float scale, int translation);
void circle(char T[N_ROW][N_COL], float a, float R, float r, bool on);
void update(float up_ti, char T[N_ROW][N_COL]);
