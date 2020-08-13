#include<stdio.h>

//DEFINING STRUCT ...
struct MyPoint
{
	int x_RAD;
	int y_RAD;
}	point_A_RAD, point_B_RAD, point_C_RAD, point_D_RAD, point_E_RAD;
	int main(void)
	{
		//code
		//Assiging Data Values To Data Members Of 'struct MyPoint' variable 'point_A'
		point_A_RAD.x_RAD = 3;
		point_A_RAD.y_RAD = 0;


		//Assigning Data Values To Te Data Members Of 'struct MyPoint'variable 'point_A'
		point_B_RAD.x_RAD = 1;
		point_B_RAD.y_RAD = 2;

        //Assigning Data Values To The Data Members Of 'struct MyPoint'variable 'point_B'
		point_C_RAD.x_RAD = 9;
		point_C_RAD.y_RAD = 6;

		//Assigning Data Values To The Data Members Of 'struct MyPoint' variable 'point_D'
		point_D_RAD.x_RAD = 8;
		point_D_RAD.y_RAD = 2;


		//Assigning Data Values To The Data Members Of 'struct MyPoint' variable 'point_E'
		point_E_RAD.x_RAD = 11;
		point_E_RAD.y_RAD = 8;

		//Displaying Data Values To The Member of 'struct MyPoint' (all variables)
		printf("\n\n");
		printf("Co-ordinates (x, y) of Point 'A' Are : (%d, %d)\n\n", point_A_RAD.x_RAD, point_A_RAD.y_RAD);
		printf("Co-ordinates (x, y) of Point 'B' Are : (%d, %d)\n\n", point_B_RAD.x_RAD, point_B_RAD.y_RAD);
		printf("Co-ordinates (x, y) of Point 'C' Are : (%d, %d)\n\n", point_C_RAD.x_RAD, point_C_RAD.y_RAD);
		printf("Co-ordinates (x, y) of Point 'D' Are : (%d, %d)\n\n", point_D_RAD.x_RAD, point_D_RAD.y_RAD);
		printf("Co-ordinates (x, y) of Point 'E' Are : (%d, %d)\n\n", point_E_RAD.x_RAD, point_E_RAD.y_RAD);

		return(0);
	}

