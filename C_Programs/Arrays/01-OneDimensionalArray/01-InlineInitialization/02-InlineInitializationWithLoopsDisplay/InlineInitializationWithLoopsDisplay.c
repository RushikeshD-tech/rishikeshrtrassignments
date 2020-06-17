#include <stdio.h>
int main(void)
{
	//variable declaration
	int iArray_RAD[] = { 9, 30, 6, 12, 98, 95, 20, 23, 2, 45 };
	int int_size_RAD;
	int iArray_size_RAD;
	int iArray_num_elements_RAD;

	float fArray_RAD[] = { 1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f, 7.8f, 8.9f };
	int float_size_RAD;
	int fArray_size_RAD;
	int fArray_num_elements_RAD;

	char cArray_RAD[] = { 'A', 'S','T', 'R','O','M','E','D','I','C','O','M','P' };
	int char_size_RAD;
	int cArray_size_RAD;
	int cArray_num_elements_RAD;

	int i_RAD;

	//code
	//****************iArray***********
	printf("\n\n");
	printf("In-Line Initilalization And Loop (For) Display of Elements of Array 'iArray[]':\n\n");

	int_size_RAD = sizeof(int);
	iArray_size_RAD = sizeof(iArray_RAD);
	iArray_num_elements_RAD = iArray_size_RAD / int_size_RAD;

	for (i_RAD = 0; i_RAD < iArray_num_elements_RAD; i_RAD++)
	{
		printf("iArray[%d] (Element %d)   = %d\n", i_RAD, (i_RAD + 1), iArray_RAD[i_RAD]);
	}
	printf("\n\n");
	printf("Size of Data type 'int'                           = %d bytes\n", int_size_RAD);
	printf("Number of Elements In 'int' Array 'iArray[]'      = %d Elements\n", iArray_num_elements_RAD);
	printf("Size Of Array 'iArray' (%d Elements * %d Bytes)  = %d Bytes\n\n", iArray_num_elements_RAD, int_size_RAD, iArray_size_RAD);

	//**********fArray**************
	printf("\n\n");
	printf("In-line Intialization And Loop (while) Display of Elements of Array 'fArray[]' :  \n\n");
	float_size_RAD = sizeof(float);
	fArray_size_RAD = sizeof(fArray_RAD);
	fArray_num_elements_RAD = fArray_size_RAD / float_size_RAD;

	i_RAD = 0;
	while (i_RAD < fArray_num_elements_RAD)
	{
		printf("fArray[%d] (Element %d)  = %f\n", i_RAD, (i_RAD + 1), fArray_RAD[i_RAD]);
		i_RAD++;
	}
	printf("\n\n");
	printf("Siaze Of Data type 'float' Array[] 'fArray[]'      = %d bytes\n", float_size_RAD);
	printf("Number Of Element In 'float' Array 'fArray[]'      = %d Elements\n", fArray_num_elements_RAD);
	printf("In-line Initialization And loop (do while) Display of Elements of Array 'cArray[]' : \n\n");

	char_size_RAD = sizeof(char);
	cArray_size_RAD = sizeof(cArray_RAD);
	cArray_num_elements_RAD = cArray_size_RAD / char_size_RAD;

	i_RAD = 0;

			do
	{
		printf("cArray[%d] (Element %d) = %c\n", i_RAD, (i_RAD + 1), cArray_RAD[i_RAD]);
		i_RAD++;
	} while (i_RAD < cArray_num_elements_RAD);

	printf("\n\n");
	printf("Size of Data type 'char'                           = %d bytes\n", char_size_RAD);
	printf("Number Of Elements In 'char' Array 'cArray[]'       = %d Elements\n", cArray_num_elements_RAD);
	printf("Size of Array 'cArray[]' (%d Elements * %d Bytes)     = %d Bytes \n\n", cArray_num_elements_RAD,char_size_RAD, cArray_size_RAD);

	return(0);

}
