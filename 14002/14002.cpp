/*
	가장 긴 증가하는 부분 수열 4
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
	int N, max_idx, max_val = 0;
	cin >> N;
	vector<int> nums(N);
	vector<pair<int, int>> dp(N);
	vector<int> answer;

	for(int i=0;i<N;i++){
		cin >> nums[i];
		dp[i] = {1, i};
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<i;j++){
			if(nums[i]>nums[j] && dp[i].first<dp[j].first+1){
				dp[i].first = dp[j].first + 1;
				dp[i].second = j;
			}
		}
		if(max_val < dp[i].first){
			max_val = dp[i].first;
			max_idx = i;
		}
	}
	int pat = max_idx;
	while(pat != dp[pat].second){
		answer.push_back(nums[pat]);
		pat = dp[pat].second;
	}
	answer.push_back(nums[pat]);
	cout << max_val << "\n";
	for(int i=answer.size()-1;i>=0;i--)
		cout << answer[i] << " ";
	cout << "\n";
	return 0;
}
