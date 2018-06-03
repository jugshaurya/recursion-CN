#include<utility>
using namespace std;

int partition(int *a,int start, int end){
	//Choose a pivot element let say the end one
	int pivot = a[end];
	int i=start; //denotes the position of upcoming element lesser than pivot
	int j=i; //denotes the element tracking element over which comparision happen
	while(j<end){
		if(a[j]<=pivot){
			swap(a[i],a[j]);
			i++;
		}
		j++;
	}
	//at last put pivot at its correct position that is i now
	swap(a[i],a[j]);
	return i;
}

void quickSort(int *a,int start, int end){
	//Base Case
	if(start>=end){
		return;
	}

	//we have 3 step here
	
	//1.Choose pivot element ,arrange data accordingly and Get the correct position of pivot element 
	int pIndex = partition(a,start,end);
	//2. sort the left sub-array
	quickSort(a,start,pIndex-1);
	//3. sort the right sub-array
	quickSort(a,pIndex+1,end);
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */

  	quickSort(input,0,size-1);
}
