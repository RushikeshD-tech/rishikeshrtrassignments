#include <stdio.h>
#define MAX_STRING_LENGTH 512
int main(void)
{
	//function prototype
	int MyStrlen(char[]);
	void MyStrcpy(char[], char[]);
	//variable declarations
	char chArray_RAD[MAX_STRING_LENGTH]; 
	int iStringLength_RAD;
	int i_RAD;
	int word_count_RAD = 0, space_count_RAD = 0;
	//code
	
	printf("\n\n");
	printf("Enter A String : \n\n");
	gets_s(chArray_RAD, MAX_STRING_LENGTH);
	iStringLength_RAD = MyStrlen(chArray_RAD);
	for (i_RAD = 0; i_RAD < iStringLength_RAD; i_RAD++)
	{
		switch (chArray_RAD[i_RAD])
		{
		case 32: 
			space_count_RAD++;
			break;
		default:
			break;
		}
	}
	word_count_RAD = space_count_RAD + 1;
	
	printf("\n\n");
	printf("String Entered By You Is : \n\n");
	printf("%s\n", chArray_RAD);
	printf("\n\n");
	printf("Number Of Spaces In The Input String = %d\n\n", space_count_RAD);
	printf("Number Of Words In The Input String = %d\n\n", word_count_RAD);
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

