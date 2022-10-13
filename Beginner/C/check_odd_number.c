#include<stdio.h>
int main()
{
    int n;
    printf("Enter an elements: ");
    scanf("%d",&n);
    if(n%2==0){
        printf("Number is not odd");
    }
    else{
        printf("Number is odd");
    }
}
