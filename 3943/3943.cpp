/*
	헤일스톤 수열
	DP
*/
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

long long T, n, dp[100000000];

long long solve(long long idx){
//	if(dp[idx])
//		return dp[idx];
	if(idx == 1)
		return 1;
	return max(idx, (idx%2? solve(idx*3 + 1):solve(idx/2)));
//	long long result = (idx%2? solve(idx*3 + 1) : solve(idx/2));
//	dp[idx] = max(idx, result);
//	return dp[idx];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(dp, 0, sizeof(dp));
	cin >> T;
	while(T--){
		cin >> n;
		cout << n << " : " << solve(n) << "\n";
	}
}
