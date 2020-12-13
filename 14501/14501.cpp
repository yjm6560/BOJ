/*
	퇴사
	DP
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, t[16], p[16], dp[17];
	cin >> N;

	for(int i=1;i<=N;i++){
		cin >> t[i] >> p[i];
		dp[i] = 0;
	}
	dp[N+1] = 0;
	
	for(int i=1;i<=N;i++)
		for(int j=i+t[i]; j<=N+1;j++)
			dp[j] = max(dp[j], dp[i]+p[i]);

	cout << dp[N+1] << endl;
}
