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

// middle is the last index of the first matrix
void merge(int *a, int left, int right, int middle){
  // temporary array to store sorted results
  int tmp[right-left+1];
  int i = 0;   // keep track of tmp index
  // pointers that keep track of current position in each subarray
  int Lpoint = left, Rpoint = middle+1;
  
  // while haven't exausted either array
  while ((Lpoint<=middle) || (Rpoint<=right)){
    // exhasted left array
    if (Lpoint>middle){
      tmp[i] = a[Rpoint];
      Rpoint++;
      i++;
      continue;
    }

    // exhausted right array
    if (Rpoint> right){
      tmp[i] = a[Lpoint];
      Lpoint++;
      i++;
      continue;
    }
    
    if (a[Lpoint] < a[Rpoint]){
      tmp[i] = a[Lpoint];
      Lpoint++;
    } else{
      tmp[i] = a[Rpoint];
      Rpoint++;
    }
    i++;
  }

  // update array
  int tmpIndex = 0;
  for (int i = left; i< right+1; i++){
    a[i] = tmp[tmpIndex];
    tmpIndex++;
  }
}

// left and right are the leftmost and rightmost index boundaries
void mergesort(int *a, int left, int right){
  // base case if left == right we have divided it to one element
  // do nothing will recurse back to previous call with two 
  if (left < right){
    int middle = (left+right)/2;
    mergesort(a, left, middle);
    mergesort(a, middle+1, right);
    merge(a, left, right, middle);
    cout<< "L= " << left<<" M= "<<middle<< " R= "<<right<<endl;
    printArr(a, size);
    
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

  mergesort(a, 0, size-1);
}
