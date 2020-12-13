/*
	알파벳
	DFS, BFS
*/

#include <iostream>
#include <string.h>
#include <set>

using namespace std;

#define INF 987654321

int R, C;
char board[20][20];
int visited [20][20];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
set<char> path;

int dfs(int x, int y, int s){
	int ret = 0;
	for(int i=0;i<4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		int ns = s|(1<<(board[nx][ny] - 'A'));

		if(nx<0 || nx>=R || ny<0 || ny>=C)
			continue;
		if(s&(board[nx][ny]-'A'))
			continue;
//		if(path.count(board[nx][ny]))
//			continue;
//		if(visited[nx][ny] > visited[x][y] + 1)
//			break;
//		path.insert(board[nx][ny]);
		if(ns&(!visited[nx][ny]) > 0){
			visited[x][y] = max(visited[x][y], dfs(nx, ny, ns));
		}
//		path.erase(path.find(board[nx][ny]));
	}
	return visited[x][y];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;

	memset(visited, 0, sizeof(visited));

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin >> board[i][j];
//			visited[i][j] = INF;
		}
	}
//	visited[0][0] = 1;
//	path.insert(board[0][0]);
	cout << dfs(0, 0, 1<<(board[0][0] - 'A')) << endl;
}
