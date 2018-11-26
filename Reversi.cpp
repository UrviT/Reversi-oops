/*
Works like Reversi with additional features.
*/

#include "myHeader.h"
void showState();                                     //displays the board whatsoever it may be
void tellValid(int row, int column, char color);      //if the move is legal or not
void tellValid2(int row, int column, char color);      //if the move is legal or not
void implement(int row, int column, char color);
void tellScore();                                    //prints both players' points
int oneWins();
int isFilled(int row, int column);
void tellValidInRow(int row, int column, int color);
void tellValidInColumn(int row, int column, int color);
void tellValidInDiagonal(int row, int column, int color);
inline int constraints(int row, int column){
    return((row<D && row>0 && column<D && column>0 /*&& !isFilled(row,column)*/));
}
char notColor(char colour){
  if(colour == 'X')
    return ('O');
  else if(colour=='O')
    return ('X');
}
void delay(clock_t a)
{
    clock_t start;
    start  = clock();
    while(clock()-start<a)
    {

    }
}
char board[D][D];

int main() {
  welcome();
  delay(3000);
  system("cls");
  // initialState();
  int row,column;
  for (int i = 0; i < D; i++) {
    for (int j = 0; j < D; j++) {
      if((i==D/2 && j==(D/2)-1 )||(j==D/2 && i==(D/2)-1))
        board[i][j]=O;
      else if((i==D/2 && j==(D/2))||((j==(D/2)-1) && i==(D/2)-1))
        board[i][j]=X;
      else
        board[i][j]='-';
    }
  }
  showState();
  tellScore();
  int x,y;
  while(!oneWins()){
    cout<<"X moves: ";
    cin>>x>>y;
    if (!isFilled(x-1,y-1)) {
      tellValid2(x-1,y-1,X);
      implement(x-1,y-1,X);
      showState();
      tellScore();
    }
    else
      cout<<"Invalid move"<<endl;
    cout<<"O moves: ";
    cin>>x>>y;
    if (!isFilled(x-1,y-1)) {
      tellValid2(x-1,y-1,O);
      implement(x-1,y-1,O);
      showState();
      tellScore();
    } else {
      cout<<"Invalid move"<<endl;
    }
  }
  return 0;
}

void showState() {
  cout<<endl;
  cout<<"\t\t"<<1<<"    "<<2<<"    "<<3<<"    "<<4<<"    "<<5<<"    "<<6<<"    "<<7<<"    "<<8<<endl<<endl;
  for (int i = 0; i < D; i++) {
    cout<<"\t "<<(i+1)<<"\t";
    for (int j = 0; j < D; j++) {
      cout<<board[i][j]<<"    ";
    }
    cout<<endl<<endl;
  }
  return;
}

void tellValid2(int row, int column, char color) {
  int check=0;
  int r,c;
  r=row,c=column;
  if (board[r][c-1]==notColor(color)) {
    c=c-2;
    while(board[r][c]!=color && constraints(r,c)) {
      if (!isFilled(r,c)) {
        // cout<<"1 Not valid"<<endl;
        break;
      } else {
        check++;
        c--;
        // cout<<" white conti... "<<endl;
      }
    }
    if (board[r][c]==color) {
      // cout<<" Valid & return "<<endl;
      return;
    }
  } else if (board[r][c+1]==notColor(color)) {
    c++;
    c++;
    while(board[r][c]!=color && constraints(r,c)){
      if (!isFilled(r,c)) {
        // cout<<"2 Not valid"<<endl;
        break;
      } else {
        c++;
      }
    }
    if (board[r][c]==color) {
      // cout<<" Valid & return "<<endl;
      return;
    }
  } else if (board[r-1][c]==notColor(color)) {
    r--;
    r--;
    while(board[r--][c]!=color && constraints(r,c)){
      if (!isFilled(r,c)) {
        // cout<<"3 Not valid"<<endl;
        break;
      } else {
        r--;
      }
    }
    if (board[r][c]==color) {
      // cout<<" Valid & return "<<endl;
      return;
    }
  } else if (board[r+1][c]==notColor(color)) {
    r++;
    r++;
    while(board[r][c]!=color && constraints(r,c)){
      if (!isFilled(r,c)) {
        // cout<<"4 Not valid"<<endl;
        break;
      } else {
        r++;
      }
    }
    if (board[r][c]==color) {
      // cout<<" Valid & return "<<endl;
      return;
    }
  } else if(board[r+1][c-1]==notColor(color)) {
    c--;
    c--;
    r++;
    r++;
    while(board[r][c]!=color && constraints(r,c)){
      if (!isFilled(r,c)) {
        // cout<<"5 Not valid"<<endl;
        break;
      } else {
        c--;
        r++;
      }
    }
    if (board[r][c]==color) {
      // cout<<" Valid & return "<<endl;
      return;
    }
  } else if(board[r-1][c+1]==notColor(color)) {
    c++;
    c++;
    r--;
    r--;
    while(board[r][c]!=color && constraints(r,c)){
      if (!isFilled(r,c)) {
        // cout<<"6 Not valid"<<endl;
        break;
      } else {
        c++;
        r--;
      }
    }
    if (board[r][c]==color) {
      // cout<<" Valid & return "<<endl;
      return;
    }
  } else if (board[r-1][c-1]==notColor(color)) {
    c--;
    c--;
    r--;
    r--;
    while(board[r][c]!=color && constraints(r,c)){
      if (!isFilled(r,c)) {
        // cout<<"7 Not valid"<<endl;
        break;
      } else {
        c--;
        r--;
      }
    }
    if (board[r][c]==color) {
      // cout<<" Valid & return "<<endl;
      return;
    }
  } else if (board[r+1][c+1]==notColor(color)) {
    c++;
    c++;
    r++;
    r++;
    while(board[r][c]!=color && constraints(r,c)) {
      if (!isFilled(r,c)) {
        // cout<<"8 Not valid"<<endl;
        break;
      } else {
        c++;
        r++;
      }
    }
    if (board[r][c]==color) {
      // cout<<" Valid & return "<<endl;
      return;
    }
  }
// }
  // cout<<"*******"<<endl;
  return;
}

void implement(int row, int column, char color) {
  int check=0;
  int i=0,j=0;
  int r,c;
  r=row,c=column;
  if (board[r][c-1]==notColor(color)) {
    c=c-2;
    while(board[r][c]!=color && constraints(r,c)) {
      if (!isFilled(r,c)) {
        // cout<<"1 Not valid"<<endl;
        break;
      } else {
        check++;
        c--;
        // cout<<" white conti... "<<endl;
      }
    }
    if (board[r][c]==color) {
      // cout<<"1 Valid "<<endl;
      for ( i = column; i>= c; i--) {
        board[r][i]=color;
      }
    }
  }
  r=row,c=column;
     if (board[r][c+1]==notColor(color)) {
    c++;
    c++;
    while(board[r][c]!=color && constraints(r,c)){
      if (!isFilled(r,c)) {
        // cout<<"2 Not valid"<<endl;
        break;
      } else {
        c++;
      }
    }
    if (board[r][c]==color) {
      // cout<<"2 Valid "<<endl;
      for ( i = column; i <= c; i++) {
        board[r][i]=color;
      }
    }
  }
  r=row,c=column;
    if (board[r-1][c]==notColor(color)) {
    r--;
    r--;
    while(board[r][c]!=color && constraints(r,c)){
      if (!isFilled(r,c)) {
        // cout<<"3 Not valid"<<endl;
        break;
      } else {
        r--;
      }
    }
    if (board[r][c]==color) {
      // cout<<"3 Valid "<<endl;
      for ( i = row; i >= r; i--) {
        board[i][c]=color;
      }
    }
  }
  r=row,c=column;
    if (board[r+1][c]==notColor(color)) {
    r++;
    r++;
    while(board[r][c]!=color && constraints(r,c)){
      if (!isFilled(r,c)) {
        // cout<<"4 Not valid"<<endl;
        break;
      } else {
        r++;
      }
    }
    if (board[r][c]==color) {
      // cout<<"4 Valid "<<endl;
      for ( i = row; i <= r; i++) {
        board[i][c]=color;
      }
    }
  }


  r=row,c=column;
  if(board[r+1][c-1]==notColor(color)) {
    c--;
    c--;
    r++;
    r++;
    while(board[r][c]!=color && constraints(r,c)){
      if (!isFilled(r,c)) {
        // cout<<"5 Not valid"<<endl;
        break;
      } else {
        c--;
        r++;
      }
    }
    if (board[r][c]==color) {
      // cout<<"5 Valid "<<endl;
      for ( i = row,j=column; i<=r,j>=c; i++,j--) {
        board[i][j]=color;
      }
    }
  }
  r=row,c=column;
  if(board[r-1][c+1]==notColor(color)) {
    c++;
    c++;
    r--;
    r--;
    while(board[r][c]!=color && constraints(r,c)){
      if (!isFilled(r,c)) {
        // cout<<"6 Not valid"<<endl;
        break;
      } else {
        c++;
        r--;
      }
    }
    if (board[r][c]==color) {
      // cout<<"6 Valid"<<endl;
      for ( i = row,j=column; i>=r,j<=c; i--,j++) {
        board[i][j]=color;
      }
    }
  }
  r=row,c=column;
  if (board[r-1][c-1]==notColor(color)) {
    c--;
    c--;
    r--;
    r--;
    while(board[r][c]!=color && constraints(r,c)){
      if (!isFilled(r,c)) {
        // cout<<"7 Not valid"<<endl;
        break;
      } else {
        c--;
        r--;
      }
    }
    if (board[r][c]==color) {
      // cout<<"7 Valid "<<endl;
      for ( i = row,j=column; i>=r,j>=c; i--,j--) {
        board[i][j]=color;
      }
    }
  }
 r=row,c=column;
 if (board[r+1][c+1]==notColor(color)) {
    c++;
    c++;
    r++;
    r++;
    while(board[r][c]!=color && constraints(r,c)) {
      if (!isFilled(r,c)) {
        // cout<<"8 Not valid"<<endl;
        break;
      } else {
        c++;
        r++;
      }
    }
    if (board[r][c]==color) {
      // cout<<"8 Valid "<<endl;
      for ( i = row,j=column;i<=r,j<=c; i++,j++) {
        board[i][j]=color;
      }
    }
  }
// }
  return;
}


void tellScore(){
  int x=0,o=0,empty=0;
  for (int i = 0; i < D; i++) {
    for (int j = 0; j < D; j++) {
      if (board[i][j]==X) {
        x++;
      } else if(board[i][j]==O){
        o++;
      }
      else
        empty++;
    }
  }
  if ((x+o+empty)==D*D) {
    cout<<endl<<"\t[X="<<x<<" O="<<o<<"]"<<endl;
    if (empty==0 && x>o)
      cout<<"\t\tPlayer X wins"<<endl;
    else if(empty==0 && o>x)
      cout<<"\t\tPlayer O wins"<<endl;
    return ;
  }
  else {
    cout<<"\t\t\tSomething's wrong."<<endl;
  }
  return ;
}

int oneWins(){
  int x=0,o=0,empty=0;
  for (int i = 0; i < D; i++) {
    for (int j = 0; j < D; j++) {
      if (board[i][j]==X) {
        x++;
      } else if(board[i][j]==O){
        o++;
      }
      else
        empty++;
    }
  }
  if ((x+o+empty)==D*D) {
    // cout<<endl<<"[X="<<x<<" O="<<o<<"]"<<endl;
    if (empty==0) {
      cout<<"Game ends"<<endl;
      return 1;
    }
  } else {
    cout<<"Something's wrong."<<endl;
  }
  return 0;
}

int isFilled(int row, int column){
  return (board[row][column]==X || board[row][column]==O);
}
