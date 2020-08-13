#include <stdio.h>
#include <ctype.h>
#define NAME_LENGTH 100
#define MARITAL_STATUS 10
struct Employee
{
	char name_RAD[NAME_LENGTH];
	int age_RAD;
	char sex_RAD;
	float salary_RAD;
	char marital_status_RAD;
};
int main(void)
{
	//function prototype
	void MyGetString(char[], int);
	//variable delarations
	struct Employee* pEmployeeRecord_RAD = NULL;
	int num_employees_RAD, i_RAD;
	//code
	printf("\n\n");
	printf("Enter Number Of Employees Whose Details You Want To Record : ");
	scanf("%d", &num_employees_RAD);
	printf("\n\n");
	pEmployeeRecord_RAD = (struct Employee*)malloc(sizeof(struct Employee) * num_employees_RAD);
	if (pEmployeeRecord_RAD == NULL)
	{
		printf("FAILED TO ALLOCATED MEMORY FOR %d EMPLOYEES !!! EXITTING NOW ...\n\n", num_employees_RAD);
			exit(0);
	}
	else
			printf("SUCCESSFULLY ALLOCATED MEMORY FOR %d EMPLOYEES !!!\n\n", num_employees_RAD);
	
	for (i_RAD = 0; i_RAD < num_employees_RAD; i_RAD++)
	{
		printf("\n\n\n\n");
		printf("********** DATA ENTRY FOR EMPLOYEE NUMBER %d **********\n", (i_RAD + 1));
		printf("\n\n");
		printf("Enter Employee Name : ");
		MyGetString(pEmployeeRecord_RAD[i_RAD].name_RAD, NAME_LENGTH);
		printf("\n\n\n");
		printf("Enter Employee's Age (in years) : ");
		scanf("%d", &pEmployeeRecord_RAD[i_RAD].age_RAD);
		printf("\n\n");
		printf("Enter Employee's Sex (M/m For Male, F/f For Female) : ");
		pEmployeeRecord_RAD[i_RAD].sex_RAD = getch();
		printf("%c", pEmployeeRecord_RAD[i_RAD].sex_RAD);
		pEmployeeRecord_RAD[i_RAD].sex_RAD = toupper(pEmployeeRecord_RAD[i_RAD].sex_RAD);
		printf("\n\n\n");
		printf("Enter Employee's Salary (in Indian Rupees) : ");
		scanf("%f", &pEmployeeRecord_RAD[i_RAD].salary_RAD);
		printf("\n\n");
		printf("Is The Employee Married? (Y/y For Yes, N/n For No) : ");
		pEmployeeRecord_RAD[i_RAD].marital_status_RAD = getch();
		printf("%c", pEmployeeRecord_RAD[i_RAD].marital_status_RAD);
		pEmployeeRecord_RAD[i_RAD].marital_status_RAD = toupper(pEmployeeRecord_RAD[i_RAD].marital_status_RAD);
	}
	// *** DISPLAY ***
	printf("\n\n\n\n");
	printf("********** DISPLAYING EMPLOYEE RECORDS **********\n\n");
	for (i_RAD = 0; i_RAD < num_employees_RAD; i_RAD++)
	{
		printf("*********** EMPLOYEE NUMBER %d **********\n\n", (i_RAD + 1));
		printf("Name : %s\n", pEmployeeRecord_RAD[i_RAD].name_RAD);
		printf("Age : %d years\n", pEmployeeRecord_RAD[i_RAD].age_RAD);
		if (pEmployeeRecord_RAD[i_RAD].sex_RAD == 'M')
			printf("Sex : Male\n");
		else if (pEmployeeRecord_RAD[i_RAD].sex_RAD == 'F')
			printf("Sex : Female\n");
		else
			printf("Sex : Invalid Data Entered\n");
		printf("Salary : Rs. %f\n", pEmployeeRecord_RAD[i_RAD].salary_RAD);
		if (pEmployeeRecord_RAD[i_RAD].marital_status_RAD == 'Y')
			printf("Marital Status : Married\n");
		else if (pEmployeeRecord_RAD[i_RAD].marital_status_RAD == 'N')
			printf("Marital Status : Unmarried\n");
		else
			printf("Marital Status : Invalid Data Entered\n");
		printf("\n\n");
	}
	if (pEmployeeRecord_RAD)
	{
		free(pEmployeeRecord_RAD);
		pEmployeeRecord_RAD = NULL;
		printf("MEMORY ALLOCATED TO %d EMPLOYEES HAS BEEN SUCCESSFULLY FREED !!!\n\n", num_employees_RAD);
	}
	return(0);
}

void MyGetString(char str[], int str_size)
{
	//variable declarations
	int i_RAD;
	char ch_RAD = '\0';
	//code
	i_RAD = 0;
	do
	{
		ch_RAD = getch();
		str[i_RAD] = ch_RAD;
		printf("%c", str[i_RAD]);
		i_RAD++;
	} while ((ch_RAD != '\r') && (i_RAD < str_size));
	if (i_RAD == str_size)
		str[i_RAD - 1] = '\0';
	else
		str[i_RAD] = '\0';
}

