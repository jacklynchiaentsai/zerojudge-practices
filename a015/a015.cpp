#include <bits/stdc++.h>
using namespace std;


int main() {
  int row, col;
  while (cin>> row>> col){
    int a[row][col];
    for(int i = 0; i< row; i++){
      for (int j = 0; j< col; j++)
        cin>>a[i][j]; 
    }

    for(int i = 0; i< col; i++){
      for (int j = 0; j< row; j++){
        if (j == row-1) 
          cout<<a[j][i]<< endl;
        else
          cout<<a[j][i]<<" ";
      }
    }
    cout<< endl;
  }
}
