/*
	좌표 정렬하기
	정렬
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

inline void swap(pair<int, int> &x, pair<int, int> &y){
	pair<int, int> tmp;
	tmp.first = x.first;
	tmp.second = x.second;
	x.first = y.first;
	x.second = y.second;
	y.first = tmp.first;
	y.second = tmp.second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, x, y;
	vector<pair<int, int>> num;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> x >> y;
		num.push_back({x, y});
	}
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			if(num[i].first > num[j].first){
				swap(num[i], num[j]);
			} else if(num[i].first == num[j].first && num[i].second > num[j].second){
				swap(num[i], num[j]);
			}
		}
	}
	/*
	   STL sort
	sort(num.begin(), num.end());
	*/
	for(auto x : num)
		cout << x.first << " " << x.second << "\n";
}
