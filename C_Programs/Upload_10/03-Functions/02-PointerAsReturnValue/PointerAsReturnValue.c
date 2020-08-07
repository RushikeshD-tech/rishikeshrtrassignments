#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 512
int main(void)
{
	//function declarations
	char* ReplaceVowelsWithHashSymbol(char*);
	
	//variable declaration
	char string_RAD[MAX_STRING_LENGTH];
	char* replaced_string_RAD = NULL;
	
	//code
	printf("\n\n");
	printf("Enter String : ");
	gets_s(string_RAD, MAX_STRING_LENGTH);
	replaced_string_RAD = ReplaceVowelsWithHashSymbol(string_RAD);
	if (replaced_string_RAD == NULL)
	{
		printf("ReplaceVowelsWithHashSymbol() Function Has Failed !!! Exitiing Now...\n\n");
			exit(0);
	}
	printf("\n\n");
	printf("Replaced String Is : \n\n");
	printf("%s\n\n", replaced_string_RAD);
	if (replaced_string_RAD)
	{
		free(replaced_string_RAD);
		replaced_string_RAD = NULL;
	}
	return(0);
}
char* ReplaceVowelsWithHashSymbol(char* s)
{
	//function prototype
	void MyStrcpy(char*, char*);
	int MyStrlen(char*);
	//varibale declarations
	char* new_string_RAD = NULL;
	int i_RAD;
	//code
	new_string_RAD = (char*)malloc(MyStrlen(s) * sizeof(char));
	if (new_string_RAD == NULL)
	{
		printf("COULD NOT ALLOCATE MEMORY FOR NEW STRING !!!\n\n");
		return(NULL);
	}
	MyStrcpy(new_string_RAD, s);
	for (i_RAD = 0; i_RAD < MyStrlen(new_string_RAD); i_RAD++)
	{
		switch (new_string_RAD[i_RAD])
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
			new_string_RAD[i_RAD] = '#';
			break;
		default:
			break;
		}
	}
	return(new_string_RAD);
}
void MyStrcpy(char* str_destination_RAD, char* str_source_RAD)
{
	//function prototype
	int MyStrlen(char*);
	//variable declarations
	int iStringLength_RAD = 0;
	int j_RAD;
	//code
	iStringLength_RAD = MyStrlen(str_source_RAD);
	for (j_RAD = 0; j_RAD < iStringLength_RAD; j_RAD++)
		*(str_destination_RAD + j_RAD) = *(str_source_RAD + j_RAD);
	*(str_destination_RAD + j_RAD) = '\0';
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





