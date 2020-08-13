#include <stdio.h>
// DEFINING STRUCT
struct MyData
{
	int i_RAD;
	float f_RAD;
	double d_RAD;
	char c_RAD;
} data = { 30, 4.5f, 11.451995, 'A' }; //Inline initialization of struct variable 'data' of type 'struct MyData'
int main(void)
{
	//code
	//Displaying Values Of The Data Members Of 'struct MyData'
	printf("\n\n");
	printf("\n\nDATA MEMBERS OF 'struct MyData' ARE : ");
	printf("\ni = %d", data.i_RAD);
	printf("\nf = %f", data.f_RAD);
	printf("\nd = %lf", data.d_RAD);
	printf("\n\nc = %c", data.c_RAD);
	return(0);
}



