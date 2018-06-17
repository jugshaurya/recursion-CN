#include <iostream>
#include <string> 
using namespace std; 

void printPermutationsHelper(string input, string output){
    if(input.length() == 0){
        cout << output << endl;
        return;
    }
    
    for(int i = 0; i< input.length(); i++){ 
        printPermutationsHelper(input.substr(0,i) + input.substr(i+1), output + input[i]);
    }
}

void printPermutations(string input){ 
    printPermutationsHelper(input, "");
    return;
}

int main(){
    string str;
    cin>>str;
    printPermutations(str);
}
