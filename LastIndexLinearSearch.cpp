int lastIndex(int input[], int size, int x) {
  if(size == 0) {
    return -1;
  }
 
 int smallAns = lastIndex(input + 1, size - 1, x); 
  if(smallAns != -1) {
    return smallAns + 1;
  }
  if(input[0] == x) { 
      return 0; 
    } else {
    return -1; 
    }
}
