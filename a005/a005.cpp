#include <bits/stdc++.h>
using namespace std;
int main() {
  int num;
  cin>> num;
  for(int i=0; i< num; i++){
    int seq[5];
    bool isArithmetic = true;
    for (int j = 0; j< 4; j++){
      cin>> seq[j];
    }
    int cd = seq[1]- seq[0], cf = seq[1]/ seq[0];
    cout<< seq[0]<<" "<<seq[1]<<" ";
    for (int j = 2; j< 5; j++){
      if (j == 4){
        if (isArithmetic){
          cout<< seq[j-1] + cd <<endl;
        }else{
          cout<< seq[j-1] * cf<<endl;
        }
      } else{
        cout<< seq[j] << " ";
        if ((seq[j]- seq[j-1]) != cd){
          isArithmetic =false;
        }
      }
    }
  }
}
