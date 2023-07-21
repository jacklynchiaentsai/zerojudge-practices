#include <bits/stdc++.h>
using namespace std;


int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int selection = 1;
  int n,x, card[20];
  vector<int> line;
  
  while (cin>>n>>x){
    line.clear();
    
    for(int i=1; i<=n; i++){
      line.push_back(i);
    }
    
    bool done = false;

    // drawing cards
    for(int i=0; i<20; i++)
      cin>>card[i];
    
    // special case: if n==x
    if (n <= x){
      goto PrintAns;
    }
    
    
    for(int i=0; i<20; i++){
      auto it = line.begin()+card[i]-1;
      // simulating elimination
      while(it < line.end()){
        // Due to deletion in loop, iterator became
            // invalidated. So reset the iterator to next item.
        it = line.erase(it);
        it += card[i]-1;

        // checks if reached enough ppl with every elimination
        if (line.size() == x){
          done= true;
          break;
        }
      }

      if (done)
        break;
    }

    PrintAns: 
    cout<< "Selection #"<< selection++ <<endl;
    for(int i=0; i< line.size(); i++){
      if (i==line.size()-1)
        cout<< line[i]<< endl;
      else
        cout<< line[i]<< " ";
    }
    
    cout<< endl;
  }
}
