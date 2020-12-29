/*
	앱
	DP
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define N_MAX 100
#define C_MAX 100
#define M_MAX 10000000

using namespace std;

int N, M;
vector<int> A(N_MAX, 0), C(N_MAX, 0);
vector<map<int, int>> dp(N_MAX);

int solve(int idx, int needMemory){
	if(idx >= N)
		return M_MAX;	
	if(needMemory <= 0)
		return 0;

	if(dp[idx][needMemory] <= 0)
		dp[idx][needMemory] = min(solve(idx + 1, needMemory), C[idx] + solve(idx + 1, needMemory - A[idx]));

	return dp[idx][needMemory];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	
	for(int i=0;i<N;i++) cin >> A[i];
	for(int i=0;i<N;i++) cin >> C[i];

	cout << solve(0, M) << endl;
}
