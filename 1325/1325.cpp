/*
	효율적인 해킹
	DFS, BFS
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

#define PB push_back
#define vi vector<int>
#define REP(i,a,b) for(int i=a;i<=b;i++)

int N, M, s, e, dp[100001];
bool visited[100001];
vector<vi> hack;

int dfs(int idx){
	visited[idx] = true;
	
	int tmp = 1;
	for(auto x : hack[idx])
		if(!visited[x])
			tmp += dfs(x);
	dp[idx] = max(dp[idx], tmp);
	return tmp;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, 0, sizeof(dp));
	
	cin >> N >> M;
	REP(i,0,N){
		vi tmp;
		hack.PB(tmp);
	}
	REP(i,1,M){
		cin >> s >> e;
		hack[e].PB(s);
	}

	REP(i,1,N){
		memset(visited, false, sizeof(visited));
		dfs(i);
	}
	int max_val = 0;
	REP(i,1,N)
		max_val = max(max_val, dp[i]);
	REP(i,1,N)
		if(dp[i]==max_val)
			cout << i << " ";
	cout << endl;
}
