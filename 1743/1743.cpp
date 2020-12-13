#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, K, r, c, answer = 0;
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	cin >> N >> M >> K;
	vector<vector<bool>> road(N+1, vector<bool>(M+1, false));
	vector<vector<int>> visited(N+1, vector<int>(M+1, 0));

	while(K--){
		cin >> r >> c;
		road[r][c] = true;
	}

	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(road[i][j] && visited[i][j]==0){
				int cnt = 0;
				visited[i][j] = 1;
				queue<pair<int, int>> q;
				q.push({i, j});
				while(!q.empty()){
					cnt++;
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for(int d=0;d<4;d++){
						int nx = x + dx[d];
						int ny = y + dy[d];
						if(nx<=0 || nx>N || ny<=0 || ny>M)
							continue;
						if(road[nx][ny] && visited[nx][ny]==0){
							visited[nx][ny] = visited[x][y] + 1;
							q.push({nx, ny});
						}
					}
				}
				answer = max(answer, cnt);
			}
		}
	}
	cout << answer << endl;
	return 0;
}
