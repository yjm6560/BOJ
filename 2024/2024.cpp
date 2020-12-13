/*
	선분 덮기
	그리디
	난이도 2
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int compare(pair<int, int> a, pair<int ,int> b){
	if(a.second > b.second)
		return true;
	else if(a.second == b.second)
		return a.first <  b.first;
	return false;
}

int solve(int M, vector<pair<int, int>> lines){
	int answer = 0;
	int beg = 0, len = lines.size();
	sort(lines.begin(), lines.end(), compare);
	while(beg < M){
		bool check = true;
		for(int i=0;i<len;i++){
			if(lines[i].second > beg && lines[i].first <= beg){
				check = false;
				beg = lines[i].second;
				answer++;
				break;
			}
		}
		if(check)
			return 0;
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int M, x, y;
	vector< pair<int, int> > lines;
	cin >> M;
	while(true){
		cin >> x >> y;
		if(!x && !y)
			break;
		lines.push_back({x, y});
	}

	cout << solve(M, lines) << endl;
}
