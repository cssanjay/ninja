#include <iostream>
#include <stack>

using namespace std;

int length(char input[]){
	int len = 0;
	for(int i = 0; input[i]!='\0'; i++)
	len++;
	return len;
}

int countBracketReversal(char input[]){
	int len = length(input);
	if(len == 0)
		return 0;
	if(len%2!=0)
		return -1;

	stack<char> stack;
	for(int i = 0; i < len; i++){
		char currentChar = input[i];
		if(currentChar == '{'){
			stack.push(currentChar);
		}
		else{
			// pop if balanced pair
			if(!stack.empty() && stack.pop() == '{'){
				stack.pop();
			}
			else{
				stack.push(currentChar);
			}
		}
	}

	int count = 0;
	while(!stack.empty()){
		char ch1 = stack.top();
		stack.pop();
		char ch2 = stack.top();
		stack.pop();
		if(char1 != char2){
			count += 2;
		}
		else{
			count += 1;
		}
	}
	return count;
}