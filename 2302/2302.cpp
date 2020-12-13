/*
	극장 좌석
	DP
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M, input;
int dp[41], vip[41];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(dp, 0, sizeof(dp));
	memset(vip, 0, sizeof(vip));
	
	cin >> N >> M;

	for(int i=0;i<M;i++){	
		cin >> input;
		vip[input] = 1;
	}

	dp[0] = dp[1] = 1;

	for(int i=2;i<=N;i++){
		if(vip[i] == 1 || vip[i-1] == 1)
			dp[i] = dp[i-1];
		else 
			dp[i] = dp[i-1] + dp[i-2];
	}

	cout << dp[N] << endl;

/*
	vector<int> v_ip;
	v_ip.push_back(0);

	for(int i=0;i<M;i++){
		cin >> input;
		v_ip.push_back(input);
	}

	vector<int>::iterator it = v_ip.begin()+1;
	dp[0] = dp[1] = 1;
	for(int i=2;i<=N;i++){
		dp[i] = dp[i-1] + dp[i-2];
		if(it == v_ip.end())
			continue;
		if(i == *it){
			dp[i] -= dp[i-2];
			it++;
		} else if(i == (*it)-1){
			dp[i] -= dp[i-2];
		}
	}
*/
}
