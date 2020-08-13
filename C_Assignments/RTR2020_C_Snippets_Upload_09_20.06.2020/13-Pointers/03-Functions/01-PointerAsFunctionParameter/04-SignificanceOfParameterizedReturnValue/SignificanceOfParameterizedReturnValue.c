#include <stdio.h>
enum
{
	NEGATIVE = -1,
	ZERO,
	POSITIVE
};
int main(void)
{
	//function declarations
	int Difference(int, int, int*);
	//variable declaration
	int a_RAD;
	int b_RAD;
	int answer_RAD, ret_RAD;
	//code
	printf("\n\n");
	printf("Enter Value Of 'A' : ");
	scanf("%d", &a_RAD);
	printf("\n\n");
	printf("Enter Value Of 'B' : ");
	scanf("%d", &b_RAD);
	ret_RAD = Difference(a_RAD, b_RAD, &answer_RAD);
	printf("\n\n");
	printf("Difference Of %d And %d = %d\n\n", a_RAD, b_RAD, answer_RAD);
	if (ret_RAD == POSITIVE)
		printf("The Difference Of %d And %d Is Positive !!!\n\n", a_RAD, b_RAD);
	else if (ret_RAD == NEGATIVE)
		printf("The Difference Of %d And %d Is Negative !!!\n\n", a_RAD, b_RAD);
	else
		printf("The Difference Of %d And %d Is Zero !!!\n\n", a_RAD, b_RAD);
	return(0);

}
int Difference(int x_RAD, int y_RAD, int* diff_RAD)
{
	//code
	*diff_RAD = x_RAD - y_RAD;
	if (*diff_RAD > 0)
		return(POSITIVE);
	else if (*diff_RAD < 0)
		return(NEGATIVE);
	else
		return(ZERO);
}





