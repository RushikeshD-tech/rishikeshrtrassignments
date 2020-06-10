#include<stdio.h>
int main(void)
{
	//variable declarations
	int age_RAD;

	//code
	printf("\n\n");
	printf("Enter Age : ");
	scanf("%d", &age_RAD);
	printf("\n\n");
	if (age_RAD >= 18)
	{
		printf("Entering if-block ....\n\n");
		printf("You Are Eligible For Voting !!!\n\n");
     }
	else
	{
		printf("Entering else-block ...\n\n");
		printf("You Are NOT Eligible For Voting !!!\n\n");

	}
	printf("Bye !!! \n\n");
	return(0);

}



