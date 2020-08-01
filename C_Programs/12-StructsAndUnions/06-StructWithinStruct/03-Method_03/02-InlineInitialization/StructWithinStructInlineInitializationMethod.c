#include<stdio.h>

int main(void)
{
	//variable declarations
	int length_RAD, breadth_RAD, area_RAD;

	struct Rectangle
	{
		struct MyPoint
		{
			int x_RAD;
			int y_RAD;

		}point_01, point_02;
	}rect = { {2, 3}, {5, 6} };

	//code
	length_RAD = rect.point_02.y_RAD - rect.point_01.y_RAD;
	if (length_RAD < 0)
		length_RAD = length_RAD * -1;

	breadth_RAD = rect.point_02.x_RAD - rect.point_01.x_RAD;
	if (breadth_RAD < 0)
		breadth_RAD = breadth_RAD * -1;

	area_RAD = length_RAD * breadth_RAD;

	printf("\n\n");
	printf("Length Of Rectangle = %d\n\n", length_RAD);
	printf("Breadth Of Rectangle = %d\n\n", breadth_RAD);
	printf("Area Of Rectangle = %d\n\n", area_RAD);

	return(0);
}
