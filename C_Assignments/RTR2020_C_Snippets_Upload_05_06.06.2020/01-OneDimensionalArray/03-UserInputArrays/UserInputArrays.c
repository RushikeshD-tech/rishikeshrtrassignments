#include<stdio.h>

#define INT_ARRAY_NUM_ELEMENTS 5
#define FLOAT_ARRAY_NUM_ELEMENTS 3
#define CHAR_ARRAY_NUM_ELEMENTS 15

int main(void)
{
	//variable declarations
	int iArray_RAD[INT_ARRAY_NUM_ELEMENTS];
	float fArray_RAD[FLOAT_ARRAY_NUM_ELEMENTS];
	char cArray_RAD[CHAR_ARRAY_NUM_ELEMENTS];

	int i_RAD, num_RAD;

	//code 

	printf("\n\n");
	printf("Enter Elements For 'Integer' Array : \n");
	for (i_RAD = 0; i_RAD < INT_ARRAY_NUM_ELEMENTS; i_RAD++)
		scanf("%d", &iArray_RAD[i_RAD]);

	printf("\n\n");
	printf("Enter Elements For 'Floating-Point' array : \n");
	for (i_RAD = 0; i_RAD < FLOAT_ARRAY_NUM_ELEMENTS; i_RAD++)
		scanf("%f", &fArray_RAD[i_RAD]);

	printf("\n\n");
	printf("EnterElements 'character' Array : \n");
	for (i_RAD = 0; i_RAD < CHAR_ARRAY_NUM_ELEMENTS; i_RAD++)
	{

		cArray_RAD[i_RAD] = getch();
		printf("%c\n", cArray_RAD[i_RAD]);

	}

	printf("\n\n");
	printf("Integer Array Enterd By You : \n\n");
	for (i_RAD = 0; i_RAD < INT_ARRAY_NUM_ELEMENTS; i_RAD++)
		printf("%d\n", iArray_RAD[i_RAD]);

	printf(" \n\n");
	printf("Integer Array Entered By You : \n\n");
	for (i_RAD = 0; i_RAD < INT_ARRAY_NUM_ELEMENTS; i_RAD++)
		printf("%d\n", iArray_RAD[i_RAD]);

	printf("\n\n");
	printf("Floating-Point Array Enterd By You : \n\n");
	printf("%f\n", fArray_RAD[i_RAD]);
	;

	printf("Character Array Enterd By You : \n\n");
	for (i_RAD = 0; i_RAD < CHAR_ARRAY_NUM_ELEMENTS; i_RAD++)
		printf("%c\n", cArray_RAD[i_RAD]);

	return(0);  
}

