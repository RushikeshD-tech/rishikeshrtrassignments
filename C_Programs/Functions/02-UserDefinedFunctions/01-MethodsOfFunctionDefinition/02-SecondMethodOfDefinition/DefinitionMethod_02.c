#include <stdio.h>

int main(int argc, char* argv[], char* envp[])
{
	int MyAddition(void);

	//local variable to main()
	int result_RAD;

	//code
	result_RAD = MyAddition();

	printf("\n\n");
	printf("Sum = %d\n\n", result_RAD);
	return(0);
}

int MyAddition(void)
{
	//local variable to MyAddition()
	int a_RAD, b_RAD, sum_RAD;

	//code
	printf("\n\n");
	printf("Enter Integer Value for 'A' :  ");
	scanf("%d", &a_RAD);

	printf("\n\n");
	printf("Enter Integer Value For 'B' : ");
	scanf("%d", &b_RAD);

	sum_RAD = a_RAD + b_RAD;

	return(sum_RAD);
}
