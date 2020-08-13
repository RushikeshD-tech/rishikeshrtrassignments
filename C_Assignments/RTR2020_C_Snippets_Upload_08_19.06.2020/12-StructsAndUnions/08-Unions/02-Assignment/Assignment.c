#include <stdio.h>

union MyUnion
{
	int i_RAD;
	float f_RAD;
	double d_RAD;
	char c_RAD;

};
int main(void)
{
	//variable declarations
	union MyUnion u1_RAD, u2_RAD;

	//code
	//***MyUnion u2 ***
	printf("\n\n");
	printf("Members Of Union u1 Are : \n\n");

	u1_RAD.i_RAD = 6;
	u1_RAD.f_RAD = 1.2f;
	u1_RAD.d_RAD = 8.333333;
	u1_RAD.c_RAD = 'S';

	printf("u1.i = %d\n\n", u1_RAD.i_RAD);
	printf("u1.f = %f\n\n", u1_RAD.f_RAD);
	printf("u1.d = %lf\n\n", u1_RAD.d_RAD);
	printf("u1.c = %c\n\n", u1_RAD.c_RAD);

	printf("Addresss Of Members Of Union u1 Are :\n\n");
	printf("u1.i = %p\n\n", &u1_RAD.i_RAD);
	printf("u1.f = %p\n\n", &u1_RAD.f_RAD);
	printf("u1.d = %p\n\n", &u1_RAD.d_RAD);
	printf("u1.c = %p\n\n", &u1_RAD.c_RAD);

	printf("MyUnion u1 = %p\n\n", &u1_RAD);

	//***MyUnion u2 ***
	printf("\n\n");
	printf("Members Of Union u2 Are : \n\n");

	u2_RAD.i_RAD = 3;
	printf("u2.i = %d\n\n", u2_RAD.i_RAD);

	u2_RAD.f_RAD = 4.5f;
	printf("u2.f = %f\n\n", u2_RAD.f_RAD);

	u2_RAD.d_RAD = 5.12764;
	printf("u2.d = %lf\n\n", u2_RAD.d_RAD);

	u2_RAD.c_RAD = 'A';
	printf("u2.c = %c\n\n", u2_RAD.c_RAD);

	printf("Addressess Of Members Of Union u2 Are : \n\n");

	printf("u2.i = %p\n\n", &u2_RAD.i_RAD);
	printf("u2.f = %p\n\n", &u2_RAD.f_RAD);
	printf("u2.d = %p\n\n", &u2_RAD.d_RAD);
	printf("u2.c = %p\n\n", &u2_RAD.c_RAD);

	printf("MyUnion u2 = %p\n\n", &u2_RAD);

	return(0);
}




