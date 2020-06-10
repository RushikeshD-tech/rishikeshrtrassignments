#include<stdio.h>
int main(void)
{
	//variable declarations
	int a_RAD;

	//code
	printf("\n\n");

	a_RAD = 5;
	if (a_RAD) 
	{
		printf("if-block 1 : 'A' Exists And Has Value = %d !!!!\n\n", a_RAD);

	}
	a_RAD = -5;
	if (a_RAD)
	{
		printf("if-block 2 : 'A' Exists And Has Value = %d !!!\n\n", a_RAD);

	}
	a_RAD = 0;
	if (a_RAD)
	{
		printf("if-block 3 : 'A' Exists And Has Value = %d !!!\n\n", a_RAD);

	}
	printf("All Three if-statements Are Done !!!!\n\n");
	return(0);

}

