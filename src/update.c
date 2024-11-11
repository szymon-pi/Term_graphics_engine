#include "../include/update.h"

float convert(int ij, float scale, int translation)
{
	return (ij - translation)/scale;
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

void update(float up_ti, char T[N_ROW][N_COL])
{

	//loadFixedCharMatrixFromFile("data.txt", T);

	float a = 0;
	static float t = 0;
	t = t + up_ti;
	float w = M_PI*1./2.;
	a = sin(w*t)/3 + 1./3.;
	circle(T, a, 2, 1, 1);

	circle(T, 1, 0.2, 0, 0);

}
