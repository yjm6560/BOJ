/*
	보물섬
	BFS
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define ROW(x) (x/M)
#define COL(x) (x%M)
#define IDX(i,j) (i*M + j)

int N, M, ret = 0;
char island[50][50];
int dp[50][50];
queue<int> q;

void bfs(){
	while(!q.empty()){
		int x = ROW(q.front());
		int y = COL(q.front());
		q.pop();

		ret = max(ret, dp[x][y]);

		if((x>0 && island[x-1][y] == 'L') && dp[x-1][y] == 0){
			dp[x-1][y] = dp[x][y] + 1;
			q.push(IDX((x-1), y));
		}
		if((x<N-1 && island[x+1][y] == 'L') && dp[x+1][y] == 0){
			dp[x+1][y] = dp[x][y] + 1;
			q.push(IDX((x+1), y));
		}
		if((y>0 && island[x][y-1] == 'L') && dp[x][y-1] == 0){
			dp[x][y-1] = dp[x][y] + 1;
			q.push(IDX(x, (y-1)));
		}
		if((y<M-1 && island[x][y+1] == 'L') && dp[x][y+1] == 0){
			dp[x][y+1] = dp[x][y] + 1;
			q.push(IDX(x, (y+1)));
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	REP(i,0,N)
		REP(j,0,M)
			cin >> island[i][j];

	REP(i,0,N){
		REP(j,0,M){
			if(island[i][j] == 'L'){
				memset(dp, 0, sizeof(dp));
				dp[i][j] = 1;
				q.push(IDX(i,j));
				bfs();
			}
		}
	}
	cout << max(ret-1,0) << endl;
}
