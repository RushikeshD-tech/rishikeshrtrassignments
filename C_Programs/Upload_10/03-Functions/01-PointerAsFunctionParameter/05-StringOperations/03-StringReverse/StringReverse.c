#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//function prototype
	void MyStrrev(char * ,char *);
	int MyStrlen(char *);

		//variable declarations
		char *chArray_original_RAD = NULL, *chArray_Reversed_RAD = NULL;
	    int original_string_length_RAD;

	//code
        
	// *** STRING INPUT ***
		printf("\n\n");
		chArray_original_RAD = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
		if (chArray_original_RAD == NULL)
		{
			printf("MEMORY ALLOCATION FOR ORIGINAL STRING FAILED !!! EXITTING NOW ...\n\n");
				exit(0);
		}
		printf("Enter A String : \n\n");
		gets_s(chArray_original_RAD, MAX_STRING_LENGTH);
		
		// *** STRING REVERSE ***
		original_string_length_RAD = MyStrlen(chArray_original_RAD);
		chArray_Reversed_RAD = (char *)malloc(original_string_length_RAD * sizeof(char));
		if (chArray_Reversed_RAD == NULL)
		{
			printf("MEMORY ALLOCATION FOR REVERSED STRING FAILED !!! EXITTING NOW ...\n\n");
				exit(0);
		}
		MyStrrev(chArray_Reversed_RAD, chArray_original_RAD);
		
		// *** STRING OUTPUT ***
		printf("\n\n");
		printf("The Original String Entered By You (i.e : 'chArray_Original[]')Is : \n\n");
			printf("%s\n", chArray_original_RAD);
		printf("\n\n");
		printf("The Reversed String (i.e : 'chArray_Reversed[]') Is : \n\n");
		printf("%s\n", chArray_Reversed_RAD);
		if (chArray_Reversed_RAD)
		{
			free(chArray_Reversed_RAD);
			chArray_Reversed_RAD = NULL;
			printf("\n\n");
			printf("MEMORY ALLOCATED TO REVERSED STRING HAS BEEN SUCCESSFULLY FREED !!!\n\n");
		}
		if (chArray_original_RAD)
		{
			free(chArray_original_RAD);
			chArray_original_RAD = NULL;
			printf("\n\n");
			printf("MEMORY ALLOCATED TO ORIGINAL STRING HAS BEEN SUCCESSFULLY FREED !!!\n\n");
		}
		return(0);
}
void MyStrrev(char *str_destination_RAD, char *str_source_RAD)
{
	//function prototype
	int MyStrlen(char*);
	//variable declarations
	int iStringLength_RAD = 0;
	int i_RAD, j_RAD, len_RAD;
	//code
	iStringLength_RAD = MyStrlen(str_source_RAD);
	
				len_RAD = iStringLength_RAD - 1;
	
		for (i_RAD = 0, j_RAD = len_RAD; i_RAD < iStringLength_RAD, j_RAD >= 0; i_RAD++, j_RAD--)
		{
			*(str_destination_RAD + i_RAD) = *(str_source_RAD + j_RAD);
		}
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


