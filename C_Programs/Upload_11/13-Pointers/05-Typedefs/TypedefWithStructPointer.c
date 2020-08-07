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
	//variable declarations
	int i_size_RAD;
	int f_size_RAD;
	int d_size_RAD;
	int struct_MyData_size_RAD;
	int pointer_to_struct_MyData_size_RAD;
	typedef struct MyData* MyDataPtr_RAD;
	MyDataPtr_RAD pData_RAD;
	//code
	printf("\n\n");
	pData_RAD = (MyDataPtr_RAD)malloc(sizeof(struct MyData));
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

	i_size_RAD = sizeof(pData_RAD->i_RAD);
	f_size_RAD = sizeof(pData_RAD->f_RAD);
	d_size_RAD = sizeof(pData_RAD->d_RAD);

	printf("\n\n");
	printf("SIZES (in bytes) OF DATA MEMBERS OF 'struct MyData' ARE : \n\n");
	printf("Size of 'i' = %d bytes\n", i_size_RAD);
	printf("Size of 'f' = %d bytes\n", f_size_RAD);
	printf("Size of 'd' = %d bytes\n", d_size_RAD);
	
	struct_MyData_size_RAD = sizeof(struct MyData);
	pointer_to_struct_MyData_size_RAD = sizeof(MyDataPtr_RAD);
	
	printf("\n\n");
	printf("Size of 'struct MyData' : %d bytes\n\n", struct_MyData_size_RAD);
	printf("Size of pointer to 'struct MyData' : %d bytes\n\n", pointer_to_struct_MyData_size_RAD);
	if (pData_RAD)
	{
		free(pData_RAD);
		pData_RAD = NULL;
		printf("MEMORY ALLOCATED TO 'struct MyData' HAS BEEN SUCCESSFULLY FREED !!!\n\n");
	}
	return(0);
}



