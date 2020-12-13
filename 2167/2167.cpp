/*
	2차원 배열의 합
	DP
	난이도 1.5
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M, K, sx, sy, dx, dy;
	int matrix[301][301], dp[301][301];

	memset(dp, 0, sizeof(dp));
	memset(matrix, 0, sizeof(matrix));


	cin >> N >> M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin >> matrix[i][j];
			dp[i][j] = matrix[i][j];
		}
	}

	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];

	cin >> K;
	while(K--){
		cin >> sx >> sy >> dx >> dy;
		cout << dp[dx][dy] - dp[sx-1][dy] - dp[dx][sy-1] +dp[sx-1][sy-1] << "\n";
	}
}
