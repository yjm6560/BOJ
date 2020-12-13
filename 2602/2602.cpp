/*
	돌다리 건너기
	DP
*/

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

string huzi, rocks[2];
int dp[2][101][101];

int solve(int a, int b, int c){
	if(dp[a][b][c])
		return dp[a][b][c];
	if(c > huzi.length())
		return 0;
	if(c == huzi.length())
		return 1;
	for(int i=b;i<rocks[a].length();i++){
		if(rocks[a][i] == huzi[c]){
			dp[a][b][c] += solve(1-a, i+1, c+1);
		}
	}
	return dp[a][b][c];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp,0,sizeof(dp));

	cin >> huzi >> rocks[0] >> rocks[1];
	cout << solve(0,0,0)+solve(1,0,0) << endl;
}
