/*
  Q-->Let A[0 ... n-1] be an array of n distinct positive integers. If i < j and A[i] > A[j]
  then the pair (i, j) is called an inversion of A (where i and j are indexes of A).
  Given an integer array A, your task is to find the number of inversions in A.
  //constraints
  1 <= n <= 10^5
  1 <= A[i] <= 10^9
*/

#include <iostream>
using namespace std;

long long countDuringMerging(int* arr, int start, int end){
    int newarray[1000000];
    int mid = (start+end)/2;
    int i=start;
    int j=mid+1;
    int k=start;
    
    long long inversionCount = 0 ;
    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            newarray[k++] = arr[i++];
        }else{
            inversionCount += (mid+1) - i; // (total length) - i
            newarray[k++] = arr[j++];
        }    
    }
    
    while(i<=mid){
        newarray[k++] =arr[i++];
    }
    
    while(j<=end){
        newarray[k++] = arr[j++];
    }
    
    
    for(int m = start; m<k; m++){
        arr[m] = newarray[m];
    }
    
    return inversionCount;
}

long long inversionCount(int* arr, int s, int e){
    if(s>=e){
        return 0;
    }
    
    int mid = (s+e)/2;
    long long leftInversionCount = inversionCount(arr,s,mid);
    long long rightInversionCount = inversionCount(arr,mid+1,e);
    
    return leftInversionCount + rightInversionCount + countDuringMerging(arr,s,e);
}


long long solve(int A[], int n)
{
	return inversionCount(A,0,n-1);
}

int main(){
  int a[] = {3,2,1};
  cout<<solve(a,5);//ans-->3
}

