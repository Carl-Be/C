/************************************************************************
* FILE NAME: Bechie_Carl_Asgmnt_9.c                                     *
* Student: Carl Bechie                                                  *
* Class: CNR 10777 CIS265                                               *
*                                                                       *
* PURPOSE:                                                              *
* Take user input and sort it with strcmp() using bubble sorting.       *   
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
* <stdlib.h>    malloc(), exit()                                        *
* <string.h>    strcmp(), strcpy()                                      *
*                                                                       *
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:          *
*                                                                       *
* Abnormal Termination Conditions: malloc() returns a NULL pointer.     *   
*                                                                       *
* Error Message: "FAILED TO ALLOCATE MEMORY".                           *
*                                                                       *
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:                               *
*                                                                       *
* Assumption: No word can be longer then 20 chars long.                 *
*                                                                       *
* NOTES: Did not use _s functions                                       *
*                                                                       *
* REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:                    *
*                                                                       *
* Add Preprocessor Definition: _CRT_SECURE_NO_WARNINGS                  *
*                                                                       *
* DEVELOPMENT HISTORY:                                                  *
*                                                                       *
* Date          Author      Change Id Release     Description Of Change *
* -----       ---------     -----------------     --------------------- *
* 10/15/2020  Carl Bechie        1.0              First Edit            *
* 10/16/2020  Carl Bechie        1.0              Finished              *
*                                                                       *
* ALGORITHM (PDL)                                                       *
*                                                                       *
************************************************************************/

/*Includes*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Defines*/
#define MAX_LEN (int) 20 /*Max word length*/
#define MAX_ROWS (int) 100 /*Max word list length*/

/*Prototypes*/
void add_words(char** words,const char* word, int i);/*Adds word to word list*/

void display_words(int word_count ,char** words);/*Displays results to user*/

void sort_words(int word_count, char** words, char* word);/*Bubble sorts the words*/

void take_word(char* word);/*Takes input from the user*/

/*************************************************************************************************************************************************************/

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
	int sentinal_val = 1;/*Used to stop the while loop*/
	char* words[MAX_ROWS];/*Declear array*/
	char* word = malloc(MAX_LEN + 1);/*Initialize array with allocated space*/

	int word_count = 0;/*number of words*/

	while (sentinal_val)/*When sentinal_val == 0 exit loop*/
	{
		take_word(word);/*Get the word from the user*/
		sentinal_val = *word;/*Once word returns empty (ie. '\0' == 0) end the loop*/
		
		if (sentinal_val != 0)/*What sentinal_val is not 0 add words to word list*/
		{
			add_words(words, word, word_count);/*Add the words to the words array*/
			word_count++;/*Increment to the next index of the words array */
		}
	}

	sort_words(word_count, words, word);/*Sort the array of string pointers*/
	display_words(word_count, words);/*Display the results to the user*/

	return 0;/*Return normal termination code*/
}

/*************************************************************************************************************************************************************/

/*************************************************************************
*                                                                        *
* FUNCTION NAME: add_words                                               *
*                                                                        *
* ARGUMENT LIST:                                                         *
*                                                                        *
* ARGUMENT        TYPE       I/O          DESCRIPTION                    *
* --------        ----       ---          -----------                    *
* words           char**      I           The array the holds the users  *
*                                         input.                         *
*                                                                        *
* word      const char*       O           The string array to be copied  *
*                                         into the words array.          *
*                                                                        *
* i                int                    Correct index of the words     *
*                                         array to add the word array to *
*                                                                        *
* RETURNS:                                                               *
* void                                                                   *
*                                                                        *
*************************************************************************/

void add_words(char** words, const char* word, int i)
{
	/*Add word to the pointer of string pointers array name words*/

	words[i] = malloc(strlen(word) + 1);/*Allocate space for the string using the heap*/
	if (words[i] == NULL)/*Print error message to user if words[i] == NULL.*/
	{
		printf("\nFAILED TO ALLOCATE MEMORY.\n");/*Show error message*/
		exit(EXIT_FAILURE);/*Exit Program*/
	}

	strcpy(words[i], word);/*Copy strings into word list*/
}

/*************************************************************************************************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: display_words                                          *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O           DESCRIPTION                  *
* --------        ----       ---           -----------                  *
* word_count      int                      Helps the for loop to not go *
*                                          out of bounds on the indexing*
*                                                                       *
* words           char**      O            The sorted array to be       *
*                                          the displayed to the user.   *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void display_words(int word_count, char** words)
{
	/*Displays the now sorted list to the user*/

	printf("\nIn sorted order: ");
	for (int i = 0; i < word_count ; i++)/*Increments through the words array indexes displaying the words*/
	{
		printf("%s ", words[i]);/*Print words*/
	}
	puts(" ");/*Print new-line for readability*/
}

/*************************************************************************************************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: sort_word                                              *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
* word_count      int                       Used to make sure for loops *
*                                           stay inbounds with indexing.* 
*                                                                       *
* words           char**                    The array that gets bubble  *
*                                           sorted.                     *
*                                                                       *
* stored_word    char*                      Temporarily holds the word  * 
*                                           thats currently being bubble*
*                                           sorted so that its not over-*
*                                           written and lost.           *
*                                                                       *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void sort_words(int word_count, char** words, char* stored_word)
{
	/*Sort function using bubble sorting*/

	for (int i = 0; i < word_count; i++)
	{
		/*Tried to be fancy at first but remembered I forgot about K.I.S.S */
		for (int j = i; j < word_count; j++)
		{
			if (strcmp(words[i], words[j]) > 0)/*If the words[j] is less then words[i] start bubble sort rotation*/
			{
				strcpy(stored_word, words[i]);/*Copy current word into sorted_word string array for safe keeping*/
				strcpy(words[i], words[j]);/*Copy smaller word into larger word position*/
				strcpy(words[j], stored_word);/*Recover larger word from memory location and place it back into the array at the smaller words old index.*/
			}
		}
	}
}

/*************************************************************************************************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: take_word                                              *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
*  word           char*       I             String array to hold user   *
*                                           input.                      *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void take_word(char* word)
{
	/*Takes input from the user*/

	int ch = 0;/*Holds the inputed values from the user*/

	printf("Enter word: ");/*Prompt for user input*/
	while ((ch = getchar()) != '\n')/*If users presses the 'Return' key loop ends*/
	{
		*word++ = (char)ch;/*Put the char at the pointers memory location. Incerment ptr*/
	}

	*word = '\0';/*Add a null string to the end of the char array to make it a string (literal)*/
}
