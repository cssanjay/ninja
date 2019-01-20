#include <iostream>
using namespace std;

/*
giving wrong answer
int lis(int* input, int n){
	int* output = new int[n];
	output[0] = 1;
	for(int i = 1; i < n; i++){
		output[i] = 1;
		for(int j = i-1; j >= 0; j--){
			if(input[j] > input[i]){
				continue;
			}
			int possibleAns = output[j] + 1;
			if(possibleAns > output[i]){
				output[i] = possibleAns;
			}
		}
	}
	int best = 0;
	for(int i = 0; i < n; i++){
		if(best < output[i]){
			best = output[i];
		}
	}
	delete [] output;
	return best;
}
*/

int lis(int* input, int n){
	int* storage = new int[n];
	storage[0] = 1;
	int ans = 1;

	for(int i = 1; i < n; i++){
		int max = 1;
		for(int j = i-1; j >= 0; j--){
			if(input[j] < input[i]){
				int op = storage[j] + 1;
				if(op > max)
					max = op;
			}
		}
		storage[i] = max;
		if(max > ans)
			ans = max;
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	int* input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int ans = lis(input, n);
	cout << ans;
	delete [] input;
}