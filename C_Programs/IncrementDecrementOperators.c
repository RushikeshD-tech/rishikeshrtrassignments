#include <stdio.h>

int main(void)
{
	//variable declarations
	int a_RAD = 5;
	int b_RAD = 10;

	//code
	printf("\n\n");
	printf("A = %d\n", a_RAD);
	printf("A = %d\n", a_RAD++);
	printf("A = %d\n", a_RAD);
	printf("A = %d\n\n", ++a_RAD);

	printf("B = %d\n", b_RAD);
	printf("B = %d\n", b_RAD--);
	printf("B = %d\n", b_RAD);
	printf("B = %d\n\n", --b_RAD);

	return(0);
}
