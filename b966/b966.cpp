#include <bits/stdc++.h>
using namespace std;

typedef struct _segment{
  int start;
  int end;      
}Segment;

// sort by increasing order of start
// if start are the same sort by decreasing order of end
bool cmp (Segment a, Segment b){
  if (a.start == b.start) return a.end>b.end;
  return a.start<b.start;
}

int main() {
  int num;
  while(cin>>num){
    Segment a[num];
    // taking inputs
    for(int i = 0; i< num; i++){
      cin>> a[i].start >> a[i].end;
    }
    
    // sorting by our cmp function
    sort(a, a+num, cmp);

    Segment baseSegment;
    baseSegment.start = a[0].start;
    baseSegment.end = a[0].end;
    
    int length = baseSegment.end - baseSegment.start;
    for (int i =1; i< num; i++){
      // segment is contained in baseSegment
      if (a[i].start >= baseSegment.start && a[i].end <= baseSegment.end){
        continue;
      } else if (a[i].start >= baseSegment.start && a[i].start <= baseSegment.end){
        // segment start point is in baseSegment but extends longer
        length += a[i].end - baseSegment.end;
        baseSegment.end = a[i].end;
      } else{
        // segment start point is beyond baseSegment
        length += a[i].end - a[i].start;
        baseSegment.start = a[i].start;
        baseSegment.end = a[i].end;
      }
    }
    cout<< length<< endl;
  }
  
}
