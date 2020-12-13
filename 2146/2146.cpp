/*
	다리 만들기
	DFS, BFS
*/
#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define RANGE(x, y) (x>=0 && x<N && y>=0 && y<N)
#define F first
#define S second
#define INF 987654321

int N, ret = INF, dp[103][103], region[103][103];
bool map[103][103];
queue<pair<int, int>> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void divideRegion(int num){
	while(!q.empty()){
		int x = q.front().F;
		int y = q.front().S;
		q.pop();

		REP(i,0,4){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(!RANGE(nx, ny))
				continue;
			if(map[nx][ny] && region[nx][ny] == 0){
				region[nx][ny] = num;
				q.push({nx, ny});
			}
		}
	}
}

int bfs(int beg_x, int beg_y, int nRegion){
	queue<pair<int, int>> bfs_q;
	bfs_q.push({beg_x, beg_y});

	while(!bfs_q.empty()){
		int x = bfs_q.front().F;
		int y = bfs_q.front().S;
		bfs_q.pop();
		
		if(ret < dp[x][y])
			return INF;
		if(map[x][y])
			return dp[x][y];
		
		REP(i,0,4){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(!RANGE(nx, ny))
				continue;
			if(region[nx][ny] == nRegion)
				continue;
			if(dp[nx][ny] < INF)
				continue;
			dp[nx][ny] = dp[x][y] + 1;
			bfs_q.push({nx, ny});
		}	
	}
	return INF;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	REP(i,0,N){
		REP(j,0,N){
			cin >> map[i][j];
		}
	}

	memset(region, 0, sizeof(region));
	int nRegion = 1;
	REP(i,0,N){
		REP(j,0,N){
			if(map[i][j] && region[i][j] == 0){
				q.push({i,j});
				region[i][j] = nRegion;
				divideRegion(nRegion++);
			}
		}
	}
	REP(i,0,N){
		REP(j,0,N){
			if(!map[i][j]){
				REP(k,0,4){
					int nx = i + dx[k];
					int ny = j + dy[k];
					if(RANGE(nx, ny) && map[nx][ny]){
						REP(l,0,N)
							REP(m,0,N)
								dp[l][m] = INF;
						dp[i][j] = 0;
						ret = min(ret, bfs(i, j, region[nx][ny]));
						break;
					}
				}
			}
		}
	}
	REP(i,0,N){
		REP(j,0,N){
			cout << region[i][j] << " ";
		}
		cout << endl;

	}
	cout << ret << endl;
}
