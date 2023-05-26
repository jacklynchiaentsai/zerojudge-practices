#include <bits/stdc++.h>
using namespace std;


int main(){
  int firstNum, secNum;
  string s, ele;
  while (getline(cin,s)){
    // access each element on string separated by space individually 
    stringstream ss(s);
    stack<int> st;
    while (ss >> ele){
      if (ele.compare("+") == 0){
        secNum = st.top();
        st.pop();
        firstNum = st.top();
        st.pop();
        int result = firstNum + secNum;
        st.push(result);
      } else if (ele.compare("-") == 0){
        secNum = st.top();
        st.pop();
        firstNum = st.top();
        st.pop();
        int result = firstNum - secNum;
        st.push(result);
      } else if (ele.compare("*") == 0){
        secNum = st.top();
        st.pop();
        firstNum = st.top();
        st.pop();
        int result = firstNum * secNum;
        st.push(result);
      } else if (ele.compare("/") == 0){
        secNum = st.top();
        st.pop();
        firstNum = st.top();
        st.pop();
        int result = firstNum / secNum;
        st.push(result);
      } else{
        // number
        int num = stoi(ele);
        st.push(num);
      }
    }

    cout<< st.top() << endl;
  }
}
