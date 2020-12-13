/*
	
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int mySolution(int n, vector<int> &dp){
	static int INF = 987654321;
	if(dp[n] != INF)
		return dp[n];
	if(n == 1)
		return 1;
	if(n%3 == 0){
		dp[n] = min(dp[n], mySolution(n/3, dp) + 1);
	}
	if(n%2 == 0){
		dp[n] = min(dp[n], mySolution(n/2, dp) + 1);
	}
	dp[n] = min(dp[n], mySolution(n-1, dp) + 1);
	return dp[n];
}

int solution(int N){
	int answer = 0;
	int INF = 987654321;
	vector<int> dp(N+1, INF);
	dp[1] = 0;
// top down solution
	answer = mySolution(N, dp);
// bottom up solution
	/*
	for(int i=1;i<N;i++){
		dp[i+1] = min(dp[i+1], dp[i] + 1);
		if(i*3 <= N) dp[i*3] = min(dp[i*3], dp[i] + 1);
		if(i*2 <= N) dp[i*2] = min(dp[i*2], dp[i] + 1);
	}
	answer = dp[N];
	*/
	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	cout << solution(N) << endl;
}
