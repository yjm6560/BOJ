/*
	Puyo Puyo
	시뮬레이션
	난이도 2

	1. find4Items
	2. if return value of find4Items >= 4 change board
		2-1. remove items
		2-2. pull above items to down
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

#define N 12
#define M  6
using namespace std;

vector<string> board(N);
int visited[N][M];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int find4Items(int x, int y){
	visited[x][y] = 1;
	for(int i=0;i<4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx>=0 && nx<N && ny>=0 && ny<M 
				&& board[x][y]==board[nx][ny]
				&& !visited[nx][ny]){
			visited[x][y] += find4Items(nx, ny);
		}
	}
	return visited[x][y];
}

void remove(int x, int y){
	visited[x][y] = 1;
	for(int i=0;i<4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx>=0 && nx<N && ny>=0 && ny<M 
				&& board[x][y]==board[nx][ny]
				&& !visited[nx][ny]){
			remove(nx, ny);
		}
	}
}

int solve(){
	bool check = true;
	int answer = -1;
	int cnt = 3;
	while(check){
		memset(visited, 0, sizeof(visited));
		vector<pair<int, int>> removeList;
		check = false;
		answer++;
		// find 4 sequenced items
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(board[i][j] != '.' && !visited[i][j]){
					if(find4Items(i, j) >= 4){
						removeList.push_back({i, j});
						check = true;
					}
				}
			}
		}

		// change the board
		// simpleDateFormat java
		memset(visited, 0, sizeof(visited));
		for(auto pos : removeList){
			remove(pos.first, pos.second);
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(visited[i][j]){
					for(int k=i;k>0;k--){
						board[k][j] = board[k-1][j];
					}
					board[0][j] = '.';
				}
			}
		}
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<N;i++)
		cin >> board[i];
	cout << solve() << endl;
}
