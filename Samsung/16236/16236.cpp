/*
	아기 상어
	시뮬레이션, BFS
	난이도 2
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

vector<vector<int>> sea(20, vector<int>(20, 0));
int N, sharkSize = 2, eatCnt = 0, ret, sx, sy;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
const int INF = 987654321;

int bfs(){
	int answer = INF;
	vector<vector<int>> visited(N, vector<int>(N, INF));
	queue<pair<int, int>> q;
	q.push({sx, sy});
	visited[sx][sy] = 0;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(sea[x][y]>0 && sea[x][y]<sharkSize)
			answer = min(answer, visited[x][y]);

		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx<0 || nx==N || ny<0 || ny==N || visited[nx][ny]<INF)
				continue;
			visited[nx][ny] = visited[x][y] + 1;
			if(sea[nx][ny] <= sharkSize)
				q.push({nx, ny});
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(sea[i][j]>0 && sea[i][j]<sharkSize
					&& visited[i][j]==answer){
				sea[i][j] = 0;
				sx = i;
				sy = j;
				return visited[i][j];
			}
		}
	}
	return INF;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int answer = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> sea[i][j];
			if(sea[i][j] == 9){
				sx = i;
				sy = j;
				sea[i][j] = 0;
			}
		}
	}
	while((ret = bfs()) < INF){
		answer += ret;
		if(++eatCnt == sharkSize){
			sharkSize++;
			eatCnt = 0;
		}
	}
	cout << answer << endl;
}
