/*
	돌 게임
	DP
	난이도
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	vector<bool> dp(N+1);

	dp[1] = true;
	dp[2] = false;

	for(int i=3;i<=N;i++)
		dp[i] = dp[i-2];
		 
	cout << (dp[N]? "SK\n" : "CY\n");

	return 0;
}
