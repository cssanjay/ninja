#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

bool hasPath_DFS(unordered_map<int, vector<int>* > &adjacencyList, int v1, int v2, unordered_map<int, bool> &visited){
	vector<int>* adjacencyVertices = adjacencyList[v1];

	for(int i = 0; i < adjacencyVertices->size(); i++){
		if(adjacencyVertices->at(i) == v2){
			return true;
		}
	}

	visited[v1] = true;

	// Recursion call
	for(int i = 0; i < adjacencyVertices->size(); i++){
		if(visited.count(adjacencyVertices->at(i)) == 0){
			int ans = hasPath_DFS(adjacencyList, adjacencyVertices->at(i), v2, visited);
			if(ans)
				return true;
		}
	}
	return false;
}

bool hasPath_DFS(unordered_map<int, vector<int>* > &adjacencyList, int v1, int v2){
	unordered_map<int, bool> visited;
	return hasPath_DFS(adjacencyList, v1, v2, visited);
}

int main(){
	int n, e;
	cin >> n >> e;

	// Taking graph input and creating an adjacency list
	unordered_map<int, vector<int>* > adjacencyList;
	for(int i = 0; i < n; i++){
		vector<int> *v = new vector<int>;
		adjacencyList[i] = v;
	}

	int count = 1;
	while(count <= e){
		int source, dest;
		cin >> source >> dest;
		adjacencyList[source] -> push_back(dest);
		adjacencyList[dest]->push_back(source);
		count++;
	}

	int v1, v2;
	cin >> v1 >> v2;

	if(hasPath_DFS(adjacencyList, v1, v2)){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}

	return 0;
}