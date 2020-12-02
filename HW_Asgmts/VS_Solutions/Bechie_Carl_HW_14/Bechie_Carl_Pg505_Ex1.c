/************************************************************************
* FILE NAME: Bechie_Carl_Pg505_Ex1.c                                    *
* Student: Carl Bechie                                                  *
* Class: CNR 10777 CIS265                                               *
*                                                                       *
* PURPOSE:                                                              *
* The main driver of the program.                                       *
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
* "queue.h"     insert_int(), remove_int(), display_first()             *
*               display_last(), display_size(), Item                    *
*                                                                       *
* <stdio.h>      scanf(), printf(), getc()                              *                                                      
*                                                                       *
* REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:                    *
*    Pre-Processor - _CRT_SECURE_NO_WARNINGS                            *
*                                                                       *
* DEVELOPMENT HISTORY:                                                  *
*                                                                       *
* Date          Author      Change Id Release     Description Of Change *
* -----       ---------     -----------------     --------------------- *
* 11/30/2020  Carl Bechie        1.0              First Edit/Finish     *
*                                                                       *
* ALGORITHM (PDL)                                                       *
*                                                                       *
************************************************************************/

/*Includes*/
#include <stdbool.h>/*C basic logic lib (true / false)*/
#include <stdio.h>/*Standard C I/O lib*/
#include "queue.h"/*My Queue lib*/



/*Defines*/
#define MIN_MENU (int) 1 /*Minimum value of the menu option user input*/
#define MAX_MENU (int) 6 /*Maximum value of the menu option user input*/

/*Prototypes*/
_Bool  check_input(Item item, int min, int max);/*Checks to see if user input is proper*/
void clear_stdin();/*Clears the standard input stream*/
void display_menu();/*Displays a menu to the user*/
void get_input(Item* item);/*Gets user input*/
void select_option(Item* item, queue* q);/*Starts the selected user function*/

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
* void                                                                  *
*                                                                       *
************************************************************************/
static int count_main = 0;

void main()
{
	queue* q1 = create_queue();/*Create queue object*/

	while (1 == 1)/*Infinite loop. Loop breaks and exits program with select_option(6)*/
	{
		/*
			Using an array to mark bad input so we dont input a newline or null char into the Queue on accident.

			item[0] = User Input 
			item[1] = Bad input marker.  Values can be 0 or 1. 0 = no bad input. 1 = bad input.

		*/
		Item item[] = { 0, 0 };
		display_menu();
		get_input(item);

		if (item[1] == 1) /*If bad input skip rest of loop and start over.*/
		{
			continue;
		}

		/*If  true bad input do not do selection statement. User needs to select bewteen MIN_MENU and MAX_MENU*/
		if (check_input(item[0], MIN_MENU, MAX_MENU))
		{
			/*Do nothing. Go through the loop agian. check_input() displays Error message.*/
		}
		else
		{
			select_option(item, q1);/*input is good.*/
		}
	}
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: check_input                                            *
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

_Bool check_input(Item item, int min, int max)
{
	/*
	Checks user input is within the acceptable range.
	*/

	if (item < min || item > max)
	{
		printf("\nInput not valid try agian (only select one number bewteen %d - %d).\n", min, max);
		clear_stdin();
		return true;
	}
	else
	{
		return false;
	}

}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: clear_stdin                                            *
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

void clear_stdin()
{
	/*Clears the standard input stream*/

	int ch;

	while ((ch = getc(stdin)) != '\n');
}

/************************************************************************/

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

	printf("\n1 - Insert an integer item to the end of the queue\n" \
	       "2 - Remove an integer item from the beginning of the queue\n" \
	       "3 - Display first item in the queue\n" \
	       "4 - Display last item in the queue\n" \
	       "5 - Display the count of items in the queue\n" \
		   "6 - Quit the program\n" \
           "Selection: ");
	
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: get_input                                              *
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

void get_input(Item* item)
{
	/*Gets user input. Since this program just uses the int data type we can use scanf instead of getc.*/
	

    int returned_values  = scanf(" %d", item);

	if (item[0] == 0 && returned_values == 0)
	{
		printf("\nBad input.\n");

		clear_stdin();
		item[1] = 1; /*Mark bad input*/
	}
	
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: select_option                                          *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
*  num             int                      Users selected menu option  *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void select_option(Item* item, queue* q)
{
      /*Starts the selected user function*/

	switch (item[0])
	{
		case 1:
			 
			printf("Enter Number: ");/*Asking for input*/
			item[0] = 0;/*Reset index 0 to int 0*/
			item[1] = 0;/*Reset index 1 to int 0*/
			get_input(item);/*Getting user input*/
			if(item[1] == 1) /*bad input break*/
			{
				break;
			}
			insert_item(q, item[0]);/*Inserting num into queue*/
			clear_stdin();/*Clear standard input*/
			break;
		case 2: 
			remove_item(q);
			break;
		case 3: 
			display_front(q);
			break;
		case 4:
			display_rear(q); 
			break;
		case 5:
			display_size(q);
			break;
		case 6:
			printf("Goodbye!\n");
			exit(0);/*Terminate program under normal conditions*/
			break;
		default:
			return;
	}
}