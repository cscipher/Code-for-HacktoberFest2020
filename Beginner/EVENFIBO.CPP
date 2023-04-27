//@Ankush9954
//C++ program to find sum(integer) of even fibbonical series upto nth term 
#include<iostream.h>
#include<conio.h>
#include<math.h>

 void main()
   {
     clrscr();
     int i,j=1,k,sum=0,n;
     cout<<"Enter the nth term of the fibonnical series = ";
     cin>>n;
     for(i=1;i<n;)
       {
	 k=i+j;
	 if(k%2==0)
	   sum=sum+k;
	 j=i;
	 i=k;
       }
     cout<<sum;
     getch();
   }