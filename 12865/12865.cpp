#include <iostream>

using namespace std;

int N, K, W[101], V[101], knap[101];

int knapsack_recursive(int pos, int capacity){
	if(pos == N) return knap[pos];
	int ret = 0;
	if(capacity >= W[pos]){
		ret = knapsack_recursive(pos+1, capacity - W[pos]) + V[pos];
	}
	knap[pos] = max(knapsack_recursive(pos+1, capacity), ret);
	return knap[pos];
}

int knap_dp[101][100001];

int knapsack_dp(int pos, int capacity){
	if(pos == N+1) return 0;
	if(knap_dp[pos][capacity] != -1) return knap_dp[pos][capacity];
	int ret = 0;
	if(capacity >= W[pos]){
		ret = knapsack_dp(pos+1, capacity - W[pos]) + V[pos];
	}
	knap_dp[pos][capacity] = max(knapsack_dp(pos+1, capacity), ret);
	return knap_dp[pos][capacity];
}
int main()
{
	cin >> N >> K;
	for(int i=1;i<=N;i++){
		cin >> W[i] >> V[i];
		knap[i] = 0;
		for(int j=1;j<=K;j++)
			knap_dp[i][j] = -1;
	}
	cout << knapsack_dp(1, K) << endl;
}
