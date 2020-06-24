#include <stdio.h>
int main(void)
{
    //variable declarartions

    int iArray_RAD[5][3][2] = { { {9,18},{27,36},{45,54} },
    { {8,16},{24,32},{40,48} },
    { {7,14},{21,28},{35,42} },
    { {6,12},{18,24},{30,36} },
    { {5,10},{15,20},{25,30} } };

        int int_size_RAD;
    int iArray_size_RAD;
    int iArray_num_elements_RAD, iArray_width_RAD, iArray_height_RAD, iArray_depth_RAD;

    //code
    printf("\n\n");

    int_size_RAD = sizeof(int);

    iArray_size_RAD = sizeof(iArray_RAD);
    printf("Size Of Three Dimensional (3D) Integer Array Is = %d\n\n", iArray_size_RAD);

    iArray_width_RAD = iArray_size_RAD / sizeof(iArray_RAD[0]);
    printf("Number of Rows (width) In Three Dimensional (3D) Integer Array Is = %d\n\n", iArray_height_RAD);

    iArray_depth_RAD = sizeof(iArray_RAD[0][0]) / int_size_RAD;
    printf("Depth In Three Dimensional (3D) Integer Array Is = %d\n\n", iArray_depth_RAD);

    iArray_num_elements_RAD = iArray_width_RAD * iArray_height_RAD * iArray_depth_RAD;
    printf("Number of Elements In Three Dimensional (3D) Integer Array Is = %d\n\n", iArray_num_elements_RAD);

    printf("\n\n");

    printf("Elements In Integer 3D Array : \n\n");

    printf("***********ROW 1***************\n");
    printf("*********COLUMN 1***************\n");
    printf("iArray[0][0][0] = %d\n", iArray_RAD[0][0][0]);
    printf("iArray[0][0][0] = %d\n", iArray_RAD[0][0][0]);
    printf("\n");

    printf("********COLUMN 2 **********\n");
    printf("iArray[0][1][0] = %d\n", iArray_RAD[0][1][0]);
    printf("iArray[0][1][1] = %d\n", iArray_RAD[0][1][1]);
    printf("\n");

    printf("*********COLUMN 3***************\n");
    printf("iArray[0][2][0] = %d\n", iArray_RAD[0][2][0]);
    printf("iArray[0][2][1] = %d\n", iArray_RAD[0][2][1]);
    printf("\n\n");

    printf("*********ROW 2************\n");
    printf("***********COLUMN 1***********\n");
    printf("iArray[1][0][0] = %d\n", iArray_RAD[1][0][0]);
    printf("iArray[1][0][1] = %d\n", iArray_RAD[1][0][1]);
    printf("\n");


    printf("*********COLUMN 2**************\n");
    printf("iArray[1][1][0] = %d\n", iArray_RAD[1][1][0]);
    printf("iArray[1][1][1] = %d\n", iArray_RAD[1][1][1]);
    printf("\n");


    printf("********COLUMN 3*************\n");
    printf("iArray[1][2][0] = %d\n", iArray_RAD[1][2][0]);
    printf("iArray[1][2][1] = %d\n", iArray_RAD[1][2][1]);
    printf("\n\n");

    printf("***********ROW 3************\n");
    printf("*********COLUMN 1**********\n");
    printf("iArray[2][0][0] = %d\n", iArray_RAD[2][0][0]);
    printf("iArray[2][0][1] = %d\n", iArray_RAD[2][0][1]);
    printf("\n");


    printf("**********COLUMN 2***********\n");
    printf("iArray[2][1][0] = %d\n", iArray_RAD[2][1][0]);
    printf("iArray[2][1][1] = %d\n", iArray_RAD[2][1][1]);
    printf("\n");

    printf("***********COLUMN 3***********\n");
    printf("iArray[2][2][0] = %d\n", iArray_RAD[2][2][0]);
    printf("iArray[2][2][1] = %d\n", iArray_RAD[2][2][1]);
    printf("\n\n");

    printf("*************ROW 4 ***********\n");
    printf("**********COLUMN 1***********\n");
    printf("iArray[3][0][0] = %d\n", iArray_RAD[3][0][1]);
    printf("\n");

    printf("*************COLUMN 2************\n");
    printf("iArray[3][1][0] = %d\n", iArray_RAD[3][1][0]);
    printf("iArray[3][1][1] = %d\n", iArray_RAD[3][1][1]);
    printf("\n");

    printf("************COLUMN 3************\n");
    printf("iArray[3][2][0] = %d\n", iArray_RAD[3][2][0]);
    printf("iArray[3][2][1] = %d\n", iArray_RAD[3][2][1]);
    printf("\n\n");

    printf("**************ROW 5*********\n");
    printf("************COLUMN 1************\n");
    printf("iArray[4][2][0] = %d\n", iArray_RAD[4][2][0]);
    printf("iArray[4][2][1] = %d\n", iArray_RAD[4][2][1]);
    printf("\n\n");

    return(0);

}




