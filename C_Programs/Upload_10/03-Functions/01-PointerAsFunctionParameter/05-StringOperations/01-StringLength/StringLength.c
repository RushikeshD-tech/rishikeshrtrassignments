#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 512
int main(void)
{
	//function prototype
	int MyStrlen(char*);
	
	//variable declarations
	char* chArray_RAD = NULL; 
	int iStringLength_RAD = 0;
	
		//code
	printf("\n\n");
	chArray_RAD = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
	if (chArray_RAD == NULL)
	{
		printf("MEMORY ALOCATION TO CHARACTER ARRAY FAILED !!! EXITTING NOW..\n\n");
		exit(0);
	}
	
	printf("Enter A String : \n\n");
	gets_s(chArray_RAD, MAX_STRING_LENGTH);
	
	printf("\n\n");
	printf("String Entered By You Is : \n\n");
	printf("%s\n", chArray_RAD);
	
	printf("\n\n");
	iStringLength_RAD = MyStrlen(chArray_RAD);
	printf("Length Of String Is = %d Characters !!!\n\n", iStringLength_RAD);
	if (chArray_RAD)
	{
		free(chArray_RAD);
		chArray_RAD = NULL;
	}
	return(0);
}
int MyStrlen(char* str)
{
	//variable declarations
	int j_RAD;
	int string_length_RAD = 0;
	for (j_RAD = 0; j_RAD < MAX_STRING_LENGTH; j_RAD++)
	{
		if (*(str + j_RAD) == '\0')
			break;
		else
			string_length_RAD++;
	}
	return(string_length_RAD);
}


	