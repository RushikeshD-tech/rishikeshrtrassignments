#include<stdio.h>

struct MyPoint
{
	int x_RAD;
	int y_RAD;

};
struct Rectangle
{
	struct MyPoint point_01_RAD, point_02_RAD;

};
int main(void)
{
	//variable declarations
	int length_RAD, breadth_RAD, area_RAD;
	struct Rectangle rect_RAD;

	//code
	printf("\n\n");
	printf("Enter Leftmost X-Coordinate of Rectangle : ");
	scanf("%d", &rect_RAD.point_01_RAD.x_RAD);

	printf("\n\n");
	printf("Enter Bottommost Y-Coordinate of Rectangle : ");
	scanf("%d", &rect_RAD.point_01_RAD.y_RAD);

	printf("\n\n");
	printf("Enter Rightmost X-Coordinate of Rectangle : ");
	scanf("%d", &rect_RAD.point_02_RAD.x_RAD);

	printf("\n\n");
	printf("Enter Topmost Y-Coordinate of Rectangle :");
	scanf("%d", &rect_RAD.point_02_RAD.y_RAD);

	length_RAD = rect_RAD.point_02_RAD.y_RAD;
	if (length_RAD < 0)
		length_RAD = length_RAD * -1;

	breadth_RAD = breadth_RAD * -1;

	area_RAD = length_RAD * breadth_RAD;

	printf("\n\n");
	printf("Length of Rectangle = %d\n\n", length_RAD);
	printf("Breadth of Rectangle = %d\n\n", area_RAD);
	printf("Area of Rectangle = %d\n\n", area_RAD);

	return(0);

}

