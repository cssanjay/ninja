#include <iostream>
using namespace std;

void findElement(int input[][100], int m, int n, int x){
	int i =0, j=n-1;
	while(i<m && j>=0){
		if(input[i][j] == x){
			cout << i << " " << j;
		}
		else if(x > input[i][j])
				i++;
		else j--;
	}
	cout << "-1" << endl;
}