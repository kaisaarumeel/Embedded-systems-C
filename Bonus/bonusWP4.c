#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
* This program expects the user to provide a string as an argument to the program.
* It then creates all possible permutations of that string, stores them in an array using pointers and 
* prints them out to the user.
*
* Used source: https://www.codesdope.com/blog/article/generating-permutations-of-all-elements-of-an-arra/
*
* Author: Kaisa Arumeel, 2024
*/


// Define section
#define MAX_INPUT 10 // Maximum length of the argument


// Function to swap two characters 
void swap(char *a, char *b)
{
    char temp; // Temporary string
    // Assign the temporary character to be the first argument
    temp = *a;
    // Assign the first character to be the second argument
    *a = *b;
    // Assign the second character to be the temporary string (actually the first argument).
    *b = temp;
}

// Function to generate all permutations of an input string.
// It takes as parameters the input string, start and end of the string, array to store the permutations and count on permutations.
void generatePermutations(char *input, int start, int end, char **permutations, int *count){

  // Check if the start and end are the same.
  if (start == end) {
    // Then store the current permutation in the permutation array
    permutations[*count] = strdup(input);
    // Increment the count of permutations.
    (*count)++;
  } else {
    // Loop through the start of the string until the end of the string
      for (int i = start; i <= end; i++)
      { 
        // Swap the characters at start and i to generate permutations
        swap(input+start, input+i);
        // Recursively call the function to generate permutations for the remaining characters.
        generatePermutations(input, start+1, end, permutations, count);
         // Swap the characters at start and i to go back to the initial input string.
        swap(input+start, input+i);
      }
  }
}

// Main function of the program
int main(int argc, char * argv[]){

  // Check if the provided argument is valid.
    if (argc != 2 || strlen(argv[1]) > MAX_INPUT)
    {
      printf("invalid");
      return 0;
    }

    // Variable declarations.
    char *input = argv[1]; // Assign the variable input to the argument.
    int length = strlen(input); // Length of the inputted string.
    int fact = 1; // Factorial of the inputted string.
    int count = 0; // Count of permutations

    // Find the factorial of the input length to know how many permutations there will be.
    // Loop through the length of the string.
    for(int i=1;i<=length;i++){
      // Calculate the factorial.
      fact=fact*i; 
    }

    // Array to store all of the permutations, allocate the factorial of the input length as memory.
    char **permutations = (char **)malloc(fact * sizeof(char *));

    // Generate all of the permutations, passing in the input string, the start and end of the string, permutations array and count.
    generatePermutations(input, 0, length-1, permutations, &count);

    // Print all of the permutations-
    printf("All permutations of the string %s are: ", input);
    // Loop through all permutations
    for (int i = 0; i < count; i++) {
      // Print them one by one
      printf("%s  ", permutations[i]);
      // Free the memory of each permutation.
      free(permutations[i]); 
    }
    // Free the memory of permutations array.
    free(permutations); 

    // Return success code
    return 0;
}