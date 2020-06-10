#include<stdio.h>
#include<conio.h>

int main(void)
{
	int a_RAD, b_RAD;
	int result_RAD;

	char option_RAD, option_division_RAD;

	//code
	printf("\n\n");

	printf("Enter Value For 'A' : ");
	scanf("%d", &a_RAD);

	printf("Enter Value For 'B' : ");
	scanf("%d", &b_RAD);


	printf("Enter Option In Character : \n\n");
	printf("'A' or 'a' For Addition :  \n");
	printf("'S' or 's' For Subtraction : \n");
	printf("'M' or 'm' For Multiplication : \n\n");
	printf("'D' or 'd' For Division : \n\n");

	printf("Enter Option : ");
	option_RAD = getch();

	printf("\n\n");

	switch (option_RAD)
	{
	case 'A':
	case 'a':
		result_RAD = a_RAD + b_RAD;
		printf("Addition Of A = %d And B = %d Gives Result %d !!!\n\n", a_RAD, b_RAD, result_RAD);
		break;

	case 'S':
	case 's':
		if (a_RAD >= b_RAD)
		{
			result_RAD = a_RAD - b_RAD;
			printf("Subtraction Of B = %d From A = %d Gives Result %d !!!\n\n", b_RAD, a_RAD, result_RAD);
		}
		else
		{
			result_RAD = b_RAD - a_RAD;

			printf("Subtraction Of A= %d From B = %d Gives Result %d !!!\n\n", a_RAD, b_RAD, result_RAD);
		}
		break;

	case 'M':
	case 'm':
		result_RAD = a_RAD * b_RAD;
		printf("Multiplication Of A = %d And B = %d Gives Result %d !!!\n\n", a_RAD, b_RAD, result_RAD);
		break;

	case 'D':
	case 'd':
		printf("Enter Option In character : \n\n ");
		printf("'Q' or 'q' or '/' For Quotiont Upon Division : \n");
		printf("'R' or 'r' or '%%' For Remainder Upon Division : \n");

		printf("Enter Option : ");
		option_division_RAD = getch();

		printf("\n\n");

		switch (option_division_RAD)
		{
		case 'Q':
		case 'q':
		case'/':
			if (a_RAD >= b_RAD)
			{
				result_RAD = a_RAD / b_RAD;
				printf("Division OF A = %d By B = %d Gives Quotiont = %d !!!\n\n", a_RAD, b_RAD, result_RAD);
			}
			else
			{
				result_RAD = b_RAD / a_RAD;
				printf("Division Of B = %d By A = %d Gives Quotient = %d !!!\n\n", b_RAD, a_RAD, result_RAD);
			}
			break;


		case 'R':
		case'r':
		case '%':

			if (a_RAD >= b_RAD)
			{
				result_RAD = a_RAD % b_RAD;
				printf("Division Of A = %d Gives Remainder = %d !!!\n\n", a_RAD, b_RAD, result_RAD);
			}
			else
			{
				result_RAD = b_RAD % a_RAD;
				printf("Division of B = %d By A = %d Gives Remainder = %d !!!\n\n", b_RAD, a_RAD, result_RAD);
			}
			break;
		default:
			printf("Invalid Character %c Enterd For division !!! Please Try Again....\n\n", option_division_RAD);
			break;

		}

		break;

	default:
		printf("Invalid Character %c Enterd !!! Please Try Again....\n\n", option_RAD);
		break;
	}
	printf("Switch Case Block Complete!!!\n");
	return(0);
}









	




