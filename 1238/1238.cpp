#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <queue>

#define MAXTOWN 1000
#define MAXCOST 1000000

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, X;
	int s, e, cost;
	int answer = 0;
	cin >> N >> M >> X;

	vector<vector<int>> town(N+1, vector<int>(N+1, MAXCOST));
	vector<tuple<int, int, int>> dist;

	for(int i=1;i<=M;i++){
		cin >> s >> e >> cost;
		dist.push_back({s, e, cost});
	}
	for(int i=1;i<=N;i++){
		town[i][i] = 0;
		for(auto e : dist){
			town[i][get<1>(e)] = min(town[i][get<1>(e)], town[i][get<0>(e)] + get<2>(e));
		}
	}

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout << (town[i][j] == MAXCOST? 0 : town[i][j]) << " ";
		}
		cout << endl;
	}

	return 0;
}
