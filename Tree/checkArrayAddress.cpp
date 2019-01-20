#include <stdio.h>

int main(){
	int arr[] = {89,34, 54,68,98};
	printf("%u\n\n", &arr);
	printf("%u, %u\n", arr+1, &arr+1);
}