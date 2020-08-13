#include <stdio.h>
#include <stdlib.h> //contains prototypes of malloc() and free()
int main(void)
{
	//variable declarations
	int* ptr_iArray_RAD = NULL;
	unsigned int intArrayLength_RAD = 0;
	int i_RAD;
	//code
	printf("\n\n");
	printf("Enter The Number Of Elements You Want In Your Integer Array : ");
	scanf("%d", &intArrayLength_RAD);

	ptr_iArray_RAD = (int*)malloc(sizeof(int) * intArrayLength_RAD);
	if (ptr_iArray_RAD == NULL)
	{
		printf("\n\n");
		printf("MEMORY ALLOCATION FOR INTEGER ARRAY HAS FAILED !!! EXITTING NOW...\n\n");
			exit(0);
	}
	else
	{
		printf("MEMORY ALLOCATION FOR INTEGER ARRAY HAS SUCCEEDED !!!\n\n");
		printf("MEMORY ADDRESSES FROM %p TO %p HAVE BEEN ALLOCATED TO INTEGER ARRAY !!!\n\n", ptr_iArray_RAD, (ptr_iArray_RAD + (intArrayLength_RAD - 1)));
	}
	printf("\n\n");
	printf("Enter %d Elements For The Integer Array : \n\n", intArrayLength_RAD);
	for (i_RAD = 0; i_RAD < intArrayLength_RAD; i_RAD++)
	scanf("%d", (ptr_iArray_RAD + i_RAD));
	printf("\n\n");
	printf("The Integer Array Entered By You, Consisting Of %d Elements : \n\n", intArrayLength_RAD);
	for (i_RAD = 0; i_RAD < intArrayLength_RAD; i_RAD++)
	{
		printf("ptr_iArray[%d] = %d \t \t At Address &ptr_iArray[%d] : %p\n", i_RAD, ptr_iArray_RAD[i_RAD], i_RAD, &ptr_iArray_RAD[i_RAD]);
	}
	printf("\n\n");
	for (i_RAD = 0; i_RAD < intArrayLength_RAD; i_RAD++)
	{
		printf("*(ptr_iArray + %d) = %d \t \t At Address (ptr_iArray + %d) : %p\n", i_RAD, *(ptr_iArray_RAD + i_RAD), i_RAD, (ptr_iArray_RAD + i_RAD));
	}
	if (ptr_iArray_RAD)
	{
		free(ptr_iArray_RAD);
		ptr_iArray_RAD = NULL;
		printf("\n\n");
		printf("MEMORY ALLOCATED FOR INTEGER ARRAY HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}
	return(0);
}







	