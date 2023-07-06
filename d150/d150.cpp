#include <bits/stdc++.h>
using namespace std;

bool cmp (int a, int b){
  return a > b;
}

int main() {
  int t, n;
  cin>> t;
  for (int i = 0; i< t; i++){
    cin>>n;
    int items[n];
    for (int j = 0 ; j < n; j++){
      cin>> items[j];
    }
    sort (items, items +n, cmp);
    int saves = 0;
    for (int j = 2; j< n; j+=3){
      saves += items[j];
    }
    cout<< saves << endl;
  }
}
