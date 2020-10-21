// File Name  : BechieCarlPg179Ex7.c
// Description: Reads a 5x5 array of integers inputed by the user and then prints the row sums and the column sums 
//
// Aurthor: Carl Bechie
// Created: 9/21/2020
// Updated: 9/22/2020
// Version: 1
// Class  : CNR 10777 / CIS 265
//
// Build: VS 2019 compiler
// Run: VS 2019 compiler

#include <stdio.h> // standard C lib for I/O

#define NUM_ROWS  5 // Number of rows
#define NUM_COLS  5 // Number of columns 

int main(void)

{
    int twoDArray[NUM_ROWS][NUM_COLS] = { 0 }; // Declearing and initializing twoDArray in memory with all zeros. 

    // Have to make two more arrays to hold the sum totals of each row and column
    int rowTotals[NUM_ROWS] = { 0 }; // Declearing and initializing rowTotals in memory with all zeros. 
    int colTotals[NUM_COLS] = { 0 }; // Declearing and initializing colTotals in memory with all zeros. 


    // Printing instructions for user
    printf("You will be prompted to enter %d rows of whole numbers. Each row has %d columns.\n\n", (int) NUM_ROWS, (int) NUM_COLS);
    printf("Example input for 5 rows with 5 columns each: \n\n");
    printf("Enter row 1: 8 3 9 0 10\n");
    printf("Enter row 2: 3 5 17 1 1\n");
    printf("Enter row 3: 2 8 6 23 1\n");
    printf("Enter row 4: 15 7 3 2 9\n");
    printf("Enter row 5: 6 14 2 6 0\n\n");
    // End of instructions 
    

    // Getting input from the user and placing int vaules into twoDArray 
    int colOneInput, colTwoInput, colThreeInput, colFourInput, colFiveInput; // Firstly declearing vars to hold user input 
    for (int i = 0; i < NUM_ROWS; i++) 
    {
        // Getting user input
        int laymanRowNumber = i + 1; // show the user in layman terms the row number
        printf("Enter row %d: ", laymanRowNumber); // Asking for user input.  
        // Taking user input
        scanf_s("%d %d %d %d %d", &colOneInput, &colTwoInput, &colThreeInput, &colFourInput, &colFiveInput);

        // Placing user input into designated twoDArray element position
        for(int j = 0; j < NUM_COLS; j ++)
        {
            switch (j)
            {
            case 0: 
                twoDArray[i][j] = colOneInput;
                break;
            case 1:
                twoDArray[i][j] = colTwoInput;
                break;
            case 2:
                twoDArray[i][j] = colThreeInput;
                break;
            case 3:
                twoDArray[i][j] = colFourInput;
                break;
            case 4:
                twoDArray[i][j] = colFiveInput;
                break;
            }
        }
    }

    // Doing the calculations for both rows and cols 
    for(int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
        {
            rowTotals[i] += twoDArray[i][j]; // Summing row totals.
            colTotals[i] += twoDArray[j][i]; // Summing col totals.
        }
    }

    // Displaying Results for row totals
    int i;
    printf("\nRow totals: ");
    for (i = 0; i < NUM_ROWS; i++) 
    {
        printf("%d ", rowTotals[i]); // Print array element 
    }

    // Displaying Results for col totals 
    printf("\nColumn Total: ");
    for (i = 0; i < NUM_COLS; i++)
    {
        printf("%d ", colTotals[i]); // Print array element 
    }

    printf("\n\n"); // Print two new lines 

    return 0; // Terminate program with normal status code
}