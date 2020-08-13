#include <stdio.h>
int main(void)
{
	//variable declarations
	float f_RAD;
	float f_num_RAD = 1.7f; 
	
		//code
		printf("\n\n");
	printf("Printing Numbers %f to %f : \n\n", f_num_RAD, (f_num_RAD * 10.0f));
	for (f_RAD = f_num_RAD; f_RAD <= (f_num_RAD * 10.0f); f_RAD = f_RAD + f_num_RAD)
	{
		printf("\t%f\n", f_RAD);
	}
	printf("\n\n");
	return(0);
}