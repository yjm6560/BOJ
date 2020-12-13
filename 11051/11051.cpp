/*
	이항 계수 2
	DP
	난이도
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, K;
	const int mod = 10007;

	cin >> N >> K;

	vector<vector<int>> dp(N+1, vector<int>(N+1, 0));

	for(int i=0;i<=N;i++)
		dp[i][0] = dp[i][i] = 1;
	
	for(int i=2;i<=N;i++){
		for(int j=1;j<i;j++){
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
		}
	}
	cout << dp[N][K] << endl;
}
