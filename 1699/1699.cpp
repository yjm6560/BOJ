#include <iostream>

using namespace std;

int N, dp[1000001];

int main()
{
	cin >> N;
	for(int i=1;i<=N;i++) dp[i] = 100000000;
	for(int i=1;i<=316;i++) dp[i*i] = 1;
	for(int i=2;i<=N;i++) for(int j=1;j*j<=i;j++) dp[i] = min(dp[i],dp[j*j] + dp[i-j*j]);
	cout << dp[N] << endl;
}

