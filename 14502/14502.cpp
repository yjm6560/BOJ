#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	vector<int> dx = {-1, 1, 0, 0};
	vector<int> dy = {0, 0, -1, 1};

	int N, M, answer = 0, walls = 3;
	cin >> N >> M;
	
	vector<vector<int>> lab(N, vector<int>(M, 0));
	vector<pair<int, int>> virus;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> lab[i][j];
			if(lab[i][j] == 2){
				virus.push_back({i, j});
			} else if(lab[i][j] == 1){
				walls++;
			}
		}
	}
	for(int i=0;i<N*M;i++){
		if(lab[i/M][i%M] != 0)
			continue;
		for(int j=i+1;j<N*M;j++){
			if(lab[j/M][j%M] != 0)
				continue;
			for(int k=j+1;k<N*M;k++){
				if(i==j || j==k || i==k || lab[k/M][k%M] != 0)
					continue;
				queue<pair<int, int>> q;
				vector<vector<bool>> visited(N, vector<bool>(M, false));
				visited[i/M][i%M] = true;
				visited[j/M][j%M] = true;
				visited[k/M][k%M] = true;
				for(auto v: virus)
					q.push(v);
				//바이러스 감염된 애들 구하기
				int cnt = 0;
				while(!q.empty()){
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					cnt++;
					for(int d=0;d<4;d++){
						int nx = x + dx[d];
						int ny = y + dy[d];
				
						if(nx<0 || nx>=N || ny<0 || ny>=M)
							continue;
						if(lab[nx][ny]==0 && !visited[nx][ny]){
							visited[nx][ny] = true;
							q.push({nx, ny});
						}
					}
				}
				answer = max(answer, N*M - walls - cnt);
			}
		}
	}
	
	cout << answer << "\n";

	return 0;
}
