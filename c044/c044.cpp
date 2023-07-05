#include <bits/stdc++.h>
using namespace std;
struct Node{
  char alpha;
  int freq = 0; // default initial value
};

bool cmp(Node a, Node b){
  if (a.freq == b.freq){
    int anum = a.alpha - 'A';
    int bnum = b.alpha - 'A';
    return (anum < bnum);
  } else{
    return (a.freq > b.freq);
  }
}

int main() {
  int n;
  while (cin>>n){
    string s;
    // 26 represents each alphabetical character
    Node arr[26];
    cin.ignore();
    for (int i = 0; i<n; i++){
      getline(cin, s);
      for (int j = 0; j< s.length(); j++){
        if (!isalpha(s[j]))
          continue;
        s[j] = toupper(s[j]);
        int index = s[j] -'A';
        arr[index].alpha = s[j];
        arr[index].freq += 1;
      }
    }
    sort (arr, arr + 26, cmp);
    for (int i = 0 ; i< 26; i++){
      if (arr[i].freq == 0)
        break;
      cout<< arr[i].alpha << " " << arr[i].freq << endl;
    }
  }
}
