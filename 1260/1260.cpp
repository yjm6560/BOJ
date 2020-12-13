/*
	DFS와 BFS
	그래프, DFS, BFS
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int N, M, V;
bool board[1001][1001], d_visited[1001], b_visited[1001];

void dfs(int e){
	cout << e << " ";
	d_visited[e] = true;
	for(int next=1;next<=N;next++)
		if(board[e][next] && !d_visited[next])
			dfs(next);
}

void bfs(int e){
	queue<int> q;
	b_visited[e] = true;
	q.push(e);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		cout << cur << " ";
		for(int next=1;next<=N;next++){
			if(board[cur][next] && !b_visited[next]){
				b_visited[next] = true;
				q.push(next);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(board, 0, sizeof(board));
	memset(d_visited, 0, sizeof(d_visited));
	memset(b_visited, 0, sizeof(b_visited));
	
	cin >> N >> M >> V;
	int x, y;
	for(int i=0;i<M;i++){
		cin >> x >> y;
		board[x][y] = board[y][x] = true;
	}
	dfs(V);
	cout << "\n";
	bfs(V);
	cout << "\n";
}

