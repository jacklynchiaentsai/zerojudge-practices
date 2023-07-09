#include <bits/stdc++.h>
using namespace std;

// don't need to check everytime if can update at once
// use array to keep track

int main() {
  int T, n, p;
  cin>> T;
  for (int count=0; count<T; count++){
    int loss = 0;
    cin>>n;
    cin>>p;
    int days[n+1]; // days count from 1
    memset(days, 0, sizeof(days));

    // input hartals and update array accordingly
    int h;
    for (int i=0; i<p; i++){
      cin>>h;
      for (int j =h; j<= n; j+=h)
        days[j] = 1;
    }

    // update friday
    for (int i = 6; i<=n; i+=7){
      days[i] = 0;
    }
    
    // update Saturday
    for (int i = 7; i<=n; i+=7){
      days[i] = 0;
    }

    for (int i=1; i<=n; i++)
      loss += days[i];

    cout<< loss << endl;
    
  }
}
