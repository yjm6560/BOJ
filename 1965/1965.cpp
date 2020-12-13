/*
	상자 넣기
	DP
	난이도 2
*/
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, box[1001], dp[1001], answer = 0;
	cin >> N;
	
	memset(dp, 0, sizeof(dp));
	memset(box, 0, sizeof(box));

	for(int i=1;i<=N;i++)
		cin >> box[i];

	for(int i=1;i<=N;i++){
		for(int j=0;j<i;j++){
			if(box[j] < box[i]){
				dp[i] = max(dp[i], dp[j]+1);  
			}
		}
		answer = max(answer, dp[i]);
	}
	cout << answer << "\n";
}
