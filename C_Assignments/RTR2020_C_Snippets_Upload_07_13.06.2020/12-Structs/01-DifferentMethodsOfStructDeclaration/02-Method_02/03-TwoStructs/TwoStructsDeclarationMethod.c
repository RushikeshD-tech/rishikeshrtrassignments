#include <stdio.h>

//Defining Struct
struct MyPoint
{
	int x_RAD;
	int y_RAD;

};
//Defining Struct
struct MypointProperties
{
	int quadrant;
	char axis_location[10];

};
struct MyPoint point; //declaring a single variable of type 'struct MyPoint' gloablly..
struct MypointProperties point_properties; //declaring a single variable of type 'struct MyPointProperties' globally...

int main(void)
{
	//code
	//User Input For The Data Members Of 'struct MyPoint ' variable 'point_A' 

	printf("\n\n");
	printf("Enter X-Coordinate For A Point :  ");
     scanf("%d", &point.x_RAD);
	printf("Enter Y-Coordinates For A Point : ");
     scanf("%d", &point.y_RAD);

	printf("\n\n");
	printf("\n\nPoint Co-ordinates (x,y) Are : (&d, &d) !!!", point.x_RAD, point.y_RAD);

	if (point.x_RAD == 0 && point.y_RAD == 0)
		printf("\nThe Point Is The Origin (%d,%d) !!!", point.x_RAD, point.y_RAD);
	else // Atlest One Of the two values (either 'X' or 'Y' or Both) is non-zero value...
	{
		if (point.x_RAD == 0) // If 'X' is zero ...OBVIOUSLY 'Y' is non zero value
		{
			if (point.y_RAD < 0) // If 'Y' is -ve 
				strcpy(point_properties.axis_location, "Negative Y");

			if (point.y_RAD > 0)//If 'Y' is +ve
				strcpy(point_properties.axis_location, "Positive Y");

			point_properties.quadrant = 0; // A point Lying on Any Of the co-ordinate axis is NOT a part of ANY quadrant...
			printf("\nThe point Lies On The %s Axis !!!", point_properties.axis_location);

		}
		else if (point.y_RAD == 0)// If 'Y' is zero  ...OBVIOUSLY 'X' is non zero value
		{
			if (point.x_RAD < 0)//If 'X' is -ve
				strcpy(point_properties.axis_location, "Negative X");

			if (point.x_RAD > 0)// If 'Y' is +ve
				strcpy(point_properties.axis_location, "Positive X");
			
			point_properties.quadrant = 0; // A point Lying on Any Of the co-ordinate axis is NOT a part of ANY quadrant...

			printf("\n\nThe Point Lies On The %s Axis !!!", point_properties.axis_location);

		}
		else // BOTH 'X' AND 'Y' are non-zero
		{
			point_properties.axis_location[0] = '\0'; 

			if (point.x_RAD > 0 && point.y_RAD > 0)
				point_properties.quadrant = 1;

			else if (point.x_RAD < 0 && point.y_RAD > 0)
				point_properties.quadrant = 2;

			else if (point.x_RAD < 0 && point.y_RAD < 0)
				point_properties.quadrant = 3;

			else
				point_properties.quadrant = 4;

			printf("\n\n The Point Lies In quadrant Number %d !!!", point_properties.quadrant);

		}
	}
	return(0);

}


