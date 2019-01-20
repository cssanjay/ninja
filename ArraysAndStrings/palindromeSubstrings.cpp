int countPalindromeSubstrings(char s[]){
	int count = 0;
	int length = length(s);
	for(int i = 0; i < len; i++){
		int left = i-1;
		int right = i+1;
		count++;
		while(left >= 0 && right < len){
			if(s[left] == s[right]){
				count++;
				left--;
				right++;
			}
			else{
				break;
			}
		}
		if(i < len-1 && s[i] == s[i+1]){
			left = i-1;
			right = i+2;
			count++;
			while(left >= 0 && right<len){
				if(s[left] == s[right]){
					count++;
					left--;
					right++;
				}
				else{
					break;
				}
			}
		}
	}
	return count;
}