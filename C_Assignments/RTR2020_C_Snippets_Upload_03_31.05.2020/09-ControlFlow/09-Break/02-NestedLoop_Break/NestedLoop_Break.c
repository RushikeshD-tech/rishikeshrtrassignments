#include <stdio.h>
#include <conio.h>
int main(void)
{
	//variable declarations
	int i_RAD, j_RAD;
	//code
	printf("\n\n");
	for (i_RAD = 1; i_RAD <= 20; i_RAD++)
	{
		for (j_RAD = 1; j_RAD <= 20; j_RAD++)
		{
			if (j_RAD > i_RAD)
			{
				break;
			}
			else
			{
				printf("* ");
			}
		}
		printf("\n");
	}
	printf("\n\n");
	return(0);
}