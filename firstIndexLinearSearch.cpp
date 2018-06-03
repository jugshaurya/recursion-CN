int firstIndex(int input[], int size, int x, int i) {

  if(i==size){
    return -1;
  }
  
  if(input[i]==x){
    return i;
  }
  
  return firstIndex(input,size,x,i+1);
  
}
int firstIndex(int input[], int size, int x) {
  	return firstIndex(input,size,x,0);
}
