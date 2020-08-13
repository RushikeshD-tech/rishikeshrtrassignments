#include <stdio.h>
#define MAX_STRING_LENGTH 512
int main(void)
{
	//function prototype
	void MyStrrev(char[], char[]);
	//variable declarations
	char chArray_Original_RAD[MAX_STRING_LENGTH], chArray_Reversed_RAD[MAX_STRING_LENGTH];
		
	//code
		
	printf("\n\n");
	printf("Enter A String : \n\n");
	gets_s(chArray_Original_RAD, MAX_STRING_LENGTH);
	
	MyStrrev(chArray_Reversed_RAD, chArray_Original_RAD);
	
	printf("\n\n");
	printf("The Original String Entered By You (i.e : 'chArray_Original[]') Is :\n\n");
	printf("%s\n", chArray_Original_RAD);
	printf("\n\n");
	printf("The Reversed String (i.e : 'chArray_Reversed[]') Is : \n\n");
	printf("%s\n", chArray_Reversed_RAD);
	return(0);
}
void MyStrrev(char str_destination[], char str_source[])
{
	
	int MyStrlen(char[]);

	//variable declarations

	int iStringLength_RAD = 0;
	int i_RAD, j_RAD, len_RAD;

	//code

	iStringLength_RAD = MyStrlen(str_source);
	len_RAD = iStringLength_RAD - 1;

	for (i_RAD = 0, j_RAD = len_RAD; i_RAD < iStringLength_RAD, j_RAD >= 0; i_RAD++, j_RAD--)
	{
		str_destination[i_RAD] = str_source[j_RAD];
	}
	str_destination[i_RAD] = '\0';
}
int MyStrlen(char str[])
{
	//variable declarations
	int j_RAD;
	int string_length_RAD = 0;
	for (j_RAD = 0; j_RAD < MAX_STRING_LENGTH; j_RAD++)
	{
		if (str[j_RAD] == '\0')
			break;
		else
			string_length_RAD++;
	}
	return(string_length_RAD);
}




