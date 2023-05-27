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

  int count = 1;
  // n-1 cycles: i is the index we iterate until
  for(int i=size-1; i >0; i--){
    for (int j = 0; j< i; j++){
      // swap if left larger than white
      if (a[j] > a[j+1]){
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
    cout << "Cycle "<< count<<":"<<endl;
    count++;
    printArr(a, size);
  }
}
