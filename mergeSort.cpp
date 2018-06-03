
#include<iostream>
using namespace std;

void merge(int *a, int start, int end){

	int mid = (start + end) / 2;
	int i=start; //work as an index for first sorted array from start to mid
	int j=mid+1; //work as an index for second sorted array from  mid+1 to end
	int temp[1001];//will store our data temporarily
	int k=start; //work as an index for temporary array

	while(i<=mid &&j<=end){
		if(a[i]<a[j]){
			temp[k++]=a[i++];
		}else{
			temp[k++]=a[j++];
		}
	}
	//one of the two arrays will be exausted hence we put rest elements of other array into temp array
	while(i<=mid){
		temp[k++]=a[i++];
	}
	while(j<=end){
		temp[k++]=a[j++];
	}

	//copy all the elements from temp back to array a[]
	for (int x = start; x <k ; ++x)
	{
		a[x]=temp[x];
	}
}

void mergeSort(int *a, int start,int end){
	if(start>=end){
		return;
	}
	//Inductive Step
	//need to follow 3 steps
	//1. Divide
	int mid = (start + end) / 2;

	//2.sort the individual Parts --0 to mid and mid+1 to end
	mergeSort(a, start, mid);
	mergeSort(a, mid+1, end);
	
	//3.merge the sorted parts into the same original array i.e a[]
	merge(a, start, end);
	
}

void mergeSort(int input[], int size){
	mergeSort(input,0,size-1);        
}
