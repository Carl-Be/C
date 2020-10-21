// File Name  : BechieCarlPg217Ex6.c
// Description: Ask the user to enter a value for x to compute the value of a predefined polynomial ( 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 )
//
// Aurthor: Carl Bechie
// Created: 9/22/2020
// Updated: 9/22/2020
// Version: 1
// Class  : CNR 10777 / CIS 265
//
// Build: VS 2019 compiler
// Run: VS 2019 compiler

#include <stdio.h> // standard C lib for I/O

// Start function declaration
double computePolynomial(double xValue); // This function well compute and return the solution for the polynomial  
double pow(int exponent, double xValue); // Does arithmetic on exponents. Not sure if the book as went over the lib for exponets or not yet so i'll just make my own. 
// End function declaration 

int main(void)
{
    // Start description for user
    printf("You are going to be asked to enter a value for 'x' for the following polynomial:  \n");
    printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 \n\n");
    // End description for user

    // Get user input
    double xValue; // Var to hold user input for the value of x in the polynomial
    printf("Enter a value for x: "); // Ask for user input 
    scanf_s("%lf", &xValue); // Take user input

    // Get the solution to x 
    double answer = computePolynomial(xValue);

    printf("Answer: %.2lf\n", answer); // Display the results with two decimal points 

    return 0; // Terminate program with normal status code

}

// Start function definition

 // This function well compute and return the solution for the polynomial  ( 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 )
double computePolynomial(double xValue)
{
    return ( 3.0 * (pow(5, xValue)) ) + ( 2.0 * (pow(4, xValue)) ) - ( 5.0 * (pow(3, xValue)) ) - ( pow(2, xValue) ) + ( 7.0 * xValue ) - ( 6.0 );
}

// Does arithmetic on exponents. Not sure if the book has went over the lib for exponets or not yet so i'll just make my own. 
double pow(int exponent, double xValue)
{
    double product = xValue; // Holds the product of the exponential arithmetic

    // Computes the exponential arithmetic
    for (int i = 1; i < exponent; i++)
    {
        product *= xValue;
    }

    return product; 
}

// End function definition 

