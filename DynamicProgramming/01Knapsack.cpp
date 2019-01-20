//Recursive
// capacity W
int knapsack(int W, int wt[], int val[], int n){
	// Base case
	if(n==0 || W==0)
		return 0;

	if(wt[n-1] > W)
		return knapsack(W, wt, val, n-1);
	else
		return max(val[n-1]+knapsack(W, wt, val, n-1),
			knapsack(W, wt, val, n-1)
		);
}

// DP
int knapsack(int W, int wt[], int val[], int n){
	int i, w;
	int K[n+1][W+1];
	for(i=0; i<=n; i++){
		for(w=0; w<=W; w++){
			if(i==0 || w==0)
				K[i][w] = 0;
			else if(wt[i-1] <= w)
				K[i][w] = max(val[i-1]+K[i-1][w-wt[i-1]], K[i-1][w]);
			else
				K[i][w] = K[i-1][w];
		}
	}
	return K[n][W];
}