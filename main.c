#include <stdio.h>

#include "NumClass.h"

int main() {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    if (a <= 0 || b <= 0 || b < a) {
        printf("a and b must be positive integers, a must be smaller than b.");
        return 1;
    }

    printf("The Armstrong numbers are:");
    for (int i = a; i <= b; i++) {
        if (isArmstrong(i)) {
            printf(" %i", i);
        }
    }
    printf("\n");

    printf("The Palindromes are:");
    for (int i = a; i <= b; i++) {
        if (isPalindrome(i)) {
            printf(" %i", i);
        }
    }
    printf("\n");

    printf("The Prime numbers are:");
    for (int i = a; i <= b; i++) {
        if (isPrime(i)) {
            printf(" %i", i);
        }
    }
    printf("\n");

    printf("The Strong numbers are:");
    for (int i = a; i <= b; i++) {
        if (isStrong(i)) {
            printf(" %i", i);
        }
    }
    printf("\n");
}
