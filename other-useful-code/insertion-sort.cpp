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

  for (int i = 1; i< size; i++){
    int insert = a[i];
    int j;
    for (j = i-1; j >=0; j--){
      if (insert < a[j]){
        a[j+1] = a[j]; // shift right
      } else{
        break;
      }
    }
    a[j+1] = insert;
    cout<< "Cycle "<<i<<": "<< endl;
    printArr(a, size);
  }
}
