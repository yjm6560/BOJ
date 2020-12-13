/*
   구슬 찾기
   DFS
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

#define MID ((N+1)/2)

int N, M, ret = 0, input1, input2;//, order[2][100]; 
vector<int> graph[2][100];
bool visited[2][100];

int dfs(int idx, int w){
	int result = 1;
	for(auto x : graph[w][idx]){
		if(visited[w][x])
			continue;
		visited[w][x] = true;
		result += dfs(x, w);
	}
	return result;	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;

	for(int i=0;i<M;i++){
		cin >> input1 >> input2;
		graph[0][input1].push_back(input2);
		graph[1][input2].push_back(input1);
	}
	for(int i=1;i<=N;i++){
		memset(visited, 0, sizeof(visited));
		if(dfs(i,0)>MID || dfs(i,1)>MID)
			ret++;
	}
	cout << ret << endl;
}
