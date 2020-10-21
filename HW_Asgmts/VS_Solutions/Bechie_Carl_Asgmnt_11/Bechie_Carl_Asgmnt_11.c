/*Includes*/
#include <stdio.h> /*Standard C I/O Lib*/
#include <string.h> /*String Lib*/

/*Defines*/
#define MAX_DIGITS 10 /*Maximum digits allowed to be used by the program*/
#define ROWS 3 /*Number of rows in the digit_array*/
#define COLS (MAX_DIGITS * 4) /*Number if columns the digit_array*/

/*External Vars*/
char digit_array[ROWS][COLS]; /*This array holds the digits to be outputed to the user*/

/*Holds the digits repersentation to be displayed to the user*/
const char segments_array[10][7] = { {1,1,1,1,1,1,0}, {0,1,1,0,0,0,0}, {1,1,0,1,1,0,1}, /*0, 1, 2*/
                                     {1,1,1,1,0,0,1}, {0,1,1,0,0,1,1}, {1,0,1,1,0,1,1}, /*3, 4, 5*/
                                     {1,0,1,1,1,1,1}, {1,1,1,0,0,0,0}, {1,1,1,1,1,1,1}, /*6, 7, 8*/
                                     {1,1,1,1,0,1,1} };                                 /*9*/
                        

/*Prototypes*/
void clear_digits(void);/*Clears the digit_array*/
void process_digit(int digit, int position);/*Places the digit into the digit_array*/
void print_digit(void);/*Prints the digit_array*/

/******************************************************************************/

int main(void)
{
    int position = 0;
    int digit = 0;
    int digit_count;

    clear_digits();/*Initalize the digit_array elements to all spaces for proper output*/

    
    do{
        
        digit_count = 0;
        
        printf("Enter a number or No numbers to quit: ");
        while ((digit = getchar()) != '\n')
        {
            if (digit >= '0' && digit <= '9' && digit_count < MAX_DIGITS)
            {
                process_digit(digit - '0', position);
                position++;
                digit_count++;
            }
        }

        if (digit_count != 0)
        {
            print_digit();
            clear_digits();
            position = 0;
        }

    } while (digit_count != 0);

    return 0;
}

/******************************************************************************/

void clear_digits(void)
{
    /*Clears the digit_array*/

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            digit_array[i][j] = ' '; /*Place spaces into the elements of the digit_array*/
        }
    }

}

/******************************************************************************/

void process_digit(int digit, int position)
{
    /*Places the digit into the digit_array*/

    position *= 4;

    for (int i = 0; i < ROWS; i++)
    {
        if(i == 0)
        {
            if (segments_array[digit][0] == 1)
            {
                digit_array[i][position + 1] = '_';
            }
        }
        else if (i == 1)
        {
            if (segments_array[digit][1] == 1)
            {
                digit_array[i][position + 2] = '|';
            }

            if (segments_array[digit][6] == 1)
            {
                digit_array[i][position + 1] = '_';
            }

            if (segments_array[digit][5] == 1)
            {
            digit_array[i][position] = '|';
            }
        }
        else if (i == 2)
        {
            if (segments_array[digit][2] == 1)
            {
                digit_array[i][position + 2] = '|';
            }

            if (segments_array[digit][3] == 1)
            {
                digit_array[i][position + 1] = '_';
            }

            if (segments_array[digit][4] == 1)
            {
                digit_array[i][position] = '|';
            }
        }
    }
}

/******************************************************************************/

void print_digit(void)
{
    /*Prints the digit_array*/

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            putchar(digit_array[i][j]);/*stdout the digit_array*/
        }
        puts("");
    }
    
    puts("");
}
