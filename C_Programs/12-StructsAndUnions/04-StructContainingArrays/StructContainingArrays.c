#include <stdio.h>
#define INT_ARRAY_SIZE 10
#define FLOAT_ARRAY_SIZE 5
#define CHAR_ARRAY_SIZE 26
#define NUM_STRINGS 10
#define MAX_CHARACTERS_PER_STRING 20
#define ALPHABET_BEGINNING 65 // 'A'

struct MyDataOne
{
	int iArray_RAD[INT_ARRAY_SIZE];
	float fArray_RAD[FLOAT_ARRAY_SIZE];
};
struct MyDataTwo
{
	char cArray_RAD[CHAR_ARRAY_SIZE];
	char strArray_RAD[NUM_STRINGS][MAX_CHARACTERS_PER_STRING];
};
int main(void)
{
	//variable declarations
	struct MyDataOne data_one_RAD;
	struct MyDataTwo data_two_RAD;
	int i_RAD;
	//code
	// *** PIECE-MEAL ASSIGNMENT (HARD-CODED) ***
	
	data_one_RAD.fArray_RAD[0] = 0.1f;
	data_one_RAD.fArray_RAD[1] = 1.2f;
	data_one_RAD.fArray_RAD[2] = 2.3f;
	data_one_RAD.fArray_RAD[3] = 3.4f;
	data_one_RAD.fArray_RAD[4] = 4.5f;
	
	// *** LOOP ASSIGNMENT (USER INPUT) ***
	
	printf("\n\n");
	printf("\n\nEnter %d Integers : ", INT_ARRAY_SIZE);
	for (i_RAD = 0; i_RAD < INT_ARRAY_SIZE; i_RAD++)
	
	scanf("%d", &data_one_RAD.iArray_RAD[i_RAD]);
	
	// *** LOOP ASSIGNMENT (HARD-CODED) ***
	
	for (i_RAD = 0; i_RAD < CHAR_ARRAY_SIZE; i_RAD++)
	data_two_RAD.cArray_RAD[i_RAD] = (char)(i_RAD + ALPHABET_BEGINNING);
	
	// *** PIECE-MEAL ASSIGNMENT (HARD-CODED) ***
	
	strcpy(data_two_RAD.strArray_RAD[0], "Welcome !!!");
	strcpy(data_two_RAD.strArray_RAD[1], "This");
	strcpy(data_two_RAD.strArray_RAD[2], "Is");
	strcpy(data_two_RAD.strArray_RAD[3], "ASTROMEDICOMP'S");
	strcpy(data_two_RAD.strArray_RAD[4], "Real");
	strcpy(data_two_RAD.strArray_RAD[5], "Time");
	strcpy(data_two_RAD.strArray_RAD[6], "Rendering");
	strcpy(data_two_RAD.strArray_RAD[7], "Batch");
	strcpy(data_two_RAD.strArray_RAD[8], "Of");
	strcpy(data_two_RAD.strArray_RAD[9], "2020-2021 !!!");
	
	// *** DISPLAYING DATA MEMBERS OF 'struct DataOne' AND THEIR VALUES ***
	
	printf("\n\n");
	printf("\n\nMembers Of 'struct DataOne' Alongwith Their Assigned Values Are :    ");
	printf("\n\n");
	printf("\n\nInteger Array (data_one.iArray[]) :  ");
	
	for (i_RAD = 0; i_RAD < INT_ARRAY_SIZE; i_RAD++)
	
	printf("\ndata_one.iArray[%d] = %d", i_RAD, data_one_RAD.iArray_RAD[i_RAD]);
	printf("\n\n");
	printf("\n\nFloating-Point Array (data_one.fArray[]) : ");
	
	for (i_RAD = 0; i_RAD < FLOAT_ARRAY_SIZE; i_RAD++)
	
		printf("\ndata_one.fArray[%d] = %f", i_RAD, data_one_RAD.fArray_RAD[i_RAD]);
	
	// *** DISPLAYING DATA MEMBERS OF 'struct DataTwo' AND THEIR VALUES ***
	
	printf("\n\n");
	printf("\n\nMembers Of 'struct DataTwo' Alongwith Their Assigned Values Are :   ");
	printf("\n\n");
	printf("\n\nCharacter Array (data_two.cArray[]) : ");
	
	for (i_RAD = 0; i_RAD < CHAR_ARRAY_SIZE; i_RAD++)
		
	printf("\ndata_two.cArray[%d] = %c", i_RAD, data_two_RAD.cArray_RAD[i_RAD]);
	printf("\n\n");
	printf("String Array (data_two.strArray[]) : ");
	
	for (i_RAD = 0; i_RAD < NUM_STRINGS; i_RAD++)
	
	printf("%s ", data_two_RAD.strArray_RAD[i_RAD]);
	printf("\n\n");
	return(0);
}



