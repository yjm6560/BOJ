/*
	미로 탈출하기
	알고리즘
	난이도
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, answer = 0;
vector<string> board(500);
vector<vector<int>> escaped(500, vector<int>(500, 0));
vector<vector<bool>> visited(500, vector<bool>(500, false));

int solution(int x, int y){
	if(escaped[x][y] != 0)
		return escaped[x][y];
	if(visited[x][y]){
		escaped[x][y] = -1;
		visited[x][y] = true;
		return escaped[x][y];
	}
	visited[x][y] = true;
	pair<int, int> dir;
	if(board[x][y]=='U') dir = {-1, 0};
	else if(board[x][y]=='R') dir = {0, 1};
	else if(board[x][y]=='D') dir = {1, 0};
	else dir = {0, -1};
	
	int nx = x + dir.first;
	int ny = y + dir.second;
	if(nx<0 || nx==N || ny<0 || ny==M){
		escaped[x][y] = true;
	} else {
		escaped[x][y] = solution(x+dir.first, y+dir.second);
	}
	return escaped[x][y];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	
	for(int i=0;i<N;i++)
		cin >> board[i];
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(escaped[i][j]==0){
				solution(i, j);
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(escaped[i][j] == 1)
				answer++;
		}
	}
	cout << answer << endl;
}
