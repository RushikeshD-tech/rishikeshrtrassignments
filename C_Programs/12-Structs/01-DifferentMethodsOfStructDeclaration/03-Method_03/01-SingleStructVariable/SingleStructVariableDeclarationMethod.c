#include <stdio.h>
int main(void)
{
	//defining struct
	struct MyData
	{
		int i_RAD;
		float f_RAD;
		double d_RAD;

	}data;//Declaring a single struct variable of type 'struct MyData' locally....

	//variable declarations
	int i_size_RAD;
	int f_size_RAD;
	int d_size_RAD;
	int struct_MyData_size;

	//code
	//Assigning Data Values To the Data Members Of 'struct MyData'
	data.i_RAD = 30;
	data.f_RAD = 11.45f;
	data.d_RAD = 1.2995;

	//Displaying Values To Data Members Of 'struct MyData'
	printf("\n\n");
	printf("\n\n DATA MEMBERS OF 'struct MyData' ARE :   ");
	printf("\ni_RAD = %d", data.i_RAD);
	printf("\nf_RAD = %f", data.f_RAD);
	printf("\nd_RAD = %lf", data.d_RAD);

	//calculating Sizes (In Bytes ) Of The Data Members Of 'struct MyData'
	i_size_RAD = sizeof(data.i_RAD);
	f_size_RAD = sizeof(data.f_RAD);
	d_size_RAD = sizeof(data.d_RAD);

	//Displaying Sizes (In Bytes) Of The Data Members Of 'struct MyData'
	printf("\n\n");
	printf("\n\n SIZES (in bytes) OF DATA MEMBERS OF 'struct MyData' ARE :  ");
	printf("\nSize of 'i' = %d bytes", i_size_RAD);
	printf("\nsize of 'f' = %d bytes", f_size_RAD);
	printf("\nsize of 'd' = %d bytes", d_size_RAD);

	//Calculating Size (In bytes) Of the entire 'struct MyData'
	struct_MyData_size = sizeof(struct MyData);

	//Displaying Sizes (In Bytes ) Of the entire  'struct MyData'
	printf("\n\n");
	printf("\n\nSize Of 'Struct MyData' : %d bytes \n\n", struct_MyData_size);
	return(0);
}
