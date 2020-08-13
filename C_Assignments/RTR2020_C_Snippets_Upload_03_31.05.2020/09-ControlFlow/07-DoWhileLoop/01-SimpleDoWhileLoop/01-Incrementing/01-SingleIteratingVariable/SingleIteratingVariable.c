#include <stdio.h>
int main(void)
{
	//variable declarations
	int i_RAD;
	//code
	printf("\n\n");
	printf("Printing Digits 1 to 10 : \n\n");
	i_RAD = 1;
	do
	{
		printf("\t%d\n", i_RAD);
		i_RAD++;
	} while (i_RAD <= 10);
	printf("\n\n");
	return(0);
}