#include <stdio.h>
int main(void)
{
	//variable declarations
	int i_RAD, j_RAD;
	//code
	printf("\n\n");
	printf("Printing Digits 1 to 10 and 10 to 100: \n\n");
	i_RAD = 1;
	j_RAD = 10;
	do
	{
		printf("\t %d \t %d\n", i_RAD, j_RAD);
		i_RAD++;
		j_RAD = j_RAD + 10;
	} while (i_RAD <= 10, j_RAD <= 100);
	printf("\n\n");
	return(0);
}