#include <bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin>> n;
  string s;
  // prevent the first \n being caught by getline
  cin.ignore();
  for (int count = 0; count<n; count++){
    //for reading empty string
    getline(cin,s);
    if (s.length() == 0){
      cout<< "Yes" << endl;
      continue;
    }

    bool match = true;
    stack<char> mystack;
    for (int i=0; i<s.length(); i++){
      
      if (s[i] == '(' || s[i] == '['){
        mystack.push(s[i]);
      } else if (s[i] == ')' || s[i] == ']') {
        // consider case if stack is empty
        if (mystack.empty()){
          match = false;
          break;
        }
        
        char tmp = mystack.top();
        if ((tmp == '(' && s[i] == ')') || (tmp =='[' && s[i] ==']')){
          mystack.pop();
        } else{
          match = false;
          break;
        }
      }
      
    }

    // check if there are any characters left in stack
    if (!mystack.empty()){
      match = false;
    }
    
    if (match){
      cout<< "Yes" << endl;
    } else{
      cout<< "No" << endl;
    }   
  }
}
