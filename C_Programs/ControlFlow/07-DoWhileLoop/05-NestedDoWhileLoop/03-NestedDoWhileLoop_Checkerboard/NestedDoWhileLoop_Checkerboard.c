#include <stdio.h>
int main(void)
{
	//variable declarations
	int i_RAD, j_RAD, c_RAD;
	//code
	printf("\n\n");
	i_RAD = 0;
	do
	{
		j_RAD = 0;
		do
		{
			c_RAD = ((i_RAD & 0x8) == 0) ^ ((j_RAD & 0x8) == 0);
			if (c_RAD == 0)
				printf(" ");
			if (c_RAD == 1)
				printf("* ");
			j_RAD++;
		} while (j_RAD < 64);
		printf("\n\n");
		i_RAD++;
	} while (i_RAD < 64);
	return(0);
}