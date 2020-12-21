#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 50
#define MAX_M 50

using namespace std;

/*
0 북
1 동
2 남
3 서
*/

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
int N, M, sx, sy, sd, answer = 0;
vector<vector<int>> room(MAX_N + 1, vector<int>(MAX_M + 1, 0));
vector<vector<int>> dp(MAX_N + 1, vector<int>(MAX_M + 1, 0));

void clean(int x, int y, int direction){
	for(int i=3;i>=0;i--){
		int nd = (direction + i)%4;
		int nx = x + dx[nd];
		int ny = y + dy[nd];
		if(nx<0 || nx>=N || ny<0 || ny>=M)
			continue;
		if(room[nx][ny]==1 || dp[nx][ny]>0)
			continue;
		dp[nx][ny] = 1;
		clean(nx, ny, nd);
		return;
	}
	int nd = (direction+2)%4;
	int nx = x + dx[nd];
	int ny = y + dy[nd];	
	
	if(nx<0 || nx>=N || ny<0 || ny>=M || room[nx][ny]==1)
		return;
	
	dp[nx][ny] = 1;
	clean(nx, ny, direction);

	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	cin >> sx >> sy >> sd;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin >> room[i][j];
	dp[sx][sy] = 1;
	clean(sx, sy, sd);
	
	for(auto r : dp)
		for(auto val : r)
			answer += val;

	cout << answer << endl;

	return 0;
}
