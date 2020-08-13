#include<stdio.h>

#define MAX_STRING_LENGTH 512
 
int main(void)
{
	//function prototype
	void MyStrcpy(char[], char[]);

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
	printf("size of two dimensional (2D) character Array (String Array) Is = %d \n\n", strArray_size_RAD);

	strArray_num_rows_RAD = strArray_size_RAD / sizeof(strArray_RAD[0]);
	printf("Number of Rows (Strings) In Two Dimensional (2D) Character Array (String Array) Is = %d\n\n", strArray_num_rows_RAD);

	strArray_num_columns_RAD = sizeof(strArray_RAD[0]) / char_size_RAD;
	
	printf("Maximum number of Elements (Character) In Two Dimensional (2D) Character Array (String Array) Is = %d\n\n", strArray_num_elements_RAD);

	//****PIECE-MEAL ASSIGNENT****
	MyStrcpy(strArray_RAD[0], "My");
	MyStrcpy(strArray_RAD[1], "Name");
	MyStrcpy(strArray_RAD[2], "Is");
	MyStrcpy(strArray_RAD[3], "Rishikesh");
	MyStrcpy(strArray_RAD[4], "Dumbre");

	printf("\n\n");
	printf("The Strings In The 2D Character Array Are : \n\n");

	for (i_RAD = 0; i_RAD < strArray_num_rows_RAD; i_RAD++)
		printf("%s", strArray_RAD[i_RAD]);

	printf("\n\n");

	return(0);
}
void MyStrcpy(char str_destination[], char str_source[])
{
	int MyStrlen(char[]);

	int iStringLength_RAD = 0;

	int j_RAD;

	//code
	iStringLength_RAD = MyStrlen(str_source);
	for (j_RAD = 0; j_RAD < iStringLength_RAD; j_RAD++)
		str_destination[j_RAD] = str_source[j_RAD];
	str_destination[j_RAD] = '\0';
}

int MyStrlen(char str[])
{
	// variable declarations
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
					