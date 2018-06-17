/*
Q-->  Return Permutations - String
    Given a string S, find and return all the possible permutations of the input string.
    Note 1 : The order of permutations is not important.
    Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
    Input Format :
    String S
    Output Format :
    All permutations (in different lines)
    Sample Input :
    abc
    Sample Output :
    abc
    acb
    bac
    bca
    cab
    cba

*/
#include <string>
using namespace std; 
int returnPermutations(string input, string output[]){
    if(input.length() == 0){
        output[0] = ""; 
        return 1;
        }
    
    string smallOutput[10000];
    int smallSize = returnPermutations(input.substr(1), smallOutput); 
    int k = 0;
    for(int i = 0; i < smallSize; i++){
        for(int j = 0; j <=smallOutput[i].length(); j++){ 
            output[k++] = smallOutput[i].substr(0,j) + input[0] + smallOutput[i].substr(j); 
            
        }
    }
    
    return k;
}
