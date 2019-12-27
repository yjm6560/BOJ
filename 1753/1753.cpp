#include <stdio.h>
#include <iostream>
#include <stack.h>
#include <vector.h>

using namespace std;

int weight_map[20001][20001];
int min_map[20001][20001];
int min_path[20001];
int E, V, min, dest, start;

void dfs(int x, int y, int cost){
	if(x < 1 || x > E || y < 1 || y > E || weight_map[x][y] < 1)
		return;
	if(min_map[x][y] > weight_map[x][y] + cost){
		min_map[x][y] = cost;
	}
	dfs(x-1, y, min_map[x][y]);
	dfs(x-1, y-1, min_map[x][y]);
	dfs(x, y+1, min_map[x][y]);
	dfs(x+1, y+1, min_map[x][y]);
	
}
int main()
{
	cin >> E >> V >> start;
	for(int i=0;i<V;i++){
		int x, y, weight;
		scanf("%d %d %d", &x, &y, &weight);
		weight_map[x][y] = weight;
	}
	for(int i=1;i<=E;i++){
		min = 0;
		dest = i;
		dfs(1, 1, 0);
	}
}
