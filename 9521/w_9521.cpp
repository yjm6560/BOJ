/*
	색칠 공부
	DFS
*/
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

long long N, K, f[1000001];
const int MOD = 1000000007;
bool visited[1000001];

long long dfs(long long now, long long val){
	visited[now] = true;
	if(val == 0)
		return 0;
	if(now == f[now])
		return val;
	return (val * (visited[f[now]] ? 1 : dfs(f[now], val - 1)))%MOD;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for(int i=1;i<=N;i++)
		cin >> f[i];

	memset(visited, 0, sizeof(visited));
	long long result = 1;
	for(long long i=1;i<=N;i++)
		if(!visited[i])
			result = (result * dfs(i, K))%MOD;
	cout << result % MOD << endl;
}
