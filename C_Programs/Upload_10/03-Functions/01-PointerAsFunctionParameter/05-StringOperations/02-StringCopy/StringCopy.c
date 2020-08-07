#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//function prototype
	void MyStrcpy(char*, char*);
	int MyStrlen(char*);

	//variable declarations
	char* chArray_original_RAD = NULL, * chArray_Copy_RAD = NULL;
	int original_string_length_RAD;

	//code
  //*** STRING INPUT***

	printf("\n\n");
	chArray_original_RAD = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
	if (chArray_original_RAD == NULL)
	{
		printf("MEMORY ALLOCATION FOR ORIGINAL STRING FAILED !!! EXISTING NOW...\n\n ");
		exit(0);
	}
	printf("Enter A String : \n\n");
	gets_s(chArray_original_RAD, MAX_STRING_LENGTH);

	original_string_length_RAD = MyStrlen(chArray_original_RAD);
	chArray_Copy_RAD = (char*)malloc(original_string_length_RAD * sizeof(char));
	if (chArray_Copy_RAD == NULL)
	{
		printf("MEMORY ALLOCATION FOR COPIED STRING FAILED !!! EXITTING NOW...\n\n");
		exit(0);
	}
	//***STRING COPY***
	MyStrcpy(chArray_Copy_RAD, chArray_original_RAD);

	//***STRING OUTPUT***
	printf("\n\n");
	printf("The Original String Enterd By You (i.e : 'chArray_original') Is :\n\n");
	printf("%s\n", chArray_original_RAD);

	printf("\n\n");
	printf("The Copied String (i.e : 'chArray_Copy') Is :\n\n");
	printf("%s\n", chArray_Copy_RAD);

	if (chArray_Copy_RAD)
	{
		free(chArray_Copy_RAD);
		chArray_Copy_RAD = NULL;
		printf("\n\n");
		printf("MEMORY ALLOCATED FOR ORIGINAL STRING HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}

	if (chArray_original_RAD)
	{
		free(chArray_original_RAD);
		chArray_original_RAD = NULL;
		printf("\n\n");
		printf("MEMORY ALLOCATED FOR ORIGINAL STRING HAS BEEN SUCCESSFULLY FREED !!!\n\n");

	}
	return(0);
}
void MyStrcpy(char *str_destination, char *str_source)
{
	//function prototype
	int MyStrlen(char *);

	//variable declaartions
	int iStringLength_RAD = 0;
	int j_RAD;

	//code
	iStringLength_RAD = MyStrlen(str_source);
	for (j_RAD = 0; j_RAD < iStringLength_RAD; j_RAD++)
		*(str_destination + j_RAD) = *(str_source + j_RAD); 
	
	*(str_destination + j_RAD) = '\0';
}
int MyStrlen(char *str)
{
	//variable declarations
	int j_RAD;
	int  string_length_RAD = 0;

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

