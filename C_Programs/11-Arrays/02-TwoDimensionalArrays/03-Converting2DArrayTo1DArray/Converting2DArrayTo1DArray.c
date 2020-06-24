#include<stdio.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
	//variable declarations

	int iArray_RAD_2D[NUM_ROWS][NUM_COLUMNS];
	int iArray_RAD_1D[NUM_ROWS * NUM_COLUMNS];

	int i_RAD, j_RAD;
	int num_RAD;

	//code
	printf("Enter Elements of Your Choice To Fill Up The Integer 2D Array : \n\n");
	for (i_RAD = 0; i_RAD < NUM_ROWS; i_RAD++)
	{
		printf("For ROW NUMBER %d : \n", (i_RAD + 1));
		for (j_RAD = 0; j_RAD < NUM_COLUMNS; j_RAD++)
		{
			printf("Enter Element Number %d : \n", (j_RAD + 1));
			scanf("%d", &num_RAD);
			iArray_RAD_2D[i_RAD][j_RAD] = num_RAD;

		}
		printf("\n\n");

	}

	printf("\n\n");
	printf("Two-Dimensional (2D) Array of Integer : \n\n");
	for (i_RAD = 0; i_RAD < NUM_COLUMNS; i_RAD++)
	{
		printf("**********ROW %d*************\n", (i_RAD + 1));
		for (j_RAD = 0; j_RAD < NUM_ROWS; j_RAD++)
		{
			printf("iArray_RAD_2D[%d][%d] = %d\n", i_RAD, j_RAD, iArray_RAD_2D[i_RAD][j_RAD]);
		}
		printf("\n\n");
	}

	for (i_RAD = 0; i_RAD < NUM_ROWS; i_RAD++)
	{
		for (j_RAD = 0; j_RAD < NUM_COLUMNS; j_RAD++)
		{
			iArray_RAD_1D[(i_RAD * NUM_COLUMNS) + j_RAD] = iArray_RAD_2D[i_RAD][j_RAD];

		}

		printf("\n\n");
		printf("One-Dimensional (1D) Array of Integers : \n\n");
		for (i_RAD = 0; i_RAD < (NUM_ROWS * NUM_COLUMNS); i_RAD++)
		{
			printf("iArray_1D[%d] = %d\n", i_RAD, iArray_RAD_1D[i_RAD]);
		}

		printf("\n\n");
		return(0);
	}
} 


