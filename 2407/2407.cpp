#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long n, m;
	long long INF = 1000000000;
	string ans1, ans2;
	cin >> n >> m;
	vector<vector<vector<int>>> dp(10, vector<vector<int>(101, vector<int>(101,0)));
	
	for(int i=0;i<=n;i++){
		dp[0][i][0] = dp[0][i][i] = 1;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=0;k<9;k++){
				dp[k][i][j] = dp[k][i-1][j-1] + dp[k][i-1][j];
				dp[k+1][i][j] = dp[k+1][i-1][j-1] + dp[k+1][i-1][j];
				
				dp[k+1][i][j] += dp[k][i][j]/INF;
				dp[k][i][j] %= INF;
			}
		}
	}
	
	if(dp2[n][m] > 0){
		ans1 = to_string(dp1[n][m]);
		cout << dp2[n][m];
		for(int i=0;i<9-ans1.length();i++)
			cout << 0;
	}
	cout << dp1[n][m] << endl;

	return 0;
}
