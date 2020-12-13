/*
   토마토
   DFS, BFS
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second

int M, N, max_val = 0;
int tomato[1001][1001], dp[1001][1001];
queue<pair<int, int>> q;

void bfs(){
	while(!q.empty()){
		int a = q.front().F;
		int b = q.front().S;
		q.pop();
		if(a>1 && tomato[a-1][b]==0){
			if(dp[a-1][b] == 0){
				q.push({a-1,b});
				dp[a-1][b] = dp[a][b]+1;
			} 
		}
		if(a<M && tomato[a+1][b]==0){
			if(dp[a+1][b] == 0){
				q.push({a+1,b});
				dp[a+1][b] = dp[a][b]+1;
			}
		} 
		if(b>1 && tomato[a][b-1]==0){
			if(dp[a][b-1] == 0){
				q.push({a,b-1});
				dp[a][b-1] = dp[a][b]+1;
			}
		} 
		if(b<N && tomato[a][b+1]==0){
			if(dp[a][b+1] == 0){
				q.push({a,b+1});
				dp[a][b+1] = dp[a][b]+1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int zero_cnt = 0;
	REP(i,1,M) REP(j,1,N){ 
		cin >> tomato[i][j]; 
		dp[i][j] = tomato[i][j]; 
		if(tomato[i][j] == 1){
			q.push({i,j});
		}
		else if(tomato[i][j] == 0)
			zero_cnt++;
	}
	if(zero_cnt == 0){
		cout << "0\n";
	} else {
		bfs();
		REP(i,1,M){
			REP(j,1,N){
				if(dp[i][j] == 0){
					cout << "-1\n";
					return 0;
				}
				max_val = max(max_val, dp[i][j]);
			}
		}
		cout << max_val-1 << endl;
	}
}
