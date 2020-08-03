#include<stdio.h>

int main(void)
{
	//varibale declarations
	float num_RAD;
	float* ptr_RAD = NULL;

	//code
	num_RAD = 6.9f;

	printf("\n\n");

	printf("*******BEFORE ptr = &num*********\n\n");
	printf("Value of 'num'       =%f\n\n", num_RAD);
	printf("Address of 'num'     =%p\n\n", &num_RAD);
	printf("Value At Address  of 'num' =%f\n\n", *(&num_RAD));

	//Assigning address of variable 'num' to pointer variable 'ptr'
	//'ptr' now contains address of 'num' ...hence, 'ptr' is SAME as '&num'

	ptr_RAD = &num_RAD;

	printf(" ****** AFTER ptr = &num ******\n\n");
	printf("Value Of 'num' = %f\n\n", num_RAD);
	printf("Address Of 'num' = %p\n\n", ptr_RAD);
	printf("Value At Address Of 'num' = %f\n\n", *ptr_RAD);
	return(0);
}


