#include <iostream>
using namespace std;
void push(int);
int pop();
void printStack();
struct Stack{
  int s[100];
  int top;
  Stack(){top=-1;}
};
Stack st;
int main(){
  for(int i=1;i<=4;i++){
    push(i);
    printStack();
  }
  cout << "從Stack取出最上面的元素為"<<pop()<<endl; 
  printStack();
}
void push(int n){
  if(st.top == 99) {
    cout << "Stack是滿的" << endl;
  } else {    
    st.s[++st.top]=n;
  }
}
int pop(){
  if(st.top == -1) {
    cout << "Stack是空的" << endl; 
  } else {
    return st.s[st.top--];
  }
}
void printStack(){
  cout << "Stack目前儲存的元素有";
  for(int i=0;i<=st.top;i++){
    cout << st.s[i] <<" ";
  }
  cout << endl;  
}
