#include <stdio.h>
// DEFINING STRUCT
struct MyData
{
	int* ptr_i_RAD;
	int i_RAD;
	float* ptr_f_RAD;
	float f_RAD;
	double* ptr_d_RAD;
	double d_RAD;
};
int main(void)
{
	//variable declarations
	struct MyData* pData_RAD = NULL;
	//code
	printf("\n\n");
	pData_RAD = (struct MyData*)malloc(sizeof(struct MyData));
	if (pData_RAD == NULL)
	{
		printf("FAILED TO ALLOCATE MEMORY TO 'struct MyData' !!! EXITTING NOW ...\n\n");
			exit(0);
	}
	else
			printf("SUCCESSFULLY ALLOCATED MEMORY TO 'struct MyData' !!!\n\n");
	pData_RAD->i_RAD = 9;
	pData_RAD->ptr_i_RAD = &(pData_RAD->i_RAD);
	pData_RAD->f_RAD = 11.45f;
	pData_RAD->ptr_f_RAD = &(pData_RAD->f_RAD);
	pData_RAD->d_RAD = 30.121995;
	pData_RAD->ptr_d_RAD = &(pData_RAD->d_RAD);
	printf("\n\n");
	printf("i = %d\n", *(pData_RAD->ptr_i_RAD));
	printf("Adress Of 'i' = %p\n", pData_RAD->ptr_i_RAD);
	printf("\n\n");
	printf("f = %f\n", *(pData_RAD->ptr_f_RAD));
	printf("Adress Of 'f' = %p\n", pData_RAD->ptr_f_RAD);
	printf("\n\n");
	printf("d = %lf\n", *(pData_RAD->ptr_d_RAD));
	printf("Adress Of 'd' = %p\n", pData_RAD->ptr_d_RAD);
	if (pData_RAD)
	{
		free(pData_RAD);
		pData_RAD = NULL;
		printf("MEMORY ALLOCATED TO 'struct MyData' HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}
	return(0);
}

