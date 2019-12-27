#include <iostream>

using namespace std;

int T, K, fs[501][501], fs_sub[501][501];

int funct(int x, int y){
	if(fs[x][y] != -1) return fs[x][y];
	int i, j, tmp1, tmp2, tmpSum, fs_sub_min, fs_min = -1;
	for(i = x+1; i<= K-y+1; i++){
		tmp1 = funct(i, y);
		tmp2 = funct(x, K-i+2);
		tmpSum = tmp1 + tmp2 + (y == K-i+1 ? 0 : fs_sub[i][y]) + (x == i-1 ? 0 : fs_sub[x][K-i+2]);
		if(fs_min == -1 || fs_min > tmpSum){
			fs_min = tmpSum;
			fs_sub_min = fs_sub[i][y] + fs_sub[x][K-i+2];
		}
	}
	fs[x][y] = fs_min;
	fs_sub[x][y] = fs_sub_min;
	return fs[x][y];
}
int main()
{
	cin >> T;
	while(T--){
		cin >> K;
		for(int i=1;i<=K;i++)
			for(int j=1;j<=K;j++)
				fs[i][j] = -1;
		for(int i=1;i<=K;i++){
			scanf("%d", &fs[i][K-i+1]);
			fs_sub[i][K-i+1] = fs[i][K-i+1];
		}
		cout << funct(1,1) << endl;
	}
}
