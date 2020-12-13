/*

*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_HEIGHT 987654321

using namespace std;

int N, S;

vector<vector<int>> picture(300000, vector<int>(2, 0));
vector<vector<int>> dp(300000, vector<int>(2, 0));

int solve(int order, bool purchased, int height){
	if(dp[order][purchased])
		return dp[order][purchased];

	if(order == 0)
		if(purchased)
			return picture[0][1];
		else
			return 0;
	
	for(int i=order-1;i>=0;i--){
		if(height - picture[order-1][0] >= S){
			dp[order][purchased] = solve(i, 1, picture[i][0]);
			break;
		}
	}
			
	dp[order][purchased] = max(dp[order][purchased], solve(order-1, 0, height));

	if(purchased)
		dp[order][purchased] += picture[order][1];

	return dp[order][purchased];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> S;
	picture.resize(N, vector<int>(2,0));
	dp.resize(N, vector<int>(2,0));

	for(int i=0;i<N;i++)
		cin >> picture[i][0] >> picture[i][1];
	
	sort(picture.begin(), picture.end());

	cout << max(solve(N-1, 0, MAX_HEIGHT), solve(N-1, 1, MAX_HEIGHT)) << endl;

	for(int i=0;i<N;i++)
		cout << picture[i][0] << " " << picture[i][1] << " : " << dp[i][0] << " " << dp[i][1] << endl;
	return 0;
}
