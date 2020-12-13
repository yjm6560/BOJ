/*
	격자상의 경로
	DP
	난이도 2
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, K, dp[16][16];
	memset(dp, 0, sizeof(dp));

	for(int i=0;i<=15;i++)
		dp[0][i] = dp[i][0] = 1;
	
	for(int i=1;i<=15;i++)
		for(int j=1;j<=15;j++)
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
	cin >> N >> M >> K;
	if(K != 0){
		// (1, 1) -> ( K/M, K%M )
		// ( K/M, K%M ) -> (N, M)
		int x = (K-1)/M;
		int y = (K-1)%M;
		cout << (dp[x][y]*dp[N-x-1][M-y-1]) << "\n";
	} else {
		// (1, 1) -> (N, M)
		cout << dp[N-1][M-1] << "\n";
	}
}
