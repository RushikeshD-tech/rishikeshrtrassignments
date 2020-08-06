#include <stdio.h>
int main(void)
{
	//function declarations
	void MathematicalOperations(int, int, int*, int*, int*, int*, int*);
	//variable declaration
	int a_RAD;
	int b_RAD;
	int answer_sum_RAD;
	int answer_difference_RAD;
	int answer_product_RAD;
	int answer_quotient_RAD;
	int answer_remainder_RAD;
	//code
	printf("\n\n");
	printf("Enter Value Of 'A' : ");
	scanf("%d", &a_RAD);
	printf("\n\n");
	printf("Enter Value Of 'B' : ");
	scanf("%d", &b_RAD);
	MathematicalOperations(a_RAD, b_RAD, &answer_sum_RAD, &answer_difference_RAD,&answer_product_RAD, &answer_quotient_RAD, &answer_remainder_RAD);
	printf("\n\n");
	printf("****** RESULTS ****** : \n\n");
	printf("Sum = %d\n\n", answer_sum_RAD);
	printf("Difference = %d\n\n", answer_difference_RAD);
	printf("Product = %d\n\n", answer_product_RAD);
	printf("Quotient = %d\n\n", answer_quotient_RAD);
	printf("Remainder = %d\n\n", answer_remainder_RAD);
	return(0);
}
void MathematicalOperations(int x_RAD, int y_RAD, int* sum_RAD, int* difference_RAD, int* product_RAD, int* quotient_RAD, int* remainder_RAD)
{
	//code
	*sum_RAD = x_RAD + y_RAD;
	*difference_RAD = x_RAD - y_RAD;
	*product_RAD = x_RAD * y_RAD;
	*quotient_RAD = x_RAD / y_RAD;
	*remainder_RAD = x_RAD % y_RAD;

}



