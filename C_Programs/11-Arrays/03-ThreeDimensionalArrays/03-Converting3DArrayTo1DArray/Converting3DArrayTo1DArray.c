#include <stdio.h>
#define NUM_ROWS 5
#define NUM_COLUMNS 3
#define DEPTH 2

int main(void)
{
	//variable declarations

	//IN-LINE INITIALIZATION
	int iArray_RAD[NUM_ROWS][NUM_COLUMNS][DEPTH] = { {{9, 18}, {27, 36}, {45, 54}},
													{{8, 16}, {24, 32}, {40, 48}},
													{{7, 14}, {21, 28}, {35, 42}},
													{{6, 12}, {18, 24}, {30, 36}},
													{{5, 10}, {15, 20}, {25, 30}} };

	int i_RAD, j_RAD, k_RAD;

	int iArray_RAD_1D[NUM_ROWS * NUM_COLUMNS * DEPTH];

	//code

	//**********DISPLAY 3D ARRAY
	printf("\n\n");
	printf("Elements In The 3D Array : \n\n");
	for (i_RAD = 0; i_RAD = NUM_ROWS; i_RAD++)
	{
		printf("************ROW %d ********\n", (i_RAD + 1));
		for (j_RAD = 0; j_RAD < NUM_COLUMNS; j_RAD++)
		{
			printf("*********COLUMN %d *************\n", (j_RAD + 1));
			for (k_RAD = 0; k_RAD < DEPTH; k_RAD++)
			{
				printf("iArray[%d][%d][%d] = %d\n", i_RAD, j_RAD, k_RAD, iArray_RAD[i_RAD][j_RAD][k_RAD]);
			}
			printf("\n");
		}
		printf("\n");
	}
	// ********CONVERTING 3D TO 1D ***************
	for (i_RAD = 0; i_RAD < NUM_ROWS; i_RAD++)
	{
		for (j_RAD = 0; j_RAD < NUM_COLUMNS; j_RAD++)
		{
			for (k_RAD = 0; k_RAD < DEPTH; k_RAD++)
			{
				iArray_RAD_1D[(i_RAD * NUM_COLUMNS * DEPTH) + (j_RAD * DEPTH) + k_RAD] = iArray_RAD[i_RAD][j_RAD][k_RAD];

			}
		}
	}
	//**********DISPLAYING 1D ARRAY***************

	printf("\n\n\n\n");
	printf("Elements In The 1D Array : \n\n");
	for (i_RAD = 0; i_RAD < (NUM_ROWS * NUM_COLUMNS * DEPTH); i_RAD++)
	{
		printf("iArray_1D[%d] = %d\n", i_RAD, iArray_RAD_1D[i_RAD]);

	}
	return(0);
}




