/*
	강의실 배정
	알고리즘
	난이도
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

long long solution(int N, vector<pair<int, int>> lectures){
	long long answer = 0;
	sort(lectures.begin(), lectures.end());
	priority_queue<long long> pq;
	for(auto lec : lectures){
		while(!pq.empty() && -pq.top()<=lec.first)
			pq.pop();
		pq.push(-lec.second);
		answer = max(answer, (long long)pq.size());
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<pair<int, int>> lectures(N);
	priority_queue<int> pq;
	for(int i=0;i<N;i++){
		cin >> lectures[i].first >> lectures[i].second;
	}

	cout << solution(N, lectures) << endl;
}
