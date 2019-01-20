/*
* Given a string S, reverse each word of a string 
* individually. For eg. if a string is "abc def", 
* reversed string should be "cba fed".
*/

void reverse(char input[], int start, int end){
	int i = start, j = end;
	while(i < j){
		char temp = input[i];
		input[i] = input[j];
		input[j] = temp;
		i++;
		j--;
	}
}

void reverseEachWord(char input[]){
	int start = 0, end = 0, i;
	for(i = 0; input[i] != '\0'; i++){
		if(input[i] == ' '){
			end = i-1;
			reverse(input, start, end);
			start = i+1;
		}
	}
	end = i-1;
	reverse(input, start, end);
}