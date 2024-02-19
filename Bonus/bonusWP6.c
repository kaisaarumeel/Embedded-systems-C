#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
* This program reads five strings from the console, prints them out and finds the shortest one.
* It then removes the shortest string and prints the array after removal.
*
* Author: Kaisa Arumeel (2024)
* 
* 
**/


//Function to find and remove the shortest string from an array
void removeShortestString(char strings[][250]){
    int shortest = 0; // Index of the shortest string in the array

    // Loop through the array
    for (int i = 0; i < 5; i++)
    {
        // Check if the length of the current string is less than the length of the current shortest string
        if (strlen(strings[i]) < strlen(strings[shortest]))
        {
            // If yes, set the index of the shortest to the current index.
            shortest = i;
        }
        
    }

    // Print the string at position of the shortest string.
    printf("Shortest string removed: %s\n", strings[shortest]);
    
    // Loop through the strings that come after the shortest one.
    for (int i = shortest; i < 4; i++) {
        // Copy the strings after the shortest ones to one position before.
        strcpy(strings[i], strings[i + 1]);
    }
}

// Main function of the program
int main(){
    char strings[5][250]; // Array of 5 strings of max length 250 characters.

    // Loop 5 times
   for (int i = 0; i < 5; i++) {
    // Scan the input and save it in the array
        fgets(strings[i], sizeof(strings[i]), stdin);
    // If the string ends with an enter, remove it.
        if (strings[i][strlen(strings[i]) - 1] == '\n') {
            strings[i][strlen(strings[i]) - 1] = '\0';
        }
    // If the string is just an enter, replace it with an empty string. 
        if (strlen(strings[i]) == 0) {
            strcpy(strings[i], "");
        }
   }

    // Print the array before removal
    printf("Array before removal: \n");
    for (int i = 0; i < 5; i++) {
        printf("%s", strings[i]);
        printf("\n");
       
    }
    
    // Find and remove the shortest string.
    removeShortestString(strings);

    // Print the array after removal.
    printf("Array after removal:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s", strings[i]);
        printf("\n");
       
    }
    // Return with success code.
    return 0;
}