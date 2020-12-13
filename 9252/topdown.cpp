/*
	LCS 2
	DP
	난이도
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 1000

using namespace std;

string A = "", B = ""; 
vector<vector<int>> dp(MAX, vector<int>(MAX, -1));

int solve(int A_idx, int B_idx){
	if(A_idx == A.length() || B_idx == B.length())
		return 0;
	if(dp[A_idx][B_idx]>=0)
		return dp[A_idx][B_idx];
	for(int i=A_idx;i<A.length();i++){
		for(int j=B_idx;j<B.length();j++){
			if(A[i] == B[j]){
				dp[A_idx][B_idx] = max(dp[A_idx][B_idx], solve(i+1, j+1)+1);
			}
		}
	}
	return dp[A_idx][B_idx];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> A >> B;
	
	cout << solve(0, 0) << "\n";

	return 0;
}
