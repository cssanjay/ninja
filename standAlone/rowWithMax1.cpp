#include <iostream>
using namespace std;

int rowWithMax1(bool matrix[4][4], int m, int n){
	int max = 0;

	int j =n;

	for(int i = 0; i < m; i++){
		while(j >= 0 && matrix[i][j] == 1){
			j = j-1;
			max = i;
		}
	}
	return max;
}

int main(){
	bool m[4][4] = { {0, 0, 0, 1},
                       {0, 1, 1, 1},
                       {1, 1, 1, 1},
                       {0, 0, 0, 0}};
 
    cout << "Index of row with maximum 1s is "<< rowWithMax1(m, 4, 4);
 
    return 0;
}