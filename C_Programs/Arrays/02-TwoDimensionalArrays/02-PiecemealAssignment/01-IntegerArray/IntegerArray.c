#include <stdio.h>
int main(void)
{
	//variable declarations
	int iArray_RAD[3][5];
	int int_size_RAD;
	int iArray_size_RAD;
	int iArray_num_elements_RAD, iArray_num_rows_RAD, iArray_num_columns_RAD;
	int i_RAD, j_RAD;


	//code
	printf("\n\n");

	int_size_RAD = sizeof(int);

	iArray_size_RAD = sizeof(iArray_RAD);
	printf("Size Of Two Dimensional (2D) Integer Array Is = %d\n\n", iArray_num_rows_RAD);

	iArray_num_columns_RAD = sizeof(iArray_RAD[0]) / int_size_RAD;
	printf("Number of Column In Two Dimensional (2D) Integer Array Is = %d\n\n", iArray_num_columns_RAD);

	iArray_num_elements_RAD = iArray_num_rows_RAD * iArray_num_columns_RAD;
	printf("number of elements In two Dimensional (2D) Integer Array Is = %d\n\n", iArray_num_elements_RAD);

	printf("\n\n");
	printf("Elements In The 2D Array : \n\n");

	//*******PIECE-MEAL ASSIGNMENT ************
	//************ROW 1***************

	iArray_RAD[0][0] = 21;
	iArray_RAD[0][1] = 42;
	iArray_RAD[0][2] = 63;
	iArray_RAD[0][3] = 84;
	iArray_RAD[0][4] = 105;

	//********* Row 2*************

	iArray_RAD[1][0] = 22;
	iArray_RAD[1][1]= 44;
	iArray_RAD[1][2] = 66;
	iArray_RAD[1][3] = 88;
	iArray_RAD[1][4] = 110;

	//***********Row 3************

	iArray_RAD[2][0] = 23;
	iArray_RAD[2][1] = 46;
	iArray_RAD[2][2] = 69;
	iArray_RAD[2][3] = 92;
	iArray_RAD[2][4] = 115;

	for (i_RAD = 0; i_RAD < iArray_num_columns_RAD; i_RAD++)
	{
		printf("****************Row %d **********\n", (i_RAD + 1));
		for(j_RAD = 0; j_RAD < iArray_num_columns_RAD; j_RAD++)
		{
			printf("iArray[%d][%d] = %d\n", i_RAD, j_RAD, iArray_RAD[i_RAD][j_RAD]);
		}
		printf("\n\n");
	}
	return(0);

}