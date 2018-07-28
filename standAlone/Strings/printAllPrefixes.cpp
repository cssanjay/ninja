#include <iostream>
using namespace std;

void printAllPrefixes(char input[]){
	int i, j;
	for(i = 0; input[i]!='/0', i++){
		for(j = 0; j <= i; j++){
			cout << input[j];
		}
		cout << endl;
	}
}