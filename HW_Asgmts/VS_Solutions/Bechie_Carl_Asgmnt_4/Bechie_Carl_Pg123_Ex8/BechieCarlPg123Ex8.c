// File Name  : BechieCarlPg123Ex8.c
// Description: Displays a calender that provided parameters from user input 
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

int main(void)
{
    // Taking user input for number of days 
    int numberOfDays; // Declearing var to hold user input for number of days
    printf("Enter number of days in month: "); // Asking for user input 
    scanf_s("%d", &numberOfDays); // Getting user input

    // Taking user input for starting day of week 
    int startingDayOfWeek; // Declearing var to hold user input for starting day of week 
    printf("Enter starting day of the week (1=Sun, 7=Sat): "); // Asking for user input
    scanf_s("%d", &startingDayOfWeek); // Getting user input 

    printf("\n%3s%3s%3s%3s%3s%3s%3s\n", "Su","M","Tu","W","Th","F","Sa"); // Print calendar header 


    // Logic to determine how many black spaces to start out with. 
    // Each blank space needs to be ((startingDayOfWeek - 1) * 3) right justified characters wide
    switch (startingDayOfWeek) 
    {
    case 1: break; // No blank spaces needed 
    case 2: 
        printf("%3s", "");
        break;
    case 3: 
        printf("%6s", "");
        break;
    case 4: 
        printf("%9s", "");
        break;
    case 5: 
        printf("%12s", "");
        break;
    case 6: 
        printf("%15s", "");
        break;
    case 7:  
        printf("%18s", "");
        break;
    }

    int dayOfWeekCounter = startingDayOfWeek; // Make new var with a meaningful name to keep track of the day of week  

    // For loop to display each day of the calendar
    for (int i = 1; i <= numberOfDays; i++) 
    {
        // Once the counter reaches greater then 7 make a new line and restart counter at 1
        if (dayOfWeekCounter > 7)
        {
            printf("\n"); // Print newline 
            dayOfWeekCounter = 1; // restart counter at 1 
        }

        // Display the calendar day
        printf("%3d", i);
 
        dayOfWeekCounter++; // increment counter by 1 
    }

    printf("\n"); // Print blank line so it looks nicer after exec in console 

    return 0; // Terminate program with normal status code

}








