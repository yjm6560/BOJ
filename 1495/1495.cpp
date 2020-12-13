/*
	기타리스트
	DP
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
	
	int N, S, M;

	cin  >> N >> S >> M;
	
	vector<int> V(N+1);
	vector<vector<bool>> dp(M+1, vector<bool>(N+1, false));

	for(int i=0;i<N;i++)
		cin >> V[i];

	dp[S][0] = true;

	for(int i=0;i<N;i++){
		for(int j=0;j<=M;j++){
			if(j-V[i]>=0 && dp[j][i]){
				dp[j-V[i]][i+1] = dp[j][i];
			}
			if(j+V[i]<=M && dp[j][i]){
				dp[j+V[i]][i+1] = dp[j][i];
			}
		}
	}
	for(int i=M;i>=0;i--){
		if(dp[i][N]){
			cout << i << "\n";
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}
