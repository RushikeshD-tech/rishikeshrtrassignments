#include<stdio.h>
int main(void)
{
	 //variable declarations
	int num_RAD;

	//code
	printf("Enter Value For 'num' : ");
	scanf("%d", &num_RAD);

	if (num_RAD < 0)
	{
		printf("Num = %d Is Less Than 0 (NEGATIVE).\n\n", num_RAD);

	}
	if ((num_RAD > 0) && (num_RAD <= 100))
	{
		printf("Num = %d Is Betwwn 0 And 100.\n\n", num_RAD);

	}
	if ((num_RAD > 100) && (num_RAD <= 200))
	{
		printf("Num = %d Is Betwwn 100 And 200.\n\n", num_RAD);

	}
	if ((num_RAD > 200) && (num_RAD <= 300))
	{
		printf("Num = %d Is Betwwn 200 And 300.\n\n", num_RAD);


	}
	if ((num_RAD > 400) && (num_RAD <= 500))
	{
		printf("Num = %d Is Greater Than 500.\n\n", num_RAD);

	}
	if (num_RAD > 500)
	{
		printf("Num = %d Is Greater Than 500.\n\n", num_RAD);

     }
	return(0);

}