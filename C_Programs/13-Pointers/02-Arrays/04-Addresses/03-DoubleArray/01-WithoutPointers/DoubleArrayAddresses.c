#include <stdio.h>
int main(void)
{
	//variable declarations
	double dArray_RAD[10];
	int i_RAD;
	
	//code
	
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
	dArray_RAD[i_RAD] = (float)(i_RAD + 1) * 1.333333f;
	printf("\n\n");
	printf("Elements Of The 'double' Array : \n\n");
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
	printf("dArray[%d] = %lf\n", i_RAD, dArray_RAD[i_RAD]);
	printf("\n\n");
	printf("Elements Of The 'double' Array : \n\n");
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
	printf("dArray[%d] = %lf \t \t Address = %p\n", i_RAD, dArray_RAD[i_RAD], &dArray_RAD[i_RAD]);
	printf("\n\n");
	return(0);
}





