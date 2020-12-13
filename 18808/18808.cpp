/*
	스티커 붙이기
	구현?
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M, K, notebook[100][100], sticker[10][10], cnt = 0;

bool paste(int r, int c){
	for(int i=0;i<=N-r;i++){
		for(int j=0;j<=M-c;j++){
			bool check = true;
			for(int x=0;x<r;x++){
				if(check == false)
					break;
				for(int y=0;y<c;y++){
					if(sticker[x][y] && notebook[i+x][j+y]){
						check = false;
						break;
					}
				}
			}
			if(check){
				for(int x=0;x<r;x++){
					for(int y=0;y<c;y++){
						notebook[i+x][j+y] |= sticker[x][y];
					}
				}
				return true;
			}
		}
	}
	return false;
}

void turn(int r, int c){
	int tmp[10][10];
	memset(tmp, 0, sizeof(tmp));
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			tmp[i][j] = sticker[i][j];
		}
	}
	memset(sticker,0,sizeof(sticker));
	for(int i=0;i<c;i++){
		for(int j=0;j<r;j++){
			sticker[i][j] = tmp[r-j-1][i];
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	memset(notebook, 0, sizeof(notebook));
	while(K--){	
		int r, c;
		cin >> r >> c;
		memset(sticker, 0, sizeof(sticker));
	
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin >> sticker[i][j];
			}
		}
		for(int i=0;i<4;i++){
			int nr = (i%2 == 0? r : c);
			int nc = (i%2 == 0? c : r);
			//보드 돌면서 체크
			if(paste(nr, nc))
				break;
			//회전
			turn(nr, nc);
		}


	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(notebook[i][j])
				cnt++;
		}
	}
	cout << cnt << endl;
}
