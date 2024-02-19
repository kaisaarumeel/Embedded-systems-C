#include <stdio.h>
#include <stdlib.h>

/*
* This program takes in an argument and returns the Fibonacci number at that position.
* The program generates the Fibonacci squence using a linked list.
*
*
* Author: Kaisa Arumeel (2024)
*/

// Structure for a node in the linked list
typedef struct Node {
    int value; // Value of the node
    struct Node* next; // Pointer to the next node in the linked list
} Node;


// Function to add a new node to the end of the linked list
void append(Node** headPtr, int value) {
    Node* node = (Node*)malloc(sizeof(Node)); // Create a new node and allocate memory of the size of a node
    Node* previous = *headPtr; // Create a pointer to the previous element in the linked list.
    // Set the new node's value to the value passed in
    node->value = value; 
    // Set the new node's next pointer to be null.
    node->next = NULL;
    // Check if the head is empty
    if (*headPtr == NULL) {
        // Then set the new node to be the head
        *headPtr = node;
        return;
    }
    // Loop as long as the next is not empty.
    while (previous->next != NULL){
        // Set the previous to be the previous' node's next
        previous = previous->next;
    }
    // Set the previous's next to be the new node
    previous->next = node;
}

// Function to retrieve the value at a given index in the linked list
int get(Node* head, int index) {
    // Set the current node to be the head of the linked list
    Node* current = head; 
    // Loop through all the elements in the linked list until the index
    for (int i = 0; i < index; i++) {
        // Go to the next node
        current = current->next;
    }
    // Return the last element's value.
    return current->value;
}

// Function to generate the Fibonacci sequence as a linked list up to the index provided
void generateLinkedList(Node** head_ref, int index) {
    // First add a 0 to the linked list
    append(head_ref, 0);
    // Then add a 1
    append(head_ref, 1);
    // For every element until the index
    for (int i = 2; i <= index; i++) {
        // Append a node with the value of the sum of the two previous nodes.
        append(head_ref, get(*head_ref, i - 1) + get(*head_ref, i - 2));
    }
}

// Main function of the program
int main(int argc, char* argv[]) {
    // Check if there is any argument provided or if it is below zero
    if (argc != 2 || atoi(argv[1]) < 0) {
        // Print 0 and return
        printf("0");
        return 0;
    }

    // Save the argument as a variable
    int index = atoi(argv[1]);
    // Set the head of the linked list to be null
    Node* head = NULL;
    // Generate the linked list
    generateLinkedList(&head, index);

    // Print the value at the desired position
    printf("%d\n", get(head, index-1));

    // Free memory
    // Set the current node to the head
    Node* current = head;
    // Create a pointer to the next
    Node* next;
    // Loop as long as the head is not empty
    while (current != NULL) {
        // Set the next to the current's next element
        next = current->next;
        // Free the memory of current element
        free(current);
        // Set the current element to the next element.
        current = next;
    }
    // Return with success code
    return 0;
}
