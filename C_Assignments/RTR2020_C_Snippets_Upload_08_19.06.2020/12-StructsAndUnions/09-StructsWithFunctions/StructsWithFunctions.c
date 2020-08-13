#include <stdio.h>

//DEFINING STRUCT
struct MyData
{
	int i_RAD;
	float f_RAD;
	double d_RAD;
	char c_RAD;

};

int main(void)
{
	//function prototype
	struct MyData AddStructMembers(struct MyData, struct MyData, struct MyData);

	//variable declarations
	struct MyData data1, data2, data3, answer_data;

	//code
	//***data1***
	printf("\n\n\n\n\n");
	printf("***********DATA 1**********\n\n");
	printf("Enter Integer Value For 'i' of 'struct MyData data1' :");
	scanf("%d", &data1.i_RAD);

	printf("\n\n");
	printf("Enter 'Double' Value For 'f' of 'struct MyData data1' :");
	scanf("%f", &data1.f_RAD);

	printf("\n\n");
	printf("Enter Floating-point Value For 'd' of  'struct MyData data1' :");
	scanf("%lf", &data1.d_RAD);

	printf("\n\n");
	printf("Enter Character Value For 'c' of 'struct MyData data1' :");
	data1.c_RAD = getch();
	printf("%c", data1.c_RAD);

	//***data2****
	printf("\n\n\n\n");
	printf("*****************DATA 2**************\n\n");
	printf("Enter Integer Value For 'i' Of 'struct MyData data2' :");
	scanf("%d", &data2.i_RAD);

	printf("\n\n");
	printf("Enter 'Double Value For 'f' Of 'struct MyData data2' :");
	scanf("%f", &data2.f_RAD);

	printf("\n\n");
	printf("Enter Character Value For 'd' Of 'struct MyData data2' : ");
	//data2.c_RAD = getch();
	scanf("%lf", &data2.d_RAD);
	

	printf("\n\n");
	printf("Enter Character Value For 'c' Of 'struct MyData data2' : ");
	data2.c_RAD = getch();
	printf("%c", data2.c_RAD);

	//***data3****
	printf("\n\n\n\n");
	printf("*****************DATA 3 *******************\n\n");
	printf("Enter Floating Value For 'i' of 'struct Mydata data3' : ");
	scanf("%d", &data3.i_RAD);

	printf("\n\n");
	printf("Enter Floating-Point Value For 'f' Of 'struct MyData data3' :");
	scanf("%f", &data3.f_RAD);

	printf("\n\n");
	printf("Enter Floating-Point Value For 'd' of 'struct MyData data3' :");
	scanf("%lf", &data3.d_RAD);

	printf("\n\n");
	printf("Enter Character Value For 'c' Of 'struct MyData data3' : ");
	data3.c_RAD = getch();
	printf("%c", data3.c_RAD);

	answer_data = AddStructMembers(data1, data2, data3);

	printf("\n\n\n\n");
	printf("********** ANSWER *********\n\n");
	printf("answer_data.i = %d\n", answer_data.i_RAD);
	printf("answer_data.f = %f\n", answer_data.f_RAD);
	printf("answer_data.d = %lf\n\n", answer_data.d_RAD);

	answer_data.c_RAD = data1.c_RAD;
	printf("answer_data.c (from data1) = %c\n\n", answer_data.c_RAD);
	answer_data.c_RAD = data2.c_RAD;
	printf("answer_data.c (from data2) = %c\n\n", answer_data.c_RAD);
	answer_data.c_RAD = data3.c_RAD;
	printf("answer_data.c (from data3) = %c\n\n", answer_data.c_RAD);
	return(0);

}

struct MyData AddStructMembers(struct MyData md_one, struct MyData md_two, struct MyData md_three)
{
	//variable declarations

	struct MyData answer;
	//code
	answer.i_RAD = md_one.i_RAD + md_two.i_RAD + md_three.i_RAD;
	answer.f_RAD = md_one.f_RAD + md_two.f_RAD + md_three.f_RAD;
	answer.d_RAD = md_one.d_RAD + md_two.d_RAD + md_three.d_RAD;
	return(answer);




}

