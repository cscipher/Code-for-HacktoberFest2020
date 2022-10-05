#include<stdio.h>  
int main()  
{  
    int n;  
    printf("Enter the value for calculating factorial=");  
    scanf("%d", &n);  
    int j = 2; 
    int a[1000] = {0};
    a[0] = 1;  
    int len = 1;
    int c = 0, num = 0;  
    while(j <= n)
    {  
        c = 0;  
        num = 0;  
        while(c < len)  
        {  
            a[c] = a[c] * j;  
            a[c] = a[c] + num;  
            num = a[c] / 10;  
            a[c] = a[c] % 10;  
            c++;  
        }  
        while(num != 0)  
        {  
            a[len] = num % 10;  
            num = num / 10;  
            len++;  
        }  
        j++;  
    }  
    len--;  
    printf("\n\nFactorial of %d is below = ", n);  
    while(len >= 0)  
    {  
        printf("%d", a[len]);  
        len--;  
    }  
return 0;      
} 