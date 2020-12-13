#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef unsigned long long ull;

vector<pair<int, int>> path;
vector<vector<ull>> dp(101, vector<ull>(2, 0));

ull solution(int beg, int mid, int end, int N){
	if(N == 1){
		path.push_back({beg, end});
		return 1;
	}
	ull answer = solution(beg, end, mid, N-1);
	path.push_back({beg, end});
	answer += solution(mid, beg, end, N-1);
	return answer + 1;
}
vector<ull> solution20(int N){
	if(dp[N][0] > 0 || dp[N][1] > 0)
		return dp[N];
	dp[N][0] = 0;
	dp[N][1] = 1;
	if(N == 1)
		return dp[N];
	dp[N] = solution20(N-1);
	dp[N][0] = dp[N][0]*2;
	if(dp[N][1] & ((ull)1 << 63)){
		dp[N][0] += 1;
	}
	dp[N][1] = (dp[N][1]*2) + 1;
	return dp[N];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	if(N <= 20){
		cout << solution(1, 2, 3, N) << "\n";
		for(auto p : path)
			cout << p.first << " " << p.second << "\n";
	}
	else {
		vector<ull> answer = solution20(N);
		if(answer[0] != 0){
			cout << answer[0];
			vector<int> tmp(20, 0);
			for(int i=0;i<20;i++){

			}
		cout << answer[1] << "\n";
	}
}
