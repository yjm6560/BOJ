/*
	교환
	BFS, ?
*/
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int input, k;
int visited[10][1000001];

int bfs(int num, int n, int cnt){
	if(visited[cnt][num] != INF)
		return num;
	queue<pair<int, int>> q;
	string s = to_string(num);
	char max_val = '0';
	int ret = 0;
	for(int i=n;i<s.length();i++){
		max_val = max(max_val, s[i]);
	}
	for(int i=0;i<s.length();i++){
		if(max_val == s[i]){
			string tmp = s;
			tmp[n] = s[i];
			tmp[i] = s[n];
			q.push({atoi(tmp.c_str()),(n==i? cnt : cnt+1)});
		}
	}
	while(!q.empty()){
		int nnum = q.front().first;
		int ncnt = q.front().second;
		q.pop();
		if(
		ret = max(ret, bfs(nnum, n+1, ncnt));	
	}
}

int main()
{
	cin >> input >> k;
	for(int i=0;i<10;i++)
		for(int j=0;j<=1000000;j++)
			visited[i][j] = INF;
	visited[0][input] = 0;
	cout << bfs(input, 0, 0) << endl;
}
