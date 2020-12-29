/*
	앱
	DP
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define N_MAX 100
#define C_MAX 100
#define M_MAX 10000000

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, maxCost, answer;
	vector<int> A(N_MAX, 0), C(N_MAX, 0);
	vector<int> dp(N_MAX*C_MAX + 1, 0);

	cin >> N >> M;
	
	for(int i=0;i<N;i++) cin >> A[i];
	for(int i=0;i<N;i++) cin >> C[i];
	
	maxCost = accumulate(C.begin(), C.end(), 0);
	
	for(int i=0;i<N;i++)
		for(int j=maxCost;j>=C[i];j--)
			dp[j] = max(dp[j], dp[j - C[i]] + A[i]);

	for(answer=0;answer<maxCost && dp[answer]<M;answer++);
	cout << answer << "\n";
}
