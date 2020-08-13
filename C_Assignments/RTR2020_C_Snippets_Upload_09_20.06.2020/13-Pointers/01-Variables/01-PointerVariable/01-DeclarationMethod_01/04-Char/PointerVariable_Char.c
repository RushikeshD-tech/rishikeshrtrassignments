#include <stdio.h>

int main(void)
{
	//variable declarations
	char ch_RAD;
	char* ptr_RAD = NULL;

	//code
	ch_RAD = 'A';

	printf("\n\n");

	printf(" ****** BEFORE ptr = &ch ******\n\n");
	printf("Value Of 'ch' = %c\n\n", ch_RAD);
	printf("Address Of 'ch' = %p\n\n", &ch_RAD);
	printf("Value At Address Of 'ch' = %c\n\n", *(&ch_RAD));
	
	//Assigning address of variable 'ch' to pointer variable 'ptr'
	//'ptr' now contains address of 'ch'...hence, 'ptr' is SAME as '&ch'
	
	ptr_RAD = &ch_RAD;
	
	printf("\n\n");
	printf(" ****** AFTER ptr = &ch ******\n\n");
	printf("Value Of 'ch' = %c\n\n", ch_RAD);
	printf("Address Of 'ch' = %p\n\n", ptr_RAD);
	printf("Value At Address Of 'ch' = %c\n\n", *ptr_RAD);
	return(0);

}


