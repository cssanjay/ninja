#include <string>
#include <iostream>
using namespace std;


void getSpiralString(int arr[][5], int size){
    int i = 0, j = 0;
    int numRows = size, numCols = size;
    while(i<size && j <size){
        for(j = 0;j < numCols; j++){
            cout << arr[i][j];
        }
        i++; // i =1 j =4
        for(; i < numRows; i++){
            cout << arr[i][j];
        }
        j--; // j = 3 i=4
        --numCols;
        for(;j>=0;j--){
            cout << arr[i][j];
        }
        i--;numRows--;
        //j=0; j =i=4
        for(i = numRows; i>=0; i--){
            cout << arr[i][j];
        }
        cout << endl;
    }
    
}
int main() {
	int num, size, value;
	
	string result;
	cin >> num;										// Reading input from STDIN
// 	cout << "Input number is " << num << endl;		// Writing output to STDOUT
    int arr[5][5] = {{0,1,2,3,4},            
            {5,6,7,8,9},
            {10,11,12,13,14},
            {15,16,17,18,19},
            {20,21,22,23,24}};

        getSpiralString(arr, size);
        // cout << result;
    
}