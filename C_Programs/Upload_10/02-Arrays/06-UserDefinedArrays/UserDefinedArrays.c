#include <stdio.h>
#include <stdlib.h>
#define INT_SIZE sizeof(int)
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)
#define CHAR_SIZE sizeof(char)
int main(void)
{
	//variable declarations
	int* ptr_iArray_RAD = NULL;
	unsigned int intArrayLength_RAD = 0;
	float* ptr_fArray_RAD = NULL;
	unsigned int floatArrayLength_RAD = 0;
	double* ptr_dArray_RAD = NULL;
	unsigned int doubleArrayLength_RAD = 0;
	char* ptr_cArray_RAD = NULL;
	unsigned int charArrayLength_RAD = 0;
	int i_RAD;
	//code
	// ****** INTEGER ARRAY *******
	printf("\n\n");
	printf("Enter The Number Of Elements You Want In The Integer Array : ");
	scanf("%u", &intArrayLength_RAD);
	ptr_iArray_RAD = (int*)malloc(INT_SIZE * intArrayLength_RAD);
	if (ptr_iArray_RAD == NULL)
	{
		printf("\n\n");
		printf("MEMORY ALLOCATION FOR INTEGER ARRAY FAILED !!! EXITTING NOW...\n\n");
			exit(0);
	}
	else
	{
		printf("\n\n");
		printf("MEMORY ALLOCATION FOR INTEGER ARRAY SUCCEEDED !!!\n\n");
	}
	printf("\n\n");
	printf("Enter The %d Integer Elements To Fill Up The Integer Array : \n\n", intArrayLength_RAD);
		for (i_RAD = 0; i_RAD < intArrayLength_RAD; i_RAD++)
			scanf("%d", (ptr_iArray_RAD + i_RAD));
	// ****** FLOAT ARRAY *******
	printf("\n\n");
	printf("Enter The Number Of Elements You Want In The 'float' Array : ");
	scanf("%u", &floatArrayLength_RAD);
	ptr_fArray_RAD = (float*)malloc(FLOAT_SIZE * floatArrayLength_RAD);
	if (ptr_fArray_RAD == NULL)
	{
		printf("\n\n");
		printf("MEMORY ALLOCATION FOR FLOATING-POINT ARRAY FAILED !!! EXITTING NOW...\n\n");
			exit(0);
	}
	else
	{
		printf("\n\n");
		printf("MEMORY ALLOCATION FOR FLOATING-POINT ARRAY SUCCEEDED !!!\n\n");
	}
	printf("\n\n");
	printf("Enter The %d Floating-Point Elements To Fill Up The 'float' Array : \n\n", floatArrayLength_RAD);
		for (i_RAD = 0; i_RAD < floatArrayLength_RAD; i_RAD++)
			scanf("%f", (ptr_fArray_RAD + i_RAD));
	// ****** DOUBLE ARRAY *******
	printf("\n\n");
	printf("Enter The Number Of Elements You Want In The 'double' Array : ");
	scanf("%u", &doubleArrayLength_RAD);
	ptr_dArray_RAD = (double*)malloc(DOUBLE_SIZE * doubleArrayLength_RAD);
	if (ptr_dArray_RAD == NULL)
	{
		printf("\n\n");
		printf("MEMORY ALLOCATION FOR 'DOUBLE' ARRAY FAILED !!! EXITTING NOW...\n\n");
			exit(0);
	}
	else
	{
		printf("\n\n");
		printf("MEMORY ALLOCATION FOR 'DOUBLE' ARRAY SUCCEEDED !!!\n\n");
	}
	printf("\n\n");
	printf("Enter The %d Double Elements To Fill Up The 'double' Array : \n\n", doubleArrayLength_RAD);
		for (i_RAD = 0; i_RAD < doubleArrayLength_RAD; i_RAD++)
			scanf("%lf", (ptr_dArray_RAD + i_RAD));
	// ****** CHAR ARRAY *******
	printf("\n\n");
	printf("Enter The Number Of Elements You Want In The Character Array : ");
	scanf("%u", &charArrayLength_RAD);
	ptr_cArray_RAD = (char*)malloc(CHAR_SIZE * charArrayLength_RAD);
	if (ptr_cArray_RAD == NULL)
	{
		printf("\n\n");
		printf("MEMORY ALLOCATION FOR CHARACTER ARRAY FAILED !!! EXITTING NOW...\n\n");
			exit(0);
	}
	else
	{
		printf("\n\n");
		printf("MEMORY ALLOCATION FOR CHARACTER ARRAY SUCCEEDED !!!\n\n");
	}
	printf("\n\n");
	printf("Enter The %d Character Elements To Fill Up The Character Array :\n\n", charArrayLength_RAD);
		for (i_RAD = 0; i_RAD < charArrayLength_RAD; i_RAD++)
		{
			*(ptr_cArray_RAD + i_RAD) = getch();
			printf("%c\n", *(ptr_cArray_RAD + i_RAD));
		}
	// ********** DISPLAY OF ARRAYS **********
	// ****** INTEGER ARRAY ******
	printf("\n\n");
	printf("The Integer Array Entered By You And Consisting Of %d Elements Is As Follows : \n\n", intArrayLength_RAD);
		for (i_RAD = 0; i_RAD < intArrayLength_RAD; i_RAD++)
	printf(" %d \t \t At Address : %p\n", *(ptr_iArray_RAD + i_RAD), (ptr_iArray_RAD + i_RAD));
	// ****** FLOAT ARRAY ******
	printf("\n\n");
	printf("The Float Array Entered By You And Consisting Of %d Elements Is As Follows : \n\n", floatArrayLength_RAD);
		for (i_RAD = 0; i_RAD < floatArrayLength_RAD; i_RAD++)
	printf(" %f \t \t At Address : %p\n", *(ptr_fArray_RAD + i_RAD), (ptr_fArray_RAD + i_RAD));
	// ****** DOUBLE ARRAY ******
	printf("\n\n");
	printf("The Double Array Entered By You And Consisting Of %d Elements Is As Follows : \n\n", doubleArrayLength_RAD);
		for (i_RAD = 0; i_RAD < doubleArrayLength_RAD; i_RAD++)
			printf(" %lf \t \t At Address : %p\n", *(ptr_dArray_RAD + i_RAD), (ptr_dArray_RAD + i_RAD));
	// ****** CHARACTER ARRAY ******
	printf("\n\n");
	printf("The Character Array Entered By You And Consisting Of %d Elements Is As Follows : \n\n", charArrayLength_RAD);
		for (i_RAD = 0; i_RAD < charArrayLength_RAD; i_RAD++)
	printf(" %c \t \t At Address : %p\n", *(ptr_cArray_RAD + i_RAD), (ptr_cArray_RAD + i_RAD));

		if (ptr_cArray_RAD)
		{
			free(ptr_cArray_RAD);
			ptr_cArray_RAD = NULL;
			printf("\n\n");
			printf("MEMORY OCCUPIED BY CHARACTER ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n");
		}
		if (ptr_dArray_RAD)
		{
			free(ptr_dArray_RAD);
			ptr_dArray_RAD = NULL;
			printf("\n\n");
			printf("MEMORY OCCUPIED BY 'DOUBLE' ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n");
		}
		if (ptr_fArray_RAD)
		{
			free(ptr_fArray_RAD);
			ptr_fArray_RAD = NULL;
			printf("\n\n");
			printf("MEMORY OCCUPIED BY FLOATING-POINT ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n");
		}
		if (ptr_iArray_RAD)
		{
			free(ptr_iArray_RAD);
			ptr_iArray_RAD = NULL;
			printf("\n\n");
			printf("MEMORY OCCUPIED BY INTEGER ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n");
		}
		return(0);
}


