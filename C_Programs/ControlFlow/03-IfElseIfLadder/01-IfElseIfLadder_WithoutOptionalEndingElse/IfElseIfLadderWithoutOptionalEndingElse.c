#include<stdio.h>
int main(void)
{
	//variable declarations
	int num_RAD;


	//code
	printf("Enter Value For 'num' : ");
	scanf("%d", &num_RAD);

	//If - Else - If Ladder Begins From Here....
	if (num_RAD < 0)
		printf("Num = %d Is Less Than 0 (NEGATIVE) !!!\n\n ", num_RAD);

	else if ((num_RAD > 0) && (num_RAD <= 100))
		printf("Num = %d Is Between 0 And 100 !!!!\n\n", num_RAD);

	else if ((num_RAD > 100) && (num_RAD <= 200))
		printf("Num = %d Is Between 100 And 200 !!!\n\n", num_RAD);

	else if ((num_RAD > 200) && (num_RAD <= 300))
		printf("Num = %d Is Between 200 And 300 !!!\n\n", num_RAD);

	else if ((num_RAD > 300) && (num_RAD <= 400))
		printf("Num = %d Is Between 300 And 400 !!!\n\n", num_RAD);

	else if ((num_RAD > 400) && (num_RAD <= 500))
		printf("Num = %d Is Between 400 And 500 !!!\n\n", num_RAD);

	else if (num_RAD > 500)
		printf("Num = %d Is Greater Than 500 !!!\n\n", num_RAD);

	return(0);

}




