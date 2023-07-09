#include <bits/stdc++.h>
using namespace std;


int main() {
  int s, day = 1, time[481];
  while(cin>>s){
    memset(time, 0, sizeof(time));
    cin.ignore();
    string str, temp;
    for (int i=0; i<s; i++){
      int count = 0;
      string start, end;
      int startindex, endindex;
      getline(cin,str);
      stringstream ss(str);
      while (ss>> temp){
        if (count ==0)
          start = temp;
        else if (count == 1)
          end = temp;
        else
          break;
        count += 1;
      }
      
      startindex = stoi(start.substr(0, 2))*60 + stoi(start.substr(3,2)) - 600;
      endindex = stoi(end.substr(0, 2))*60 + stoi(end.substr(3,2)) - 600;
      // note end time is non inclusive
      for(int i = startindex; i< endindex; i++){
        time[i] = 1; // indicate schedule
      }
    }
    
    time[480] = 1; // marking end time
    int maxmins = 0;
    int maxstart;
    int cumstart;
    int cummins = 0;
    for (int i=0; i< 481; i++){
      if (time[i] == 0 && cummins ==0){
        cumstart = i + 600;
        cummins += 1;
      } else if (time[i] ==0 && cummins >0){
        cummins += 1;
      } else if (time[i] == 1 && cummins >0){
        if (cummins > maxmins){
          maxmins = cummins;
          maxstart = cumstart;
        }
        cummins = 0;
      }
    }

    // converting starttime to hh:mm format
    string starttime = to_string(maxstart/60) + ":";
    if ((maxstart%60) < 10)
      starttime += "0" + to_string(maxstart%60);
    else
      starttime += to_string(maxstart%60);

    cout<< "Day #"<< day<<": the longest nap starts at "<< starttime<< " and will last for ";

    if (maxmins <60){
      cout<< maxmins << " minutes."<< endl;
    } else{
      cout<< maxmins/60 <<" hours and "<< maxmins%60 << " minutes."<< endl;
    }

    day += 1;
  }
}
