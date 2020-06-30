#include <stdio.h>
int main(void)
{
	//code
	printf("\n\n");
	printf("\n\nGoing On To Next Line...Using \\n Escape Sequence..");
	printf("\n\nDemonstrating \t Horizontal \t Tab \t Using \t \\t Escape Sequence !!!");
	printf("\n\n\"This Is A Double Quoted Output\" Done Using \\\" \\\" Escape Sequence");
	printf("\n\n\'This Is A Single Quoted Output\' Done Using \\\' \\\' Escape Sequence");
	printf("\n\nBACKSPACE Turned To BACKSPACE\b Using Escape Sequence \\b");

	printf("\n\r Demonstrating Carriage Return Using \\r Escape Sequence");
	printf("\nDemonstrating \r Carriage Return Using \\r Escape Sequence");
	printf("\n\nDemonstrating Carriage \r Return Using \\r Escape Sequence");

	printf("\n\nDemonstrating \x41 Using \\xhh Escape Sequence");   //0x41 Is The Hexadecimal Code For Letter 'A'.
	printf("\n\nDemonstrating \102 Using \\ooo Escape Sequence");   //102 Is The Octal Code For Letter 'B'. 
	return(0);
}



