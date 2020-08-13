#include<stdio.h>

struct MyStruct
{
	int i_RAD;
	float f_RAD;
	double d_RAD;
	char c_RAD;

};
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
	struct MyStruct s_RAD;
	union MyUnion u_RAD;

	//code
	printf("\n\n");
	printf("Members of Struct Are : \n\n");

	s_RAD.i_RAD = 9;
	s_RAD.f_RAD = 8.7f;
	s_RAD.d_RAD = 1.233422;
	s_RAD.c_RAD = 'P';

	printf("s_RAD.i_RAD = %d\n\n", s_RAD.i_RAD);
	printf("s_RAD.f_RAD = %f\n\n", s_RAD.f_RAD);
	printf("s_RAD.d_RAD = %lf\n\n", s_RAD.d_RAD);
	printf("s_RAD.c_RAD = %c\n\n", s_RAD.c_RAD);

	printf("Addressess Of Members Of Struct Are : \n\n");
	printf("s_RAD.i_RAD = %p\n\n", &s_RAD.i_RAD);
	printf("s_RAD.f_RAD = %p\n\n", &s_RAD.f_RAD);
	printf("s_RAD.d_RAD = %p\n\n", &s_RAD.d_RAD);
	printf("s_RAD.c_RAD = %p\n\n", &s_RAD.c_RAD);

	printf("MyStruct s = %p\n\n", &s_RAD);

	printf("\n\n");
	printf("Members Of Union Are : \n\n");

	u_RAD.i_RAD = 3;
	printf("u_RAD.i_RAD = %d\n\n", u_RAD.i_RAD);

	u_RAD.f_RAD = 4.5f;
	printf("u_RAD.f_RAD = %f\n\n", u_RAD.f_RAD);

	u_RAD.d_RAD = 5.12764;
	printf("u_RAD.c_RAD = %lf\n\n", u_RAD.d_RAD);

	u_RAD.c_RAD = 'A';
	printf("Addressses Of Members of Union Are : \n\n");
	printf("u_RAD.i_RAD = %p\n\n", &u_RAD.i_RAD);
	printf("u_RAD.f_RAD = %p\n\n", &u_RAD.f_RAD);
	printf("u_RAD.d_RAD = %p\n\n", &u_RAD.d_RAD);
	printf("u_RAD.c_RAD = %p\n\n", &u_RAD.c_RAD);

	printf("MyUnion u = %p\n\n", &u_RAD);
	return(0);

}









