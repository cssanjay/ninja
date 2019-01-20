/*
Given an array of n positive integers. The task is to count the number of Arithmetic Progression subsequences in the array. As the answer could be very large, output it modulo 100001.
Note: Empty sequence or single element sequence is Arithmetic Progression.
*/

int numOfAP(int* arr, int n){
	int ans = n+1;
	unordered_map<int, int>* map = new unordered_map<int, int>[n];
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j <n; j++){
			int diff = arr[j]-arr[i];
			map[i][diff] +=1;
			ans = (ans+1)%10001;
		}
	}

	for(int i = n-3; i>=0; i--){
		for(int j = i+1; j < n; j++){
			int diff = arr[j]-arr[i];
			map[i][diff] = (map[i][diff] + map[j][diff])%10001;
			ans = (ans + map[j][diff])%10001;
		}
	}

	delete [] map;
	return ans;
}

int main(){
	int n;
	cin>>n;
	int* arr = new int[n];
	for(int i = 0; i <n; i++){
		cin >> arr[i];
	}
	cout << numOfAP(arr, n);
	delete[] arr;
	return 0;
}