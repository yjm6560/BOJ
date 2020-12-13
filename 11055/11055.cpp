/*
	가장 큰 증가 부분 수열
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

	int N, answer = 0, arr[1001], dp[1001];

	memset(arr, 0, sizeof(arr));
	memset(dp, 0, sizeof(dp));

	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> arr[i];
		dp[i] = arr[i];
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<i;j++){
			if(arr[i] > arr[j]){
				dp[i] = max(dp[i], dp[j] + arr[i]);
			}
		}
		answer = max(answer, dp[i]);
	}
	cout << answer << endl;
}
