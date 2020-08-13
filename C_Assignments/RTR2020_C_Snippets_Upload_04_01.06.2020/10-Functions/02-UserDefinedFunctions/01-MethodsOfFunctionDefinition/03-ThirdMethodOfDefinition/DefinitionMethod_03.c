#include <stdio.h> 

int main(int argc, char* argv[], char* envp[])
{
	
	void MyAddition(int, int);
	
	int a_RAD, b_RAD;
	//code
	printf("\n\n");
	printf("Enter Integer Value For 'A' : ");
	scanf("%d", &a_RAD);
	printf("\n\n");
	printf("Enter Integer Value For 'B' : ");
	scanf("%d", &b_RAD);
	MyAddition(a_RAD, b_RAD); 
	return(0);
}

void MyAddition(int a_RAD, int b_RAD) 
{
	
	int sum_RAD;
	//code
	sum_RAD = a_RAD + b_RAD;
	printf("\n\n");
	printf("Sum Of %d And %d = %d\n\n", a_RAD, b_RAD, sum_RAD);
}




