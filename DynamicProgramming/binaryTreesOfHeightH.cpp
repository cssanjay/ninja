int binaryTreesOfHeightH(int h){
	int* a = new int[h+1];
	if(h == 0)
		return 1;
	if(h == 1)
		return 1;
	a[0] = 1;
	a[1] = 1;

	int mod = (int)(pow(10, 9)) + 7;
	for(int i = 2; i <= h; i++){
		long temp1 = (long) (a[i-1]) * a[i-1];
		temp1 = temp1 % mod;

		long temp2 = 2* (long)(a[i-1]) * a[i-2];
		temp2 = temp2 % mod;

		a[i] = (temp1 + temp2)% mod;
	}
	int ans = a[h];

	delete [] a;
	return ans;
} 