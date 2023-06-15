#include <bits/stdc++.h>
using namespace std;


int main() {
  int c, n;
  while (cin>>c>>n){
    long long int val, num[c+1];
    memset(num, 0x6f, sizeof(num));
    num[0] = 0;
    for (int i = 0; i<n; i++){ // item
      cin>>val;
      for (int j=val; j<c+1; j++){
        if (num[j] > num[j-val] + 1){
          num[j] = num[j-val] +1;
        }
      }
    }
    cout<< num[c] << endl;
  }
}
