/*
	자동차 공장
	BFS,DFS
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

char cmd;
int N, M, parent, a, x, pay[500001], diff[500001];
vector<vector<int>> relation;
bool updated = false;

int dfs(int a){
	int ret = 0;
	for(auto c : relation[a]){
		ret += dfs(c) + diff[c];
	}
	pay[a] += ret;
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	cin >> pay[1];
	for(int i=0;i<=N;i++){
		vector<int> child;
		relation.push_back(child);
	}
	for(int i=2;i<=N;i++){
		cin >> pay[i] >> parent;
		relation[i].push_back(parent);
	}
	for(int i=0;i<M;i++){
		cin >> cmd;
		if(cmd == 'p'){
			cin >> a >> x;
			diff[a] +=x;
			updated = true;
		} else if(cmd == 'u'){
			cin >> a;
			cout << pay[a] + (updated? dfs(a) : 0) << "\n";
			if(updated)
				memset(diff, 0, sizeof(diff));
			updated = false;
		}
	}
}
