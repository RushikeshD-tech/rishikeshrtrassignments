#include <stdio.h>
int main(void)
{
	//DEFINING STRUCT
	struct MyData
	{
		int i_RAD;
		float f_RAD;
		double d_RAD;
		char c_RAD;
	} data = { 5, 9.1f, 3.78623, 'N' };
	//Displaying Values Of The Data Members Of 'struct MyData'
	printf("\n\n");
	printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	printf("\ni = %d", data.i_RAD);
	printf("\nf = %f", data.f_RAD);
	printf("\nd = %lf", data.d_RAD);
	printf("\n\nc = %c", data.c_RAD);
	return(0);
}