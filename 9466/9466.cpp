/*
	텀 프로젝트
	그래프, 사이클, DFS, BFS
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, student[100001], c_cnt[100001], c_group[100001];

int dfs(int cur, int group, int cnt){
	if(c_group[cur] == group){
		return (cnt - c_cnt[cur]);
	} else if(c_group[cur] != 0){
		return 0;
	}
	c_cnt[cur] = cnt;
	c_group[cur] = group;
	return dfs(student[cur], group, cnt+1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		memset(student, 0, sizeof(student));
		memset(c_cnt, 0, sizeof(c_cnt));
		memset(c_group, 0, sizeof(c_group));
		
		cin >> N;
		int answer = N, group = 1;
		for(int i=1;i<=N;i++)
			cin >> student[i];
		
		for(int i=1;i<=N;i++){
			if(c_group[i] == 0)
				answer -= dfs(i, group++, 1);
		}
		cout << answer << "\n";
	}
}
