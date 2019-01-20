#include <climits>
#include <stack>
#include <math.h>

using namespace std;

void sortstack(stack<int> &s){
	if(s.size() <= 1)
		return;
	stack<int> helper;
	int n = s.size();
	for(int i = 0; i < n; i++){
		// pop till all elements in stack are greater than top
		int max = INT_MIN;
		bool maxSkipped = false;
		for(int j = 0; j < n-i; j++){
			int element = s.top();
			s.pop();
			if(element > max){
				max = element;
			}
			helper.push(element);
		}
		while(!helper.empty()){
			int element = helper.top();
			helper.pop();
			if(element != max || maxSkipped){
				s.push(element);
			}
			else{
				maxSkipped = true;
			}
		}
	}
}