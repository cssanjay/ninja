#include <iostream>
#include <map>
using namespace std;

int highestFrequency(int *input, int n){
	map<int, int> counterMap;
	int max = 0, number;
	for(int i =0; i< n; i++){
		counterMap[input[i]]++;
		if(max < counterMap[input[i]]){
			max = counterMap[input[i]];
			number = input[i];
		}
	}

	return number;
}
int main(){
	int arr[] = {2, 12, 2, 11, 12, 2, 1, 2, 2, 11, 12, 2, 6 };
	int size = 13;
	cout <<highestFrequency(arr, size);
	return 0;
}