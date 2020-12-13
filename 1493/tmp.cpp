/*
	박스 채우기
	그리디
	난이도
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
//#include <math.h>

using namespace std;

int L, W, H, N;
vector<pair<int, int>> cube;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> L >> W >> H >> N;
	cube.reserve(N);
	
	for(int i=0;i<N;i++)
		cin >> cube[i].first >> cube[i].second;

	sort(cube.begin(), cube.end(), greater<pair<int, int>>()); 

	for(int i=0;i<N;i++)
		cout << cube[i].first << ", " << cube[i].second << endl;
}
