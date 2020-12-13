/*
	토마토(3차원)
	BFS
*/
#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

int M, N, H, tomato[101][101][101], days[101][101][101], ret = 0;
queue<tuple<int, int, int>> q;

void bfs(){
	while(!q.empty()){
		int x = get<0>(q.front()); 
		int y = get<1>(q.front()); 
		int z = get<2>(q.front());
		q.pop();

		ret = max(ret, days[x][y][z]);
		
		if(x>1 && days[x-1][y][z] == 0){
			days[x-1][y][z] = days[x][y][z] + 1;
			q.push({x-1,y,z});
		}
		if(x<N && days[x+1][y][z] == 0){
			days[x+1][y][z] = days[x][y][z] + 1;
			q.push({x+1,y,z});
		}
		if(y>1 && days[x][y-1][z] == 0){
			days[x][y-1][z] = days[x][y][z] + 1;
			q.push({x,y-1,z});
		}
		if(y<M && days[x][y+1][z] == 0){
			days[x][y+1][z] = days[x][y][z] + 1;
			q.push({x,y+1,z});
		}
		if(z>1 && days[x][y][z-1] == 0){
			days[x][y][z-1] = days[x][y][z] + 1;
			q.push({x,y,z-1});
		}
		if(z<H && days[x][y][z+1] == 0){
			days[x][y][z+1] = days[x][y][z] + 1;
			q.push({x,y,z+1});
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int zero_cnt = 0;

	cin >> M >> N >> H;
	for(int k=1;k<=H;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=M;j++){
				cin >> tomato[i][j][k];
				days[i][j][k] = tomato[i][j][k];
				if(tomato[i][j][k] == 1)
					q.push({i,j,k});
				else if(tomato[i][j][k] == 0)
					zero_cnt++;
			}
		}
	}
	if(zero_cnt == 0){
		cout << 0 << endl;
		return 0;
	}
	
	bfs();

	for(int k=1;k<=H;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=M;j++){
				if(days[i][j][k] == 0){
					cout << "-1\n";
					return 0;
				}
			}
		}
	}

	cout << ret - 1 << endl;
}
