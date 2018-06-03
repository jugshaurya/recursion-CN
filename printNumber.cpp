void print(int n){
    if(n == 1){
        cout << n << " ";
      	return;
    }
  	print(n - 1);
    cout << n << " ";
    
}
