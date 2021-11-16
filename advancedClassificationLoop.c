#include "NumClass.h"
#include <math.h>
int isArmstrong(int number) {
    int originalNumber, remainder, result = 0, num = 0, flag;
 
    originalNumber = number;
 
    while (originalNumber != 0)
    {
        originalNumber /= 10;
        ++num;
    }
 
    originalNumber = number;
 
    while (originalNumber != 0)
    {
        remainder = originalNumber%10;
        result += pow(remainder, num);
        originalNumber /= 10;
    }
 
    // condition for Armstrong number
    if(result == number)
        flag = 1;
    else
        flag = 0;
 
    return flag;
}



int isPalindrome(int num) {
    int rev = num , i=0;
    for(; num>0; num=num/10)
    {
        i = i * 10;
        i = i + (num%10);
    }
    if(rev == i) return 1;
    return 0;
}
