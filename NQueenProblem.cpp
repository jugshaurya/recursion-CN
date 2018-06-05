#include <iostream>
using namespace std;

bool isSafe(int r, int c, int board[][10],int n){  
    //vertical check
    for(int i=0;i<r;i++){
        if(board[i][c]==1){
            return false;
        }
    }
    
    // upper left-diagonal
    int i = r;
    int j = c;
    while(i>=0 && j>=0){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j--;
    }
    
    //upper right-diagonal
    i = r;
    j = c;
    while(i>=0 && j<n){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j++;
    }
    
    return true;
}

void placeNQueens(int n, int i, int board[][10]){
  
    if( i == n){
        //print board
        for(int k = 0; k < n; k++){
            for(int l = 0; l < n; l++){
                cout << board[k][l] <<" ";
            }
        // cout<<endl;
        }
        cout<<endl;
        return;
    }
  
    for(int j = 0; j < n ; j++) {
        if(isSafe(i,j,board,n)){
            board[i][j] = 1;  
            placeNQueens(n,i+1,board); 
            board[i][j]=0;
        }
    }
}

void placeNQueens(int n){
    int board[10][10] = {};
	placeNQueens(n,0,board);
}

int main() {
   placeNQueens(4);
}
