/*
	단지번호붙이기
	그래프, DFS, BFS
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

string input;
int N, answer = 0;
bool town[25][25], visited[25][25];
vector<int> apartment;
int dx[4] = { -1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1};

int bfs(pair<int, int> cur){
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push(cur);
	while(!q.empty()){
		cnt++;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx<0 || nx==N || ny<0 || ny==N)
				continue;
			if(town[nx][ny] && !visited[nx][ny]){
				visited[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	memset(town, 0, sizeof(town));
	memset(visited, 0, sizeof(visited));
	
	for(int i=0;i<N;i++){
		cin >> input;
		for(int j=0;j<N;j++){
			town[i][j] = (input[j]=='1'? true : false);
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(town[i][j] && !visited[i][j]){
				answer++;
				visited[i][j] = true;
				apartment.push_back(bfs({i, j}));
			}
		}
	}
	cout << answer << "\n";
	sort(apartment.begin(), apartment.end());
	for(auto x : apartment)
		cout << x << "\n";
}
