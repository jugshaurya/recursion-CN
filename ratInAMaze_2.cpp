
#include<bits/stdc++.h>
using namespace std;


void printoutput(int** output,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << output[i][j] << " ";
		}
	}
	cout<<endl;
}
void mazeHelp(int maze[][20],int n,int** output,int x,int y){


	if(x == n-1 && y == n-1){
		output[x][y] =1;
		printoutput(output,n);
      	output[x][y] =0;
		return;
	}
  
	if(x>=n || x<0 || y>=n || y<0 || maze[x][y] ==0 || output[x][y] ==1){
		return;
	}
  
	output[x][y] = 1;
	mazeHelp(maze,n,output,x-1,y);
	mazeHelp(maze,n,output,x+1,y);
	mazeHelp(maze,n,output,x,y-1);
	mazeHelp(maze,n,output,x,y+1);
	output[x][y] = 0;
}
void ratInAMaze(int maze[][20], int n){

  int** output = new int*[n];
  for(int i=0;i<n;i++){
  	output[i] = new int[n];
  }
  mazeHelp(maze,n,output,0,0);
  for(int i=0;i<n;i++){
  	delete [] output[i] ;
  }
  delete [] output;


}
int main(){
	
}
