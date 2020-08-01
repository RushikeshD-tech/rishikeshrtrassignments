#include<stdio.h>
#define NAME_LENGTH 100
#define MARITAL_STATUS 10

struct Employee
{
	char name_RAD[NAME_LENGTH];
	int age_RAD;
	float salary_RAD;
	char sex_RAD;
	char marital_status_RAD[MARITAL_STATUS];

};
int main(void)
{
	//variable declarations
	struct Employee EmployeeRecord_RAD[5];//An array of 5 structs - Each being type 'struct Employee'
	char employee_rajesh_RAD[] = "Rajesh";
	char employee_sameer_RAD[] = "Sameer";
	char employee_kalyani_RAD[] = "Kalyani";
	char employee_sonali_RAD[] = "Sonali";
	char employee_shantanu_RAD[] = "Shantanu";

	int i_RAD;

	//code
	//***********HARD-CODED INITIALIZATION OF ARRAY OF 'struct Employee'***************

	//************EMPLOYEE 1************
	strcpy(EmployeeRecord_RAD[0].name_RAD, employee_rajesh_RAD);
	EmployeeRecord_RAD[0].age_RAD = 30;
	EmployeeRecord_RAD[0].sex_RAD = 'M';
	EmployeeRecord_RAD[0].salary_RAD = 50000.0f;
	strcpy (EmployeeRecord_RAD[0].marital_status_RAD, "Unmarried");

	//*********EMPLOYEE 2**************
	strcpy(EmployeeRecord_RAD[1].name_RAD, employee_sameer_RAD);
	EmployeeRecord_RAD[1].age_RAD = 32;
	EmployeeRecord_RAD[1].sex_RAD = 'M';
	EmployeeRecord_RAD[1].salary_RAD = 60000.0f;
	strcpy(EmployeeRecord_RAD[1].marital_status_RAD, "Married");

	//*********EMPLOYEE 3**************
	strcpy(EmployeeRecord_RAD[1].name_RAD, employee_kalyani_RAD);
	EmployeeRecord_RAD[2].age_RAD = 29;
	EmployeeRecord_RAD[2].sex_RAD = 'F';
	EmployeeRecord_RAD[2].salary_RAD = 62000.0f;
	strcpy(EmployeeRecord_RAD[2].marital_status_RAD, "Unmarried");

	//*********EMPLOYEE 4**************
	strcpy(EmployeeRecord_RAD[3].name_RAD, employee_sonali_RAD);
	EmployeeRecord_RAD[3].age_RAD = 33;
	EmployeeRecord_RAD[3].sex_RAD = 'F';
	EmployeeRecord_RAD[3].salary_RAD = 50000.0f;
	strcpy(EmployeeRecord_RAD[3].marital_status_RAD, "Married");

	//*********EMPLOYEE 5**************
	strcpy(EmployeeRecord_RAD[4].name_RAD, employee_shantanu_RAD);
	EmployeeRecord_RAD[4].age_RAD = 35;
	EmployeeRecord_RAD[4].sex_RAD = 'M';
	EmployeeRecord_RAD[4].salary_RAD = 55000.0f;
	strcpy(EmployeeRecord_RAD[4].marital_status_RAD, "Married");


//*********Display*************
printf("\n\n");
printf("****** DISPLAYING EMPLOYEE RECORDS ******\n\n");
for (i_RAD = 0; i_RAD < 5; i_RAD++)
{
	printf("******* EMPLOYEE NUMBER %d ******\n\n", (i_RAD + 1));
	printf("Name : %s\n", EmployeeRecord_RAD[i_RAD].name_RAD);
	printf("Age : %d years\n", EmployeeRecord_RAD[i_RAD].age_RAD);
	if (EmployeeRecord_RAD[i_RAD].sex_RAD == 'M' || EmployeeRecord_RAD[i_RAD].sex_RAD == 'm')
		printf("Sex : Male\n");
	else
		printf("Sex : Female\n");
	printf("Salary : Rs. %f\n", EmployeeRecord_RAD[i_RAD].salary_RAD);
		printf("Marital Status : Rs. %s\n", EmployeeRecord_RAD[i_RAD].marital_status_RAD);
	printf("\n\n");
}
return(0);
}



