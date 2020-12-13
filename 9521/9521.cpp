/*
	색칠 공부
	그래프 이론, DFS, DP
*/
#include <iostream>

using namespace std;

long long N, K, ret = 1, s, tot_cycle = 0, cycle_cnt, f[1000001], dp[1000001], visited[1000001] = {0}, first_visited[1000001] = {0};
const long long inf = 1000000007;

long long dfs(long long idx, long long cnt){
	if(visited[idx]){
		if(first_visited[idx] == s)
			return cnt - visited[idx];
		else
			return 0;
	}
	first_visited[idx] = s;
	visited[idx] = cnt;
	return dfs(f[idx], cnt+1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for(long long i=1;i<=N;i++)
		cin >> f[i];

	dp[0] = 1;
	dp[1] = K;
	dp[2] = (K*(K-1))%inf;
	dp[3] = (dp[2] * (K-2))%inf;
	for(long long i=4;i<=1000000;i++)
		dp[i] = ((dp[i-2] * (K-1)) + (dp[i-1] * (K-2)))%inf;

	for(long long i=1;i<=N;i++){
		if(!visited[i]){
			s = i;
//			first_visited[i] = s;
//			visited[i] = 1;
			cycle_cnt = dfs(s, 1);
//			if(cycle_cnt > 0)
			ret = (ret * dp[cycle_cnt])%inf;
			tot_cycle += cycle_cnt;
			cout << cycle_cnt << endl;
		}
	}

	for(long long i=1;i<=(N-tot_cycle);i++)
		ret = (ret * (K-1))%inf;

	cout << ret << endl;
}
