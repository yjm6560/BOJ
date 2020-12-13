/*
	트리의 지름
	트리
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, parent, child, cost, answer = 0;
vector<pair<int, int>> tree[10001];

int solve(int node){
	if(tree[node].size() == 0)
		return 0;
	vector<int> costList;

	for(auto next : tree[node]){
		costList.push_back(solve(next.first) + next.second);
	}
	sort(costList.begin(), costList.end());
	int size = costList.size();
	if(size >= 2){
		answer = max(answer, costList[size - 1] + costList[size - 2]);
	} else {
		answer = max(answer, costList[size - 1]);
	}
	return costList[costList.size()-1];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for(int i=2;i<=N;i++){
		cin >> parent >> child >> cost;
		tree[parent].push_back({child, cost});
	}
	solve(1);
	cout << answer << endl;
}
