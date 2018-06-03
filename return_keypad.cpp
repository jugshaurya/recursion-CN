#include <string>
using namespace std;

string mapping[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int keypad(int num, string output[]){
  	if(num == 0){
      output[0] = "";
      return 1;
    }
 	
  	int size = keypad(num/10, output);
  	int digit = num%10;
  	int possibilities = mapping[digit].size();
  	string temp[size] ;
  	for(int i= 0;i<size;i++){
  	    temp[i] = output[i] ;
  	}
      for(int i=0; i<possibilities;i++){
		for(int j=0; j<size; j++){
      		output[j + i*size] = temp[j] + mapping[digit][i] ;
      }
	}

  return size * possibilities; 
}

