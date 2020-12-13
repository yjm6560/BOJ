/*
	앱
	DP
*/
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

#define MAX 10000001

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	vector<int> A(N, 0), C(N, 0), dp(N, MAX);
	
	for(int i=0;i<N;i++) cin >> A[i];
	for(int i=0;i<N;i++) cin >> C[i];
	
	dp[0] = C[0];

	for(int i=1;i<N;i++){
		for(int j=0;j<i;j++){
			dp[i] = min(dp[i], dp[j] + C[i]);
		}
	}
}
