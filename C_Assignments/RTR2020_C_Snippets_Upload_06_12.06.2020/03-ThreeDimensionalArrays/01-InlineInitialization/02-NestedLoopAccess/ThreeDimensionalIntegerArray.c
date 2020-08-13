#include <stdio.h>
int main(void)
{
	//variable declaraions
	//IN-LINE INITIALIZATION
	int iArray_RAD[5][3][2] = { { { 9, 18 }, { 27, 36 }, { 45, 54 } },
	{ { 8, 16 }, { 24, 32 }, { 40, 48 } },
	{ { 7, 14 }, { 21, 28 }, { 35, 42 } },
	{ { 6, 12 }, { 18, 24 }, { 30, 36 } },
	{ { 5, 10 }, { 15, 20 }, { 25, 30 } } };
	int int_size_RAD;
	int iArray_size_RAD;
	int iArray_num_elements_RAD, iArray_width_RAD, iArray_height_RAD, iArray_depth_RAD;
	int i_RAD, j_RAD, k_RAD;
	//code
	printf("\n\n");
	int_size_RAD = sizeof(int);
	iArray_size_RAD = sizeof(iArray_RAD);
	printf("Size Of Three Dimensional ( 3D ) Integer Array Is = %d\n\n", iArray_size_RAD);
	iArray_width_RAD = iArray_size_RAD / sizeof(iArray_RAD[0]);
	printf("Number of Rows (Width) In Three Dimensional ( 3D ) Integer Array Is = %d\n\n", iArray_width_RAD);
		iArray_height_RAD = sizeof(iArray_RAD[0]) / sizeof(iArray_RAD[0][0]);
	printf("Number of Columns (Height) In Three Dimensional ( 3D ) Integer Array Is = % d\n\n", iArray_height_RAD);
		iArray_depth_RAD = sizeof(iArray_RAD[0][0]) / int_size_RAD;
	printf("Depth In Three Dimensional ( 3D ) Integer Array Is = %d\n\n", iArray_depth_RAD);
	iArray_num_elements_RAD = iArray_width_RAD * iArray_height_RAD * iArray_depth_RAD;
	printf("Number of Elements In Three Dimensional ( 3D ) Integer Array Is = %d\n\n", iArray_num_elements_RAD);
		printf("\n\n");
	printf("Elements In Integer 3D Array : \n\n");
	for (i_RAD = 0; i_RAD < iArray_width_RAD; i_RAD++)
	{
		printf("****** ROW %d ******\n", (i_RAD + 1));
		for (j_RAD = 0; j_RAD < iArray_height_RAD; j_RAD++)
		{
			printf("****** COLUMN %d ******\n", (j_RAD + 1));
			for (k_RAD = 0; k_RAD < iArray_depth_RAD; k_RAD++)
			{
				printf("iArray[%d][%d][%d] = %d\n", i_RAD, j_RAD, k_RAD, iArray_RAD[i_RAD][j_RAD][k_RAD]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
	return(0);
}



