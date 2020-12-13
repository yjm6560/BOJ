/*
	축사 배정
	네트워크 플로우, 이분 매칭, 최대 유량
	난이도
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, answer=0;
vector<vector<int>> cows;
vector<int> manager;
vector<bool> visited;

bool solution(int idx){
	if(visited[idx])
		return false;
	visited[idx] = true;
	
	for(auto x : cows[idx]){
		if(!manager[x] || solution(x){
				answer++;
				manager[managerIdx] = x;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	cows.resize(N+1);
	manager.resize(M);
	visited.resize(M);
	fill(manager.begin(), manager.end(), 0);
	fill(visited.begin(), visited.end(), 0);

	for(int i=1;i<=N;i++){
		int cnt;
		cin >> cnt;
		cows[i].resize(cnt);
		for(int j=0;j<cnt;j++)
			cin >> cows[i][j];
	}
	solution(1);
	cout << answer << endl;
}
