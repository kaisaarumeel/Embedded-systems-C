#include <stdio.h>
#include <stdint.h>

void printBinary(uint32_t num){
    for (int i = 31; i >= 0; i--)
    {
       if (num & 1 << i)
       {
        printf("1");
       } else {
        printf("0");
       }
       
       if (i%8==0 && i != 0)
       {
       printf(".");
       }
       
    }
    printf("\n");
}

uint16_t make_16bit(uint8_t least_significant, uint8_t most_significant){
   // Combine the least significant byte and the most significant byte into a 16-bit integer
    uint16_t result = ((uint16_t)most_significant << 8) | least_significant;
    return result;

}

int main(){
    int* a, b;
    int*x, *y;

    int temp_a = 1;
    a = &temp_a;
    b= 2;
     int temp_x = 3;
    x = &temp_x;

    int temp_y = 4;
    y = &temp_y;
    printf("%p %d %d %d", a, b, *x, *y);

    printBinary(make_16bit(7,1));

    return 0;
}