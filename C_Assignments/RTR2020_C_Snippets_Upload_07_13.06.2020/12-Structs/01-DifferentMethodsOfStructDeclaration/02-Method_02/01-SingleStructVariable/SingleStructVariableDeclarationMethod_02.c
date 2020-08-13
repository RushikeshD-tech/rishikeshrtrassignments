#include <stdio.h>

struct MyData
{
	int i_RAD;
	float f_RAD;
	double d_RAD;

};
struct MyData data;

int main(void)
{
	//variable declarations
	int i_size_RAD;
	int f_size_RAD;
	int d_size_RAD;
	int struct_MyData_size_RAD;


	//code

	data.i_RAD = 30;
	data.f_RAD = 11.45f;
	data.d_RAD = 1.2995;

	printf("\n\n");
	printf("Data Members Of 'struct MyData' ARE : \n\n");
	printf("i_RAD = %d\n", data.i_RAD);
	printf("f_RAD = %f\n", data.f_RAD);
	printf("d_RAD = %l\n", data.d_RAD);

	i_size_RAD = sizeof(data.i_RAD);
	f_size_RAD = sizeof(data.f_RAD);
	d_size_RAD = sizeof(data.d_RAD);

	printf("\n\n");
	printf("Sizes (in bytes) of the data members of 'struct' MyData Are :\n\n ");
	printf("size of 'i' = bytes\n", i_size_RAD);
	printf("size of 'f' = bytes\n", f_size_RAD);
	printf("size of 'd' = bytes\n", d_size_RAD);

	struct_MyData_size_RAD = sizeof(struct MyData);

	printf("\n\n");

	printf("size of 'struct MyData' : %d bytes\n\n", struct_MyData_size_RAD);

	return(0);

}


