int findMaxSquareWithAllZeroes(int input[][], int x, int y){
	int max = 0;
	int array[x][y];

	for(int i = 0; i < x; i++){
		if(input[i][0] == 0){
			array[i][0] = 1;
			max = 1;
		}
		else
			array[i][0] = 0;
	}

	for(int j = 0; j < n; j++){
		if(input[0][j] == 0){
			array[0][j] = 1;
			max  = 1;
		}
		else
			array[0][j] = 0;
	}

	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			if(input[i][j] == 1)
				array[i][j] = 0;
			else{
				array[i][j] = min(array[i-1][j-1], min(array[i-1][j],array[i][j-1]));
				if(array[i][j] > max){
					max = array[i][j];
				}
			}
		}
	}
	return max;
}