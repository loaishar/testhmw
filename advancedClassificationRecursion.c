#include "NumClass.h"
#include <math.h>
int digits (int n) {
    int r = 1;
    while (n > 9) {
        n /= 10;
        r++;
    }
    return r;
}
int reverseNumber(int num) {
    // Finding number of digits in num
    int digit = digits(num);
    
    if(num == 0)
        return 0;
    return (((num%10) * pow(10, digit-1)) + reverseNumber(num/10));
}

int isPalindrome(int num) {
    if(num == reverseNumber(num)) return 1;
    return 0;
}

int armstrongRec(int num  , int digits) {
    if (num == 0) return 0;
    int d = num %10;
    return pow(d, digits) + armstrongRec(num/10 ,digits );
}

int isArmstrong(int number) {

    if (number == armstrongRec(number,digits(number))) return 1;
    return 0;
}
