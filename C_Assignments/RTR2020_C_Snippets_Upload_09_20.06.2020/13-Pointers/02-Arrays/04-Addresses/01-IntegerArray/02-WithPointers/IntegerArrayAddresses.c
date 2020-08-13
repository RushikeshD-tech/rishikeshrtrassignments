#include <stdio.h>
int main(void)
{
	//variable declarations
	int iArray_RAD[10];
	int* ptr_iArray_RAD = NULL;
	int i_RAD;
	
	//code
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
		iArray_RAD[i_RAD] = (i_RAD + 1) * 3;
	ptr_iArray_RAD = iArray_RAD; 
	printf("\n\n");
	printf("Elements Of The Integer Array : \n\n");
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
		printf("iArray[%d] = %d\n", i_RAD, *(ptr_iArray_RAD+ i_RAD));
	printf("\n\n");
	printf("Elements Of The Integer Array : \n\n");
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
	printf("iArray[%d] = %d \t \t Address = %p\n", i_RAD, *(ptr_iArray_RAD + i_RAD), (ptr_iArray_RAD + i_RAD));
	printf("\n\n");
	return(0);
}




