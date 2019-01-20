#include <stack>
#include <iostream>

using namespace std;
int precedence(char c){
	if(c == '^')
		return 3;
	else if(c == '*' || c == '/')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else 
		return -1;
}

void infixToPostfix(string s){
	stack<char> st;
	int l = s.length();
	string ns;
	for(int i = 0; i < l; i++){
		// if operand, add to ns

		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			ns+=s[i];
		else if(s[i] == '(')
			st.push(s[i]);
		else if(s[i] == ')'){
			while(!st.empty() && st.top()!= '('){
				char c = st.top();
				st.pop();
				ns+=c;
			}
			if(st.top() == '('){
				char c = st.top();
				st.pop();
			}
		}
		//if got operator
		else{
			while(!st.empty() && precedence(s[i]) <= prec(st.top())){
				char c = st.top();
				st.pop();
				ns+=c;
			}
			st.push(s[i]);
		}
	}
	while(!st.empty()){
		char c = st.top();
		st.pop();
		ns+=c;
	}
	cout << ns << endl;
}

int main(){
	string expression = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(expression);
	return 0;
}