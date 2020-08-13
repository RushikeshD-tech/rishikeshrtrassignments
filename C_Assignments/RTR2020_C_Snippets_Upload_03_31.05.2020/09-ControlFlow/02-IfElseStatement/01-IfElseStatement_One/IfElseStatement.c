#include<stdio.h>
int main(void)
{
	 //variable declarations
	int a_RAD, b_RAD, p_RAD;


	//code
	a_RAD = 9;
	b_RAD = 30;
	p_RAD = 30;

	//**** First if-else PAIR***
	printf("\n\n");
	if (a_RAD < b_RAD)
	{
		printf("Entering First if-block...\n\n");
		printf("A Is Less Than B !!!\n\n");
	}
	else
	{
		printf("Entering First else-block ....\n\n");
		printf("A Is NOT less Than B !!!!\n\n");

	}
	printf("First if-else pair Done !!!\n\n");

	//***SECOND if-else PAIR****
	printf("\n\n");
	if (b_RAD != p_RAD)
	{
		printf("Entering Second if-block ....\n\n");
		printf(" Is Equal To p !!!\n\n");
	}
	else
	{
		printf("Entering Second if-block .....\n\n");
		printf("B Is NOT Equal To p !!!!\n\n");
    }
	printf("Second if-else Pair Done !!!\n\n");

	return(0);
}



