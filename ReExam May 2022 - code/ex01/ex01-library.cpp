#include <iostream>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Square **createChessboard(unsigned int m, unsigned int n) {
    Square ** chessBoard = new Square*[m];
    for (int i = 0; i < m; i++)
    {
        chessBoard[i] = new Square[n];
        for (int j = 0; j < n; j++)
        {
            chessBoard[i][j].piece = none;
            chessBoard[i][j].team = nobody;
        }
    }
    return chessBoard;
}

// Task 1(b).  Implement this function
void displayChessboard(Square **c,
                       unsigned int m, unsigned int n) {
    for (int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++){
            switch (c[i][j].piece)
            {
            case king:
                if(c[i][j].team == black) cout << "K ";
                else cout << "k ";
                break;
            case queen:
                if(c[i][j].team == black) cout << "Q ";
                else cout << "q ";
                break;
            default:
                cout << "_ ";
                break;
            }
        }
        cout << endl;
    }
    
}

// Task 1(c).  Implement this function
bool move(Square **c, unsigned int m, unsigned int n,
          int r1, int c1, int r2, int c2) {
    if(r1 == r2 && c1 == c2){
        return false; //same position....
    }
    if(c[r1][c1].piece == none){
        return false; //no piece
    }
    if(c[r1][c1].team == c[r2][c2].team){
        return false; // same team pieces...
    }

    //there is a piece to move to a legal square... check if piece can move like dat
    int rowDiff = abs(r2-r1);
    int colDiff = abs(c2-c1);
    if(c[r1][c1].piece == king){
        if(rowDiff > 1 || colDiff > 1){
            return false; //king can only move one
        }
    }
    else{
        //queen
        if(rowDiff != colDiff && !(rowDiff == 0 || colDiff == 0)){
            return false;
        }
    }

    c[r2][c2].piece = c[r1][c1].piece;
    c[r2][c2].team = c[r1][c1].team;

    c[r1][c1].piece = none;
    c[r1][c1].team = nobody;

    return true;
}
bool CheckIfMoveLegal(Square **c, unsigned int m, unsigned int n,
          int r1, int c1, int r2, int c2) {
    if(r1 == r2 && c1 == c2){
        return false; //same position....
    }
    if(c[r1][c1].piece == none){
        return false; //no piece
    }
    if(c[r1][c1].team == c[r2][c2].team){
        return false; // same team pieces...
    }

    //there is a piece to move to a legal square... check if piece can move like dat
    int rowDiff = abs(r2-r1);
    int colDiff = abs(c2-c1);
    if(c[r1][c1].piece == king){
        if(rowDiff > 1 || colDiff > 1){
            return false; //king can only move one
        }
    }
    else{
        //queen
        if(rowDiff != colDiff && !(rowDiff == 0 || colDiff == 0)){
            return false;
        }
    }

    return true;
}

// Task 1(d).  Implement this function
bool threatened(Square **c, unsigned int m, unsigned int n,
                int row, int col) {
    if(c[row][col].piece == nobody){
        return false; // no piece to cap
    }
    //get enemy team
    Team enemyTeam;
    if(c[row][col].team == black){
        enemyTeam = white;
    }
    else{
        enemyTeam = black;
    }
    //check kings:
    /*
    bool kingAttacker= (isEnemy(c, m, n, row-1, col, enemyTeam)
    || isEnemy(c, m, n, row-1, col-1, enemyTeam)
    || isEnemy(c, m, n, row-1, col+1, enemyTeam)
    || isEnemy(c, m, n, row, col-1, enemyTeam)
    || isEnemy(c, m, n, row, col+1, enemyTeam)
    || isEnemy(c, m, n, row+1, col, enemyTeam)
    || isEnemy(c, m, n, row+1, col-1, enemyTeam)
    || isEnemy(c, m, n, row+1, col+1, enemyTeam));
    
    if(kingAttacker){
        return true;
    }
*/
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(c[i][j].piece != nobody && c[i][j].team == enemyTeam){
                if(CheckIfMoveLegal(c, m, n, i, j, row, col)){
                    return true;
                }
            }
        }
        
    }
    
    return false;


    
}



bool isEnemy(Square **c, unsigned int m, unsigned int n,
                int row, int col, Team enemyTeam){
    if(row < 0 || row > m || col < 0 || col > n){
        return false;
    }
   
    return ((c[row][col].piece == king || c[row][col].piece == queen) && c[row][col].team == enemyTeam );
}
bool checkForQueen(Square **c, unsigned int m, unsigned int n,
                int row, int col, Team enemyTeam){
    if(row < 0 || row > m || col < 0 || col > n){
        return false;
    }
    if(c[row][col].piece == queen && c[row][col].team == enemyTeam){
        return true;
    }
}


// Do not modify
void deleteChessboard(Square **c, unsigned int m) {
    for (unsigned int i = 0; i < m; i++) {
        delete[] c[i];
    }
    delete[] c;
}


