#include<stdio.h>

//Entry-Point Function => main() =>Valid Return Type (int) and 2 Parameters(int argc, char *argv[])
int main(int argc, char *argv[])
{
	//variable declarations
	int i_RAD;

	//code
	printf("\n\n");
	printf("Hello World!!!\n\n");//Library Function
	printf("Number of Command Line Arguments = %d\n\n", argc);
	printf("Command Line Arguments Passed To This Program Are :\n\n");
	for (i_RAD=0;i_RAD < argc;i_RAD++)
	{
		printf("Command Line Argument Number %d = %s\n", (i_RAD + 1), argv[i_RAD]);


	}
	printf("\n\n");
	return(0);

}