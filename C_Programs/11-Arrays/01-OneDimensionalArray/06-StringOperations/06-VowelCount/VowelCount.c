#include<stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//function prototype
	int MyStrlen(char[]);

	//variable declarations
	char chArray_RAD[MAX_STRING_LENGTH];
	int iStringLength_RAD;
	int count_A_RAD = 0, count_E_RAD = 0, count_I_RAD = 0, count_O_RAD = 0, count_U_RAD = 0;

	int i_RAD;

	//code

	printf("\n\n");
	printf("Enter A String : \n\n");
	gets_s(chArray_RAD, MAX_STRING_LENGTH);

	printf("\n\n");
	printf("String Enterd By You Is : \n\n");
	printf("%s\n", chArray_RAD);

	iStringLength_RAD = MyStrlen(chArray_RAD);

	for (i_RAD = 0; i_RAD < iStringLength_RAD; i_RAD++)
	{
		switch (chArray_RAD[i_RAD])
		{
		case 'A':
		case 'a':
			count_A_RAD++;
			break;
		case'E':
		case'e':
			count_E_RAD++;
			break;
		case 'I':
		case 'i':
			count_I_RAD++;
			break;
		case 'O':
		case 'o':
			count_O_RAD++;
			break;
		case 'U':
		case'u':
			count_U_RAD++;
			break;
		default:
			break;

		}
	}
	printf("\n\n");
	printf("In The String Enterd By You, The Vowels And The Number Of Their Occurences Are Are Follows: \n\n");
	printf("'A' Has Occured = %d Times !!!\n\n", count_A_RAD++);
	printf("'E' Has Occured = %d Times !!!\n\n", count_E_RAD++);
	printf("'I' Has Occured = %d Times !!!\n\n", count_I_RAD++);
	printf("'O' Has Occured = %d Times !!!\n\n", count_O_RAD++);
	printf("'U' Has Occured = %d Times !!!\n\n", count_U_RAD++);

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


