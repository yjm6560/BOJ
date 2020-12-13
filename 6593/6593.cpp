/*
	상범 빌딩
	BFS
*/
#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define MAX 30
#define REP(i,a,b) for(int i=a;i<b;i++)

int L, R, C, dp[MAX][MAX][MAX];
char building[MAX][MAX][MAX];
const int INF = 987654321;
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while(true){
		cin >> L >> R >> C;
		if(L==0 && R==0 && C==0)
			break;

		queue<int> q;
		bool check = false;

		REP(i,0,L){
			REP(j,0,R){
				REP(k,0,C){
					cin >> building[i][j][k];
					dp[i][j][k] = INF;
					if(building[i][j][k] == 'S'){
						q.push(i);q.push(j);q.push(k);
						dp[i][j][k] = 0;
					}
				}
			}
		}
		while(!q.empty()){
			int x = q.front(); q.pop();
			int y = q.front(); q.pop();
			int z = q.front(); q.pop();
			if(building[x][y][z] == 'E'){
				cout << "Escaped in " << dp[x][y][z] << " minute(s)\n";
				check = true;
				break;
			}
			REP(i,0,6){
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];

				if(nx<0 || nx>=L || ny<0 || ny>=R || nz<0 || nz>=C)
					continue;
				if(dp[nx][ny][nz] < INF)
					continue;
				if(building[nx][ny][nz] == '#')
					continue;
				dp[nx][ny][nz] = dp[x][y][z] + 1;
				q.push(nx); q.push(ny); q.push(nz);
			}
		}
		if(!check)
			cout << "Trapped!\n";
	}
}
