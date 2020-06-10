#include<stdio.h>
int main(void)
{
	 //variable declarations
	int age_RAD;

	//code
	printf("\n\n");
	printf("Enter Age: ");
	scanf("%d", &age_RAD);
	if (age_RAD >= 18)
	{
		printf("You Are Eligible For Voting !!!\n\n");

	}
	return(0);
}
