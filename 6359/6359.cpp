/*
	만취한 상범
	DP
	난이도 2
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

	int T, N, dp[2][101];
	memset(dp, 0, sizeof(dp));
	
	dp[0][1] = dp[1][1] = 1;
	for(int i=2;i<=100;i++){
		for(int j=1;j<=i;j++)
			if(i%j == 0)
				dp[0][i]++;
		dp[1][i] = dp[1][i-1] + (dp[0][i]%2?1:0);
	}
	cin >> T;
	while(T--){
		cin >> N;
		cout << dp[1][N] << "\n";
	}
}
