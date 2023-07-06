#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, u, d, f;
  while (cin>> h>>u>>d>>f){
    if (h == u && u == d && d== f && f==0){
      break;
    }
    
    double loss = u * f / 100.0 ;
    double current = 0;
    double climb = u;
    int day = 1;
    bool fail = false;
    while (true){
      if (climb > 0)
        current += climb;
      // climbed exceeded height
      if (current > h){
        break;
      }
      climb -= loss; // lose climbing capacity
      current-= d; // night time
      if (current < 0) {
        fail = true;
        break;
      }
      day += 1;
    }
    if (fail){
      cout<< "failure on day "<< day << endl;
    } else{
      cout<< "success on day " << day << endl;
    }
  }
}
