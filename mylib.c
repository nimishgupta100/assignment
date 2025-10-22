#include <stdio.h>
#include <math.h>
#include "mylib.h"


int reverseDigits(int n) {
    int r = 0;
    while (n > 0) {
        r = r * 10 + n % 10;
        n /= 10;
    }
    return r;
}


int isArmstrong(int num) {
    int temp = num, sum = 0, digits = 0;

    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = num;
    while (temp > 0) {
        int rem = temp % 10;
        sum += pow(rem, digits);
        temp /= 10;
    }

    return sum == num;
}


int isAdams(int num) {
    int sq = num * num;
    int rev = reverseDigits(num);
    int revsq = rev * rev;

    return reverseDigits(revsq) == sq;
}

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return 0;
    return 1;
}

int isPrimePalindrome(int num) {
    if (!isPrime(num))
        return 0;
    return num == reverseDigits(num);
}
