// File Name  : Bechie_Carl_Pg34_Ex4
// Description: This program takes stdin from the user in the form of dollar amount then adds 5% tax to that amount and displays the new amount with tax added to the orginal amount.
//
// Aurthor: Carl Bechie 
// Created: 8/24/2020
// Updated: 8/24/2020 
// Version: 1
// 
// Build: VS 2019 compiler 
// Run: VS 2019 compiler  

#include <stdio.h> // Standard C I/O lib

int main(void) // main function return normal program termination status code 
{
	// this block takes in user input 
	float dollarAmount;// var to hold user input 
	printf("Enter an amount: "); // ask for user input
	scanf_s("%f", &dollarAmount); // take user input and store it in var dollarAmount
    //Recived a warning with visual studio saying to use scan_s() or #define _CRT_SECURE_NO_WARNINGS at the top. 
	//Decided secuirty practices are good to follow so I used scanf_s() instead of scanf()
	//Below is the warning. 
	//Severity Code Description Project File Line Suppression State Error C4996 'scanf': This function or 
	//variable may be unsafe. Consider using scanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS.

	// this block dose the calculations to get the amount added with tax 	
	#define TAX_RATE .05f // the user will be charged 5% tax
	float taxAmount = dollarAmount * TAX_RATE; // calculate the tax amount
	float newAmount = dollarAmount + taxAmount; // get the new amount with tax added to the old amount

	// this block displays the new amount to the user 
	printf("With tax added: $%.2f\n", newAmount); // Display the new amount with 2 persion points 
	
	return 0; // teminatate the program under the normal status code 
}
