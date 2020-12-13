/*
	사회망 서비스(SNS)
	DP
	난이도 3
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int N;
vector<int> tree[1000001];
int dp[1000001][2];

int solve(int parent, int cur, bool check){
	if(dp[cur][check] != -1)
		return dp[cur][check];
	int answer = 0;
	for(auto next : tree[cur]){
		if(parent == next)
			continue;
		if(check){
			answer += min(solve(cur, next, true) + 1, solve(cur, next, false));
		} else {
			answer += solve(cur, next, true) + 1;
		}
	}
	dp[cur][check] = answer;
	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for(int i=1,u,v;i<N;i++){
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
		dp[i][0] = dp[i][1] = -1;
	}
	dp[N][0] = dp[N][1] = -1;
	cout << min(solve(0, 1, true)+1, solve(0, 1, false)) << endl;
}
