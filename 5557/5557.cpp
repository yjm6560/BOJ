/*
	1학년
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
	
	const int maxSum = 20;
	int N;
	cin >> N;

	vector<int> nums(N);

	for(int i=0;i<N;i++)
		cin >> nums[i];

	vector<vector<long long>> DP(21, vector<long long>(N, 0));
	
	DP[nums[0]][0] = 1;

	for(int i=1;i<N-1;i++){
		for(int j=0;j<=maxSum;j++){
			if(j-nums[i] >= 0)
				DP[j][i] += DP[j-nums[i]][i-1];
			if(j+nums[i] <= maxSum)
				DP[j][i] += DP[j+nums[i]][i-1];
				/*
			if(j+nums[i+1] <= maxSum) 
				DP[j+nums[i+1]][i+1] += DP[j][i];
			if(j-nums[i+1] >= 0) 
				DP[j-nums[i+1]][i+1] += DP[j][i];
				*/
		}
	}

	cout << DP[nums[N-1]][N-2] << "\n";

	return 0;
}
