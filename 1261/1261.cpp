/*
	알고스팟
	??
	난이도
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};

	int N, M, answer = -1;
	cin >> M >> N;
	
	vector<vector<char>> miro(N+1, vector<char>(M+1));
	vector<vector<bool>> visited(N+1, vector<bool>(M+1, false));

	priority_queue<tuple<int, int, int>> pq;

	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			cin >> miro[i][j];

	pq.push({0, 1, 1});
	visited[1][1] = true;

	while(!pq.empty()){
		int wall = get<0>(pq.top());
		int x = get<1>(pq.top());
		int y = get<2>(pq.top());
		pq.pop();
		
		if(x==N && y==M){
			answer = -wall;
			break;
		}
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx<=0 || nx>N || ny<=0 || ny>M)
				continue;
			if(visited[nx][ny])
				continue;
			
			visited[nx][ny] = true;
			pq.push({(miro[nx][ny]=='1'? wall-1 : wall), nx, ny});
		}
	}
	
	cout << answer << endl;

	return 0;
}
