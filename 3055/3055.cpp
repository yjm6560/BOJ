/*
   탈출
   BFS
*/
#include <iostream>
#include <queue>

using namespace std;

#define Fir first
#define Sec second

int R, C, dp[50][50], wdp[50][50];
char map[50][50], wmap[50][50];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
const int INF = 987654321;
queue<pair<int, int>> q, wq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin >> map[i][j];
			wmap[i][j] = map[i][j];
			dp[i][j] = wdp[i][j] = INF;
			if(map[i][j] == 'S'){
				q.push({i,j});
				dp[i][j] = 0;
			}
			if(map[i][j] == '*'){
				wq.push({i,j});
				wdp[i][j] = 0;
			}
		}
	}
	
	while(!wq.empty()){
		int x = wq.front().Fir;
		int y = wq.front().Sec;
		wq.pop();

		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx<0 || nx >= R || ny<0 || ny>=C)
				continue;
			if(wmap[nx][ny] == '*' || wmap[nx][ny] == 'X' || wmap[nx][ny] == 'D')
				continue;
			wmap[nx][ny] = '*';
			wdp[nx][ny] = wdp[x][y] + 1;
			wq.push({nx, ny});
		}
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout << wdp[i][j] << " ";
		}
		cout << endl;
	}

	while(!q.empty()){
		int x = q.front().Fir;
		int y = q.front().Sec;
		q.pop();
		if(map[x][y] == 'D'){
			cout << dp[x][y] << endl;
//			return 0;
		}
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx<0 || nx >= R || ny<0 || ny>=C)
				continue;
			if(map[nx][ny] == 'X')
				continue;
			if(dp[nx][ny] < INF)
				continue;
			if(dp[x][y] + 1 >= wdp[nx][ny])
				continue;
			dp[nx][ny] = dp[x][y] + 1;
			q.push({nx, ny});
		}
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "KAKTUS\n";
}
