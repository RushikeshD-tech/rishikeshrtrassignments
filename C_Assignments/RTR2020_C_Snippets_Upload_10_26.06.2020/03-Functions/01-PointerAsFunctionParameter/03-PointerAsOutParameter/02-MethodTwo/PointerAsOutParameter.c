#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	//function declarations
	void MathematicalOperations(int, int, int*, int*, int*, int*, int*);
	//variable declaration
	int a_RAD;
	int b_RAD;
	int* answer_sum_RAD = NULL;
	int* answer_difference_RAD = NULL;
	int* answer_product_RAD = NULL;
	int* answer_quotient_RAD = NULL;
	int* answer_remainder_RAD = NULL;
	//code
	printf("\n\n");
	printf("Enter Value Of 'A' : ");
	scanf("%d", &a_RAD);
	printf("\n\n");
	printf("Enter Value Of 'B' : ");
	scanf("%d", &b_RAD);
	answer_sum_RAD = (int*)malloc(1 * sizeof(int));
	if (answer_sum_RAD == NULL)
	{
		printf("Could Not Allocate Memory For 'answer_sum'. Exitting Now...\n\n");
			exit(0);
	}
	answer_difference_RAD = (int*)malloc(1 * sizeof(int));
	if (answer_difference_RAD == NULL)
	{
		printf("Could Not Allocate Memory For 'answer_difference'. Exitting Now...\n\n");
			exit(0);
	}
	answer_product_RAD = (int*)malloc(1 * sizeof(int));
	if (answer_product_RAD == NULL)
	{
		printf("Could Not Allocate Memory For 'answer_product'. Exitting Now...\n\n");
			exit(0);
	}
	answer_quotient_RAD = (int*)malloc(1 * sizeof(int));
	if (answer_quotient_RAD == NULL)
	{
		printf("Could Not Allocate Memory For 'answer_quotient'. Exitting Now...\n\n");
			exit(0);
	}
	answer_remainder_RAD = (int*)malloc(1 * sizeof(int));
	if (answer_remainder_RAD == NULL)
	{
		printf("Could Not Allocate Memory For 'answer_remainder'. Exitting Now...\n\n");
			exit(0);
	}
	MathematicalOperations(a_RAD, b_RAD, answer_sum_RAD, answer_difference_RAD, answer_product_RAD, answer_quotient_RAD, answer_remainder_RAD);
	printf("\n\n");
	printf("****** RESULTS ****** \n\n");
	printf("Sum = %d\n\n", *answer_sum_RAD);
	printf("Difference = %d\n\n", *answer_difference_RAD);
	printf("Product = %d\n\n", *answer_product_RAD);
	printf("Quotient = %d\n\n", *answer_quotient_RAD);
	printf("Remainder = %d\n\n", *answer_remainder_RAD);
	if (answer_remainder_RAD)
	{
		free(answer_remainder_RAD);
		answer_remainder_RAD = NULL;
		printf("Memory Allocated For 'answer_remainder' Successfully Freed !!!\n\n");
	}
	if (answer_quotient_RAD)
	{
		free(answer_quotient_RAD);
		answer_quotient_RAD = NULL;
		printf("Memory Allocated For 'answer_quotient' Successfully Freed !!!\n\n");
	}
	if (answer_product_RAD)
	{
		free(answer_product_RAD);
		answer_product_RAD = NULL;
		printf("Memory Allocated For 'answer_product' Successfully Freed !!!\n\n");
	}
	if (answer_difference_RAD)
	{
		free(answer_difference_RAD);
		answer_difference_RAD = NULL;
		printf("Memory Allocated For 'answer_difference' Successfully Freed !!!\n\n");
	}
	if (answer_sum_RAD)
	{
		free(answer_sum_RAD);
		answer_sum_RAD = NULL;
		printf("Memory Allocated For 'answer_sum' Successfully Freed !!!\n\n");
	}
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






