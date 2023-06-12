#include <bits/stdc++.h>
using namespace std;


int main() {
  // observe fibonacci sequence
  // maximum of n = 50
  long long int F[50];
  F[0] = 1;
  F[1] = 2;
  for (int i =2; i<50; i++){
    F[i] = F[i-1] + F[i-2];
  }
  int n;
  while (cin>>n){
    if (n ==0) break;
    cout<< F[n-1]<< endl;
  }
}
