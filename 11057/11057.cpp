/*
	오르막 수
	DP
*/
#include <iostream>
#include <string.h>

using namespace std;

const int mod = 10007;
int N, ret=0, dp[1001][10];

int main()
{
	cin >> N;
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<10;i++)
		dp[1][i] = 1;

	for(int i=2;i<=N;i++){
		for(int j=0;j<10;j++){
			for(int k=j;k<10;k++){
				dp[i][j] += dp[i-1][k]%mod;
			}
		}
	}
	for(int i=0;i<10;i++)
		ret += dp[N][i];
	cout << ret%mod << endl;
}
