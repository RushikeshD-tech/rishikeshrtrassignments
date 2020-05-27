#include <stdio.h>

int main(void)
{
	//variable declarations
	int a_RAD;
	int b_RAD;
	int result_RAD;

	//code
	printf("\n\n");
	printf("Enter A Number : ");
	scanf("%d", &a_RAD);

	printf("\n\n");
	printf("Enter Another Number : ");
	scanf("%d", &b_RAD);

	printf("\n\n");

	
	result_RAD = a_RAD + b_RAD;
	printf("Addition Of A = %d And B = %d Gives %d.\n", a_RAD, b_RAD, result_RAD);

	result_RAD = a_RAD - b_RAD;
	printf("Subtraction Of A = %d And B = %d Gives %d.\n", a_RAD, b_RAD, result_RAD);

	result_RAD = a_RAD * b_RAD;
	printf("Multiplication Of A = %d And B = %d Gives %d.\n", a_RAD, b_RAD, result_RAD);

	result_RAD = a_RAD / b_RAD;
	printf("Division Of A = %d And B = %d Gives Quotient %d.\n", a_RAD, b_RAD, result_RAD);

	result_RAD = a_RAD % b_RAD;
	printf("Division Of A = %d And B = %d Gives Remainder %d.\n", a_RAD, b_RAD, result_RAD);

	printf("\n\n");

	return(0);
}
