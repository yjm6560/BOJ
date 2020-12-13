/*
	게임 개발
	DP
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500

using namespace std;

int N;
vector<vector<int>> build(MAX+1, vector<int>(0));
vector<int> b_time(MAX+1, 0);
vector<int> dp(MAX+1, -1);

int solve(int b_num){
	if(dp[b_num] >= 0)
		return dp[b_num];

	dp[b_num] = b_time[b_num];

	for(auto c : build[b_num])
		dp[b_num] = max(dp[b_num], solve(c) + b_time[b_num]);

	return dp[b_num];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;

	for(int i=1;i<=N;i++){
		int child;
		cin >> b_time[i] >> child;
		while(child != -1){
			build[i].push_back(child);
			cin >> child;
		}
	}

	for(int i=1;i<=N;i++)
		cout << solve(i) << "\n";
	return 0;
}
