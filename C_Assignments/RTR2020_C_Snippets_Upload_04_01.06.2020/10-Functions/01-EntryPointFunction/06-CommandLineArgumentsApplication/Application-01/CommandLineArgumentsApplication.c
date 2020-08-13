#include<stdio.h>
#include<ctype.h>
#include <stdlib.h> 
int main(int argc, char* argv[], char* envp[])
{
	//variable declarations
	int i_RAD;
	int num_RAD;
	int sum_RAD = 0;
	//code
	if (argc == 1)
	{
		printf("\n\n");
		printf("No Numbers Given For Addition !!! Exitting now ...\n\n");
		printf("Usage : CommandLineArgumentsApplication <first number> <second number > ...\n\n");
			exit(0);
	}
	
	
		
		printf("\n\n");
	printf("Sum Of All Integer Command Line Arguments Is : \n\n");
	for (i_RAD = 1; i_RAD < argc; i_RAD++) 
		
	{
		num_RAD = atoi(argv[i_RAD]);
		sum_RAD = sum_RAD + num_RAD;
	}
	printf("Sum = %d\n\n", sum_RAD);
	return(0);
}