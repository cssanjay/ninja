#include <iostream>
#define NM 105;

using namespace std;
int visited[NM];
int adj[NM][NM];
void dfs(int u, int p, int n){
	if(visited[u])
		return;
	visited[u] = 1;
	for(int i = 1; i <= n; i++)
		if(adj[u][i] && i!=p)
			dfs(i,u,n);
}

int solve(int n, int m, vector<int> u, vector<int> v){
	for(int i = 0; i < m; i++){

	}
}