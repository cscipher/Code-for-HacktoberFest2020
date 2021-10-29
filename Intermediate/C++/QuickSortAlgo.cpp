#include<iostream>
using namespace std;

void swapping(int &a, int &b) { //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

int partition(int *array, int lower, int upper) {
   //Hoare partitioning technique to find correct location for pivot
   int pivot, start, end;
   pivot = array[lower];      //first element as pivot
   start = lower; end = upper;

   while(start < end) {
      while(array[start] <= pivot && start<end) {
         start++;      //start pointer moves to right
      }

      while(array[end] > pivot) {
         end--;      //end pointer moves to left
      }

      if(start < end) {
         swap(array[start], array[end]); //swap smaller and bigger element
      }
   }

   array[lower] = array[end];
   array[end] = pivot;
   return end;
}

void quickSort(int *array, int left, int right) {
   int q;

   if(left < right) {
      q = partition(array, left, right);
      quickSort(array, left, q-1);    //sort left sub-array
      quickSort(array, q+1, right);   //sort right sub-array
   }
}

int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n]; //create an array with given number of elements
   cout << "Enter elements:" << endl;

   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }

   cout << "Array before Sorting: ";
   display(arr, n);
   quickSort(arr, 0, n-1); //(n-1) for last index
   cout << "Array after Sorting: ";
   display(arr, n);
}
