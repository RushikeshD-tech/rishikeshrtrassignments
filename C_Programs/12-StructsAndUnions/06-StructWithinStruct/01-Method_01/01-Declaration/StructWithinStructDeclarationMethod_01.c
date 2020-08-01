#include <stdio.h>
struct Rectangle
{
	struct MyPoint
	{
		int x_RAD;
		int y_RAD;
	} 
	point_01_RAD, point_02_RAD;
} 
rect_RAD;
int main(void)
{
	//variable declarations
	int length_RAD, breadth_RAD, area_RAD;
	//code
	printf("\n\n");
	printf("Enter Leftmost X-Coordinate Of Rectangle : ");
	scanf("%d", &rect_RAD.point_01_RAD.x_RAD);
	printf("\n\n");
	printf("Enter Bottommost Y-Coordinate Of Rectangle : ");
	scanf("%d", &rect_RAD.point_01_RAD.y_RAD);
	printf("\n\n");
	printf("Enter Rightmost X-Coordinate Of Rectangle : ");
	scanf("%d", &rect_RAD.point_02_RAD.x_RAD);
	printf("\n\n");
	printf("Enter Topmost Y-Coordinate Of Rectangle : ");
	scanf("%d", &rect_RAD.point_02_RAD.y_RAD);
	length_RAD = rect_RAD.point_02_RAD.y_RAD - rect_RAD.point_01_RAD.y_RAD;
	if (length_RAD < 0)
		length_RAD = length_RAD * -1;
	breadth_RAD = rect_RAD.point_02_RAD.x_RAD - rect_RAD.point_01_RAD.x_RAD;
	if (breadth_RAD < 0)
		breadth_RAD = breadth_RAD * -1;
	area_RAD = length_RAD * breadth_RAD;
	printf("\n\n");
	printf("Length Of Rectangle = %d\n\n", length_RAD);
	printf("Breadth Of Rectangle = %d\n\n", breadth_RAD);
	printf("Area Of Rectangle = %d\n\n", area_RAD);
	return(0);
}

