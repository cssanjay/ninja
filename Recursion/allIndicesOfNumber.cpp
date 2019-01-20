void findIndices(int input[], int currIndex, int size, int x, int output[], int &k){
	if(currIndex == size)
		return;
	if(input[currIndex] == x){
		output[k] = currIndex;
		k++;
	}
	findIndices(input, currIndex+1, size, x, output, k);
}

int allIndices(int input[], int size, int x, int output[]){
	int k = 0;
	findIndices(input, 0, size, x, output, k);
	return k;
}