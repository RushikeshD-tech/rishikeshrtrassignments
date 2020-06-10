#include <stdio.h>
int main(void)
{
	//variable declarations
	int num_month_RAD;
	//code
	printf("\n\n");
	printf("Enter Number Of Month (1 to 12) : ");
	scanf("%d", &num_month_RAD);
	printf("\n\n");
	// IF - ELSE - IF LADDER BEGINS FROM HERE...
	if (num_month_RAD == 1) //like 'case 1'
		printf("Month Number %d Is JANUARY !!!\n\n", num_month_RAD);
	else if (num_month_RAD == 2) //like 'case 2'
		printf("Month Number %d Is FEBRUARY !!!\n\n", num_month_RAD);
	else if (num_month_RAD == 3) //like 'case 3'
		printf("Month Number %d Is MARCH !!!\n\n", num_month_RAD);
	else if (num_month_RAD == 4) //like 'case 4'
		printf("Month Number %d Is APRIL !!!\n\n", num_month_RAD);
	else if (num_month_RAD == 5) //like 'case 5'
		printf("Month Number %d Is MAY !!!\n\n", num_month_RAD);
	else if (num_month_RAD == 6) //like 'case 6'
		printf("Month Number %d Is JUNE !!!\n\n", num_month_RAD);
	else if (num_month_RAD == 7) //like 'case 7'
		printf("Month Number %d Is JULY !!!\n\n", num_month_RAD);
	else if (num_month_RAD == 8) //like 'case 8'
		printf("Month Number %d Is AUGUST !!!\n\n", num_month_RAD);
	else if (num_month_RAD == 9) //like 'case 9'
		printf("Month Number %d Is SEPTEMBER !!!\n\n", num_month_RAD);
	else if (num_month_RAD == 10) //like 'case 10'
		printf("Month Number %d Is OCTOBER !!!\n\n", num_month_RAD);
	else if (num_month_RAD == 11) //like 'case 11'
		printf("Month Number %d Is NOVEMBER !!!\n\n", num_month_RAD);
	else if (num_month_RAD == 12) //like 'case 12'
		printf("Month Number %d Is DECEMBER !!!\n\n", num_month_RAD);
	else 
		printf("Invalid Month Number %d Entered !!! Please Try Again...\n\n",
			num_month_RAD);
	printf("If - Else If - Else Ladder Complete !!!\n");
	return(0);
}