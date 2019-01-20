#include <iostream>
#include <climits>

int findSum(int arr[], int n){
	int *tempArr = new int[n];
	tempArr[0] = arr[0];
	int result = tempArr[0];
	for(int i = 1; i < n; i++){
		if((arr[i]+tempArr[i-1]) > arr[i])
			tempArr[i] = arr[i]+tempArr[i-1];
		else
			tempArr[i] = arr[i];
		if(tempArr[i]>result)
			result = tempArr[i];
	}
	return result;
}