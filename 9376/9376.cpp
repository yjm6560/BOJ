/*
	탈옥
	BFS
*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define REP(i,a,b) for(int i=a;i<=b;i++)
#define PB push_back
#define F first
#define S second
#define INF 987654 

int main()
{
	int N, H, W, dp[105][105][3];
	char map[105][105];
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	cin >> N;

	while(N--){
		memset(map, '.', sizeof(map));
		memset(dp, INF, sizeof(dp));
		vector<pair<int, int>> prisoner;
		prisoner.PB({0,0});
		
		cin >> H >> W;
	
		REP(i,1,H){
			REP(j,1,W){
				cin >> map[i][j];
				if(map[i][j] == '$'){
					prisoner.PB({i,j});
					map[i][j] = '.';
				}
			}
		}
		REP(i,0,2){
			queue<pair<int, int>> q;
			q.push(prisoner[i]);
			dp[prisoner[i].F][prisoner[i].S][i] = 0;
			while(!q.empty()){
				int x = q.front().F;
				int y = q.front().S;
				q.pop();

				REP(j,0,3){
					int nx = x + dx[j];
					int ny = y + dy[j];
					
					if(nx<0 || nx>H+1 || ny<0 || ny>W+1)
						continue;
					if(map[nx][ny] == '*')
						continue;
					if(map[nx][ny] == '#' && dp[nx][ny][i] > dp[x][y][i]+1){
						dp[nx][ny][i] = min(dp[x][y][i] + 1, dp[nx][ny][i]);
						q.push({nx, ny});
					} else if(map[nx][ny] == '.' && dp[nx][ny][i] > dp[x][y][i]){
						dp[nx][ny][i] = dp[x][y][i];
						q.push({nx, ny});
					}
				}
			}
		}
		int ret = INF;
		REP(i,0,H+1){
			REP(j,0,W+1){
				ret = min(ret, dp[i][j][0]+dp[i][j][1]+dp[i][j][2]+(map[i][j]=='#'? -2:0));
			}
		}
		cout << ret << endl;
		REP(k,0,2){
			cout << k <<"st\n";
			REP(i,0,H+1){
				REP(j,0,W+1){
					cout << (dp[i][j][k] > 100000? -1:dp[i][j][k]) << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

	}
}
		/*
		   REP(i,0,H+1){
			REP(j,0,W+1){
				cout << map[i][j];
			}
			cout << endl;
		}
		*/

