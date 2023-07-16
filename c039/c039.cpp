#include <bits/stdc++.h>
using namespace std;


int main() {
  map<int, int> nummap;
  
  int a,b;
  while (cin>>a>>b){
    int lower = min(a,b);
    int upper = max(a,b);
    int maxlen = 0;
    for(int i = lower; i<= upper; i++){
      if (nummap.find(i) == nummap.end()){
        int cycle = 0;
        int cpy = i;
        while(true){
          cycle += 1;
          if (cpy == 1)
            break;
          if (cpy % 2 == 1){
            cpy = 3*cpy + 1;
          } else{
            cpy /= 2;
          }
        }
        nummap[i] = cycle;
      }
      
      if (maxlen < nummap[i])
        maxlen = nummap[i];
    }
    cout<< a<< " "<< b<< " " << maxlen << endl;
  }
}
