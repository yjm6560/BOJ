/*
	택배
	그리디
	난이도 2
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

typedef struct {
	int d, s, p;
} truck;

bool compare(truck a, truck b){
	if(a.d < b.d)
		return true;
	else if(a.d == b.d){
		if(a.s < b.s){
			return true;
		} else if(a.s == b.s){
			return a.p < b.p;
		}
	}
	return false;
}

int solve(int N, int C, vector<truck> deliver_info){
	int answer = 0;
	vector<int> path(N);
	sort(deliver_info.begin(), deliver_info.end(), compare);
	
	for(auto di : deliver_info){
		int leftMax = min(di.p, C - *max_element(&path[di.s], &path[di.d]));
		answer += leftMax;
	
		for(int j=di.s;j<di.d;j++)
			path[j] += leftMax;
	}

	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, C, M;
	cin >> N >> C >> M;
	vector<truck> deliver_info(M);
	for(int i=0;i<M;i++)
		cin >> deliver_info[i].s >>  deliver_info[i].d >> deliver_info[i].p ;
	
	cout << solve(N, C, deliver_info) << endl;
}
