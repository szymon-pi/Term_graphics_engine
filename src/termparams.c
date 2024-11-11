#include "../include/termparams.h"

void changeTerminalParamToNew(struct termios* oldt)
{
	struct termios newt;

	newt = *oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void changeTerminalParamToOld(struct termios* oldt)
{
	tcsetattr(STDIN_FILENO, TCSANOW, oldt);
}

void changeCursorPositionTo(int i, int j)
{
	char first_coord[5];
	char second_coord[5];
	char esc_code[] = "\033[";
	char position[17];

	position[0] = '\0';

	sprintf(first_coord, "%d", i);
	sprintf(second_coord, "%d", j);

	strcat(position, esc_code);
	strcat(position, first_coord);
	strcat(position, ";");
	strcat(position, second_coord);
	strcat(position, "H");

	//printf("%s\n", position);
	write(STDOUT_FILENO, position, strlen(position));
}

void getTerminalSize(int T[])
{
	int r = 0;
	int c = 0;

	char buf[64];

	changeCursorPositionTo(1000,1000);
	write(STDOUT_FILENO, "\033[6n", 5);

	ssize_t n = read(STDIN_FILENO, buf, sizeof(buf) - 1);

	if(n > 0)
	{
		buf[n] = '\0';
		if(sscanf(buf, "\033[%d;%dR", &r, &c) == 2)
		{
			T[0] = r;
			T[1] = c;
			//printf("%d, %d\n", r, c);
		}
		else
		{
			printf("Failed to parse cursor position\n");
		}
	}
	else
	{
		printf("Failed to read cursor position\n");
	}

	changeCursorPositionTo(1,1);
	usleep(10000);
}
