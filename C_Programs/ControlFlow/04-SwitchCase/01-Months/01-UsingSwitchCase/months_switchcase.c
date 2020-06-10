#include<stdio.h>
int main(void)
{
	//variable declarations 
	int num_month_RAD;

	//code
	printf("Enter Number Of Month (1 to 12) : ");
	scanf("%d", &num_month_RAD);

	printf("\n\n");

	switch (num_month_RAD)
	{
	case 1: // like 'if'
		printf("Month Number %d Is January !!! \n\n", num_month_RAD);
		break;

	case 2:// like 'else if'
		printf("Month Number %d Is February !!!!\n\n", num_month_RAD);
		break;

	case 3: // like 'else if'
		printf("Month Number %d Is March !!!\n\n", num_month_RAD);
		break;

	case 4:// like 'else if'
		printf("Month Number %d Is April !!!\n\n", num_month_RAD);
		break;

	case 5://like 'else if'
		printf("Month Number %d Is May !!!\n\n", num_month_RAD);
		break;

	case 6://like 'else if'
		printf("Month Number %d September !!!\n\n", num_month_RAD);
		break;
	case 7://like 'else if'
		printf("Month Number %d Octomber !!!\n\n", num_month_RAD);

	case 8://like 'else if'
		printf("Month NUmber %d November !!!\n\n", num_month_RAD);

	case 9://like 'else if'
		printf("Month Number %d December !!!\n\n", num_month_RAD);

	default:
		printf("Invalid Month Number%d Enterd !!! Please Try Again....\n\n", num_month_RAD);
		break;
    }
	printf("Switch Case Block Complete !!!\n");

	return(0);

}