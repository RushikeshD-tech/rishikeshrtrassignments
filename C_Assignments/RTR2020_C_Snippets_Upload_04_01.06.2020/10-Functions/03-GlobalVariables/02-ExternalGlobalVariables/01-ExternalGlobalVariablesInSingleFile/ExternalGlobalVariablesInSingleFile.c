#include <stdio.h>

int main(void)
{
	//function prototypes
	void change_count(void);
	//variable declarations
	extern int global_count_RAD;
	//code
	printf("\n");
	printf("Value Of global_count before change_count() = %d\n", global_count_RAD);
	change_count();
	printf("Value Of global_count after change_count() = %d\n", global_count_RAD);
	printf("\n");
	return(0);
}

int global_count_RAD = 0;
void change_count(void)
{
	//code
	global_count_RAD = 5;
	printf("Value Of global counting change_count() = %d\n", global_count_RAD);
}


