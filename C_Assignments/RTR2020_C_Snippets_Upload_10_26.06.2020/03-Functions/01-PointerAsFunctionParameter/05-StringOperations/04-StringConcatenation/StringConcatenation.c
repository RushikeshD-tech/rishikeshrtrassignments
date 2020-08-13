#include <stdio.h>
#define MAX_STRING_LENGTH 512
int main(void)
{
	//function prototype
	void MyStrcat(char*, char*);
	int MyStrlen(char*);
	//variable declarations
	char* chArray_One_RAD = NULL, * chArray_Two_RAD = NULL;
		//code

		// *** STRING INPUT ***
		printf("\n\n");
	chArray_One_RAD = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
	if (chArray_One_RAD == NULL)
	{
		printf("MEMORY ALLOCATION TO FIRST STRING FAILED !!! EXITTING NOW...\n\n");
			exit(0);
	}
	printf("Enter First String : \n\n");
	gets_s(chArray_One_RAD, MAX_STRING_LENGTH);
	printf("\n\n");
	chArray_Two_RAD = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
	if (chArray_Two_RAD == NULL)
	{
		printf("MEMORY ALLOCATION TO SEOND STRING FAILED !!! EXITTING NOW...\n\n");
			exit(0);
	}
	printf("Enter Second String : \n\n");
	gets_s(chArray_Two_RAD, MAX_STRING_LENGTH);
	
	// *** STRING CONCAT ***
	printf("\n\n");
	printf("****** BEFORE CONCATENATION ******");
	printf("\n\n");
	printf("The Original First String Entered By You (i.e : 'chArray_One[]' )Is : \n\n");
	printf("%s\n", chArray_One_RAD);
	printf("\n\n");
	printf("The Original Second String Entered By You (i.e : 'chArray_Two[]')Is : \n\n");
	printf("%s\n", chArray_Two_RAD);
	MyStrcat(chArray_One_RAD, chArray_Two_RAD);
	printf("\n\n");
	printf("****** AFTER CONCATENATION ******");
	printf("\n\n");
	printf("'chArray_One[]' Is : \n\n");
	printf("%s\n", chArray_One_RAD);
	printf("\n\n");
	printf("'chArray_Two[]' Is : \n\n");
	printf("%s\n", chArray_Two_RAD);
	if (chArray_Two_RAD)
	{
		free(chArray_Two_RAD);
		chArray_Two_RAD = NULL;
		printf("\n\n");
		printf("MEMORY ALLOCATED TO SECOND STRING HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}
	if (chArray_One_RAD)
	{
		free(chArray_One_RAD);
		chArray_One_RAD = NULL;
		printf("\n\n");
		printf("MEMORY ALLOCATED TO FIRST STRING HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}
	return(0);
}
void MyStrcat(char* str_destination_RAD, char* str_source_RAD)
{
	//function prototype
	int MyStrlen(char*);
	//variable declarations
	int iStringLength_Source_RAD = 0, iStringLength_Destination_RAD = 0;
	int i_RAD, j_RAD;
	//code
	iStringLength_Source_RAD = MyStrlen(str_source_RAD);
	iStringLength_Destination_RAD = MyStrlen(str_destination_RAD);
	for (i_RAD = iStringLength_Destination_RAD, j_RAD = 0; j_RAD < iStringLength_Source_RAD; i_RAD++, j_RAD++)
	{
		*(str_destination_RAD + i_RAD) = *(str_source_RAD + j_RAD);
	}
	*(str_destination_RAD + i_RAD) = '\0';
	*(str_destination_RAD + i_RAD) = '\0';
}
int MyStrlen(char* str)
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

