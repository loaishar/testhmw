#include "NumClass.h"

int fact(int r)  
{  
    int mul=1;  
    for(int i=1;i<=r;i++)  
    {  
        mul=mul*i;  
    }  
    return mul;    
}  

int isStrong(int x){
    int k = x , sum=0 , r=0;;
    while(k!=0)  
        {  
            r=k%10;  
            int f=fact(r);  
            k=k/10;  
            sum=sum+f;  
        }
    if (sum == x) return 1; //this is a strong number
    return 0;
}

int isPrime(int x) {
    for (int i=2 ; i< x/2 ; i++) {
        if (x%i == 0) return 0;
    }
    return 1;
}