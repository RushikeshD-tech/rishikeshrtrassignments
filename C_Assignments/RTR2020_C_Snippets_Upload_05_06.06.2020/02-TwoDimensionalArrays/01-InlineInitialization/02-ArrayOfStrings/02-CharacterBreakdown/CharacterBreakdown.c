#include <stdio.h>
#define MAX_STRING_LENGTH 512
 
int main(void)
{
	int MyStrlen(char[]);

	//variable declarations

	char strArray_RAD[10][15] = { "Hello!", "Welcome", "To", "Real", "Rendering", "Batch", "(2020-21)", "Of", "Astromedicomp." };

	int iStrLengths_RAD[10];

	int strArray_size_RAD;
	int strArray_num_rows_RAD;
	int i_RAD, j_RAD;

	//code

	strArray_size_RAD = sizeof(strArray_RAD);
	strArray_num_rows_RAD = strArray_size_RAD / sizeof(strArray_RAD[0]);

	//r (i_RAD = 0; i_RAD < MyStrlen(strArray_RAD[0]))

	for (i_RAD = 0; i_RAD < strArray_num_rows_RAD; i_RAD++)
		iStrLengths_RAD[i_RAD] = MyStrlen(strArray_RAD[i_RAD]);

	printf("\n\n");
	printf("The Entire String Array :\n\n");
	for (i_RAD = 0; i_RAD < strArray_num_rows_RAD; i_RAD++)

		printf("\n\n");
	printf("Strings In The 2D Array : \n\n");

	//rintf("Strings In The 2D Array : \n\n");

	for (i_RAD = 0; i_RAD < strArray_num_rows_RAD; i_RAD++)
	{
		printf("string Number %d => %s \n\n", (i_RAD + 1), strArray_RAD[i_RAD]);
		for (j_RAD = 0; j_RAD < iStrLengths_RAD[i_RAD]; j_RAD++)
		{
			printf("Character %d = %c\n", (j_RAD + 1), strArray_RAD[i_RAD][j_RAD]);
		}
		printf("\n\n");
	}
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


