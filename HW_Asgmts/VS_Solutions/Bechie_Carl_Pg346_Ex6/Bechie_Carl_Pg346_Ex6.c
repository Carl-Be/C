/************************************************************************
* FILE NAME: Bechie_Carl_Pg346_Ex6.c                                    *
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
* <stdio.h>     printf()                                                *
*                                                                       *
* <math.h>      sqrt()                                                  *
*                                                                       *
* <string.h>    strcmp()                                                *  
*                                                                       *
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:          *
*                                                                       *
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
#include <stdio.h> /*Standard C I/O lib*/
#include <math.h> /*Math Lib*/
#include <string.h> /*String Lib*/ 

/*Defines*/

/*sqrts x*/
#define DISP(f,x) printf("sqrt(%g) = %g\n", x, f(x));

/*compares two strings*/
#define DISP2(f,x,y) printf("strcmp(%s, %s) = %d\n", x, y, f(x, y));

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
	DISP(sqrt, 3.0);/*Call macro*/
	DISP2(strcmp, "batt", "bat");/*Call macro*/

	return 0;
}