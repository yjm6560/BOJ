/*
	욕심쟁이 판다
	DP
	난이도 2.5
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

int n, answer = 0, boo[500][500], dp[500][500];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solve(int x, int y){
	if(dp[x][y])
		return dp[x][y];
	dp[x][y] = 1;
	for(int i=0;i<4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx<0 || nx==n || ny<0 || ny == n)
			continue;
		if(boo[x][y] < boo[x+dx[i]][y+dy[i]])
			dp[x][y] = max(dp[x][y], 1 + solve(x+dx[i], y+dy[i]));
	}
	return dp[x][y];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(boo, 0, sizeof(boo));
	memset(dp, 0, sizeof(dp));

	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> boo[i][j];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!dp[i][j]){
				answer = max(answer, solve(i,j));
			}
		}
	}
	cout << answer << "\n";
}
