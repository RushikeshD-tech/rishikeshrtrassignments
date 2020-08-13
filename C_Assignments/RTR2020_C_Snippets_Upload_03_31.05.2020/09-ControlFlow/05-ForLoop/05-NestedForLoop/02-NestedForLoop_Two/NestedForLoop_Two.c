#include <stdio.h>
int main(void)
{
	//variable declarations
	int i_RAD, j_RAD, k_RAD;
	//code
	printf("\n\n");
	for (i_RAD = 1; i_RAD <= 10; i_RAD++)
	{
		printf("i = %d\n", i_RAD);
		printf("--------\n\n");
		for (j_RAD = 1; j_RAD <= 5; j_RAD++)
		{
			printf("\tj = %d\n", j_RAD);
			printf("\t--------\n\n");
			for (k_RAD = 1; k_RAD <= 3; k_RAD++)
			{
				printf("\t\tk = %d\n", k_RAD);
			}
			printf("\n\n");
		}
		printf("\n\n");
	}
	return(0);
}
