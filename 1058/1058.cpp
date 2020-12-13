/*
	친구
	그래프 이론
	난이도
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, answer = 0;
	const int INF = 987654321;
	char c;
	cin >> N;
	vector<vector<int>> relation(N, vector<int>(N, INF));

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> c;
			if(c=='Y')
				relation[i][j] = 1;
		}
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			for(int k=0;k<N;k++)
				if(i!=j && i!=k && j!=k)
					relation[i][j] = min(relation[i][j], (relation[i][k] + relation[k][j]));
	
	for(auto r : relation){
		int cnt = 0;
		for(auto f : r){
			if(f<=2)
				cnt++;
		}
		answer = max(answer, cnt);
	}
	cout << answer << endl;
}
