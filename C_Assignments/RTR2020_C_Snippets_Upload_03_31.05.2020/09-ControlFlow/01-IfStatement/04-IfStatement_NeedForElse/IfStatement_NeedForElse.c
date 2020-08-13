#include<stdio.h>
int main(void)
{

	//Variable declarations 
	int age_RAD;


	//code
	printf("\n\n");
	printf("Enter Age : ");
	scanf("%d", &age_RAD);
	if (age_RAD >= 18)
	{
		printf("Yor Are Eligible For voting !!!\n\n",age_RAD);
	
	}
	else
	{
		printf("You Are NOT ELIGIBLE FOR VOTING !!!\n\n");
	
	}
	return(0);
}



