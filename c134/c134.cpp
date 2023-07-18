#include <bits/stdc++.h>
using namespace std;

/*
  what the question is asking for:
  - sum is N
  - want the nums that yield maximum product but no repeating nums
*/
int main() {
  int cases, n;
  cin>> cases;
  while (cases--){
    cin>>n;
    vector<int> nums;
    // in comparison to adding an individual num by 1, it's better to have one more num
    // maximimizing the number of nums
    // 1 is unhelpful in incrementing the product
    for(int i=2; i<=n; i++){
      nums.push_back(i);
      n -= i;
    }

    // have maximized the number of nums
    // no repeating nums increment 1 backwards from endIndex until sum is n
    for(int i = nums.size()-1; n>0 ; i--){
      nums[i] += 1;
      n -= 1;

      if (i ==0)
        i = nums.size();
    }

    for(int i=0; i<nums.size(); i++){
      if (i == nums.size()-1)
        cout<< nums[i] << endl;
      else
        cout<< nums[i] << " ";
    }
    cout<< endl;
    
  }
}
