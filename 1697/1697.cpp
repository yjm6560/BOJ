#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;

int start, dest, dist;
int map[100001];

queue<int> bfs_queue;
queue<int> befSpot_queue;
void bfs(int s, int d){
	int bef_move = 0;
	bfs_queue.push(s);
	befSpot_queue.push(s);
	while(!bfs_queue.empty()){
		
		int spot = bfs_queue.front();
		int bef_spot = befSpot_queue.front();
		bfs_queue.pop();
		befSpot_queue.pop();
		if(spot == dest){
			map[spot] = map[bef_spot] + 1;
			return;
		}
		if(spot < 0 || spot > 100000 || map[spot] > 0)
			continue;
		map[spot] = map[bef_spot]+1;
		if(bef_move == -1){
			bfs_queue.push(spot-1);
			bfs_queue.push(spot*2);

			befSpot_queue.push(spot);
			befSpot_queue.push(spot); 
		} else if(bef_move == 1){
			bfs_queue.push(spot+1);
			bfs_queue.push(spot*2);

			befSpot_queue.push(spot); 
			befSpot_queue.push(spot); 

		} else {
			bfs_queue.push(spot-1);
			bfs_queue.push(spot+1); 
			bfs_queue.push(spot*2); 

			befSpot_queue.push(spot); 
			befSpot_queue.push(spot); 
			befSpot_queue.push(spot); 
		}
	}
}
int main()
{
	for(int i=0;i<100001;i++)
		map[i] = -1;
	cin >> start >> dest;
	dist = dest - start;
	if(dist < 0)
		map[dest] = -1 * dist;
	else
		bfs(start, dest);
	printf("%d\n", map[dest]);
}	
