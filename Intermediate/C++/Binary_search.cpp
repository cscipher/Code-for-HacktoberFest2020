#include<iostream>
using namespace std;

void B_search(int a[],int n, int item)
{
    int b=0,e=n-1,mid;
    while(b<=e)
    {
        mid = (b+e)/2;
        if(a[mid] == item)
        {
            cout<<"Item Found at position: "<<mid+1;
            return;
        }
        else if(a[mid] > item)
        {
            e=mid-1;
        }
        else
        {
            b=mid+1;
        }
    }
    cout<<"Element is not in the array.";
}
 int main()
 {
     int n,x;
     cout<<"\nEnter the number of elements:"; cin>>n;
     int arr[n];
     cout<<"\nEnter the elements into the array:";
     for(int i=0;i<n;i++)
     {
         cout<<"\nEnter A["<<i+1<<"]:"; cin>>arr[i];
     }
     cout<<"\nEnter the element to search:";
     cin>>x;
     B_search(arr,n,x);
     return 0;
 }
