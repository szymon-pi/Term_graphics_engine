#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#ifndef MAX_TERMINAL_SIZE
#define MAX_TERMINAL_SIZE

#define N_COL  379
#define N_ROW  107

#endif

void changeTerminalParamToNew(struct termios* oldt);
void changeTerminalParamToOld(struct termios* oldt);
void getTerminalSize(int T[]);
