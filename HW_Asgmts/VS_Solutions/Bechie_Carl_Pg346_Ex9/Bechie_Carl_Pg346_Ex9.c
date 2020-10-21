/************************************************************************
* FILE NAME: Bechie_Carl_Pg346_Ex9.c                                    *
* Student: Carl Bechie                                                  *
* Class: CNR 10777 CIS265                                               *
*                                                                       *
* PURPOSE:                                                              *
*                                                                       *
* FILE REFERENCES:                                                      *
*                                                                       *
* Name              I/O                     Description                 *
* ----              ---                     -----------                 *
*                                                                       *
* EXTERNAL VARIABLES:                                                   *
* Source: < >                                                           *
*                                                                       *
* Name        Type            I/O           Description                 *
* -----       ----            ---           -----------                 *
*                                                                       *
* EXTERNAL REFERENCES:                                                  *
*                                                                       *
* Name			Description                                             *
* ----			-----------                                             *
* <stdio.h>     printf(), scanf_s()                                     *
*                                                                       *
* <math.h>      pow()                                                   *
*                                                                       *
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:          *
*                                                                       *
* Warning Message: "Not a valid input."  - Main Menu                    *
*                                                                       *
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:                               *
*                                                                       *
* NOTES:                                                                *
*                                                                       *
* REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:                    *
*                                                                       *
* DEVELOPMENT HISTORY:                                                  *
*                                                                       *
* Date          Author      Change Id Release     Description Of Change *
* -----       ---------     -----------------     --------------------- *
* 10/19/2020  Carl Bechie        1.0              First Edit/Working    *
* 10/20/2020  Carl Bechie        1.0              Added Documentation   *
*                                                                       *
* ALGORITHM (PDL)                                                       *
*                                                                       *
************************************************************************/

/*Includes*/
#include <stdio.h> /*Standard C I/O Lib*/ 
#include <math.h> /*Math Lib*/

/*Defines*/

/*Checks to see if x and y and within bounds of 0 and n - 1*/
#define CHECK(x, y, n) (x > 0 && y > 0 && x < (n - 1) && y < (n - 1)) ? (int) 1 : (int) 0

/*Finds the median of x, y, and z*/
#define MEDIAN(x, y, z) ((y < x && y > z) || (y < z && y > x)) ? y : ((x < y && x > z) || (x < z && x > y)) ? x : ((z < x && z > y) || (z < y && z > x)) ? z : '!'

/*Calculates the polynomial of x*/
#define POLYNOMIAL(x) (double) ((3 * (pow(x, 5))) + (2 * (pow(x, 4))) - (5 * (pow(x, 3))) - (pow(x, 2)) + (7 * x) - (6))

/*Prototypes*/
void display_menu();/*Displays the menu*/
int selections();/*Program runs the users seleceted menu item*/
void check();/*Shows results for the CHECK constant*/
void median();/*Shows results for the MEDIAN constant*/
void polynomial();/*Shows results fot the POLYNOMIAL constant*/

/**************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: main                                                   *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
*  none                                                                 *
*                                                                       *
* RETURNS:                                                              *
* int 0                                                                 *
*                                                                       *
************************************************************************/

int main(void)
{
	int selection = 0;/*Sentinel value var*/

	do {

		display_menu();
		selection = selections();

	} while (selection != 4);/*Exit loop when user selects to quit*/

	return 0;
}

/**************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: display_menu                                           *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
*  none                                                                 *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void display_menu()
{
	/*Displays a menu to the user*/

	printf("\n*****************************\n");
	printf("Main Menu\n");
	printf("1 : Check\n");
	printf("2 : Median\n");
	printf("3 : Polynomial\n");
	printf("4 : Quit\nEnter Item: ");
}

/**************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: selections                                             *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
*  none                                                                 *
*                                                                       *
* RETURNS:                                                              *
* int selection                                                         *
*                                                                       *
************************************************************************/

int selections()
{
	/*Calls the function selected by the user*/

	int selection = 0;
	scanf_s("%d", &selection); 

	switch (selection)
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

/************************************************************************
*                                                                       *
* FUNCTION NAME: check                                                  *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
*  none                                                                 *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void check()
{
	/*Handles the CHECK macro input and output*/

	double x, y, n = 0;
	printf("\nEnter Three Numbers (ie. 9 4 5): ");
	scanf_s("%lf %lf %lf", &x, &y, &n);

	if (CHECK(x, y, n)) /*CHECK returns 1 or 0 aka true or false*/
	{
		printf("Within bounds of '0 and n - 1' \n");
	}
	else
	{
		printf("Not within bounds of '0 and n - 1'\n");
	}
}

/**************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: median                                                 *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
*  none                                                                 *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void median()
{
	/*Handles the MEDIAN macros input and output*/

	int x, y, z = 0;
	printf("\nEnter Three Numbers (ie. 9 4 5): ");
	scanf_s("%d %d %d", &x, &y, &z);

	int median = MEDIAN(x, y, z);

	if (median == '!')/*No median was found*/
	{
		printf("No MEDIAN Found \n");
	}
	else/*Median found*/
	{
		printf("Median = %d \n", median);
	}
}

/**************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: polynomial                                             *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
*  none                                                                 *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void polynomial()
{
	/*Handles the POLYNOMIAL macros input and output*/

	double x = 0.0;

	printf("\nEnter Number: ");
	scanf_s("%lf", &x);

	printf("Polynomial = %f\n", POLYNOMIAL(x));
}


