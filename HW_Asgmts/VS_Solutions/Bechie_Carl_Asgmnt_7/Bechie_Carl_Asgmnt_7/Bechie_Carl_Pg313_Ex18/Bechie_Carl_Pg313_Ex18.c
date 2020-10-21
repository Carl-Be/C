/************************************************************************
* FILE NAME: Bechie_Carl_Pg313_Ex18.c                                   *
* Student: Carl Bechie                                                  *
* Class: CNR 10777 CIS265                                               *
*                                                                       *
* PURPOSE:                                                              *
* Reformats user date format from "<mm>/<dd>/<yyyy>"                    *
*  to "<month> <dd>, <yyyy>"                                            * 
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
* ASSUMPTION - Do I dear say user inputs data correctly (lol)           *
*                                                                       *
* NOTES:                                                                *
*                                                                       *
* REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:                    *
*   Visual Studio 2019 IDE for edits.                                   *
*                                                                       *
* DEVELOPMENT HISTORY:                                                  *
*                                                                       *
* Date          Author      Change Id Release     Description Of Change *
* -----       ---------     -----------------     --------------------- *
* 10/06/2020  Carl Bechie        1.0              First Edit            *
* 10/07/2020  Carl Bechie        1.0              Finished Logic        *
*                                                                       *
* ALGORITHM (PDL)                                                       *
*                                                                       *
************************************************************************/

/* Include global parameters */
#include <stdio.h> /* standard C lib for I/O */

/* initialize Defines */
#define MAX_LEN (int)10 /*Max length of the date string inputted by the user*/

/* Declare Prototypes */
void get_date(char* date);/*Gets the date from the user*/
void corrected_date_format(const char* date, const char** months);/*Corrects the dates format*/
char* get_month(const char** months, const char* date);/*Returns the proper index of the month string for user month inputed*/
int month_index(const char* date); /*Finds out what month from the months array to get*/
int get_day(const char* date);/*Gets the day out of the inputed date string array*/
void get_year(const char* date, char* year);/*Gets the year out of the inputed date string array*/

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
    char date[MAX_LEN + 1] = { '\0' };
    char* months[] = {"January", "Febuary", "March",
                      "April", "May", "June",
                      "July", "August", "September",
                      "October", "November", "December"};

    get_date(date);
    corrected_date_format(date, months);

    return 0; /* Terminate program with normal status code */

}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: get_date                                               *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
*  date           char*       I             points to the start of date *
*                                           array                       *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void get_date(char* date)
{
    /*Takes user input to set the date array*/
    int ch = 0;/*Needed to place the user input into the date array*/
    printf("Enter a date (mm/dd/yyyy): ");

    while ((ch = getchar()) != '\n')
    {
        *date++ = ch;
    }

    *date = '\0'; /*Place null byte at end of date array*/
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: corrected_date_format                                  *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
*  date     const char*                     points to the start of date *
*                                           array                       *
*                                                                       *
* months    const char*                     points to the start of month*
*                                           array                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void corrected_date_format(const char* date, const char** months)
{
    char year[5] = { '\0' };/*Holds the year portion of the user string*/

    char* month_ptr = get_month(months, date); /*Points to the correct month string*/
    int day = get_day(date);/*Holds the day of the month*/
    get_year(date, year);/*Correctly stores year portion inside year array*/
    
    printf("You entered the date %s %d, %s\n", month_ptr, day, year);/*Display results*/
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: get_month                                              *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
*  date     const char*                     points to the start of date *
*                                           array                       *
*                                                                       *
* months    const char*                     points to the start of month*
*                                           array                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

char* get_month(const char** months, const char* date)
{
    return months[month_index(date)]; /*return the month to the formatting function*/
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: month_index                                            *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
* date      const char*                     pointer to the date array   *
*                                                                       *
* RETURNS:                                                              *
* int month_index. This index is used to select the proper month.       *
*                                                                       *
************************************************************************/

int month_index(const char* date)
{
    /*The program can not tell if the user inputted the month with padding (ie. 03/19/2020) or
    without padding (ie. 3/19/2020 but it can make asumptions based on a two digit maximum for the 
    month. The following code allows us to take in a month with or without a padding 0. Anything 
    else is an error.*/

    int month_index = 0;

    if (date[0] == '1' && date[1] != '/') /*Example trigger: '10'/15/2020*/
    {
         month_index = ((date[1] - '1') + 10) ; 
    }
    else if(date[0] == '0' && date[1] != '/') /*Example trigger: '09'/15/2020*/
    {
        month_index = (date[1] - '1');
    }
    else if(date[1] == '/')/*Example trigger: '9/'15/2020*/
    {
        month_index = (date[0] - '1');
    }
    else 
    {
        printf("Please enter the input as shown mm/dd/yyyy\n"); /*error message*/
    }

    return month_index;
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: get_day                                                *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
* date      const char*                     pointer to the date array   *
*                                                                       *
* RETURNS:                                                              *
* int day                                                               *
*                                                                       *
************************************************************************/
int get_day(const char *date)
{
    /*We dont know how the user inputed the date so we cant tell at what index the 
    day beings or ends without looping throug the array to find the first "/" index 
    after that we can make asumptions based on a two digit day at most. That
    includeds padding with a 0 or without a 0.*/

    int day = 0;
    int most_sig_digit = 0;
    int least_sig_digit = 0;

    for (;;)
    {
        if (*date++ == '/') /*Finds first slash*/
        {
            most_sig_digit = *date++; /*stores the most significant digit*/
            if (*date != '/')/*Example trigger 9/'15'/2020 ie. there is a least significant digit*/
            {
                least_sig_digit = *date;/*stores the least significant digit*/
                if (most_sig_digit != '0')/*Example trigger 9/'15'/2020*/
                {
                    /*Calculats the day with a tens and one place included*/
                    day = ((most_sig_digit - '0') * 10) + (least_sig_digit - '0');
                }
                else /*Example trigger 9/'05'/2020*/
                {
                    /*Calculates the day with only the ones place included*/
                    day = least_sig_digit - '0';
                }
                    break;
            }
            /*Calculates the day with only the ones place included*/
            day = most_sig_digit - '0';
            break;
        }
    }

    return day;
}

/************************************************************************/

/************************************************************************
*                                                                       *
* FUNCTION NAME: get_year                                               *
*                                                                       *
* ARGUMENT LIST:                                                        *
*                                                                       *
* ARGUMENT        TYPE       I/O            DESCRIPTION                 *
* --------        ----       ---            -----------                 *
* date      const char*                     pointer to date array       *
*                                                                       *
* year            char*                     pointer to year array       *
*                                                                       *
* RETURNS:                                                              *
* void                                                                  *
*                                                                       *
************************************************************************/

void get_year(const char* date, char* year)
{
    /*Finds the second slash in the array then puts the year into the referenced year array*/
    int count_slash = 0;

    for (;;)
    {
        /*find the second slash so the program knows where to start the year at*/
        if (*date++ == '/')
        {
            count_slash++;
        }
        /*Place year into the year array*/
        if (count_slash == 2)
        {
            year[0] = *date++;
            year[1] = *date++;
            year[2] = *date++;
            year[3] = *date;
            break;
        }
    }
}