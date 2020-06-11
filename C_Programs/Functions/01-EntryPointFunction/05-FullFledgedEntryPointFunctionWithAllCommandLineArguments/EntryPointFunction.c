#include<stdio.h>

//Entry-Point Function =>main() => Valid Return Type (int) and 3 Parameters (int argc,char *argv[], char *envp[])
int main(int argc, char* argv[], char* envp[])
{
	//variable declarations
	int i_RAD;

	//code 
	printf("\n\n");
	printf("Hello World!!!\n\n");//Library function
	printf("Number Of Command Line Arguments = %d\n\n", argc);
	printf("Command Line Arguments Passed To This Program Are :\n\n");
	for (i_RAD = 0; i_RAD < argc; i_RAD++)
	{
		printf("Command Line Argument Number %d = %s\n", (i_RAD + 1), argv[i_RAD]);

	}
	printf("\n\n");
	printf("First 20 Environmental Variables Passed To This Program Are : \n\n");
	for (i_RAD = 0; i_RAD < 20; i_RAD++)
	{
		printf("Environmental Variable Number %d = %s\n", (i_RAD + 1), envp[i_RAD]);

	
	}
	printf("\n\n");
	return(0);

}