/*
	강의실 배정
	?
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> N;
	vector<pair<int, int>> lecture(N);
	for(int i=0;i<N;i++)
		cin >> lecture[i].first >> lecture[i].second;

	sort(lecture.begin(), lecture.end());
	for(int i=0;i<N;i++){
		while(pq.size() && pq.top()<=lecture[i].first)
			pq.pop();
		pq.push(lecture[i].second);
		answer = max(answer, (int)pq.size());
	}

	cout << answer << endl;

	return 0;
}
