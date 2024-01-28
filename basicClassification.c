#include "NumClass.h"

BOOL isPrime(int num) {
    if (num < 1) {
        return FALSE;  // 0 is not prime numbers
    }

    if (num <= 2) {
        return TRUE; // 1 and 2 are prime number
    }

    // Quick check, not sure if serves any benefit
    if (num % 2 == 0) {
        return FALSE;  // Even numbers (except 2) are not prime
    }

    // Start from 3 since 0, 1 and 2 have been taken care of
    // Run until sqrt(num), skipping even numbers since they've also been taken care of
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return FALSE;  // num is divisible by i, hence not a prime number
        }
    }

    return TRUE;  // num is a prime number
}

int factorial(int num) {
    if (num == 0) {
        return 1;
    }

    int sum = 1;
    for (int i = 1; i <= num; i++) {
        sum *= i;
    }

    return sum;
}

int isStrong(int num) {
    int sum = 0, originalNum = num;
    while (num >= 1) {
        // Add factorial of last digit to sum
        sum += factorial(num % 10);

        // Remove last digit from num
        num /= 10;
    }

    return sum == originalNum ? TRUE : FALSE;
}

