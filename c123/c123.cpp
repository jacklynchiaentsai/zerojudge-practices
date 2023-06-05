#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin>>n){
    if (n==0) break;
    int b[n];
    while (cin>>b[0]){
      if (b[0] == 0){
        cout<< endl;
        break;
      } 
      stack <int> st;
      queue <int> A;
      bool ans = true;
      for (int i = 1; i<=n; i++){
        A.push(i);
      }
      
      for (int i = 1; i<n; i++){
        cin>>b[i];
      }      
      
      for (int i = 0; i<n; i++){
        // no carts from station, pull from A until match B
        if (st.empty()){
          while (st.empty() || st.top()!= b[i]){
            st.push(A.front());
            A.pop();
          }
          st.pop();  // send cart to B
          continue;
        }
        
        // can provide directly from station to B
        if (b[i] == st.top()){
          st.pop();
        } else if (b[i]> st.top()){
          while (st.top()!= b[i]){
            st.push(A.front());
            A.pop();
          }
          st.pop();
        } else{ // b[i]< st.top()
          // smaller cart requested is stuck under stack
          ans = false;
          break;
        }
      }  
      if (ans){
        cout<< "Yes" <<endl;
      } else{
        cout<< "No" << endl;
      }
    }
  }
}
