#include <bits/stdc++.h>
using namespace std;

int divideAndConquer(long long int b, long long int p, long long int m){
  //base case
  if (p == 0) return 1;
  if (p == 1) return b%m;

  if ( p%2 == 0){
    int temp = divideAndConquer(b, p/2,m) % m;
    return (temp * temp) % m;
  } else{
    return (b* divideAndConquer(b, p-1, m)) %m;
  }
}

int main() {
  long long int b, p, m;
  while (cin>>b>>p>>m){
    int ans = divideAndConquer(b, p, m);
    cout<< ans <<endl;
  }
}
