#include<stdio.h>
#include<conio.h>

#define CHAR_ALPHABET_UPPER_CASE_BEGINNING 65
#define CHAR_ALPHABET_UPPER_CASE_ENDING 90

#define CHAR_ALPHABET_LOWER_CASE_BEGINNING 97
#define CHAR_ALPHABET_LOWER_CASE_ENDING 122

#define CHAR_DIGIT_BEGINNING 48
#define CHAR_DIGIT_ENDING 57

int main(void)
{
	//variable declarations
	char ch_RAD;
	int ch_value_RAD;

	//code
	printf("\n\n");

	printf("Enter Character : ");
	ch_RAD = getch();

	printf("\n\n");

	switch (ch_RAD)
	{
// FALL Through Condition

	case 'A':
	case 'a':
	
	case 'E':
	case 'e':

	case 'I':
	case 'i':

	case 'O':
	case 'o':

	case 'U':
	case 'u':
		printf("Character Enterd By You, Is A Vowel Character from English Alpahbet !!!\n\n", ch_RAD);
		break;
	default:
		ch_value_RAD = (int)ch_RAD;

		if ((ch_value_RAD >= CHAR_ALPHABET_UPPER_CASE_BEGINNING && ch_value_RAD <= CHAR_ALPHABET_UPPER_CASE_ENDING) || (ch_value_RAD >= CHAR_ALPHABET_LOWER_CASE_BEGINNING && ch_value_RAD <= CHAR_ALPHABET_LOWER_CASE_ENDING))
		{
			printf("Character \'%c\' Enterd By You, IS A Consonant Character from The english alpahbet !!!!\n\n", ch_RAD);

         }
		else if (ch_value_RAD >= CHAR_DIGIT_BEGINNING && ch_value_RAD <= CHAR_DIGIT_ENDING)
		{
			printf(" Character \'%c\' Enterd By You, Is A DIGIT CHARACTER !!!\n\n", ch_RAD);
        }
		else
		{
			printf("Character \'%c\' Enterd By You, Is A SPECIAL CHARACTER !!!\n\n", ch_RAD);

		}
		break;

	}
	printf("Switch Case Block Complete !!!\n");
	return(0);
}