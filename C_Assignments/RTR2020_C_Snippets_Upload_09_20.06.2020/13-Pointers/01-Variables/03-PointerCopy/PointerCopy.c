#include <stdio.h>
int main(void)
{
	//variable declarations
	int num_RAD;
	int* ptr_RAD = NULL;
	int* copy_ptr_RAD = NULL;

	//code
	num_RAD = 5;
	ptr_RAD = &num_RAD;
	printf("\n\n");
	printf("****** BEFORE copy_ptr = ptr ******\n\n");
	printf(" num = %d\n", num_RAD);
	printf(" &num = %p\n", &num_RAD);
	printf(" *(&num) = %d\n", *(&num_RAD));
	printf(" ptr = %p\n", ptr_RAD);
	printf(" *ptr = %d\n", *ptr_RAD);

	copy_ptr_RAD = ptr_RAD; 

	printf("\n\n");
	printf("****** AFTER copy_ptr = ptr ******\n\n");
	printf(" num = %d\n", num_RAD);
	printf(" &num = %p\n", &num_RAD);
	printf(" *(&num) = %d\n", *(&num_RAD));
	printf(" ptr = %p\n", ptr_RAD);
	printf(" *ptr = %d\n", *ptr_RAD);
	printf(" copy_ptr = %p\n", copy_ptr_RAD);
	printf(" *copy_ptr = %d\n", *copy_ptr_RAD);

	return(0);
}


