#include <stdio.h>
//Defining Struct
struct MyData
{
	int i_RAD;
	float f_RAD;
	double d_RAD;
	char c_RAD;
} data;//Declaring a single struct variable of type 'struct MyData' globally.....

int main(void)
{
	//variable declaration
	int i_size_RAD;
	int f_size_RAD;
	int d_size_RAD;
	int struct_MyData_size_RAD;

	//code
	//Assigning Data Values To Data Members Of 'struct MyData'
	data.i_RAD = 30;
	data.f_RAD = 11.45f;
	data.d_RAD = 1.2995;


	//Displaying Values Of The Data Members of 'struct MyData'
	printf("\n\n");
	printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	printf("i = %d\n", data.i_RAD);
	printf("f = %f\n", data.f_RAD);
	printf("d = %l\n", data.d_RAD);

	//Calculating Size (In Bytes) of The Data Members Of 'struct MyData'
	i_size_RAD = sizeof(data.i_RAD);
	f_size_RAD = sizeof(data.f_RAD);
	d_size_RAD = sizeof(data.d_RAD);


	//Displaying Sizes (In bytes) of The Data Members Of 'struct MyData'
	printf("\n\n");
	printf("SIZES (in bytes) of DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	printf("size of 'i' = %d bytes\n", i_size_RAD);
	printf("size of 'f' = %d bytes\n", f_size_RAD);
	printf("size of 'd' = %d bytes\n", d_size_RAD);

	//Calculating Size (In Bytes) Of the entire struct MyData'
	struct_MyData_size_RAD = sizeof(struct MyData);

	printf("\n\n");
	printf("Size of 'struct MyData' : %d bytes\n\n", struct_MyData_size_RAD);
	return(0);
}

