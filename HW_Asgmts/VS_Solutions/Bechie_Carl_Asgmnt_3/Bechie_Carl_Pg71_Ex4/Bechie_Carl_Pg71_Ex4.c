// File Name  : Bechie_Carl_Pg71_Ex4.c
// Description: Integer to Octal convertor 
//
// Aurthor: Carl Bechie
// Created: 9/9/2020
// Updated: 9/9/2020
// Version: 1
// Class  : CNR 10777 / CIS 265
//
// Build: VS 2019 compiler
// Run: VS 2019 compiler

#include <stdio.h> // standard C lib for I/O

int main(void)
{
    int intNum; // declare var intNum 

    // Taking input from user 
    printf("Enter a number between 0 and 32767: "); // Ask for input
    scanf_s("%d", &intNum); // Getting input from the user

    // Output the integer as an Octal
    printf("In octal, your number is: %.5o\n", intNum); 

    return 0; // Terminate program with normal status code

}