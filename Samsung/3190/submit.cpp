/*
	뱀
	그래프
	난이도 2.5
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <deque>

#define nextDirection(d) (direction + 4 + ((d)=='L'?-1:1))%4

using namespace std;

int N, K, L, answer = 0, board[10001][10001];
int x = 1, y = 1, cur = 0, direction = 1;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
deque<pair<int, int>> snake;

bool solve(int sec) {
	for(int i=0;i<sec;i++){
		if(x==0||y==0||x>N||y>N || board[x][y] == 2){
			answer += i;
			return false;
		}
		
		if(board[x][y] != 1){
			board[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}

		snake.push_front({x, y});
		board[x][y] = 2;
		x += dx[direction];
		y += dy[direction];
	}
	answer += sec;
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	snake.push_back({1, 1});
	cin >> N;
	cin >> K;
	memset(board, 0, sizeof(board));

	for(int i=0;i<K;i++){
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;
	}
	cin >> L;
	for(int i=0;i<L;i++){
		int s;
		char d;
		cin >> s >> d;
		if(!solve(s - cur)){
			cout << answer << "\n";
			return 0;
		}
		cur = s;
		direction = nextDirection(d);
	}
	solve(987654321);
	cout << answer << "\n";
}
