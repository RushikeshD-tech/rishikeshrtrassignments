#include <stdio.h>
#define MAX_STRING_LENGTH 512
#define SPACE ' '
#define FULLSTOP '.'
#define COMMA ','
#define EXCLAMATION '!'
#define QUESTION_MARK '?'
int main(void)
{
	//function prototype
	
	int MyStrlen(char[]);
	char MyToUpper(char);
	
	//variable declarations
	
	char chArray_RAD[MAX_STRING_LENGTH], chArray_CapitalizedFirstLetterOfEveryWord_RAD[MAX_STRING_LENGTH]; 
	int iStringLength_RAD;
	int i_RAD, j_RAD;
	//code
	
	printf("\n\n");
	printf("Enter A String : \n\n");
	gets_s(chArray_RAD, MAX_STRING_LENGTH);
	iStringLength_RAD = MyStrlen(chArray_RAD);
	j_RAD = 0;
	for (i_RAD = 0; i_RAD < iStringLength_RAD; i_RAD++)
	{
		if (i_RAD == 0) 
			chArray_CapitalizedFirstLetterOfEveryWord_RAD[j_RAD] = MyToUpper(chArray_RAD[i_RAD]);
		else if (chArray_RAD[i_RAD] == SPACE) 
			
		{
			chArray_CapitalizedFirstLetterOfEveryWord_RAD[j_RAD] = chArray_RAD[i_RAD];
			chArray_CapitalizedFirstLetterOfEveryWord_RAD[j_RAD + 1] = MyToUpper(chArray_RAD[i_RAD + 1]);
		
		
				
				j_RAD++;
			i_RAD++;
		}
		else if ((chArray_RAD[i_RAD] == FULLSTOP || chArray_RAD[i_RAD] == COMMA || chArray_RAD[i_RAD] == EXCLAMATION || chArray_RAD[i_RAD] == QUESTION_MARK) && (chArray_RAD[i_RAD] != SPACE))
		{
			chArray_CapitalizedFirstLetterOfEveryWord_RAD[j_RAD] = chArray_RAD[i_RAD];
			chArray_CapitalizedFirstLetterOfEveryWord_RAD[j_RAD + 1] = SPACE;
			chArray_CapitalizedFirstLetterOfEveryWord_RAD[j_RAD + 2] = MyToUpper(chArray_RAD[i_RAD + 1]);
			j_RAD = j_RAD + 2;
			i_RAD++;
		}
		else
			chArray_CapitalizedFirstLetterOfEveryWord_RAD[j_RAD] = chArray_RAD[i_RAD];
		j_RAD++;
	}
	chArray_CapitalizedFirstLetterOfEveryWord_RAD[j_RAD] = '\0';
	// *** STRING OUTPUT ***
	printf("\n\n");
	printf("String Entered By You Is : \n\n");
	printf("%s\n", chArray_RAD);
	printf("\n\n");
	printf("String After Capitalizing First Letter Of Every Word : \n\n");
	printf("%s\n", chArray_CapitalizedFirstLetterOfEveryWord_RAD);
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
char MyToUpper(char ch)
{
	//variable declaration
	
	int num_RAD;
	int c_RAD;
	
	//code

	num_RAD = 'a' - 'A';
	if ((int)ch >= 97 && (int)ch <= 122)
	{
		c_RAD = (int)ch - num_RAD;
		return((char)c_RAD);
	}
	else
		return(ch);
}


