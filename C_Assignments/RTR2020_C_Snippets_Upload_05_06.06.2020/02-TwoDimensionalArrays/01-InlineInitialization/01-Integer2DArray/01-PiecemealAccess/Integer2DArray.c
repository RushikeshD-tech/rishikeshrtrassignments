#include <stdio.h>
int main(void)
{
	//variable declarations
	int iArray_RAD[5][3] = { {1, 2, 3}, {2, 4, 6}, {3, 6, 9}, {4, 8, 12}, {5, 10, 15} };
	int int_size_RAD;
	int iArray_size_RAD;
	int iArray_num_elements_RAD, iArray_num_rows_RAD, iArray_num_columns_RAD;

	//code

	printf("\n\n");

	int_size_RAD = sizeof(iArray_RAD);
	iArray_size_RAD = sizeof(iArray_RAD);
	printf("size of two dimensional (2D) Integer Array Is  = %d\n\n", iArray_size_RAD);

	iArray_num_rows_RAD = iArray_size_RAD / sizeof(iArray_RAD[0]);
	printf("Sizenof Two Dimensional (2D) Integer Array Is = %d\n\n", iArray_num_rows_RAD);

	iArray_num_columns_RAD = sizeof(iArray_RAD[0]) / int_size_RAD;
	printf("Number of Columns In Two Dimensional (2D) Integer Array Is = %d\n\n", iArray_num_columns_RAD);

	iArray_num_elements_RAD = iArray_num_rows_RAD * iArray_num_columns_RAD;
	printf("Number Of Elements In Two Dimensional (2D) Integer Array Is = %d\n\n", iArray_num_columns_RAD);

	printf("\n\n");
	printf("Elements In The 2D Array : \n\n");


	printf("*********ROW 1***********\n");
	printf("iArray_RAD[0][0] = %d\n", iArray_RAD[0][0]);

	printf("iArray_RAD[0][0] = %d\n", iArray_RAD[0][10]);

	printf("iArray_RAD[0][0] = %d\n", iArray_RAD[0][2]);

	printf("\n\n");

	//**********ROW 2********
	printf("*******ROW 2 *********\n");
	printf("iArray[1][0] = %d\n", iArray_RAD[1][0]);

	printf("iArray[1][1] = %d\n", iArray_RAD[1][1]);

	printf("iArray[1][1] = %d\n", iArray_RAD[1][1]);

	printf("iArray[1][2] = %d\n", iArray_RAD[1][2]);

	printf("\n\n");

	printf("********* ROW 4*********\n");

	printf("iArray[3][0] = %d\n", iArray_RAD[3][0]);

	printf("iArray[3][1] = %d\n", iArray_RAD[3][1]);

	printf("iArray[3][2] = %d\n", iArray_RAD[3][2]);

	printf("\n\n");

	//***********ROW 5************
	printf("*******ROW 5************\n");

	printf("iArray[4][0] = %d\n", iArray_RAD[4][0]);

	printf("iArray[4][2] = %d\n", iArray_RAD[4][2]);

	printf("\n\n");

	return(0);
}






