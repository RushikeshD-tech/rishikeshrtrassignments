#include <stdio.h>

int main(void)
{
	//variable declarartions
	char chArray_01_RAD[] = { 'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P', '\0' };

	char chArray_02_RAD[9] = { 'W', 'E', 'L', 'C', 'O', 'M', 'E', 'S', '\0' };

	char chArray_03_RAD[] = { 'Y','O', 'U','\0' };

	char chArray_04_RAD[] = "To";

	char chArray_05_RAD[] = "REAL TIME RENDERING BATCH OF 2020-21";

	char chArray_WithoutNullTerminator_RAD[] = { 'H', 'e', 'l', 'l', 'o' };

	//code
	printf("\n\n");

	printf("size of chArray_01 : %lu\n\n", sizeof(chArray_01_RAD));
	printf("size of chArray_02 : %lu\n\n", sizeof(chArray_02_RAD));
	printf("size of chArray_03 : %lu\n\n", sizeof(chArray_03_RAD));
	printf("size of chArray_04 : %lu\n\n", sizeof(chArray_04_RAD));
	printf("size of chArray_05 : %lu\n\n", sizeof(chArray_05_RAD));

	printf("\n\n");

	printf("The String Are : \n\n");
	printf("chArray_01 : %s\n\n", chArray_01_RAD);
	printf("chArray_02 : %s\n\n", chArray_02_RAD);
	printf("chArray_03 : %s\n\n", chArray_03_RAD);
	printf("chArray_04 : %s\n\n", chArray_04_RAD);
	printf("chArray_05 : %s\n\n", chArray_05_RAD);

	printf("\n\n");
	printf("Size of chArray_WithoutNuLLTerminator : %lu\n\n", sizeof(chArray_WithoutNullTerminator_RAD));
	printf("chArray_WithoutNullTerminator : %s\n\n", chArray_WithoutNullTerminator_RAD);

	return(0);
}

