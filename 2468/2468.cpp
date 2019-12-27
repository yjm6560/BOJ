#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int map[101][101];
bool check_map[101][101];
int N, depth, max_region, tmp_max;

void dfs(int x, int y){
	if(x < 1 || x > N || y < 1 || y > N || map[x][y] <= depth)
		return;
	if(check_map[x][y] == true)
		return;
	check_map[x][y] = true;
	dfs(x-1, y);
	dfs(x+1, y);
	dfs(x, y-1);
	dfs(x, y+1);
	
}
int main()
{
	int max_depth = 0;
	cin >> N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%d", &map[i][j]);
			if(max_depth < map[i][j]) max_depth = map[i][j];
		}
	}
	max_region = 0;
	for(int i=1;i<=max_depth;i++){
		if(max_region >  ((N*N)/2 + 1)) break;
		for(int j=1;j<=N;j++)
			for(int k=1;k<=N;k++)
				check_map[j][k] = false;
		depth = i;
		tmp_max = 0;
		for(int j=1;j<=N;j++){
			for(int k=1;k<=N;k++){
				if(check_map[j][k] == true || map[j][k] <= depth)
					continue;
				tmp_max++;
				dfs(j, k);
			}
		}
		if(max_region < tmp_max)
			max_region = tmp_max;
	}
	printf("%d\n", max_region);
}
