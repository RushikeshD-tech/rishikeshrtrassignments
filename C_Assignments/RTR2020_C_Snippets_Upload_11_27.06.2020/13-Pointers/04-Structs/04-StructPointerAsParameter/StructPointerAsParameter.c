#include <stdio.h>
// DEFINING STRUCT
struct MyData
{
	int i_RAD;
	float f_RAD;
	double d_RAD;
};
int main(void)
{
	//function prototypes
	void ChangeValues(struct MyData*);
	//variable declarations
	struct MyData* pData_RAD = NULL;
	
	//code
	printf("\n\n");
	pData_RAD = (struct MyData*)malloc(sizeof(struct MyData));
	if (pData_RAD == NULL)
	{
		printf("FAILED TO ALLOCATE MEMORY TO 'sturct MyData' !!! EXITTING NOW ...\n\n");
			exit(0);
	}
	else
			printf("SUCCESSFULLY ALLOCATED MEMORY TO 'sturct MyData' !!!\n\n");

	pData_RAD->i_RAD = 30;
	pData_RAD->f_RAD = 11.45f;
	pData_RAD->d_RAD = 1.2995;
	
	printf("\n\n");
	printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	printf("i = %d\n", pData_RAD->i_RAD);
	printf("f = %f\n", pData_RAD->f_RAD);
	printf("d = %lf\n", pData_RAD->d_RAD);
	ChangeValues(pData_RAD);
	
	printf("\n\n");
	printf("DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	printf("i = %d\n", pData_RAD->i_RAD);
	printf("f = %f\n", pData_RAD->f_RAD);
	printf("d = %lf\n", pData_RAD->d_RAD);
	if (pData_RAD)
	{
		free(pData_RAD);
		pData_RAD = NULL;
		printf("MEMORY ALLOCATED TO 'struct MyData' HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}
	return(0);
}
void ChangeValues(struct MyData* pParam_Data)
{
	//code
	pParam_Data->i_RAD = 9;
	pParam_Data->f_RAD = 8.2f;
	pParam_Data->d_RAD = 6.1998;
	
	
}

