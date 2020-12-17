#include <iostream>
#include <vector>
#include <algorithm>

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
	vector<vector<int>> town(MAXTOWN + 1, vector<int>(MAXTOWN + 1, MAXCOST));

	for(int i=1;i<=M;i++){
		cin >> s >> e >> cost;
		town[s][e] = cost;
	}
	cout << "INIT TOWN\n";
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout << (town[i][j]==MAXCOST? 0 : town[i][j]) << " ";
		}
		cout << endl;
	}
	for(int k=1;k<=30;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(i!=j && j!=k && i!=k)
					town[i][j] = min(town[i][j], town[i][k] + town[k][j]); 
			}
		}
	}
	cout << "AFTER TOWN\n";
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout << (town[i][j]==MAXCOST? 0 : town[i][j]) << " ";
		}
		cout << endl;
	}
	for(int i=1;i<=N;i++)
		if(i != X)
			answer = max(answer, town[i][X] + town[X][i]);
	cout << answer << "\n";

	return 0;
}
