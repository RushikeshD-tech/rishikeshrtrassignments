#include <stdio.h>
//DEFINING STRUCT
struct MyPoint
{
	int x_RAD;
	int y_RAD;
};
//DEFINING STRUCT
struct MyPointProperties
{
	int quadrant_RAD;
	char axis_location_RAD[10];
};
int main(void)
{
	//variable declarations
	struct MyPoint point; //declaring a single variable of type 'struct MyPoint' locally...
	struct MyPointProperties point_properties; //declaring a single variable of type 'struct MyPointProperties' locally...
		//code
		//User Input For The Data Members Of 'struct MyPoint' variable 'point_A'
		
	printf("\n\n");
	printf("Enter X-Coordinate For A Point : ");
	scanf("%d", &point.x_RAD);
	printf("Enter Y-Coordinate For A Point : ");
	scanf("%d", &point.y_RAD);
	printf("\n\n");
	printf("\n\nPoint Co-ordinates (x, y) Are : (%d, %d) !!!", point.x_RAD, point.y_RAD);
	if (point.x_RAD == 0 && point.y_RAD == 0)
		printf("\nThe Point Is The Origin (%d, %d) !!!", point.x_RAD, point.y_RAD);
	else // Atleast One of the two values (either 'X' or 'Y' or BOTH) is a nonzero value...
	{
		if (point.x_RAD == 0) // If 'X' IS ZERO...OBVIOUSLY 'Y' IS THE NON-ZERO VALUE
		{
			if (point.y_RAD < 0) // If 'Y' IS -ve
				strcpy(point_properties.axis_location_RAD, "Negative Y");
			if (point.y_RAD > 0) // If 'Y' IS +ve
				strcpy(point_properties.axis_location_RAD, "Positive Y");
			point_properties.quadrant_RAD = 0; // A Point Lying On Any Of The Coordinate Axes Is NOT A Part Of ANY Quadrant...
				printf("\n\nThe Point Lies On The %s Axis !!!", point_properties.axis_location_RAD);
		}
		else if (point.y_RAD == 0) // If 'Y' IS ZERO...OBVIOUSLY 'X' IS THE NON-ZERO VALUE
		{
		if (point.x_RAD < 0) // If 'X' IS -ve
		strcpy(point_properties.axis_location_RAD, "Negative X");
		if (point.x_RAD > 0) // If 'X' IS +ve
		strcpy(point_properties.axis_location_RAD, "Positive X");
		point_properties.quadrant_RAD = 0; // A Point Lying On Any Of The Coordinate Axes Is NOT A Part Of ANY Quadrant...
		printf("\n\nThe Point Lies On The %s Axis !!!",point_properties.axis_location_RAD);
		}
		else // BOTH 'X' AND 'Y' ARE NON-ZERO
		{
			point_properties.axis_location_RAD[0] = '\0'; // A Point Lying In ANY Of The 4 Quadrants Cannot Be Lying On Any Of The Co - ordinate Axes...
				if (point.x_RAD > 0 && point.y_RAD > 0) // 'X' IS +ve AND 'Y' IS +ve
					point_properties.quadrant_RAD = 1;
				else if (point.x_RAD < 0 && point.y_RAD > 0) // 'X' IS -ve AND 'Y' IS +ve
					point_properties.quadrant_RAD = 2;
				else if (point.x_RAD < 0 && point.y_RAD < 0) // 'X' IS -ve AND 'Y' IS -ve
					point_properties.quadrant_RAD = 3;
				else // 'X' IS +ve AND 'Y' IS -ve
					point_properties.quadrant_RAD = 4;
			printf("\n\nThe Point Lies In Quadrant Number %d !!!", point_properties.quadrant_RAD);
		}
	}
	return(0);
}



