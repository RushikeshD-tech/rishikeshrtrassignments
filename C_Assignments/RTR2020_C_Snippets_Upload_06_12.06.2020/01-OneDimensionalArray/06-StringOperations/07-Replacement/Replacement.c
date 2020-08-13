#include<stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//function prototype
	int MyStrlen(char[]);
	void MyStrcpy(char[], char[]);

	//variable declarations
	char chArray_Original_RAD[MAX_STRING_LENGTH], chArray_VowelsReplaced_RAD[MAX_STRING_LENGTH];
	int iStringLength_RAD;
	int i_RAD;

	//code
	printf("\n\n");
	printf("Enter A String: \n\n");
	gets_s(chArray_Original_RAD, MAX_STRING_LENGTH);


	// ***String Output***
	MyStrcpy(chArray_VowelsReplaced_RAD, chArray_Original_RAD);

	iStringLength_RAD = MyStrlen(chArray_VowelsReplaced_RAD);

	for (i_RAD = 0; i_RAD < iStringLength_RAD; i_RAD++)
	{
		switch (chArray_VowelsReplaced_RAD[i_RAD])
		{
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'U':
		case 'u':
			chArray_VowelsReplaced_RAD[i_RAD] = '*';
			break;
		default:
			break;
		}
	}
	//***STRING OUTPUT***
	printf("\n\n");
	printf("String Enterd By You Is : \n\n");
	printf("%s\n", chArray_Original_RAD);

	printf("\n\n");
	printf("String After Replacement Of Vowels By * IS : \n\n");
	printf("%s\n", chArray_VowelsReplaced_RAD);

	return(0);

}
int MyStrlen (char str[])
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
void MyStrcpy(char str_destination[], char str_source[])
{

	//function prototype
	int MyStrlen(char[]);

	// variable declarations
	int iStringLength_RAD = 0;
	int j_RAD;

	//code
	iStringLength_RAD = MyStrlen(str_source);
	for (j_RAD = 0; j_RAD < iStringLength_RAD; j_RAD++)
		str_destination[j_RAD] = str_source[j_RAD];

	str_destination[j_RAD] = '\0';


}



