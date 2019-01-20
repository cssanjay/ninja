#include <iostream>
// #include <array>
// #include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

void printPairs(int arr[], int arr_size, int sum){
	unordered_set<int> s;
	for(int i = 0; i < arr_size; i++){
		int temp = sum - arr[i];
		if(temp >= 0 && s.find(temp)!=s.end())
			cout << "Pair of " << sum << "::"<< arr[i] <<"," << temp << endl;
		s.insert(arr[i]);
	}
}


int main(){
	int A[] = {1, 213,43,21,453,64, 8};
	// array<int,5> myarray{ 1, 2, 3, 4, 5 };
	int n = 22;
	int arr_size = sizeof(A)/sizeof(A[0]);

	printPairs(A, arr_size, n);
	return 0;
}