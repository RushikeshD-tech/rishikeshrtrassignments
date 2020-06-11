#include <stdio.h>
int main(void)
{
	//variable declarations
	int i_RAD, j_RAD;
	//code
	printf("\n\n");
	i_RAD = 1;
	do
	{
		printf("i = %d\n", i_RAD);
		printf("--------\n\n");
		j_RAD = 1;
		do
		{
			printf("\tj = %d\n", j_RAD);
			j_RAD++;
		} while (j_RAD <= 5);
		i_RAD++;
		printf("\n\n");
	} while (i_RAD <= 10);
	return(0);
}