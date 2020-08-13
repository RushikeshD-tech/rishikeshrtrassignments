#include <stdio.h>
#include <stdlib.h>
#define NUM_ROWS 5
#define NUM_COLUMNS 3
int main(void)
{
	//variable declarations
	int i_RAD, j_RAD;
	int** ptr_iArray_RAD = NULL;
	//code
	printf("\n\n");
	// *** MEMORY ALLOCATION ***
	ptr_iArray_RAD = (int**)malloc(NUM_ROWS * sizeof(int*)); 
		if (ptr_iArray_RAD == NULL)
		{
			printf("MEMORY ALLOCATION TO THE 1D ARRAY OF BASE ADDRESSES OF %d ROWS FAILED !!!EXITTING NOW...\n\n", NUM_ROWS);
				exit(0);
		}
		else
				printf("MEMORY ALLOCATION TO THE 1D ARRAY OF BASE ADDRESSES OF %d ROWS HAS SUCCEEDED !!!\n\n", NUM_ROWS);
					// *** ALLOCATING MEMORY TO EACH ROW ***
					for (i_RAD = 0; i_RAD < NUM_ROWS; i_RAD++)
					{
						ptr_iArray_RAD[i_RAD] = (int*)malloc(NUM_COLUMNS * sizeof(int));
							if (ptr_iArray_RAD == NULL)
							{
								printf("MEMORY ALLOCATION TO THE COLUMNS OF ROW %d FAILED !!! EXITTING NOW...\n\n", i_RAD);
									exit(0);
							}
							else
									printf("MEMORY ALLOCATION TO THE COLUMNS OF ROW %d HAS SUCCEEDED !!!\n\n", i_RAD);
					}
	// *** ASSIGNING VALUES ***
	for (i_RAD = 0; i_RAD < NUM_ROWS; i_RAD++)
	{
		for (j_RAD = 0; j_RAD < NUM_COLUMNS; j_RAD++)
		{
			*(*(ptr_iArray_RAD + i_RAD) + j_RAD) = (i_RAD + 1) * (j_RAD + 1);
			//(i + 1)* (j + 1);
		}
	}
	// *** DISPLAYING VALUES ***
	printf("\n\n");
	printf("2D Integer Array Elements Along With Addresses : \n\n");
	for (i_RAD = 0; i_RAD < NUM_ROWS; i_RAD++)
	{
		for (j_RAD = 0; j_RAD < NUM_COLUMNS; j_RAD++)
		{
			printf("ptr_iArray_Row[%d][%d] = %d \t \t At Address & ptr_iArray_Row[% d][% d] : % p\n", i_RAD, j_RAD, ptr_iArray_RAD[i_RAD][j_RAD], i_RAD, j_RAD, &ptr_iArray_RAD[i_RAD][j_RAD]);
		}
		printf("\n\n");
	}
	// *** FREEING ALLOCATED MEMORY ***
	// *** FREEING MEMORY OF EACH ROW ***
	for (i_RAD = (NUM_ROWS - 1); i_RAD >= 0; i_RAD--)
	{
		if (*(ptr_iArray_RAD + i_RAD)) 
		{
			free(*(ptr_iArray_RAD + i_RAD)); 
			*(ptr_iArray_RAD + i_RAD) = NULL;
			printf("MEMORY ALLOCATED TO ROW %d HAS BEEN SUCCESSFULLY FREED !!! \n\n", i_RAD);
		}
	}
	
		if (ptr_iArray_RAD)
		{
			free(ptr_iArray_RAD);
			ptr_iArray_RAD = NULL;
			printf("MEMORY ALLOCATED TO ptr_iArray HAS BEEN SUCCESSFULLY FREED !!! \n\n");
		}
	return(0);
}

