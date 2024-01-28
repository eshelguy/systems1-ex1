#include "NumClass.h"

BOOL isPalindromeRecursive(int num, int originalNum, int reversedNum) {
    if (num == 0) {
        return originalNum == reversedNum;
    }

    int digit = num % 10;
    reversedNum = reversedNum * 10 + digit;

    return isPalindromeRecursive(num / 10, originalNum, reversedNum);
}

BOOL isPalindrome(int num) {
    return isPalindromeRecursive(num, num, 0);
}

int power(int base, int exponent) {
    int result = 1;

    while (exponent > 0) {
        result *= base;
        exponent--;
    }

    return result;
}

int digitsRecursive(int num, int digits) {
    if (num == 0) {
        return digits;
    }

    num /= 10;
    digits += 1;

    return digitsRecursive(num, digits);
}

BOOL isArmstrongRecursive(int num, int originalNum, int sum, int digits) {
    if (num == 0) {
        return originalNum == sum;
    }

    sum += power(num % 10, digits);
    num /= 10;

    return isArmstrongRecursive(num, originalNum, sum, digits);
}

BOOL isArmstrong(int num) {
    int digits = digitsRecursive(num, 0);
    return isArmstrongRecursive(num, num, 0, digits);
}