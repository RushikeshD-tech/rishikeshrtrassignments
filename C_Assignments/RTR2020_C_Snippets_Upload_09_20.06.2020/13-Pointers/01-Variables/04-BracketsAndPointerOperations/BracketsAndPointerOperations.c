#include <stdio.h>
int main(void)
{
	//variable declarations
	int num_RAD;
	int* ptr_RAD = NULL;
	int ans_RAD;
	//code
	num_RAD = 5;
	ptr_RAD = &num_RAD;
	printf("\n\n");
	printf(" num = %d\n", num_RAD);
	printf(" &num = %p\n", &num_RAD);
	printf(" *(&num) = %d\n", *(&num_RAD));
	printf(" ptr = %p\n", ptr_RAD);
	printf(" *ptr = %d\n", *ptr_RAD);
	printf("\n\n");

	printf("Answer Of (ptr + 10) = %p\n", (ptr_RAD + 10));
	printf("Answer Of *(ptr + 10) = %d\n", *(ptr_RAD + 10));
	printf("Answer Of (*ptr + 10) = %d\n\n", (*ptr_RAD + 10));
	printf("Answer Of ++*ptr : %d\n", *ptr_RAD);
	printf("Answer Of *ptr++ : %d\n", *ptr_RAD);
	printf("Answer Of (*ptr)++ : %d\n\n", *ptr_RAD);

	return(0);
}





