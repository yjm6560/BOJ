/*
	구간 합 구하기 5
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
	
	int N, M;
	int x1, y1, x2, y2;

	cin >> N >> M;

	vector<vector<int>> table(N+1, vector<int>(N+1, 0));
	vector<vector<int>> dp(N+1, vector<int>(N+1, 0));

	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cin >> table[i][j];

	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + table[i][j];
	for(int i=0;i<M;i++){
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1] << "\n";
	}

	return 0;
}

