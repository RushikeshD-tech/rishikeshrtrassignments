#include <stdio.h>
int main(void)
{
	//variable declarations
	char option_RAD, ch_RAD = '\0';
	//code
	printf("\n\n");
	printf("Once The Infinite Loop Begins, Enter 'Q' or 'q' To Quit The Infinite For Loop : \n\n");
		printf("Enter 'Y' oy 'y' To Initiate User Controlled Infinite Loop : ");
	printf("\n\n");
	option_RAD = getch();
	if (option_RAD == 'Y' || option_RAD == 'y')
	{
		while (1) 
		{
			printf("In Loop...\n");
			ch_RAD = getch();
			if (ch_RAD == 'Q' || ch_RAD == 'q')
				break; 
		}
		printf("\n\n");
		printf("EXITTING USER CONTROLLED INFINITE LOOP...");
		printf("\n\n");
	}
	else
		printf("You Must Press 'Y' or 'y' To Initiate The User Controlled Infinite Loop....Please Try Again...\n\n");
			return(0);
}