#include <stdio.h>
#define MAX_STRING_LENGTH 512
int main(void)
{
	//function prototype
	int MyStrlen(char[]);
	void MyStrcpy(char[], char[]);
	
	//variable declarations
	char chArray_RAD[MAX_STRING_LENGTH], chArray_SpacesRemoved_RAD[MAX_STRING_LENGTH]; //
	
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
		if (chArray_RAD[i_RAD] == ' ')
			continue;
		else
		{
			chArray_SpacesRemoved_RAD[j_RAD] = chArray_RAD[i_RAD];
			j_RAD++;
		}
	}
	chArray_SpacesRemoved_RAD[j_RAD] = '\0';
	
	printf("\n\n");
	printf("String Entered By You Is : \n\n");
	printf("%s\n", chArray_RAD);
	printf("\n\n");
	printf("String After Removal Of Spaces Is : \n\n");
	printf("%s\n", chArray_SpacesRemoved_RAD);
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




