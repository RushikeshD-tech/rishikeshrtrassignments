#include <stdio.h>

struct Employee
{
	char name_RAD[100];
	int age_RAD;
	float salary_RAD;
	char sex_RAD;
	char marital_status_RAD;
};
int main(void)
{
	//code
	printf("\n\n");
	printf("SIZES OF DATA TYPES AND POINTERS TO THOSE RESPECTIVE DATA TYPES ARE : \n\n");
	printf("Size Of (int)           : %d \t \t \t Size of pointer to int  (int*)   :%d\n\n", sizeof(int), sizeof(int*));
	printf("Size Of (float)         : %d \t \t \t Size of pointer to float (float*)   :%d\n\n", sizeof(float), sizeof(float*));
	printf("Size Of (double)         : %d \t \t \t Size of pointer to double (double*)   :%d\n\n", sizeof(double), sizeof(double*));
	printf("Size Of (char)         : %d \t \t \t Size of pointer to char (char*)   :%d\n\n", sizeof(char), sizeof(char*));
	printf("Size Of (struct Employee)         : %d \t \t \t Size of pointer to struct Employee (struct Employee*)   :%d\n\n", sizeof(struct Employee), sizeof(struct Employee*));

	return(0);


}




