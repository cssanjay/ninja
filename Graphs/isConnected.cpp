#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void dfs(unordered_map<int, vector<int>* > adjacencyList, int v1, unordered_map<int, bool>& visited){
	vector<int>* adjacenctVertices = adjacencyList[v1];

	visited[v1] = true;

	// Recursive call
	for(int i = 0; i <adjacenctVertices->size(); i++){
		if(visited.count(adjacenctVertices->at(i))==0){
			dfs(adjacencyList, adjacenctVertices->at(i), visited);
		}
	}
}

bool isConnected(unordered_map<int, vector<int>*> &adjacencyList){
	unordered_map<int, bool> visited;
	int startVertex = adjacencyList.begin()->first;
	dfs(adjacencyList, startVertex, visited);
	return visited.size() == adjacencyList.size();
}

int main(){
	int v, e;
	cin >> v >> e;

	// taking input
	unordered_map<int, vector<int>*> adjacencyList;
	for(int i = 0; i < v; i++){
		vector<int>* v1 = new vector<int>;
		adjacencyList[i] = v1;
	} 

	int count = 1;
	while(count <= e){
		int source, dest;
		cin >> source >> dest;
		adjacencyList[source]->push_back(dest);
		adjacencyList[dest]->push_back(source);
		count++;
	}

	if(isConnected(adjacencyList)){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}
	return 0;
}