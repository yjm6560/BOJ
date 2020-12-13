/*
	컵라면
	그리디
	난이도 2
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <queue>

using namespace std;

int solve(vector<pair<int ,int>> deadline){
	int answer = 0;
	int len = deadline.size();
	priority_queue<int> q;
	
	sort(deadline.begin(), deadline.end());

	for(int i=0, day=1;i<len&&day<=len;i++){
		if(deadline[i].first >= day){
			q.push(-1*deadline[i].second);
			day++;
		} else if(-1*q.top() < deadline[i].second){
				q.pop();
				q.push(-1*deadline[i].second);
		}
	}
	while(!q.empty())
		answer+=q.top(), q.pop();

	return -1 * answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	
	vector<pair<int, int>> deadline(N);
	map<int, int> m;

	for(int i=0;i<N;i++)
		cin >> deadline[i].first >> deadline[i].second;
	
	cout << solve(deadline) << endl;
}
