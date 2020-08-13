#include <stdio.h>
#define NUM_ELEMENTS 10

int main(void)
{
	//variable declaration

	int iArray_RAD[NUM_ELEMENTS];
		int i_RAD,num_RAD,sum_RAD = 0;

	//code
	printf("\n\n");


	//**********ARRAY ELEEMENTS INPUT**************
	printf("Enter Integer Elements For Array : \n\n");
	for (i_RAD = 0; i_RAD < NUM_ELEMENTS; i_RAD++)
	{
		scanf("%d",&num_RAD);
		iArray_RAD[i_RAD] = num_RAD;

 }
	// *******SEPARATING OUT EVEN NUMBERS FROM ARRAY ELEMENTS ******

	printf("\n\n");
	printf("Even Numbers Amongst The Array Ellements Are : \n\n");
	for (i_RAD = 0; i_RAD < NUM_ELEMENTS; i_RAD++)
	{
		if ((iArray_RAD[i_RAD] % 2) == 0)
			printf("%d\n", iArray_RAD[i_RAD]);


	}

	printf("\n\n");
	printf("Odd Nu,bers Amongst The Array Elements Are : \n\n ");
	for (i_RAD = 0; i_RAD < NUM_ELEMENTS; i_RAD++)
	{
		if ((iArray_RAD[i_RAD]) != 0)
			printf("%d\n", iArray_RAD[i_RAD]);

	}
	return(0);

}


