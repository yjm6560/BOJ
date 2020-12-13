/*
	별찍기 - 11
	분할정복
*/
#include <iostream>
#include <string.h>

using namespace std;

int N;
bool board[3073][6146];

void funct(int x, int y, int cnt){
	if(cnt==3){
		board[x][y+2] = true;
		board[x+1][y+1] = board[x+1][y+3] = true;
		for(int i=0;i<5;i++)
			board[x+2][y+i] = true;
		return;
	}
	int newCnt = cnt/2;
	funct(x, y+newCnt, newCnt);
	funct(x+newCnt, y, newCnt);
	funct(x+newCnt, y+newCnt*2, newCnt);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(board, 0, sizeof(board));

	cin >> N;
	funct(1, 1, N);

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N*2;j++){
			cout << (board[i][j]? '*':' ');
		}
		cout << "\n";
	}
}
