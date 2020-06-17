#include <stdio.h>
#define NUM_ELEMENTS 10
int main(void)
{
	//variable declarations
	int iArray_RAD[NUM_ELEMENTS];
	int i_RAD, num_RAD, j_RAD, count_RAD = 0;
	//code
	printf("\n\n");

	printf("Enter Integer Elememts For Array : \n\n");
	for (i_RAD = 0; i_RAD < NUM_ELEMENTS; i_RAD++)
	{
		scanf("%d", &num_RAD);
		
		if (num_RAD < 0)
			num_RAD = -1 * num_RAD;
		iArray_RAD[i_RAD] = num_RAD;
	}
	
	printf("\n\n");
	printf("Array Elements Are : \n\n");
	for (i_RAD = 0; i_RAD < NUM_ELEMENTS; i_RAD++)
		printf("%d\n", iArray_RAD[i_RAD]);
	
	printf("\n\n");
	printf("Prime Numbers Amongst The Array Elements Are : \n\n");
	for (i_RAD = 0; i_RAD < NUM_ELEMENTS; i_RAD++)
	{
		for (j_RAD = 1; j_RAD <= iArray_RAD[i_RAD]; j_RAD++)
		{
			if ((iArray_RAD[i_RAD] % j_RAD) == 0)
				count_RAD++;
		}
		
			if (count_RAD == 2)
				printf("%d\n", iArray_RAD[i_RAD]);
		count_RAD = 0; 
	}
	return(0);
}


