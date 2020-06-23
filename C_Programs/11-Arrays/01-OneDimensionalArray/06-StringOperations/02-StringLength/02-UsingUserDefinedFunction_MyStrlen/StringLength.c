#include <stdio.h>

#define MAX_STRING_LENGTH 512
int main(void)
{


	//function declarations

	char chArray_RAD[MAX_STRING_LENGTH];
	int iStringLength_RAD = 0;

	//code
	//*****STRING INPUT******
	printf("\n\n");
	printf("Enter A String :\n\n");
	gets_s(chArray_RAD, MAX_STRING_LENGTH);

	//*****STRING OUTPUT*****
	printf("\n\n");
	printf("String Enterd By You Is : \n\n");
	printf("%s\n", chArray_RAD);

	//*****STRING LENGTH****
	printf("\n\n");
	iStringLength_RAD = MyStrlen(chArray_RAD);
	printf("Length of String Is = %d Character !!!!\n\n", iStringLength_RAD);

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

 