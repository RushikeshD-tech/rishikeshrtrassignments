#include <stdio.h>
#define MAX_STRING_LENGTH 512
int main(void)
{
	//variable declarations
	
	char strArray_RAD[5][10]; 

	int char_size_RAD;
	int strArray_size_RAD;
	int strArray_num_elements_RAD, strArray_num_rows_RAD, strArray_num_columns_RAD;
	int i_RAD;

	//code
	printf("\n\n");
	char_size_RAD = sizeof(char);
	strArray_size_RAD = sizeof(strArray_RAD);
	printf("Size Of Two Dimensional ( 2D ) Character Array (String Array) Is = %d\n\n", strArray_size_RAD);
		strArray_num_rows_RAD = strArray_size_RAD / sizeof(strArray_RAD[0]);
	printf("Number of Rows (Strings) In Two Dimensional ( 2D ) Character Array (String Array) Is = % d\n\n", strArray_num_rows_RAD);
		strArray_num_columns_RAD = sizeof(strArray_RAD[0]) / char_size_RAD;
	printf("Number of Columns In Two Dimensional ( 2D ) Character Array (String Array) Is = % d\n\n", strArray_num_columns_RAD);
		strArray_num_elements_RAD = strArray_num_rows_RAD * strArray_num_columns_RAD;
	printf("Maximum Number of Elements (Characters) In Two Dimensional ( 2D ) Character Array(String Array) Is = % d\n\n", strArray_num_elements_RAD);
		// *** PIECE-MEAL ASSIGNMENT ***
		// ****** ROW 1 / STRING 1 ******
		strArray_RAD[0][0] = 'M';
	    strArray_RAD[0][1] = 'y';
	    strArray_RAD[0][2] = '\0';

		// ****** ROW 2 / STRING 2 ******
		strArray_RAD[1][0] = 'N';
		strArray_RAD[1][1] = 'a';
		strArray_RAD[1][2] = 'm';
		strArray_RAD[1][3] = 'e';
		strArray_RAD[1][4] = '\0';

		// ****** ROW 3 / STRING 3 ******
		strArray_RAD[2][0] = 'I';
		strArray_RAD[2][1] = 's';
		strArray_RAD[2][2] = '\0';

		// ****** ROW 4 / STRING 4 ******
		strArray_RAD[3][0] = 'R';
		strArray_RAD[3][1] = 'r';
		strArray_RAD[3][2] = 'i';
		strArray_RAD[3][3] = 's';
		strArray_RAD[3][4] = 'h';
		strArray_RAD[3][5] = 'i';
		strArray_RAD[3][6] = 'k';
		strArray_RAD[3][7] = 'e';
		strArray_RAD[3][8] = 's';
		strArray_RAD[3][9] = 'h';
		strArray_RAD[3][10] = '\0';

		// ****** ROW 5 / STRING 5 ******
		strArray_RAD[4][0] = 'D';
		strArray_RAD[4][1] = 'u';
		strArray_RAD[4][2] = 'm';
		strArray_RAD[4][3] = 'b';
		strArray_RAD[4][4] = 'r';
		strArray_RAD[4][5] = 'e';
		strArray_RAD[4][6] = '\0'; //NULL-TERMINATING CHARACTER
		printf("\n\n");
		printf("The Strings In the 2D Character Array Are : \n\n");
		for (i_RAD = 0; i_RAD < strArray_num_rows_RAD; i_RAD++)
			printf("%s ", strArray_RAD[i_RAD]);
		printf("\n\n");
		return(0);
}
int MyStrlen(char str[])
{
	//variable declarations
	int j_RAD;
	int string_length_RAD = 0;
	//code

	for (j_RAD = 0; j_RAD < MAX_STRING_LENGTH; j_RAD++)
	{
		if (str[j_RAD] == '\0')
			break;
		else
			string_length_RAD++;
	}
	return(string_length_RAD);
}