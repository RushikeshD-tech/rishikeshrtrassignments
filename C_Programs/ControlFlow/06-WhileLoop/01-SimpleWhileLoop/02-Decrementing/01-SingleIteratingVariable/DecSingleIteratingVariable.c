#include <stdio.h>
int main(void)
{
	//variable declarations
	int i_RAD;
	//code
	printf("\n\n");
	printf("Printing Digits 10 to 1 : \n\n");
	i_RAD = 10;
	while (i_RAD >= 1)
	{
		printf("\t%d\n", i_RAD);
		i_RAD--;
	}
	printf("\n\n");
	return(0);
}