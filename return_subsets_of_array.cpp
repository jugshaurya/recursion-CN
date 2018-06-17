/*
q-->Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Input format :
Line 1 : Size of array
Line 2 : Array elements (separated by space)

Sample Input:
3
15 20 12
Sample Output:
""
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 
*/

int subset(int input[], int n, int output[][20]) {
  	if(n==1){
      output[0][0] = 0;//length of subset
      output[1][0] = 1;
      output[1][1] = input[0];
      return 2;
    }
  
  	int smallSize = subset(input+1,n-1,output);
  	for(int i=0;i<smallSize;i++){
      output[i+smallSize][0] = output[i][0]+1;
      output[i+smallSize][1] = input[0];
      
      int j=1;
      while(output[i][j]!=0){
        output[i+smallSize][j+1] = output[i][j];
        j++;
      }
    }
    
	return 2*smallSize;
}
//
//write main yourself
