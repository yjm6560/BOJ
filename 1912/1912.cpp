#include <iostream>

using namespace std;

int N, maxVal , arr[100001];
int dp[100001];
int main()
{
	cin >> N;
	for(int i=1;i<=N;i++)
		scanf("%d", &arr[i]);
	dp[N] = maxVal  = arr[N];
	for(int i=N-1;i>0;i--){
		if(dp[i+1] > 0) dp[i] = arr[i] + dp[i+1];
		else dp[i] = arr[i];
		if(dp[i] > maxVal ) maxVal = dp[i];
	}
	cout << maxVal  << endl;
}
