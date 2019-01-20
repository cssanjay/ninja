#include <queue.h>
#include <vector.h>

vector<int> kSmallest(int * input, int n, int k){
	priority_queue<int>pq;
	vector <int> output;
	int i;

	for(i = 0; i < k; i++){
		pq.push(input[i]);
	}
	for(; i < n; i++){
		if(input[i] < pq.top()){
			pq.pop();
			pq.push(input[i]);
		}
	}
	while(!pq.empty()){
		output.push_back(pq.top());
		pq.pop();
	}
	return output;
}