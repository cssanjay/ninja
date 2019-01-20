#include <iostream>
#include <cstring>

using namespace std;

int lcs(char* s1, char* s2){
	// cout << "lcs";
	if(s1[0] == '\0' || s2[0] == '\0')
		return 0;
	if(s1[0] == s2[0])
		return 1 + lcs(s1+1, s2+1);
	else
		return max(lcs(s1, s2+1), lcs(s1+1, s2));
}

int lcs2Helper(char* s1, char* s2, int m, int n, int** dp){
	if(m==0 || n==0)
		return 0;
	if(dp[m][n] > -1)
		return dp[m][n];
	int ans;
	if(s1[0] == s2[0])
		ans = 1 + lcs2Helper(s1+1, s2+1, m-1, n-1, dp);
	else
		ans = max(lcs2Helper(s1, s2+1,m,n-1,dp), lcs2Helper(s1+1, s2,m-1,n,dp));
	dp[m][n] = ans;
	return ans;
}

int lcs2(char* s1, char* s2){
	int m = strlen(s1);
	int n = strlen(s2);
	int** dp = new int* [m+1];
	for(int i = 0; i <= m; i++){
		dp[i] = new int[n+1];
		for(int j = 0; j <= n; j++){
			dp[i][j] = -1;
		}
	}
	int ans = lcs2Helper(s1, s2, m, n, dp);
	for(int i = 0; i <= m; i++){
		delete [] dp[i];
	}
	delete [] dp;
	return ans;
}

int lcsI(char* s1, char*s2){
	int m = strlen(s1);
	int n = strlen(s2);
	int** dp = new int*[m+1];
	for(int i = 0; i <= m; i++)
		dp[i] = new int[n+1];

	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	int ans = dp[m][n];
	cout << ans;
	// delete 2d array
	for(int i = 0; i <= m; i++)
		delete [] dp[i];
	delete [] dp;
	return ans;
}

int main(){
	char a[100];
	char b[100];
	cin >> a;
	cin >> b;
	cout <<lcs(a,b) << endl;
	cout << lcs2(a,b) << endl;
	cout << lcsI(a,b) << endl;
}