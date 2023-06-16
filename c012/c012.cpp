#include <bits/stdc++.h>
#define MAX 128
using namespace std;

// there are 128 printable ascii characters
struct Node{
  int ascii;
  int fre;
};

bool cmp(Node a, Node b){
  if (a.fre == b.fre) return (a.ascii > b.ascii);
  else return (a.fre < b.fre);
}
int main() {
  // index is ascii 
  Node a[MAX];
  string s;
  while(getline(cin,s)){
    memset(a,0,sizeof(a));
    for(int i = 0; i<s.length(); i++){
      int index = (int)s[i];
      a[index].ascii = index;
      a[index].fre += 1;
    }
    sort(a, a+MAX, cmp);
    for(int i =0; i< MAX; i++){
      if (a[i].fre>0){
        cout<< a[i].ascii<<" "<<a[i].fre<<endl;
      }
    }
  }
}
