#include <stdio.h>
#include <stdarg.h>
int main(void)
{
	// function prototypes
	int CalculateSum(int, ...);
	
	// variable declarations
	int answer_RAD;
	// code
	printf("\n\n");
	answer_RAD = CalculateSum(5, 10, 20, 30, 40, 50);
	printf("Answer = %d\n\n", answer_RAD);
	answer_RAD = CalculateSum(10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
	printf("Answer = %d\n\n", answer_RAD);
	answer_RAD = CalculateSum(0);
	printf("Answer = %d\n\n", answer_RAD);
	return(0);
}
int CalculateSum(int num_RAD, ...) 
{
	// function prototype
	int va_CalculateSum(int, va_list);
	// variable declarations
	int sum_RAD = 0;
	va_list numbers_list_RAD;
	// code
	va_start(numbers_list_RAD, num_RAD);
	sum_RAD = va_CalculateSum(num_RAD, numbers_list_RAD);
	va_end(numbers_list_RAD);
	return(sum_RAD);
}
int va_CalculateSum(int num_RAD, va_list list_RAD)
{
	// variable declaration
	int n_RAD;
	int sum_total_RAD = 0;
	// code
	while (num_RAD)
	{
		n_RAD = va_arg(list_RAD, int);
		sum_total_RAD = sum_total_RAD + n_RAD;
		num_RAD--;
	}
	return(sum_total_RAD);
}




