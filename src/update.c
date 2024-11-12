#include "../include/update.h"

#define TRANSLATION_X N_COL/2 
#define TRANSLATION_Y N_ROW/2

float convert(int ij, float scale, int translation)
{
	return (ij - translation)/scale;
}

void drawCoordinates(char T[N_ROW][N_COL])
{
	for(int i = 0; i < N_COL; i++)
	{
		for(int j = 0; j < N_ROW; j++)
		{
			if(convert(i, 20, TRANSLATION_X) == 0 && convert(j, 11, TRANSLATION_Y) == 0)
			{
				T[j][i] = '0';	
			}
			else if(convert(i, 20, TRANSLATION_X) == 0)
			{
				T[j][i] = '|';
			}
			else if(convert(j, 11, TRANSLATION_Y) == 0)
			{
				T[j][i] = '-';
			}
			else
			{

			}

		}
	}
}

void circle(char T[N_ROW][N_COL], float a, float R, float r, bool on)
{
//	int circ_x = ;
//	int circ_y = ;


	for(int i = 0; i < N_COL; i++)
	{
		for(int j = 0; j < N_ROW; j++)
		{
			if(pow(convert(i, 20, N_COL/2), 2) + (pow(convert(j, 11, N_ROW/2), 2))/a >= r && pow(convert(i, 20, N_COL/2),2) + pow(convert(j, 11, N_ROW/2), 2) <= R)
			{
				T[j][i] = '#';
			}
			else
			{
				if(on)
				{
					T[j][i] = ' ';
				}
				else
				{

				}
			}
		}
	}
}

void move(char object[N_ROW][N_COL], float dx, float dy)
{
		
}

void update(float up_ti, char T[N_ROW][N_COL])
{

	//loadFixedCharMatrixFromFile("data.txt", T);
/*
	float a = 0;
	static float t = 0;
	t = t + up_ti;
	float w = M_PI*1./2.;
	a = sin(w*t)/3 + 1./3.;
	circle(T, a, 2, 1, 1);

	circle(T, 1, 0.2, 0, 0);
*/
	drawCoordinates(T);

}
