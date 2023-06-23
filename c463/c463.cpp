#include <bits/stdc++.h>
using namespace std;


int main() {
  int n;
  while (cin>>n){
    // stores parent of each node either one or none (root)
    long long int parent[n+1];
    long long int maxheight[n+1];
    long long int numchilds[n+1]; // stores the number of childs in each node
    queue <long long int> leafs; // queue for storing leaf nodes

    // initialize values
    memset(parent, 0, sizeof(parent));
    memset(maxheight, -1, sizeof(maxheight));
    
    for (int i = 1; i<=n; i++){
      cin>>numchilds[i];
      if (numchilds[i] ==0){
        leafs.push(i);
        maxheight[i] = 0;
      } else{
        int child;
        for(int j = 0; j<numchilds[i]; j++){
          cin>>child;
          parent[child] = i;
        }
      }
    }

    // update the height from bottom up
    long long int leaf;
    while (!leafs.empty()){
      leaf = leafs.front();
      leafs.pop();
      maxheight[parent[leaf]] = max(maxheight[parent[leaf]], maxheight[leaf] + 1);
      numchilds[parent[leaf]] -= 1;

      if (numchilds[parent[leaf]] == 0){
        leafs.push(parent[leaf]);
      }
    }

    long long int sum = 0;
    for (int i = 1; i<=n; i++){
      sum += maxheight[i];
    }
    // the last node that turns into leaf node is the root node
    cout<< leaf <<endl;
    cout<< sum <<endl;
    
  }
}
