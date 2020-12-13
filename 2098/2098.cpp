#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

#define REP(i,a,b) for(int i=a;i<=b;i++)
#define all_set (1<<16)
#define MAX_VAL 999999999

int N, W[17][17], set = 1;
int dp[all_set][17];

int TSP(int set, int cur){
	if(__builtin_popcount(set) == N){
		return W[cur][0];
	}
	if(dp[set][cur] != MAX_VAL)
		return dp[set][cur];
	REP(i,1,N){
		if(W[cur][i] == 0 || set&(1<<i))
			continue;
		int tmp = TSP(set|(1<<i), i);
		if(tmp != 0)
			dp[set][cur] = min(dp[set][cur], tmp + W[cur][i]);
	}
	return dp[set][cur];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	
	REP(i,0,all_set-1)
		REP(j,0,15)
			dp[i][j] = MAX_VAL;
	REP(i,0,N-1)
		REP(j,0,N-1)
			cin >> W[i][j];
	cout << TSP(set,0) << endl;
}
