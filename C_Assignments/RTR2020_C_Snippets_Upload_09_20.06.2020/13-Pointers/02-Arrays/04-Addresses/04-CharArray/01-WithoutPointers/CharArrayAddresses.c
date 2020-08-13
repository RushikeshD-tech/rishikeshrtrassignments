#include <stdio.h>
int main(void)
{
	//variable declarations
	char cArray_RAD[10];
	int i_RAD;
	//code
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
		cArray_RAD[i_RAD] = (char)(i_RAD + 65);
	printf("\n\n");
	printf("Elements Of The Character Array : \n\n");
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
		printf("cArray[%d] = %c\n", i_RAD, cArray_RAD[i_RAD]);
	printf("\n\n");
	printf("Elements Of The Character Array : \n\n");
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
		printf("cArray[%d] = %c \t \t Address = %p\n", i_RAD, cArray_RAD[i_RAD], &cArray_RAD[i_RAD]);
	printf("\n\n");
	return(0);
}



