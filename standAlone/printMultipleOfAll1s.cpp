#include <iostream>
using namespace std;
void printMultipleOfAll1s(int n){
	int count = 1, res = 1;
	while(res){
		res = (res * 10 + 1) % n;
		count++;
	}
	while(count--)
		cout << "1";
	cout << endl;
}

int main(){
	printMultipleOfAll1s(3);
	printMultipleOfAll1s(13);
}