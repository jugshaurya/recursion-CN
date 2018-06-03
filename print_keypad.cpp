#include <iostream>
#include <string>
using namespace std;

string mapping[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void printKeypad(int num, string output){

  if( num == 0){
    	cout<< output <<endl;
	}  

  int digit  = num%10;
  for(int i=0;i<mapping[digit].size();i++){
    printKeypad(num/10, mapping[digit][i]+output);
  }
  
}


void printKeypad(int num){
  
	string output = "";
  	printKeypad(num,output);
}
