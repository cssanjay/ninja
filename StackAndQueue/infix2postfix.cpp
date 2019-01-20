#include <stack.h>

int length(char input[]){
	int i = 0;
	while(input[i])
		i++;
	return i;
}

// to return priority of operators
int priority(char c){
	if(c == '*' || c == '/')
		return 2;
	if(c == '+' || c == '-')
		return 1;
	else 
		return -1;
}

int evaluate(int op1, int op2, char operate){
	switch(operate){
		case '*': return op1*op2;
		case '/': return op1/op2;
		case '+': return op1+op2;
		case '-': return op1-op2;
		default: return 0;
	}
}

void infixTpPostfix(char * input){
	stack<char> s;
	int len = length(input), index = 0;
	char output[1000];

	for(int i = 0; i < len; i++){
		if(input[i] >= '0' && input[i] <= '9'){
			output[index++] = input[i];
		}
		else if(input[i] == '(')
			s.push('(');
		else if(input[i] == ')'){
			while(!s.empty() && s.top() != '('){
				char c = s.top();
				s.pop();
				output[index++] = c;
			}
			if(s.top() == '('){
				char c = s.top();
				s.pop();
			}
		}
		else{
			while(!s.empty() && priority(input[i]) <= priority(s.top())){
				char c = s.top();
				s.pop();
				output[ndex++] = c;
			}
			s.push(input[i]);
		}
	}
	while(!s.empty()){
		char c = s.top();
		s.pop();
		output[index++] = c;
	}
	output[index] = '\0';

	cout << output << "\n";

	// copying output to input
	int i = 0;
	while(i < length(output)){
		input[i] = output[i];
		i++;
	}
	input[i] = '\0';
}

void evalPostfix(char postfix[]){
	stack<int> s;
	int i = 0;
	char ch;
	int val;
	int len = length(postfix);

	while(i < len){
		ch = postfix[i];
		if(isDigit(ch)){
			s.push(ch-'0');
		}
		else{
			int op1 = s.top();
			s.pop();
			int op2 = s.top();
			s.pop();
			val = evaluate(op1, op2, ch);
			s.push(val);
		}
		i++;
	}
	cout << val;
}

void evaluatePostfix(char exp[]){
	infixTpPostfix(exp);
	evalPostfix(exp);
}