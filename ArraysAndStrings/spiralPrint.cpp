void spiralPrint(int matrix[][1000], int row, int col){
	int i, rowStart = 0, colStart = 0;
	
	while(rowStart < row, colStart < col){
		// first row
		for(i = colStart ; i < col; i++)
			cout << matrix[rowStart][i];
		rowStart++;

		// last column
		for(i = rowStart; i < row; i++)
			cout << matrix[i][col-1];
		col--;

		//print last row
		if(rowStart < row){
			for(i = col-1; i >= colStart; i--)
				cout << matrix[row-1][i];
			row--;
		}
	
		// print first col
		if(colStart < col){
			for(i = row-1; i >= rowStart; i--)
				cout << matrix[][colStart];
			colStart++;
		}
	}
}