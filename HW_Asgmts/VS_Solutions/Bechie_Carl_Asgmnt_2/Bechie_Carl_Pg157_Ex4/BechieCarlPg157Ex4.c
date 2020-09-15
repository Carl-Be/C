// File Name  : BechieCarlPg157Ex4
// Description: This program takes in a user inputted phone number and prints out the phone number in all numeric values. Excluding puncuation
//
// Aurthor: Carl Bechie
// Created: 9/1/2020
// Updated: 9/1/2020
// Version: 1
// Class  : CNR 10777 / CIS 265
//
// Build: VS 2019 compiler
// Run: VS 2019 compiler

#include <stdio.h> // Standard C lib for I/O
#include <ctype.h> // Functions to determine the type contained in character data

//Took the book literal and only printed chars it had in the Example.

int main(void)
{
    // Making a var to hold user input 
    typedef int PhoneNumber; // making a Phone Number type 
    PhoneNumber phoneNumber = 0; // This well hold user input of the phone number

    // Asking the user for a phone number  
    printf("Enter phone number: ");// Ask for input 
    while (phoneNumber != '\n') // Get user input while no new line char is found
    {
        phoneNumber = toupper(getchar()); // This is what gets the actual user input. Upper Case format
        
        if(phoneNumber >= 'A' && phoneNumber <= 'C') // is A - C print 2 
        {
            putchar('2'); // prints 2 
        }
        else if (phoneNumber >= 'D' && phoneNumber <= 'F') // D - F print 3
        {
            putchar('3'); // print 3 
        }
        else if (phoneNumber >= 'G' && phoneNumber <= 'I') // G - I print 4
        {
            putchar('4'); // print 4
        }
        else if (phoneNumber >= 'J' && phoneNumber <= 'L') // J - L print 5
        {
            putchar('5'); // print 5
        }
        else if (phoneNumber >= 'M' && phoneNumber <= 'O') // M - O print 6
        {
            putchar('6'); // print 6
        }
        else if (phoneNumber >= 'P' && phoneNumber <= 'S') // P - S print 7
        {
            putchar('7'); // print 7
        }
        else if (phoneNumber >= 'T' && phoneNumber <= 'V') // T - V print 8
        {
            putchar('8'); // print 8
        }
        else if (phoneNumber >= 'W' && phoneNumber <= 'Y')// W - Y print 9
        {
            putchar('9'); // print 9
        }
        else if (phoneNumber == '-') // the char is a punctiation for a phone number. Print it. 
        {
            putchar(phoneNumber); // print the char 
        }
        else if (phoneNumber >= '0' && phoneNumber <= '9') // the char is already a numeric value. Print it
        {
            putchar(phoneNumber); // print the char
        }

    } // end of while loop 

    return 0; // Terminate program with normal status code

}