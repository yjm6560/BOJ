/*
	박스 채우기
	그리디
	난이도 3.5
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int L, W, H, N, answer = 0;
int x, y;
vector<pair<int, int>> cubes;

void solve(int l, int w, int h){
	if(answer < 0)
		return;
	if(l==0 || w==0 || h==0)
		return;
	for(auto &cube : cubes){
		if(l>=cube.first && w>=cube.first && h>=cube.first && cube.second>0){
			cube.second -= 1;
			answer++;
			solve(l, w, h-cube.first);
			solve(l-cube.first, w, cube.first);
			solve(cube.first, w-cube.first, cube.first);
			return;
		}
	}
	answer = -1;
	return;

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> L >> W >> H >> N;
	
	for(int i=0;i<N;i++){
		cin >> x >> y;
		cubes.push_back({x, y});
		cubes[i].first = pow(2, cubes[i].first);
	}

	sort(cubes.rbegin(), cubes.rend());
	
	solve(L, W, H);

	cout << answer << endl;
	
}
