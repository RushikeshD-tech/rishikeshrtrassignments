#include <stdio.h>
int main(void)
{
	//variable declarations
	int i_num_RAD, num_RAD, i_RAD;
	//code
	printf("\n\n");
	printf("Enter An Integer Value From Which Iteration Must Begin : ");
	scanf("%d", &i_num_RAD);
	printf("How Many Digits Do You Want To Print From %d Onwards ? : ", i_num_RAD);
	scanf("%d", &num_RAD);
	printf("Printing Digits %d to %d : \n\n", i_num_RAD, (i_num_RAD + num_RAD));
	i_RAD= i_num_RAD;
	while (i_RAD <= (i_num_RAD + num_RAD))
	{
		printf("\t%d\n", i_RAD);
		i_RAD++;
	}
	printf("\n\n");
	return(0);
}