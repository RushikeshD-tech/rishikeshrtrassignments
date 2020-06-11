#include <stdio.h>
int main(void)
{
	//variable declarations
	char option_RAD, ch_RAD = '\0';
	//code
	printf("\n\n");
	printf("Once The Infinite Loop Begins, Enter 'Q' or 'q' To Quit The Infinite For Loop : \n\n");
		do
		{
			do
			{
				printf("\n");
				printf("In Loop...\n");
				ch_RAD = getch(); 
			} while (ch_RAD != 'Q' && ch_RAD != 'q');
			printf("\n\n");
			printf("EXITTING USER CONTROLLED INFINITE LOOP...");
			printf("\n\n");
			printf("DO YOU WANT TO BEGIN USER CONTROLLED INFINITE LOOP AGAIN?...(Y/y -Yes, Any Other Key - No) : ");
				option_RAD = getch();
		} while (option_RAD == 'Y' || option_RAD == 'y');
		return(0);
}