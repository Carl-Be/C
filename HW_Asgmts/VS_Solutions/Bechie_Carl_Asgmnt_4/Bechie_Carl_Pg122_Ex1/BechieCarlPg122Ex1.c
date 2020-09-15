// File Name  : BechieCarlPg122Ex1.c
// Description: This program displays the lagest number entered by the user 
//
// Aurthor: Carl Bechie
// Created: 9/15/2020
// Updated: 9/15/2020
// Version: 1
// Class  : CNR 10777 / CIS 265
//
// Build: VS 2019 compiler
// Run: VS 2019 compiler

#include <stdio.h> // standard C lib for I/O

int main(void){

    // Describe the program operations to the user
    printf("Menu:\nInput number greater than 0 = Program Continues Running.\nInput number eqaual to or less then 0 = Program Stops Running.\n");
    printf("==============================================================\n\n");

    // Taking input from the user
    double doubleInputted = 0.00; // Initializing a double that is used to hold user input 
    printf("Enter a number: "); // Ask for user input
    scanf_s("%lf", &doubleInputted); // Get double value from user 

    double largestDouble = 0.00; // Initializing a double var to hold the largest input double 

    while (doubleInputted > 0.00) // Keep taking user input until doubleInputted is equal to or less then zero
    { 
        // Logic to determin largest double inputted by user 
        if (doubleInputted > largestDouble)
        {
            largestDouble = doubleInputted; // Setting largest inputted double
        }

        printf("Enter a number: "); // Ask for user input
        scanf_s("%lf", &doubleInputted); // Get double value from user 
    }

    printf("\nThe largest number entered was %f\n", largestDouble); // output the largest double value inputted by the user. 0 means invailed input at start of program. 
    return 0; // Terminate program with normal status code
}