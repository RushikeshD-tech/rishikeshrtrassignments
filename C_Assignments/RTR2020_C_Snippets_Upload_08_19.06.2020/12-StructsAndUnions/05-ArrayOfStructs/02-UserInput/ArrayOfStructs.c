#include <stdio.h>
#include <ctype.h>
#define NUM_EMPLOYEES 5 // Simply Change this constant value to have as many number of Employee Records as you please ...
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
	struct Employee EmployeeRecord[NUM_EMPLOYEES]; //An array of <NUM_EMPLOYEES> structs - Each being type 'struct Employee'
	int i_RAD;
	//code
	// ****** USER INPUT INITIALIZATION OF ARRAY OF 'struct Employee' ******
	for (i_RAD = 0; i_RAD < NUM_EMPLOYEES; i_RAD++)
	{
		printf("\n\n\n\n");
		printf("********** DATA ENTRY FOR EMPLOYEE NUMBER %d **********\n", (i_RAD + 1));
		printf("\n\n");
		printf("Enter Employee Name : ");
		MyGetString(EmployeeRecord[i_RAD].name_RAD, NAME_LENGTH);
		printf("\n\n\n");
		printf("Enter Employee's Age (in years) : ");
		scanf("%d", &EmployeeRecord[i_RAD].age_RAD);
		printf("\n\n");
		printf("Enter Employee's Sex (M/m For Male, F/f For Female) : ");
		EmployeeRecord[i_RAD].sex_RAD = getch();
		printf("%c", EmployeeRecord[i_RAD].sex_RAD);
		EmployeeRecord[i_RAD].sex_RAD = toupper(EmployeeRecord[i_RAD].sex_RAD);
		printf("\n\n\n");
		printf("Enter Employee's Salary (in Indian Rupees) : ");
		scanf("%f", &EmployeeRecord[i_RAD].salary_RAD);
		printf("\n\n");
		printf("Is The Employee Married? (Y/y For Yes, N/n For No) : ");
		EmployeeRecord[i_RAD].marital_status_RAD = getch();
		printf("%c", EmployeeRecord[i_RAD].marital_status_RAD);
		EmployeeRecord[i_RAD].marital_status_RAD = toupper(EmployeeRecord[i_RAD].marital_status_RAD);
	}
	// *** DISPLAY ***
	printf("\n\n\n\n");
	printf("********** DISPLAYING EMPLOYEE RECORDS **********\n\n");
	for (i_RAD = 0; i_RAD < NUM_EMPLOYEES; i_RAD++)
	{
		printf("*********** EMPLOYEE NUMBER %d **********\n\n", (i_RAD + 1));
		printf("Name : %s\n", EmployeeRecord[i_RAD].name_RAD);
		printf("Age : %d years\n", EmployeeRecord[i_RAD].age_RAD);
		
		if (EmployeeRecord[i_RAD].sex_RAD == 'M')
			printf("Sex : Male\n");
		else if (EmployeeRecord[i_RAD].sex_RAD == 'F')
			printf("Sex : Female\n");
		else
			printf("Sex : Invalid Data Entered\n");
		
		printf("Salary : Rs. %f\n", EmployeeRecord[i_RAD].salary_RAD);
		
		if (EmployeeRecord[i_RAD].marital_status_RAD == 'Y')
			printf("Marital Status : Married\n");
		else if (EmployeeRecord[i_RAD].marital_status_RAD == 'N')
			printf("Marital Status : Unmarried\n");
		else
			printf("Marital Status : Invalid Data Entered\n");
		
		printf("\n\n");
	}
	return(0);
}
// *** SIMPLE RUDIMENTARY IMPLEMENTATION OF gets_s() ***
// *** IMPLEMENTED DUE TO DIFFERENT BEHAVIOUR OF gets_s() / fgets() / fscanf() ON DIFFERENT PLATFORMS***
// *** BACKSPACE / CHARACTER DELETION AND ARROW KEY CURSOR MOVEMENT NOT IMPLEMENTED***

void MyGetString(char str[], int str_size)
{
       //variable declarations
		int i_RAD;
	char ch = '\0';
	
	  //code
	i_RAD = 0;
	do
	{
		ch = getch();
		str[i_RAD] = ch;
		printf("%c", str[i_RAD]);
		i_RAD++;
	} 
	while ((ch != '\r') && (i_RAD < str_size));
	if (i_RAD == str_size)
		str[i_RAD - 1] = '\0';
	else
		str[i_RAD] = '\0';
}





