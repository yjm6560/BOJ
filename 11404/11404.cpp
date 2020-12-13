/*
	플로이드
	그래프 이론, 플로이드 와샬
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_C 100
#define MAX_B 100000
#define INF 987654321
#define REP(i,a,b) for(int i=a;i<=b;i++)

int N, M;
vector<int> adj[MAX_C];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	REP(i,0,N-1)
		REP(j,0,N-1)
			adj[i].push_back(INF);
	REP(i,1,M){
		int s, d, w;
		cin >> s >> d >> w;
		adj[s-1][d-1] = min(adj[s-1][d-1], w);
	}

	REP(k,0,N-1)
		REP(i,0,N-1)
			REP(j,0,N-1)
				if(i != j)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	REP(i,0,N-1){
		REP(j,0,N-1){
			cout << (adj[i][j] == INF? 0 : adj[i][j]) << " ";
		}
		cout << "\n";
	}
}
