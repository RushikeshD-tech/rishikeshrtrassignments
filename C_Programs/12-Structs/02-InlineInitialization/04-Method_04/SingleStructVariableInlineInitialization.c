#include<stdio.h>

struct MyData
{
	int i_RAD;
	float f_RAD;
	double d_RAD;
	char c_RAD;

};
int main(void)
{
	struct MyData data_one = { 35,3.9f,1.23765,'A' };

	struct MyData data_two = { 'P',6.2f, 12.199523, 68 };

	struct MyData data_three = { 36, 'G' };

	struct MyData data_four = { 79 };

	printf("\n\n");
	printf("DATA MEMBERS OF 'struct MyData data_one' ARE : \n\n");
	printf("i = %d\n", data_one.i_RAD);
	printf("f = %f\n", data_one.f_RAD);
	printf("d = %lf\n", data_one.d_RAD);
	printf("c = %c\n", data_one.c_RAD);
	printf("\n\n");
	printf("DATA MEMBERS OF 'struct MyData data_two' ARE : \n\n");
	printf("i = %d\n", data_two.i_RAD);
	printf("f = %f\n", data_two.f_RAD);
	printf("d = %lf\n", data_two.d_RAD);
	printf("c = %c\n", data_two.c_RAD);
	printf("\n\n");
	printf("DATA MEMBERS OF 'struct MyData data_three' ARE : \n\n");
	printf("i = %d\n", data_three.i_RAD);
	printf("f = %f\n", data_three.f_RAD);
	printf("d = %lf\n", data_three.d_RAD);
	printf("c = %c\n", data_three.c_RAD);
	printf("\n\n");
	printf("DATA MEMBERS OF 'struct MyData data_four' ARE : \n\n");
	printf("i = %d\n", data_four.i_RAD);
	printf("f = %f\n", data_four.f_RAD);
	printf("d = %lf\n", data_four.d_RAD);
	printf("c = %c\n", data_four.c_RAD);

	return(0);
}

