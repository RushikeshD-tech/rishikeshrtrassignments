#include <stdio.h>
#include <stdlib.h>
#define NUM_ROWS 5
#define NUM_COLUMNS 3
int main(void)
{
	//variable declarations
	int iArray_RAD[NUM_ROWS][NUM_COLUMNS];
	int i_RAD, j_RAD;
	//code
	for (i_RAD = 0; i_RAD < NUM_ROWS; i_RAD++)
	{
		for (j_RAD = 0; j_RAD < NUM_COLUMNS; j_RAD++)
			*(iArray_RAD[i_RAD] + j_RAD) = (i_RAD + 1) * (j_RAD + 1); 
	}
	printf("\n\n");
	printf("2D Integer Array Elements Along With Addresses : \n\n");
	for (i_RAD = 0; i_RAD < NUM_ROWS; i_RAD++)
	{
		for (j_RAD = 0; j_RAD < NUM_COLUMNS; j_RAD++)
		{
			printf("*(iArray[%d] + %d)= %d \t \t At Address (iArray[i] + j) : %p\n", i_RAD, j_RAD, *(iArray_RAD[i_RAD] + j_RAD), (iArray_RAD[i_RAD] + j_RAD));
		}
		printf("\n\n");
	}
	return(0);
}
