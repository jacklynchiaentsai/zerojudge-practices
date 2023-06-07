#include <bits/stdc++.h>
using namespace std;

// declare global vairables
int n, k;
int p[50001];

// testing if delimeter d can encompass every site
bool test(int d){
  int i = 0, next =0, currNum = 0;
  while (i<n){
    next = p[i] +d;
    currNum += 1;
    // exceed number of servers can use
    if (currNum > k) return false;
    else if (next >= p[n-1] && currNum <=k){
      return true;
    } else{
      do{
        i++;
      } while (p[i] <= next);
    }
  }
  return false;
}

int main() {
  while (cin>>n>>k){
    for(int i =0; i<n; i++){
      cin>>p[i];
    }
    sort(p,p+n);  // sort from smallest to largest
    int L = 1, R = (int)((p[n-1]- p[0])/k) +1;
    while (L<=R){
      int M = (L+R) / 2;
      if (test(M)){
        if (!test(M-1)){
          // answer is M
          L = M;
          break;
        } else{
          // there may potentially be smaller solutions
          R = M-1;
        }
      } else{
        L = M+1;
      }
    }
    cout<< L << endl;
  }
}
