#include <bits/stdc++.h>

using namespace std;
int main() {
  int num;
  while(cin>>num){
    int stu[num];
    for(int i = 0; i< num; i++){
      cin>> stu[i];
    }
    
    sort(stu, stu+num);
    bool allfail = true, allpass = true;
    int largestFail = -1, smallestPass = 101;
    for(int i=0; i<num; i++){
      if (i==num-1){
        cout<< stu[i] <<endl;
      } else{
        cout<< stu[i] << " ";
      }

      if (stu[i] <60){
        allpass = false;
        if (stu[i] > largestFail){
          largestFail = stu[i];
        }
      } else{
        allfail = false;
        if (stu[i] < smallestPass){
          smallestPass = stu[i];
        }
      }
    }

    if (allpass){
      cout<<"best case"<<endl;
    } else{
      cout<< largestFail << endl;
    }

    if (allfail){
      cout<< "worst case"<<endl;
    }else{
      cout<< smallestPass <<endl;
    }
    
  }
}
