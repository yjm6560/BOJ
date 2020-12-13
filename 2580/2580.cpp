/*
	스도쿠
	백트래킹
	난이도 2
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#define getSquareIdx(x, y) ((x-1)/3*3 + (y-1)/3)
using namespace std;

int board[10][10];
bool row[10][10], col[10][10], square[10][10];
vector<pair<int, int>> hole;
bool check = false;

void solve(int idx){
	if(check)
		return;
	if(idx == hole.size()){
		for(int i=1;i<10;i++){
			for(int j=1;j<10;j++){
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
		check = true;
		return;
	}
	int x = hole[idx].first;
	int y = hole[idx].second;

	for(int i=1;i<10;i++){
		if(row[x][i] || col[y][i] || square[getSquareIdx(x, y)][i]){
			continue;
		}
		board[x][y] = i;
		row[x][i] = col[y][i] = square[getSquareIdx(x, y)][i] = true;
		solve(idx+1);
		row[x][i] = col[y][i] = square[getSquareIdx(x, y)][i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(square, 0, sizeof(square));

	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			cin >> board[i][j];
			if(board[i][j]){
				row[i][board[i][j]] = true;
				col[j][board[i][j]] = true;
				square[getSquareIdx(i,j)][board[i][j]] = true;
			} else {
				row[i][board[i][j]] = false;
				col[j][board[i][j]] = false;
				square[getSquareIdx(i,j)][board[i][j]] = false;
				hole.push_back({i, j});
			}
		}
	}
	solve(0);
}
