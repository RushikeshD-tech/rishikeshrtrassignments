#include <stdio.h>
#define NUM_ROWS 5
#define NUM_COLUMNS 3
int main(void)
{
	//variable declarations
	int iArray_RAD[NUM_ROWS][NUM_COLUMNS];
	int i_RAD, j_RAD;
	int* ptr_iArray_Row_RAD = NULL;
	//code
	for (i_RAD = 0; i_RAD < NUM_ROWS; i_RAD++)
	{
		ptr_iArray_Row_RAD = iArray_RAD[i_RAD]; 
			for (j_RAD = 0; j_RAD < NUM_COLUMNS; j_RAD++)
				*(ptr_iArray_Row_RAD + j_RAD) = (i_RAD + 1) * (j_RAD + 1); //
		
	}
	printf("\n\n");
	printf("2D Integer Array Elements Along With Addresses : \n\n");
	for (i_RAD = 0; i_RAD < NUM_ROWS; i_RAD++)
	{
		ptr_iArray_Row_RAD = iArray_RAD[i_RAD];
		for (j_RAD = 0; j_RAD < NUM_COLUMNS; j_RAD++)
		{
			printf("*(ptr_iArray_Row + %d)= %d \t \t At Address (ptr_iArray_Row + j) : % p\n", j_RAD, *(ptr_iArray_Row_RAD + j_RAD), (ptr_iArray_Row_RAD + j_RAD));
		}
		printf("\n\n");
	}
	return(0);
}



