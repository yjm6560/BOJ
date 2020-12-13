/*
	결혼식
	그래프
*/
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, s, d, cnt = 0;
	vector<int> adj[500];
	bool visited[500];
	memset(visited, 0, sizeof(visited));

	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> s >> d;
		adj[s-1].push_back(d-1);
		adj[d-1].push_back(s-1);
	}
	visited[0] = true;
	for(auto f : adj[0]){
		if(!visited[f]){
			visited[f] = true;
			cnt++;
		}
		for(auto s : adj[f]){
			if(!visited[s]){
				visited[s] = true;
				cnt++;
			}
		}		
	}
	cout << cnt << endl;
}
