#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int A, B, C, N;

	cin >> A >> B >> C >> N;
	
	vector<bool> dp(N+1, false);
	dp[0] = false;
	dp[A] = dp[B] = dp[C] = true;

	for(int i=1;i<=N;i++)
		dp[i] = dp[i] || dp[max(0, i-A)] || dp[max(0, i-B)] || dp[max(0, i-C)];

	cout << dp[N] << "\n";
	
	return 0;
}

