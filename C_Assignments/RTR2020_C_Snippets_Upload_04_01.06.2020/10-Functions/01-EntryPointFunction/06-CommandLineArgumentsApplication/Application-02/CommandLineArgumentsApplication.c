#include <stdio.h> 
#include <stdlib.h> 
int main(int argc, char* argv[], char* envp[])
{
	//variable declarations
	int i_RAD;
	//code
	if (argc != 4)

	{
		printf("\n\n");
		printf("Invalid Usage !!! Exitting Now ... \n\n");
		printf("Usage : CommandLineArgumentsApplication <first name> <middle name> < surname > \n\n");
		exit(0);
	}


	printf("\n\n");
	printf("Your Full Name Is : ");
	for (i_RAD = 1; i_RAD < argc; i_RAD++)


	{
		printf("%s ", argv[i_RAD]);
	}
	printf("\n\n");
	return(0);
}
