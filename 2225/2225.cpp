/*
	합분해
	DP
*/
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
	int N, K, dp[201][201];
	const int MOD = 1000000000;
	
	cin >> N >> K;

	memset(dp, 0, sizeof(dp));
	for(int i=0;i<=200;i++){
		dp[0][i] = 0;
		dp[1][i] = dp[i][0] = 1;
	}
	
	for(int i=1;i<=200;i++)
		for(int j=2;j<=200;j++)
			dp[j][i] = (dp[j-1][i] + dp[j][i-1])%MOD;

	cout << dp[K][N] << endl;
}
