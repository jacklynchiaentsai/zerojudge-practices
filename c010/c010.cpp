#include <bits/stdc++.h>
using namespace std;

// declare global vairables
int main() {
  int n, size = 0;
  vector<int> seq;
  while (cin>>n){
    // insert directly in position no need to resort O(n)
    seq.insert(lower_bound(seq.begin(), seq.end(), n),n);
    size++;
    if (size % 2 != 0){
      cout<< seq[(int)(size/2)]<< endl;
    } else{
      cout<< (int)((seq[size/2]+seq[size/2-1])/2) << endl;
    }
  }
}
