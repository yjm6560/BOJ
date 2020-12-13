/*
	Gaaaaaaaaaarden
	BFS
*/
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, G, R, board[50][50], dp[50][50], answer = 0;
vector<pair<int, int>> cand;

int bfs(){
	memset(dp, 0, sizeof(dp));
	queue<pair<int, int>> q;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> G >> R;

	memset(board, 0, sizeof(board));

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> board[i][j];
			if(board[i][j] == 2)
				cand.push_back({i, j});
		}
	}
	answer = max(answer, bfs());
	
}
