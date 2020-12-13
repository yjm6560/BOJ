/*
	신입 사원
	그리디
	난이도 1.5
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	while(T--){
		int N, cnt = 0, best = 987654321;
		cin >> N;
		vector<pair<int, int>> order(N);
		for(int i=0;i<N;i++){
			int x, y;
			cin >> x >> y;
			order[i] = {x, y};
		}

		sort(order.begin(), order.end());
		
		for(int i=0;i<N;i++){
			if(best < order[i].second)
				cnt++;
			else
				best = min(best, order[i].second);
		}
		cout << order.size() - cnt << "\n";
	}
}
