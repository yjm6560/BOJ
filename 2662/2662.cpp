/*
   기업투자
   DP
*/

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<=b;i++)

int N, M, input, reward[301][21], dp[301][21], invested[301][21];

int invest(int budget, int order){
	if(dp[budget][order] != 0 || budget == 0 || order == M)
		return dp[budget][order];
	REP(i,0,budget){
		int tmp = reward[i][order]+invest(budget-i, order+1);
		if(tmp > dp[budget][order]){
			dp[budget][order] = tmp;
			invested[budget][order] = i;
		}
	}
	return dp[budget][order];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(reward, 0, sizeof(reward));
	memset(dp, 0, sizeof(dp));
	memset(invested, 0, sizeof(invested));

	cin >> N >> M;

	REP(i,1,N){
		cin >> input;
		REP(j,1,M){
			cin >> reward[i][j];
		}
		dp[i][M] = reward[i][M];
		invested[i][M] = i;
	}

	cout << invest(N,1) << endl;

	REP(i,1,M){
		cout << invested[N][i] << " ";
		N -= invested[N][i];
	}
	cout << endl;
}
