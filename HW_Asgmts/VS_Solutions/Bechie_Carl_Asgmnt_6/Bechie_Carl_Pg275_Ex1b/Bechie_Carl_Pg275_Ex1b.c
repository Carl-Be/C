/************************************************************************
* FILE NAME: Bechie_Carl_Pg274_Ex9.c                                    *
* Student: Carl Bechie                                                  *
* Class: CNR 10777 CIS265                                               *
*                                                                       *
* PURPOSE:Reads a messages from stdin and reverses it.                  *
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
* <stdio.h>     printf(), getchar()                                     *
*                                                                       *
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:          *
*                                                                       *
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:                               *
*                                                                       *
* NOTES: Compiled with VS 2019                                          *
*                                                                       *
* REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:                    *
*                                                                       *
* DEVELOPMENT HISTORY:                                                  *
*                                                                       *
* Date          Author      Change Id Release     Description Of Change *
* -----       ---------     -----------------     --------------------- *
* 10/03/2020  Carl Bechie        1.0              Start/Finish          *
*                                                                       *
* ALGORITHM (PDL)                                                       *
*                                                                       *
************************************************************************/

/* Include global parameters */
#include <stdio.h> /* standard C lib for I/O */

/* initialize Defines */
#define CHAR_ARRAY_BUFFER (int)1024/*Buffer size for user input*/ 

/* Declare Prototypes */
void array_null_initialzer(char* message_pointer, char* message);/*Initialize array elements to null byte*/
void take_user_input(char* message_pointer);/*Takes the user input*/
void print_reversal(char* message_pointer, char* message);/*Print the reversal output*/


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
   
    char message[CHAR_ARRAY_BUFFER];/*Declear array*/
    char* message_pointer = message;/*Setting the array pointer*/

    array_null_initialzer(message_pointer, &message);/*Initialize array elements to null byte*/
    take_user_input(message_pointer);/*Takes the user input*/
    print_reversal(message_pointer, &message);/*Print the reversal output*/

    return 0; /*Terminate program with normal status code*/

}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: array_null_initialzer                                  *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
* message_pointer char*                     Pointer for message array   *
*                                           indexing.                   *
* message         char*                     Pointer to index 0 of       *
*                                           message array.              *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void array_null_initialzer(char* message_pointer, char* message)
{
    /*initialze the array elements to null*/
    for (message_pointer; message_pointer < message + CHAR_ARRAY_BUFFER; message_pointer++)
    {
        *message_pointer = NULL;
    }

    /*point message_pointer back to the starting memory address of the message array*/
    message_pointer = message;

}
/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: take_user_input                                        *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
* message_pointer char*                     Pointer for message array   *
*                                           indexing.                   *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void take_user_input(char* message_pointer)    /*Taking user input*/
{
    char c; /*holds user char input*/

    printf("Enter a message: ");/*Asking for user input*/

    while ((c = getchar()) != '\n')/*Get user input*/
    {
        *(message_pointer)++ = c;/*Place inputted char into array at message pointer index*/
    }

}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: print_reversal                                         *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
* message_pointer char*                     Pointer for message array   * 
*                                           indexing.                   *
* message         char*                     Pointer to index 0 of       *
*                                           message array.              *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void print_reversal(char* message_pointer, char* message)
{
    /*point message_pointer to end of the message array*/
    message_pointer = &message[CHAR_ARRAY_BUFFER - 1];

    /*Print the message backwards*/
    printf("Reversal is: ");
    for (message_pointer; message_pointer >= message; message_pointer--)
    {
        printf("%c", *message_pointer);
    }

    printf("\n"); /*print new line for console readability*/
}
/************************************************************************/