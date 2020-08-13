#include <stdio.h> 
int main(int argc, char* argv[], char* envp[])
{

	int MyAddition(int, int);

	int a_RAD, b_RAD, result_RAD;
	//code
	printf("\n\n");
	printf("Enter Integer Value For 'A' : ");
	scanf("%d", &a_RAD);
	printf("\n\n");
	printf("Enter -Integer Value For 'B' : ");
	scanf("%d", &b_RAD);
	result_RAD = MyAddition(a_RAD, b_RAD); //function call
	printf("\n\n");
	printf("Sum Of %d And %d = %d\n\n", a_RAD, b_RAD, result_RAD);
	return(0);
}
int MyAddition(int a_RAD, int b_RAD) //function definition
{
	int sum_RAD;
	//code
	sum_RAD = a_RAD + b_RAD;
	return(sum_RAD);
}