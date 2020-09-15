// File Name  : Bechie_Carl_Pg35_Ex8
// Description: This program calculates the remaining balance on a loan after the first, second, and thirdmonthly payments.
//
// Aurthor: Carl Bechie
// Created:8/24/2020
// Updated:8/24/2020
// Version: 1
//
// Build: VS 2019 compiler
// Run: VS 2019 compiler

#include <stdio.h> // C standard input output lib


int main(void) // main returns normal termination status code and requiers no arguments to be supplied 
{
	// This block takes in the amount of loan 
	float amountOfLoan; // declearing var to hold user input 
	printf("Enter amount of loan: "); // asking for user input
	scanf_s("%f", &amountOfLoan); // take user input for amountOfLoan 

	// This block takes in the interest rate 
	float interestRate; // declearing var to hold user input
	printf("Enter interest rate: "); // asking for user input
	scanf_s("%f", &interestRate); // take user input for interestRate	

	// This block takes in the monthly payment
	float monthlyPayment; // declearing var to hold user input 
	printf("Enter monthly payment: "); // asking for user input 
	scanf_s("%f", &monthlyPayment); // take user input for monthlyPayment 



	// This block dose the calualtions; 
	// not sure if we can use loops or not since the book has not coverd it yet to so im going to do it the long way. 
	#define monthlyRate (interestRate / 100.0f) / 12.0f // get the monthlyRate caculations

	float firstBalance = (amountOfLoan - monthlyPayment) + (monthlyRate * amountOfLoan); // calulate the first balance 
	printf("\nBalance remaining after first payment: $%.2f\n", firstBalance); // Display the results 

	float seconodBalance = (firstBalance - monthlyPayment) + (monthlyRate * firstBalance); // calulate the second balance 
	printf("Balance remaining after second payment: $%.2f\n", seconodBalance); // Display the results

        float thirdBalance = (seconodBalance - monthlyPayment) + (monthlyRate * seconodBalance); // calulate the third balance
	printf("Balance remaining after third payment: $%.2f\n", thirdBalance); // Display the results 
	


	return 0; // terminatate program with normal status code 
}
