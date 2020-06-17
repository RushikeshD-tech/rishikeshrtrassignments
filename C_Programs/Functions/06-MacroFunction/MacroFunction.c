#include <stdio.h>
#define MAX_NUMBER(a, b) ((a > b) ? a : b)

int main(int argc, char* argv[], char* envp[])
{
	//variable declration
	int iNum_01_RAD;
	int iNum_02_RAD;
	int iResult_RAD;

	float fNum_01_RAD;
	float fNum_02_RAD;
	float fResult_RAD;

	//code
	//*********COMPARING INTEGER VALUES***********
	printf("\n\n");
	printf("Enter An Integer Number : \n\n ");
	scanf("%d", &iNum_01_RAD);

	printf("\n\n");
	printf("Enter Another Integer Number : \n\n");
	scanf("%d", &iNum_02_RAD);

	iResult_RAD = MAX_NUMBER(iNum_01_RAD, iNum_02_RAD);
	printf("\n\n");
	printf("Result of Macro Function MAX_NUMBER() = %d\n", iResult_RAD);

	printf("\n\n");

	//***********COMPAIRING FLOATING-POINT VALUES*********
	printf("\n\n");
	printf("Enter Floating Point Number :  \n\n");
	scanf("%f", &fNum_01_RAD);


	printf("\n\n");
	printf("Enter Another Floating Point Number : \n\n");
	scanf("%f", &fNum_02_RAD);


	fResult_RAD = MAX_NUMBER(fNum_01_RAD, fNum_02_RAD);
	printf("\n\n");
	printf("Result of Macro Function MAX_NUMBER() = %f", fResult_RAD);

	printf("\n\n");

	return(0);   


}