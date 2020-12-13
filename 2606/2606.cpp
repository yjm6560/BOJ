/*
	바이러스
	DFS
	난이도
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> links; // 컴퓨터 간 연결 정보
vector<bool> visited; // 방문 확인

int dfs(int cur){
	if(visited[cur])
		return 0;
	visited[cur] = true;
	int cnt = 1; // 자신이 감염되므로 1부터 시작한다.
	for(auto next : links[cur])
		cnt += dfs(next);
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;

	links.reserve(N+1);
	visited.reserve(N+1);

	fill(visited.begin(), visited.end(), false);
	
	for(int i=0;i<M;i++){
		int a, b;
		cin >> a >> b;
		links[a].push_back(b);
		links[b].push_back(a);
	}

	cout << dfs(1) - 1 << endl; // 1번 노드 제외

	return 0;
}
