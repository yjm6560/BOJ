/*
	동전 2
	DP
	난이도
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

	int n, k, INF = 987654321;
	cin >> n >> k;

	vector<int> coin(n);
	vector<int> dp(10001, INF);

	for(int i=0;i<n;i++)
		cin >> coin[i];
	
	dp[0] = 0;
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			if(i+coin[j] > k)
				break;
			dp[i+coin[j]] = min(dp[i+coin[j]], dp[i] + 1);
		}
	}
	cout << (dp[k]==INF? -1 : dp[k]) << endl;
}
