#include <stdio.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int addFraction(int a, int c, int b, int d){
    int numerator =(a*d + b*c);
    int denominator = c * d;

    int common_divisor = gcd(numerator, denominator);
    numerator /= common_divisor;
    denominator /= common_divisor;

    printf("%d/%d\n", numerator, denominator);
    return 1;
}

int substractFraction(int a, int c, int b, int d){
    int numerator =(a*d - b*c);
    int denominator = c * d;

    int common_divisor = gcd(numerator, denominator);
    numerator /= common_divisor;
    denominator /= common_divisor;

    printf("%d/%d\n", numerator, denominator);
    return 1;
}
int multiplyFraction(int a, int c, int b, int d){
    int numerator =a*b;
    int denominator = c * d;

    int common_divisor = gcd(numerator, denominator);
    numerator /= common_divisor;
    denominator /= common_divisor;

    printf("%d/%d\n", numerator, denominator);
    return 1;
}

int main(){
    int a, b, c, d;
    printf("Enter a: \n");
    scanf("%d", &a);
    printf("Enter b: \n");
    scanf("%d", &b);
    printf("Enter c: \n");
    scanf("%d", &c);
    printf("Enter d: \n");
    scanf("%d", &d);
    addFraction(a, c, b, d);
    substractFraction(a, c, b, d);
    multiplyFraction(a, c, b, d);
    return 0;
}
