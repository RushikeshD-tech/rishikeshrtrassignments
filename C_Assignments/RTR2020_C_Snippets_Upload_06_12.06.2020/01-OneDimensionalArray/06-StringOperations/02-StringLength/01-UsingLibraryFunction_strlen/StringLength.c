#include<stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//variable declarations
	char chArray_RAD[MAX_STRING_LENGTH];
	int iStringLength_RAD = 0;

	//code 

	//*****STRING INPUT***********

	printf("\n\n");
	printf("Enter A String :\n\n");
	gets_s(chArray_RAD, MAX_STRING_LENGTH);

	//*****STRING OUTPUT******

	printf("\n\n");
	printf("Strict Enterd By You Is : \n\n");
	printf("%s\n", chArray_RAD);

	//*****STRING LENGTH*******
	printf("\n\n");
	iStringLength_RAD = strlen(chArray_RAD);
	printf("Length Of String Is = %d Characters !!!!\n\n", iStringLength_RAD);

	return(0);

}

