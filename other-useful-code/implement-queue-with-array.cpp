#include <iostream>
using namespace std;
void insertQueue(int);
int deleteQueue();
void printQueue();
struct Queue{
  int q[100];
  int back;
  int front;
  Queue(){ back=-1,front=-1;}
};
Queue qu;
int main(){
  for(int i=1;i<5;i++){
    insertQueue(i);
    printQueue();   
  }
  cout<<"從Queue取出最前面的元素為"<<deleteQueue()<<endl; 
  printQueue();
}
void insertQueue(int n){
  if(qu.back == 99) {
    cout << "Queue是滿的" << endl;
  } else {    
    qu.q[++qu.back]=n;
  }
}
int deleteQueue(){
  if(qu.front == qu.back) {
    cout << "Queue是空的" << endl; 
  } else {
    return qu.q[++qu.front];
  }
}
void printQueue(){
  cout << "Queue目前儲存的元素有";
  for(int i=qu.front+1;i<=qu.back;i++){
    cout << qu.q[i] <<" ";
  }
  cout << endl;  
}
