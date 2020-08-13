#include <stdio.h>

struct MyPoint
{
	int x_RAD;
	int y_RAD;
};
struct MyPoint point_A_RAD, point_B_RAD, point_C_RAD, point_D_RAD, point_E_RAD; 

int main(void)
{
	//code


	point_A_RAD.x_RAD = 3;
	point_A_RAD.y_RAD = 0;


	point_B_RAD.x_RAD = 1;
	point_B_RAD.y_RAD = 2;


	point_C_RAD.x_RAD = 9;
	point_C_RAD.y_RAD = 6;

	point_D_RAD.x_RAD = 8;
	point_D_RAD.y_RAD = 2;


	point_E_RAD.x_RAD = 11;
	point_E_RAD.y_RAD = 8;

	printf("\n\n");
	printf("Co-ordinates (x, y) Of Point 'A' Are : (%d, %d)\n\n", point_A_RAD.x_RAD, point_A_RAD.y_RAD);
	printf("Co-ordinates (x, y) Of Point 'B' Are : (%d, %d)\n\n", point_B_RAD.x_RAD, point_B_RAD.y_RAD);
	printf("Co-ordinates (x, y) Of Point 'C' Are : (%d, %d)\n\n", point_C_RAD.x_RAD, point_C_RAD.y_RAD);
	printf("Co-ordinates (x, y) Of Point 'D' Are : (%d, %d)\n\n", point_D_RAD.x_RAD, point_D_RAD.y_RAD);
	printf("Co-ordinates (x, y) Of Point 'E' Are : (%d, %d)\n\n", point_E_RAD.x_RAD, point_E_RAD.y_RAD);

	return(0);
}
