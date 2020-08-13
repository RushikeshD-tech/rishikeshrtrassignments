#include<stdio.h>

int main(void)
{
     //variable declarations
    int a_RAD;
    int b_RAD;
    int result_RAD;

     //code
    printf("\n\n");
    printf("Enter One Integer : ");
    scanf("%d", &a_RAD);

    printf("\n\n");
    printf("Enter Another Integer : ");
    scanf("%d", &b_RAD);

    printf("\n\n");
    printf("\nIf Answer = 0, It Is 'FALSE'.");
    printf("\n\nIf Answer = 1, It Is  'TRUE'.");

    result_RAD = (a_RAD < b_RAD);
    printf("\n(a < b) A = %d Is Less Than B = %d                \t Answer = %d", a_RAD, b_RAD, result_RAD);

    result_RAD = (a_RAD > b_RAD);
    printf("\n(a > b) A = %d Is Greater Than  B = %d            \t Answer = %d", a_RAD, b_RAD, result_RAD);

    result_RAD = (a_RAD <= b_RAD);
    printf("\n(a <= b) A = %d Is Less Than Or Equal To B = %d   \t Answer = %d", a_RAD, b_RAD, result_RAD);

    result_RAD = (a_RAD >= b_RAD);
    printf("\n(a >= b) A = %d Is Greater Than Or Equal To B = %d\t Answer = %d", a_RAD, b_RAD, result_RAD);

    result_RAD = (a_RAD == b_RAD);
    printf("\n(a == b) A = %d Is Equal To B = %d                \t Answer = %d", a_RAD, b_RAD, result_RAD);

    result_RAD = (a_RAD != b_RAD);
    printf("\n(a != b) A = %d Is NOT Equal To B = %d            \t Answer = %d", a_RAD, b_RAD, result_RAD);

    return(0);
} 


