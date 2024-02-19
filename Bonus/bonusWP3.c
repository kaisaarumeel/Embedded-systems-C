//Include section
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


// Main program section
/*
* This program asks the user to input two matrices and finds the sum of both matrices using pointers.
*
* Author: Kaisa Arumeel, 2024
*/

// Method to check if the input is a number.
int isNumber(const char *input) {
    // Check if the input is an empty string.
    if (*input == '\0') {
        // If it is, return 0, since empty string is not a number.
        return 0;
    }
    // Loop through each charachter in the input
    for (int i = 0; input[i] != '\0'; i++) {
        // Check if the character is a digit, additional check for '-' to allow negative numbers as well.
        if (!isdigit(input[i]) && input[i] != '-') {
            // If not, return 0
            return 0;
        }
    }
    // If each character is a digit, then the argument is a number.
    return 1;
}

/// Function to input and validate a matrix
int scanMatrix(int matrix[], int height, int width) {

    //Variable declarations.
    char input[256]; // User input for the matrix.
    int count = 0; // Numbers in the input.
    const char *ptr = input; // Pointer to iterate through the input.
    char number[20]; // A char array to store the input as

    //Scan the input until a the end of line character and save it in the input variable.
    scanf(" %[^\n]", input);

    // Loop as long as the pointer is not an empty string.
    while (*ptr != '\0') {
        // If the current character is a space.
        if (isspace(*ptr)) {
            // Skip it and continue to the next character.
            ptr++;
            continue;
        }
        
        int i = 0;
        // Check if the input is a negative number.
        if (*ptr == '-') {
            // If it is, then set number at the current position to the value of the pointer.
            number[i] = *ptr;
            // Move to the next character.
            i++;
            ptr++;
        }
        // As long as the value of the pointer is not an empty string and the value of the pointer is a digit.
        while (*ptr != '\0' && isdigit(*ptr)) {
            // Set number at the current position to the value of the pointer.
            number[i] = *ptr;
            // Move to the next character.
            i++;
            ptr++;
        }
        // Terminate the number array to make it a valid string.
        number[i] = '\0';
        // Make an additional check if the final number is a decimal number.
        if (!isNumber(number)) {
            printf("invalid\n");
            return 0;
        }
        // Convert the current number to an integer and store it in the matrix at the current position.
        matrix[count] = atoi(number);
        
        // Increment the count by one since a number has been added.
        count ++;
    }

    // Check if there are too few or too many elements in the matrix
    if (count != height * width) {
        printf("invalid\n");
        return 0;
    }
    return 1;
}

// Method to sum the two matrices.
void sumMatrices(int matrix1[], int matrix2[], int height, int width){

    printf("The sum is:\n");

    // First, loop through the height of the matrix (rows).
    for (int i = 0; i < height; i++) {
        // Loop through the width of the matrix (columns).
        for (int j = 0; j < width; j++) {
            // Add the elements of the matrices together and print them in a grid.
            printf("%d ", matrix1[i * width + j]+ matrix2[i * width + j]);
        }

        printf("\n");
    }
    
}

// Main function of the program
int main() {
    int width; // Width of the matrices
    int height; // Height of the matrices
    int matrix1[16], matrix2[16]; // Two matrices inputted by the user.

    // Scan and save the user input for the height and width of the matrices.
    scanf("%d %d", &height, &width);

    // Check that the input is between 2 and 4.
    if (height < 2 || height > 4 || width < 2 || width > 4) {
        // If not, print according message and return.
        printf("invalid\n");
        return 0;
    }

    // Scan the user input for matrix 1 and validate it.
    if (!scanMatrix(matrix1, height, width)) {
        // If the matrix is not valid, return.
        return 0;
    }
    

    // Scan the user input for matrix 2 and validate it.
    if (!scanMatrix(matrix2, height, width)) {
         // If the matrix is not valid, return.
        return 0;
    }

    // Sum the two matrices together.
    sumMatrices(matrix1, matrix2, height, width);

    // Return with success code.
    return 0;
}
