#include<stdio.h>

int main(void)
{
	//variable declarations
	int a_RAD;
	int b_RAD;
	int c_RAD;
	int result_RAD;

	//code
	printf("\n\n");
	printf("Enter First Interger : ");
	scanf("%d", &a_RAD);

	printf("\n\n");
	printf("Enter Sceond Interger : ");
	scanf("%d", &b_RAD);

	printf("\n\n");
	printf("Enter Third Integer : ");
	scanf("%d", &c_RAD);

	printf("\n\n");
	printf("If Answer = 0, It Is 'FALSE' .\n");
	printf("If Answer = 1, It Is 'TRUE' .\n\n");

	result_RAD = (a_RAD <= b_RAD) && (b_RAD != c_RAD);
	printf("LOGICAL AND (&&) : Answer is TRUE (1) If And Only If Both Conditions Are True. The Answer is FALSE (0), If Any One Or Both Conditions Are False.\n\n");
	printf("A = %d IS Less Than Or Equal To B = %d AND B = %d Is NOT Equal To C = %d    \t Answer = %d\n\n", a_RAD, b_RAD, b_RAD, c_RAD, result_RAD);

	result_RAD = (b_RAD >= a_RAD) || (a_RAD == c_RAD);
	printf("LOGICAL OR (||) : Answer is FALSE (0) If And Only If Both Conditions Are False. The Answer is TRUE (1), If And Only If Both Conditions Are True.\n\n");
	printf("Either B =%d Is Greater Than Or Equal To A = %d OR A = %d Is Equal To C = %d \t Answer = %d\n\n", b_RAD, a_RAD, a_RAD, c_RAD, result_RAD);

	result_RAD = !a_RAD;
	printf("A = %d And Using Logical NOT (!) Operator on A Gives Result = %d\n\n", a_RAD, result_RAD);

	result_RAD = !b_RAD;
		printf("B = %d And Using Logical NOT (!) Operator On B Gives Result = %d\n\n", b_RAD, result_RAD);

	result_RAD = !c_RAD;
		printf("C = %d And using Logical NOT (!) Operators On C Gives Result = %d\n\n", c_RAD, result_RAD);

	result_RAD = (!(a_RAD <= b_RAD) && !(b_RAD != c_RAD));
	printf("Using Logical NOT (!) On (a <= b) And  Also On (b != c) And then ANDING THEM Afterwards Gives Result = %d\n", result_RAD);

	printf("\n\n");

	result_RAD = !((b_RAD >= a_RAD) || (a_RAD == c_RAD));
	printf("Using Logical NOT (!) On Entire Logical Expression (b >= a) || (a == c) Gives Result = %d\n", result_RAD);

	printf("\n\n");

	return(0);
}








