#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void set_unset_bit(int *number, int position, int set ){
    if (set == 1)
    {
        *number |= (1 << (position-1));
    } else{
        *number &= ~(1<< (position-1));
    }
    
}

void printBinary(int number){
    printf("0b");
    int start_printing = 0;
    for (int i = (sizeof(number)*8)-1; i >= 0; i--)
    {
        if (number & (1 << i))
        {
           printf("1");
           start_printing = 1;
        } else if (start_printing == 1){
            printf("0");
        }
        
    }
    
}

int main(int argc, char * argv[]){
    if (argc != 4)
    {
       printf("Please enter 3 arguments. \n");
       return 1;
    }

    int number;
    if (sscanf(argv[1], "0x%x", &number) != 1) {
        printf("Invalid number: %s\n", argv[1]);
        return 1;
    }

    char *action = argv[2];
    int bit = atoi(argv[3]);

    if (bit< 1 || bit > sizeof(number) * 8) {
        printf("Invalid bit position: %d\n", bit);
        return 1;
    }

     if (strcmp(action, "set") == 0)
        set_unset_bit(&number, bit, 1);
    else if (strcmp(action, "unset") == 0)
        set_unset_bit(&number, bit, 0);
    else {
        printf("Invalid action: %s\n", action);
        return 1;
    }

    printf("%X", number);
    printf("\n");
    printBinary(number);
    printf("\n");

    return 0;
    
}
