/*
	연결 요소의 개수
	DFS, BFS
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M, u, v, cnt = 0;
bool visited[1001];
vector<int> graph[1001];

void dfs(int idx){
	visited[idx] = true;
	for(auto next : graph[idx])
		if(!visited[next])
			dfs(next);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(visited, 0, sizeof(visited));
	cin >> N >> M;
	for(int i=1;i<=M;i++){
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for(int i=1;i<=N;i++){
		if(!visited[i]){
			cnt++;
			dfs(i);
		}
	}
	cout << cnt << endl;
}
