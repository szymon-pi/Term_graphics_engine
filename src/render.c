#include "../include/render.h"

void loadFixedCharMatrixFromFile(const char* filename, char matrix[N_ROW][N_COL])
{
    FILE* file = fopen(filename, "r");

    if (!file)
    {
        perror("Failed to open file");
        return;
    }

    int i = 0, j = 0;
    int ch;

    // Read each character one by one, including spaces and newlines
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            // Move to the next row on newline
            i++;
            j = 0;
            if (i >= N_ROW)
            {
                break; // Avoid going beyond the matrix rows
            }
        }
        else
        {
            // Store character in matrix if within bounds
            if (j < N_COL && i < N_ROW)
            {
                matrix[i][j++] = (char)ch;
            }
        }
    }

    fclose(file);
}

// Free memory allocated for the matrix
void freeCharMatrix(char matrix[N_ROW][N_COL], int rows)
{

	for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);

    }

    free(matrix);
}


void cleanMatrix(char T[N_ROW][N_COL])
{
	for(int i = 0; i < N_ROW; i++)
	{
		for(int j = 0; j < N_COL; j++)
		{
			T[i][j] = ' ' ;
		}
	}
}

void renderScene(int y_dim, int x_dim, char T[N_ROW][N_COL])
{
	changeCursorPositionTo(1, 1);
	char pr[y_dim * (x_dim + 1) + 1];
	int k = 0;

	for(int i = 0; i < y_dim; i++)
	{
		for(int j = 0; j < x_dim; j++)
		{
			pr[k] = T[i][j];
			k++;
		}
		pr[k] = '\n';
		k++;
	}
	pr[k] = '\0';
	//usleep(1000); //can work slightly better (I cannot tell the difference)
	printf("%s\n", pr);
//----------------------------------------------------
	/*Debug char by char
	for(int i = 0; i < y_dim*(x_dim + 1) + 1; i++)
	{
		printf("%c", pr[i]);
		fflush(stdout);
	//	printf("%c", pr[i]);
		usleep(800000);
	}
	*/
}

