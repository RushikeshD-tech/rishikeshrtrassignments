#include <stdio.h>
#include <string.h> 
#define MAX_STRING_LENGTH 512
int main(void)
{
	//variable declarations
	char chArray_Original_RAD[MAX_STRING_LENGTH];
	//code
	
	printf("\n\n");
	printf("Enter A String : \n\n");
	gets_s(chArray_Original_RAD, MAX_STRING_LENGTH);
	
	printf("\n\n");
	printf("The Original String Entered By You (i.e : 'chArray_Original[]') Is :\n\n");
		printf("%s\n", chArray_Original_RAD);
	printf("\n\n");
	printf("The Reversed String (i.e : 'chArray_Reverse[]') Is : \n\n");
	printf("%s\n", strrev(chArray_Original_RAD));
	return(0);
}

