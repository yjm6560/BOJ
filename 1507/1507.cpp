/*
	궁금한 민호
	그리디, 플로이드 와샬, 그래프 이론
*/
#include <iostream>
#include <string.h>

using namespace std;

int N, ret = 0, dist[20][20], answer[20][20], board[20][20];
const int INF = 987654321;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> dist[i][j];
			board[i][j] = dist[i][j];
		}
	}

	for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(i==j || i==k || j==k)
					continue;
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					cout << "-1\n";
					return 0;
				}
				if(dist[i][j] == dist[i][k] + dist[k][j]){
					board[i][j] = 0;
				}
			}
		}
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			ret += board[i][j];
	cout << ret/2 << endl;
}
