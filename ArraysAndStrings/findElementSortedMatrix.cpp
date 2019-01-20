void findElement(int input[][], int m , int n, int x){
	int i = 0; j = n-1;
	while(i < m; j < = 0){
		if(input[i][j] == x){
			cout << i << " " << j << endl;
			return;
		}
		else if(input[i][j] < x)
			i++;
		else
			j--;
	}
	cout << "-1" << endl;
	return;
}