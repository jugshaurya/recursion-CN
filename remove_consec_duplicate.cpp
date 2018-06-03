
/*Q-->Given a string S, remove consecutive duplicates from it recursively.*/

void removeConsecutiveDuplicates(char *input) {
if(input[0] == '\0'){
    	return ;
    }
  
 if(input[0] == input[1]){
      	int i = 1;
    	for(; input[i]!='\0'; i++){
          input[i-1] = input[i];
        }
      	input[i-1] = input[i];
      return removeConsecutiveDuplicates(input);
    }
  	removeConsecutiveDuplicates(input+1);
}
