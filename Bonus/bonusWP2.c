//Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


// Main program section
/*
* This program asks the user to provide the start day and week. 
* This program acts as a calendar, it prints out the Week number and day.
* It increments the day every second and writes the week and day on the console.
*
* Purpose: Calendar program using enums
*
* Author: Kaisa Arumeel, 2024
*/


// Enum declarations
enum weekDays {Mon = 1, Tue, Wed, Thu, Fri, Sat, Sun};              // Stores the days of the week
enum week { Week1 = 1, Week2 = 2, Week3 = 3, Week4 = 4, Week5 = 5}; // Stores the week numbers


// This function prints the current week number and day to the screen.
// It takes in the current week and current day as parameters.
void displayWeekDay(enum week week, enum weekDays day) {

    // Print the number of the week.
    printf("Week %d, ", week);

    // Depending on the current day, print the name of the day.
    switch (day) 
   {
      case Mon: printf("Monday\n");break;
      case Tue: printf("Tuesday\n");break;
      case Wed: printf("Wednesday\n");break;
      case Thu: printf("Thursday\n");break;
      case Fri: printf("Friday\n");break;
      case Sat: printf("Saturday\n");break;
      case Sun: printf("Sunday\n");break;
   }
}

// This method increments the week number and the day.
// It takes in the current week and the current day as parameters.
void incrementDayWeek(enum week *week, enum weekDays *day) {

    // Check if the current day is Sunday.
    if (*day != Sun) {
        // If not, go to the next day in the week.
        *day = *day + 1;
    } 
    // If the current day is Sunday.
    else {
        // Then set the current day to Monday (start of the new week).
        *day = Mon;
        // And increment the week number.
        *week = *week + 1;
    }
}


// Main function of the program
/*
* The main function asks the user for the starting week and starting day.
* It then calls the display and increment methods every 1 seconds.
*/

int main () { 

    // Variable declarations
    enum week startingWeek;     // User inputted starting week number
    enum weekDays startingDay;  // User inputted starting day

    // Save the first inputted number in the startingWeek variable.
    scanf("%u", &startingWeek);

    // Make sure the next line character is not read as the input. 
    while (getchar() != '\n');
    
    // Save the second user input in the input variable.
    scanf("%u", &startingDay);

    // Validate input for starting week and starting day.
    if((startingWeek < 1 || startingWeek > 5) && (startingDay < 1 || startingDay > 7)){
        // If both are invalid, print invalid.
        printf("invalid\n");
        return 0;

    } 
    // Validate input for starting week. Week has to be between 1 and 5.
    else if (startingWeek < 1 || startingWeek > 5) {
        // If the starting week is not valid, print a error message and return with error code.
        printf("invalid week\n");
        return 0;
    }
    
    // Validate input for starting week. Day has to be between Monday and Sunday.
    else if (startingDay < 1 || startingDay > 7) {
        // If the starting week is not valid, print a error message and return with error code.
        printf("invalid day\n");
        return 0;
    }

    // As long as the current week is not greater than 5.
    while (startingWeek != Week5 + 1)
    {
    // Display the current week and day.
    displayWeekDay(startingWeek, startingDay);
    // Wait for 1 second.
    sleep(1);
    // Increment the day by one (if needed, also week).
    incrementDayWeek(&startingWeek, &startingDay);
    }

    // Return with success code.
    return 0;  

}

