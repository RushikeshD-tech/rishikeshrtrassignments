#include <stdio.h>
int main(void)
{
	//variable declarations
	int i_RAD, j_RAD;
	//code
	printf("\n\n");
	i_RAD = 1;
	while (i_RAD <= 10)
	{
		printf("i = %d\n", i_RAD);
		printf("--------\n\n");
		j_RAD = 1;
		while (j_RAD <= 5)
		{
			printf("\tj = %d\n", j_RAD);
			j_RAD++;
		}
		i_RAD++;
		printf("\n\n");
	}
	return(0);
}
