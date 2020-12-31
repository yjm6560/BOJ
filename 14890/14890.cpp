#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isBridgePossible(vector<int> road, int idx, int L, int N){
	if(idx + L > N)
		return false;
	for(int i=idx+1;i<idx+L+1;i++){
		if(road[idx+1] != road[i])
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, L, answer = 0;
	cin >> N >> L;
	vector<vector<int>> road(N*2, vector<int>(N));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> road[i][j];
			road[N+j][i] = road[i][j];
		}
	}
	/*
	for(int i=0;i<2*N;i++)
		for(int j=0;j<N;j++)
			cout << i << ", " << j << " : " << road[i][j] << endl;
	*/
	for(int i=0;i<2*N;i++){
		bool check = true;
		int bef = 1;
		cout << i << " : ";
		for(int j=0;j<N-1;j++){
			if(road[i][j] == road[i][j + 1]){
				bef++;
			} else if(road[i][j] == road[i][j + 1] + 1){
				if(isBridgePossible(road[i], j, L, N)){
					j += L - 1;
					bef = 0;
				} else {
					cout << "down false" << j;
					check = false;
					break;
				}
			} else if(road[i][j] + 1 == road[i][j + 1]){
				if(bef >= L){
					bef = 1;
				} else {
					cout << "up false";
					check = false;
					break;
				}
			} else {
				cout << "gap false";
				check = false;
				break;
			}
		}
		cout << endl;
		if(check){
			cout << i << endl;
			answer++;
		}
	}
	cout << answer << endl;
	return 0;
}
