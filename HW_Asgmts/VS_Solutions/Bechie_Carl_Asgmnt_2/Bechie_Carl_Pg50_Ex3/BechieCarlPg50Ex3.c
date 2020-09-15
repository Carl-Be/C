// File Name  : BechieCarlPg50Ex3
// Description: This program breaks down an ISBN entered by the user
//
// Aurthor: Carl Bechie
// Created: 8/31/2020
// Updated: 8/31/2020
// Version: 1
// Class  : CNR 10777 / CIS 265
//
// Build: VS 2019 compiler
// Run: VS 2019 compiler

#include <stdio.h> // standard C lib for I/O

int main(void)
{
    // Declearing int vars to hold user input 
    int gsPrefix, grpID, publisherCode, itemNumber, checkDigit;

    // Getting input from the user 
    printf("Enter ISBN: "); // Asking for input from the user
    scanf_s("%d-%d-%d-%d-%d", &gsPrefix, &grpID, &publisherCode, &itemNumber, &checkDigit); // Taking user input

    // Displaying the broken down IBSN
    printf("GS1 prefix: %d\nGroup identifier: %d\nPublisher code: %d\nItem number: %d\nCheck digit: %d\n",
            gsPrefix, grpID, publisherCode, itemNumber, checkDigit);

    return 0; // Terminate program with normal status code

}