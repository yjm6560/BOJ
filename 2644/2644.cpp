#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[101][101];
int chonsu_count[101][101];
int N, relation, beg, dest, max_count;

queue<int> bfs_queue;
queue<int> bef_queue;
queue<int> count_queue;
void bfs(){
	bfs_queue.push(beg);
	bef_queue.push(beg);
	count_queue.push(0);
	while(!bfs_queue.empty()){
		int chonsu = bfs_queue.front();
		int bef_count = bef_queue.front();
		int count = count_queue.front();
		bfs_queue.pop();
		bef_queue.pop();
		count_queue.pop();
		if(chonsu_count[bef_count][chonsu] > 0) continue;
		if(chonsu == dest){
			max_count = count;
			return;
		}
		chonsu_count[chonsu][bef_count] = chonsu_count[bef_count][chonsu] = count+1;
		for(int i=1;i<=N;i++){
			if(map[chonsu][i] == 1){
				bfs_queue.push(i);
				bef_queue.push(chonsu);
				count_queue.push(chonsu_count[chonsu][bef_count]);
			}
		}
	}
}
int main()
{
	cin >> N >> beg >> dest >> relation;
	for(int i=1;i<=relation;i++){
		int x, y;
		scanf("%d %d", &x, &y);
		map[x][y] = map[y][x] = 1;
	}
	bfs();
	if(beg == dest)
		printf("%d\n", 0);
	else
		printf("%d\n", max_count == 0 ? -1 : max_count);
}
