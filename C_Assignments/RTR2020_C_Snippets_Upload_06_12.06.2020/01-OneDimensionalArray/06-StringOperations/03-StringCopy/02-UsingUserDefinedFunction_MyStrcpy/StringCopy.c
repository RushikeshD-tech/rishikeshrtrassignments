#include <stdio.h>
#define MAX_STRING_LENGTH 512
int main(void)
{
	
	void MyStrcpy(char[], char[]);
	
	//variable declarations
	char chArray_Original_RAD[MAX_STRING_LENGTH], chArray_Copy_RAD[MAX_STRING_LENGTH]; 
		//code
		
		printf("\n\n");
	printf("Enter A String : \n\n");
	gets_s(chArray_Original_RAD, MAX_STRING_LENGTH);
	
	MyStrcpy(chArray_Copy_RAD, chArray_Original_RAD);
	
	printf("\n\n");
	printf("The Original String Entered By You (i.e : 'chArray_Original[]') Is :\n\n");
		printf("%s\n", chArray_Original_RAD);
	printf("\n\n");
	printf("The Copied String (i.e : 'chArray_Copy[]') Is : \n\n");
	printf("%s\n", chArray_Copy_RAD);
	return(0);
}
void MyStrcpy(char str_destination[], char str_source[])
{
	
	int MyStrlen(char[]);
	//variable declarations
	int iStringLength_RAD = 0;
	int j_RAD;
	//code
	iStringLength_RAD = MyStrlen(str_source);
	for (j_RAD = 0; j_RAD < iStringLength_RAD; j_RAD++)
		str_destination[j_RAD] = str_source[j_RAD];
	str_destination[j_RAD] = '\0';
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



