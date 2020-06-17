#include <stdio.h>
extern int global_count_RAD;
void change_count_one(void)
{
	//code
	global_count_RAD = global_count_RAD + 1;
	printf("change_count_one() : Value Of global_count in File_01 = %d\n", global_count_RAD);
}


