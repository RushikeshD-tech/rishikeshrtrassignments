#include <stdio.h>
int main(void)
{
	//variable declarations
	int num_RAD;
	int* ptr_RAD = NULL;
	int** pptr_RAD = NULL;

	//code

	num_RAD = 10;
	printf("\n\n");
	printf(" ****** BEFORE ptr = &num ******\n\n");
	printf("Value Of 'num' = %d\n\n", num_RAD);
	printf("Address Of 'num' = %p\n\n", &num_RAD);
	printf("Value At Address Of 'num' = %d\n\n", *(&num_RAD));

	ptr_RAD = &num_RAD;
	printf("\n\n");
	printf(" ****** AFTER ptr = &num ******\n\n");
	printf("Value Of 'num' = %d\n\n", num_RAD);
	printf("Address Of 'num' = %p\n\n", ptr_RAD);
	printf("Value At Address Of 'num' = %d\n\n", *ptr_RAD);
	pptr_RAD = &ptr_RAD;
	printf("\n\n");
	printf(" ****** AFTER pptr = &ptr ******\n\n");
	printf("Value Of 'num' = %d\n\n", num_RAD);
	printf("Address Of 'num' (ptr) = %p\n\n", ptr_RAD);
	printf("Address Of 'ptr' (pptr) = %p\n\n", pptr_RAD);
	printf("Value At Address Of 'ptr' (*pptr) = %p\n\n", *pptr_RAD);
	printf("Value At Address Of 'num' (*ptr) (*pptr) = %d\n\n", **pptr_RAD);
	return(0);
}


