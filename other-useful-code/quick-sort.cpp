#include <bits/stdc++.h>
#define size 10
using namespace std;

// helper function to print out array
void printArr(int *a, int arrSize){
  for(int i = 0; i< arrSize; i++){
    cout<< a[i] << " ";
  }
  cout<< endl;
}

// helper function to swap two values
// passing in as pointers to change parameter values directly
void swap(int *a, int*b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

// sorting all the elements from index L to index R
void quicksort(int *a, int L, int R){
  // base case: more than one element to sort
  if (L<R){
    // inialize the two pointers
    int pivot = a[L];
    int i = L+1;
    int j = R;
    while (1){
      // moving i pointer until finding first element greater than pivot
      while (a[i]< pivot) i++;
      while (a[j]>pivot) j--;

      // check first before swapping
      if (i >= j) break;
      
      swap(&a[i], &a[j]);
      
    }
    swap(&a[L], &a[j]); 
    cout<< "L= "<< L << " j="<< j<< " R=" << R<<endl;
    printArr(a, size);
    
    quicksort(a,L,j-1);
    quicksort(a, j+1, R);
  }
}

int main(){
  int a[size];

  // generate random number for array
  srand(time(NULL));  // initialize random function
  for (int i = 0; i< size;i++){
    // generate random values from 1~1000
    a[i] = rand()%1000 + 1;
  }
  
  cout<< "Before Sorting: "<<endl;
  printArr(a, size);

  quicksort(a, 0, size-1);
  cout<< "After Sorting: "<<endl;
  printArr(a, size);
}
