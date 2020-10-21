/************************************************************************
* FILE NAME: Bechie_Carl_Pg274_Ex9.c                                    *
* Student: Carl Becie                                                   *
* Class: CNR 10777 CIS265                                               *
*                                                                       *
* PURPOSE:                                                              *
*   Use pointer arithmetic to vistit array elements                     *
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
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:          *
*                                                                       *
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:                               *
*                                                                       *
* NOTES:                                                                *
*  Complied with VS 2019                                                *
*                                                                       *
* REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:                    *
*                                                                       *
* DEVELOPMENT HISTORY:                                                  * 
*                                                                       *
* Date		   Author		Change Id Release     Description Of Change *
* -----       ---------     -----------------     --------------------- *
* 10/2/2020   Carl Bechie        1.0              First Edit            *
* 10/3/2020   Carl Bechie        1.1              Finished              *
*                                                                       *
* ALGORITHM (PDL)                                                       *
*                                                                       *
************************************************************************/

/* Include global parameters */
#include <stdio.h> /* standard C lib for I/O */

/* initialize Defines */
#define N (int)3 /*Length of arrays*/

/* Declare Prototypes */
double inner_product(const double* a, const double* b, int n);

/************************************************************************/

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
    /*initialize arrays*/
    const double a[N] = {2, 3, 7}; 
    const double b[N] = {2, 3, 7};

    /*do arithmetic on arrays*/
    double arrays_summed_product = inner_product(&a, &b, N);
  
    /*display results*/
    printf("arrays_summed = %.2f \n\n", arrays_summed_product);

    return 0; /*Terminate program with normal status code*/

}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: inner_product                                          *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
*  *a            double                     Const arary pointer         *
*  *b            double                     Const array pointer         *
*   n             int                       Length of array in terms of *
*                                           elements.                   *    
*                                                                       *
* RETURNS:                                                              *
* double  a[0] * b[0] +....+ a[n-1] * b[n-1]                            *
*                                                                       *
*                                                                       *
************************************************************************/

double inner_product(const double* a, const double* b, int n) 
{

    double sum_of_products = 0.0;/*Holds the sum of the products*/
    const double* a_pointer = a;/*Point a_pointer at a starting memory location*/
    const double* b_pointer = b;/*Point b_pointer at b starting memory location*/

    for(a_pointer; a_pointer < a + n;)/*a_pointer is incremented below for readability*/
    {
       
        sum_of_products += *a_pointer++ * *b_pointer++; /*Increment through the arrays one index at a time*/
    }

    return sum_of_products;
}

/************************************************************************/