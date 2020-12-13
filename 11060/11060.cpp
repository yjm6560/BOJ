/*
	점프 점프
	DP
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N, board[1000], dp[1000];
const int INF = 987654321;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for(int i=0;i<N;i++){
		cin >> board[i];
		dp[i] = INF;
	}
	dp[0] = 0;

	for(int i=0;i<N;i++){
		for(int j=i;j<min(N, i+board[i]+1);j++){
			dp[j] = min(dp[j], dp[i] + 1);
		}
	}
	cout << (dp[N-1] == INF? -1 : dp[N-1]) << endl;
}
