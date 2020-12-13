/*
	소형기관차
	DP
	난이도 2
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;


int solve(const int N, const int miniTrain, const vector<int> train){
	int answer = 0;
	int dp[50001];

	memset(dp, 0, sizeof(dp));

	for(int i=0;i<miniTrain;i++)
		dp[0] += train[i];
	for(int i=1;i<=N-miniTrain;i++)
		dp[i] = dp[i-1] - train[i-1] + train[i+miniTrain-1];
	/*
		//O(N^3) solution

	for(int i=0;i<=N-3*miniTrain;i++){
		for(int j=i+miniTrain;j<=N-2*miniTrain;j++){
			for(int k=j+miniTrain;k<=N-miniTrain;k++){
				answer = max(answer, dp[i]+dp[j]+dp[k]);
			}
		}
	}
	*/

	int mDP[2][50001];
	memset(mDP, 0, sizeof(mDP));
	mDP[0][0] = dp[0];
	for(int i=1;i<=N-miniTrain;i++){
		mDP[0][i] = max(mDP[0][i-1], dp[i]);
		if(i>=miniTrain)
			mDP[1][i] = max(mDP[1][i-1], mDP[0][i-miniTrain] + dp[i]);
		if(i>=miniTrain*2)
			answer = max(mDP[2][i-1], mDP[1][i-miniTrain] + dp[i]);
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, miniTrain;
	cin >> N;
	vector<int> train(N);
	for(int i=0;i<N;i++)
		cin >> train[i];
	cin >> miniTrain;

	cout << solve(N, miniTrain, train) << endl;
}
