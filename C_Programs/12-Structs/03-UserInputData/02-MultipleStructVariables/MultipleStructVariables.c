#include <stdio.h>
struct MyPoint
{
	int x_RAD;
	int y_RAD;
};
int main(void)
{
	//variable declarations
	struct MyPoint point_A_RAD, point_B_RAD, point_C_RAD, point_D_RAD, point_E_RAD; //declaring a 5 struct variables
		//code
		//User Input For The Data Members Of 'struct MyPoint' variable 'point_A'
	printf("\n\n");
	printf("Enter X-Coordinate For Point 'A' : ");
	scanf("%d", &point_A_RAD.x_RAD);
	printf("Enter Y-Coordinate For Point 'A' : ");
	scanf("%d", &point_A_RAD.y_RAD);
	//User Input For The Data Members Of 'struct MyPoint' variable 'point_B'
	printf("\n\n");
	printf("Enter X-Coordinate For Point 'B' : ");
	scanf("%d", &point_B_RAD.x_RAD);
	printf("Enter Y-Coordinate For Point 'B' : ");
	scanf("%d", &point_B_RAD.y_RAD);
	//User Input For The Data Members Of 'struct MyPoint' variable 'point_C'
	printf("\n\n");
	printf("Enter X-Coordinate For Point 'C' : ");
	scanf("%d", &point_C_RAD.x_RAD);
	printf("Enter Y-Coordinate For Point 'C' : ");
	scanf("%d", &point_C_RAD.y_RAD);
	//User Input For The Data Members Of 'struct MyPoint' variable 'point_D'
	printf("\n\n");
	printf("Enter X-Coordinate For Point 'D' : ");
	scanf("%d", &point_D_RAD.x_RAD);
	printf("Enter Y-Coordinate For Point 'D' : ");
	scanf("%d", &point_D_RAD.y_RAD);
	//User Input For The Data Members Of 'struct MyPoint' variable 'point_E'
	printf("\n\n");
	printf("Enter X-Coordinate For Point 'E' : ");
	scanf("%d", &point_E_RAD.x_RAD);
	printf("Enter Y-Coordinate For Point 'E' : ");
	scanf("%d", &point_E_RAD.y_RAD);
	//Displaying Values Of The Data Members Of 'struct MyPoint' (all variables)
	printf("\n\n");
	printf("\n\nCo-ordinates (x, y) Of Point 'A' Are : (%d, %d)", point_A_RAD.x_RAD, point_A_RAD.y_RAD);
	printf("\n\nCo-ordinates (x, y) Of Point 'B' Are : (%d, %d)", point_B_RAD.x_RAD, point_B_RAD.y_RAD);
	printf("\n\nCo-ordinates (x, y) Of Point 'C' Are : (%d, %d)", point_C_RAD.x_RAD, point_C_RAD.y_RAD);
	printf("\n\nCo-ordinates (x, y) Of Point 'D' Are : (%d, %d)", point_D_RAD.x_RAD, point_D_RAD.y_RAD);
	printf("\n\nCo-ordinates (x, y) Of Point 'E' Are : (%d, %d)", point_E_RAD.x_RAD, point_E_RAD.y_RAD);
	return(0);
}



