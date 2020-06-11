#include <stdio.h>
int main(void)
{
	//variable declarations
	int i_RAD;
	//code
	printf("\n\n");
	printf("Printing Even Numbers From 0 to 100: \n\n");
	for (i_RAD = 0; i_RAD <= 100; i_RAD++)
	{
		
		
			
			if (i_RAD % 2 != 0)
			{
				continue;
			}
			else
			{
				printf("\t%d\n", i_RAD);
			}
	}
	printf("\n\n");
	return(0);
}