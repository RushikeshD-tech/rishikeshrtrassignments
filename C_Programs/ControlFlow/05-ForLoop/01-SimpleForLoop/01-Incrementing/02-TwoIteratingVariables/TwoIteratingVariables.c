#include <stdio.h>
int main(void)
{
	//variable declarations
	int i_RAD, j_RAD;
	//code
	printf("\n\n");
	printf("Printing Digits 1 to 10 and 10 to 100 : \n\n");
	for (i_RAD = 1, j_RAD = 10; i_RAD <= 10, j_RAD <= 100; i_RAD++, j_RAD = j_RAD + 10)
	{
		printf("\t %d \t %d\n", i_RAD, j_RAD);
	}
	printf("\n\n");
	return(0);
}