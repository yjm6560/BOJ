#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100000

using namespace std;

vector<vector<int>> tree(MAX+1, vector<int>(0));
vector<int> parent(MAX+1, 0);

void solve(int node){
	for(auto child : tree[node]){
		if(parent[child] == 0){
			parent[child] = node;
			solve(child);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, a, b;
	cin >> N;
	
	for(int i=0;i<N;i++){
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	solve(1);
	
	for(int i=2;i<=N;i++)
		cout << parent[i] << "\n";

	return 0;
}
