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
  cout << "�qStack���X�̤W����������"<<pop()<<endl; 
  printStack();
}
void push(int n){
  if(st.top == 99) {
    cout << "Stack�O����" << endl;
  } else {    
    st.s[++st.top]=n;
  }
}
int pop(){
  if(st.top == -1) {
    cout << "Stack�O�Ū�" << endl; 
  } else {
    return st.s[st.top--];
  }
}
void printStack(){
  cout << "Stack�ثe�x�s��������";
  for(int i=0;i<=st.top;i++){
    cout << st.s[i] <<" ";
  }
  cout << endl;  
}
