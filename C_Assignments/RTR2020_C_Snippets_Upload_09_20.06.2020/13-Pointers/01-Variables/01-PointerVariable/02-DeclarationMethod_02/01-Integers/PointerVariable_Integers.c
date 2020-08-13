#include <stdio.h>
int main(void)
{
	//variable declarations
	int num_RAD;
	int* ptr_RAD = NULL;

	//code

	num_RAD = 10;

	printf("\n\n");
	printf(" ****** BEFORE ptr = &num ******\n\n");
	printf("Value Of 'num' = %d\n\n", num_RAD);
	printf("Address Of 'num' = %p\n\n", &num_RAD);
	printf("Value At Address Of 'num' = %d\n\n", *(&num_RAD));

	//Assigning address of variable 'num' to pointer variable 'ptr'
	//'ptr' now contains address of 'num'...hence, 'ptr' is SAME as '&num'

	ptr_RAD = &num_RAD;

	printf("\n\n");
	printf(" ****** AFTER ptr = &num ******\n\n");
	printf("Value Of 'num' = %d\n\n", num_RAD);
	printf("Address Of 'num' = %p\n\n", ptr_RAD);
	printf("Value At Address Of 'num' = %d\n\n", *ptr_RAD);

	return(0);
}



