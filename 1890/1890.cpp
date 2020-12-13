/*
	점프
	DP
*/
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

long long N, answer = 0, board[100][100], dp[100][100];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for(long long i=0;i<N;i++){
		for(long long j=0;j<N;j++){
			cin >> board[i][j];
			dp[i][j] = 0;
		}
	}
	board[N-1][N-1] = dp[0][0] = 1;
	for(long long i=0;i<N;i++){
		for(long long j=0;j<N;j++){
			if(dp[i][j] == 0)
				continue;
			if(i+board[i][j] < N){
				if(dp[i+board[i][j]][j] != 0)
					dp[i+board[i][j]][j] += dp[i][j];
				else
				 	dp[i+board[i][j]][j] = dp[i][j];
			}
			if(j+board[i][j] < N){
				if(dp[i][j+board[i][j]] != 0)
					dp[i][j+board[i][j]] += dp[i][j];
				else 
					dp[i][j+board[i][j]] = dp[i][j];
			}
		}
	}
	cout << dp[N-1][N-1] << endl;
/*
	for(long long i=0;i<N;i++){
		for(long long j=0;j<N;j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
*/
}
