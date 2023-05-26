#include <bits/stdc++.h>

using namespace std;

// helper function to convert records to integer for simplicity
int convert(string s){
  if (s.compare("1B") == 0) return 1;
  if (s.compare("2B") == 0) return 2;
  if (s.compare("3B") == 0) return 3;
  if (s.compare("HR") == 0) return 4;
  if (s.compare("FO") == 0) return -1;
  if (s.compare("GO") == 0) return -1;
  if (s.compare("SO") == 0) return -1;
}

int main(){
  int record[9][5];
  int a, b;
  string ele;
  int bases[3];
  while (cin>>a){
    //intialize array values
    memset (record, 0, sizeof(record));
    memset (bases, 0, sizeof(bases));

    /*
      in this question constant range using double for loop is not costly
    */

    // take in first row of inputs
    for (int i= 0; i < a; i++){
      cin >> ele;
        record[0][i] = convert(ele);
    }
    
    // take in inputs
    for (int i=1; i< 9; i++){
      cin >> a;
      for (int j = 0; j < a; j++){
        cin >> ele;
        record[i][j] = convert(ele);
      }
    }
    cin>>b;

    // going round by round (column)
    int current_out = 0;
    int round_out = 0;
    int score = 0;
    for (int col =0; col<5; col++){
      for (int row=0; row<9; row++){
        // if record is an out
        if (record[row][col] == -1){
          current_out += 1;
          round_out += 1;
          if (current_out == b){
            goto jump;
          }

          if (round_out ==3){
            round_out = 0;
            memset (bases, 0, sizeof(bases));
          }
        }

        else if (record[row][col] != 0){
          // update base record
          // concept each person on the base runs individually
          for (int i =2; i >= 0; i--){
            if (bases[i] == 1){
              bases[i] = 0;
              // return to home base
              if ((i+record[row][col]) >= 3){
                score += 1;
              }
              else{
                bases[i+record[row][col]] = 1;
              }
            }
          }
          // put the one who pitched on base
          if (record[row][col] == 4){
            score += 1;
          } else{
            bases[record[row][col] - 1] = 1;
          }
          
        }

        
      }
    }
    
    jump:
      cout<< score <<endl;

    
  }
}
