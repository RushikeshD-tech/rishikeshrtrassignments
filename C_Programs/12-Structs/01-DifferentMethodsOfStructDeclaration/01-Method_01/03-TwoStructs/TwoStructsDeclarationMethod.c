#include <stdio.h>

struct MyPoint
{
	int x_RAD;
	int y_RAD;
} point;

struct MyPointProperties
{
	int quadrant_RAD;
	char axis_location_RAD[10];
}point_properties;

int main(void)
{
	//code
	printf("\n\n");
	printf("Enter X-Coordinate for A point : ");
	scanf("%d", &point.x_RAD);
	printf("Enter Y-Coordinate For A point : ");
	scanf("%d", &point.y_RAD);

	printf("\n\n");
	printf("Point Co-Ordinates (x, y) Are : (%d, %d)!!!\n\n", point.x_RAD, point.y_RAD);

	if (point.x_RAD == 0 && point.y_RAD == 0)
		printf("The Point Is The Origin (%d, %d) !!!\n", point.x_RAD, point.y_RAD);
	else
	{
		if (point.x_RAD == 0)
		{
			if (point.y_RAD < 0)
				strcpy(point_properties.axis_location_RAD, "Negative Y");
			if (point.y_RAD > 0)
				strcpy(point_properties.axis_location_RAD, "Positive Y");

			point_properties.quadrant_RAD = 0;

			printf("The Point Lies On The %s Axis !!!\n\n", point_properties.axis_location_RAD);
		}
		else if (point.y_RAD == 0)
		{
			if (point.x_RAD < 0)
				strcpy(point_properties.axis_location_RAD, "Negative X");

			if (point.x_RAD > 0)
				strcpy(point_properties.axis_location_RAD, "Positive Y");

			point_properties.quadrant_RAD = 0;
			printf("The Point Lies On The %s Axis!!!\n\n", point_properties.axis_location_RAD);
		}
		else if (point.y_RAD == 0)
		{
			if (point.x_RAD < 0)
				strcpy(point_properties.axis_location_RAD, "Negative X");

			if (point.x_RAD > 0)
				strcpy(point_properties.axis_location_RAD, "Positive X");

			point_properties.quadrant_RAD = 0;
			printf("The Point Lies on The %s Axies !!!\n\n", point_properties.axis_location_RAD);
		}
		else
		{
			point_properties.axis_location_RAD[0] = '\0';

			if (point.x_RAD > 0 && point.y_RAD > 0)
				point_properties.quadrant_RAD = 1;

			else if (point.x_RAD < 0 && point.y_RAD > 0)
				point_properties.quadrant_RAD = 2;

			else if (point.x_RAD < 0 && point.y_RAD < 0)
				point_properties.quadrant_RAD = 3;

			else
				point_properties.quadrant_RAD = 4;
			printf("The point Lies In Quadrant Number %d !!!\n\n", point_properties.quadrant_RAD);
		}
	}

	return(0);
}
		
	
