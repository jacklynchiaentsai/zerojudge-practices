#include <bits/stdc++.h>
using namespace std;

deque<int> graph[100001];
int md;

// DFS stores the distance between the longest two children to md
int DFS(int curr){
  // bottom up
  // no child
  if (graph[curr].size()==0)
    return 0;
  else if (graph[curr].size() == 1)
    return DFS(graph[curr][0]) + 1;
  else{
    // stores the top two longest child length
    // they will be able to reach each other through parent node
    int m1, m2, result;
    for (int i=0; i< graph[curr].size(); i++){
      // length of current node from child
      result = DFS(graph[curr][i]) + 1;
      if (i ==0)
        m1 = result;
      else if (i == 1){
        if (result > m1){
          m2 = m1;
          m1 = result;
        } else{
          m2 = result;
        }
      } else{
        if (result >= m1){
          m2 = m1;
          m1 = result;
        } else if (result > m2){
          m2 = result;
        }
      } 
    }

    md = max(m1+m2, md);
    // return the longest distance as of now
    return m1;
  }
}

int main() {
  // increasing cin cout speed
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  while (cin>>n){
    // for identifying root node
    bool ischild[n];
    md = 0;
    // initialization
    for(int i =0; i<n; i++){
      graph[i].clear();
      ischild[i] = false;
    }

    // taking in inputs
    for(int i=0; i<n-1; i++){
      int a,b;
      cin>>a>>b;
      graph[a].push_back(b);
      ischild[b] = true;
    }

    int root;
    for(int i=0; i<n; i++){
      if (!ischild[i]){
        root = i;
        break;
      }
    }

    // 從root 出發最長的深度
    int rd = DFS(root);
    cout<< max(rd, md)<< endl;
  }
}
