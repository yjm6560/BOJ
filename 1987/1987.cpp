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
int visited [27];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y, int cnt){
		
	int ret = cnt;
		    
	for(int i=0;i<4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx<0 || nx>=R || ny<0 || ny>=C)
			continue;
		if(visited[board[nx][ny] - 'A'])
			continue;
		visited[board[nx][ny] - 'A'] = true;
		ret = max(ret, dfs(nx, ny, cnt+1));
		visited[board[nx][ny] - 'A'] = false;
	}
	return ret;
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
		}
	}

	visited[board[0][0] - 'A'] = true;
	cout << dfs(0, 0, 1) << endl;
}

