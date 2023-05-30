#include <bits/stdc++.h>
using namespace std;

struct item{
  long long int w;
  long long int f;
};

bool cmp(item a, item b){
  // stacking have to withstand other's weight
  // stack the smaller product on top
  return a.w*b.f < b.w*a.f;
}
int main() {
  long long int n;
  while (cin>>n){
    item li[n];
    for(int i = 0; i<n; i++){
      cin>>li[i].w;
    }
    for (int i = 0; i<n; i++){
      cin>>li[i].f;
    }
    sort(li, li+n, cmp);
    long long int energy = 0;
    long long int weight = 0;
    
    for (int i = 0; i<n; i++){
      energy += weight * li[i].f;
      weight += li[i].w;
    }
    
    cout<< energy<< endl;
  }
}
