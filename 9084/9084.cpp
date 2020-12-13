/*
	동전
	DP
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_COIN_NUM 20
#define MAX_VAL 10001

using namespace std;

int T, N, M;
vector<int> coins(MAX_COIN_NUM, 0);
vector<vector<int>> dp(MAX_VAL, vector<int>(MAX_COIN_NUM, MAX_VAL));

int solve(int idx, int budget){
	if(budget == 0)
		return 1;
	if(idx == N)
		return 0;
	if(dp[budget][idx] < MAX_VAL)
		return dp[budget][idx];
	dp[budget][idx] = 0;
	for(int i=0;i*coins[idx]<=budget;i++){
		dp[budget][idx] += solve(idx+1, budget - i*coins[idx]);
	}
	return dp[budget][idx];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while(T--){
		fill(coins.begin(), coins.end(), 0);
		for(int i=0;i<MAX_VAL;i++)
			fill(dp[i].begin(), dp[i].end(), MAX_VAL);

		cin >> N;
		for(int i=0;i<N;i++)
			cin >> coins[i];
		cin >> M;
		cout << solve(0, M) << endl;
	}
	return 0;
}
