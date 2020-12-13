/*
	연구소 3
	그래프
	난이도
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N, M, count = 0, answer = 0;

vector<vector<int>> lab(N, vector<int>(N));
vector<vector<vector<int>>> visited(126, vector<vector<int>>(N, vector<int>(N, 0)));

int bfs(int x){
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	cin >> N >> M;

	queue<pair<int, int>> q;

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> lab[i][j];
	for(int k=0;k<126;k++)
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(lab[i][j]
				visited[k][i][j] = 
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx<0 || nx==N || ny<0 || ny==N)
				continue;
			if(visited[nx][ny]!=0)
				continue;
			visited[nx][ny] = visited[x][y] + 1;
			q.push({nx, ny});
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			answer = max(answer, visited[i][j]);
			cout << visited[i][j] << " ";
			if(visited[i][j] == 0){
				cout << "-1\n";
				return 0;
			}
		}
		cout << endl;
	}
	cout << answer << "\n";
	return 0;
}
