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

	if ((ch_RAD == 'A' || ch_RAD == 'a') || (ch_RAD == 'E' || ch_RAD == 'e') || (ch_RAD == 'I' || ch_RAD == 'i') || (ch_RAD == 'O' || ch_RAD == 'o') || (ch_RAD == 'U' || ch_RAD == 'u'))
	{
		printf("Character \'%c\' Enterd By You, Is A Vowel Character From The English Alphabet !!!\n\n", ch_RAD);
	}
	else
	{
		ch_value_RAD = (int)ch_RAD;

		if ((ch_value_RAD >= CHAR_ALPHABET_LOWER_CASE_BEGINNING && ch_value_RAD <= CHAR_ALPHABET_UPPER_CASE_ENDING) || (ch_value_RAD >= CHAR_ALPHABET_LOWER_CASE_BEGINNING && ch_value_RAD <= CHAR_ALPHABET_LOWER_CASE_ENDING))

		{
			printf("Character \'%c\' Enterd By You, Is A Consonant Character From The English Alphabet !!!\n\n", ch_RAD); 
		}
		else if (ch_value_RAD >= CHAR_DIGIT_BEGINNING && ch_value_RAD <= CHAR_DIGIT_ENDING)
		{
			printf("Character \'%c\' Enterd By you, Is A DIGIT CHARACTER !!!\n\n", ch_RAD);
		}
		else
		{
			printf("Character \'%c\' Enterd By You, IS A Special Character !!!\n\n", ch_RAD);
		}
	}
	return(0);
}




	
