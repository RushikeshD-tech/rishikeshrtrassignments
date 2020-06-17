#include <stdio.h>
int main(void)
{
	// Variable Declaration
	int iArray_RAD[] = { 9, 30, 6, 12, 98, 95, 20, 23, 2, 45 };
	int int_size_RAD;
	int iArray_size_RAD;
	int iArray_num_elements_RAD;

	float fArray_RAD[] = { 1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f, 7.8f, 8.9f };
	int float_size_RAD;
	int fArray_size_RAD;
	int fArray_num_elements_RAD;

	char cArray_RAD[] = { 'A', 'S', 'T', 'R' , 'O' , 'M' , 'E', 'D' , 'I' , 'C' , 'O' , 'M' , 'P' };
	int char_size_RAD;
	int cArray_size_RAD;
	int cArray_num_elements_RAD;

	//code

	//**********iArray[]**************
	printf("\n\n");
	printf("In-line Innitialization And Piece-meal Display Of Elements Of Array 'iArray[]' : \n\n");
	printf("iArray[0] (1st Element)  = %d\n", iArray_RAD[0]);
	printf("iArray[1] (2nd Element)  = %d\n", iArray_RAD[1]);
	printf("iArray[2] (3rd Element)  = %d\n", iArray_RAD[2]);
	printf("iArray[3] (4th Element)  = %d\n", iArray_RAD[3]);
	printf("iArray[4] (5th Element)  = %d\n", iArray_RAD[4]);
	printf("iArray[5] (6th Element)  = %d\n", iArray_RAD[5]);
	printf("iArray[6] (7th Element)  = %d\n", iArray_RAD[6]);
	printf("iArray[7] (8th Element)  = %d\n", iArray_RAD[7]);
	printf("iArray[8] (9th Element)  = %d\n", iArray_RAD[8]);
	printf("iArray[9] (10th Element)  = %d\n", iArray_RAD[9]);

	int_size_RAD = sizeof(int);
	iArray_size_RAD = sizeof(iArray_RAD);
	iArray_num_elements_RAD = iArray_size_RAD / int_size_RAD;
	printf("Size of Data Type 'int'                      = %d  bytes\n", int_size_RAD);
	printf("Size Of Data type 'int' Array 'iArray'[]'    = %d  Elements\n", iArray_num_elements_RAD, int_size_RAD, iArray_size_RAD);

	//*******fArray[]********
	printf("\n\n");
	printf("In-line Initialization And Piece-meal Display of Elements of Array 'fArray[]' : \n\n");
	printf("fArray[0] (1st Element)  =%f\n", fArray_RAD[0]);
	printf("fArray[1] (2nd Element)  =%f\n", fArray_RAD[1]);
	printf("fArray[2] (3rd Element)  =%f\n", fArray_RAD[2]);
	printf("fArray[3] (4th Element)  =%f\n", fArray_RAD[3]);
	printf("fArray[4] (5th Element)  =%f\n", fArray_RAD[4]);
	printf("fArray[5] (6th Element)  =%f\n", fArray_RAD[5]);
	printf("fArray[6] (7th Element)  =%f\n", fArray_RAD[6]);
	printf("fArray[7] (8th Element)  =%f\n", fArray_RAD[7]);
	printf("fArray[8] (9th Element)  =%f\n", fArray_RAD[8]);
	printf("fArray[9] (10th Element)  =%f\n", fArray_RAD[9]);
	printf("fArray[10] (11th Element)  =%f\n", fArray_RAD[10]);

	float_size_RAD = sizeof(float);
	fArray_size_RAD = sizeof(fArray_RAD);
	fArray_num_elements_RAD = fArray_size_RAD / float_size_RAD;
	printf("size of Data type 'float'                        =%d bytes\n ", float_size_RAD);
	printf("Number of Elements In 'float' Array 'fArray[]'   =%d Elements\n", fArray_num_elements_RAD);
	printf("Size Of Array 'fArray[]'  (%d Elements * %d Bytes) =%d Bytes \n\n", fArray_num_elements_RAD, float_size_RAD, fArray_size_RAD);

	//******cArray**********

	printf("\n\n");
	printf("In-line Initialization And Piece-meal Display of elemets of Array 'cArray[]': \n\n");

	printf("cArray[0]  (1st Element)    =%c\n", cArray_RAD[0]);
	printf("cArray[1] (2nd Element)     =%c\n", cArray_RAD[1]);
	printf("cArray[2] (3rd Element)     =%c\n", cArray_RAD[2]);
	printf("cArray[3] (4th Element)     =%c\n", cArray_RAD[3]);
	printf("cArray[4] (5th Element)     =%c\n", cArray_RAD[4]);
	printf("cArray[5] (6th Element)     =%c\n", cArray_RAD[5]);
	printf("cArray[6] (7th Element)     =%c\n", cArray_RAD[6]);
	printf("cArray[7] (8th Element)     =%c\n", cArray_RAD[7]);
	printf("cArray[8] (9th Element)     =%c\n", cArray_RAD[8]);
	printf("cArray[9] (10th Element)     =%c\n", cArray_RAD[9]);
	printf("cArray[10] (11th Element)    =%c\n", cArray_RAD[10]);
	printf("cArray[11] (12th Element)    =%c\n", cArray_RAD[11]);
	printf("cArray[12] (13th Element)    =%c\n", cArray_RAD[12]);

	char_size_RAD = sizeof(char);
	cArray_size_RAD = sizeof(cArray_RAD);
	cArray_num_elements_RAD = cArray_size_RAD / char_size_RAD;
	printf("Size of Data type 'char'                         = %d bytes\n", char_size_RAD);
	printf("Number of Elements in 'char' Array 'cArray[]'     = %d Elements\n", cArray_num_elements_RAD);
	printf("Size of Array 'cArray[]'   (%d Elements * %d Bytes) = %d Bytes\n\n", cArray_num_elements_RAD, char_size_RAD, cArray_size_RAD);

	return(0);

}


