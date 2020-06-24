#include <stdio.h>
int main(void)
{
	// variable declaration
	int iArray_One_RAD[5];
	int iArray_Two_RAD[5][3];
	int iArray_Three_RAD[100][100][5];
	int num_rows_RAD_2D;
	int num_columns_RAD_2D;
	int num_rows_RAD_3D;
	int num_columns_RAD_3D;
	int depth_RAD_3D;
	// code
	printf("\n\n");
	printf("Size of 1-D integer array iArray_One = %lu\n", sizeof(iArray_One_RAD));
	
	printf("Number of elements in 1-D integer array iArray_One = %lu\n", (sizeof(iArray_One_RAD) / sizeof(int)));
	
	printf("\n\n");
	printf("Size of 2-D integer array iArray_Two = %lu\n", sizeof(iArray_Two_RAD));
	
	printf("Number rows in 2-D integer array iArray_Two = %lu\n", (sizeof(iArray_Two_RAD) / sizeof(iArray_Two_RAD[0])));
	
	num_rows_RAD_2D = (sizeof(iArray_Two_RAD) / sizeof(iArray_Two_RAD[0]));
	
	printf("Number of elements (columns) in each row in 2-D integer array iArray_Two = % lu\n", (sizeof(iArray_Two_RAD[0]) / sizeof(iArray_Two_RAD[0][0])));
	
	num_columns_RAD_2D = (sizeof(iArray_Two_RAD[0]) / sizeof(iArray_Two_RAD[0][0]));

	printf("Number of elements in total in 2-D Array iArray_Two = %d\n",(num_rows_RAD_2D * num_columns_RAD_2D));
	printf("\n\n");
	
	printf("\n\n");
	printf("Size of 3-D integer array iArray_Three = %lu\n", sizeof(iArray_Three_RAD));
	
	printf("Number rows in 3-D integer array iArray_Three = %lu\n", (sizeof(iArray_Three_RAD) / sizeof(iArray_Three_RAD[0])));

	num_rows_RAD_3D = (sizeof(iArray_Three_RAD) / sizeof(iArray_Three_RAD[0]));

	printf("Number of elements (columns) in one row in 3-D integer array iArray_Three = % lu\n", (sizeof(iArray_Three_RAD[0]) / sizeof(iArray_Three_RAD[0][0])));

	num_columns_RAD_3D = (sizeof(iArray_Three_RAD[0]) / sizeof(iArray_Three_RAD[0][0]));
	
	printf("Number of elements (depth) in one column in one row in 3-D integer array iArray_Three = %lu\n", (sizeof(iArray_Three_RAD[0][0]) / sizeof(iArray_Three_RAD[0][0][0])));
		
	depth_RAD_3D = (sizeof(iArray_Three_RAD[0][0]) / sizeof(iArray_Three_RAD[0][0][0]));
	
	printf("Number of elements in total in 3-D Array iArray_Three = %d\n",(num_rows_RAD_3D * num_columns_RAD_3D * depth_RAD_3D));
    printf("\n\n");
		return(0);
}

