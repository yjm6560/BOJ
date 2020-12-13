/*
	반복수열
	그래프
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

int A, P, visited[500000];

int dfs(int e, int cnt){
	if(visited[e]){
		return visited[e]-1;
	}
	visited[e] = cnt;

	int next = 0;
	for(int digit=1;e/digit != 0;digit*=10)
		next += pow((e%(digit*10))/digit, P);
	return dfs(next, cnt+1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(visited, 0, sizeof(visited));

	cin >> A >> P;
	cout << dfs(A, 1) << "\n";
}
