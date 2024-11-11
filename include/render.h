#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include "termparams.h"

void loadFixedCharMatrixFromFile(const char* filename, char matrix[N_ROW][N_COL]);
void freeCharMatrix(char matrix[N_ROW][N_COL], int rows);
void cleanMatrix(char T[N_ROW][N_COL]);
void renderScene(int y_dim, int x_dim, char T[N_ROW][N_COL]);
void changeCursorPositionTo(int i, int j);


