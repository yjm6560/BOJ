#include <iostream>

using namespace std;

int M, N, arr[501][501], dp[501][501];

int funct(int x, int y){
	if(dp[x][y] == -1){
	dp[x][y]++;
	if(x-1>=1 && arr[x-1][y] > arr[x][y]) { dp[x][y] += funct(x-1, y); }
	if(x+1<=M && arr[x+1][y] > arr[x][y]) { dp[x][y] += funct(x+1, y); }
	if(y-1>=1 && arr[x][y-1] > arr[x][y]) { dp[x][y] += funct(x, y-1); }
	if(y+1<=N && arr[x][y+1] > arr[x][y]) { dp[x][y] += funct(x, y+1); }
	}
	return dp[x][y];
}
int main()
{
	cin >> M >> N;
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
	dp[1][1] = 1;
	funct(M, N);
	cout << dp[M][N] << endl;
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			printf("%3d ", dp[i][j]);
		}
		cout << endl;
	}
}
