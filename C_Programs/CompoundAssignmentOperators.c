#include <stdio.h>

int main(void)
{
	//variable declarations
	int a_RAD;
	int b_RAD;
	int x_RAD;

	//code
	printf("\n\n");
	printf("Enter A Number : ");
	scanf("%d", &a_RAD);

	printf("\n\n");
	printf("Enter Another Number : ");
	scanf("%d", &b_RAD);

	printf("\n\n");

	
	x_RAD = a_RAD;
	a_RAD += b_RAD; // a = a + b
	printf("Addition Of A = %d And B = %d Gives %d.\n", x_RAD, b_RAD, a_RAD);

	
	x_RAD = a_RAD;
	a_RAD -= b_RAD; // a = a - b
	printf("Subtraction Of A = %d And B = %d Gives %d.\n", x_RAD, b_RAD, a_RAD);

	
	x_RAD = a_RAD;
	a_RAD *= b_RAD; // a = a * b
	printf("Multiplication Of A = %d And B = %d Gives %d.\n", x_RAD, b_RAD, a_RAD);

	
	x_RAD = a_RAD;
	a_RAD /= b_RAD; // a = a / b 
	printf("Division Of A = %d And B = %d Gives Quotient %d.\n", x_RAD, b_RAD, a_RAD);

	
	x_RAD = a_RAD;
	a_RAD %= b_RAD; // a = a % b
	printf("Division Of A = %d And B = %d Gives Remainder %d.\n", x_RAD, b_RAD, a_RAD);

	printf("\n\n");

	return(0);
}
