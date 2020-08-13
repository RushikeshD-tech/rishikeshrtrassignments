#include<stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	void MyAddition(void);

	//code
	MyAddition();
	return(0);
}

void MyAddition(void)
{
	int a_RAD, b_RAD, sum_RAD;

	//code
	printf("\n\n");
	printf("Enter Interger Value For 'A' : ");
	scanf("%d", &a_RAD);

	printf("\n\n");
	printf("Enter Integer Value For 'B' : ");
	scanf("%d", &b_RAD);

	sum_RAD = a_RAD + b_RAD;

	printf("\n\n");
	printf("Sum Of %d = %d \n\n", a_RAD, b_RAD, sum_RAD);
}

