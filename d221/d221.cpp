#include <bits/stdc++.h>
using namespace std;
/*
concept: greedy every time add the smallest two elements to avoid
cumulative extra costs  -> use priority queue
*/
int main() {
  int n;
  while (cin>>n){
    if (n == 0) break;
    priority_queue<long long int, vector<long long int>, greater<long long int> > pq;
    for (int i = 0; i< n; i++){
      long long int ele;
      cin>> ele;
      pq.push(ele);
    }

    long long int cost = 0;
    while (pq.size() > 1){
      long long int firstNum = pq.top();
      pq.pop();
      long long int secNum = pq.top();
      pq.pop();
      long long int sum = firstNum + secNum;
      cost+= sum;
      pq.push(sum);
    }
    cout<< cost <<endl;
  }
}
