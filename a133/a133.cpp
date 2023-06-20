#include <bits/stdc++.h>
using namespace std;


int main() {
  int n1, n2, count = 1;
  int lcs[101][101];
  while (cin>>n1>>n2){
    if ((n1 == n2) && (n1==0))
      break;
    
    int first[n1],second[n2];
    for(int i = 0; i< n1; i++)
      cin >> first[i];
    for(int i = 0; i< n2; i++)
      cin >> second[i];
    
    memset(lcs,0, sizeof(lcs));

    for(int i = 0; i< n1; i++){
      for (int j = 0; j< n2; j++){
        if (first[i] == second[j]){
          lcs[i+1][j+1] = lcs[i][j] + 1;
        } else{
          lcs[i+1][j+1] = max(lcs[i+1][j], lcs[i][j+1]);
        }
      }
    }

    cout<< "Twin Towers #"<< count++ << endl;
    cout<< "Number of Tiles : "<< lcs[n1][n2]<<endl;
    cout<< endl;
    
  }
}
