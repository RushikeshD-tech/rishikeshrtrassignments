#include <stdio.h>

int main(void)
{
	//code
    printf("\n\n");
    printf("************************************************************");
    printf("\n\n");

    printf("\n\nHello World ...");

	int a_RAD = 13;                                    // assign integer value to 'a'
	printf("\nInteger Decimal Value Of 'a' = %d", a_RAD);                                   
	printf("\nInteger Octal Value Of 'a' = %o", a_RAD);
	printf("\nInteger Hexadecimal Value Of 'a' (Hexadecimal Letters In Lower Case) = %x", a_RAD);
	printf("\n\nInteger Hexadecimal Value Of 'a' (Hexadecimal Letters In Lower Case) = %X", a_RAD);

	char ch_RAD = 'A';                                // assign value as character 'A'
	printf("\nCharacter ch = %c", ch_RAD);
	char str_RAD[] = "AstroMediComp's Real Time Rendering Batch 3.0 (2020-2021)";
	printf("\n\nString str = %s", str_RAD);

	long num_RAD = 30121995L;                         // assign value to long integer
	printf("\n\nLong Integer = %ld", num_RAD);

	unsigned int b_RAD = 7;                           // assign value to unsigned integer
	printf("\n\nUnsigned Integer 'b' = %u", b_RAD);

	float f_num_RAD = 3012.1995f;                     // assign value to float 
	printf("\nFloating Point Number With Just %%f 'f_num' = %f", f_num_RAD);
	printf("\nFloating Point Number With %%4.2f 'f_num' = %4.2f", f_num_RAD);
	printf("\n\nFloating Point Number With %%6.5f 'f_num' = %6.5f", f_num_RAD);

	double d_pi_RAD = 3.14159265358979323846;        // assign value to double
	printf("\nDouble Precision Floating Point Number Without Exponential = %g", d_pi_RAD);
	printf("\nDouble Precision Floating Point Number With Exponential (Lower Case) = %e", d_pi_RAD);
	printf("\n\nDouble Precision Floating Point Number With Exponential (Upper Case) = %E", d_pi_RAD);
	printf("\nDouble Hexadecimal Value Of 'd_pi' (Hexadecimal Letters In Lower Case) = %a", d_pi_RAD);
	printf("\n\nDouble Hexadecimal Value Of 'd_pi' (Hexadecimal Letters In Upper Case) = %A", d_pi_RAD);
    
    printf("******************************************************\n");
    printf("\n\n");
	return(0);
}




