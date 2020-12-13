/*
	2xn 타일링
	DP
*/
#include <iostream>
#include <string.h>

using namespace std;

const int MOD = 10007;

int main()
{
	int n, dp[1001];
	memset(dp, 0, sizeof(dp));
	
	cin >> n;

	dp[1] = 1;
	dp[2] = 3;

	for(int i=3;i<=n;i++)
		dp[i] = (dp[i-1] + 2*dp[i-2])%MOD;
	cout << dp[n] << endl;
}
