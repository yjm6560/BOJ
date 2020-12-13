/*
	전시장
	DP
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, S;
	cin >> N >> S;
	
	vector<pair<int, int>> picture(N+1, {0, 0});
	vector<int> dp(N+1, 0), bef(N+1, 0);

	for(int i=1;i<=N;i++){
		cin >> picture[i].first >> picture[i].second;
	}

	sort(picture.begin(), picture.end());

	for(int i=1;i<=N;i++){
		for(bef[i]=bef[i-1];bef[i]<i;bef[i]++){
			if(picture[i].first-picture[bef[i]].first < S) {
				break;
			}
		}
		bef[i]--;
	}

	for(int i=1;i<=N;i++)
		dp[i] = max(dp[i-1], dp[bef[i]] + picture[i].second);
	
	cout << dp[N] << "\n";

	return 0;
}
