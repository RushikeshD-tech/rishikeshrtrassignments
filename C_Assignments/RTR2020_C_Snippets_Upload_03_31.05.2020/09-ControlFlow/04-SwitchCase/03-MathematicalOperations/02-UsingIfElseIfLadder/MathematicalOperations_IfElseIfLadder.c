#include<stdio.h>
#include<conio.h>

int main(void)
{

	//variable declarations

	int a_RAD, b_RAD;
	int result_RAD;

	char option_RAD, option_division_RAD;

	//code
	printf("\n\n");

	printf("Enter Value For 'A': ");
	scanf("%d", &a_RAD);

	printf("Enter Value For 'B' :");
	scanf("%d", &b_RAD);

	printf("Enter Optin In character : \n\n");
	printf("'A' or 'a' For Addition : \n");
	printf("'S' or 's' For Subtraction : \n");
	printf("'M' or 'm' For Multiplication :\n");
	printf("'D' or 'd' For Division : \n");

	printf("Enter Option : ");
	option_RAD = getch();

	printf("\n\n");

	if (option_RAD == 'A' || option_RAD == 'a')
	{
		result_RAD = a_RAD + b_RAD;
		printf("Addition Of a = %d And b = %d Gives result %d !!!\n\n", a_RAD, b_RAD, result_RAD);
	}
	else if (option_RAD == 'S' || option_RAD == 's')
	{
		if (a_RAD >= b_RAD)
		{
		result_RAD = a_RAD - b_RAD;
			printf("Subtraction Of B = %d From A = %d Gives result %d !!!\n\n", a_RAD, b_RAD, result_RAD);

		}
		result_RAD = b_RAD - a_RAD;
		printf("Subtraction of A = %d From B = %d Gives Result %d !!!\n\n", a_RAD, b_RAD, result_RAD);
	}
	else if (option_RAD == 'M' || option_RAD == 'm')
	{
		result_RAD = a_RAD * b_RAD;
		printf("Multiplication Of A = %d And B = %d Gives Result %d !!!\n\n", a_RAD, b_RAD, result_RAD);

	}
	else if (option_RAD == 'D' || option_RAD == 'd')
	{
		printf("Enter Option In Character : \n\n");
		printf("'Q' or 'q' or '/' For Quotient Upon Division : \n");
		printf("'R' or 'r' or '%%' For Remainder Upon Division : \n");

		printf("\n\n");
		option_division_RAD = getch();

		if (option_division_RAD == 'Q' || option_division_RAD == 'q' || option_division_RAD == '/')
		{
			if (a_RAD >= b_RAD)
			{
				result_RAD = a_RAD / b_RAD;
				printf("Division Of A = %d By B = %d Gives Qotioent = %d !!!\n\n", a_RAD, b_RAD, result_RAD);
			}
			else
			{
				result_RAD = b_RAD / a_RAD;
				printf("Division Of B = %d By A = %d Gives Quotient =%d !!!\n\n", b_RAD, a_RAD, result_RAD);
			}
		}
		else if (option_division_RAD == 'R' || option_division_RAD == 'r' || option_division_RAD == '%')
		{
			if (a_RAD >= b_RAD)
			{
				result_RAD = a_RAD % b_RAD;
				printf("Division of A =%d By B = %d Gives Remainder = %d !!!\n \n", a_RAD, b_RAD, result_RAD);
			}
			else
			{
				result_RAD = b_RAD % a_RAD;
				printf("Division Of B = %d By A = %d Gives Remainder = %d !!!\n\n", b_RAD, a_RAD, result_RAD);

			}
		}
		else
			printf("Invalid Character %c Enterd For Division !!! Please Try Again...\n\n", option_division_RAD);
		}
		else
			printf("Invalid Character %c Enterd !!! Please Try Again....\n\n", option_RAD);
		printf("If - Else If Else Ladder Complete!!!\n");

		return(0);
	}
