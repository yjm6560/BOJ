/*
	줄 세우기
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

	int N;
	cin >> N;

	vector<int> children(N, 0), dp(N, 1);
	
	for(int i=0;i<N;i++)
		cin >> children[i];
	
	for(int i=0;i<N;i++)
		for(int j=i-1;j>=0;j--)
			if(children[i] > children[j])
				dp[i] = max(dp[i], dp[j] + 1);

	cout << N - *max_element(dp.begin(), dp.end()) << "\n";

	return 0;
}
