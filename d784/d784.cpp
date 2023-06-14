#include <bits/stdc++.h>
using namespace std;


int main() {
  int n;
  cin>> n;
  for (int i = 0; i<n; i++){
    int sum = 0, max = -10000000, nums, num;
    cin>>nums;
		for (int j =0; j< nums; j++){  
			cin>>num;
      sum += num;
      // avoids if cumulative sum is smaller than the max value we've seen 
      if (sum > max){
        max = sum;
      }
      if (sum < 0){
        sum = 0;
      }
		}
    cout<< max << endl;
  }
}
