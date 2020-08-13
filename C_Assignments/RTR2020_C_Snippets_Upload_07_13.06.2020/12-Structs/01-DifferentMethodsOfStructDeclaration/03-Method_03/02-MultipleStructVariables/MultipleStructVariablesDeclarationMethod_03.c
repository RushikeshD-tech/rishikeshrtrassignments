#include <stdio.h>
int main(void)
{
	// DEFINING STRUCT ...
	struct MyPoint
	{
		int x_RAD;
		int y_RAD;
	} point_A_RAD, point_B_RAD, point_C_RAD, point_D_RAD, point_E_RAD;   //Declaring 5 struct variables of type 'struct MyPoint' locally...
		
																		 
	 //code
	//Assigning Data Values To The Data Members Of 'struct MyPoint' variable 'point_A'
        point_A_RAD.x_RAD = 3;
	    point_A_RAD.y_RAD = 0;
	
	//Assigning Data Values To The Data Members Of 'struct MyPoint' variable 'point_B'
	    point_B_RAD.x_RAD = 1;
	    point_B_RAD.y_RAD = 2;
	
	//Assigning Data Values To The Data Members Of 'struct MyPoint' variable 'point_C'
		point_C_RAD.x_RAD = 9;
	    point_C_RAD.y_RAD = 6;
	
	//Assigning Data Values To The Data Members Of 'struct MyPoint' variable 'point_D'
		point_D_RAD.x_RAD = 8;
	    point_D_RAD.y_RAD = 2;
	
	//Assigning Data Values To The Data Members Of 'struct MyPoint' variable 'point_E'
		point_E_RAD.x_RAD = 11;
	    point_E_RAD.y_RAD = 8;
	
	//Displaying Values Of The Data Members Of 'struct MyPoint' (all variables)
	printf("\n\n");
	printf("\n\nCo-ordinates (x, y) Of Point 'A' Are : (%d, %d)", point_A_RAD.x_RAD, point_A_RAD.y_RAD);
	printf("\n\nCo-ordinates (x, y) Of Point 'B' Are : (%d, %d)", point_B_RAD.x_RAD, point_B_RAD.y_RAD);
	printf("\n\nCo-ordinates (x, y) Of Point 'C' Are : (%d, %d)", point_C_RAD.x_RAD, point_C_RAD.y_RAD);
	printf("\n\nCo-ordinates (x, y) Of Point 'D' Are : (%d, %d)", point_D_RAD.x_RAD, point_D_RAD.y_RAD);
	printf("\n\nCo-ordinates (x, y) Of Point 'E' Are : (%d, %d)", point_E_RAD.x_RAD, point_E_RAD.y_RAD);
	return(0);
}



