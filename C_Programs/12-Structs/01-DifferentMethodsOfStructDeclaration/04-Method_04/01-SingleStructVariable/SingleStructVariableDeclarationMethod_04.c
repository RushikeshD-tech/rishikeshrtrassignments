#include <stdio.h>
// DEFINING STRUCT
struct MyData
{
	int i_RAD;
	float f_RAD;
	double d_RAD;
};
int main(void)
{
	//variable declarations
	struct MyData data; //declaring a single struct variable of type 'struct' MyData locally...
	int i_RAD_size;
	int f_RAD_size;
	int d_RAD_size;
	int struct_MyData_RAD_size;
	
	//code
	//Assigning Data Values To The Data Members Of 'struct MyData'
	data.i_RAD = 30;
	data.f_RAD = 11.45f;
	data.d_RAD = 1.2995;
	//Displaying Values Of The Data Members Of 'struct MyData'
	printf("\n\n");
	printf("\n\nDATA MEMBERS OF 'struct MyData' ARE : ");
	printf("\ni = %d", data.i_RAD);
	printf("\nf = %f", data.f_RAD);
	printf("\nd = %lf", data.d_RAD);
	
	//Calculating Sizes (In Bytes) Of The Data Members Of 'struct MyData'
	i_RAD_size = sizeof(data.i_RAD);
	f_RAD_size = sizeof(data.f_RAD);
	d_RAD_size = sizeof(data.d_RAD);
	
	//Displaying Sizes (In Bytes) Of The Data Members Of 'struct MyData'
	printf("\n\n");
	printf("\n\nSIZES (in bytes) OF DATA MEMBERS OF 'struct MyData' ARE : ");
	printf("\nSize of 'i' = %d bytes", i_RAD_size);
	printf("\nSize of 'f' = %d bytes", f_RAD_size);
	printf("\nSize of 'd' = %d bytes", d_RAD_size);
	
	//Calculating Size (In Bytes) Of the entire 'struct Mydata'
	struct_MyData_RAD_size = sizeof(struct MyData); //can also give struct name ->sizeof(MyData)
		
	//Displaying Sizes (In Bytes) Of the entire 'struct Mydata'
		
	printf("\n\n");
	printf("\n\nSize of 'struct MyData' : %d bytes", struct_MyData_RAD_size);
	return(0);
}

