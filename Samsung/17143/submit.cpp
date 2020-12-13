/*
	낚시왕
	그래프
	난이도
	상어 움직이기
	상어 잡아먹기
	상어 골라내기

*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct sharkPos {
	int r, c, s, d, z;
	bool isAlive;
	sharkPos(int R, int C, int S, int D, int Z, bool alive) : r(R), c(C), s(S), d(D), z(Z), isAlive(alive) {}

} sharkPos;

int R, C, M, sea[101][101], answer = 0;
vector<sharkPos> sharks;
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

void moveShark(){
	int tempMap[101][101];
	memset(tempMap, 0, sizeof(tempMap));

	for(int i=1;i<sharks.size();i++){
		if(!sharks[i].isAlive)
			continue;
		int nx = sharks[i].r, ny = sharks[i].c, s = sharks[i].s, d = sharks[i].d;
		while(true){
			nx += s*dx[d];
			ny += s*dy[d];

			if(nx>0 && nx<=R && ny>0 && ny<=C)
				break;
			if(d==1){
				s = (-1)*(nx-1); nx = 1; d = 2;
			}
			else if(d==2){
				s = nx-R; nx = R; d = 1;
			}
			else if(d==3){
				s = ny-C; ny = C; d = 4;
			}
			else if(d==4){
				s = (-1)*(ny-1); ny = 1; d = 3;
			}
		}
		sharks[i].r = nx;
		sharks[i].c = ny;
		sharks[i].d = d;
		if(sharks[tempMap[nx][ny]].z > sharks[i].z){
			sharks[i].isAlive = false;
		} else {
			sharks[tempMap[nx][ny]].isAlive = false;
			tempMap[nx][ny] = i;
		}
	}
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++)
			sea[i][j] = tempMap[i][j];
}
void fish(){
	for(int i=1;i<=C;i++){
		for(int j=1;j<=R;j++){
			if(sea[j][i]){
				sharks[sea[j][i]].isAlive = false;
				answer += sharks[sea[j][i]].z;
				sea[j][i] = 0;
				break;
			}
		}
		moveShark();
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int r, c, s, d, z;
	
	cin >> R >> C >> M;

	memset(sea, 0, sizeof(sea));
	sharks.push_back(sharkPos(0, 0, 0, 0, -1, false));
	for(int i=1;i<=M;i++){
		cin >> r >> c >> s >> d >> z;
		sharks.push_back(sharkPos(r, c, s, d, z, true));
		sea[r][c] = i;
	}

	fish();
	cout << answer << endl;
}
