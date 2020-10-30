// @sidhartha8011
// c Program for finding the factorial of any large number

#include<stdio.h>
void main()
{   
    int a[40000],carry=0,size=1,i,n,j,fact=0;
    a[0]=1;
    printf("enter the number to calculate the factorial: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        carry=0;
        for(j=0;j<size;j++){
            fact=a[j]*i;
            a[j]=(fact+carry)%10;
            carry=(fact+carry)/10;
            
            if((j==size-1)&&carry>0){
                a[j+1]=0;
                size++;
                
            } 
        }
    }
    printf("factorial: ");
    for( i = size-1; i>=0; i--)
        printf(" %d",a[i]);
    printf("\nnumber of digits in %d factorial: %d",n,size);
    
}
