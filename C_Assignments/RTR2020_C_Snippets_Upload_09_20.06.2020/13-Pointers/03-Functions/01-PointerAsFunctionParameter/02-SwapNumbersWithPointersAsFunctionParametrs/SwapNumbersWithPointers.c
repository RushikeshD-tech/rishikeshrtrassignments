#include <stdio.h>
int main(void)
{
	//function declarations
	void SwapNumbers(int*, int*);
	//variable declaration
	int a_RAD;
	int b_RAD;
	//code
	printf("\n\n");
	printf("Enter Value For 'A' : ");
	scanf("%d", &a_RAD);
	printf("\n\n");
	printf("Enter Value For 'B' : ");
	scanf("%d", &b_RAD);
	printf("\n\n");
	printf("****** BEFORE SWAPPING ******\n\n");
	printf("Value Of 'A' = %d\n\n", a_RAD);
	printf("Value Of 'B' = %d\n\n", b_RAD);
	SwapNumbers(&a_RAD, &b_RAD); 

	printf("\n\n");
	printf("****** AFTER SWAPPING ******\n\n");
	printf("Value Of 'A' = %d\n\n", a_RAD);
	printf("Value Of 'B' = %d\n\n", b_RAD);
	return(0);
}
void SwapNumbers(int* x_RAD, int* y_RAD)
{

	//varibale declarations
	int temp_RAD;
	
	//code
	printf("\n\n");
	printf("****** BEFORE SWAPPING ******\n\n");
	printf("Value Of 'X' = %d\n\n", *x_RAD);
	printf("Value Of 'Y' = %d\n\n", *y_RAD);
	temp_RAD = *x_RAD;
	*x_RAD = *y_RAD;
	*y_RAD = temp_RAD;
	printf("\n\n");
	printf("****** AFTER SWAPPING ******\n\n");
	printf("Value Of 'X' = %d\n\n", *x_RAD);
	printf("Value Of 'Y' = %d\n\n", *y_RAD);
}


