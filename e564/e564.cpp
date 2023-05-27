#include <bits/stdc++.h>
using namespace std;


int main(){
  int t, count =0;
  while (cin>>t){
    count++;
    if (t==0){
      break;
    }
    
    cout<< "Scenario #"<< count << endl;
    
    // initialize array of individual team queues
    queue<int> team[t];
    // initialize person-team array
    int id[1000000];
    // initialize team queue
    queue<int> teamQ;
    
    int n, xi;
    // populate id array with input
    for (int i = 0; i< t; i++){
      cin>>n;
      for (int j = 0; j< n; j++){
        cin>>xi;
        id[xi] = i;
      }
    }

    cin.ignore();
    string instruct;
    while (getline(cin, instruct)){
      if (instruct.compare("STOP") == 0){
        cout<<"\n";
        break;
      } else if (instruct.compare("DEQUEUE") == 0){
        int firstTeam = teamQ.front();
        cout<< team[firstTeam].front()<< endl;
        team[firstTeam].pop();
        if (team[firstTeam].empty()){
          teamQ.pop();  // remove empty team
        }
      } else{  // must be enqueue
        string command;
        string personstr;
        int person;
        stringstream ss(instruct);
        ss >> command;
        ss >> personstr;
        person = stoi(personstr);

        int teamNum = id[person];
        if (team[teamNum].empty()){
          team[teamNum].push(person);
          teamQ.push(teamNum);  // lining up last of team queue
        } else{
          team[teamNum].push(person);
        }
      }
      
    }
  }
}
