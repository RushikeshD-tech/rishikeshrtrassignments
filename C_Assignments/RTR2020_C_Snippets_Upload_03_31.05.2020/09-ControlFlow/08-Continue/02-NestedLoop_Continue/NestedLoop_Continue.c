#include <stdio.h>
int main(void)
{
	//variable declarations
	int i_RAD, j_RAD;
	//code
	printf("\n\n");
	printf("Outer Loop Prints Odd Numbers Between 1 and 10. \n\n");
	printf("Inner Loop Prints Even Numbers Between 1 and 10 For Every Odd Number Printed By Outer Loop. \n\n");


	for (i_RAD = 1; i_RAD <= 10; i_RAD++)
	{
		if (i_RAD % 2 != 0) 
		{
			printf("i = %d\n", i_RAD);
			printf("---------\n");
			for (j_RAD = 1; j_RAD <= 10; j_RAD++)
			{
				if (j_RAD % 2 == 0)
				{
					printf("\tj = %d\n", j_RAD);
				}
				else
				{
					continue;
				}
			}
			printf("\n\n");
		}
		else
		{
			continue;
		}
	}
	printf("\n\n");
	return(0);
}

