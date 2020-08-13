#include <stdio.h>
void change_count_two(void)
{
	//code
	extern int global_count_RAD;
	global_count_RAD = global_count_RAD + 1;
	printf("change_count_two() : Value Of global_count in File_02 = %d\n", global_count_RAD);
}


