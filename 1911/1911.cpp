/*
	흙길 보수하기
	그리디
	난이도
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

LL solve(LL L, vector< pair<LL, LL> > holes){
	LL answer = 0;

	sort(holes.begin(), holes.end());

	LL N = holes.size();

	for(LL i=0;i<N;i++){
		LL dist = holes[i].second - holes[i].first;
		LL nStick = (dist + L - 1)/L;
//		cout << holes[i].first << " " << holes[i].second << " " << nStick << endl;
		if(i<N-1)
			holes[i+1].first = max(holes[i+1].first, holes[i].first + nStick*L);
		answer += nStick;
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	LL N, L;
	cin >> N >> L;
	vector< pair<LL, LL> > holes(N);
	for(LL i=0;i<N;i++)
		cin >> holes[i].first >> holes[i].second;
	cout << solve(L, holes) << endl;
}
