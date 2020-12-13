/*
	가장 가까운 두 점
	분할 정복, 라인 스위핑
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

typedef struct Point {
	int x;
	int y;
} Point;

int N;
const int INF = 987654321;
vector<Point> pos;

bool compare(Point a, Point b){
	if(a.x < b.x)
		return true;
	else if(a.x == b.x && a.y < b.y)
		return true;
	return false;
}
bool cmp(Point &a, Point &b){
	return a.y < b.y;
}

int dist(Point a, Point b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
int brutforce(int a, int b){
	int ans = INF;
	for(int i=a;i<=b-1;i++){
		for(int j=i+1;j<=b;j++){
			ans = min(ans, dist(pos[i], pos[j]));
		}
	}
	return ans;
}

int lineSweep(int a, int b){
	if(b - a < 3){
		return brutforce(a, b);
	}
	int mid = (a + b)/2;
	
	int left = lineSweep(a, mid);
	int right = lineSweep(mid, b);
	int ans = min(left, right);
	vector<Point> tmp;
	for(int i=a;i<=b;i++){
		if(i == mid)
			continue;
		int d = pos[i].x - pos[mid].x;
		
		if(d*d < ans) {
			tmp.push_back(pos[i]);
		} 
	}
	
	sort(tmp.begin(), tmp.end(), cmp);
	
	int size = tmp.size();
	for(int i=0;i<size-1;i++){
		for(int j=i+1;j<size;j++){
			int dy = tmp[j].y - tmp[i].y;
			if(dy*dy < ans){
				ans = min(ans,dist(tmp[i], tmp[j]));
			} else {
				break;
			}
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for(int i=0;i<N;i++){
		Point input;
		cin >> input.x >> input.y;
		pos.push_back(input);
	}
	
	sort(pos.begin(), pos.end(), compare);
	cout << lineSweep(0, pos.size()-1) << endl;
}
