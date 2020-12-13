/*
	RGB2
	DP3
*/

#include <iostream>
#include <limits.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define MAX_VAL 999999999;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, house[3][1001], h_dp[3][1001], ret[3];

	cin >> N;
	REP(i,0,N){
		REP(j,0,3){
			cin >> house[j][i];
			h_dp[j][i] = MAX_VAL;
		}
	}
	if(N == 1){
		cout << min(house[0][0], min(house[1][0], house[2][0])) << endl;
		return 0;
	}
	REP(i,0,3){
		house[i][N] = h_dp[i][0] = house[i][0];
		h_dp[i][N] = MAX_VAL;
		ret[i] = 0;
	}	
	REP(k,0,3){
		h_dp[k][0] = MAX_VAL;
		REP(i,1,N){
			h_dp[0][i] = house[0][i] + min(h_dp[1][i-1], h_dp[2][i-1]);
			h_dp[1][i] = house[1][i] + min(h_dp[0][i-1], h_dp[2][i-1]);
			h_dp[2][i] = house[2][i] + min(h_dp[0][i-1], h_dp[1][i-1]);
		}
//		if(k==0) ret[k] = min(h_dp[1][N-1], h_dp[2][N-1]);
//		else if(k==1) ret[k] = min(h_dp[0][N-1], h_dp[2][N-1]);
//		else ret[k] = min(h_dp[0][N-1], h_dp[1][N-1]);
		ret[k] = h_dp[k][N-1];
		h_dp[k][0] = house[k][0];
	}
	cout << min(ret[0], min(ret[1], ret[2]));
//	cout << min(h_dp[0][N-1], min(h_dp[1][N-1], h_dp[2][N-1])) << endl;
}
