/*
	토마토(3차원)
	BFS
	난이도 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int answer = 0;
	int M, N, H;
	cin >> M >> N >> H;

	vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M, 0)));
	queue<tuple<int, int, int>> q;
	int dx[6] = {-1, 1, 0, 0, 0, 0};
	int dy[6] = {0, 0, -1, 1, 0, 0};
	int dz[6] = {0, 0, 0, 0, -1, 1};
	
	//입력
	for(int i=0;i<H;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<M;k++){
				cin >> box[i][j][k];
				if(box[i][j][k] == 1)
					q.push({i, j, k});
			}
		}
	}
	//BFS 시작
	while(!q.empty()){
		int z = get<0>(q.front());
		int x = get<1>(q.front());
		int y = get<2>(q.front());
		q.pop();

		for(int i=0;i<6;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if(nx<0 || nx>=N || ny<0 || ny>=M || nz<0 || nz>=H)
				continue;
			if(box[nz][nx][ny] != 0)
				continue;
			box[nz][nx][ny] = box[z][x][y] + 1;
			q.push({nz, nx, ny});
		}
	}

	//다 익을 수 없는 경우 체크, 토마토가 익는 데 걸리는 최대 시간 찾기
	for(int i=0;i<H;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<M;k++){	
				if(box[i][j][k] == 0){
					cout << "-1\n";
					return 0;
				}
				answer = max(answer, box[i][j][k]);
			}
		}
	}
	
	//1부터 셌으니까 -1 해서 출력
	cout << answer - 1 << "\n";

	return 0;
}

