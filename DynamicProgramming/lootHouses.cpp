/*
* A thief wants to loot houses. He knows the 
* amount of money in each house. He cannot loot two 
* consecutive houses. Find the maximum amount of
* money he can loot. 

* Input: 6
	5 5 10 100 10 5
*
* Output:
*  110
*/
int getMaxMoney(int arr[], int n){
	int* dp = new int[n];
	dp[0] = arr[0];
	if(n>1){
		dp[1] = max(dp[0], arr[1]);
	}

	for(int i = 2; i < n; i++){
		dp[i] = max(arr[i]+dp[i-2], dp[i-1]);
	}
	return dp[n-1];
}