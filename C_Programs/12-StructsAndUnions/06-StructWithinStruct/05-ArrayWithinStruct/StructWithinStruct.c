#include <stdio.h>

struct MyNumber
{
	int num_RAD;
	int num_table_RAD[10];

};
struct NumTables
{
	struct MyNumber a_RAD;
	struct MyNumber b_RAD;
	struct MyNumber c_RAD;

};

int main(void)
{
	//variable declarations
	struct NumTables tables_RAD;
	int i_RAD;

	//code
	tables_RAD.a_RAD.num_RAD = 2;
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
		tables_RAD.a_RAD.num_table_RAD[i_RAD] = tables_RAD.a_RAD.num_RAD * (i_RAD + 1);
	printf("\n\n");
	printf("Table Of %d : \n\n", tables_RAD.a_RAD.num_RAD);
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
		printf("%d * %d = %d\n", tables_RAD.c_RAD.num_RAD, (i_RAD + 1), tables_RAD.c_RAD.num_table_RAD[i_RAD]);

	tables_RAD.a_RAD.num_RAD = 3;
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
		tables_RAD.a_RAD.num_table_RAD[i_RAD] = tables_RAD.a_RAD.num_RAD * (i_RAD + 1);
	printf("\n\n");
	printf("Table Of %d : \n\n", tables_RAD.a_RAD.num_RAD);
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
		printf("%d * %d = %d\n", tables_RAD.c_RAD.num_RAD, (i_RAD + 1), tables_RAD.c_RAD.num_table_RAD[i_RAD]);

	tables_RAD.a_RAD.num_RAD = 4;
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
		tables_RAD.a_RAD.num_table_RAD[i_RAD] = tables_RAD.a_RAD.num_RAD * (i_RAD + 1);
	printf("\n\n");
	printf("Table Of %d : \n\n", tables_RAD.a_RAD.num_RAD);
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
		printf("%d * %d = %d\n", tables_RAD.c_RAD.num_RAD, (i_RAD + 1), tables_RAD.c_RAD.num_table_RAD[i_RAD]);

	return(0);


}


