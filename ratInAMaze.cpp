#include <iostream>
using namespace std;
void ratInAMaze(int maze[][20], int n, int output[][20], int row, int col){
    if(row==n-1 && col == n-1){
        //print output
        output[row][col] = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<output[i][j] <<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        output[row][col]=0;
        return;
    }
    output[row][col] = 1;
    
    //UP -Direction
    if(row-1 >=0 && output[row-1][col]!=1 && maze[row-1][col]!=0){
        ratInAMaze(maze,n,output,row-1,col);
    }
    
    //down -Direction
    if(row+1<n && output[row+1][col]!=1 && maze[row+1][col]!=0){
        ratInAMaze(maze,n,output,row+1,col);
    }
    
    //right -Direction
    if(col+1 <n && output[row][col+1]!=1 && maze[row][col+1]!=0){
        ratInAMaze(maze,n,output,row,col+1);
    }
    
    //left -Direction
    if(col-1>=0 && output[row][col-1]!=1 && maze[row][col-1]!=0){
        ratInAMaze(maze,n,output,row,col-1);
    }
    
    output[row][col] = 0;
}

void ratInAMaze(int maze[][20], int n){
    int output[20][20] = {};
    output[0][0] = 1;
    ratInAMaze(maze, n, output,0,0);
}

int main() {
   int maze[20][20]=  {{1,0,1},{1,1,1},{1,1,1}};
    ratInAMaze(maze,3);
}
