/*
	섬의 개수
	그래프, 그래프 이론, DFS, BFS?
*/

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int w, h;
bool board[50][50], visited[50][50];
queue<pair<int, int>> q;
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void bfs(int sx, int sy){
	q.push({sx, sy});
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i=0;i<8;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx<0 || nx>=h || ny<0 || ny>=w)
				continue;
			if(!board[nx][ny] || visited[nx][ny])
				continue;
			visited[nx][ny] = true;
			q.push({nx, ny});
		}
	}
}

int main()
{
	while(true)
	{
		cin >> w >> h;
		if(!w && !h)
			break;

		int cnt = 0;

		memset(visited, 0, sizeof(visited));
		memset(board, 0, sizeof(board));
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				cin >> board[i][j];
		
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(board[i][j] && !visited[i][j]){
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
/*		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cout << visited[i][j] << " ";
			}
			cout << endl;
		}
*/
	}
}
