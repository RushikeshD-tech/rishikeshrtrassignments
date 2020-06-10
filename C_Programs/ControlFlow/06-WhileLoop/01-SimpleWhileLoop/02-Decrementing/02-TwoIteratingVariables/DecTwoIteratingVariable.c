int main(void)
{
	//variable declarations
	int i_RAD, j_RAD;
	//code
	printf("\n\n");
	printf("Printing Digits 10 to 1 and 100 to 10: \n\n");
	i_RAD = 10;
	j_RAD = 100;
	while (i_RAD >= 1, j_RAD >= 10)
	{
		printf("\t %d \t %d\n", i_RAD, j_RAD);
		i_RAD--;
		j_RAD = j_RAD - 10;
	}
	printf("\n\n");
	return(0);
}



