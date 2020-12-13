/*
	크리보드
	DP
	난이도 1.5
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long N, buf = 0, dp[101];
	cin >> N;

	memset(dp, 0, sizeof(dp));

	dp[1] = 1, dp[2] = 2, dp[3] = 3;
	for(int i=1;i<=N;i++)
		for(int j=i+3;j<=N;j++)
			dp[j] = max(dp[j], max(dp[j-1] + 1, (j-i-1)*dp[i]));
	
	cout << dp[N] << endl;
}

