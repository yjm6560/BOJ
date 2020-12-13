/*
	연료 채우기
	그리디, 힙
	난이도 2
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solve(int L, int P, vector<pair<int, int>> soil){
	int answer = 0;
	
	set<pair<int, int>> s;
	for(auto oil : soil){
		oil.first *= -1;
		s.insert(oil);
	}
	while(P<L){
		bool check = true;
		for(auto oil : s){
			if(oil.second <= P){
				P -= oil.first;
				answer++;
				s.erase(oil);
				check = false;
				break;
			}
		}
		if(check)
			return -1;
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, L, P;
	cin >> N;
	vector< pair<int, int> > soil(N);
	for(int i=0;i<N;i++)
		cin >> soil[i].second >> soil[i].first;
	cin >> L >> P;
	cout << solve(L, P, soil) << endl;
}
