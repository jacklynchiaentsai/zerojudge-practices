#include <bits/stdc++.h>
using namespace std;


int main() {
  int n;
  while (cin>>n){
    int stomach[101];
    memset(stomach, 0, sizeof(stomach));
    int a,b;
    for (int i =0; i<n;i++){
      cin>>a>>b;
      for (int j = 100; j>=a; j--){
        int newValue = b + stomach[j-a];
        if (newValue> stomach[j]){
          stomach[j] = newValue;
        }
      }
    }
    cout<< stomach[100]<<endl;   
  }
}
