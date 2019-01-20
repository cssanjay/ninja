#include <iostream>
using namespace std;

bool isPalindrome(int n){
	int divisor = 1;
	while(n/divisor >= 10)
		divisor *= 10;

	while(n!=0){
		int leading = n/divisor;
		int trailing= n%10;

		if(leading != trailing)
			return false;

		n = (n%divisor)/10;

		divisor = divisor/100;
	}
	return true;
}

int main(){
	isPalindrome(1001)? cout << "Yes, it is Palindrome" :
	cout << "No, not a plaindrome" ;
	return 0;
}