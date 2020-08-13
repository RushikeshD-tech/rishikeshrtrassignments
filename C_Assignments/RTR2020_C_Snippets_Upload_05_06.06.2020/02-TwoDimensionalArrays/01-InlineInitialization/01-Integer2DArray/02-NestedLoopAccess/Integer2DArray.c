#include<stdio.h>
int main(void)
{
	//variable declarations
	int iArray_RAD[5][3] = { {1, 2, 3}, {2, 4, 6}, {3, 6, 9}, {4, 8, 12}, {5, 10, 15} };
	int int_size_RAD;
	int iArray_size_RAD;
	int iArray_num_elements_RAD, iArray_num_rows_RAD, iArray_num_columns_RAD;
	int i_RAD, j_RAD;

	//code
	printf("\n\n");

	int_size_RAD = sizeof(int);

	iArray_size_RAD = sizeof(iArray_RAD);
	printf("Size of Two Dimensional (2D) Integer Array Is = %d\n\n", iArray_size_RAD);
	 
	iArray_num_rows_RAD = iArray_size_RAD / sizeof(iArray_RAD[0]);
	printf("Number of Rows In Two Dimensional ( 2D ) Integer Array Is = %d\n\n", iArray_num_rows_RAD);
	
	iArray_num_columns_RAD = sizeof(iArray_RAD[0]) / int_size_RAD;
	printf("Number of Columns In Two Dimensional ( 2D ) Integer Array Is = %d\n\n", iArray_num_columns_RAD);
		
	iArray_num_elements_RAD = iArray_num_rows_RAD * iArray_num_columns_RAD;
	printf("Number of Elements In Two Dimensional ( 2D ) Integer Array Is = %d\n\n", iArray_num_elements_RAD);
		
	printf("\n\n");
	printf("Elements In The 2D Array : \n\n");

	for (i_RAD = 0; i_RAD < iArray_num_rows_RAD; i_RAD++)
	{
		printf("****** ROW %d ******\n", (i_RAD + 1));
		for (j_RAD = 0; j_RAD < iArray_num_columns_RAD; j_RAD++)
		{
			printf("iArray[%d][%d] = %d\n", i_RAD, j_RAD, iArray_RAD[i_RAD][j_RAD]);
		}
		printf("\n\n");
	}
	return(0);

}

