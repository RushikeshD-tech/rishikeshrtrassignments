#include <stdio.h>
int main(void)
{
	//variable declarations
	
	float fArray_RAD[10];
	float* ptr_fArray_RAD = NULL;
	int i_RAD;
	
	//code
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
	fArray_RAD[i_RAD] = (float)(i_RAD + 1) * 1.5f;
	
	ptr_fArray_RAD = fArray_RAD; 
	printf("\n\n");
	printf("Elements Of The 'float' Array : \n\n");
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
	printf("fArray[%d] = %f\n", i_RAD, *(ptr_fArray_RAD + i_RAD));
	printf("\n\n");
	printf("Elements Of The 'float' Array : \n\n");
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
	printf("fArray[%d] = %f \t \t Address = %p\n", i_RAD, *(ptr_fArray_RAD + i_RAD), (ptr_fArray_RAD + i_RAD));
	printf("\n\n");
	return(0);
}



