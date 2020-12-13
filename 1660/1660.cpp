/*
	캡틴 이다솜
	DP(bottom-up)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string.h>

using namespace std;

#define PB push_back
#define GETFOUR(n) ((n*(n+1)*(n+2))/6)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define MAX_VAL 120

int N, dp[300001];
vector<int> four;

int main()
{
	cin >> N;

	REP(i,0,300000)
		dp[i] = 300001;

	REP(i,0,MAX_VAL){
		four.PB(GETFOUR(i));
		dp[GETFOUR(i)] = 1;
	}
	
	REP(i,1,MAX_VAL)
		REP(j,four[i],N)
			dp[j] = min(dp[j], 1+dp[j-four[i]]);
	cout << dp[N] << endl;
}
