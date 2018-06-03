bool checkNumber(int input[], int size, int x) {
	if(size==0){
      return false;
    }

  bool smallans = checkNumber(input,size-1,x);
  if(smallans){
  	return true;
  }else{
    if(input[size]==x){
 		  return true;
    }else{
      return false;
    }
  }
}
