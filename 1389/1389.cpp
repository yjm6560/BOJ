/*
	케빈 베이컨의 6단계 법칙
	DFS, BFS, 플로이드 와샬
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

#define PB push_back
#define F first
#define S second

int N, M, inputX, inputY, cnt = 0, calvin[101][101];
//vector<pair<pair<int, int>, int>> calvin;
const int INF = 987654321;

int main()
{
	cin >> N >> M;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			calvin[i][j] = INF;

	for(int i=0;i<M;i++){
		cin >> inputX >> inputY;
		calvin[inputX][inputY] = calvin[inputY][inputX] = 1;
//		calvin.PB({{inputX, inputY}, 1});
	}
/*
	for(int i=0;i<M;i++){
		cout << calvin[i].F.F << ", " << calvin[i].F.S << ", " << calvin[i].S << endl;
	}
*/
	while(cnt < 10){
		bool changed = false;
		for(int i=1;i<=N;i++){
			for(int j=1;j<N;j++){
				if(i == j)
					continue;
				for(int k=1;k<=N;k++){
					if(i == k || j == k)
						continue;
					if(calvin[i][j] > calvin[i][k] + calvin[k][j]){
						calvin[i][j] = calvin[i][k] + calvin[k][j];
						calvin[j][i] = calvin[i][j];
						changed = true;
					}
				}
			}
		}
		if(changed)
			cnt = 0;
		else
			cnt++;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout << (calvin[i][j] == INF? -1 : calvin[i][j]) << " ";
		}
		cout << endl;
	}
	int ret = 1;
	for(int i=1;i<=N;i++){
		calvin[i][0] = 0;
		for(int j=1;j<=N;j++){
			calvin[i][0] += calvin[i][j];
		}
		if(calvin[ret][0] > calvin[i][0])
			ret = i;
	}
	cout << ret << endl;
}
