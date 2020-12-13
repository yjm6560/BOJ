/*
	DP
	moving
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M, miro[1001][1001], miro_dp[1001][1001];
	
	cin >> N >> M;

	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin >> miro[i][j];
			miro_dp[i-1][j-1] = 0;
		}
	}
	miro_dp[N][0] = miro_dp[0][M] = 0;

	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			miro_dp[i][j] = max(miro_dp[i-1][j], max(miro_dp[i-1][j-1], miro_dp[i][j-1])) + miro[i][j];
		}
	}
	cout << miro_dp[N][M] << endl;
}
