#include<stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	int MyStrlen(char[]);

	//variable declarations

	char strArray_RAD[10][15] = { "Hello", "Welcome", "To", "Real", "Time", "Rendering", "Batch", "(2020-21)", "Of", "Astromedicomp." };
	int char_size_RAD;
	int strArray_size_RAD;
	int strArray_num_elements_RAD, strArray_num_rows_RAD, strArray_num_columns_RAD;
	int strActual_num_chars_RAD = 0;
	int i_RAD;

	printf("\n\n");

	char_size_RAD = sizeof(char);

	strArray_size_RAD = sizeof(strArray_RAD);
	printf("Size of Two Dimensional (2D) Character Array (String Array) Is = %d\n\n", strArray_size_RAD);

	strArray_num_rows_RAD = strArray_size_RAD / sizeof(strArray_RAD[0]);
	printf("Number of Rows (String) In Two Dimensional (2D) Character Array (String Array) Is = %d\n\n", strArray_num_rows_RAD);

	strArray_num_columns_RAD = sizeof(strArray_RAD[0]) / char_size_RAD;
	printf("Number of Column In Two Dimensional (2D) Character Array (String Array) Is = %d\n\n", strArray_num_columns_RAD);

	strArray_num_elements_RAD = strArray_num_rows_RAD * strArray_num_columns_RAD;
	printf("Maximum Number Of Elements (Character) In Two Dimensional (2D) Charcater Array (String Array) Is = %d\n\n", strArray_num_elements_RAD);

	for (i_RAD = 0; i_RAD < strArray_num_rows_RAD; i_RAD++)
	{
		strActual_num_chars_RAD = strActual_num_chars_RAD + MyStrlen(strArray_RAD[i_RAD]);
	}
	printf("Actual Number of Elements (Character) In Two Dimensional (2D) Charcater Array (String Array) Is = %d\n\n", strActual_num_chars_RAD);

	printf("\n\n");
	printf("String In The 2D Array : \n\n");

	printf("%s", strArray_RAD[0]);
	printf("%s", strArray_RAD[1]);
	printf("%s", strArray_RAD[2]);
	printf("%s", strArray_RAD[3]);
	printf("%s", strArray_RAD[4]);
	printf("%s", strArray_RAD[5]);
	printf("%s", strArray_RAD[6]);
	printf("%s", strArray_RAD[7]);
	printf("%s", strArray_RAD[8]);
	printf("%s\n\n", strArray_RAD[9]);

	return(0);
}

int MyStrlen(char str[])
{
	//variable declarations

	int  j_RAD;
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