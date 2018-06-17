/* Q-->
Return all codes - String
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw

*/
#include <string>
using namespace std;
int getCodes(string input, string output[]) { 
    if(input[0] == '\0'){ 
        output[0] = ""; 
        return 1; 
        
    }
    
    int first = input[0] - 48; 
    char firstChar = first + 'a' - 1;
    char secondChar = '\0';
    string smallOutput1[500];
    string smallOutput2[500]; 
    int size1 = getCodes(input.substr(1), smallOutput1); 
    int size2 = 0;
    if(input[1] != '\0'){ 
        int second = first * 10 + input[1] - 48;
        if(second >= 10 && second <= 26){ 
            secondChar = second + 'a' - 1; 
            size2 = getCodes(input.substr(2), smallOutput2); 
            
        }
    }
    
    int k = 0;
    for(int i = 0; i < size1; i++){
        output[k] = firstChar + smallOutput1[i];
        k++; 
        
    } 
    
    for(int i = 0; i < size2; i++){ 
        output[k] = secondChar + smallOutput2[i]; 
        k++;
    }
    return k;
}
