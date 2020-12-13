/*
	나이트의 이동
	BFS
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;

	vector<int> dx = {-2, -1, 1, 2, 2, 1, -1, -2};
	vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};

	while(T--){
		int N;
		cin >> N;
		pair<int, int> src, dst;
		cin >> src.first >> src.second >> dst.first >> dst.second;
		//cout << src.first << ", " << src.second << " - > " << dst.first << ", " << dst.second << endl;
		vector<vector<int>> dp(N, vector<int>(N, 0));
		queue<pair<int, int>> q;
		q.push(src);
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			//cout << x << ", " << y << " : " << dp[x][y] << endl;
			q.pop();
			if(x==dst.first && y==dst.second){
				cout << dp[x][y] << "\n";
				break;
			} else {
				for(int i=0;i<dx.size();i++){
					int nx = x + dx[i];
					int ny = y + dy[i];
	
					if(nx<0 || nx>=N || ny<0 || ny>=N)
						continue;
					if(!dp[nx][ny]){
						dp[nx][ny] = dp[x][y] + 1;
						q.push({nx, ny});
					}
				}
			}
		}
	}

	return 0;
}
