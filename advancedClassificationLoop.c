#include "NumClass.h"

BOOL isPalindrome(int num) {
    int originalNum = num;
    int reversedNum = 0;

    while (num > 0) {
        // Get last digit
        int digit = num % 10;

        // Append to reversedNum
        reversedNum = reversedNum * 10 + digit;

        // Move on to next digit
        num /= 10;
    }

    return originalNum == reversedNum;
}

int power(int base, int exponent) {
    int result = 1;

    while (exponent > 0) {
        result *= base;
        exponent--;
    }

    return result;
}

BOOL isArmstrong(int num) {
    int originalNum = num;

    // Count number of digits in num
    int digits = 0;
    while (num > 0) {
        digits++;
        num /= 10;
    }

    // Sum up the powers of the digits of num
    int sum = 0;
    num = originalNum;
    while (num > 0) {
        sum += power(num % 10, digits);
        num /= 10;
    }

    return originalNum == sum;
}