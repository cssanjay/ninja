void findLargestUniqueSubstring(char input[], char output[]){
	if(input[0] == '\0'){
		output[0] = '\0';
	}

	int lastIndex[256];

	for(int i = 0; i < 256; i++){
		lastIndex[i] = -1;
	}

	int 
}

int longestUniqueSubstring(char* input){
	if(input[0] = '\0')
		return 0;
	int start = 0, next = 0;
	int lastIndex[256];
	for(int i = 0; i < 256; i++)
		lastIndex[i] = -1;


	int longestSoFar = 0;
	while(input[i]!='\0'){
		char nextChar = input[next];
		if(lastIndex[nextChar] < start){
			next++;
		}
		else{
			if(next-start > longestSoFar)
				longestSoFar = next-start;
			start = lastIndex[nextChar] + 1;
			next++;
		}
		lastIndex[nextChar] = next-1;
	}
	if(next-start > longestSoFar)
		longestSoFar = next-start;
	return longestSoFar;
}