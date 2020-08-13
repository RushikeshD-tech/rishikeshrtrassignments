#include <stdio.h>
#include <conio.h>
int main(void)
{
	//variable declarations
	int i_RAD;
	char ch_RAD;
	//code
	printf("\n\n");
	printf("Printing Even Numbers From 1 to 100 For Every User Input. Exitting the Loop When User Enters Character 'Q' or 'q' : \n\n");
		printf("Enter Character 'Q' or 'q' To Exit Loop : \n\n");
	for (i_RAD = 1; i_RAD <= 100; i_RAD++)
	{
		printf("\t%d\n", i_RAD);
		ch_RAD = getch();
		if (ch_RAD == 'Q' || ch_RAD == 'q')
		{
			break;
		}
	}
	printf("\n\n");
	printf("EXITTING LOOP...");
	printf("\n\n");
	return(0);
}