/*
	연속합
	DP
	N개의 수열에서 연속해있는 부분 수열 중 최대 합을 출력한다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N, maxVal , arr[100001], dp[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for(int i=1;i<=N;i++)
		cin >> arr[i];	
	
	maxVal = dp[1] = arr[1];

	for(int i=2;i<=N;i++){
		dp[i] = dp[i-1] > 0 ? arr[i] + dp[i-1] : arr[i];
		maxVal = max(maxVal, dp[i]);
	}

	cout << maxVal  << endl;
}
