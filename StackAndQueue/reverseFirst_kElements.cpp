#include <iostream>
#include <cmath>

using namespace std;

queue<int> reverseKElements(queue<int> Queue, int k){
	if(Queue.empty() || k > Queue.size())
		return Queue;
	if(k<=0)
		return Queue;

	stack<int> Stack;

	for(int i = 0; i < k; i++){
		Stack.push(Queue.front());
		Queue.pop():
	}
	while(!Stack.empty()){
		Queue.push(Stack.top());
		Stack.pop();
	}
	for(int i = 0; i < Queue.size()-k; i++){
		Queue.push(Queue.front());
		Queue.pop();
	}
	return Queue;
}
