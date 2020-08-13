#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	//variable declarations
	int** ptr_iArray_RAD = NULL; 
		int i_RAD, j_RAD;
	int num_rows_RAD, num_columns_RAD;
	//code
	
	printf("\n\n");
	printf("Enter Number Of Rows : ");
	scanf("%d", &num_rows_RAD);
	
	printf("\n\n");
	printf("Enter Number Of Columns : ");
	scanf("%d", &num_columns_RAD);
	
	printf("\n\n");
	printf("********** MEMORY ALLOCATION TO 2D INTEGER ARRAY **********\n\n");
	ptr_iArray_RAD = (int**)malloc(num_rows_RAD * sizeof(int*));
	if (ptr_iArray_RAD == NULL)
	{
		printf("FAILED TO ALLOCATE MEMORY TO %d ROWS OF 2D INTEGER ARRAY !!! EXITTING NOW...\n\n", num_rows_RAD);
			exit(0);
	}
	else
			printf("MEMORY ALLOCATION TO %d ROWS OF 2D INTEGER ARRAY SUCCEEDED !!! \n\n", num_rows_RAD);
				
				for (i_RAD = 0; i_RAD < num_rows_RAD; i_RAD++)
				{
					ptr_iArray_RAD[i_RAD] = (int*)malloc(num_columns_RAD * sizeof(int)); 
						if (ptr_iArray_RAD[i_RAD] == NULL) 
						{
							printf("FAILED TO ALLOCATE MEMORY TO COLUMNS OF ROW %d OF 2D INTEGER ARRAY !!!EXITTING NOW...\n\n", i_RAD);
								exit(0);
						}
						else
								printf("MEMORY ALLOCATION TO COLUMNS OF ROW %d OF 2D INTEGER ARRAY SUCCEEDED !!!\n\n", i_RAD);
				}
				for (i_RAD = 0; i_RAD < num_rows_RAD; i_RAD++)
				{
					for (j_RAD = 0; j_RAD < num_columns_RAD; j_RAD++)
					{
						ptr_iArray_RAD[i_RAD][j_RAD] = (i_RAD * 1) + (j_RAD * 1); 
					}
				}
				
				for (i_RAD = 0; i_RAD < num_rows_RAD; i_RAD++)
				{
					printf("Base Address Of Row %d : ptr_iArray[%d] = %p \t At Address : %p\n", i_RAD, i_RAD, ptr_iArray_RAD[i_RAD], &ptr_iArray_RAD[i_RAD]);
				}
				printf("\n\n");
				for (i_RAD = 0; i_RAD < num_rows_RAD; i_RAD++)
				{
					for (j_RAD = 0; j_RAD < num_columns_RAD; j_RAD++)
					{
						printf("ptr_iArray[%d][%d] = %d \t At Address : %p\n", i_RAD, j_RAD,ptr_iArray_RAD[i_RAD][j_RAD], &ptr_iArray_RAD[i_RAD][j_RAD]); 
					}
					printf("\n");
				}
			
				for (i_RAD = (num_rows_RAD - 1); i_RAD >= 0; i_RAD--)
				{
					if (ptr_iArray_RAD[i_RAD])
					{
						free(ptr_iArray_RAD[i_RAD]);
						ptr_iArray_RAD[i_RAD] = NULL;
						printf("MEMORY ALLOCATED TO ROW %d HAS BEEN SUCCESSFULLY FREED !!!\n\n", i_RAD);
					}
				}
				
					if (ptr_iArray_RAD)
					{
						free(ptr_iArray_RAD);
						ptr_iArray_RAD = NULL;
						printf("MEMORY ALLOCATED TO ptr_iArray HAS BEEN SUCCESSFULLY FREED !!!\n\n");
					}
				return(0);
}
	


