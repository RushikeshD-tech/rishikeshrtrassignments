#include <stdio.h>
#define MAX_NAME_LENGTH 100

struct Employee
{
	char name[MAX_NAME_LENGTH];
	unsigned int age;
	char gender;
	double salary;
};
struct MyData
{
	int i_RAD;
	float f_RAD;
	double d_RAD;
	char c_RAD;
};
int main(void)
{
	// Typedefs
	typedef struct Employee MY_EMPLOYEE_TYPE;
	typedef struct MyData MY_DATA_TYPE;
	// variable declarations
	struct Employee emp = { "Funny", 25, 'M', 10000.00 };
	MY_EMPLOYEE_TYPE emp_typedef = { "Bunny", 23, 'F', 20400.00 };
	struct MyData md = { 30, 11.45f, 26.122017, 'X' };
	MY_DATA_TYPE md_typedef;
	// code
	md_typedef.i_RAD = 9;
	md_typedef.f_RAD = 1.5f;
	md_typedef.d_RAD = 8.041997;
	md_typedef.c_RAD = 'P';
	printf("\n\n");
	printf("\n\nstruct Employee : ");
	printf("\nemp.name = %s", emp.name);
	printf("\nemp.age = %d", emp.age);
	printf("\nemp.gender = %c", emp.gender);
	printf("\nemp.salary = %lf", emp.salary);
	printf("\n\n");
	printf("\n\nMY_EMPLOYEE_TYPE : ");
	printf("\nemp_typedef.name = %s", emp_typedef.name);
	printf("\nemp_typedef.age = %d", emp_typedef.age);
	printf("\nemp_typedef.gender = %c", emp_typedef.gender);
	printf("\nemp_typedef.salary = %lf", emp_typedef.salary);
	printf("\n\n");
	printf("\n\nstruct MyData : ");
	printf("\nmd.i = %d", md.i_RAD);
	printf("\nmd.f = %f", md.f_RAD);
	printf("\nmd.d = %lf", md.d_RAD);
	printf("\nmd.c = %c", md.c_RAD);
	printf("\n\n");
	printf("\n\nMY_DATA_TYPE : ");
	printf("\nmd_typedef.i = %d", md_typedef.i_RAD);
	printf("\nmd_typedef.f = %f", md_typedef.f_RAD);
	printf("\nmd_typedef.d = %lf", md_typedef.d_RAD);
	printf("\nmd_typedef.c = %c", md_typedef.c_RAD);
	printf("\n\n");
	return(0);
}

