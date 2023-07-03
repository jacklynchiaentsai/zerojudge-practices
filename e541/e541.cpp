#include <bits/stdc++.h>
using namespace std;

// using vector to sort and search is much faster
int main() {
  int n,q, count = 1;
  while (cin>> n>> q){
    if (n == q && n ==0)
      break;
    
    vector <int> marbles;
    int x;
    for (int i = 0 ; i < n; i++){
      cin>>x;
      marbles.push_back(x);
    }

    sort(marbles.begin(), marbles.end());
    int query;
    
    cout<< "CASE# "<< count++ << ":" << endl;
    for (int i = 0; i< q; i++){
      cin>> query;
      // the first position that is greater or equal to value
      int index = lower_bound(marbles.begin(), marbles.end(), query) - marbles.begin(); 
      if (marbles[index] == query){
        cout<< query << " found at " << index + 1 << endl;
      } else{
        cout<< query << " not found" << endl;
      }
      
    }
    
  }
}
