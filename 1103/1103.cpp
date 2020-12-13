/*
	게임
	DP, 그래프
	난이도 2.5
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, board[50][50], dp[50][50];
bool visited[50][50];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solve(int x, int y){
	if(visited[x][y])
		return -1;
	if(dp[x][y]>0)
		return dp[x][y];
	dp[x][y] = 1;
	visited[x][y] = true;
	for(int i=0;i<4;i++){
		int nx = x + dx[i] * board[x][y];
		int ny = y + dy[i] * board[x][y];

		if(nx<0||ny<0||nx>=N||ny>=M||board[nx][ny]=='H'-'0')
			continue;

		int ret = solve(nx, ny);
		if(ret == -1){
			dp[x][y] = -1;
			break;
		}
		dp[x][y] = max(dp[x][y], ret + 1);
	}
	visited[x][y] = false;
	return dp[x][y];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(board, 0, sizeof(board));
	memset(dp, 0, sizeof(dp));
	
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			char c;
			cin >> c;
			board[i][j] = c - '0';
			dp[i][j] = -1;
		}
	}

	cout << solve(0, 0) << endl;
}
