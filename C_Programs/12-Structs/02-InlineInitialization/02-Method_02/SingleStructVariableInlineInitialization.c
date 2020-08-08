#include <stdio.h>
// DEFINING STRUCT
struct MyData
{
	int i_RAD;
	float f_RAD;
	double d_RAD;
	char c_RAD;
};
struct MyData data = { 9, 8.2f, 9.61998, 'P' };
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