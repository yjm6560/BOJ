/*
	색상환
	DP
*/
#include <iostream>
#include <limits.h>

using namespace std;

#define MOD 1000000003

long long N, K;
long long dp[1001][1001];

long long color(int n_size, int k_size){
	if(n_size < 0 || k_size < 0)
		return 0;
	if(dp[n_size][k_size] != -1)
		return dp[n_size][k_size];
	if(k_size <= 1)
		return n_size;
	if(n_size == k_size)
		return 0;
	dp[n_size][k_size] = (color(n_size-1, k_size))%MOD + (color(n_size-2, k_size-1))%MOD;
	return (dp[n_size][k_size])%MOD;
}

int main()
{
	cin >> N >> K;
	for(int i=0;i<=1000;i++){
		for(int j=1;j<=1000;j++)
			dp[i][j] = -1;
		dp[i][0] = 1;
	}
//	cout << "(N-1,K), (N-2,K-1), (N-4,K-2) : " << color(N-1,K) << ", " << color(N-2,K-1) << ", " << color(N-4, K-2) << endl;
	long long ret = color(N-1, K) + color(N-2,K-1) - color(N-4,K-2);
	cout << (MOD + color(N-1, K) + color(N-2,K-1) - color(N-4,K-2))%MOD << endl;
}
