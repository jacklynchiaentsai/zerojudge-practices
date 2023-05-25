#include<iostream>

#include<algorithm>

#include <ext/rope>

//#include <x86intrin.h>

using namespace std;

using namespace __gnu_cxx;

int main(){
  int n, m, k;
  // dynamically add remove: use vector
  // using vector will TLE so use rope instead
  rope<int> survived;
  while (cin>>n>>m>>k){
    
    survived.clear();
    
    //initializing vector
    for (int i = 0; i<n; i++){
      // note starting-from-zero
      survived.push_back(i);
    }

    // start eliminating ppl
    int current = 0;  // records the current index
    for (int i = 0; i<k; i++){
      int eliminate = (current+m-1) % survived.size();
      survived.erase(eliminate, 1);
      if (eliminate == survived.size()){
        current = 0;
      } else{
        current = eliminate;
      }
    }

    cout<< survived[current] + 1<< endl;
  }
}
