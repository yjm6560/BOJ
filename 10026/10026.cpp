/*
	적록색약
	BFS, DFS
*/

#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;
bool visited[100][100][2];
char pic[100][100][2];
queue<pair<int, int>> q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
const int INF = 987654321;

void bfs(int idx){
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
	
			if(nx<0 || nx==N || ny<0 || ny==N)
				continue;
			if(visited[nx][ny][idx])
				continue;
			if(pic[nx][ny][idx] != pic[x][y][idx])
				continue;
			visited[nx][ny][idx] = true;
			q.push({nx, ny});
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> pic[i][j][0];
			pic[i][j][1] = (pic[i][j][0] == 'G'? 'R':pic[i][j][0]);
			visited[i][j][0] = visited[i][j][1] = false;
		}
	}
	for(int k=0;k<2;k++){
		int cnt = 0;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(!visited[i][j][k]){
					q.push({i, j});
					bfs(k);
					cnt++;
				}
			}
		}
		cout << cnt << " ";
	}
	cout << endl;
}
