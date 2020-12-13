/*
	색칠 공부
	DFS, 그래프 이론
*/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

long long N, K, ret = 1, board[1000001], comb[1000001];
bool visited[1000001];
const long long MOD = 1000000007;

long long dfs(long long idx){
	long long next = board[idx];
	if(visited[next] || idx == next)
		return ;
	if(comb[next] != MOD){
		comb[idx]--;
	} else {
		comb[next] = comb[idx] - 1;
		return dfs(next);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> K;
	for(long long i=1;i<=N;i++){
		cin >> board[i];
		comb[i] = MOD;
	}
	for(long long i=1;i<=N;i++){
		if(comb[i] == MOD){
			memset(visited, 0, sizeof(visited));
			comb[i] = K;
			visited[i] = true;
			dfs(i);
		}
	}
	for(long long i=1;i<=N;i++){
		cout << comb[i] << " ";
		if(comb[i] <= 0){
			cout << "\n0\n";
			return 0;
		}
		ret = (ret * comb[i])%MOD;
	}
	cout << "\n" << ret << endl;
}
