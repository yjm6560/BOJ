/*	
	가장 긴 감소하는 부분 수열
	DP
	난이도
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
	
	int N, answer = 1;
	cin >> N;
	vector<int> nums(N);
	vector<int> dp(N, 1);

	for(int i=0;i<N;i++)
		cin >> nums[i];
	
	for(int i=1;i<N;i++){
		for(int j=0;j<i;j++){
			if(nums[i] < nums[j]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		answer = max(answer, dp[i]);
	}
	cout << answer << endl;
}
