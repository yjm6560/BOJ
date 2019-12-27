#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>

using namespace std;

int map[101][101];
int check[101][101];
queue< pair<int, int> > bfs_queue;
queue< pair<int, int> > bfs_sub_queue;
int N, M;
void bfs(){
	bfs_queue.push(pair<int, int>(1, 1));
	bfs_queue.push(pair<int, int>(0, 0));
	bfs_queue.push(pair<int, int>(0, 0));
	bfs_queue.push(pair<int, int>(0, 0));
	
	bfs_sub_queue.push(pair<int, int>(0, 0));
	bfs_sub_queue.push(pair<int, int>(0, 0));
	bfs_sub_queue.push(pair<int, int>(0, 0));
	bfs_sub_queue.push(pair<int, int>(0, 0));

	int x, y, bef_x, bef_y;

	while(bfs_queue.empty() == false){
		x = bfs_queue.front().first;
		y = bfs_queue.front().second;
		bef_x = bfs_sub_queue.front().first;
		bef_y = bfs_sub_queue.front().second;

		bfs_queue.pop();
		bfs_sub_queue.pop();
		
		if(x<1 || x>N || y<1 || y>M ||map[x][y] == 0) continue;
		if(check[x][y] > 0) continue;
		check[x][y] = check[bef_x][bef_y] + 1;

		bfs_queue.push(pair<int, int>(x-1, y));
		bfs_queue.push(pair<int, int>(x, y-1));
		bfs_queue.push(pair<int, int>(x, y+1));
		bfs_queue.push(pair<int, int>(x+1, y));

		bfs_sub_queue.push(pair<int, int>(x, y));
		bfs_sub_queue.push(pair<int, int>(x, y)); 
		bfs_sub_queue.push(pair<int, int>(x, y)); 
		bfs_sub_queue.push(pair<int, int>(x, y)); 
	}
}
int main()
{
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			scanf("%1d", &map[i][j]);
			check[i][j] = 0;
		}
	}
	bfs();
	printf("%d\n", check[N][M]);
}
