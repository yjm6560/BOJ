/* 
   거울 설치 
   BFS 
*/ 
#include <iostream> 
#include <queue> 
#include <vector> 

using namespace std; 

#define F first 
#define S second 
const int INF = 987654321; 
int N, dp[50][50][4]; 
char house[50][50]; 
//direction : u l r d 
int dx[4] = {-1, 0, 0, 1}; 
int dy[4] = {0, -1, 1, 0}; 
queue<int> q; 
vector<pair<int, int>> door; 

int main() 
{ 
	cin >> N; 
	for(int i=0;i<N;i++){ 
		for(int j=0;j<N;j++){ 
			cin >> house[i][j]; 
			if(house[i][j] == '#'){ 
				door.push_back({i, j}); 
			} 
			for(int k=0;k<4;k++) 
				dp[i][j][k] = INF; 
		} 
	} 
	for(int i=0;i<4;i++){ 
		dp[door[0].F][door[0].S][i] = 0;
		q.push(door[0].F); q.push(door[0].S); q.push(i);
	}

	while(!q.empty()){
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
		int direct = q.front(); q.pop();
/*		if(x == door[1].F && y == door[1].S){
			cout << dp[x][y][direct] << endl;
			break;
		}
*/		
		int nx = x + dx[direct];
		int ny = y + dy[direct];

		if(nx<0 || nx>=N || ny<0 || ny>=N)
			continue;
		if(house[nx][ny] == '*')
			continue;

		for(int i=0;i<4;i++){
			if(dp[nx][ny][i] <= dp[x][y][direct])
				continue;
			if(house[nx][ny] == '!' || i == direct){
				if(3-direct == i)
					continue;
				q.push(nx); q.push(ny); q.push(i);
				dp[nx][ny][i] = (i == direct? dp[x][y][direct] : dp[x][y][direct] + 1);
			}
		}
	}
	int ret = INF;
	for(int i=0;i<4;i++)
		ret = min(ret, dp[door[1].F][door[1].S][i]);
	cout << ret << endl;
	for(int k=0;k<4;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout << (dp[i][j][k] == INF? 0 : dp[i][j][k]) << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
} 
