/*
	숨바꼭질
	플로이드 와샬, 다익스트라, 최단 경로, 그래프 이론
*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

//int N, M, x, y, cnt = 0, answer = 1, farm[20001][20001];
int N, M, x, y, cnt = 0, answer = 1, dist[20001];
vector<int> adj[20001];
priority_queue<pair<int, int>> q;
bool processed[20001];
const int INF = 987654321;

int main()
{
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	//다익스트라 풀이
	for(int i=1;i<=M;i++){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=1;i<=N;i++){
		dist[i] = INF;
		processed[i] = false;
	}

	dist[1] = 0;
	q.push({0, 1});

	while(!q.empty()){
		int a = q.top().second;
		q.pop();
		if(processed[a])
			continue;
		processed[a] = true;
		for(auto b : adj[a]){
			if(dist[a] + 1 < dist[b]){
				dist[b] = dist[a] + 1;
				q.push({-dist[b], b});
			}
		}
	}

	for(int i=1;i<=N;i++){
		if(dist[answer] < dist[i]){
			answer = i;
			cnt = 1;
		} else if(dist[answer] == dist[i]){
			cnt++;
		}
	}
	cout << answer << " " << dist[answer] << " " << cnt << endl;


	//플로이드 와샬 풀이(메모리 초과)
/*
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			farm[i][j] = INF;
		}
	}
	for(int i=1;i<=M;i++){
		cin >> x >> y;
		farm[x][y] = farm[y][x] = 1;
	}
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(!(i==j || i==k || j==k))
					farm[i][j] = min(farm[i][j], farm[i][k] + farm[k][j]);
			}
		}
	}

	for(int i=1;i<=N;i++){
		farm[i][i] = 0;
		if(farm[1][answer] < farm[1][i]){
			answer = i;
			cnt = 1;
		} else if(farm[1][answer] == farm[1][i]){
			cnt++;
		}
	}
	cout << answer << " " << farm[1][answer] << " " << cnt << endl;
*/
}
