/*
	순열 사이클
	그래프, DFS, BFS, 사이클
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int T, N, cnt, board[1001], visited[1001];

void dfs(int e, int cycle){
	if(visited[e] == cycle){
		cnt++;
		return;
	}
	visited[e] = cycle;
	dfs(board[e], cycle);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while(T--){
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		int cycle = 1;
		cin >> N;

		for(int i=1;i<=N;i++)
			cin >> board[i];

		for(int i=1;i<=N;i++)
			if(!visited[i])
				dfs(i, cycle);
		
		cout << cnt << endl;
	}
}
