/*
	달이 차오른다, 가자.
	BFS
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <limits.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define IS_KEY(x) (x >= 'a' && x <= 'f')
#define IS_DOOR(x) (x >= 'A' && x <= 'F')
#define GET_KEY(x) (x-'A')
#define GET_DOOR(x) (x-'a')

int N, M, dp[51][51][65];
char miro[51][51];
int dx[4] = { -1, 1, 0, 0,};
int dy[4] = { 0, 0, -1, 1 };

const int INF = INT_MAX;

int bfs(int beg_x, int beg_y, int key_set, int init_val){
	queue<pair<int, int>> q;
	int ret = INF;
	
	dp[beg_x][beg_y][key_set] = init_val;
	q.push({beg_x, beg_y});

	while(!q.empty()){
		int x = q.front().F;
		int y = q.front().S;
		q.pop();
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx<1 || nx>N || ny<1 || ny>M)
				continue;
			if(miro[nx][ny] == '#')
				continue;
			if(IS_DOOR(miro[nx][ny]) && !(key_set & 1<<GET_KEY(miro[nx][ny]))){
				continue;
			}
			if(dp[nx][ny][key_set] <= dp[x][y][key_set] + 1)
				continue;
			dp[nx][ny][key_set] = dp[x][y][key_set] + 1;
			if(IS_KEY(miro[nx][ny]) && !(key_set & 1<<GET_DOOR(miro[nx][ny]))){
				if(dp[nx][ny][key_set|(1<<GET_DOOR(miro[nx][ny]))] < dp[nx][ny][key_set]){

				}
				ret = min(ret, bfs(nx, ny, (key_set | 1<<GET_DOOR(miro[nx][ny])), dp[nx][ny][key_set]));
			}
			if(miro[nx][ny] == '1'){
				return min(ret, dp[nx][ny][key_set]);
			}
			q.push({nx, ny});
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin >> miro[i][j];
			for(int k=0;k<=64;k++){
				dp[i][j][k] = INF;
			}
		}
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(miro[i][j] == '0'){
				int result = bfs(i, j, 0, 0);
				cout << (result == INF? -1: result) << endl;
				break;
			}
		}
	}
}
