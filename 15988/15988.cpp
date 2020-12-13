#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000000
#define MOD 1000000009

using namespace std;

typedef long long LL;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T, n;
	vector<LL> dp(MAX+1, 0);
	
	dp[0] = dp[1] = 1;
	dp[2] = 2;

	for(int i=3;i<=MAX;i++)	dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%MOD;

	cin >> T;

	while(cin >> n){
//		cin >> n;
		cout << dp[n] << "\n";
	}

	return 0;
}
