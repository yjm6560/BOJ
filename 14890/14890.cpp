#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool bridgeCheck(vector<int> road, int s, int length){
	if(s+length >= road.size())
		return false;
	for(int i=s+1;i<s+length;i++)
		if(road[i] != road[i-1])
			return false;
	return true;
}

bool isStraight(vector<int> road){
	for(int i=1;i<road.size();i++)
		if(road[i] != road[i-1])
			return false;
	return true;
}
bool isGapOver(vector<int> road){
	for(int i=1;i<road.size();i++)
		if(abs(road[i]-road[i-1]) > 1)
			return false;
	return true;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, L, answer = 0;
	cin >> N >> L;
	vector<vector<int>> road(N, vector<int>(N));
	vector<bool> rows(N, true);
	vector<bool> cols(N, true);

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> road[i][j];
	
	for(int r=0;r<N;r++){
		/*
		1. 높이 비교
		2-1. 차이 안 나면 continue
		2-2. 1 넘게 차이나면 false
		2-3. 1 차이나면 다음 L만큼 높이 비교
		3-1. L만큼 못 가면(중간에 높이 변경, 길이 짧음) false
		3-2. L만큼 가면 c 업데이트
		*/
		if(isStraight(road[r]))
			continue;
		if(!isGapOver(road[r])){
			rows[r] = false;
			continue;
		}
		vector<bool> check(N, false);
		for(int c=1;c<N;c++){
			if(road[r][c] == road[r][c-1] + 1){
				if(c+L > N || check[c]){
					rows[r] = false;
					break;
				}
				if(!isBridge(road[r], c, L)){
					rows[r] = false;
					break;
				}
				for(int i=c;i<c+L;i++){
					check[c] = true;
				}
				c += L - 1;
			}
		}
	}
	for(int i=0;i<N;i++)
		if(rows[i])
			cout << i << endl;
			

	return 0;
}
