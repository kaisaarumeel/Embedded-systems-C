//Include section
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


// Main program section
/*
* This program takes a decimal number as input from the user.
* It turns the decimal number into binary number and counts
* the number of 0s and 1s in the binary number.
*
* Purpose: Counting the number of 0s and 1s in the binary representation of a decimal number. 
*
* Author: Kaisa Arumeel, 2024
*/


// This method checks if the argument provided is a decimal number.
int isDecimalNumber(const char *input) {
    int i; // Index of the loop
    // Loop through each charachter in the input
    for (i = 0; input[i] != '\0'; i++) {
        // Check if the character is a digit
        if (!isdigit(input[i])) {
            // If not, return 0
            return 0;
        }
    }
    // If each character is a digit, then the argument is a decimal number.
    return 1;
}


/*
* This method converts a decimal number into its binary representation 
* and counts all the 0s and 1s in the binary representation.
*/
void decimalToBinary(int decimalNumber) {
    // Variable declarations
    int zeroCounter = 0,     // Counts the number of 0s
    oneCounter = 0,          // Counts the number of 1s
    significantDigits = 0,   // Counts significant digits (to exclude the count of leading 0s)
    i;                       // Index of the loop


    // Print the beginning of the line
    printf("Binary: 0b");

    // Loop through every bit in the decimal number (32 bits)
    for(i = 31; i >= 0; i -- ){
        // Shift the bits in the decimal number to the right by i position,
        // Check if the current bit in the binary representation is 1
        if(((decimalNumber >> i) & 1) == 1) {
            // Current bit is 1, incerement the counter
            oneCounter++;
            // Set the significantDigits to 1 to show that significant digits have been encountered and there are no leading zeros to be counted.
            significantDigits = 1;
        }
        // The current bit is 0, check if significant digits have been encountered to not count leading zeros
        else if (significantDigits) {
            // Increase the zero counter
            zeroCounter++;
        }

        // If significant digits have been encountered, print the current bit
        if (significantDigits) {
             printf("%d", (decimalNumber >> i) & 1);
        }
    }
    
    printf("\n");

    // Print the binary number.
    // Print the number of 0s in the binary number.
    printf("Number of 0s: %d\n", zeroCounter);
    // Print the number of 1s in the binary number.
    printf("Number of 1s: %d\n", oneCounter);

    // Return
    return;
}


// Main function check
/*
* The main function fistly checks for the inputted argument by the user, 
* makes sure it is a decimal number, prints the decimal number and calls the
* convert method.
*/
int main (int argc, char *argv[]) { 

    int decimalNumber;  // Decimal number inputted by the user

    // Check if there is a single input provided
    if (argc != 2 ) {
        // If not, show appropriate message.
        printf("Error: No number provided. Please provide a number as a command line argument. \n");
        // Return
        return 0;
    }

    // Check if the input is a decimal number
    if (isDecimalNumber(argv[1]) == 0) {
        // If not, print an error message and return
        printf("Error: Invalid number. \n");
        return 0;
    }

    // Converts the string representing the inputted decimal number to an actual integer
    decimalNumber = atoi(argv[1]);

    // Print the inputed number
    printf("Number: %d \n", decimalNumber);
    // Convert decimal number to binary
    decimalToBinary(decimalNumber);
    
    // Return
    return 0;  

}

