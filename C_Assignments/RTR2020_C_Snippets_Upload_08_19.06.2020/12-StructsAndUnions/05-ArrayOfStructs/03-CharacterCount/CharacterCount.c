#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_STRING_LENGTH 1024
struct CharacterCount
{
	char ch_RAD;
	int ch_count_RAD;
} 
character_and_count[] = { { 'A', 0 }, //character_and_count[0].ch = 'A' & character_and_count[0].ch_count_RAD = 0 
	{ 'B', 0 }, //character_and_count[1].ch = 'B' & character_and_count[1].ch_count_RAD = 0 
	{ 'C', 0 }, //character_and_count[2].ch = 'C' & character_and_count[2].ch_count_RAD = 0  
	{ 'D', 0 }, //character_and_count[3].ch = 'D' & character_and_count[3].ch_count_RAD = 0  
	{ 'E', 0 }, //character_and_count[4].ch = 'E' & character_and_count[4].ch_count_RAD = 0
{ 'F', 0 },
{ 'G', 0 },
{ 'H', 0 },
{ 'I', 0 },
{ 'J', 0 },
{ 'K', 0 },
{ 'L', 0 },
{ 'M', 0 },
{ 'N', 0 },
{ 'O', 0 },
{ 'P', 0 },
{ 'Q', 0 },
{ 'R', 0 },
{ 'S', 0 },
{ 'T', 0 },
{ 'U', 0 },
{ 'V', 0 },
{ 'W', 0 },
{ 'X', 0 },
{ 'Y', 0 },
{ 'Z', 0 } }; //character_and_count[25].ch = 'Z' & character_and_count[25].ch_count_RAD = 0



#define SIZE_OF_ENTIRE_ARRAY_OF_STRUCTS sizeof(character_and_count)
#define SIZE_OF_ONE_STRUCT_FROM_THE_ARRAY_OF_STRUCTS sizeof(character_and_count[0])
#define NUM_ELEMENTS_IN_ARRAY (SIZE_OF_ENTIRE_ARRAY_OF_STRUCTS / SIZE_OF_ONE_STRUCT_FROM_THE_ARRAY_OF_STRUCTS)
	
// ENTRY POINT FUNCTION

	int main(void)
{
	//variable declarations
	char str[MAX_STRING_LENGTH];
	int i_RAD, j_RAD, actual_string_length_RAD = 0;
	//code
	printf("\n\n");
	printf("Enter A String : \n\n");
	gets_s(str, MAX_STRING_LENGTH);
	actual_string_length_RAD = strlen(str);
	printf("\n\n");
	printf("The String You Have Entered Is : \n\n");
	printf("%s\n\n", str);
	for (i_RAD = 0; i_RAD < actual_string_length_RAD; i_RAD++)
	{
		for (j_RAD = 0; j_RAD < NUM_ELEMENTS_IN_ARRAY; j_RAD++) //Run every character of the input string through the entire alphabet(A TO Z)
		{
			str[i_RAD] = toupper(str[i_RAD]); //If input character is in lower case, turn it to upper case for comparison
				if (str[i_RAD] == character_and_count[j_RAD].ch_RAD) //If character is present...
					character_and_count[j_RAD].ch_count_RAD++; //Increment its count by 1 ...
		}
	}
	printf("\n\n");
	printf("The Number Of Occurences Of ALL Characters From The Alphabet Are As Follows : \n\n");
		for (i_RAD = 0; i_RAD < NUM_ELEMENTS_IN_ARRAY; i_RAD++)
		{
			printf("Character %c = %d\n", character_and_count[i_RAD].ch_RAD, character_and_count[i_RAD].ch_count_RAD);
		}
	printf("\n\n");
	return(0);
}



