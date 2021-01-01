#include <iostream>
#include <vector>
#include <algorithm>

#define PAPER_SIZE 10
#define PAPER_KIND_SIZE 5
#define PAPER_MAX_NUM 5

using namespace std;

vector<vector<int>> board(PAPER_SIZE, vector<int>(PAPER_SIZE, 0));

bool check(int x, int y, int p_size, int val = 0){
	for(int i=0;i<p_size;i++)
		for(int j=0;j<p_size;j++)
			if(board[x+i][y+j] == val)
				return false;
	return true;
}

void setBoard(int x, int y, int p_size, int val){
	for(int i=0;i<p_size;i++)
		for(int j=0;j<p_size;j++)
			board[x+i][y+j] = val;
}

int solve(int p_size, int cnt){
	if(cnt > PAPER_MAX_NUM)
		return 0;
	for(int p=p_size;p>0;p--){
		for(int i=0;i<PAPER_SIZE - p;i++){
			for(int j=0;j<PAPER_SIZE - p;j++){
				if(!check(i, j, p))
					continue;
				setBoard(i, j, p, 0);
				answer += solve(p, cnt+1);
				setBoard(i, j, p, 1);
			}
		}
	}
}
/*	
int solve(int p_size){
	int answer = 0;
	for(int i=0;i<=PAPER_SIZE - p_size;i++){
		for(int j=0;j<=PAPER_SIZE - p_size && answer<=PAPER_MAX_NUM;j++){
			if(!board[i][j])
				continue;
			if(!check(i, j, p_size))
				continue;	

			for(int a=0;a<p_size;a++)
				for(int b=0;b<p_size;b++)
					board[i+a][j+b] = 0;
			answer++;
		}
	}
	return answer;
}
*/
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int answer = 0;

	for(int i=0;i<PAPER_SIZE;i++)
		for(int j=0;j<PAPER_SIZE;j++)
			cin >> board[i][j];

	for(int i=PAPER_KIND_SIZE;i>0;i--)
		answer += solve(i);
	
	if(!check(0, 0, 10, 1))
		answer = -1;

	cout << answer << "\n";

	return 0;
}
