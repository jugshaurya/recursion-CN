#include <iostream>
#include<cmath>
using namespace std;

bool isValid(int num, int** mat, int n,int i,int j){
    //column check
    for(int k=0;k<n;k++){
        if(mat[k][j] == num){
            return false;
        }
    }
 
    //row check
    for(int k=0;k<n;k++){
        if(mat[i][k] == num){
            return false;
        }
    }
 
    //sqrt(n) grid check
    int starti,startj;
    int sqrtn = sqrt(n);
    starti = (i/sqrtn) * sqrtn;
    startj = (j/sqrtn) * sqrtn;
    
    for(int k=starti;k<starti+sqrtn;k++){
       for(int l=startj;l<startj+sqrtn;l++){
           if(mat[k][l] == num){
               return false;
           }
        }
    }    

    return true;

}


bool solveSudoku(int** mat, int n,int i,int j){
    
    if(i == n ){
     return true;   
    }
    
    if(j == n){
        return solveSudoku(mat,n,i+1,0);
    }
    
    if(mat[i][j] !=0){
        return  solveSudoku(mat,n,i,j+1);
    }
    
    //that means mat[i][j]==0
    for(int k=1;k<=n;k++){
        if(isValid(k,mat,n,i,j)){
            mat[i][j] = k;
            if(solveSudoku(mat,n,i,j+1)){
                return true;
            }
        }
    }

    //all values are tried nothing works therefore 
    mat[i][j] = 0;
    return false;    
}


int main(){
    int n;
    cin>>n;
    
    int** mat = new int*[n];
    for(int i=0;i<n;i++){
        mat[i] = new int[n];
    }
    
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    solveSudoku(mat,n,0,0);
    
    for(int i= 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
