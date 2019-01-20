/*
Given 2 sorted arrays (in increasing order), 
find a path through the intersections that produces
 maximum sum and return the maximum sum.
*/

#include <math.h>

long maxPathSum(int arr1[], int arr2[], int m, int n){
	int i = 0, j =0;
	long result = 0, sum1 = 0, sum2 = 0;

	while(i < m && j < n){
		if(arr1[i] < arr2[j])
			sum1 += arr1[i++];
		else if(arr1[i] > arr2[j])
			sum2 += arr2[j++];
		else{
			result = result + arr1[i++];
			j++;
		}
	}
	while(i < m)
		sum1 += arr1[i++];
	while(j < n)
		sum2 += arr2[j++];

	result += max(sum1, sum2);

	return result;
}