#include<stdio.h>
struct Rectangle
{
	struct MyPoint
	{
		int x_RAD;
		int y_RAD;
	}	point_01_RAD, point_02_RAD;
}rect = { {2, 3}, {5, 6} };
int main(void)
{
	//variable declarations
	int length_RAD, breadth_RAD, area_RAD;

	//code
	length_RAD = rect.point_02_RAD.y_RAD - rect.point_01_RAD.y_RAD;
	if (length_RAD < 0)
		length_RAD = length_RAD * -1;

	breadth_RAD = rect.point_02_RAD.y_RAD - rect.point_01_RAD.x_RAD;
	if (breadth_RAD < 0)
		breadth_RAD = breadth_RAD * -1;

	area_RAD = length_RAD * breadth_RAD;

	printf("\n\n");
	printf("Length of Rectangle = %d\n\n", length_RAD);
	printf("Breadth of Rectangle = %d\n\n", breadth_RAD);
	printf("Area of Rectangle = %d\n\n", area_RAD);

	return(0);
}

