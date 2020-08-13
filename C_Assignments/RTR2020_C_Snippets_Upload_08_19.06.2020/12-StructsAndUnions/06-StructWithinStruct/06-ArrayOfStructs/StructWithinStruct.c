#include <stdio.h>

struct MyNumber
{
	int num_RAD;
	int num_table_RAD[10];
};
struct NumTables
{
	struct MyNumber n_RAD;

};
int main(void)
{
	//variable declarations
	struct NumTables tables_RAD[10];
	int i_RAD;
	int j_RAD;

	//code
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
	{
		tables_RAD[i_RAD].n_RAD.num_RAD = (i_RAD + 1);

	}
	for (i_RAD = 0; i_RAD < 10; i_RAD++)
	{
		printf("\n\n");
		printf("Table of %d : \n\n", tables_RAD[i_RAD].n_RAD.num_RAD);
		for (j_RAD = 0; j_RAD < 10; i_RAD++)
		{
			tables_RAD[i_RAD].n_RAD.num_table_RAD[j_RAD] = tables_RAD[i_RAD].n_RAD.num_RAD * (j_RAD + 1);
			printf("%d * %d\n", tables_RAD[i_RAD].n_RAD.num_RAD, (j_RAD + 1), tables_RAD[i_RAD].n_RAD.num_table_RAD[j_RAD]);
		}
	}
	return(0);
}







	
