#include <bits/stdc++.h>
using namespace std;

// rule is you add n^2 to the previous value
// can be found by testing a couple numbers 

int main() {
  int n;
  int feynman[100];
  feynman[0] = 1;
  for (int i = 1; i< 100; i++){
    feynman[i] = feynman[i-1] + pow(i+1,2);
  }
  while (cin>>n){
    if (n==0) 
      break;
    cout<< feynman[n-1]<< endl;
  }
}
