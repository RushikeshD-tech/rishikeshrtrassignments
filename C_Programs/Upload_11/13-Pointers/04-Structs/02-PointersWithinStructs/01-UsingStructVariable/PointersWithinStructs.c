#include <stdio.h>

// DEFINING STRUCT
struct MyData
{
	int* ptr_i_RAD;
	int i_RAD;
	float* ptr_f_RAD;
	float f_RAD;
	double* ptr_d_RAD;
	double d_RAD;
};
int main(void)
{
	//variable declarations
	struct MyData data;
	
	//code
	data.i_RAD = 9;
	data.ptr_i_RAD = &data.i_RAD;
	data.f_RAD = 11.45f;
	data.ptr_f_RAD = &data.f_RAD;
	data.d_RAD = 30.121995;
	data.ptr_d_RAD = &data.d_RAD;
	printf("\n\n");
	printf("i = %d\n", *(data.ptr_i_RAD));
	printf("Adress Of 'i' = %p\n", data.ptr_i_RAD);
	printf("\n\n");
	printf("f = %f\n", *(data.ptr_f_RAD));
	printf("Adress Of 'f' = %p\n", data.ptr_f_RAD);
	printf("\n\n");
	printf("d = %lf\n", *(data.ptr_d_RAD));
	printf("Adress Of 'd' = %p\n", data.ptr_d_RAD);
	return(0);
}



