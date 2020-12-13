/*
   자두나무
   DP
*/
#include <iostream>
#include <algorithm>

using namespace std;

int T, W, jadu[3000], dp[2][1000][31];

int eat(int pos, int cur, int budget){
	if(cur == T || budget < 0)
		return 0;
	if(dp[pos-1][cur][budget] == -1)
		dp[pos-1][cur][budget] = (jadu[cur] == pos? 1 : 0) + max(eat(pos, cur + 1, budget), eat(3-pos, cur + 1, budget-1));
	return dp[pos-1][cur][budget];
}

int main()
{
	cin >> T >> W;
	for(int i=0;i<T;i++)
		cin >> jadu[i];
	for(int i=0;i<T;i++)
		for(int j=0;j<=W;j++)
			dp[0][i][j] = dp[1][i][j] = -1;
	cout << max(eat(1, 0, W), eat(2, 0, W-1)) << endl;
}
