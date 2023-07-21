#include <bits/stdc++.h>
# define BOUND 8
using namespace std;
char chess[BOUND][BOUND];
// direct simulation, no strategy
// using helper methods for cleaner code

bool withinbounds(int row, int column){
  if (row >=0 && row <8 && column >=0 && column<8)
    return true;
  else
    return false;
}

bool rowcolcheck(int row, int col, bool upper){
  char targetKing;
  if(upper)
    targetKing = 'k';
  else
    targetKing = 'K';
  
  // left check
  for(int i=col-1; i>=0; i--){
    if (chess[row][i] == '.')
      continue;
    else if (chess[row][i] == targetKing)
      return true;
    else 
      break;
  }

  // rightcheck
  for(int i=col+1; i< BOUND; i++){
    if (chess[row][i] == '.')
      continue;
    else if (chess[row][i] == targetKing)
      return true;
    else 
      break;
  }

  // upper check
  for(int i=row-1; i>=0; i--){
    if (chess[i][col] == '.')
      continue;
    else if (chess[i][col] == targetKing)
      return true;
    else 
      break;
  }

  // lower check
  for(int i=row+1; i< BOUND; i++){
    if (chess[i][col] == '.')
      continue;
    else if (chess[i][col] == targetKing)
      return true;
    else 
      break;
  }

  return false;
}

bool diagcheck(int row, int col, bool upper){
  char targetKing;
  if(upper)
    targetKing = 'k';
  else
    targetKing = 'K';

  // upper left check
  int currow = row-1, curcol = col-1;
  while (withinbounds(currow, curcol)){
    if (chess[currow][curcol] == '.'){
      currow-- ;
      curcol-- ;
    }
    else if (chess[currow][curcol] == targetKing)
      return true;
    else 
      break;
  }

  // upper right check
  currow = row-1, curcol = col+1;
  while (withinbounds(currow, curcol)){
    if (chess[currow][curcol] == '.'){
      currow-- ;
      curcol++ ;
    }
    else if (chess[currow][curcol] == targetKing)
      return true;
    else 
      break;
  }

  // lower left check
  currow = row+1, curcol = col-1;
  while (withinbounds(currow, curcol)){
    if (chess[currow][curcol] == '.'){
      currow++ ;
      curcol-- ;
    }
    else if (chess[currow][curcol] == targetKing)
      return true;
    else 
      break;
  }

  // lower right check
  currow = row+1, curcol = col+1;
  while (withinbounds(currow, curcol)){
    if (chess[currow][curcol] == '.'){
      currow++ ;
      curcol++ ;
    }
    else if (chess[currow][curcol] == targetKing)
      return true;
    else 
      break;
  }

  return false;
}

bool kingcheck(int row, int col, bool upper){
  char targetKing;
  if(upper)
    targetKing = 'k';
  else
    targetKing = 'K';

  int rowvar[3] = {-1, 0, 1};
  int colvar[3] = {-1, 0, 1};

  for(int i=0; i< 3; i++){
    for (int j = 0; j< 3; j++){
      int currow = row +rowvar[i];
      int curcol = col + colvar[j];
      if (!withinbounds(currow, curcol))
        continue;
      else if (i == 0 && i == j)
        continue;
      else if (chess[currow][curcol] == targetKing)
        return true;
    }
  }
  return false;
}

bool knightcheck(int row, int col, bool upper){
  char targetKing;
  if(upper)
    targetKing = 'k';
  else
    targetKing = 'K';

  int rowvar[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
  int colvar[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

  for(int i=0; i< 8; i++){
    int currow = row +rowvar[i];
    int curcol = col + colvar[i];
    if (!withinbounds(currow, curcol))
      continue;
    else if (chess[currow][curcol] == targetKing)
      return true;
  }
  return false;
}

bool pawncheck(int row, int col, bool upper){
  char targetKing;
  int currow;
  int colvar[2] = {-1, 1};
  
  if(upper){
    targetKing = 'k';
    currow = row - 1;
  } 
  else{
    targetKing = 'K';
    currow = row + 1;
  }

  for (int i=0; i< 2; i++){
    int curcol = col + colvar[i];
    if (withinbounds(currow, curcol)){
      if (chess[currow][curcol] == targetKing)
        return true;
    }
  }

  return false;
    
}

int main() {
  int game = 1;
  while (true){
    bool checkwhite = true;
    bool check = false;
    string input;
    bool alldots = true;
    
    // taking in input
    for(int i=0; i<BOUND; i++){
      cin>> input;
      for(int j = 0; j<BOUND; j++){
        if (input[j] != '.')
          alldots = false;
        chess[i][j] = input[j];
      }
    }

    // checks if ending condition
    if (alldots)
      break;

    for (int i=0; i<BOUND; i++){
      for(int j=0; j<BOUND; j++){
        if (chess[i][j] == '.'){
          continue;
        } else if (tolower(chess[i][j]) == 'r'){
          if (rowcolcheck(i,j,isupper(chess[i][j]))){
            if (isupper(chess[i][j]))
              checkwhite = false;
            check = true;
            goto Result;
          }
        } else if (tolower(chess[i][j]) == 'b'){
          if (diagcheck(i,j,isupper(chess[i][j]))){
            if (isupper(chess[i][j]))
              checkwhite = false;
            check = true;
            goto Result;
          }
        } else if (tolower(chess[i][j]) == 'q'){
          if (diagcheck(i,j,isupper(chess[i][j])) || rowcolcheck(i,j,isupper(chess[i][j]))){
            if (isupper(chess[i][j]))
              checkwhite = false;
            check = true;
            goto Result;
          }
        } else if (tolower(chess[i][j]) == 'k'){
          if (kingcheck(i,j,isupper(chess[i][j]))){
            if (isupper(chess[i][j]))
              checkwhite = false;
            check = true;
            goto Result;
          }
        } else if (tolower(chess[i][j]) == 'n'){
          if (knightcheck(i,j,isupper(chess[i][j]))){
            if (isupper(chess[i][j]))
              checkwhite = false;
            check = true;
            goto Result;
          }
        } else if (tolower(chess[i][j]) == 'p'){
          if (pawncheck(i,j,isupper(chess[i][j]))){
            if (isupper(chess[i][j]))
              checkwhite = false;
            check = true;
            goto Result;
          }
        }
      }
    }

    Result:
      cout<< "Game #"<< game++<<": ";
      if (check){
        if(checkwhite){
          cout<< "white ";
        } else{
          cout<< "black ";
        }
        cout<< "king is in check."<< endl;
      } else{
         cout<< "no king is in check."<< endl;
      }
        
  }
  
}
