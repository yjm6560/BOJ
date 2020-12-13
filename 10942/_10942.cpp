/*
	DP
	palindrome
*/

#include <iostream>

using namespace std;

int N, M, palin[2001], S, E;
bool p_dp[2001][2001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> palin[i];
		p_dp[i][i] = p_dp[i][i-1] = 1;
	}
	cin >> M;

	for(int i=2;i<=N;i++){
		for(int j=1;j<i;j++){
			p_dp[j][i] = (palin[j] == palin[i] && p_dp[j+1][i-1])? 1 : 0;
		}
	}

	for(int i=0;i<M;i++){
		cin >> S >> E;
		cout << p_dp[S][E] << "\n";
	}
}
