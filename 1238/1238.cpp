#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <queue>

#define MAXTOWN 1000
#define MAXCOST 1000000

using namespace std;

vector<int> solve(int N, int X, vector<vector<int>> adj){
	vector<int> dist(N+1, MAXCOST);
	vector<bool> visited(N+1, false);
	priority_queue<pair<int, int>> pq;
	
	dist[X] = 0;
	pq.push({0, X});

	while(!pq.empty()){
		int a = pq.top().second;
		pq.pop();
		if(visited[a])
			continue;
		visited[a] = true;
		for(int i=1;i<=N;i++){
			if(adj[a][i] == 0)
				continue;
			if(dist[a] + adj[a][i] < dist[i]){
				dist[i] = dist[a] + adj[a][i];
				pq.push({-dist[i], i});
			}
		}
	}
	return dist;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, X;
	int s, e, cost;
	int answer = 0;
	cin >> N >> M >> X;
	
	vector<vector<int>> adjToX(N+1, vector<int>(N+1, 0));
	vector<vector<int>> adjFromX(N+1, vector<int>(N+1, 0));
	for(int i=1;i<=M;i++){
		cin >> s >> e >> cost;
		adjToX[s][e] = cost;
		adjFromX[e][s] = cost;
	}
	
	vector<int> distToX = solve(N, X, adjToX);
	vector<int> distFromX = solve(N, X, adjFromX);
	
	for(int i=1;i<=N;i++)
		answer = max(answer, distToX[i] + distFromX[i]);
	
	cout << answer << endl;

	return 0;
}
