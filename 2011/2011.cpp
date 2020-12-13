/*
	암호코드
	DP
*/
#include <iostream>
#include <string>

using namespace std;

#define MOD 1000000

int e[5001], dp[5001], N;
string input;

int decode(int idx){
	if(dp[idx] != -1)
		return dp[idx];

	if(e[idx] == 0){
		if(e[idx-1] != 1 && e[idx-1] != 2)
			dp[idx] = 0;
		else
			dp[idx] = decode(idx-2);
	} else if((e[idx-1] == 2 && e[idx] <= 6) || e[idx-1] == 1){
			dp[idx] = decode(idx-1) + decode(idx-2);
	} else {
		dp[idx] = decode(idx-1);
	}
	return dp[idx]%MOD;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> input;
	N = input.length();
	for(int i=0;i<N;i++){
		e[i+1] = input[i] - '0';
		dp[i+1] = -1;
	}
	e[0] = 0;
	dp[0] = 1;
	cout << decode(N) << endl;
}
