/*
	타일 채우기
	DP
*/
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
	int N, dp[31];

	memset(dp,0,sizeof(dp));
	cin >> N;
	dp[0] = 1;
	dp[2] = 3;
	dp[4] = 3*dp[2] + 2;
	for(int i=5;i<=30;i++){
		dp[i] = dp[i-2];
		for(int j=2;i>=j;j+=2){
			dp[i] += 2*dp[i-j];
		}
	}
	cout << dp[N] << endl;
}
