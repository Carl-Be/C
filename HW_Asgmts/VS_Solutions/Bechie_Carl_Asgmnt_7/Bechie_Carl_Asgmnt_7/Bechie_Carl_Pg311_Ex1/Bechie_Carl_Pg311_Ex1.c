/************************************************************************
* FILE NAME: Bechie_Carl_Pg311_Ex1.c                                    *
* Student: Carl Bechie                                                  *
* Class: CNR 10777 CIS265                                               *
*                                                                       *
* PURPOSE:                                                              *
* Finds the smallest and largest in a series of words inputted by the   *
* user.                                                                 *
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
* <stdio.h>      getchar(), printf()                                    *
* <string.h>     strlen(), strcmp(), strncpy_s()                        *
*                                                                       *
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:          *
*                                                                       *                                      
* ABNORMAL TERMINATION CONDITION - Word length of four letters.         * 
*                                                                       *      
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:                               *
*                                                                       *
* ASSUMPTION - No word is longer then 20 chars                          *
*                                                                       *
* NOTES:                                                                *
*                                                                       *
* REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:                    *
*  Visual Studio 2019 IDE for edits.                                    * 
*                                                                       *
* DEVELOPMENT HISTORY:                                                  *
*                                                                       *
* Date          Author      Change Id Release    Description Of Change  *
* -----       ---------     -----------------    ---------------------  *
* 10/06/2020  Carl Bechie        1.0             First Edit             *
* 10/07/2020  Carl Bechie        1.0             Finished Logic control *
*                                                                       *
* ALGORITHM (PDL)                                                       *
*                                                                       *
************************************************************************/


/* Include global parameters */
#include <stdio.h> /* standard C lib for I/O */
#include <string.h> /*standard C lig for string operations*/

/* initialize Defines */
#define MAX_WORD_LEN (int)20 /*This is the max length that any string can be*/
#define SENTINEL_LEN_VAL (int)4 /*Used to see if the word inputted equals this length if so terminate program*/

/* Declare Prototypes */
void get_word(char* word);/*gets the input the user*/
void clear_word(char* word);/*clears the array before next word is inputted*/
void cmp_words(const char* word, char* biggest, char* smallest);/*compares the words.*/

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
    char word[MAX_WORD_LEN + 1] = {'\0'};
    char smallest[MAX_WORD_LEN + 1] = {'\0'};
    char biggest[MAX_WORD_LEN + 1] = {'\0'};

    /*This while loop controls the program*/
    while (strlen(word) != SENTINEL_LEN_VAL)
    {
        clear_word(word);
        get_word(word);
        cmp_words(word, biggest, smallest);
    }

    /*Display results */
    printf("\nSmallest word: %s\n", smallest);
    printf("Largest word: %s\n", biggest);

    return 0; /* Terminate program with normal status code */

}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: get_word                                               *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O          DESCRIPTION                   *
* --------        ----       ---          -----------                   *
*  word           char*       I           pointer to word arrary start  *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/
void get_word(char* word) 
{
    /*Takes user input to set the string array words*/
        int ch = 0;/*Needed to place the user input into the word array*/
        printf("Enter word: ");

        while ((ch = getchar()) != '\n')
        {
            *word++ = ch;
        }

        *word = '\0'; /*Place null byte at end of word array*/
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: clear_word                                             *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O          DESCRIPTION                   *
* --------        ----       ---          -----------                   *
*  word           char*                   pointer to word array start   *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void clear_word(char* word)
{   
    /*Clears the word array so it can be used again properly*/
    while (*word != '\0')/*could also be "while(*word)" but this is easier to read*/
    {
        *word++ = '\0';
    }
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: cmp_words                                              *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O          DESCRIPTION                   *
* --------        ----       ---          -----------                   *
* word       const char*                  pointer to word array start   *
*                                                                       * 
* biggest         char*                   pointer to the start of the   * 
*                                         array that holds the biggest  *
*                                         word                          *
*                                                                       *
* smallest        char*                   pointer to the start of the   *
*                                         array that holds the smallest *
*                                         word                          *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void cmp_words(const char* word, char* biggest, char* smallest)
{
    /*This function sets the string arrays to the correct words*/

    if (smallest[0] == '\0') 
    {
     /*If it is equal biggest and smallest both need to be initalized properly
       since it is the first cycle through the while loop that calls this 
       function. So the program can have a baseline starting point for comparing 
       the strings accurately.*/

        strncpy_s(smallest, MAX_WORD_LEN + 1, word, MAX_WORD_LEN + 1);
        strncpy_s(biggest, MAX_WORD_LEN + 1, word, MAX_WORD_LEN + 1);
    }
    else if (strcmp(word, smallest) < 0) 
    {
     /*current word is smaller then smallest word set new smallest word to current word*/
        strncpy_s(smallest, MAX_WORD_LEN + 1,word, MAX_WORD_LEN + 1);
    }
    else if (strcmp(word, biggest) > 0)
    {
     /*current word is larger than biggest word set new biggest word to current word*/
        strncpy_s(biggest, MAX_WORD_LEN + 1,word, MAX_WORD_LEN + 1);
    }

}
