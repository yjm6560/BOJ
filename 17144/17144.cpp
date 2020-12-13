/*
	미세먼지 안녕!
	그래프
*/
#include <iostream>
#include <vector>

using namespace std;

#define rREP(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define SPREAD 5

int R, C, T, room[51][51][1001], sum=0;
vector<int> ac;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> R >> C >> T;
	REP(i,1,R){
		REP(j,1,C){
			cin >> room[i][j][0];
			if(room[i][j][0] == -1)
				ac.push_back(i);
		}
	}
	REP(w,0,T-1){
		//micro dust spread
		REP(x,1,R){
			REP(y,1,C){
				int tmp = room[x][y][w]/SPREAD;
				REP(k,0,3){
					int nx = x + dx[k], ny = y + dy[k];
					if(nx<1 || nx>R || ny<1 || ny>C)
						continue;
					if(room[nx][ny][w] == -1)
						continue;
					room[nx][ny][w+1] += tmp;
					room[x][y][w] -= tmp;
				}
				room[x][y][w+1] += room[x][y][w];
			}
		}

		//air cleaning top
		rREP(i,ac[0]-1,2) room[i][1][w+1] = room[i-1][1][w+1]; //top-left
		REP(i,1,C-1) room[1][i][w+1] = room[1][i+1][w+1]; //top-top
		REP(i,1,ac[0]-1) room[i][C][w+1] = room[i+1][C][w+1]; //top-right
		rREP(i,C,3)	room[ac[0]][i][w+1] = room[ac[0]][i-1][w+1]; //top-bottom

		//air cleaning bottom
		REP(i,ac[1]+1,R-1) room[i][1][w+1] = room[i+1][1][w+1]; //bottom-left
		REP(i,1,C-1) room[R][i][w+1] = room[R][i+1][w+1]; //bottom-bottom
		rREP(i,R,ac[1]+1) room[i][C][w+1] = room[i-1][C][w+1]; //bottom-right
		rREP(i,C,3)	room[ac[1]][i][w+1] = room[ac[1]][i-1][w+1]; //bottom-top
	
		room[ac[0]][2][w+1] = room[ac[1]][2][w+1] = 0;
		room[ac[0]][1][w+1] = room[ac[1]][1][w+1] = -1;
	}
	REP(i,1,R)
		REP(j,1,C)
			sum += room[i][j][T];
	cout << sum+2 << endl;
}
