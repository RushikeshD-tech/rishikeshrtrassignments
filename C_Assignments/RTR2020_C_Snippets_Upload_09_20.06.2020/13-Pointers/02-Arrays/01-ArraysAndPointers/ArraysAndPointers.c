#include <stdio.h>
int main(void)
{
	//variable declarations
	int iArray_RAD[] = { 12, 24, 36, 48, 60, 72, 84, 96, 108, 120 };
	float fArray_RAD[] = { 9.8f, 8.7f, 7.6f, 6.5f, 5.4f };
	double dArray_RAD[] = { 1.222222, 2.333333, 3.444444 };
	char cArray_RAD[] = { 'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M','P', '\0' };
	//code
	printf("\n\n");
	printf("Integer Array Elements And The Addresses They Occupy Are As Follows :\n\n");
	printf("iArray[0] = %d \t At Address : %p\n", *(iArray_RAD + 0), (iArray_RAD + 0));
	printf("iArray[1] = %d \t At Address : %p\n", *(iArray_RAD + 1), (iArray_RAD + 1));
	printf("iArray[2] = %d \t At Address : %p\n", *(iArray_RAD + 2), (iArray_RAD + 2));
	printf("iArray[3] = %d \t At Address : %p\n", *(iArray_RAD + 3), (iArray_RAD + 3));
	printf("iArray[4] = %d \t At Address : %p\n", *(iArray_RAD + 4), (iArray_RAD + 4));
	printf("iArray[5] = %d \t At Address : %p\n", *(iArray_RAD + 5), (iArray_RAD + 5));
	printf("iArray[6] = %d \t At Address : %p\n", *(iArray_RAD + 6), (iArray_RAD + 6));
	printf("iArray[7] = %d \t At Address : %p\n", *(iArray_RAD + 7), (iArray_RAD + 7));
	printf("iArray[8] = %d \t At Address : %p\n", *(iArray_RAD + 8), (iArray_RAD + 8));
	printf("iArray[9] = %d \t At Address : %p\n", *(iArray_RAD + 9), (iArray_RAD + 9));
	printf("\n\n");
	printf("Float Array Elements And The Addresses They Occupy Are As Follows : \n\n");
	printf("fArray[0] = %f \t At Address : %p\n", *(fArray_RAD + 0), (fArray_RAD + 0));
	printf("fArray[1] = %f \t At Address : %p\n", *(fArray_RAD + 1), (fArray_RAD + 1));
	printf("fArray[2] = %f \t At Address : %p\n", *(fArray_RAD + 2), (fArray_RAD + 2));
	printf("fArray[3] = %f \t At Address : %p\n", *(fArray_RAD + 3), (fArray_RAD + 3));
	printf("fArray[4] = %f \t At Address : %p\n", *(fArray_RAD + 4), (fArray_RAD + 4));
	printf("\n\n");
	printf("Double Array Elements And The Addresses They Occupy Are As Follows :\n\n");
	printf("dArray[0] = %lf \t At Address : %p\n", *(dArray_RAD + 0), (dArray_RAD + 0));
	printf("dArray[1] = %lf \t At Address : %p\n", *(dArray_RAD + 1), (dArray_RAD + 1));
	printf("dArray[2] = %lf \t At Address : %p\n", *(dArray_RAD + 2), (dArray_RAD + 2));
	printf("\n\n");
	printf("Character Array Elements And The Addresses They Occupy Are As	Follows : \n\n");
	printf("cArray[0] = %c \t At Address : %p\n", *(cArray_RAD + 0), (cArray_RAD + 0));
	printf("cArray[1] = %c \t At Address : %p\n", *(cArray_RAD + 1), (cArray_RAD + 1));
	printf("cArray[2] = %c \t At Address : %p\n", *(cArray_RAD + 2), (cArray_RAD + 2));
	printf("cArray[3] = %c \t At Address : %p\n", *(cArray_RAD + 3), (cArray_RAD + 3));
	printf("cArray[4] = %c \t At Address : %p\n", *(cArray_RAD + 4), (cArray_RAD + 4));
	printf("cArray[5] = %c \t At Address : %p\n", *(cArray_RAD + 5), (cArray_RAD + 5));
	printf("cArray[6] = %c \t At Address : %p\n", *(cArray_RAD + 6), (cArray_RAD + 6));

	printf("cArray[7] = %c \t At Address : %p\n", *(cArray_RAD + 7), (cArray_RAD + 7));
	printf("cArray[8] = %c \t At Address : %p\n", *(cArray_RAD + 8), (cArray_RAD + 8));
	printf("cArray[9] = %c \t At Address : %p\n", *(cArray_RAD + 9), (cArray_RAD + 9));
	printf("cArray[10] = %c \t At Address : %p\n", *(cArray_RAD + 10), (cArray_RAD + 10));
	printf("cArray[11] = %c \t At Address : %p\n", *(cArray_RAD + 11), (cArray_RAD + 11));
	printf("cArray[12] = %c \t At Address : %p\n", *(cArray_RAD + 12), (cArray_RAD + 12));
	printf("cArray[13] = %c \t At Address : %p\n", *(cArray_RAD + 13), (cArray_RAD + 13));
	
	return(0);
}
