#include <iostream>
using namespace std;

// output: 2 4 1 3 28 0 0
// input: 2 0 4 1 3 0 28

void PushZeroesEnd(int arr[], int n){
	int start = 0, i =0;

	while(start < n){
		while(arr[start]==0 && start!=n)
			start++;
		arr[i] = arr[start];
		i++;
		start++;
	}

	while(i < n){
		arr[i] = 0;
		i++;
	}
}

int main(){
	int arr[]= {0,3,0,2,0};
	// int arr[] = {2,0,4,1,3,0,28};
	PushZeroesEnd(arr, 5);
	for(int i = 0; i<5; i++)
		cout <<endl<<endl<<arr[i];
	return 0;
}
