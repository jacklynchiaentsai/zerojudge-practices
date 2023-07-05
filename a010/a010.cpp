#include <bits/stdc++.h>
using namespace std;

// 質因數會在他的倍數前出現

int main() {
  long long int n;
  while (cin>>n){
    for (int i = 2; i <= n; i++){
      int count = 0;
      while (n % i == 0){
        count += 1;
        n /= i;
      }
      
      if (count == 0){
        continue;
      } else if (count == 1){
        cout<< i;
      } else{
        cout<< i << "^" << count;
      }

      if (n== 1){
        cout<< endl;
        break;
      } else{
        cout<< " * ";
      }
    }
  }
}
