/*
	가장 가까운 두 점
	분할 정복, 라인 스위핑
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

typedef struct Point{
	int x;
	int y;
} Point;

bool compare(Point a, Point b){
	if(a.x < b.x)
		return true;
	else if(a.x == b.x && a.y < b.y)
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<Point> pos(N);

	for(int i=0;i<N;i++)
		cin >> pos[i].x >> pos[i].y;
	for(int i=0;i<N;i++)
		cout << pos[i].x << " " << pos[i].y << endl;
	sort(pos.begin(), pos.end(), compare);
	cout << "\n\n";
//	sort(pos.begin(), pos.end());
	for(int i=0;i<N;i++)
		cout << pos[i].x << " " << pos[i].y << endl;
}
