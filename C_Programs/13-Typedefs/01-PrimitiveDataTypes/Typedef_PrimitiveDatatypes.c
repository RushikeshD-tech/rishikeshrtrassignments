#include <stdio.h>

// Global typedef
typedef int MY_INT; // "type" int has been re"def"ined as MY_INT ... Now, "MY_INT" can be treated just like "int"
int main(void)
{
	// Function prototype
	MY_INT Add(MY_INT, MY_INT);
	// Typedefs
	typedef int MY_INT; // "type" int has been re"def"ined as MY_INT ... Now, "MY_INT" can be treated just like "int"
		typedef float PVG_FLOAT; // "type" float has been re"def"ined as PVG_FLOAT ... Now, "MY_FLOAT" can be treated just like "float"
		typedef char CHARACTER; // "type" char has been re"def"ined as CHARACTER ...Now, "CHARACTER" can be treated just like "char"
		typedef double MY_DOUBLE; // "type" double has been re"def"ined as MY_DOUBLE ... Now, "MY_DOUBLE" can be treated just like "double"
	
								  // ****** JUST LIKE IN Win32SDK !!! ******
	typedef unsigned int UINT;
	typedef UINT HANDLE;
	typedef HANDLE HWND;
	typedef HANDLE HINSTANCE;
	// variable declarations
	MY_INT a_RAD = 10, i_RAD;
	MY_INT iArray_RAD[] = { 9, 18, 27, 36, 45, 54, 63, 72, 81, 90 };
	PVG_FLOAT f_pvg_RAD = 30.9f;
	const PVG_FLOAT f_pvg_pi_RAD = 3.14f;
	CHARACTER ch_RAD = '*';
	CHARACTER chArray_01_RAD[] = "Hello";
	CHARACTER chArray_02_RAD[][10] = { "RTR", "Batch", "2020-2021" };
	MY_DOUBLE d_RAD = 8.041997;
	
	// ****** JUST RANDOM NUMBERS - THEY HAVE NOTHING TO DO WITH ANY WINDOW'S HANDLE OR INSTANCE HANDLE !!!This is just for understanding******
		
	UINT uint = 3456;
	HANDLE handle = 987;
	HWND hwnd = 9876;
	HINSTANCE hInstance = 14466;
	
	// code
	printf("\n\n");
	printf("\nType MY_INT variable a = %d", a_RAD);
	printf("\n\n");
	for (i_RAD = 0; i_RAD < (sizeof(iArray_RAD) / sizeof(int)); i_RAD++)
	{
		printf("\nType MY_INT array variable iArray[%d] = %d", i_RAD, iArray_RAD[i_RAD]);
	}
	printf("\n\n");
	printf("\n\n");
	printf("\nType PVG_FLOAT variable f = %f", f_pvg_RAD);
	printf("\nType PVG_FLOAT constanct f_pvg_pi = %f", f_pvg_pi_RAD);
	printf("\n\n");
	printf("\nType MY_DOUBLE variable d = %lf", d_RAD);
	printf("\n\n");
	printf("\nType CHARACTER variable ch = %c", ch_RAD);
	printf("\n\n");
	printf("\nType CHARACTER array variable chArray_01 = %s", chArray_01_RAD);
	printf("\n\n");
	for (i_RAD = 0; i_RAD < (sizeof(chArray_02_RAD) / sizeof(chArray_02_RAD[0])); i_RAD++)
	{
		printf("%s\t", chArray_02_RAD[i_RAD]);
	}
	printf("\n\n");
	printf("\n\n");
	printf("\n\nType UINT variable uint = %u", uint);
	printf("\n\nType HANDLE variable handle = %u", handle);
	printf("\n\nType HWND variable hwnd = %u", hwnd);
	printf("\n\nType HINSTANCE variable hInstance = %u", hInstance);
	printf("\n\n");
	MY_INT x_RAD = 90;
	MY_INT y_RAD = 30;
	MY_INT ret_RAD;
	ret_RAD = Add(x_RAD, y_RAD);
	printf("\n\nret_RAD = %d", ret_RAD);
	return(0);
}
MY_INT Add(MY_INT a_RAD, MY_INT b_RAD)
{
	// code
	MY_INT c_RAD;
	c_RAD = a_RAD + b_RAD;
	return(c_RAD);
}


