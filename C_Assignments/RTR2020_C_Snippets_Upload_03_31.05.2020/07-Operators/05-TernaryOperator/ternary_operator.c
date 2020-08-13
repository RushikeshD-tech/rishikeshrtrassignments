#include<stdio.h>

int main(void)
{
	//Variable declarations
	int a_RAD, b_RAD;
	int p_RAD, q_RAD;
	char ch_result_RAD_01, ch_result_RAD_02;
	int i_result_RAD_01, i_result_RAD_02;

	//code
	printf("\n\n");

	a_RAD = 7;
	b_RAD = 5;
	ch_result_RAD_01 = (a_RAD > b_RAD) ? 'A' : 'B';
	i_result_RAD_01 = (a_RAD > b_RAD) ? a_RAD : b_RAD;
	printf("Ternary Operator Answer 1 -----%c and %d.\n\n", ch_result_RAD_01, i_result_RAD_01);

	p_RAD = 30;
	q_RAD = 30;
	ch_result_RAD_02 = (p_RAD != q_RAD) ? 'P' : 'Q';
	i_result_RAD_02 = (p_RAD != q_RAD) ? p_RAD : q_RAD;
	printf("Ternary Operator Answer 2 ------%c and %d.\n\n", ch_result_RAD_02, i_result_RAD_02);

	printf("\n\n");
	return(0);

}



