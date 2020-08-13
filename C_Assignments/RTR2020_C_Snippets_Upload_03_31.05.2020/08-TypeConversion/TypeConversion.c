#include<stdio.h>

int main(void)
{
	//variable declarations
	int i_RAD, j_RAD;
	char ch_RAD_01, ch_RAD_02;

	int a_RAD, result_int_RAD;
	float f_RAD, result_float_RAD;

	int i_explicit_RAD;
	float f_explicit_RAD;

	//code
	printf("\n\n");

	//INTERCONVERSION AND IMPLICITE TYPE-CASTING BETWEEN 'char' AND 'int' TYPES....
	i_RAD = 70;
	ch_RAD_01 = i_RAD;
	printf("Character 1 (after ch_RAD_01 = i_RAD) = %C\n\n", ch_RAD_01);

	ch_RAD_02 = 'Q';
	j_RAD = ch_RAD_02;
	printf("Character 2 = %c\n", ch_RAD_02);
	printf("J (after j = ch_RAD_02) = %d\n\n", j_RAD);

	//IMPLICIT CONVERSION OF 'int' TQ 'float'....
	a_RAD = 5;
	f_RAD = 7.8f;
	result_float_RAD = a_RAD + f_RAD;
	printf("Integer a = %d And Floating-Point Number %f Added Gives Floating-Point Sum = %f\n\n", a_RAD, f_RAD, result_float_RAD);

	result_int_RAD = a_RAD + f_RAD;
	printf("Integer a= %d And Floating-Point Number %f Added Gives Floating-Point Sum = %d\n\n", a_RAD, f_RAD, result_int_RAD);

	//EXPLICIT TYPE CASTING USING CAST OPERATOR.......
	f_explicit_RAD = 30.121995f;
	i_explicit_RAD = (int)f_explicit_RAD;
	printf("Floating Point Number Which will Be Type Casted Explicitly = %f\n", f_explicit_RAD);
	printf("Resultant Integer Afetr Explicit Type Casting Of %f = %d\n\n", f_explicit_RAD, i_explicit_RAD);

	return(0);
}
