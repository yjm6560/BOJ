/*
	카드 구매하기
	DP
*/

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, P[1001], dp[1001];

	memset(P, 0, sizeof(P));
	memset(dp, 0, sizeof(dp));

	cin >> N;
	for(int i=1;i<=N;i++)
		cin >> P[i];
	for(int i=1;i<=N;i++){
		for(int j=0;j<=N-i;j++){
			dp[j+i] = max(dp[j+i], dp[j] + P[i]);
		}
	}

	cout << dp[N] << endl;
}
