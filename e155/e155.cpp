#include <bits/stdc++.h>
using namespace std;


int main(){
  int n;
  // n <= 50
  while (cin>>n){
    if (n==0){
      break;
    }

    if (n==1){
      cout<< "Discarded cards: "<<endl;
       cout<<"Remaining card: "<< 1 <<endl;
       continue;
    }

    queue<int> cards;
    vector<int> discarded;
    
    // insert everything in queue
    for (int i = 0; i< n; i++){
      cards.push(i+1);
    }

    // simulating the rule
    while (cards.size() > 1){
      int discard = cards.front();
      cards.pop();
      discarded.push_back(discard);
      
      int temp = cards.front();
      cards.pop();
      cards.push(temp);
    }

    cout<< "Discarded cards: ";
    for (int i = 0; i< discarded.size(); i++){
      if (i == discarded.size()-1){
        cout<< discarded[i]<<endl;
      } else{
        cout<< discarded[i]<< ", ";
      }
    }

    cout<<"Remaining card: "<< cards.front()<<endl;
    
    
  }
}
