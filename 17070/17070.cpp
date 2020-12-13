/*
	파이프 옮기기 1
	알고리즘
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
	
	int N, answer = 0;
	cin >> N;

	vector<vector<int>> house(N+1, vector<int>(N+1));
	/*
		0 - 가로
		1 - 세로
		2 - 대각선
	*/
	vector<vector<vector<int>>> dp(3,vector<vector<int>>(N+1, vector<int>(N+1, 0)));

	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cin >> house[i][j];

	for(int i=2;i<=N && !house[1][i];i++)
		dp[0][1][i] = 1;

	for(int i=2;i<=N;i++){
		for(int j=2;j<=N;j++){
			if(!house[i][j]){
				dp[0][i][j] = dp[0][i][j-1] + dp[2][i][j-1];
				dp[1][i][j] = dp[1][i-1][j] + dp[2][i-1][j];
				if(!house[i-1][j] && !house[i][j-1]){
					dp[2][i][j] = dp[0][i-1][j-1] + dp[1][i-1][j-1] + dp[2][i-1][j-1];
				}
			}
		}
	}
	for(int i=0;i<3;i++)
		answer += dp[i][N][N];
	
	cout << answer << endl;

	return 0;
}
