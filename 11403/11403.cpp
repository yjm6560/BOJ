#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<vector<int>> board(N, vector<int>(N, 0));
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> board[i][j];
	
	for(int k=0;k<N;k++)
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				board[i][j] |= board[i][k] & board[k][j];

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
