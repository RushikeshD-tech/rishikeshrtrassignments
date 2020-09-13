#include <stdio.h>
#include <stdarg.h>
#define NUM_TO_BE_FOUND 3
#define NUM_ELEMENTS 10
int main(void)
{
	// function prototypes
	void FindNumber(int, int, ...);
	// code
	printf("\n\n");
	FindNumber(NUM_TO_BE_FOUND, NUM_ELEMENTS, 3, 5, 9, 2, 3, 6, 9, 3, 1, 3);
	return(0);
}
void FindNumber(int num_to_be_found_RAD, int num_RAD, ...) 
{
	// variable declarations
	int count_RAD = 0;
	int n_RAD;
	va_list numbers_list_RAD;
	// code
	va_start(numbers_list_RAD, num_RAD);
	while (num_RAD)
	{
		n_RAD = va_arg(numbers_list_RAD, int);
		if (n_RAD == num_to_be_found_RAD)
			count_RAD++;
		num_RAD--;
	}
	if (count_RAD == 0)
		printf("Number %d Could Not Be Found !!!\n\n", num_to_be_found_RAD);
	else
		printf("Number %d Found %d Times !!!\n\n", num_to_be_found_RAD, count_RAD);
	va_end(numbers_list_RAD);
}
