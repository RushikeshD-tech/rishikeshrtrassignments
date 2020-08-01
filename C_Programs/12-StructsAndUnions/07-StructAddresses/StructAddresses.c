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
	//variable declarations
	struct MyData data;

	//code
	//Assigning Data Values To The Data Members Of 'Struct Mydata'
	data.i_RAD = 30;
	data.f_RAD = 11.45f;
	data.d_RAD = 1.2995;
	data.c_RAD = 'A';

	//Displaying Values Of The Data  Members Of 'Struct MyData'
	printf("\n\n");
	printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	printf("i = %d\n", data.i_RAD);
	printf("f = %f\n", data.f_RAD);
	printf("d = %lf\n", data.d_RAD);
	printf("c = %c\n", data.c_RAD);

	printf("\n\n");
	printf("ADDRESSES OF DATA MEMBERS OF 'struct MyData' ARE: \n\n");
	printf("'i' Occupies Addresses From %p\n", &data.i_RAD);
	printf("'f' Occupies Addresses From %p\n", &data.f_RAD);
	printf("'d' Occupies Addresses From %p\n", &data.d_RAD);
	printf("'c' Occupies Address %p\n\n", &data.c_RAD);

	printf("Starting Address Of 'Struct MyData' variable 'data' = %p\n\n", &data);

	return(0);

}
