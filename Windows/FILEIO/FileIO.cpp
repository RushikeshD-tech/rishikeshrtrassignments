#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	//local variable declarations
	FILE * pFile = NULL;
	//code
	if (fopen_s(&pFile, "RADLog.txt", "w") != 0)
	{
		printf("\nCan Not Open Desired File");
		exit(0);

	}
	fprintf(pFile, "\nINDIA IS MY COUNTRY");
	fclose(pFile);
	pFile = NULL;
	return(0);

}