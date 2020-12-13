/*
	미로 탈출하기
	알고리즘
	난이도
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M, answer, group = 1;
vector<string> board(500);
vector<vector<int>> groupNums(500, vector<int>(500, 0));
vector<vector<int>> cycleCount(500, vector<int>(500, 1));
set<int> cycleGroupSet;

int solution(int x, int y){
	pair<int, int> dir;
	if(board[x][y]=='U') dir = {-1, 0};
	else if(board[x][y]=='R') dir = {0, 1};
	else if(board[x][y]=='D') dir = {1, 0};
	else dir = {0, -1};
	
	int nx = x + dir.first;
	int ny = y + dir.second;
	if(nx<0 || nx==N || ny<0 || ny==M){
		return 0;
	} else {
		if(groupNums[nx][ny] == group){
			cycleGroupSet.insert(group);
			return cycleCount[x][y];
		} else if(groupNums[nx][ny] != 0){
			if(cycleGroupSet.find(groupNums[nx][ny])!=cycleGroupSet.end())
				return cycleCount[x][y];
			else
				return 0;
		}
		groupNums[nx][ny] = group;
		cycleCount[nx][ny] = cycleCount[x][y] + 1;
		return solution(x+dir.first, y+dir.second);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	answer = N*M;
	for(int i=0;i<N;i++)
		cin >> board[i];
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(groupNums[i][j]==0){
				answer -= solution(i, j);
				group++;
			}
		}
	}
	cout << answer << endl;
}
