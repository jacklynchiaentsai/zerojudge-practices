#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  while (cin>>n){
    int myfriend[n]; 
    int visited[n];   
    int groups = 0;
    //initialize
    memset (visited, 0, sizeof(visited));

    // get input
    for (int i = 0; i< n; i++){
      cin >> myfriend[i];
    }

    for (int i =0; i<n; i++){
      if (visited[i] != 0){
        continue;
      } else{
        int nextFriend = myfriend[i];
        // have no friends
        if (nextFriend == i){
          groups += 1;
        } else{
          while (nextFriend != i){
            visited[nextFriend] = 1;
            nextFriend = myfriend[nextFriend];
          }
          groups += 1;
        }
      }
    }

    cout<< groups << endl;
    
  }
}
