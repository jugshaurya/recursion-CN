int sum(int input[], int n, int i){ // i is the index of array
  
  if(i==n){
    return 0;
  }
  
  int smallsum  = sum(input, n,i+1);
  return input[i]+smallsum;
}

int sum(int input[], int n) {
	return sum(input,n,0);
}
