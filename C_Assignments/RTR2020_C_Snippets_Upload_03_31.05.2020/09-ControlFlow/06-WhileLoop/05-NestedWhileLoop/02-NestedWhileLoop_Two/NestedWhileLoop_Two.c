#include <stdio.h>
int main(void)
{
	//variable declarations
	int i_RAD, j_RAD, k_RAD;
	//code
	printf("\n\n");
	i_RAD= 1;
	while (i_RAD <= 10)
	{
		printf("i = %d\n", i_RAD);
		printf("--------\n\n");
		j_RAD = 1;
		while (j_RAD <= 5)
		{
			printf("\tj = %d\n", j_RAD);
			printf("\t--------\n\n");
			k_RAD = 1;
			while (k_RAD <= 3)
			{
				printf("\t\tk = %d\n", k_RAD);
				k_RAD++;
			}
			printf("\n\n");
			j_RAD++;
		}
		printf("\n\n");
		i_RAD++;
	}
	return(0);
}