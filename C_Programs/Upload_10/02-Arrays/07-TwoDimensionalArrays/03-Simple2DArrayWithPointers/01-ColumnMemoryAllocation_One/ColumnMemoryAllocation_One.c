#include <stdio.h>
#include <stdlib.h>
#define NUM_ROWS 5
#define NUM_COLUMNS 3
int main(void)
{
	//variable declarations
	int* iArray_RAD[NUM_ROWS]; 
		int i_RAD, j_RAD;
	//code
	printf("\n\n");
	for (i_RAD = 0; i_RAD < NUM_ROWS; i_RAD++)
	{
		iArray_RAD[i_RAD] = (int*)malloc(NUM_COLUMNS * sizeof(int));
		if (iArray_RAD[i_RAD] == NULL)
		{
			printf("FAILED TO ALLOCATE MEMORY TO ROW %d OF 2D INTEGER ARRAY !!! EXITTING NOW...\n\n", i_RAD);
				exit(0);
		}
		else
				printf("MEMORY ALLOCATION TO ROW %d OF 2D INTEGER ARRAY SUCCEEDED !!!\n\n", i_RAD);
	}
	//ASSIGNING VALUES TO 2D ARRAY ...
	for (i_RAD = 0; i_RAD < NUM_ROWS; i_RAD++)
	{
		for (j_RAD = 0; j_RAD < NUM_COLUMNS; j_RAD++)
		{
			iArray_RAD[i_RAD][j_RAD] = (i_RAD + 1) * (j_RAD + 1);
		}
	}
	//DISPLAYING 2D ARRAY ...
	printf("\n\n");
	printf("DISPLAYING 2D ARRAY : \n\n");
	for (i_RAD = 0; i_RAD < NUM_ROWS; i_RAD++)
	{
		for (j_RAD = 0; j_RAD < NUM_COLUMNS; j_RAD++)
		{
			printf("iArray[%d][%d] = %d\n", i_RAD, j_RAD, iArray_RAD[i_RAD][j_RAD]);
		}
		printf("\n\n");
	}
	printf("\n\n");
	
	for (i_RAD = (NUM_ROWS - 1); i_RAD >= 0; i_RAD--)
	{
		free(iArray_RAD[i_RAD]);
		iArray_RAD[i_RAD] = NULL;
		printf("MEMORY ALLOCATED TO ROW %d Of 2D INTEGER ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n", i_RAD);
	}
	return(0);
}

