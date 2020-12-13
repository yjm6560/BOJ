/*
	가장 큰 정사각형
	DP
	난이도 2.5
*/
#include <iostream>
#include <string.h>
#include <vector>
#define MAX 1000
using namespace std;

vector<string> board;
int n, m, dp[MAX][MAX];
int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};
const int INF = 987654321;

int solve(int x, int y){
	if(dp[x][y])
		return dp[x][y];
	dp[x][y] = INF;
	for(int i=0;i<3;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx==n || ny==m || board[nx][ny]=='0'){
			dp[x][y] = 1;
			break;
		}
		else
			dp[x][y] = min(dp[x][y], 1 + solve(nx, ny));
	}
	return dp[x][y];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(dp, 0, sizeof(dp));

	int answer = 0;
	
	cin >> n >> m;
	
	board.resize(n);

	for(int i=0;i<n;i++)
		cin >> board[i];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(board[i][j] == '1' && !dp[i][j])
				solve(i, j);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			answer = max(answer, dp[i][j]);
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << answer*answer << "\n";
}
