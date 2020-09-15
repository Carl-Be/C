// File Name  : Bechie_Carl_Pg96_Ex5
// Description: Calculates tax due on taxable income inputed by user 
//
// Aurthor: Carl Bechie
// Created: 9/9/2020
// Updated: 9/10/2020
// Version: 1
// Class  : CNR 10777 / CIS 265
//
// Build: VS 2019 compiler
// Run: VS 2019 compiler

#include <stdio.h> // standard C lib for I/O

int main(void)
{
    
    float taxableIncome = 0.00; // declearing var

    // Getting input fromt the user
    printf("Enter the amount of taxable income: $");// Asking for input
    scanf_s("%f", &taxableIncome);// read in a double value

    float taxDue; // declaring var for output 

    // selection statements for tax groups 
    if (taxableIncome <= 750.00f) // 1st tax group
    {
        taxDue = .01f * taxableIncome; // calculate taxDue
    }
    else if (taxableIncome > 750.00f && taxableIncome <= 2250.00f) // 2nd tax group 
    {
        taxDue = 7.50f + (.02f * (taxableIncome - 750.00f)); // calculate taxDue
    }
    else if (taxableIncome > 2250.00f && taxableIncome <= 3750.00f) // 3rd tax group 
    {
        taxDue = 37.50f + (.03f * (taxableIncome - 2250.00f)); // calculate taxDue
    }
    else if (taxableIncome > 3750.00f && taxableIncome <= 5250.00) // 4th tax group 
    {
        taxDue = 82.50f + (.04f * (taxableIncome - 3750.00f)); // calculate taxDue
    }
    else if (taxableIncome > 5250.00f && taxableIncome <= 7000.00f) // 5th tax group 
    {
        taxDue = 142.50f + (.05f * (taxableIncome - 5250.00f)); // calculate taxDue
    }
    else if (taxableIncome > 7000.00f) // 6th tax group 
    {
        taxDue = 230.00f + (.06f * (taxableIncome - 7000.00f)); // calculate taxDue
    }

    printf("Total tax due: $%.2f\n", taxDue); // display output to user 

    return 0; // Terminate program with normal status code

}