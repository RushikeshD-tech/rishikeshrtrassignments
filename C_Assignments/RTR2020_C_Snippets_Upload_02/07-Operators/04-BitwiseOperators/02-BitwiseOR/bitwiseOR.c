#include<stdio.h>

int main(void)
{
	 //function prototypes
	void PrintBinaryFormOfNumber(unsigned int);

	//variable declarations
	unsigned int a_RAD;
	unsigned int b_RAD;
	unsigned int result_RAD;

	//code
	printf("\n\n");
	printf("Enter An Integer = ");
	scanf("%u", &a_RAD);

	printf("\n\n");
	printf("Enter Another Integer = ");
	scanf("%u", &b_RAD);

	printf("\n\n\n\n");
	result_RAD = a_RAD | b_RAD;
	printf("Bitwise OR-ing Of \nA = %d (Decimal) and B = %d (Decimal) gives result %d (Decimal).\n\n", a_RAD, b_RAD, result_RAD);

	PrintBinaryFormOfNumber(a_RAD);
	PrintBinaryFormOfNumber(b_RAD);
	PrintBinaryFormOfNumber(result_RAD);

	return(0);

}

void PrintBinaryFormOfNumber(unsigned int decimal_number)
{
	//variable declarations
	unsigned int quotient_RAD, remainder_RAD;
	unsigned int num_RAD;
	unsigned int binary_array_RAD[8];
	int i_RAD;

	//code
	for (i_RAD = 0; i_RAD < 8; i_RAD++)
		binary_array_RAD[i_RAD] = 0;

	printf("The Binary Form Of Decimal Integer %d Is\t=\t", decimal_number);
	num_RAD = decimal_number;
	i_RAD = 7;
	while (num_RAD != 0)
	{
		quotient_RAD = num_RAD / 2;
		remainder_RAD = num_RAD % 2;
		binary_array_RAD[i_RAD] = remainder_RAD;
		num_RAD = quotient_RAD;
		i_RAD--;
	}
	for (i_RAD = 0; i_RAD < 8; i_RAD++)
		printf("%u", binary_array_RAD[i_RAD]);

	printf("\n\n");
}




