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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string A = "", B = ""; 
	cin >> A >> B;
	
	vector<vector<int>> dp(MAX, vector<int>(MAX, 0));

	//길이 구하기
	for(int i=1;i<=A.length();i++){
		for(int j=1;j<=B.length();j++){
			if(A[i-1] == B[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout << dp[A.length()][B.length()] << endl;
	
	//경로 찾아가기
	string answer = "";
	
	int x = A.length();
	int y = B.length();
	
	while(dp[x][y]>0){
		if(dp[x][y] == dp[x-1][y]){
			x--;
		} else if(dp[x][y] == dp[x][y-1]){
			y--;
		} else {
			answer = A[x-1] + answer;
			x--;
			y--;
		}
	}
	cout << answer << endl;
	return 0;
}
