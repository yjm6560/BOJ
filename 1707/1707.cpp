/*
	이분 그래프
	그래프, DFS, BFS
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int K, V, E, visited[20001];
vector<int> board[20001];

bool dfs(int node){
	for(auto next : board[node]){
		if(visited[node] == visited[next])
			return false;
		if(!visited[next]){
			visited[next] = 3 - visited[node];
			if(!dfs(next)){
				return false;
			}
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> K;
	while(K--){
		int x, y;
		bool check = true;
		cin >> V >> E;
		
		memset(visited, 0, sizeof(visited));
		for(int i=1;i<=V;i++)
			board[i].clear();

		for(int i=0;i<E;i++){
			cin >> x >> y;
			board[x].push_back(y);
			board[y].push_back(x);
		}
		for(int i=1;i<=V;i++){
			if(visited[i])
				continue;
			visited[i] = 1;
			if(!dfs(i)){
				check = false;
				break;
			}
		}
		cout << (check? "YES" : "NO") << "\n";
	}
}
