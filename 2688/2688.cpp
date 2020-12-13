/*
	줄어들지 않아
	DP
*/
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long dp[65][10];
	int T, input;
	memset(dp, 0, sizeof(dp));

	for(int i=0;i<10;i++)
		dp[1][i] = 1;
	for(int i=2;i<=64;i++){
		for(int j=0;j<10;j++){
			for(int k=j;k<10;k++){
				dp[i][j] += dp[i-1][k];
			}
		}
	}
	cin >> T;
	while(T--){
		cin >> input;
		long long answer = 0;
		for(int i=0;i<10;i++)
			answer += dp[input][i];
		cout << answer << "\n";
	}
}
