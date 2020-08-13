#include<stdio.h>

#define NUM_ELEMENTS 10
int main(void)
{

//variable declaration

	int iArray_RAD[NUM_ELEMENTS];
	int i_RAD, num_RAD, sum_RAD = 0;

	//code
	printf("\n\n");
	printf("Enter Integer Elements For Array : \n\n");
	for (i_RAD = 0; i_RAD < NUM_ELEMENTS; i_RAD++)
	{
		scanf("%d", &num_RAD);
		iArray_RAD[i_RAD] = num_RAD;
	}

	for (i_RAD = 0; i_RAD < NUM_ELEMENTS; i_RAD++)
	{
		sum_RAD = sum_RAD + iArray_RAD[i_RAD];

	}
	printf("\n\n");
	printf("sum of all elements of array = %d\n\n", sum_RAD);

	return(0);

}