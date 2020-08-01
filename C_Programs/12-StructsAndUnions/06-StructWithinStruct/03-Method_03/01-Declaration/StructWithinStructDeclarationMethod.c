#include <stdio.h>
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
	}rect;

	//code
	printf("\n\n");
	printf("Enter Leftmost X-Coordinate Of Rectangle :  ");
	scanf("%d", &rect.point_01.y_RAD);

	printf("\n\n");
	printf("Enter Bottommost Y-Coordinates Of Rectangle : ");
	scanf("%d", &rect.point_01.y_RAD);

	printf("\n\n");
	printf("Enter Rightmost X-Coordinate Of Rectangle : ");
	scanf("%d", &rect.point_02.x_RAD);

	printf("\n\n");
	printf("Enter Topmost Y-Coordinate Of Rectangle : ");
	scanf("%d", &rect.point_02.y_RAD);

	length_RAD = rect.point_02.y_RAD - rect.point_01.y_RAD;
	if (length_RAD < 0)
		length_RAD = length_RAD * -1;

	breadth_RAD = rect.point_02.x_RAD - rect.point_01.x_RAD;
	if (breadth_RAD < 0)
		breadth_RAD = breadth_RAD * -1;

	area_RAD = length_RAD * breadth_RAD;

	printf("\n\n");
	printf("\n\nLength Of Rectangle = %d ", length_RAD);
	printf("\n\nBreadth Of Rectangle = %d ", breadth_RAD);
	printf("\n\nArea Of Rectangle = %d", area_RAD);

	return(0);
}


