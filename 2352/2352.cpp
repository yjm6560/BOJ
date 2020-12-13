/*
	반도체 설계
	DP
	난이도 3
*/
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, port[40001], dp[40001], answer = 0;
	memset(dp, 0, sizeof(dp));
	cin >> N;
	
	for(int i=0;i<N;i++)
		cin >> port[i];

	dp[0] = port[0];

	for(int i=1;i<N;i++)
		if(dp[answer] < port[i])
			dp[++answer] = port[i];
		else 
			dp[lower_bound(dp, dp+answer, port[i]) - dp] = port[i];
	
	cout << answer + 1 << "\n";
}
