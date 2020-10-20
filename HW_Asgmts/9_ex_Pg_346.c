#include <stdio.h> /*Standard C Lib*/ 
#include <math.h> /*Math Lib*/

#define CHECK(x, y, n) (x > 0 && y > 0 && x < (n - 1) && y < (n - 1)) ? (int) 1 : (int) 0
#define MEDIAN(x, y, z) ((y < x && y > z) || (y < z && y > x)) ? y : ((x < y && x > z) || (x < z && x > y)) ? x : ((z < x && z > y) || (z < y && z > x)) ? z : '!'
#define POLYNOMIAL(x) (double) ((3 * (pow(x, 5))) + (2 * (pow(x, 4))) - (5 * (pow(x, 3))) - (pow(x, 2)) + (7 * x) - (6))

/*Prototypes*/
void display_menu();
int selections();
void check();
void median();
void polynomial();

int main(void)
{
	int selection = 0;
	
	do{
		
		display_menu();
		selection = selections();

	}while(selection != 4);

	return 0;
}

/**************************************************************************/

void display_menu()
{
	printf("\n*****************************\n");
	printf("Main Menu:\n");
	printf("1 : Check\n");
	printf("2 : Median\n");
	printf("3 : Polynomial\n");
	printf("4 : Quit\nEnter Item: ");
}

/**************************************************************************/

int selections()
{
	int selection = 0;
	scanf("%d", &selection);
	
	switch(selection)
	{
		case 1:
			check();
			break;
		case 2:
			median();
			break;
		case 3:
			polynomial();
			break;
		case 4:
			break;
		default:
			printf("Not a valid input.\n");
	}

	return selection;
}

/**************************************************************************/

void check()
{
	double x, y, n = 0;
	printf("\nEnter Three Numbers (ie. 9 4 5): ");
	scanf("%lf %lf %lf", &x, &y, &n);

	if(CHECK(x, y, n)) /*Returns 1 or 0*/
	{
		printf("Within bounds of '0 and n - 1' \n");
	}else
	{
		printf("Not within bounds of '0 and n - 1'\n");
	}
}

/**************************************************************************/

void median()
{
	int x, y, z = 0;
	printf("\nEnter Three Numbers (ie. 9 4 5): ");
	scanf("%d %d %d", &x, &y, &z);

	int median = MEDIAN(x, y, z);

	if((char) median == '!')  
	{
		printf("No MEDIAN Found \n");
	}
	else
	{
		printf("Median = %d \n", median);
	}
}

/**************************************************************************/

void polynomial()
{
	double x = 0.0;

	printf("\nEnter Number: ");
	scanf("%lf", &x);

	printf("Polynomial = %f\n", POLYNOMIAL(x));	
}



