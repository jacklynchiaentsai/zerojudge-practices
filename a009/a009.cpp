#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int k = '*' - '1';
  while (getline(cin,s)){
    for (int i = 0; i< s.length(); i++){
      cout<< (char)(s[i] + k);
    }
    cout<< endl;
  }
}
