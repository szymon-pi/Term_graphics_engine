#include "../include/render.h"
#include "../include/update.h"
#include "../include/termparams.h"



/*
void renderScene()
{
	
	//local space ---> world space ---> view space ---> clip space ---> screen space
}
*/






int main()
{
	struct termios oldt;
	tcgetattr(STDIN_FILENO, &oldt);
	changeTerminalParamToNew(&oldt);

	char T[N_ROW][N_COL]; 
	cleanMatrix(T);

	struct timespec start, end;
	float dt = 0;

	while(1)
	{
		clock_gettime(CLOCK_MONOTONIC, &start);
		int size[2];
		getTerminalSize(size);

		//circle(T, 20);
		update(UPDATE_TIME, T);
		renderScene(size[0], size[1], T);	
		
		//usleep(100);
		clock_gettime(CLOCK_MONOTONIC, &end);

		dt = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/1e9;

		if(dt < UPDATE_TIME)
		{
			usleep((UPDATE_TIME - dt) * 1e6);
		}
	}
	changeTerminalParamToOld(&oldt);
//	printf("%f", dt);
}
