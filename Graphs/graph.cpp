#include <iostream>
#include <queue>

using namespace std;


void printDFS(int ** edges, int n, int sv, bool* visited){
	cout << sv << endl;
	visited[sv] = true;
	for(int i = 0; i < n; i++){
		if(i == sv) continue;
		if(edges[sv][i] == 1){
				if(visited[i])
					continue;
			printDFS(edges, n, i, visited);
		}
	}
}

/*
void printBFS(int** edges, int n, int sv){
	queue<int> pending_vertices;
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	pending_vertices.push(sv);
	visited[sv] = true;
	while(!pending_vertices.empty()){
		int currentVertex = pending_vertices.front();
		pending_vertices.pop();
		cout << currentVertex << endl;
		for(int i = 0; i < n; i++){
			if(edges[currentVertex][i] == 1 && !visited[i]){
				pending_vertices.push(i);
				visited[i] = true;
			}
		}
	}
	delete [] visited;

}
*/
void printBFS(int** edges, int n, int sv, bool* visited){
	queue<int> pending_vertices;
	pending_vertices.push(sv);
	visited[sv] = true;
	while(!pending_vertices.empty()){
		int currentVertex = pending_vertices.front();
		pending_vertices.pop();
		cout << currentVertex << endl;
		for(int i = 0; i < n; i++){
			if(edges[currentVertex][i] == 1 && !visited[i]){
				pending_vertices.push(i);
				visited[i] = true;
			}
		}
	}
}

void BFS(int** edges, int n){
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++)
		visited[i] = false;
	for(int i = 0; i < n; i++){
		if(!visited[i])
			printBFS(edges, n, i, visited);
	}
	delete [] visited;
}

void DFS(int** edges, int n){
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++)
		visited[i] = false;
	for(int i = 0; i < n; i++){
		if(!visited[i])
			printDFS(edges, n, i, visited);
	}
	delete [] visited;
}


int main(){
	int n;
	int e;

	cin >> n >> e;
	int** edges =new int*[n];
	for(int i = 0; i < n; i++){
		edges[i] = new int[n];
		for(int j = 0; j < n; j++)
			edges[i][j] = 0;
	}

	for(int i = 0; i<e; i++){
		int f, s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}

	bool* visited = new bool[n];
	for(int i = 0; i < n; i++)
		visited[i] = false;

// 0 as starting vertex
	cout << "DFS" << endl;
	// print(edges, n, 0, visited);
	DFS(edges, n);
	// above is actually a DFS

	cout <<"BFS"<< endl;
	// printBFS(edges, n, 0);
	BFS(edges, n);

	delete [] visited;
	for(int i = 0; i < n; i++)
		delete [] edges[i];
	delete [] edges;
}