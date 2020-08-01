#include <stdio.h>

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
	printf("Size of MyStruct = %lu\n", sizeof(s_RAD));
	printf("\n\n");
	printf("Size Of MyUnion = %lu\n", sizeof(u_RAD));
	return(0);

}

