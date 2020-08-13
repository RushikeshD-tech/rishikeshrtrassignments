#include <stdio.h> 

int main(int argc, char *argv[], char *envp[])
{
	//function prototypes OR declarations
	void MyAddition(void);
	int MySubtraction(void);
	void MyMultiplication(int, int);
	int MyDivision(int, int);
	//variable declarations
	int result_subtraction_RAD;
	int a_multiplication_RAD, b_multiplication_RAD;
	int a_division_RAD, b_division_RAD, result_division_RAD;
	//code
	
	MyAddition(); 
	
	result_subtraction_RAD = MySubtraction(); 
	printf("\n\n");
	printf("Subtraction Yields Result = %d\n", result_subtraction_RAD);

	printf("\n\n");
	printf("Enter Integer Value For 'A' For Multiplication : ");
	scanf("%d", &a_multiplication_RAD);
	printf("\n\n");
	printf("Enter Integer Value For 'B' For Multiplication : ");
	scanf("%d", &b_multiplication_RAD);
	MyMultiplication(a_multiplication_RAD, b_multiplication_RAD); //function call
	
	printf("\n\n");
	printf("Enter Integer Value For 'A' For Division : ");
	scanf("%d", &a_division_RAD);
	printf("\n\n");
	printf("Enter Integer Value For 'B' For Division : ");
	scanf("%d", &b_division_RAD);
	result_division_RAD = MyDivision(a_division_RAD, b_division_RAD); //function call
	printf("\n\n");

		printf("Division Of %d and %d Gives = %d (Quotient)\n", a_division_RAD, b_division_RAD, result_division_RAD);
	printf("\n\n");
	return(0);
}

void MyAddition(void) //function definition
{
	//variable declarations : local variables to MyAddition()
	int a_RAD, b_RAD, sum_RAD;
	//code
	printf("\n\n");
	printf("Enter Integer Value For 'A' For Addition : ");
	scanf("%d", &a_RAD);
	printf("\n\n");
	printf("Enter Integer Value For 'B' For Addition : ");
	scanf("%d", &b_RAD);
	sum_RAD = a_RAD + b_RAD;
	printf("\n\n");
	printf("Sum Of %d And %d = %d\n\n", a_RAD, b_RAD, sum_RAD);
}

int MySubtraction(void) 
{
	
	int a_RAD, b_RAD, subtraction_RAD;
	//code
	printf("\n\n");
	printf("Enter Integer Value For 'A' For Subtraction : ");
	scanf("%d", &a_RAD);
	printf("\n\n");
	printf("Enter Integer Value For 'B' For Subtraction : ");
	scanf("%d", &b_RAD);
	subtraction_RAD = a_RAD - b_RAD;
	return(subtraction_RAD);
}

void MyMultiplication(int a_RAD, int b_RAD) //function definition
{
	int multiplication_RAD;
	//code
	multiplication_RAD = a_RAD * b_RAD;
	printf("\n\n");
	printf("Multiplication Of %d And %d = %d\n\n", a_RAD, b_RAD, multiplication_RAD);
}

int MyDivision(int a_RAD, int b_RAD) //function definition
{

	int division_quotient_RAD;
	//code
	if (a_RAD > b_RAD)
		division_quotient_RAD = a_RAD / b_RAD;
	else
		division_quotient_RAD = b_RAD / a_RAD;
	return(division_quotient_RAD);
}

