#include <iostream>
#include <algorithm>

int platformNeeded(int* arrival, int* departure, int n){
	sort(arrival, arrival+n);
	sort(departure, departure+n);

	int platforms = 1, result = 1;
	int i = 1, j = 0; // i started as 1 because arrival first, departure next
	while(i<n && j<n){
		if(arrival[i] < departure[j]){
			platforms++;
			i++;
			if(platforms > result){
				result = platforms;
			}
		}
		else{
				platforms--;
				j++;
		}
	}
	return result;
}