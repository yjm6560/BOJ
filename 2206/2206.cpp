/*
	벽 부수고 이동하기
	DFS, BFS
*/

#include <iostream>
#include <stack>
#include <string.h>
#include <limits.h>
#include <algorithm>

using namespace std;

#define F first
#define S second
#define is_broken(pos) (pos.F != -1 || pos.S != -1)
#define MAX_VAL INT_MAX

int N, M, dist[1001][1001][2], wall[1001][1001];

void movewall(int x, int y, int broken, int val){
//	cout << "(" << x << ", " << y << ") " << wall[x][y] << " : " << broken << " dist : " << dist[x][y] << " ";
	if(wall[x][y] && broken){
//		cout << "wall[x][y] && broken\n";
		return;
	}
	dist[x][y][broken] = val;
//	cout << "PASS\n";
	if((x>1 && dist[x-1][y][broken] > dist[x][y][broken]+1) && broken+wall[x-1][y] < 2){
		movewall(x-1, y, broken+wall[x][y], dist[x][y][broken]+1);
	}
	if((x<N && dist[x+1][y][broken] > dist[x][y][broken]+1) && broken+wall[x+1][y] < 2){
		movewall(x+1, y, broken + wall[x][y], dist[x][y][broken]+1);
	}
	if((y>1 && dist[x][y-1][broken] > dist[x][y][broken]+1) && broken+wall[x][y-1] < 2){
		movewall(x, y-1, broken + wall[x][y], dist[x][y][broken]+1);
	}
	if((y<M && dist[x][y+1][broken] > dist[x][y][broken]+1) && broken+wall[x][y+1] < 2){
		movewall(x, y+1, broken + wall[x][y], dist[x][y][broken]+1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	char c;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin >> c;
			wall[i][j] = c-'0';
			dist[i][j][0] = MAX_VAL;
			dist[i][j][1] = MAX_VAL;
		}
	}
	movewall(1,1,0,1);
	cout << ((min(dist[N][M][0], dist[N][M][1])==MAX_VAL)? -1:min(dist[N][M][0], dist[N][M][1])) << endl;
/*
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cout << wall[i][j] << " ";
//			cout << (dist[i][j]==MAX_VAL? -1:dist[i][j]) << " ";
		}
		cout << endl;
	}
*/
}
