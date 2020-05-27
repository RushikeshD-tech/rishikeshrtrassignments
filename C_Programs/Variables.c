#include <stdio.h>

int main(void)
{

    // variable declarations
    int i_RAD = 5;
    float f_RAD = 3.9f;
    double d_RAD = 8.041997;
    char c_RAD = 'A';
    
	//code
    printf("\n\n");
    
    printf("i_RAD = %d\n", i_RAD);
    printf("f_RAD = %f\n", f_RAD);
    printf("d_RAD = %lf\n", d_RAD);
    printf("c_RAD = %c\n", c_RAD);

    printf("\n\n");

    i_RAD = 43;
    f_RAD = 6.54f;
    d_RAD = 26.1294;
    c_RAD = 'P';
    
    printf("i_RAD = %d\n", i_RAD);
    printf("f_RAD = %f\n", f_RAD);
    printf("d_RAD = %lf\n", d_RAD);
    printf("c_RAD = %c\n", c_RAD);

    printf("\n\n");

    return(0);
}



