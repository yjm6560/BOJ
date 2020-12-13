/*
	롤러코스터
	그리디
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int R, C, rx, ry, minB=987654321, happy[1000][1000];
string path;

void append(string &s, char c, int cnt){
	for(int i=0;i<cnt;i++)
		s += c;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;

	memset(happy, 0, sizeof(happy));

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin >> happy[i][j];
			if((i+j)%2 && minB > happy[i][j]){
				rx = i;
				ry = j;
				minB = happy[i][j];
			}
		}
	}
	if(R%2 == 1){
		for(int i=0;i<R;i++){
			if(i%2 == 0){
				append(path, 'R', C-1);
				if(i != R-1)
					append(path, 'D', 1);
			} else {
				append(path, 'L', C-1);
				append(path, 'D', 1);
			}
		}
	} else if(C%2 == 1){
		for(int i=0;i<C;i++){
			if(i%2 == 0){
				append(path, 'D', R-1);
				if(i != C-1)
					append(path, 'R', 1);
			} else {
				append(path, 'U', R-1);
				append(path, 'R', 1);
			}
		}
	} else {
		int check = 0;
		if(rx == 0){
			for(int j=0;j<C-1;j++){
				if(j == ry){
					append(path, 'R', 1);
					check = 1;
				} else if(j%2 == check){
					append(path, 'D', 1);
					append(path, 'R', 1);
				} else {
					append(path, 'U', 1);
					append(path, 'R', 1);
				}
			}
			if(R > 2 && ry != C-1)
				append(path, 'D', 1);
			for(int i=2;i<R;i++){
				append(path, 'D', 1);
				if(i%2 == 0){
					append(path, 'L', C-1);
				} else {
					append(path, 'R', C-1);
				}
			}
		}

		else {
			int newR = rx%2 == 0? rx : rx-1;
			for(int i=0;i<newR;i++){
				if(i%2 == 0){
					append(path, 'R', C-1);
				} else {
					append(path, 'L', C-1);
				}
				append(path, 'D', 1);
			}
			for(int j=0;j<C-1;j++){
				if(j == ry){
					append(path, 'R', 1);
					check = 1;
				} else if(j%2 == check){
					append(path, 'D', 1);
					append(path, 'R', 1);
				} else {
					append(path, 'U', 1);
					append(path, 'R', 1);
				}
			}
			append(path, 'D', 1);
			for(int i=newR+2;i<R;i++){
				append(path, 'D', 1);
				if(i%2 == 0){
					append(path, 'L', C-1);
				} else {
					append(path, 'R', C-1);
				}
			}
		}
	}
	cout << path << endl;
}
