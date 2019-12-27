#include <iostream>
#include <limits.h>

using namespace std;

unsigned int N, row[501], col[501], MatDP[501][501];

int main()
{
	cin >> N;
	for(int i=1;i<=N;i++){
		scanf("%d %d", &row[i], &col[i]);
		for(int j=1;j<=N;j++)
			MatDP[i][j] = 0;
	}
	int d, x, mid;
	for(d=1;d<=N-1;d++){
		for(x=1;x+d<=N;x++){
			int y = x+d;
			MatDP[x][y] = INT_MAX;
			for(mid=x;mid<x+d;mid++){
				MatDP[x][y] = min(MatDP[x][y], MatDP[x][mid] + MatDP[mid+1][y] + row[x]*col[mid]*col[y]);
			}
		}
	}
	cout << MatDP[1][N] << endl;
	for(int i=1;i<=N;i++){
	for(int j=1;j<=N;j++) if(j<i) printf("      "); else printf("%5d ", MatDP[i][j]);
	cout << endl;
	}
}
