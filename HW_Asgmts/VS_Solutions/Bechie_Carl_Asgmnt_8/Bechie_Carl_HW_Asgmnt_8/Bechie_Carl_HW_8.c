/************************************************************************
* FILE NAME: Bechie_Carl_HW_8.c                                         *
* Student: Carl Bechie                                                  *
* Class: CNR 10777 CIS265                                               *
*                                                                       *
* PURPOSE:                                                              *
* Performs several file I/O functions for the supplied CIS265.txt file. *
*                                                                       *
* FILE REFERENCES:                                                      *
*                                                                       *
* Name              I/O                Description                      *
* ----              ---                -----------                      *
* CIS265.txt        I/O                A .txt file that explains        *
*                                      a very high view of C.           *
*                                                                       *
* EXTERNAL VARIABLES:                                                   *
* Source: < >                                                           *
*                                                                       *
* Name        Type            I/O           Description                 *
* -----       ----            ---           -----------                 *
*                                                                       *
* EXTERNAL REFERENCES:                                                  *
*                                                                       *
* Name			Description                                     *
* ----			-----------                                     *
* <stdio.h>     scanf_s(), printf(), getchar(),fopen(),fclose(),        *
*               fscanf(), fgetc()                                       *
*                                                                       *
* <string.h>    strcmp()                                                *
*                                                                       *
* <stdbool.h>   _Bool                                                   *
*                                                                       *
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:          *
*                                                                       *
* Abnormal Termination Condition / Error - File not found.              *
*                                                                       *
* Warning - Enter a proper menu item                                    *
*                                                                       *
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:                               *
*                                                                       *
* NOTES:                                                                *
*                                                                       *
* REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:                    *
*                                                                       *
*  Visual Studio 2019                                                   *
*                                                                       *
* DEVELOPMENT HISTORY:                                                  *
*                                                                       *
* Date          Author      Change Id Release     Description Of Change *
* -----       ---------     -----------------     --------------------- *
* 10/12/2020  Carl Bechie        1.0              First Edit/ Working   *
*                                                                       *
* 10/13/2020  Carl Bechie        1.1              Made the search for   *
*                                                 word function print   *
*                                                 new-lines.            *
*                                                                       *
* ALGORITHM (PDL)                                                       *
*                                                                       *
************************************************************************/

/* Include global parameters */
#include <stdio.h> /* standard C lib for I/O */
#include <stdbool.h> /* standard C lib for boolean */
#include <string.h> /* c string lib */

/* initialize Defines */
#define FILE_NAME "CIS265.txt" /*Name of file*/
#define MAX_WRD_LEN 100 /*Length of the arrarys used throught the program.*/

/* Declare Prototypes */
void append_text(FILE* file_ptr);/*Appends text to the end of the file*/

_Bool check_casing(char selection);/*Checks to see if the input needs to be turned to uppercase*/

_Bool check_input(char selection);/*Checks to see if user input is correct*/

void display_menu();/*Displays the menu*/

void get_word(char* search_word);/*gets the word to search for from the user*/

/*Finds a word in the file and places brackets around it. shows word count of designated word. Any input is valid input for this function.*/
void search_for_word(FILE* file_ptr);

FILE* read_file(char* file_name, char* mode);/*Reads the named file from stdinput stream*/

void reset_word(char* current_word);/*Resest the current word*/

void print_lines(FILE* file_ptr);/*Prints number of lines the the user inputs*/

/*used with the search_for_word function*/
int print_word_logic(char* current_word, char* search_word, int count_word, int ch);

/*This function holds a switch statment that runs the end users menu function selection.*/
void process_selection(char selection);

char take_input();/*Takes input from the user until proper selection is inputed*/


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
   char selection = take_input(); /*Take user input*/

   while (selection != 'Q')/*Quit program when Q(q) is inputed*/
   {
       process_selection(selection);/*Run the function the user inputed*/
       selection = take_input();/*Ask for another function to run from the user*/
   }
   /*test*/
   //printf("\nselection: %c\n", selection);

    return 0; /* Terminate program with normal status code */
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
*                                                                       *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void display_menu()
{
    /*Displays the menu*/

    /*Create the menu display*/
    const char* MENU = \
        "1- Press (S) to search for a word\n"\
        "2- Press (L) to display specified number of text lines to the screen\n"\
        "3- Press (A) to append new content to the file\n"\
        "4- Press (Q) to quit\n\n"\
        "Enter Selection: ";

    printf("%s", MENU);/*Display the menu*/
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: take_input                                             *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
*                                                                       *
*                                                                       *
* RETURNS:                                                              *
* char selection                                                        *
*                                                                       *
************************************************************************/

char take_input()
{
    /*Takes input from user until input is correct (S, L, A, or Q)*/

    char selection;
    _Bool sentinal_val = true;

    do
    {
        display_menu();/*display the menu*/

        /*Note to self Do not read in white space or new line with " %c" while "%c" dose read in white space and new lines*/
        scanf_s(" %c", &selection, 1);

        sentinal_val = check_input(selection);/*check for proper input*/
        
        if (sentinal_val)/*sentinal_val == true*/
        {
            /*if the input value is still true check the casing*/
            sentinal_val = check_casing(selection);

            if (!sentinal_val)/*sentinal_val == false*/
            {
                /*if the casing is the only thing wrong turn selection to uppercase*/
                selection -= ('a' - 'A');
            }
            else/*sentinal_val == true.*/
            { 
                /*else print error message for improper input*/
                printf("\n\nImproper input [%c] please try again with proper input.\n\n", selection);
            }
        }

    } while (sentinal_val);/*Keep going until sentinal_val == False */

    return selection;
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: check_input                                            *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O      DESCRIPTION                       *
* --------        ----       ---      -----------                       *
* selection       char        I       User input value.                 *
*                                                                       *
* RETURNS:                                                              *
* _Bool checked                                                         *
*                                                                       *
************************************************************************/

_Bool check_input(char selection)
{
    /*
    Checks for proper input.
    Proper input that will return checked = false is S, L, A, or Q
    */
    _Bool checked = true;

    if (selection == 'A' || selection == 'L' || selection == 'S' || selection == 'Q')
    {
        checked = false;
    }

    return checked;
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: check_casing                                           *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O      DESCRIPTION                       *
* --------        ----       ---      -----------                       *
* selection       char        I       User input value.                 *
*                                                                       *
* RETURNS:                                                              *
* _Bool checked                                                         *
*                                                                       *
************************************************************************/

_Bool check_casing(char selection)
{
    /*
    Checks to see if the only input mistake was inputing proper input as a 
    lower case letters.
    */
    _Bool checked = true;

    if (selection == 'a' || selection == 'l' || selection == 's' || selection == 'q')
    {
        checked = false;
    }

    return checked;
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: process_selection                                      *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O      DESCRIPTION                       *
* --------        ----       ---      -----------                       *
* selection       char                User input value.                 *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void process_selection(char selection)
{
    /*Selects the proper function to run from the users input*/
    FILE* file_ptr;
    
    switch (selection)
    {
    case 'A':
        file_ptr = read_file(FILE_NAME, "a");/*Open the file with append only permissions*/
        append_text(file_ptr);/*Run the append_text function*/
        break;
    case 'L':
        file_ptr = read_file(FILE_NAME, "r");/*Open the file with read only permissions*/
        print_lines(file_ptr);/*Run the print_lines function*/
        break;
    case 'S':
        file_ptr = read_file(FILE_NAME, "r");/*Open the file with read only permissions*/
        search_for_word(file_ptr);/*Run the search_for_word fuction*/
        break;
    }
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: search_for_word                                        *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O      DESCRIPTION                       *
* --------        ----       ---      -----------                       *
* file_ptr        FILE*      I/O      A file pointer for reading a file.*
*                                                                       *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void  search_for_word(FILE* file_ptr)
{
    /*Finds a word in the file and places brackets around it. Shows word count of designated word.*/
   
    char search_word[MAX_WRD_LEN] = {"\0"};/*Holds the users search term*/
    char current_word[MAX_WRD_LEN] = { "\0" };/*Holds current word to print*/
    char* word_ptr = current_word;/*Pointer to access the current_word array*/

    get_word(search_word);/*Get the word from the user*/
    int count_word = 0; /*Counts how many times the word appears.*/
    int ch = 0;/*Holds the char to be inputed into the current_word array*/

    puts("");/*Add new line for easier console reading*/
   
    while ((ch = fgetc(file_ptr)) != EOF)/*This loop prints the file byte by byte to ensure proper output.*/
    {
        /*Since C avoids the new-line char like the black plague with (f)scanf we make our own function that can handle a new-line char.*/
        if (ch == ' ' || ch == '\n')/*End of word / new line found. Print It!*/
        {
            count_word = print_word_logic(current_word, search_word, count_word, ch);/*Finds out how to print the current_word array*/
            word_ptr = current_word; /*point the pointer back to the start of current_word array*/
        }
        else/*Build the word*/
        {
            *word_ptr++ = ch;/*Insert char into word array*/
        }
    }
    
    /*Show results*/
    printf("\nNumber of occurrences of the word \"%s\" is %d \n\n", search_word, count_word);
    fclose(file_ptr);/*Close the file*/
    
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: reset_word                                             *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O      DESCRIPTION                       *
* --------        ----       ---      -----------                       *
* current_word    char*               The current word to be cleared to *
*                                     null bytes.                       *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void reset_word(char* current_word)
{
    /*Clears the word array so it can be used again properly*/

    while (*current_word != '\0')/*could also be "while(*word)" but this is easier to read*/
    {
        *current_word++ = '\0';
    }
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: print_word_logic                                       *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O      DESCRIPTION                       *
* --------        ----       ---      -----------                       *
* search_word     char*               String pointer for user inputed   *
*                                     word  to search for.              *
*                                                                       *                                                                          
* current_word    char*       O       Inputed word from file thats is   *                                                                      
*                                     going to be outputed to the users *                         
*                                     console.                          *                      
*                                                                       *                           
* count_word      int                 Keeps track of how many times the *                                                                       
*                                     users search word is found in the *                                                                                                                           
*                                     file.                             *                             
*                                                                       *
* ch              int         O       The ASCII decimal value thats to  *
*                                     be outputed to the users console. *
*                                                                       *
*                                                                       *
* RETURNS:                                                              *
* int count_word                                                        *
*                                                                       *
************************************************************************/

int print_word_logic(char* current_word, char* search_word, int count_word, int ch)
{
    /*Finds out how to print the current_word array*/

    if (strcmp(search_word, current_word) == 0)/*The words match*/
    {
        printf("[%s]%c", current_word, (char)ch);/*Print word with trailing white space char and bracket around the word*/
        count_word++; /*count_word  + 1*/
        reset_word(current_word);/*Reset the word*/  
    }
    else/*The words do not match*/
    {
        printf("%s%c", current_word, (char)ch);/*Print word with trailing white space char*/
        reset_word(current_word);/*Reset the word*/
    }

    return count_word;/*Return current word count*/
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: get_word                                               *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O      DESCRIPTION                       *
* --------        ----       ---      -----------                       *
* search_word     char*       I       String pointer for user input     *
*                                                                       *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void get_word(char* search_word)
{
    /*Gets the word from the user that is to be searched for*/

    int clear_stream = getchar(); /*Make sure careiage return is not in input stream*/
    int ch = 0; /*Needed to place the user input into the word array*/

    printf("Enter a word you would like to search for: ");/*Prompt user for input*/
    while ((ch = getchar()) != '\n')/*Take user input*/
    {
        *search_word++ = ch;
    }

    /*Place null byte at end of word array to make it a string literal*/
    *search_word = '\0';
}
/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: read_file                                              *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O      DESCRIPTION                       *
* --------        ----       ---      -----------                       *
* file_name       char*      I/O      Name of file to be used.          *                                                                      
*                                                                       *
* mode            char*      I/O      File stream mode to be used.      *
*                                                                       *
* RETURNS:                                                              *
* return *file_ptr                                                      *
*                                                                       *
************************************************************************/

FILE* read_file(char* file_name, char* mode)
{
    /*Read a file into the input stream*/
    FILE* file_ptr = fopen(file_name, mode);

    if (file_ptr == NULL)/*If no file handle it*/
    {
        printf("\nFile not found\n");
    }

    return file_ptr;
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: print_lines                                            *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O      DESCRIPTION                       *
* --------        ----       ---      -----------                       *
* file_ptr        FILE*      I/O      A file pointer for reading a file.*
*                                                                       *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void print_lines(FILE* file_ptr)
{
    /*Prints an n number of lines entered by the user*/

    int sentinal_val = 0;
    int count_new_line = 0;
    char* newline_str = "\n";
    int ch = 0;


    /*
    Prompt user how many lines they want to see. My file system shows 4 lines but the pdf shows 5 so im not going to try to 
    guess how many lines I should allow the user to input. They can just enter how many lines they feel like. 
    */
    printf("How many lines from the \"CIS265.txt\" would like to be printed out to the screen: ");
    scanf_s("%d", &sentinal_val);/*Take user input*/
    puts("");/*Add a new line char*/

    while ((ch = fgetc(file_ptr)) != EOF )
    {

        if ((char)ch == '\n')
        {
            count_new_line++; /*count_new_line + 1*/
            if (count_new_line == sentinal_val)
            {
                break;/*Exit loop*/
            }
        }

        printf("%c", (char) ch);/*Display word byte by byte*/
    }

    puts("\n");/*Add new line*/

    fclose(file_ptr); /*Close file*/
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: append_text                                            *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O      DESCRIPTION                       *
* --------        ----       ---      -----------                       *
* file_ptr        FILE*       O       A file pointer for reading a file.*
*                                                                       *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void append_text(FILE* file_ptr)
{
    /*This fuction appends text to the EOF*/

    int clear_stream = getchar(); /*Make sure careiage return is not in input stream*/
    int ch = 0; /*Holds char numric value*/
    printf("\nEnter text to be appended to the file: "); /*Ask for user input*/
    
    /*Take user input until newline char*/
    while ((ch = getchar()) != '\n')
    {
        fprintf(file_ptr,"%c", (char) ch);/*Append text to the end of file*/
    }
    /*
    Add new line back into the file after appending user text.
    We do this so we don't lose any chars the user inputs into the file. 
    */
    fprintf(file_ptr, "%c", '\n'); 

    puts("");/*Add new line to output*/
    fclose(file_ptr); /*Close file*/
}