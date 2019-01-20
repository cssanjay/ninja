/*
* Given an N*N integer square matrix, rotate it 
* by 90 degrees in anti-clockwise direction.
*/
#define N 4
void rotateMatrix(int mat[][N]){
	for(int x = 0; x < N/2; x++){
		for(int y = x; y < N-x-1; y++){
			int temp = mat[x][y]; // current in temp
			mat[x][y]= mat[y][N-1-x]; // right 2 top
			mat[y][N-1-x] = mat[N-1-x][N-1-y]; // bottom to right
			mat[N-1-y][x] = temp; // temp to left
		}
	}
}

void transpose(int** input, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int temp = input[j][i];
			input[j][i] = input[i][j];
			input[j][i] = temp;
		}
	}
}

void rotate(int** input, int n){
	transpose(input, n);
	// reversing the columns
	for(int j = 0; j < n; j++){
		for(int i = 0, k = n-1; i < k; i++; k--){
			int temp = input[i][j];
			input[i][j] = input[k][j];
			input[k][j] = temp;
		}
	}
}

/*
* The above steps/program do left (or anticlockwise) rotation, how to right (or clockwise) rotate?
* To right rotate, we do following steps.
* 
* 
* -- Find transpose of matrix.
* -- Reverse rows of the transpose.
*/

/*       
*	Let the given matrix be
*	1  2  3  4
*	5  6  7  8
*	9  10 11 12
*	13 14 15 16
*
*	First we find transpose.
*	1 5 9 13
*	2 6 10 14
*	3 7 11 15
*	4 8 12 16
*
void rotateMatrix(int mat[][N]){
	for(int x = 0; x < N/2; x++){
		for(int y = x; y < N-x-1; y++){//x0 y3
			int temp = mat[x][y]; // current in temp  0,3
			mat[x][y]= mat[y][N-1-x]; // right 2 top  ---0,3 3,3
			mat[y][N-1-x] = mat[N-1-x][N-1-y]; // bottom to right---3,3 3,0
			mat[N-1-y][x] = temp; // temp to left
		}
	}
}
*	Then we reverse elements of every column.
*	4 8 12 16
*	3 7 11 15
*	2 6 10 14
*	1 5  9 13
*/