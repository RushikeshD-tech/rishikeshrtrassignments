#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	void MyAlloc(int** ptr, unsigned int numberOfElements);
	//variable declarations
	int* piArray_RAD = NULL;
	unsigned int num_elements_RAD;
	int i_RAD;
	// code
	printf("\n\n");
	printf("How Many Elements You Want In Integer Array ?\n\n");
	scanf("%u", &num_elements_RAD);
	printf("\n\n");
	MyAlloc(&piArray_RAD, num_elements_RAD);
	printf("Enter %u Elements To Fill Up Your Integer Array : \n\n", num_elements_RAD);
	for (i_RAD = 0; i_RAD < num_elements_RAD; i_RAD++)
	scanf("%d", &piArray_RAD[i_RAD]);
	printf("\n\n");
	printf("The %u Elements Entered By You In The Integer Array : \n\n", num_elements_RAD);
	for (i_RAD = 0; i_RAD < num_elements_RAD; i_RAD++)
	printf("%u\n", piArray_RAD[i_RAD]);
	printf("\n\n");
	if (piArray_RAD)
	{
		free(piArray_RAD);
		piArray_RAD = NULL;
		printf("Memory Allocated Has Now Been Successfully Freed !!!\n\n");
	}
	return(0);
}
void MyAlloc(int** ptr, unsigned int numberOfElements)
{
	// code
	*ptr = (int*)malloc(numberOfElements * sizeof(int));
	if (*ptr == NULL)
	{
		printf("Could Not Allocate Memory !!! Exitting Now ...\n\n");
		exit(0);
	}
	printf("MyAlloc() Has Successfully Allocated %lu Bytes For Integer Array !!!\n\n", (numberOfElements * sizeof(int)));
}

