#include <stdio.h>
int main(void)
{
	//function declarations
	int AddIntegers(int, int);
	int SubtractIntegers(int, int);
	float AddFloats(float, float);
	
	//variable declaration
	typedef int (*AddIntsFnPtr_RAD)(int, int);
	AddIntsFnPtr_RAD ptrAddTwoIntegers_RAD = NULL;
	AddIntsFnPtr_RAD ptrFunc_RAD = NULL;
	typedef float (*AddFloatsFnPtr_RAD)(float, float);
	AddFloatsFnPtr_RAD ptrAddTwoFloats_RAD = NULL;
	int iAnswer_RAD = 0;
	float fAnswer_RAD = 0.0f;
	
	//code
	ptrAddTwoIntegers_RAD = AddIntegers;
	iAnswer_RAD = ptrAddTwoIntegers_RAD(9, 30);
	printf("\n\n");
	printf("Sum Of Integers = %d\n\n", iAnswer_RAD);
	ptrFunc_RAD = SubtractIntegers;
	iAnswer_RAD = ptrFunc_RAD(9, 30);
	printf("\n\n");
	printf("Subtraction Of Integers = %d\n\n", iAnswer_RAD);
	ptrAddTwoFloats_RAD = AddFloats;
	fAnswer_RAD = ptrAddTwoFloats_RAD(11.45f, 8.2f);
	printf("\n\n");
	printf("Sum Of Floating-Point Numbers = %f\n\n", fAnswer_RAD);
	return(0);
}
int AddIntegers(int a_RAD, int b_RAD)
{
	//varibale declarations
	int c_RAD;
	//code
	c_RAD = a_RAD + b_RAD;
	return(c_RAD);
}
int SubtractIntegers(int a_RAD, int b_RAD)
{
	//varibale declarations
	int c_RAD;
	//code
	if (a_RAD > b_RAD)
		c_RAD = a_RAD - b_RAD;
	else
		c_RAD = b_RAD - a_RAD;
	return(c_RAD);
}
float AddFloats(float f_num1_RAD, float f_num2_RAD)
{
	//varibale declarations
	float ans_RAD;
	//code
	ans_RAD = f_num1_RAD + f_num2_RAD;
	return(ans_RAD);
}

