/*
	뱀
	??
	난이도
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <deque>

#define nextDirection(d) (direction + 4 + ((d)=='L'?-1:1))%4

using namespace std;

int N, K, L, answer = 0, board[101][101];
int x = 1, y = 1, cur = 0, direction = 1;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool check = true;
deque<pair<int, int>> snake;

void solve(int sec) {
	for(int i=0;i<sec;i++){
		if(x==0||y==0||x>N||y>N || board[x][y] == 2){
			cout << "		END		\n";
			answer += i;
			check = false;
			return;
		}
		cout << i << "st   " << x << ", " << y << " snake size = " << snake.size() << "\n";

		
		int tail_x = snake.back().first;
		int tail_y = snake.back().second;
		
		if(board[x][y] != 1){
			snake.pop_back();
			board[tail_x][tail_y] = 0;
		}

		snake.push_front({x, y});
		board[x][y] = 2;
		x += dx[direction];
		y += dy[direction];
	}
	answer += sec;
	return;
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
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cin >> L;
	for(int i=0;i<L;i++){
		int s;
		char d;
		cin >> s >> d;
		cout << s << " " << d << endl;
		solve(s - cur);
		if(!check)
			break;
		cur = s;
		direction = nextDirection(d);
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				cout << board[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl;
	}
	if(check)
		solve(987654321);

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}	
	cout << "Answer : " << answer << endl;
}
