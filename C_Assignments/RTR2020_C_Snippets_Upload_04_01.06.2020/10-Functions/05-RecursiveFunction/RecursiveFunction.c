#include <stdio.h>
int main(int argc, char* argv[], char* envp[])
{
	//variable declaration

	unsigned int num_RAD;

	//function prototype
	void recursive(unsigned int);

	//code 
	printf("\n\n");
	printf("Enter Any Number : \n\n");
	scanf("%u", &num_RAD);

	printf("\n\n");
	printf("Output Of Recursive Function : \n\n");

	recursive(num_RAD);

	printf("\n\n");
	return(0);
}

void recursive(unsigned int n)
{
	//code
	printf("n = %d", n);

	if (n > 0)
	{
		recursive(n - 1);

	}
}