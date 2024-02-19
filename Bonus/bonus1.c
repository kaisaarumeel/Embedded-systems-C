//Libraries declaration
#include <stdio.h>
#include <string.h>
// Main function
int main (int argc, char *argv[]) { 
// Check if there is an input provided
if (argc != 2 ) {
    // If not, show appropriate message.
    printf("No command line argument provided, please provide a name. \n");
    // Return
    return 0;
}
// Check if the input string is less than 3 characters
 if (strlen(argv[1]) < 3) {
    // Show appropriate message
    printf("Name too short, min 3 characters\n");
    // Return
    return 0;
} 
// Check if the input string is less than 3 characters
  if (strlen(argv[1]) > 50) {
    // Show appropriate message
    printf("Name too long, max 50 characters\n");
    // Return
    return 0;
} 
    // Greet the person whose name was inserted in the command line.
    printf("Hello %s, how is your day today?\n", argv[1]);
    // Return
    return 0;  


}