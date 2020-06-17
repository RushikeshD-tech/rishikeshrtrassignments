#include <stdio.h>

	int global_count_RAD = 0;
int main(void)
{
	//function prototypes
	void change_count_one(void);
	void change_count_two(void);
	void change_count_three(void);
	//code
	printf("\n");
	printf("main() : Value of global_count = %d\n", global_count_RAD);
	change_count_one();
	change_count_two();
	change_count_three();
	printf("\n");
	return(0);
}

void change_count_one(void)
{
	//code
	global_count_RAD = 100;
	printf("change_count_one() : Value of global_count = %d\n", global_count_RAD);
}

void change_count_two(void)
{
	//code
	global_count_RAD = global_count_RAD + 1;
	printf("change_count_two() : Value of global_count = %d\n", global_count_RAD);
}
void change_count_three(void)
{
	//code
	global_count_RAD = global_count_RAD + 10;
	printf("change_count_three() : Value of global_count = %d\n", global_count_RAD);
}
