#include <climits>

int countBST(int n){
	int *catalan = new int[n+1];
	int mod = pow(10,9) + 7;
	catalan[0] = catalan[1] = 1;
	for(int i = 2; i <= n; i++){
		catalan[i] = 0;
		for(int j = 0; j < i; j++){
			int temp = (int)(catalan[j] * 1l * catalan[i-j-1]) % mod;
			catalan[i] = (catalan[i]+temp)% mod;
		}
	}
	return catalan[n] % mod;
}