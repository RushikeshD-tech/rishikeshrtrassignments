#include <stdio.h>

int global_count_RAD = 0;
int main(void)
{
	//function prototypes
	void change_count(void);
	void change_count_one(void); 
	void change_count_two(void); 
	//code
	printf("\n");
	change_count();
	change_count_one(); 
	change_count_two(); 
	return(0);
}
void change_count(void)
{
	//code
	global_count_RAD = global_count_RAD + 1;
	printf("Global Count = %d\n", global_count_RAD);
}

