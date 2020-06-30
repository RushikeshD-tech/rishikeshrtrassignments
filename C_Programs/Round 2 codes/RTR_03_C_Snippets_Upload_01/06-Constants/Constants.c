#include <stdio.h>

#define MY_PI 3.1415926535897932

#define AMC_STRING "AstroMediComp RTR 3.0"


// Un-named enums
enum
{
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
};

enum
{
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

//Named enums
enum Numbers
{
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE = 5,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN
};

enum boolean
{
	TRUE = 1,
	FALSE = 0
};

int main(void)
{
	//local constant declarations
	const double epsilon = 0.000001;

	//code
	printf("\n\n");
	printf("\n\nLocal Constant Epsilon = %lf", epsilon);

	printf("\nSunday Is Day Number = %d", SUNDAY);
	printf("\nMonday Is Day Number = %d", MONDAY);
	printf("\nTuesday Is Day Number = %d", TUESDAY);
	printf("\nWednesday Is Day Number = %d", WEDNESDAY);
	printf("\nThursday Is Day Number = %d", THURSDAY);
	printf("\nFriday Is Day Number = %d", FRIDAY);
	printf("\n\nSaturday Is Day Number = %d", SATURDAY);

	printf("\nOne Is Enum Number = %d", ONE);
	printf("\nTwo Is Enum Number = %d", TWO);
	printf("\nThree Is Enum Number = %d", THREE);
	printf("\nFour Is Enum Number = %d", FOUR);
	printf("\nFive Is Enum Number = %d", FIVE);
	printf("\nSix Is Enum Number = %d", SIX);
	printf("\nSeven Is Enum Number = %d", SEVEN);
	printf("\nEight Is Enum Number = %d", EIGHT);
	printf("\nNine Is Enum Number = %d", NINE);
	printf("\n\nTen Is Enum Number = %d", TEN);

	printf("\n\nJanuary Is Month Number = %d", JANUARY);
	printf("\nFebruary Is Month Number = %d", FEBRUARY);
	printf("\nMarch Is Month Number = %d", MARCH);
	printf("\nApril Is Month Number = %d", APRIL);
	printf("\nMay Is Month Number = %d", MAY);
	printf("\nJune Is Month Number = %d", JUNE);
	printf("\nJuly Is Month Number = %d", JULY);
	printf("\nAugust Is Month Number = %d", AUGUST);
	printf("\nSeptember Is Month Number = %d", SEPTEMBER);
	printf("\nOctober Is Month Number = %d", OCTOBER);
	printf("\nNovember Is Month Number = %d", NOVEMBER);
	printf("\n\nDecember Is Month Number = %d", DECEMBER);

	printf("\nValue Of TRUE Is = %d", TRUE);
	printf("\n\nValue Of FALSE Is = %d", FALSE);

	printf("\n\nMY_PI Macro value = %.10lf", MY_PI);
	printf("\n\nArea Of Circle Of Radius 2 units = %f", (MY_PI * 2.0f * 2.0f)); //pi * r * r = area of circle of radius 'r'

    printf("\n\n");
    
    printf(AMC_STRING);
    printf("\n\n");
    
    printf("\nAMC_STRING is : %s", AMC_STRING);
    printf("\n\n");

    return(0);
}







