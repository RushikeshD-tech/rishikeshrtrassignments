#include <stdio.h>
int main(void)
{
	//variable declarations
	int i_RAD, j_RAD, c_RAD;
	//code
	printf("\n\n");
	for (i_RAD = 0; i_RAD < 64; i_RAD++)
	{
		for (j_RAD = 0; j_RAD < 64; j_RAD++)
		{
			c_RAD = ((i_RAD & 0x8) == 0) ^ ((j_RAD & 0x8) == 0);
			if (c_RAD == 0)
				printf(" ");
			if (c_RAD == 1)
				printf("* ");
		}
		printf("\n\n");
	}
	return(0);
}