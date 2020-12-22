/*
	벽 부수고 이동하기
	DFS, BFS
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	vector<int> dx = {-1, 1, 0, 0};
	vector<int> dy = {0, 0, -1, 1};
	
	int N, M, answer = -1;
	cin >> N >> M;
	vector<vector<char>> road(N+1, vector<char>(M+1));
	vector<vector<vector<int>>> dp(2, vector<vector<int>>(N+1, vector<int>(M+1, 0)));
	queue<tuple<int, int, bool>> q;

	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			cin >> road[i][j];
	
	dp[0][1][1] = 1;

	q.push({1, 1, 0});

	while(!q.empty()){
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int wall = get<2>(q.front());
		q.pop();
		if(x==N && y==M){
			answer = dp[wall][x][y];
			break;
		}
		for(int d=0;d<4;d++){
			int nx = x + dx[d];
			int ny = y + dy[d];
			if(nx<1 || nx>N || ny<1 || ny>M)
				continue;
			if(road[nx][ny]=='0' && dp[wall][nx][ny]==0){
				dp[wall][nx][ny] = dp[wall][x][y] + 1;
				q.push({nx, ny, wall});
			} else if(wall==0 && road[nx][ny]=='1' && dp[0][nx][ny]==0){
				dp[1][nx][ny] = dp[wall][x][y] + 1;
				q.push({nx, ny, 1});
			}
		}
	}
	
	cout << answer << "\n";

	return 0;
}
