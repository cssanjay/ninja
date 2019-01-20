#include <iostream>

using namespace std;

int editDistance(string s1, string s2){
	if(s1.length() == 0)
		return s2.length();
	if(s2.length() == 0)
		return s1.length();
	int m1 = s1.length();
	int m2 = s2.length();
	int storage[m+1][n+1];

	for(int i = 0; i <= m; i++)
		storage[i][0] = i;
	for(int j = 0; j <= n; j++)
		storage[0][j] = j;

	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(s1[i-1] == s2[j-1])
				storage[i][j] = storage[i-1][j-1];
			else storage[i][j] = 1 + min(storage[i][j-1],//insert
				min(storage[i-1][j], //remove
					storage[i-1][j-1])); //replace
		}
	}
	return storage[m][n];
}