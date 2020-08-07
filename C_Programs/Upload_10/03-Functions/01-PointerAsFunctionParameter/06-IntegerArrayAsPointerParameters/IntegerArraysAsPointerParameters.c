#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//function declarations
	void MultiplyArrayElementsByNumber(int*, int, int);
	//variable declaration
	int *iArray_RAD = NULL;
	int num_elements_RAD;
	int i_RAD, num_RAD;
	
	//code
	printf("\n\n");
	printf("Enter How Many Elements You Want In The Integer Array : ");
	scanf("%d", &num_elements_RAD);
	iArray_RAD = (int *)malloc(num_elements_RAD * sizeof(int));
	if (iArray_RAD == NULL)
	{
		printf("MEMORY ALLOCATION TO 'iArray' HAS FAILED !!! EXITTING NOW...\n\n");
			exit(0);
	}
	printf("\n\n");
	printf("Enter %d Elements For The Integer Array : \n\n", num_elements_RAD);
	for (i_RAD = 0; i_RAD < num_elements_RAD; i_RAD++)
		scanf("%d", &iArray_RAD[i_RAD]);
	
	// ****** ONE ******
	printf("\n\n");
	printf("Array Before Passing To Function MultiplyArrayElementsByNumber() :\n\n");
		for (i_RAD = 0; i_RAD < num_elements_RAD; i_RAD++)
    printf("iArray[%d] = %d\n", i_RAD, iArray_RAD[i_RAD]);
	printf("\n\n");
	printf("Enter The Number By Which You Want To Multiply Each Array Element :");
		scanf("%d", &num_RAD);
	MultiplyArrayElementsByNumber(iArray_RAD, num_elements_RAD, num_RAD);
	printf("\n\n");
	printf("Array Returned By Function MultiplyArrayElementsByNumber() : \n\n");
		for (i_RAD = 0; i_RAD < num_elements_RAD; i_RAD++)
	printf("iArray[%d] = %d\n", i_RAD, iArray_RAD[i_RAD]);
	if (iArray_RAD)
	{
		free(iArray_RAD);
		iArray_RAD = NULL;
		printf("\n\n");
		printf("MEMORY ALLOCATED TO 'iArray' HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}
	return(0);
}
void MultiplyArrayElementsByNumber(int *arr_RAD, int iNumElements_RAD, int n_RAD)
{
	//variable declarations
	int i_RAD;

	//code
	for (i_RAD = 0; i_RAD < iNumElements_RAD; i_RAD++)
		arr_RAD[i_RAD] = arr_RAD[i_RAD] * n_RAD;
}

