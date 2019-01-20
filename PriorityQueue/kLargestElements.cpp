#include <vector>
#include <queue>

using namespace std;

vector<int> kLargest(int input[], int n, int k){
	priority_queue<int, vector<int>, greater<int> > pq;

	for(int i = 0; i < k; i++){
		pq.push(input[i]);
	}
	for(int i = k; i <n; i++){
		if(input[i] > pq.top()){
			pq.pop();
			pq.push(input[i]);
		}
	}

	vector<int> output;
	while(!pq.empty()){
		output.push_back(pq.top());
		pq.pop();
	}
	return output;
}