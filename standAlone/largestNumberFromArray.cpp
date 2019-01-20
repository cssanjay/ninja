#include <iostream>

using namespace std;


int compareFunction(string a, string b){
	string ab = a.append(b);
	string ba = b.append(a);

	return ab.compare(ba)>0 ? 1:0;
}
void printLargest(vector<string> arr){
	sort(arr.begin(), arr.end(), compareFunction);
	for(int i = 0; i < arr.size(); i++)
		cout << arr[i];
}