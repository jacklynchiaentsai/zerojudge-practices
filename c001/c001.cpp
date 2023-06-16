#include <bits/stdc++.h>
using namespace std;


int main() {
  string s1, s2;
  int lcs[1001][1001];
  while(getline(cin,s1)){
    getline(cin, s2);
    memset(lcs, 0, sizeof(lcs));
    int s1len = s1.length();
    int s2len = s2.length();
    for (int i = 0; i< s1len; i++){
      for (int j = 0; j< s2len; j++){
        // same character
        if (s1[i] == s2[j]){
          lcs[i+1][j+1] = lcs[i][j] +1;
        } else{
          lcs[i+1][j+1] = max(lcs[i][j+1], lcs[i+1][j]);
        }
      }
    }
    cout<< lcs[s1len][s2len]<< endl;
  }
}
