#include <stdio.h>
#include <conio.h>
struct MyData
{
	int i_RAD;
	float f_RAD;
	double d_RAD;
	char ch_RAD;
};
int main(void)
{
	//variable declarations
	struct MyData data; //declaring a single struct variable
	//code
	//User Input For Values Of Data Members Of 'struct MyData'
	printf("\n\n");
	printf("\nEnter Integer Value For Data Member 'i' Of 'struct MyData' : ");
	scanf("%d", &data.i_RAD);
	printf("\nEnter Floating-Point Value For Data Member 'f' Of 'struct MyData' : ");
		scanf("%f", &data.f_RAD);
	printf("\nEnter 'Double' Value For Data Member 'd' Of 'struct MyData' : ");
	scanf("%lf", &data.d_RAD);
	printf("\nEnter Character Value For Data Member 'c' Of 'struct MyData' : ");
	data.ch_RAD = getch();
	//Display Values Of Data Members Of 'struct MyData'
	printf("\n\n");
	printf("\n\nDATA MEMBERS OF 'struct MyData' ARE : ");
	printf("\ni = %d", data.i_RAD);
	printf("\nf = %f", data.f_RAD);
	printf("\nd = %lf", data.d_RAD);
	printf("\n\nc = %c", data.ch_RAD);
	return(0);
}


