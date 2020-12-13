/*
	고층 빌딩
	DP
*/
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;
long long dp[101][101][101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, L, R;

	cin >> N >> L >> R;
	memset(dp, 0, sizeof(dp));
	
	dp[1][1][1] = 1;

	for(int i=2;i<=N;i++){
		for(int j=1;j<=L;j++){
			for(int k=1;k<=R;k++){
				dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-1][k])%MOD;
				dp[i][j][k] = (dp[i][j][k]+ dp[i-1][j][k-1])%MOD;
				dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k]*(i-2))%MOD;
			}
		}
	}
	cout << dp[N][L][R] << endl;
}
